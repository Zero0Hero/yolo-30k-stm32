YOLOV4-(30k) 模型实现
---
2022 嵌入式芯片与系统设计竞赛 开源仓库 By HERO_ZERO


### 所需环境
tensorflow-gpu==1.13.1  
keras==2.1.5  

### 网络结构
网络代码位于 nets 文件夹下 yolo_tiny.py  


### 训练步骤
1.VOC格式进行训练。  
2.训练前将标签文件放在VOCdevkit文件夹下的VOC2007文件夹下的Annotation中。  
3.训练前将图片文件放在VOCdevkit文件夹下的VOC2007文件夹下的JPEGImages中。  
4.在训练前利用voc2yolo4.py文件生成对应的txt。  
5.再运行根目录下的voc_annotation.py，运行前需要将classes改成你自己的classes。**注意不要使用中文标签，文件夹中不要有空格！**  
6.此时会生成对应的2007_train.txt，每一行对应其**图片位置**及其**真实框的位置**。  
7.**在训练前需要务必在model_data下新建一个txt文档，文档中输入需要分的类，在train.py中将classes_path指向该文件**，示例如下：   
```python
classes_path = 'model_data/class0630.txt'    
```
8.运行 kmeans_for_anchors.py  
9.运行 train.py 即可开始训练。

### 模型测试
1.打开 get_gt_txt.py  
2.打开以下路径
```python
'VOCdevkit/VOC2007/ImageSets/Main/test.txt'
```
仿照 train.txt 添加图片名到 test.txt 并运行get_gt_txt.py  
3.运行 get_dr_txt.py  
4.可在 input 下查看 detection-result 对比 ground-truth  


### Reference
https://github.com/bubbliiiing/yolov4-tiny-keras

