YOLOV4-(30k) 模型实现 (YOLOV4-(30k) model implementation)
---
By HERO_ZERO CAST NJUPT 2022.7.14  
原始网址 https://github.com/Zero0Hero/yolo-30k-stm32

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

## 注意
在nets/yolov4_tiny.py 125行左右，涉及yolo模型更改，原模型为注释（同样涉及到loss.py52行，以及模型量化、x-cube-ai函数），如要进行更改，请统一


---
Open Source By HERO_ZERO 2022.7.14

## Background
As a typical network for target detection, YOLO seems to be difficult to find a warehouse from network construction to quantification to deployment on the Internet, which is also the purpose of my project.

## What have we done
Provide the main code from Tensorflow model building to quantization to STM32H723-Nucleo board for target detection, as well as the host computer for UDP and UART return (written in Matlab)

## File Directory
Tesensorflow: Use tensorflow to build a yolo network
Model quantification: Use tenforflow to quantify the network in the first step
X-CUBE-AI: The c file and report generated by STM32CUBEIDE X-CUBE-AI are given.
UDP_IMG_Transmit: UDP transmit image host computer
UART_IMG_Transmit: UART transmits image to the host computer
