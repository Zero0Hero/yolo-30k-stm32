import numpy as np
import cv2
import tensorflow as tf

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


def non_max_suppression(prediction, conf_thres=0.10):
    x = prediction[prediction[..., 4] > conf_thres]
    if not x.shape[0]:
        return []
    box1 = xywh2xyxy(x[:, :4])
    return box1, x[:, 4]


def sigmoid(x):
    return 1 / (1 + np.exp(-x))


interpreter = tf.lite.Interpreter(model_path='model/yolobody0713.tflite')
interpreter.allocate_tensors()

input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

img = cv2.imread('small_dataset/1598765907624905.jpg')
input = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
H, W, _ = img.shape
IMGHW = 72
w_scale = W / IMGHW
h_scale = H / IMGHW
input = cv2.resize(input, (IMGHW, IMGHW)).astype(np.float32)
input = input[np.newaxis, :, :, :]
input = input - 128
input = input.astype(np.int8)

interpreter.set_tensor(input_details[0]['index'], input)
interpreter.invoke()
output_data = interpreter.get_tensor(output_details[0]['index'])
# print(interpreter.get_tensor_details())
output = output_data[0].astype(np.float32)
output = (output - 50) * 0.1683046817779541
nx, ny, _ = output.shape
anchors = get_anchors('F:/Python_DL/tensorflow/yolov4-tiny-keras-stm32_final/model_data/yolo_anchors.txt')

output = output.reshape((IMGHW // 8, IMGHW // 8, 3, 7)).transpose([2, 0, 1, 3])
yv, xv = np.meshgrid(np.arange(ny), np.arange(nx))
grid = np.stack((yv, xv), 2).reshape((1, ny, nx, 2)).astype(np.float32)
output[..., 0:2] = (sigmoid(output[..., 0:2]) + grid) * 8
output[..., 2:4] = np.exp(output[..., 2:4]) * anchors
output[..., 4:] = sigmoid(output[..., 4:])
output = output.reshape((-1, 7))
boxes1, confidence = non_max_suppression(output, 0.1)

if len(boxes1) != 0:
    for detect in boxes1:
        print(detect)
        print(confidence)
        detect[[0, 2]] *= w_scale
        detect[[1, 3]] *= h_scale
        detect = detect.astype(np.int32)
        cv2.rectangle(img, (detect[0], detect[1]), (detect[2], detect[3]), (0, 0, 255), 2)

cv2.imshow('img', img)
cv2.waitKey(0)
