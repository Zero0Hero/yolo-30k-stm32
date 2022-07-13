from tensorflow.keras.models import load_model
from tensorflow.keras.utils import plot_model
from tensorflow.keras import backend as K
import cv2
import numpy as np

def get_anchors(anchors_path):
    '''loads the anchors from a file'''
    with open(anchors_path) as f:
        anchors = f.readline()
    anchors = [float(x) for x in anchors.split(',')]
    return np.array(anchors).reshape(3, 1, 1, 2)


def xywh2xyxy(x):
    y = np.zeros(x.shape, dtype=np.float32)
    y[..., 0] = x[..., 0] - x[..., 2] / 2
    y[..., 1] = x[..., 1] - x[..., 3] / 2
    y[..., 2] = x[..., 0] + x[..., 2] / 2
    y[..., 3] = x[..., 1] + x[..., 3] / 2
    return y


def non_max_suppression(prediction, conf_thres=0.25):
    print(np.max(prediction[..., 4]))
    x = prediction[prediction[..., 4] > conf_thres]
    print(x)
    if not x.shape[0]:
        return []
    box = xywh2xyxy(x[:, :4])
    return box


def sigmoid(x):
    return 1 / (1 + np.exp(-x))


model = load_model('F:/Python_DL/tensorflow/yolov4-tiny-keras-stm32_final/model_data/yolobody0711.h5')
# plot_model(model, to_file='model.png', show_shapes=True)
img = cv2.imread('small_dataset/m98.jpg')
input = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
IMGHW=72
H, W, _ = img.shape
w_scale = W / IMGHW
h_scale = H / IMGHW
input = cv2.resize(input, (IMGHW, IMGHW))
input = input[np.newaxis, :, :, :]
input = input / 255.

output = model(input)

output = output.numpy()[0]
output0 = output
nx, ny, _ = output.shape
anchors = get_anchors('F:/Python_DL/tensorflow/yolov4-tiny-keras-stm32_final/model_data/yolo_anchors.txt')

print(output.shape)
output = output.reshape((IMGHW//8, IMGHW//8, 3, 7)).transpose([2, 0, 1, 3])
yv, xv = np.meshgrid(np.arange(ny), np.arange(nx))
grid = np.stack((yv, xv), 2).reshape((1, ny, nx, 2)).astype(np.float32)
output[..., 0:2] = (sigmoid(output[..., 0:2]) + grid) * 8
output[..., 2:4] = np.exp(output[..., 2:4]) * anchors
output[..., 4:] = sigmoid(output[..., 4:])
output = output.reshape((-1, 7))
boxes = non_max_suppression(output, 0.1)

if len(boxes) != 0:
    for detect in boxes:
        print(detect)
        detect[[0, 2]] *= w_scale
        detect[[1, 3]] *= h_scale
        detect = detect.astype(np.int32)
        cv2.rectangle(img, (detect[0], detect[1]), (detect[2], detect[3]), (0, 0, 255), 2)
cv2.imshow('img', img)
cv2.waitKey(0)
