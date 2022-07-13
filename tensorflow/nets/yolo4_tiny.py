from functools import wraps

import numpy as np
import tensorflow as tf
from keras import backend as K
from keras.layers import Conv2D, Add, ZeroPadding2D, UpSampling2D, Concatenate, MaxPooling2D, DepthwiseConv2D, SeparableConv2D
from keras.layers.advanced_activations import LeakyReLU
from keras.layers.normalization import BatchNormalization
from keras.models import Model
from keras.regularizers import l2
from utils.utils import compose


#--------------------------------------------------#
#   单次卷积
#--------------------------------------------------#
@wraps(Conv2D)
def SConv2D(*args, **kwargs):
    darknet_conv_kwargs = {'kernel_regularizer': l2(5e-4)}
    darknet_conv_kwargs['padding'] = 'valid' if kwargs.get('strides')==(2,2) else 'same'
    darknet_conv_kwargs.update(kwargs)
    return Conv2D(*args, **darknet_conv_kwargs)

@wraps(Conv2D)
def DConv2D(*args, **kwargs):
    darknet_conv_kwargs = {'kernel_regularizer': l2(5e-4)}
    darknet_conv_kwargs['padding'] = 'valid' if kwargs.get('strides')==(2,2) else 'same'
    darknet_conv_kwargs.update(kwargs)
    return SeparableConv2D(*args, **darknet_conv_kwargs)

#---------------------------------------------------#Conv2D SeparableConv2D
#   卷积块
#   SConv2D + BatchNormalization + LeakyReLU
#---------------------------------------------------#
def SConv2D_BN_Leaky(*args, **kwargs):
    no_bias_kwargs = {'use_bias': False}
    no_bias_kwargs.update(kwargs)
    return compose( 
        SConv2D(*args, **no_bias_kwargs),
        BatchNormalization(),
        LeakyReLU(alpha=0.1)
    )

def DConv2D_BN_Leaky(*args, **kwargs):
    no_bias_kwargs = {'use_bias': False}
    no_bias_kwargs.update(kwargs)
    return compose(
        DConv2D(*args, **no_bias_kwargs),
        BatchNormalization(),
        LeakyReLU(alpha=0.1)
    )

def darknet_body_half(x):
    x = ZeroPadding2D(((1, 0), (1, 0)))(x)
    x = SConv2D_BN_Leaky(8, (3, 3), strides=(2, 2))(x)

    x = ZeroPadding2D(((1, 0), (1, 0)))(x)
    x = DConv2D_BN_Leaky(16, (3, 3), strides=(2, 2))(x)
    # x = SConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    route_10 = x
    x = SConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    # 引出一个小的残差边route_1
    route_11 = x
    # 对第主干部分进行3x3卷积
    x = SConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    # 主干部分与残差部分进行相接
    x = Concatenate()([x, route_11])
    # 对相接后的结果进行1x1卷积
    x = SConv2D_BN_Leaky(16, (1, 1))(x)
    x = Concatenate()([route_10, x])
    feat1 = x

    x = ZeroPadding2D(((1, 0), (1, 0)))(x)
    x = DConv2D_BN_Leaky(16, (3, 3), strides=(2, 2))(x)
    route_20 = x
    x = SConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    # 引出一个小的残差边route_1
    route_21 = x
    # 对第主干部分进行3x3卷积
    x = SConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    # 主干部分与残差部分进行相接
    x = Concatenate()([x, route_21])
    # 对相接后的结果进行1x1卷积
    x = SConv2D_BN_Leaky(16, (1, 1))(x)
    x = Concatenate()([route_20, x])
    x = SConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    feat2 = x

    return feat1, feat2

