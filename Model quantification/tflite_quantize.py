import tensorflow as tf
from tensorflow.keras import models
import numpy as np
import os
import cv2

img_lists = []
for root, dirs, files in os.walk("small_dataset"):
    img_lists = files


def representative_dataset_gen(IMGHW=72):
    for img in img_lists:
        img = cv2.imread('small_dataset/' + img)
        input = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        H, W, _ = img.shape
        w_scale = W / IMGHW
        h_scale = H / IMGHW
        input = cv2.resize(input, (IMGHW, IMGHW))
        input = input[np.newaxis, :, :, :]
        input = input / 255.
        # data = np.random.rand(1, 56, 56, 3)
        yield [input.astype(np.float32)]


# 定义转换器
# model=keras.models.load_model()
model = models.load_model('F:/Python_DL/tensorflow/yolov4-tiny-keras-stm32_final/model_data/yolobody0713.h5')
# models.save_model(model, 'model/pb/')
converter = tf.lite.TFLiteConverter.from_keras_model(model)
# converter = tf.lite.TFLiteConverter.from_saved_model('model/pb/')
# 定义量化配置fromt("model/yolobody0707.pb", ["Input"], ["Identity"], {"Input":[1,96,96,3]})
converter.representative_dataset = representative_dataset_gen
converter.optimizations = [tf.lite.Optimize.DEFAULT]
converter.target_spec.supported_ops = [tf.lite.OpsSet.TFLITE_BUILTINS_INT8]
converter.target_spec.supported_types = [tf.int8]
converter.inference_input_type = tf.int8
converter.inference_output_type = tf.int8

# 转换并保存
quantize_model = converter.convert()
open("model/yolobody0713.tflite", "wb").write(quantize_model)

