
#ifdef __cplusplus
 extern "C" {
#endif
/**
  ******************************************************************************
  * @file           : app_x-cube-ai.c
  * @brief          : AI program body
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V.
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other
  *    contributors to this software may be used to endorse or promote products
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under
  *    this license is void and will automatically terminate your rights under
  *    this license.
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
 /*
  * Description
  *   v1.0 - Minimum template to show how to use the Embedded Client API
  *          model. Only one input and one output is supported. All
  *          memory resources are allocated statically (AI_NETWORK_XX, defines
  *          are used).
  *          Re-target of the printf function is out-of-scope.
  *
  *   For more information, see the embeded documentation:
  *
  *       [1] %X_CUBE_AI_DIR%/Documentation/index.html
  *
  *   X_CUBE_AI_DIR indicates the location where the X-CUBE-AI pack is installed
  *   typical : C:\Users\<user_name>\STM32Cube\Repository\STMicroelectronics\X-CUBE-AI\6.0.0
  */
/* Includes ------------------------------------------------------------------*/
/* System headers */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "app_x-cube-ai.h"
#include "main.h"
#include "ai_datatypes_defines.h"

/* USER CODE BEGIN includes */
#include "pic.h"
#define IMGHW 72 //图像输入长宽 72
#define FEATHW (IMGHW/8) //Model输出FEAT 长宽 12
#define NUM_ANCHOR 3
#define NUM_CLASS 2 //分类数目 2
#define MAX_BOXNUM 10
/* USER CODE END includes */
/* Global AI objects */
static ai_handle yolobody = AI_HANDLE_NULL;
static ai_network_report yolobody_info;

/* Global c-array to handle the activations buffer */
AI_ALIGNED(4)
static ai_u8 activations[AI_YOLOBODY_DATA_ACTIVATIONS_SIZE];

/*  In the case where "--allocate-inputs" option is used, memory buffer can be
 *  used from the activations buffer. This is not mandatory.
 */
#if !defined(AI_YOLOBODY_INPUTS_IN_ACTIVATIONS)
/* Allocate data payload for input tensor */
AI_ALIGNED(4)
static ai_u8 in_data_s[AI_YOLOBODY_IN_1_SIZE_BYTES];
#endif

/*  In the case where "--allocate-outputs" option is used, memory buffer can be
 *  used from the activations buffer. This is no mandatory.
 */
#if !defined(AI_YOLOBODY_OUTPUTS_IN_ACTIVATIONS)
/* Allocate data payload for the output tensor */
AI_ALIGNED(4)
static ai_u8 out_data_s[AI_YOLOBODY_OUT_1_SIZE_BYTES];
#endif

static void ai_log_err(const ai_error err, const char *fct)
{
  /* USER CODE BEGIN log */
  if (fct)
    printf("TEMPLATE - Error (%s) - type=0x%02x code=0x%02x\r\n", fct,
        err.type, err.code);
  else
    printf("TEMPLATE - Error - type=0x%02x code=0x%02x\r\n", err.type, err.code);

  do {} while (1);
  /* USER CODE END log */
}

static int ai_boostrap(ai_handle w_addr, ai_handle act_addr)
{
  ai_error err;

  /* 1 - Create an instance of the model */
  err = ai_yolobody_create(&yolobody, AI_YOLOBODY_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
    ai_log_err(err, "ai_yolobody_create");
    return -1;
  }

  /* 2 - Initialize the instance */
  const ai_network_params params = {
      AI_YOLOBODY_DATA_WEIGHTS(w_addr),
      AI_YOLOBODY_DATA_ACTIVATIONS(act_addr) };

  if (!ai_yolobody_init(yolobody, &params)) {
      err = ai_yolobody_get_error(yolobody);
      ai_log_err(err, "ai_yolobody_init");
      return -1;
    }

  /* 3 - Retrieve the network info of the created instance */
  if (!ai_yolobody_get_info(yolobody, &yolobody_info)) {
    err = ai_yolobody_get_error(yolobody);
    ai_log_err(err, "ai_yolobody_get_error");
    ai_yolobody_destroy(yolobody);
    yolobody = AI_HANDLE_NULL;
    return -3;
  }

  return 0;
}

static int ai_run(void *data_in, void *data_out)
{
  ai_i32 batch;

  ai_buffer *ai_input = yolobody_info.inputs;
  ai_buffer *ai_output = yolobody_info.outputs;

  ai_input[0].data = AI_HANDLE_PTR(data_in);
  ai_output[0].data = AI_HANDLE_PTR(data_out);

  batch = ai_yolobody_run(yolobody, ai_input, ai_output);
  if (batch != 1) {
    ai_log_err(ai_yolobody_get_error(yolobody),
        "ai_yolobody_run");
    return -1;
  }

  return 0;
}

/* USER CODE BEGIN 2 */
/*
 * sigmoid function
 */
float sigmoid(float x)
{
	float y = 1/(1+expf(-x));
	return y;
}
/*
 * Pre-process the image data
 * rawdata : original image data
 * data_in : data processed to input into model
 */
int acquire_and_process_data(void * rawdata, void *data_in)
{
	for(int16_t i=0;i<IMGHW*IMGHW*3;i++)
	{
		*((int8_t*)data_in+i)=*((int8_t*)rawdata+i)-128;
	}
  return 0;
}
/*
 * Sort boxes according to confidence
 * boxes: boxes store sequence
 * box : new boxes to insert
 */
int sort(float boxes[MAX_BOXNUM][NUM_CLASS+5], float box[NUM_CLASS+5])
{
	for (uint16_t i=0; i<MAX_BOXNUM;i++)
	{
		if(box[4]>boxes[i][4])
		{
			for (uint16_t j=MAX_BOXNUM-1; j>i; j--)
			{
				memcpy(boxes[j],boxes[j-1],(NUM_CLASS+5)*4);
			}
			memcpy(boxes[i],box,(NUM_CLASS+5)*4);
			return 0;
		}
	}
	return 0;
}
/*
 * Attention!!! Please initialize @para nmsboxes with zeros
 */
int NMS(float boxes[MAX_BOXNUM][NUM_CLASS+5], float nmsboxes[MAX_BOXNUM][NUM_CLASS+5])
{
#define NMS_IOU 0.4 //非极大�?�抑制交并比阈�??
#define CONF_THRESHOLD 0.1 //替换为画框的置信程度
#define MAX(a,b) ((a>b)? a:b)
#define MIN(a,b) ((a<b)? a:b)
	uint16_t valid_box;
	float S[MAX_BOXNUM];
	//查看有几个有效boxes�? !!!请将无效boxes 中conf 归零
	if(boxes[0][4]>CONF_THRESHOLD)memcpy(nmsboxes[0],boxes[0],(NUM_CLASS+5)*4);
	else return 0;
	for (uint16_t i=0; i<MAX_BOXNUM;i++)
	{
		if(boxes[i][4]<CONF_THRESHOLD)
		{
			valid_box=i;
			break;
		}
		else S[i]=(boxes[i][2]-boxes[i][0])*(boxes[i][3]-boxes[i][1]);
	}
	uint16_t index_nms_boxes=1;

	for (uint16_t i=1; i<valid_box;i++)
	{
		float maxiou=0;
		for (uint16_t j=0; j<i;j++)
		{
			float Si=(MIN(boxes[j][2],boxes[i][2])-MAX(boxes[j][0],boxes[i][0]))*(MIN(boxes[j][3],boxes[i][3])-MAX(boxes[j][1],boxes[i][1]));
			float iou=Si/(S[j]+S[i]-Si);
			if(iou>maxiou) maxiou=iou;
		}
		if(maxiou<NMS_IOU)
		{
			memcpy(nmsboxes[index_nms_boxes],boxes[i],(NUM_CLASS+5)*4);
			index_nms_boxes++;
		}
	}
	return 0;
}
/*
 * Anchors
 */
uint8_t anchors[NUM_ANCHOR][2] = {{13,13}, {17,18}, {27,25}};

/*
 * yolo_head
 * Boxes are the output of whole model.
 * void * data: output of ai model
 * boxes : provide MAX_BOXNUM boxes (x1,y1, x2,y2, confidence, mark0, mark1)
 */
int post_process(void * data, float boxes[MAX_BOXNUM][NUM_CLASS+5])
{
#define CONF_THRESHOLD 0.1
	int8_t* out_data=data;
	int grid_x, grid_y;
	float x, y, w ,h;
	float x1, y1, x2, y2;
	float box[NUM_CLASS+5];
	for(int i = 0; i < FEATHW*FEATHW; i++)
	{
		for(int j = 0; j < NUM_ANCHOR; j++)
		{
			// 网络输出维度1*9*9*21
			// 其中21维度包含了每个像素预测的三个锚框，每个锚框对7个维度，依次为x y w h conf1 conf2 class
			// 当然因为这个网络是单类检测，以class这一维度没有
			int8_t conf = out_data[i*NUM_ANCHOR*(NUM_CLASS+5)+j*(NUM_CLASS+5)+4];
			int8_t mark0 = out_data[i*NUM_ANCHOR*(NUM_CLASS+5)+j*(NUM_CLASS+5)+5];
			int8_t mark1 = out_data[i*NUM_ANCHOR*(NUM_CLASS+5)+j*(NUM_CLASS+5)+6];
			// 公式sigmoid((conf+b)*a) < conf f
			// 0.09796401113271713 * (q - 17)
			float b=-37, a=0.2262936532497406 ;//>>conf>
			float conff=sigmoid( (((float)conf)+b)*a );
			float mark0f=sigmoid( (((float)mark0)+b)*a );
			float mark1f=sigmoid( (((float)mark1)+b)*a );
			//置信程度返回坐标
			if(conff > CONF_THRESHOLD)
			{
				grid_x = i % FEATHW;
				grid_y = i / FEATHW;
				x = (float)(out_data[i*NUM_ANCHOR*(NUM_CLASS+5)+j*(NUM_CLASS+5)]+b)*a;
				y = (float)(out_data[i*NUM_ANCHOR*(NUM_CLASS+5)+j*(NUM_CLASS+5)+1]+b)*a;
				w = (float)(out_data[i*NUM_ANCHOR*(NUM_CLASS+5)+j*(NUM_CLASS+5)+2]+b)*a;
				h = (float)(out_data[i*NUM_ANCHOR*(NUM_CLASS+5)+j*(NUM_CLASS+5)+3]+b)*a;
				x = (sigmoid(x)+grid_x) * 8;
				y = (sigmoid(y)+grid_y) * 8;
				w = expf(w) * anchors[j][0];
				h = expf(h) * anchors[j][1];
				y1 = (x - w/2);
				y2 = (x + w/2);
				x1 = y - h/2;
				x2 = y + h/2;
				if(x1 < 0) x1 = 0;
				if(y1 < 0) y1 = 0;
				if(x2 > IMGHW-1) x2 = IMGHW-1;
				if(y2 > IMGHW-1) y2 = IMGHW-1;
				//左上角坐标为(x1, y1)，左下角坐标�?????(x2, y2) conf1f conf2f
				box[0]=x1;box[1]=y1;box[2]=x2;box[3]=y2;
				box[4]=conff;box[5]=mark0f;box[6]=mark1f;
				sort(boxes, box);
			}
		}
	}
  return 0;
}
/* USER CODE END 2 */

/*************************************************************************
  *
  */
void MX_X_CUBE_AI_Init(void)
{
    /* USER CODE BEGIN 5 */
  printf("\r\nTEMPLATE - initialization\r\n");

  ai_boostrap(ai_yolobody_data_weights_get(), activations);
    /* USER CODE END 5 */
}

void MX_X_CUBE_AI_Process(void)
{
    /* USER CODE BEGIN 6 */
  int res = -1;
  uint8_t *in_data = NULL;
  uint8_t *out_data = NULL;
  //memcpy(in_data_s, indata, IMGHW*IMGHW*3);
  float boxes[MAX_BOXNUM][NUM_CLASS+5]={0};

  if (yolobody) {
    if ((yolobody_info.n_inputs != 1) || (yolobody_info.n_outputs != 1))
    {
      ai_error err = {AI_ERROR_INVALID_PARAM, AI_ERROR_CODE_OUT_OF_RANGE};
      ai_log_err(err, "template code should be updated\r\n to support a model with multiple IO");
      return;
    }
    in_data = in_data_s;
    out_data = out_data_s;
    // m1 位于 pic.h 按行列色展开，eg [第一行[第一列[R,G,B]] [第二列[R,G,B]]..]
	res = acquire_and_process_data(m1, in_data);
	if (res == 0)
	res = ai_run(in_data, out_data);
	if (res == 0)
	res = post_process(out_data, boxes);
	float nmsboxes[MAX_BOXNUM][NUM_CLASS+5]={0};
	res = NMS(boxes,nmsboxes);
	printf("\r\nTEMPLATE - done once\r\n");
  }

  if (res)
  {
    ai_error err = {AI_ERROR_INVALID_STATE, AI_ERROR_CODE_NETWORK};
    ai_log_err(err, "Process has FAILED");
  }
    /* USER CODE END 6 */
}
#ifdef __cplusplus
}
#endif