def darknet_body_S(x):
    x = ZeroPadding2D(((1, 0), (1, 0)))(x)
    x = DConv2D_BN_Leaky(8, (3, 3), strides=(2, 2))(x)

    x = ZeroPadding2D(((1, 0), (1, 0)))(x)
    x = DConv2D_BN_Leaky(16, (3, 3), strides=(2, 2))(x)
    # x = SConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    route_10 = x
    x = DConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    # 引出一个小的残差边route_1
    route_11 = x
    # 对第主干部分进行3x3卷积
    x = DConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    # 主干部分与残差部分进行相接
    x = Concatenate()([x, route_11])
    # 对相接后的结果进行1x1卷积
    x = DConv2D_BN_Leaky(16, (1, 1))(x)
    x = Concatenate()([route_10, x])
    feat1 = x

    x = ZeroPadding2D(((1, 0), (1, 0)))(x)
    x = DConv2D_BN_Leaky(16, (3, 3), strides=(2, 2))(x)
    route_20 = x
    x = DConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    # 引出一个小的残差边route_1
    route_21 = x
    # 对第主干部分进行3x3卷积
    x = DConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    # 主干部分与残差部分进行相接
    x = Concatenate()([x, route_21])
    # 对相接后的结果进行1x1卷积
    x = DConv2D_BN_Leaky(16, (1, 1))(x)
    x = Concatenate()([route_20, x])
    x = DConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    feat2 = x

    return feat1, feat2

def darknet_body(x):
    # 首先利用两次步长为2x2的3x3卷积进行高和宽的压缩
    # 416,416,3 -> 208,208,32 -> 104,104,64
    x = ZeroPadding2D(((1, 0), (1, 0)))(x)
    x = SConv2D_BN_Leaky(8, (3, 3), strides=(2, 2))(x)

    x = ZeroPadding2D(((1, 0), (1, 0)))(x)
    x = SConv2D_BN_Leaky(16, (3, 3), strides=(2, 2))(x)
    #x = SConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    route_10 = x
    x = SConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    # 引出一个小的残差边route_1
    route_11 = x
    # 对第主干部分进行3x3卷积
    x = SConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    # 主干部分与残差部分进行相接
    x = Concatenate()([x, route_11])
    # 对相接后的结果进行1x1卷积
    x = SConv2D_BN_Leaky(16, (1, 1))(x)
    x = Concatenate()([route_10, x])
    feat1 = x

    x = ZeroPadding2D(((1, 0), (1, 0)))(x)
    x = SConv2D_BN_Leaky(16, (3, 3), strides=(2, 2))(x)
    route_20 = x
    x = SConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    # 引出一个小的残差边route_1
    route_21 = x
    # 对第主干部分进行3x3卷积
    x = SConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    # 主干部分与残差部分进行相接
    x = Concatenate()([x, route_21])
    # 对相接后的结果进行1x1卷积
    x = SConv2D_BN_Leaky(16, (1, 1))(x)
    x = Concatenate()([route_20, x])
    x = SConv2D_BN_Leaky(16, (3, 3), strides=(1, 1))(x)
    feat2 = x

    return feat1, feat2

#---------------------------------------------------#
#   特征层->最后的输出
#---------------------------------------------------#
def yolo_body(inputs, num_anchors, num_classes):
    #---------------------------------------------------#
    #   生成CSPdarknet53_tiny的主干模型
    #   feat1的shape为26,26,256
    #   feat2的shape为13,13,512
    #---------------------------------------------------#
    feat1, feat2 = darknet_body_S(inputs)
    # feat1, feat2 = darknet_body(inputs)
    #feat1, feat2 = darknet_body_half(inputs)
    # 13,13,512 -> 13,13,256
    # P5 = SConv2D_BN_Leaky(32, (1,1))(feat2)
    # 13,13,256 -> 13,13,512 -> 13,13,255
    #P4 = ZeroPadding2D(((1, 0), (1, 0)))(feat1)
    #P4 = SConv2D_BN_Leaky(16, (3, 3), strides=(2, 2))(P4)

    P5 = feat2
    #P5 = SConv2D(16, (3, 3))(P5)
    P5 = SConv2D(num_anchors * (num_classes + 5), (3, 3))(P5)
    #P5 = Concatenate()([P4, P5])
    #P5 = SConv2D(num_anchors * (num_classes + 5), (1, 1))(P5)
    return Model(inputs, [P5])

