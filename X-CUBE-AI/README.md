YOLOV4-(30k) 模型实现
---
2022 嵌入式芯片与系统设计竞赛 开源仓库 By HERO_ZERO 2022.7.14

## 背景
YOLO作为目标检测的典型网络，在互联网上似乎很难找到从网络搭建到量化再到部署的仓库，这也是我做这个项目的目的。  

## 做了什么
提供从 Tensorflow 模型搭建 到量化 再到到STM32H723-Nucleo板卡进行目标检测主要代码，以及UDP、UART回传的上位机（Matlab 编写）

## 文件目录
* Tesnsorflow：使用tensorflow搭建了yolo网络
* Model quantification：使用tenforflow 对第一步的网络进行量化
* X-CUBE-AI：给出了STM32CUBEIDE X-CUBE-AI 生成的c文件以及report。
* UDP_IMG_Transmit: UDP 传输图像 上位机
* UART_IMG_Transmit: UART 传输图像 上位机

