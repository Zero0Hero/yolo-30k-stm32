import colorsys
import os

import numpy as np
from keras import backend as K
from keras.applications.imagenet_utils import preprocess_input
from keras.layers import Input
from PIL import Image
from tqdm import tqdm

from nets.yolo4_tiny import yolo_body, yolo_eval
from utils.utils import letterbox_image
from yolo import YOLO
import keras
import tensorflow as tf

from keras.models import load_model

class mAP_YOLO(YOLO):
    #---------------------------------------------------#
    #   获得所有的分类
    #---------------------------------------------------#
    def generate(self):
        self.score = 0.05
        self.iou = 0.3
        #model_path = 'model_data/yolo0701_1.h5'

        #---------------------------------------------------#
        #   计算先验框的数量和种类的数量
        #---------------------------------------------------#
        num_anchors = len(self.anchors)
        num_classes = len(self.class_names)

        #---------------------------------------------------------#
        #   载入模型，如果原来的模型里已经包括了模型结构则直接载入。
        #   否则先构建模型再载入
        #---------------------------------------------------------#
        #try:
        #self.yolo_model = load_model(self.model_path, compile=False)
        #except:
        self.yolo_model = yolo_body(Input(shape=(72, 72, 3)), num_anchors, num_classes)
        self.yolo_model.load_weights(self.model_path)
        #else:
        #    assert self.yolo_model.layers[-1].output_shape[-1] == \
        #        num_anchors/len(self.yolo_model.output) * (num_classes + 5), \
         #       'Mismatch between model and given anchor and class sizes'

        self.yolo_model.save('model_data/yolobody0713.h5');
        print('{} model, anchors, and classes loaded.'.format(self.model_path))

        # 画框设置不同的颜色
        hsv_tuples = [(x / len(self.class_names), 1., 1.)
                      for x in range(len(self.class_names))]
        self.colors = list(map(lambda x: colorsys.hsv_to_rgb(*x), hsv_tuples))
        self.colors = list(
            map(lambda x: (int(x[0] * 255), int(x[1] * 255), int(x[2] * 255)),
                self.colors))

        # 打乱颜色
        np.random.seed(10101)
        np.random.shuffle(self.colors)
        np.random.seed(None)

        self.input_image_shape = K.placeholder(shape=(2, ))

        #---------------------------------------------------------#
        #   在yolo_eval函数中，我们会对预测结果进行后处理
        #   后处理的内容包括，解码、非极大抑制、门限筛选等
        #---------------------------------------------------------#
        modelout=self.yolo_model.output,
        boxes, scores, classes = yolo_eval(modelout, self.anchors,
                num_classes, self.input_image_shape, max_boxes = self.max_boxes,
                score_threshold = self.score, iou_threshold = self.iou)
        return boxes, scores, classes

    #---------------------------------------------------#
    #   检测图片
    #---------------------------------------------------#
    def detect_image(self, image_id, image):
        f = open("./input/detection-results/"+image_id+".txt","w") 
        #---------------------------------------------------------#
        #   给图像增加灰条，实现不失真的resize
        #---------------------------------------------------------#
        new_image_size = (self.model_image_size[1], self.model_image_size[0])
        boxed_image = letterbox_image(image, new_image_size)
        image_data = np.array(boxed_image, dtype='float32')
        image_data /= 255.
        #---------------------------------------------------------#
        #   添加上batch_size维度
        #---------------------------------------------------------#
        image_data = np.expand_dims(image_data, 0)

        #---------------------------------------------------------#
        #   将图像输入网络当中进行预测！
        #---------------------------------------------------------#
        out_boxes, out_scores, out_classes = self.sess.run(
            [self.boxes, self.scores, self.classes],
            feed_dict={
                self.yolo_model.input: image_data,
                self.input_image_shape: [image.size[1], image.size[0]],
                K.learning_phase(): 0})

        for i, c in enumerate(out_classes):
            predicted_class = self.class_names[int(c)]
            score = str(out_scores[i])

            top, left, bottom, right = out_boxes[i]
            f.write("%s %s %s %s %s %s\n" % (predicted_class, score[:6], str(int(left)), str(int(top)), str(int(right)),str(int(bottom))))

        f.close()
        return 

config = tf.ConfigProto()
config.gpu_options.allow_growth = True  # TensorFlow按需分配显存
config.gpu_options.per_process_gpu_memory_fraction = 0.5  # 指定显存分配比例
keras.backend.tensorflow_backend.set_session(tf.Session(config=config))
yolo = mAP_YOLO()

image_ids = open('VOCdevkit/VOC2007/ImageSets/Main/test.txt').read().strip().split()

if not os.path.exists("./input"):
    os.makedirs("./input")
if not os.path.exists("./input/detection-results"):
    os.makedirs("./input/detection-results")
if not os.path.exists("./input/images-optional"):
    os.makedirs("./input/images-optional")

for image_id in tqdm(image_ids):
    image_path = "./VOCdevkit/VOC2007/JPEGImages/"+image_id+".jpg"
    image = Image.open(image_path)
    # 开启后在之后计算mAP可以可视化
    image.save("./input/images-optional/"+image_id+".jpg")
    yolo.detect_image(image_id, image)
print("Conversion completed!")