#---------------------------------------------------#
#   将预测值的每个特征层调成真实值
#---------------------------------------------------#
def yolo_head(feats, anchors, num_classes, input_shape, calc_loss=False):
    num_anchors = len(anchors)
    #---------------------------------------------------#
    #   [1, 1, 1, num_anchors, 2]
    #---------------------------------------------------#
    anchors_tensor = K.reshape(K.constant(anchors), [1, 1, 1, num_anchors, 2])

    #---------------------------------------------------#
    #   获得x，y的网格
    #   (13, 13, 1, 2)
    #---------------------------------------------------#
    grid_shape = K.shape(feats)[1:3]
    grid_y = K.tile(K.reshape(K.arange(0, stop=grid_shape[0]), [-1, 1, 1, 1]),
        [1, grid_shape[1], 1, 1])
    grid_x = K.tile(K.reshape(K.arange(0, stop=grid_shape[1]), [1, -1, 1, 1]),
        [grid_shape[0], 1, 1, 1])
    grid = K.concatenate([grid_x, grid_y])
    grid = K.cast(grid, K.dtype(feats))

    #---------------------------------------------------#
    #   将预测结果调整成(batch_size,13,13,3,85)
    #   85可拆分成4 + 1 + 80
    #   4代表的是中心宽高的调整参数
    #   1代表的是框的置信度
    #   80代表的是种类的置信度
    #---------------------------------------------------#
    feats = K.reshape(feats, [-1, grid_shape[0], grid_shape[1], num_anchors, num_classes + 5])

    #---------------------------------------------------#
    #   将预测值调成真实值
    #   box_xy对应框的中心点
    #   box_wh对应框的宽和高
    #---------------------------------------------------#
    box_xy = (K.sigmoid(feats[..., :2]) + grid) / K.cast(grid_shape[::-1], K.dtype(feats))
    box_wh = K.exp(feats[..., 2:4]) * anchors_tensor / K.cast(input_shape[::-1], K.dtype(feats))
    box_confidence = K.sigmoid(feats[..., 4:5])
    box_class_probs = K.sigmoid(feats[..., 5:])

    #---------------------------------------------------------------------#
    #   在计算loss的时候返回grid, feats, box_xy, box_wh
    #   在预测的时候返回box_xy, box_wh, box_confidence, box_class_probs
    #---------------------------------------------------------------------#
    if calc_loss == True:
        return grid, feats, box_xy, box_wh
    return box_xy, box_wh, box_confidence, box_class_probs

#---------------------------------------------------#
#   对box进行调整，使其符合真实图片的样子
#---------------------------------------------------#
def yolo_correct_boxes(box_xy, box_wh, input_shape, image_shape):
    #-----------------------------------------------------------------#
    #   把y轴放前面是因为方便预测框和图像的宽高进行相乘
    #-----------------------------------------------------------------#
    box_yx = box_xy[..., ::-1]
    box_hw = box_wh[..., ::-1]
    
    input_shape = K.cast(input_shape, K.dtype(box_yx))
    image_shape = K.cast(image_shape, K.dtype(box_yx))

    new_shape = K.round(image_shape * K.min(input_shape/image_shape))
    #-----------------------------------------------------------------#
    #   这里求出来的offset是图像有效区域相对于图像左上角的偏移情况
    #   new_shape指的是宽高缩放情况
    #-----------------------------------------------------------------#
    offset = (input_shape-new_shape)/2./input_shape
    scale = input_shape/new_shape

    box_yx = (box_yx - offset) * scale
    box_hw *= scale

    box_mins = box_yx - (box_hw / 2.)
    box_maxes = box_yx + (box_hw / 2.)
    boxes =  K.concatenate([
        box_mins[..., 0:1],  # y_min
        box_mins[..., 1:2],  # x_min
        box_maxes[..., 0:1],  # y_max
        box_maxes[..., 1:2]  # x_max
    ])

    boxes *= K.concatenate([image_shape, image_shape])
    return boxes

#---------------------------------------------------#
#   获取每个box和它的得分
#---------------------------------------------------#
def yolo_boxes_and_scores(feats, anchors, num_classes, input_shape, image_shape):
    #-----------------------------------------------------------------#
    #   将预测值调成真实值
    #   box_xy : -1,13,13,3,2; 
    #   box_wh : -1,13,13,3,2; 
    #   box_confidence : -1,13,13,3,1; 
    #   box_class_probs : -1,13,13,3,80;
    #-----------------------------------------------------------------#
    box_xy, box_wh, box_confidence, box_class_probs = yolo_head(feats, anchors, num_classes, input_shape)
    #-----------------------------------------------------------------#
    #   在图像传入网络预测前会进行letterbox_image给图像周围添加灰条
    #   因此生成的box_xy, box_wh是相对于有灰条的图像的
    #   我们需要对齐进行修改，去除灰条的部分。
    #   将box_xy、和box_wh调节成y_min,y_max,xmin,xmax
    #-----------------------------------------------------------------#
    boxes = yolo_correct_boxes(box_xy, box_wh, input_shape, image_shape)
    #-----------------------------------------------------------------#
    #   获得最终得分和框的位置
    #-----------------------------------------------------------------#
    boxes = K.reshape(boxes, [-1, 4])
    box_scores = box_confidence * box_class_probs
    box_scores = K.reshape(box_scores, [-1, num_classes])
    return boxes, box_scores

#---------------------------------------------------#
#   图片预测
#---------------------------------------------------#
def yolo_eval(yolo_outputs,
              anchors,
              num_classes,
              image_shape,
              max_boxes=20,
              score_threshold=.6,
              iou_threshold=.5):
    #---------------------------------------------------#
    #   获得特征层的数量，有效特征层的数量为3
    #---------------------------------------------------#
    num_layers = len(yolo_outputs)
    #-----------------------------------------------------------#
    #   13x13的特征层对应的anchor是[81,82], [135,169], [344,319]
    #   26x26的特征层对应的anchor是[23,27], [37,58], [81,82]
    #-----------------------------------------------------------#
    anchor_mask = [[0,1,2]] if num_layers==1 else [[3,4,5], [1,2,3]]
    
    #-----------------------------------------------------------#
    #   这里获得的是输入图片的大小，一般是416x416
    #-----------------------------------------------------------#
    input_shape = K.shape(yolo_outputs[0])[1:3] * 8
    print(input_shape)
    boxes = []
    box_scores = []
    #-----------------------------------------------------------#
    #   对每个特征层进行处理
    #-----------------------------------------------------------#
    for l in range(num_layers):
        _boxes, _box_scores = yolo_boxes_and_scores(yolo_outputs[l], anchors[anchor_mask[l]], num_classes, input_shape, image_shape)
        boxes.append(_boxes)
        box_scores.append(_box_scores)
    #-----------------------------------------------------------#
    #   将每个特征层的结果进行堆叠
    #-----------------------------------------------------------#
    boxes = K.concatenate(boxes, axis=0)
    box_scores = K.concatenate(box_scores, axis=0)

    #-----------------------------------------------------------#
    #   判断得分是否大于score_threshold
    #-----------------------------------------------------------#
    mask = box_scores >= score_threshold
    max_boxes_tensor = K.constant(max_boxes, dtype='int32')
    boxes_ = []
    scores_ = []
    classes_ = []
    for c in range(num_classes):
        #-----------------------------------------------------------#
        #   取出所有box_scores >= score_threshold的框，和成绩
        #-----------------------------------------------------------#
        class_boxes = tf.boolean_mask(boxes, mask[:, c])
        class_box_scores = tf.boolean_mask(box_scores[:, c], mask[:, c])

        #-----------------------------------------------------------#
        #   非极大抑制
        #   保留一定区域内得分最大的框
        #-----------------------------------------------------------#
        nms_index = tf.image.non_max_suppression(
            class_boxes, class_box_scores, max_boxes_tensor, iou_threshold=iou_threshold)

        #-----------------------------------------------------------#
        #   获取非极大抑制后的结果
        #   下列三个分别是
        #   框的位置，得分与种类
        #-----------------------------------------------------------#
        class_boxes = K.gather(class_boxes, nms_index)
        class_box_scores = K.gather(class_box_scores, nms_index)
        classes = K.ones_like(class_box_scores, 'int32') * c
        boxes_.append(class_boxes)
        scores_.append(class_box_scores)
        classes_.append(classes)
    boxes_ = K.concatenate(boxes_, axis=0)
    scores_ = K.concatenate(scores_, axis=0)
    classes_ = K.concatenate(classes_, axis=0)

    return boxes_, scores_, classes_


