/**
  ******************************************************************************
  * @file    yolobody.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Jul 13 16:12:16 2022
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "yolobody.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



/*
#define AI_TOOLS_VERSION_MAJOR 6
#define AI_TOOLS_VERSION_MINOR 0
#define AI_TOOLS_VERSION_MICRO 0
#define AI_TOOLS_VERSION_EXTRA "RC6"

*/

/*
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 4
#define AI_TOOLS_API_VERSION_MICRO 0
*/

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_yolobody
 
#undef AI_YOLOBODY_MODEL_SIGNATURE
#define AI_YOLOBODY_MODEL_SIGNATURE     "34eca0ae3af596079eca40bfeb6f9e8a"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Jul 13 16:12:16 2022"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_YOLOBODY_N_BATCHES
#define AI_YOLOBODY_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array input_1_output_array;   /* Array #0 */
AI_STATIC ai_array conv2d_1_output_array;   /* Array #1 */
AI_STATIC ai_array conv2d_4_output_array;   /* Array #2 */
AI_STATIC ai_array conv2d_5_output_array;   /* Array #3 */
AI_STATIC ai_array conv2d_7_output_array;   /* Array #4 */
AI_STATIC ai_array conv2d_9_output_array;   /* Array #5 */
AI_STATIC ai_array concat_13_output_array;   /* Array #6 */
AI_STATIC ai_array conv2d_14_output_array;   /* Array #7 */
AI_STATIC ai_array concat_18_output_array;   /* Array #8 */
AI_STATIC ai_array conv2d_20_output_array;   /* Array #9 */
AI_STATIC ai_array conv2d_21_output_array;   /* Array #10 */
AI_STATIC ai_array conv2d_23_output_array;   /* Array #11 */
AI_STATIC ai_array conv2d_25_output_array;   /* Array #12 */
AI_STATIC ai_array concat_28_output_array;   /* Array #13 */
AI_STATIC ai_array conv2d_29_output_array;   /* Array #14 */
AI_STATIC ai_array concat_33_output_array;   /* Array #15 */
AI_STATIC ai_array conv2d_34_output_array;   /* Array #16 */
AI_STATIC ai_array conv2d_36_output_array;   /* Array #17 */
AI_STATIC ai_array conv2d_1_weights_array;   /* Array #18 */
AI_STATIC ai_array conv2d_1_bias_array;   /* Array #19 */
AI_STATIC ai_array conv2d_4_weights_array;   /* Array #20 */
AI_STATIC ai_array conv2d_4_bias_array;   /* Array #21 */
AI_STATIC ai_array conv2d_5_weights_array;   /* Array #22 */
AI_STATIC ai_array conv2d_5_bias_array;   /* Array #23 */
AI_STATIC ai_array conv2d_7_weights_array;   /* Array #24 */
AI_STATIC ai_array conv2d_7_bias_array;   /* Array #25 */
AI_STATIC ai_array conv2d_9_weights_array;   /* Array #26 */
AI_STATIC ai_array conv2d_9_bias_array;   /* Array #27 */
AI_STATIC ai_array conv2d_14_weights_array;   /* Array #28 */
AI_STATIC ai_array conv2d_14_bias_array;   /* Array #29 */
AI_STATIC ai_array conv2d_20_weights_array;   /* Array #30 */
AI_STATIC ai_array conv2d_20_bias_array;   /* Array #31 */
AI_STATIC ai_array conv2d_21_weights_array;   /* Array #32 */
AI_STATIC ai_array conv2d_21_bias_array;   /* Array #33 */
AI_STATIC ai_array conv2d_23_weights_array;   /* Array #34 */
AI_STATIC ai_array conv2d_23_bias_array;   /* Array #35 */
AI_STATIC ai_array conv2d_25_weights_array;   /* Array #36 */
AI_STATIC ai_array conv2d_25_bias_array;   /* Array #37 */
AI_STATIC ai_array conv2d_29_weights_array;   /* Array #38 */
AI_STATIC ai_array conv2d_29_bias_array;   /* Array #39 */
AI_STATIC ai_array conv2d_34_weights_array;   /* Array #40 */
AI_STATIC ai_array conv2d_34_bias_array;   /* Array #41 */
AI_STATIC ai_array conv2d_36_weights_array;   /* Array #42 */
AI_STATIC ai_array conv2d_36_bias_array;   /* Array #43 */
AI_STATIC ai_array conv2d_1_scratch0_array;   /* Array #44 */
AI_STATIC ai_array conv2d_1_scratch1_array;   /* Array #45 */
AI_STATIC ai_array conv2d_4_scratch0_array;   /* Array #46 */
AI_STATIC ai_array conv2d_5_scratch0_array;   /* Array #47 */
AI_STATIC ai_array conv2d_5_scratch1_array;   /* Array #48 */
AI_STATIC ai_array conv2d_7_scratch0_array;   /* Array #49 */
AI_STATIC ai_array conv2d_7_scratch1_array;   /* Array #50 */
AI_STATIC ai_array conv2d_9_scratch0_array;   /* Array #51 */
AI_STATIC ai_array conv2d_9_scratch1_array;   /* Array #52 */
AI_STATIC ai_array conv2d_14_scratch0_array;   /* Array #53 */
AI_STATIC ai_array conv2d_14_scratch1_array;   /* Array #54 */
AI_STATIC ai_array conv2d_20_scratch0_array;   /* Array #55 */
AI_STATIC ai_array conv2d_21_scratch0_array;   /* Array #56 */
AI_STATIC ai_array conv2d_21_scratch1_array;   /* Array #57 */
AI_STATIC ai_array conv2d_23_scratch0_array;   /* Array #58 */
AI_STATIC ai_array conv2d_23_scratch1_array;   /* Array #59 */
AI_STATIC ai_array conv2d_25_scratch0_array;   /* Array #60 */
AI_STATIC ai_array conv2d_25_scratch1_array;   /* Array #61 */
AI_STATIC ai_array conv2d_29_scratch0_array;   /* Array #62 */
AI_STATIC ai_array conv2d_29_scratch1_array;   /* Array #63 */
AI_STATIC ai_array conv2d_34_scratch0_array;   /* Array #64 */
AI_STATIC ai_array conv2d_34_scratch1_array;   /* Array #65 */
AI_STATIC ai_array conv2d_36_scratch0_array;   /* Array #66 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor input_1_output;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_1_output;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_4_output;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_5_output;   /* Tensor #3 */
AI_STATIC ai_tensor conv2d_7_output;   /* Tensor #4 */
AI_STATIC ai_tensor conv2d_9_output;   /* Tensor #5 */
AI_STATIC ai_tensor concat_13_output;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_14_output;   /* Tensor #7 */
AI_STATIC ai_tensor concat_18_output;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_20_output;   /* Tensor #9 */
AI_STATIC ai_tensor conv2d_21_output;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_23_output;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_25_output;   /* Tensor #12 */
AI_STATIC ai_tensor concat_28_output;   /* Tensor #13 */
AI_STATIC ai_tensor conv2d_29_output;   /* Tensor #14 */
AI_STATIC ai_tensor concat_33_output;   /* Tensor #15 */
AI_STATIC ai_tensor conv2d_34_output;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_36_output;   /* Tensor #17 */
AI_STATIC ai_tensor conv2d_1_weights;   /* Tensor #18 */
AI_STATIC ai_tensor conv2d_1_bias;   /* Tensor #19 */
AI_STATIC ai_tensor conv2d_4_weights;   /* Tensor #20 */
AI_STATIC ai_tensor conv2d_4_bias;   /* Tensor #21 */
AI_STATIC ai_tensor conv2d_5_weights;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_5_bias;   /* Tensor #23 */
AI_STATIC ai_tensor conv2d_7_weights;   /* Tensor #24 */
AI_STATIC ai_tensor conv2d_7_bias;   /* Tensor #25 */
AI_STATIC ai_tensor conv2d_9_weights;   /* Tensor #26 */
AI_STATIC ai_tensor conv2d_9_bias;   /* Tensor #27 */
AI_STATIC ai_tensor conv2d_14_weights;   /* Tensor #28 */
AI_STATIC ai_tensor conv2d_14_bias;   /* Tensor #29 */
AI_STATIC ai_tensor conv2d_20_weights;   /* Tensor #30 */
AI_STATIC ai_tensor conv2d_20_bias;   /* Tensor #31 */
AI_STATIC ai_tensor conv2d_21_weights;   /* Tensor #32 */
AI_STATIC ai_tensor conv2d_21_bias;   /* Tensor #33 */
AI_STATIC ai_tensor conv2d_23_weights;   /* Tensor #34 */
AI_STATIC ai_tensor conv2d_23_bias;   /* Tensor #35 */
AI_STATIC ai_tensor conv2d_25_weights;   /* Tensor #36 */
AI_STATIC ai_tensor conv2d_25_bias;   /* Tensor #37 */
AI_STATIC ai_tensor conv2d_29_weights;   /* Tensor #38 */
AI_STATIC ai_tensor conv2d_29_bias;   /* Tensor #39 */
AI_STATIC ai_tensor conv2d_34_weights;   /* Tensor #40 */
AI_STATIC ai_tensor conv2d_34_bias;   /* Tensor #41 */
AI_STATIC ai_tensor conv2d_36_weights;   /* Tensor #42 */
AI_STATIC ai_tensor conv2d_36_bias;   /* Tensor #43 */
AI_STATIC ai_tensor conv2d_1_scratch0;   /* Tensor #44 */
AI_STATIC ai_tensor conv2d_1_scratch1;   /* Tensor #45 */
AI_STATIC ai_tensor conv2d_4_scratch0;   /* Tensor #46 */
AI_STATIC ai_tensor conv2d_5_scratch0;   /* Tensor #47 */
AI_STATIC ai_tensor conv2d_5_scratch1;   /* Tensor #48 */
AI_STATIC ai_tensor conv2d_7_scratch0;   /* Tensor #49 */
AI_STATIC ai_tensor conv2d_7_scratch1;   /* Tensor #50 */
AI_STATIC ai_tensor conv2d_9_scratch0;   /* Tensor #51 */
AI_STATIC ai_tensor conv2d_9_scratch1;   /* Tensor #52 */
AI_STATIC ai_tensor conv2d_14_scratch0;   /* Tensor #53 */
AI_STATIC ai_tensor conv2d_14_scratch1;   /* Tensor #54 */
AI_STATIC ai_tensor conv2d_20_scratch0;   /* Tensor #55 */
AI_STATIC ai_tensor conv2d_21_scratch0;   /* Tensor #56 */
AI_STATIC ai_tensor conv2d_21_scratch1;   /* Tensor #57 */
AI_STATIC ai_tensor conv2d_23_scratch0;   /* Tensor #58 */
AI_STATIC ai_tensor conv2d_23_scratch1;   /* Tensor #59 */
AI_STATIC ai_tensor conv2d_25_scratch0;   /* Tensor #60 */
AI_STATIC ai_tensor conv2d_25_scratch1;   /* Tensor #61 */
AI_STATIC ai_tensor conv2d_29_scratch0;   /* Tensor #62 */
AI_STATIC ai_tensor conv2d_29_scratch1;   /* Tensor #63 */
AI_STATIC ai_tensor conv2d_34_scratch0;   /* Tensor #64 */
AI_STATIC ai_tensor conv2d_34_scratch1;   /* Tensor #65 */
AI_STATIC ai_tensor conv2d_36_scratch0;   /* Tensor #66 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv2d_1_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_4_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_5_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain conv2d_7_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv2d_9_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain concat_13_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain conv2d_14_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain concat_18_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain conv2d_20_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain conv2d_21_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain conv2d_23_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain conv2d_25_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain concat_28_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain conv2d_29_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain concat_33_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain conv2d_34_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain conv2d_36_chain;   /* Chain #16 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d conv2d_1_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv2d_4_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv2d_5_layer; /* Layer #2 */
AI_STATIC ai_layer_conv2d conv2d_7_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d conv2d_9_layer; /* Layer #4 */
AI_STATIC ai_layer_concat concat_13_layer; /* Layer #5 */
AI_STATIC ai_layer_conv2d conv2d_14_layer; /* Layer #6 */
AI_STATIC ai_layer_concat concat_18_layer; /* Layer #7 */
AI_STATIC ai_layer_conv2d conv2d_20_layer; /* Layer #8 */
AI_STATIC ai_layer_conv2d conv2d_21_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d conv2d_23_layer; /* Layer #10 */
AI_STATIC ai_layer_conv2d conv2d_25_layer; /* Layer #11 */
AI_STATIC ai_layer_concat concat_28_layer; /* Layer #12 */
AI_STATIC ai_layer_conv2d conv2d_29_layer; /* Layer #13 */
AI_STATIC ai_layer_concat concat_33_layer; /* Layer #14 */
AI_STATIC ai_layer_conv2d conv2d_34_layer; /* Layer #15 */
AI_STATIC ai_layer_conv2d conv2d_36_layer; /* Layer #16 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  input_1_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 15552, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10368, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2592, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5184, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5184, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5184, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  concat_13_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10368, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5184, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  concat_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10368, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2592, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  concat_28_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2592, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  concat_33_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2592, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1701, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 216, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 72, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 21, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 652, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10368, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 297, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 192, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5184, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5408, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5184, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5408, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5184, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5184, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1185, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5408, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5408, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6496, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5990, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(input_1_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0375872477889061f),
    AI_PACK_INTQ_ZP(-111)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02221255749464035f),
    AI_PACK_INTQ_ZP(-8)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.049308910965919495f),
    AI_PACK_INTQ_ZP(-105)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.049282342195510864f),
    AI_PACK_INTQ_ZP(-106)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.049886833876371384f),
    AI_PACK_INTQ_ZP(-107)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_13_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05004185065627098f),
    AI_PACK_INTQ_ZP(-106)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.049470189958810806f),
    AI_PACK_INTQ_ZP(-105)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04955572262406349f),
    AI_PACK_INTQ_ZP(-105)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.040862664580345154f),
    AI_PACK_INTQ_ZP(-10)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03364114090800285f),
    AI_PACK_INTQ_ZP(-102)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02879694290459156f),
    AI_PACK_INTQ_ZP(-105)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03377246484160423f),
    AI_PACK_INTQ_ZP(-107)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_28_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03377246484160423f),
    AI_PACK_INTQ_ZP(-107)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.041662272065877914f),
    AI_PACK_INTQ_ZP(-110)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(concat_33_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04216764494776726f),
    AI_PACK_INTQ_ZP(-108)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04248003289103508f),
    AI_PACK_INTQ_ZP(-109)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18038468062877655f),
    AI_PACK_INTQ_ZP(44)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03843438997864723f, 0.01815941371023655f, 0.02681398019194603f, 0.005188837181776762f, 0.03084562160074711f, 0.020029719918966293f, 0.007690173573791981f, 0.017115285620093346f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00015072310634423047f, 7.12133914930746e-05f, 0.00010515286703594029f, 2.0348381440271623e-05f, 0.0001209632318932563f, 7.854792784200981e-05f, 3.015754555235617e-05f, 6.711877358611673e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0024790074676275253f, 0.0025897626765072346f, 0.002501619979739189f, 0.002155572408810258f, 0.0021732542663812637f, 0.0018963463371619582f, 0.0014912623446434736f, 0.002388187451288104f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.317907097283751e-05f, 9.734205377753824e-05f, 9.402901196153834e-05f, 8.102203719317913e-05f, 8.168664498953149e-05f, 7.12784385541454e-05f, 5.605244587059133e-05f, 8.976539538707584e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02271071821451187f, 0.027263101190328598f, 0.021175293251872063f, 0.019233642145991325f, 0.02756654843688011f, 0.035980310291051865f, 0.023055873811244965f, 0.021820951253175735f, 0.022336818277835846f, 0.01873365417122841f, 0.028857003897428513f, 0.02192898839712143f, 0.02591552585363388f, 0.02885790541768074f, 0.023050233721733093f, 0.02528977580368519f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005044631543569267f, 0.0006055831909179688f, 0.0004703574231825769f, 0.00042722836951725185f, 0.0006123235216364264f, 0.0007992147002369165f, 0.0005121299182064831f, 0.00048469912144355476f, 0.0004961578524671495f, 0.0004161223769187927f, 0.0006409878842532635f, 0.0004870989068876952f, 0.0005756501341238618f, 0.0006410079076886177f, 0.0005120046553201973f, 0.0005617506103590131f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0025512175634503365f, 0.0017855798359960318f, 0.0018041386501863599f, 0.0017512789927423f, 0.001988113857805729f, 0.0030246805399656296f, 0.002054990967735648f, 0.002438407391309738f, 0.0017246045172214508f, 0.0019097101176157594f, 0.0018730844603851438f, 0.0018350514583289623f, 0.0024627551902085543f, 0.0030370166059583426f, 0.002546088770031929f, 0.001618983456864953f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001257977564819157f, 8.804499520920217e-05f, 8.896011422621086e-05f, 8.635366248199716e-05f, 9.803172724787146e-05f, 0.00014914369967300445f, 0.00010132936586160213f, 0.00012023521412629634f, 8.5038373072166e-05f, 9.416572720510885e-05f, 9.235975448973477e-05f, 9.048439096659422e-05f, 0.00012143577623646706f, 0.0001497519842814654f, 0.00012554485874716192f, 7.983030809555203e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0021186138037592173f, 0.0015519957523792982f, 0.00225588446483016f, 0.001845471328124404f, 0.0025938963517546654f, 0.0020716791041195393f, 0.002641229424625635f, 0.0029530541505664587f, 0.0016958820633590221f, 0.002677521901205182f, 0.0026016272604465485f, 0.0023025188129395247f, 0.003123128553852439f, 0.001789441448636353f, 0.002516499487683177f, 0.0020050290040671825f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00010441025369800627f, 7.648598693776876e-05f, 0.0001111752717406489f, 9.09491500351578e-05f, 0.0001278332929359749f, 0.0001020971976686269f, 0.00013016597949899733f, 0.00014553342771250755f, 8.357704064110294e-05f, 0.0001319545553997159f, 0.000128214291180484f, 0.0001134735211962834f, 0.00015391508350148797f, 8.818786591291428e-05f, 0.00012401898857206106f, 9.881252481136471e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004282050766050816f, 0.005208312999457121f, 0.003271509427577257f, 0.004514079540967941f, 0.003286462975665927f, 0.006152354646474123f, 0.0037253210321068764f, 0.0032151213381439447f, 0.004915197379887104f, 0.004160032607614994f, 0.004318578634411097f, 0.003829005640000105f, 0.002384307561442256f, 0.0047380742616951466f, 0.004410642199218273f, 0.004912509582936764f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00021428173931781203f, 0.0002606336202006787f, 0.0001637123932596296f, 0.00022589288710150868f, 0.00016446069639641792f, 0.00030787521973252296f, 0.0001864219520939514f, 0.00016089061682578176f, 0.0002459655806887895f, 0.00020817572658415884f, 0.0002161096635973081f, 0.00019161052478011698f, 0.00011931516201002523f, 0.00023710200912319124f, 0.00022071669809520245f, 0.00024583106278441846f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0011969766346737742f, 0.001619868678972125f, 0.0012583174975588918f, 0.0014441045932471752f, 0.0021673848386853933f, 0.0012960727326571941f, 0.0013304540188983083f, 0.0012584943324327469f, 0.0010148521978408098f, 0.0007718757260590792f, 0.0019481723429635167f, 0.0012564975768327713f, 0.0007271493086591363f, 0.0013551118317991495f, 0.0008580703288316727f, 0.0011466831201687455f, 0.0013498060870915651f, 0.001903426367789507f, 0.001881426083855331f, 0.0018371072364971042f, 0.0017677504802122712f, 0.002010767813771963f, 0.0016341625014320016f, 0.0013559556100517511f, 0.001544178114272654f, 0.0014720698818564415f, 0.0018712976016104221f, 0.0013798406580463052f, 0.0019711595959961414f, 0.001425154972821474f, 0.0019764951430261135f, 0.001714165904559195f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.931704072281718e-05f, 8.027376316022128e-05f, 6.235683395061642e-05f, 7.156364881666377e-05f, 0.00010740631842054427f, 6.422781734727323e-05f, 6.593161378987134e-05f, 6.23655942035839e-05f, 5.029173553339206e-05f, 3.825085877906531e-05f, 9.654308814788237e-05f, 6.226664845598862e-05f, 3.6034409276908264e-05f, 6.715354538755491e-05f, 4.252229700796306e-05f, 5.682471237378195e-05f, 6.689061410725117e-05f, 9.432566730538383e-05f, 9.323543054051697e-05f, 9.103917545871809e-05f, 8.760215132497251e-05f, 9.96450544334948e-05f, 8.098210673779249e-05f, 6.719536031596363e-05f, 7.652286149095744e-05f, 7.294948591152206e-05f, 9.273350588046014e-05f, 6.837899854872376e-05f, 9.768224117578939e-05f, 7.06245846231468e-05f, 9.79466421995312e-05f, 8.494673238601536e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005301132332533598f, 0.007658884394913912f, 0.006444096099585295f, 0.00638345954939723f, 0.008337114006280899f, 0.006401145830750465f, 0.009766870178282261f, 0.0090938163921237f, 0.007855472154915333f, 0.006354561075568199f, 0.007317929994314909f, 0.008230245672166348f, 0.006768550258129835f, 0.009372678585350513f, 0.00484289787709713f, 0.0066024791449308395f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002166183985536918f, 0.00031296242377720773f, 0.00026332293055020273f, 0.0002608451759442687f, 0.0003406766918487847f, 0.0002615678822621703f, 0.0003991003322880715f, 0.00037159756175242364f, 0.0003209955175407231f, 0.00025966428802348673f, 0.00029903012909926474f, 0.0003363097785040736f, 0.000276581005891785f, 0.00038299261359497905f, 0.00019789370708167553f, 0.0002697948948480189f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0020546994637697935f, 0.0024483774323016405f, 0.002472464693710208f, 0.0023121945559978485f, 0.002407414373010397f, 0.0029176902025938034f, 0.0017716983566060662f, 0.0022468625102192163f, 0.001539192977361381f, 0.0026014421600848436f, 0.0020947640296071768f, 0.0025516184978187084f, 0.0018680664943531156f, 0.0023209641221910715f, 0.0023527664598077536f, 0.0025289985351264477f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.912243406986818e-05f, 8.23662121547386e-05f, 8.317653555423021e-05f, 7.778486178722233e-05f, 8.09881676104851e-05f, 9.815442899707705e-05f, 5.960195267107338e-05f, 7.558702054666355e-05f, 5.178020728635602e-05f, 8.751548011787236e-05f, 7.047025428619236e-05f, 8.583935414208099e-05f, 6.284388655330986e-05f, 7.807988004060462e-05f, 7.914975140010938e-05f, 8.507839811500162e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0022284339647740126f, 0.0022908139508217573f, 0.001969355158507824f, 0.0026081979740411043f, 0.0036021701525896788f, 0.0019707106985151768f, 0.0025919037871062756f, 0.002114750212058425f, 0.0026640405412763357f, 0.0025935706216841936f, 0.002875249832868576f, 0.0014636473497375846f, 0.001959073357284069f, 0.0029692340176552534f, 0.00302089168690145f, 0.002492617815732956f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.417208351194859e-05f, 6.596843741135672e-05f, 5.671140752383508e-05f, 7.510813156841323e-05f, 0.00010373148688813671f, 5.675044303643517e-05f, 7.463890506187454e-05f, 6.08983427810017e-05f, 7.671622006455436e-05f, 7.46869045542553e-05f, 8.27984040370211e-05f, 4.214856744511053e-05f, 5.6415323342662305e-05f, 8.550486381864175e-05f, 8.699244790477678e-05f, 7.177977386163548e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0033754275646060705f, 0.0037695940118283033f, 0.0035389065742492676f, 0.004500694572925568f, 0.0033919387497007847f, 0.0038900210056453943f, 0.004742783959954977f, 0.004924617242068052f, 0.004337798338383436f, 0.003294909605756402f, 0.0036291268188506365f, 0.004020043648779392f, 0.003884249832481146f, 0.0028122924268245697f, 0.005084384698420763f, 0.0037320037372410297f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011399650975363329f, 0.00012730847811326385f, 0.00011951760097872466f, 0.0001519995421404019f, 0.0001145541318692267f, 0.0001313755929004401f, 0.00016017550660762936f, 0.00016631645848974586f, 0.00014649814693257213f, 0.00011127721518278122f, 0.00012256455374881625f, 0.00013576677883975208f, 0.00013118068454787135f, 9.497804421698675e-05f, 0.00017171220679301769f, 0.00012603896902874112f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0017492700135335326f, 0.0017856089398264885f, 0.0018849954940378666f, 0.0018213046714663506f, 0.0017123165307566524f, 0.001827896572649479f, 0.001192396623082459f, 0.0014677330618724227f, 0.001709632109850645f, 0.0022396768908947706f, 0.001559111406095326f, 0.0016615306958556175f, 0.001954700332134962f, 0.001386122079566121f, 0.001886832993477583f, 0.0013983466196805239f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.37625960027799e-05f, 7.529492722824216e-05f, 7.94858206063509e-05f, 7.680012640776113e-05f, 7.220435509225354e-05f, 7.707809709245339e-05f, 5.0280556024517864e-05f, 6.189084524521604e-05f, 7.209116301964968e-05f, 9.444190072827041e-05f, 6.574405415449291e-05f, 7.006283703958616e-05f, 8.242511103162542e-05f, 5.844950283062644e-05f, 7.956330227898434e-05f, 5.8964982599718496e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 21,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0017220204463228583f, 0.0017548463074490428f, 0.0011661837343126535f, 0.0014102068962529302f, 0.003613504348322749f, 0.0036602597683668137f, 0.0032578592654317617f, 0.0018891611834987998f, 0.0023315344005823135f, 0.0006403852603398263f, 0.0008643507608212531f, 0.004688871093094349f, 0.003893817774951458f, 0.003539450466632843f, 0.0011432502651587129f, 0.0015213238075375557f, 0.0007736893021501601f, 0.001038464717566967f, 0.004473753739148378f, 0.004176840651780367f, 0.0034447323996573687f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_36_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 21,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.315148832276464e-05f, 7.454592559952289e-05f, 4.953952520736493e-05f, 5.9905636589974165e-05f, 0.0001535017800051719f, 0.00015548795636277646f, 0.0001383939670631662f, 8.025162969715893e-05f, 9.904366015689448e-05f, 2.7203586796531454e-05f, 3.671764716273174e-05f, 0.00019918339967262f, 0.0001654095103731379f, 0.000150355976074934f, 4.8565307224635035e-05f, 6.46258849883452e-05f, 3.286634819232859e-05f, 4.4114014599472284e-05f, 0.000190045204362832f, 0.00017743233183864504f, 0.00014633234241046011f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.060018762946128845f),
    AI_PACK_INTQ_ZP(-22)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0896376296877861f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08840997517108917f),
    AI_PACK_INTQ_ZP(-3)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08761933445930481f),
    AI_PACK_INTQ_ZP(-6)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.08902910351753235f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06397794932126999f),
    AI_PACK_INTQ_ZP(6)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05246172845363617f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05832425877451897f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.06745071709156036f),
    AI_PACK_INTQ_ZP(-20)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07151791453361511f),
    AI_PACK_INTQ_ZP(-13)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  input_1_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 72, 72), AI_STRIDE_INIT(4, 1, 1, 3, 216),
  1, &input_1_output_array, &input_1_output_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 36, 36), AI_STRIDE_INIT(4, 1, 1, 8, 288),
  1, &conv2d_1_output_array, &conv2d_1_output_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 18, 18), AI_STRIDE_INIT(4, 1, 1, 8, 144),
  1, &conv2d_4_output_array, &conv2d_4_output_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 18, 18), AI_STRIDE_INIT(4, 1, 1, 16, 288),
  1, &conv2d_5_output_array, &conv2d_5_output_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 18, 18), AI_STRIDE_INIT(4, 1, 1, 16, 288),
  1, &conv2d_7_output_array, &conv2d_7_output_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 18, 18), AI_STRIDE_INIT(4, 1, 1, 16, 288),
  1, &conv2d_9_output_array, &conv2d_9_output_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  concat_13_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 18, 18), AI_STRIDE_INIT(4, 1, 1, 32, 576),
  1, &concat_13_output_array, &concat_13_output_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 18, 18), AI_STRIDE_INIT(4, 1, 1, 16, 288),
  1, &conv2d_14_output_array, &conv2d_14_output_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  concat_18_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 18, 18), AI_STRIDE_INIT(4, 1, 1, 32, 576),
  1, &concat_18_output_array, &concat_18_output_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 9, 9), AI_STRIDE_INIT(4, 1, 1, 32, 288),
  1, &conv2d_20_output_array, &conv2d_20_output_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 9, 9), AI_STRIDE_INIT(4, 1, 1, 16, 144),
  1, &conv2d_21_output_array, &conv2d_21_output_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 9, 9), AI_STRIDE_INIT(4, 1, 1, 16, 144),
  1, &conv2d_23_output_array, &conv2d_23_output_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_output, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 9, 9), AI_STRIDE_INIT(4, 1, 1, 16, 144),
  1, &conv2d_25_output_array, &conv2d_25_output_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  concat_28_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 9, 9), AI_STRIDE_INIT(4, 1, 1, 32, 288),
  1, &concat_28_output_array, &concat_28_output_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_output, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 9, 9), AI_STRIDE_INIT(4, 1, 1, 16, 144),
  1, &conv2d_29_output_array, &conv2d_29_output_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  concat_33_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 9, 9), AI_STRIDE_INIT(4, 1, 1, 32, 288),
  1, &concat_33_output_array, &concat_33_output_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_output, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 9, 9), AI_STRIDE_INIT(4, 1, 1, 16, 144),
  1, &conv2d_34_output_array, &conv2d_34_output_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 21, 9, 9), AI_STRIDE_INIT(4, 1, 1, 21, 189),
  1, &conv2d_36_output_array, &conv2d_36_output_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 3, 8), AI_STRIDE_INIT(4, 1, 3, 9, 27),
  1, &conv2d_1_weights_array, &conv2d_1_weights_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_1_bias_array, &conv2d_1_bias_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 8, 3, 3, 1), AI_STRIDE_INIT(4, 1, 8, 24, 72),
  1, &conv2d_4_weights_array, &conv2d_4_weights_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_4_bias_array, &conv2d_4_bias_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_weights, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 16), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_5_weights_array, &conv2d_5_weights_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_bias, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_5_bias_array, &conv2d_5_bias_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  24, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 16), AI_STRIDE_INIT(4, 1, 16, 48, 144),
  1, &conv2d_7_weights_array, &conv2d_7_weights_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  25, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_7_bias_array, &conv2d_7_bias_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  26, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 16), AI_STRIDE_INIT(4, 1, 16, 48, 144),
  1, &conv2d_9_weights_array, &conv2d_9_weights_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_9_bias_array, &conv2d_9_bias_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_weights, AI_STATIC,
  28, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 16), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_14_weights_array, &conv2d_14_weights_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_bias, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_14_bias_array, &conv2d_14_bias_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_weights, AI_STATIC,
  30, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 1), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_20_weights_array, &conv2d_20_weights_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_bias, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_20_bias_array, &conv2d_20_bias_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_weights, AI_STATIC,
  32, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 16), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_21_weights_array, &conv2d_21_weights_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_bias, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_21_bias_array, &conv2d_21_bias_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_weights, AI_STATIC,
  34, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 16), AI_STRIDE_INIT(4, 1, 16, 48, 144),
  1, &conv2d_23_weights_array, &conv2d_23_weights_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_bias, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_23_bias_array, &conv2d_23_bias_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_weights, AI_STATIC,
  36, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 16), AI_STRIDE_INIT(4, 1, 16, 48, 144),
  1, &conv2d_25_weights_array, &conv2d_25_weights_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_bias, AI_STATIC,
  37, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_25_bias_array, &conv2d_25_bias_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_weights, AI_STATIC,
  38, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 16), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_29_weights_array, &conv2d_29_weights_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_bias, AI_STATIC,
  39, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_29_bias_array, &conv2d_29_bias_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_weights, AI_STATIC,
  40, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 16), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_34_weights_array, &conv2d_34_weights_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_bias, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_34_bias_array, &conv2d_34_bias_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_weights, AI_STATIC,
  42, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 21), AI_STRIDE_INIT(4, 1, 16, 48, 144),
  1, &conv2d_36_weights_array, &conv2d_36_weights_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_bias, AI_STATIC,
  43, 0x1,
  AI_SHAPE_INIT(4, 1, 21, 1, 1), AI_STRIDE_INIT(4, 4, 4, 84, 84),
  1, &conv2d_36_bias_array, &conv2d_36_bias_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch0, AI_STATIC,
  44, 0x0,
  AI_SHAPE_INIT(4, 1, 652, 1, 1), AI_STRIDE_INIT(4, 1, 1, 652, 652),
  1, &conv2d_1_scratch0_array, NULL)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch1, AI_STATIC,
  45, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 36, 36), AI_STRIDE_INIT(4, 1, 1, 8, 288),
  1, &conv2d_1_scratch1_array, &conv2d_1_scratch1_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  46, 0x0,
  AI_SHAPE_INIT(4, 1, 297, 1, 1), AI_STRIDE_INIT(4, 1, 1, 297, 297),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch0, AI_STATIC,
  47, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 1, 1, 192, 192),
  1, &conv2d_5_scratch0_array, NULL)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch1, AI_STATIC,
  48, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 18, 18), AI_STRIDE_INIT(4, 1, 1, 16, 288),
  1, &conv2d_5_scratch1_array, &conv2d_5_scratch1_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  49, 0x0,
  AI_SHAPE_INIT(4, 1, 5408, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5408, 5408),
  1, &conv2d_7_scratch0_array, NULL)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch1, AI_STATIC,
  50, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 18, 18), AI_STRIDE_INIT(4, 1, 1, 16, 288),
  1, &conv2d_7_scratch1_array, &conv2d_7_scratch1_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  51, 0x0,
  AI_SHAPE_INIT(4, 1, 5408, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5408, 5408),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch1, AI_STATIC,
  52, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 18, 18), AI_STRIDE_INIT(4, 1, 1, 16, 288),
  1, &conv2d_9_scratch1_array, &conv2d_9_scratch1_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_scratch0, AI_STATIC,
  53, 0x0,
  AI_SHAPE_INIT(4, 1, 288, 1, 1), AI_STRIDE_INIT(4, 1, 1, 288, 288),
  1, &conv2d_14_scratch0_array, NULL)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_scratch1, AI_STATIC,
  54, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 18, 18), AI_STRIDE_INIT(4, 1, 1, 16, 288),
  1, &conv2d_14_scratch1_array, &conv2d_14_scratch1_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_scratch0, AI_STATIC,
  55, 0x0,
  AI_SHAPE_INIT(4, 1, 1185, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1185, 1185),
  1, &conv2d_20_scratch0_array, NULL)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch0, AI_STATIC,
  56, 0x0,
  AI_SHAPE_INIT(4, 1, 288, 1, 1), AI_STRIDE_INIT(4, 1, 1, 288, 288),
  1, &conv2d_21_scratch0_array, NULL)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch1, AI_STATIC,
  57, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 9, 9), AI_STRIDE_INIT(4, 1, 1, 16, 144),
  1, &conv2d_21_scratch1_array, &conv2d_21_scratch1_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch0, AI_STATIC,
  58, 0x0,
  AI_SHAPE_INIT(4, 1, 5408, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5408, 5408),
  1, &conv2d_23_scratch0_array, NULL)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch1, AI_STATIC,
  59, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 9, 9), AI_STRIDE_INIT(4, 1, 1, 16, 144),
  1, &conv2d_23_scratch1_array, &conv2d_23_scratch1_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch0, AI_STATIC,
  60, 0x0,
  AI_SHAPE_INIT(4, 1, 5408, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5408, 5408),
  1, &conv2d_25_scratch0_array, NULL)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch1, AI_STATIC,
  61, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 9, 9), AI_STRIDE_INIT(4, 1, 1, 16, 144),
  1, &conv2d_25_scratch1_array, &conv2d_25_scratch1_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch0, AI_STATIC,
  62, 0x0,
  AI_SHAPE_INIT(4, 1, 288, 1, 1), AI_STRIDE_INIT(4, 1, 1, 288, 288),
  1, &conv2d_29_scratch0_array, NULL)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch1, AI_STATIC,
  63, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 9, 9), AI_STRIDE_INIT(4, 1, 1, 16, 144),
  1, &conv2d_29_scratch1_array, &conv2d_29_scratch1_intq)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch0, AI_STATIC,
  64, 0x0,
  AI_SHAPE_INIT(4, 1, 6496, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6496, 6496),
  1, &conv2d_34_scratch0_array, NULL)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch1, AI_STATIC,
  65, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 9, 9), AI_STRIDE_INIT(4, 1, 1, 16, 144),
  1, &conv2d_34_scratch1_array, &conv2d_34_scratch1_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_scratch0, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 1, 5990, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5990, 5990),
  1, &conv2d_36_scratch0_array, NULL)



/**  Layer declarations section  **********************************************/



AI_STATIC_CONST ai_i8 conv2d_1_nl_params_data[] = { -128, -128, -128, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -125, -124, -124, -124, -124, -124, -124, -123, -123, -123, -123, -123, -123, -122, -122, -122, -122, -122, -122, -122, -121, -121, -121, -121, -121, -121, -120, -120, -120, -120, -120, -120, -119, -119, -119, -119, -119, -119, -119, -118, -118, -118, -118, -118, -118, -117, -117, -117, -117, -117, -117, -116, -116, -116, -116, -116, -116, -115, -115, -115, -115, -115, -115, -115, -114, -114, -114, -114, -114, -114, -113, -113, -113, -113, -113, -113, -112, -112, -112, -112, -112, -112, -111, -111, -111, -111, -109, -108, -106, -105, -103, -101, -100, -98, -97, -95, -93, -92, -90, -89, -87, -85, -84, -82, -81, -79, -77, -76, -74, -73, -71, -69, -68, -66, -65, -63, -61, -60, -58, -57, -55, -54, -52, -50, -49, -47, -46, -44, -42, -41, -39, -38, -36, -34, -33, -31, -30, -28, -26, -25, -23, -22, -20, -18, -17, -15, -14, -12, -10, -9, -7, -6, -4, -2, -1, 1, 2, 4, 6, 7, 9, 10, 12, 14, 15, 17, 18, 20, 22, 23, 25, 26, 28, 30, 31, 33, 34, 36, 38, 39, 41, 42, 44, 45, 47, 49, 50, 52, 53, 55, 57, 58, 60, 61, 63, 65, 66, 68, 69, 71, 73, 74, 76, 77, 79, 81, 82, 84, 85, 87, 89, 90, 92, 93, 95, 97, 98, 100, 101, 103, 105, 106, 108, 109, 111, 113, 114, 116, 117, 119, 121, 122, 124, 125, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_1_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_1_nl_params_data, conv2d_1_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_weights, &conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_1_scratch0, &conv2d_1_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 2,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_1_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_4_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &conv2d_1_nl_params, 
  .nl_func = nl_func_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_weights, &conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_layer, 3,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_4_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_5_layer, AI_STATIC, 
  .groups = 8, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_5_nl_params_data[] = { -128, -128, -128, -128, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -124, -124, -124, -124, -124, -124, -123, -123, -123, -123, -123, -122, -122, -122, -122, -122, -122, -121, -121, -121, -121, -121, -120, -120, -120, -120, -120, -120, -119, -119, -119, -119, -119, -118, -118, -118, -118, -118, -118, -117, -117, -117, -117, -117, -116, -116, -116, -116, -116, -116, -115, -115, -115, -115, -115, -114, -114, -114, -114, -114, -114, -113, -113, -113, -113, -113, -112, -112, -112, -112, -112, -112, -111, -111, -111, -111, -111, -110, -110, -110, -110, -110, -110, -109, -109, -109, -109, -109, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -106, -106, -106, -106, -106, -106, -105, -105, -105, -103, -101, -100, -98, -96, -94, -92, -90, -89, -87, -85, -83, -81, -80, -78, -76, -74, -72, -70, -69, -67, -65, -63, -61, -60, -58, -56, -54, -52, -50, -49, -47, -45, -43, -41, -40, -38, -36, -34, -32, -30, -29, -27, -25, -23, -21, -20, -18, -16, -14, -12, -10, -9, -7, -5, -3, -1, 0, 2, 4, 6, 8, 10, 11, 13, 15, 17, 19, 20, 22, 24, 26, 28, 30, 31, 33, 35, 37, 39, 40, 42, 44, 46, 48, 50, 51, 53, 55, 57, 59, 60, 62, 64, 66, 68, 70, 71, 73, 75, 77, 79, 80, 82, 84, 86, 88, 90, 91, 93, 95, 97, 99, 100, 102, 104, 106, 108, 110, 111, 113, 115, 117, 119, 120, 122, 124, 126, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_5_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_5_nl_params_data, conv2d_5_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_5_output, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_5_weights, &conv2d_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_5_scratch0, &conv2d_5_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_5_layer, 6,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_5_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_7_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &conv2d_5_nl_params, 
  .nl_func = nl_func_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_7_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -124, -124, -124, -124, -124, -124, -123, -123, -123, -123, -123, -123, -122, -122, -122, -122, -122, -121, -121, -121, -121, -121, -121, -120, -120, -120, -120, -120, -119, -119, -119, -119, -119, -119, -118, -118, -118, -118, -118, -117, -117, -117, -117, -117, -117, -116, -116, -116, -116, -116, -116, -115, -115, -115, -115, -115, -114, -114, -114, -114, -114, -114, -113, -113, -113, -113, -113, -112, -112, -112, -112, -112, -112, -111, -111, -111, -111, -111, -110, -110, -110, -110, -110, -110, -109, -109, -109, -109, -109, -109, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -107, -106, -106, -106, -104, -102, -101, -99, -97, -95, -93, -92, -90, -88, -86, -84, -83, -81, -79, -77, -76, -74, -72, -70, -68, -67, -65, -63, -61, -59, -58, -56, -54, -52, -50, -49, -47, -45, -43, -41, -40, -38, -36, -34, -32, -31, -29, -27, -25, -23, -22, -20, -18, -16, -15, -13, -11, -9, -7, -6, -4, -2, 0, 2, 3, 5, 7, 9, 11, 12, 14, 16, 18, 20, 21, 23, 25, 27, 29, 30, 32, 34, 36, 38, 39, 41, 43, 45, 46, 48, 50, 52, 54, 55, 57, 59, 61, 63, 64, 66, 68, 70, 72, 73, 75, 77, 79, 81, 82, 84, 86, 88, 90, 91, 93, 95, 97, 99, 100, 102, 104, 106, 107, 109, 111, 113, 115, 116, 118, 120, 122, 124, 125, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_7_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_7_nl_params_data, conv2d_7_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_7_output, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_7_scratch0, &conv2d_7_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 8,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_7_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_9_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &conv2d_7_nl_params, 
  .nl_func = nl_func_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 conv2d_9_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -125, -124, -124, -124, -124, -124, -124, -123, -123, -123, -123, -123, -122, -122, -122, -122, -122, -122, -121, -121, -121, -121, -121, -121, -120, -120, -120, -120, -120, -119, -119, -119, -119, -119, -119, -118, -118, -118, -118, -118, -118, -117, -117, -117, -117, -117, -116, -116, -116, -116, -116, -116, -115, -115, -115, -115, -115, -115, -114, -114, -114, -114, -114, -113, -113, -113, -113, -113, -113, -112, -112, -112, -112, -112, -112, -111, -111, -111, -111, -111, -111, -110, -110, -110, -110, -110, -109, -109, -109, -109, -109, -109, -108, -108, -108, -108, -108, -108, -107, -107, -107, -105, -103, -102, -100, -98, -96, -95, -93, -91, -89, -88, -86, -84, -82, -81, -79, -77, -75, -74, -72, -70, -68, -67, -65, -63, -61, -60, -58, -56, -54, -53, -51, -49, -47, -46, -44, -42, -40, -39, -37, -35, -33, -31, -30, -28, -26, -24, -23, -21, -19, -17, -16, -14, -12, -10, -9, -7, -5, -3, -2, 0, 2, 4, 5, 7, 9, 11, 12, 14, 16, 18, 19, 21, 23, 25, 26, 28, 30, 32, 34, 35, 37, 39, 41, 42, 44, 46, 48, 49, 51, 53, 55, 56, 58, 60, 62, 63, 65, 67, 69, 70, 72, 74, 76, 77, 79, 81, 83, 84, 86, 88, 90, 91, 93, 95, 97, 98, 100, 102, 104, 106, 107, 109, 111, 113, 114, 116, 118, 120, 121, 123, 125, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_9_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_9_nl_params_data, conv2d_9_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_9_scratch0, &conv2d_9_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 10,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_9_chain,
  &AI_NET_OBJ_INSTANCE, &concat_13_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &conv2d_9_nl_params, 
  .nl_func = nl_func_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_9_output, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_13_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_13_layer, 13,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_13_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_14_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)


AI_STATIC_CONST ai_i8 conv2d_14_nl_params_data[] = { -128, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -124, -124, -124, -124, -124, -124, -123, -123, -123, -123, -123, -122, -122, -122, -122, -122, -122, -121, -121, -121, -121, -121, -120, -120, -120, -120, -120, -120, -119, -119, -119, -119, -119, -118, -118, -118, -118, -118, -118, -117, -117, -117, -117, -117, -117, -116, -116, -116, -116, -116, -115, -115, -115, -115, -115, -115, -114, -114, -114, -114, -114, -113, -113, -113, -113, -113, -113, -112, -112, -112, -112, -112, -111, -111, -111, -111, -111, -111, -110, -110, -110, -110, -110, -109, -109, -109, -109, -109, -109, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -106, -106, -106, -106, -106, -106, -105, -105, -105, -103, -101, -100, -98, -96, -94, -92, -91, -89, -87, -85, -83, -82, -80, -78, -76, -74, -73, -71, -69, -67, -65, -64, -62, -60, -58, -56, -55, -53, -51, -49, -47, -46, -44, -42, -40, -38, -37, -35, -33, -31, -29, -28, -26, -24, -22, -20, -19, -17, -15, -13, -11, -10, -8, -6, -4, -2, -1, 1, 3, 5, 7, 8, 10, 12, 14, 16, 17, 19, 21, 23, 25, 26, 28, 30, 32, 34, 35, 37, 39, 41, 43, 44, 46, 48, 50, 52, 53, 55, 57, 59, 61, 62, 64, 66, 68, 70, 71, 73, 75, 77, 79, 80, 82, 84, 86, 88, 89, 91, 93, 95, 97, 98, 100, 102, 104, 106, 107, 109, 111, 113, 115, 116, 118, 120, 122, 124, 125, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_14_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_14_nl_params_data, conv2d_14_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_14_weights, &conv2d_14_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_14_scratch0, &conv2d_14_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_14_layer, 15,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_14_chain,
  &AI_NET_OBJ_INSTANCE, &concat_18_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &conv2d_14_nl_params, 
  .nl_func = nl_func_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_5_output, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_18_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_18_layer, 18,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_18_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_20_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_20_weights, &conv2d_20_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_20_layer, 19,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_20_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_21_layer, AI_STATIC, 
  .groups = 32, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_21_nl_params_data[] = { -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -124, -124, -124, -124, -124, -123, -123, -123, -123, -123, -123, -122, -122, -122, -122, -122, -121, -121, -121, -121, -121, -120, -120, -120, -120, -120, -119, -119, -119, -119, -119, -119, -118, -118, -118, -118, -118, -117, -117, -117, -117, -117, -116, -116, -116, -116, -116, -116, -115, -115, -115, -115, -115, -114, -114, -114, -114, -114, -113, -113, -113, -113, -113, -112, -112, -112, -112, -112, -112, -111, -111, -111, -111, -111, -110, -110, -110, -110, -110, -109, -109, -109, -109, -109, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -106, -106, -106, -106, -106, -105, -105, -105, -105, -105, -104, -104, -104, -104, -104, -104, -103, -103, -103, -103, -103, -102, -102, -102, -100, -98, -96, -94, -92, -91, -89, -87, -85, -83, -81, -79, -77, -75, -73, -72, -70, -68, -66, -64, -62, -60, -58, -56, -54, -53, -51, -49, -47, -45, -43, -41, -39, -37, -35, -34, -32, -30, -28, -26, -24, -22, -20, -18, -16, -15, -13, -11, -9, -7, -5, -3, -1, 1, 3, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 122, 124, 126, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_21_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_21_nl_params_data, conv2d_21_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_21_output, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_21_weights, &conv2d_21_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_21_scratch0, &conv2d_21_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_layer, 22,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_21_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_23_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &conv2d_21_nl_params, 
  .nl_func = nl_func_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_i8 conv2d_23_nl_params_data[] = { -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -124, -124, -124, -124, -124, -124, -123, -123, -123, -123, -123, -122, -122, -122, -122, -122, -122, -121, -121, -121, -121, -121, -120, -120, -120, -120, -120, -120, -119, -119, -119, -119, -119, -118, -118, -118, -118, -118, -118, -117, -117, -117, -117, -117, -116, -116, -116, -116, -116, -116, -115, -115, -115, -115, -115, -114, -114, -114, -114, -114, -114, -113, -113, -113, -113, -113, -112, -112, -112, -112, -112, -112, -111, -111, -111, -111, -111, -110, -110, -110, -110, -110, -110, -109, -109, -109, -109, -109, -108, -108, -108, -108, -108, -108, -107, -107, -107, -107, -107, -106, -106, -106, -106, -106, -106, -105, -105, -105, -103, -101, -100, -98, -96, -94, -92, -90, -89, -87, -85, -83, -81, -79, -78, -76, -74, -72, -70, -69, -67, -65, -63, -61, -59, -58, -56, -54, -52, -50, -49, -47, -45, -43, -41, -39, -38, -36, -34, -32, -30, -28, -27, -25, -23, -21, -19, -18, -16, -14, -12, -10, -8, -7, -5, -3, -1, 1, 2, 4, 6, 8, 10, 12, 13, 15, 17, 19, 21, 23, 24, 26, 28, 30, 32, 33, 35, 37, 39, 41, 43, 44, 46, 48, 50, 52, 53, 55, 57, 59, 61, 63, 64, 66, 68, 70, 72, 74, 75, 77, 79, 81, 83, 84, 86, 88, 90, 92, 94, 95, 97, 99, 101, 103, 105, 106, 108, 110, 112, 114, 115, 117, 119, 121, 123, 125, 126 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_23_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_23_nl_params_data, conv2d_23_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_23_output, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_23_weights, &conv2d_23_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_23_scratch0, &conv2d_23_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_23_layer, 24,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_23_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_25_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &conv2d_23_nl_params, 
  .nl_func = nl_func_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 conv2d_25_nl_params_data[] = { -128, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -125, -124, -124, -124, -124, -124, -124, -123, -123, -123, -123, -123, -123, -122, -122, -122, -122, -122, -122, -121, -121, -121, -121, -121, -120, -120, -120, -120, -120, -120, -119, -119, -119, -119, -119, -119, -118, -118, -118, -118, -118, -118, -117, -117, -117, -117, -117, -116, -116, -116, -116, -116, -116, -115, -115, -115, -115, -115, -115, -114, -114, -114, -114, -114, -114, -113, -113, -113, -113, -113, -113, -112, -112, -112, -112, -112, -111, -111, -111, -111, -111, -111, -110, -110, -110, -110, -110, -110, -109, -109, -109, -109, -109, -109, -108, -108, -108, -108, -108, -108, -107, -107, -107, -105, -104, -102, -100, -98, -97, -95, -93, -91, -90, -88, -86, -85, -83, -81, -79, -78, -76, -74, -72, -71, -69, -67, -66, -64, -62, -60, -59, -57, -55, -53, -52, -50, -48, -47, -45, -43, -41, -40, -38, -36, -34, -33, -31, -29, -28, -26, -24, -22, -21, -19, -17, -15, -14, -12, -10, -9, -7, -5, -3, -2, 0, 2, 4, 5, 7, 9, 10, 12, 14, 16, 17, 19, 21, 23, 24, 26, 28, 29, 31, 33, 35, 36, 38, 40, 42, 43, 45, 47, 48, 50, 52, 54, 55, 57, 59, 61, 62, 64, 66, 67, 69, 71, 73, 74, 76, 78, 80, 81, 83, 85, 86, 88, 90, 92, 93, 95, 97, 99, 100, 102, 104, 105, 107, 109, 111, 112, 114, 116, 118, 119, 121, 123, 124, 126, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_25_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_25_nl_params_data, conv2d_25_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_25_weights, &conv2d_25_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_25_scratch0, &conv2d_25_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_25_layer, 26,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_25_chain,
  &AI_NET_OBJ_INSTANCE, &concat_28_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &conv2d_25_nl_params, 
  .nl_func = nl_func_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_25_output, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_28_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_28_layer, 28,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_28_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_29_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)


AI_STATIC_CONST ai_i8 conv2d_29_nl_params_data[] = { -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -125, -124, -124, -124, -124, -124, -124, -123, -123, -123, -123, -123, -123, -122, -122, -122, -122, -122, -122, -121, -121, -121, -121, -121, -121, -121, -120, -120, -120, -120, -120, -120, -119, -119, -119, -119, -119, -119, -118, -118, -118, -118, -118, -118, -117, -117, -117, -117, -117, -117, -116, -116, -116, -116, -116, -116, -116, -115, -115, -115, -115, -115, -115, -114, -114, -114, -114, -114, -114, -113, -113, -113, -113, -113, -113, -112, -112, -112, -112, -112, -112, -111, -111, -111, -111, -111, -111, -110, -110, -110, -110, -108, -107, -105, -104, -102, -100, -99, -97, -95, -94, -92, -91, -89, -87, -86, -84, -82, -81, -79, -78, -76, -74, -73, -71, -70, -68, -66, -65, -63, -61, -60, -58, -57, -55, -53, -52, -50, -48, -47, -45, -44, -42, -40, -39, -37, -36, -34, -32, -31, -29, -27, -26, -24, -23, -21, -19, -18, -16, -14, -13, -11, -10, -8, -6, -5, -3, -2, 0, 2, 3, 5, 7, 8, 10, 11, 13, 15, 16, 18, 20, 21, 23, 24, 26, 28, 29, 31, 32, 34, 36, 37, 39, 41, 42, 44, 45, 47, 49, 50, 52, 54, 55, 57, 58, 60, 62, 63, 65, 66, 68, 70, 71, 73, 75, 76, 78, 79, 81, 83, 84, 86, 88, 89, 91, 92, 94, 96, 97, 99, 100, 102, 104, 105, 107, 109, 110, 112, 113, 115, 117, 118, 120, 122, 123, 125, 126, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_29_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_29_nl_params_data, conv2d_29_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_29_weights, &conv2d_29_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_29_scratch0, &conv2d_29_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_29_layer, 30,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_29_chain,
  &AI_NET_OBJ_INSTANCE, &concat_33_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &conv2d_29_nl_params, 
  .nl_func = nl_func_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  concat_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_21_output, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_33_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  concat_33_layer, 33,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &concat_33_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_34_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)


AI_STATIC_CONST ai_i8 conv2d_34_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -125, -124, -124, -124, -124, -124, -124, -123, -123, -123, -123, -123, -123, -122, -122, -122, -122, -122, -122, -121, -121, -121, -121, -121, -121, -120, -120, -120, -120, -120, -120, -119, -119, -119, -119, -119, -119, -118, -118, -118, -118, -118, -118, -117, -117, -117, -117, -117, -117, -116, -116, -116, -116, -116, -116, -115, -115, -115, -115, -115, -115, -114, -114, -114, -114, -114, -114, -113, -113, -113, -113, -113, -113, -112, -112, -112, -112, -112, -112, -111, -111, -111, -111, -111, -111, -110, -110, -110, -110, -110, -110, -109, -109, -109, -107, -106, -104, -102, -101, -99, -97, -96, -94, -92, -90, -89, -87, -85, -84, -82, -80, -79, -77, -75, -74, -72, -70, -69, -67, -65, -64, -62, -60, -58, -57, -55, -53, -52, -50, -48, -47, -45, -43, -42, -40, -38, -37, -35, -33, -32, -30, -28, -27, -25, -23, -21, -20, -18, -16, -15, -13, -11, -10, -8, -6, -5, -3, -1, 0, 2, 4, 5, 7, 9, 11, 12, 14, 16, 17, 19, 21, 22, 24, 26, 27, 29, 31, 32, 34, 36, 37, 39, 41, 43, 44, 46, 48, 49, 51, 53, 54, 56, 58, 59, 61, 63, 64, 66, 68, 69, 71, 73, 75, 76, 78, 80, 81, 83, 85, 86, 88, 90, 91, 93, 95, 96, 98, 100, 101, 103, 105, 106, 108, 110, 112, 113, 115, 117, 118, 120, 122, 123, 125, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_34_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_34_nl_params_data, conv2d_34_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_34_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &concat_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_34_weights, &conv2d_34_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_34_scratch0, &conv2d_34_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_34_layer, 35,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_34_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_36_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &conv2d_34_nl_params, 
  .nl_func = nl_func_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_36_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_36_weights, &conv2d_36_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_36_layer, 36,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_36_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_36_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 19940, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 31104, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_YOLOBODY_IN_NUM, &input_1_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_YOLOBODY_OUT_NUM, &conv2d_36_output),
  &conv2d_1_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool yolobody_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, 4));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    input_1_output_array.data = AI_PTR(NULL);
    input_1_output_array.data_start = AI_PTR(NULL);
    conv2d_1_output_array.data = AI_PTR(activations + 2744);
    conv2d_1_output_array.data_start = AI_PTR(activations + 2744);
    conv2d_4_output_array.data = AI_PTR(activations + 2592);
    conv2d_4_output_array.data_start = AI_PTR(activations + 2592);
    conv2d_5_output_array.data = AI_PTR(activations + 10368);
    conv2d_5_output_array.data_start = AI_PTR(activations + 10368);
    conv2d_7_output_array.data = AI_PTR(activations + 20736);
    conv2d_7_output_array.data_start = AI_PTR(activations + 20736);
    conv2d_9_output_array.data = AI_PTR(activations + 25920);
    conv2d_9_output_array.data_start = AI_PTR(activations + 25920);
    concat_13_output_array.data = AI_PTR(activations + 0);
    concat_13_output_array.data_start = AI_PTR(activations + 0);
    conv2d_14_output_array.data = AI_PTR(activations + 21024);
    conv2d_14_output_array.data_start = AI_PTR(activations + 21024);
    concat_18_output_array.data = AI_PTR(activations + 0);
    concat_18_output_array.data_start = AI_PTR(activations + 0);
    conv2d_20_output_array.data = AI_PTR(activations + 11556);
    conv2d_20_output_array.data_start = AI_PTR(activations + 11556);
    conv2d_21_output_array.data = AI_PTR(activations + 1584);
    conv2d_21_output_array.data_start = AI_PTR(activations + 1584);
    conv2d_23_output_array.data = AI_PTR(activations + 8288);
    conv2d_23_output_array.data_start = AI_PTR(activations + 8288);
    conv2d_25_output_array.data = AI_PTR(activations + 9584);
    conv2d_25_output_array.data_start = AI_PTR(activations + 9584);
    concat_28_output_array.data = AI_PTR(activations + 2880);
    concat_28_output_array.data_start = AI_PTR(activations + 2880);
    conv2d_29_output_array.data = AI_PTR(activations + 5472);
    conv2d_29_output_array.data_start = AI_PTR(activations + 5472);
    concat_33_output_array.data = AI_PTR(activations + 2880);
    concat_33_output_array.data_start = AI_PTR(activations + 2880);
    conv2d_34_output_array.data = AI_PTR(activations + 1296);
    conv2d_34_output_array.data_start = AI_PTR(activations + 1296);
    conv2d_36_output_array.data = AI_PTR(NULL);
    conv2d_36_output_array.data_start = AI_PTR(NULL);
    conv2d_1_scratch0_array.data = AI_PTR(activations + 2092);
    conv2d_1_scratch0_array.data_start = AI_PTR(activations + 2092);
    conv2d_1_scratch1_array.data = AI_PTR(activations + 2744);
    conv2d_1_scratch1_array.data_start = AI_PTR(activations + 2744);
    conv2d_4_scratch0_array.data = AI_PTR(activations + 2092);
    conv2d_4_scratch0_array.data_start = AI_PTR(activations + 2092);
    conv2d_5_scratch0_array.data = AI_PTR(activations + 2092);
    conv2d_5_scratch0_array.data_start = AI_PTR(activations + 2092);
    conv2d_5_scratch1_array.data = AI_PTR(activations + 5184);
    conv2d_5_scratch1_array.data_start = AI_PTR(activations + 5184);
    conv2d_7_scratch0_array.data = AI_PTR(activations + 2092);
    conv2d_7_scratch0_array.data_start = AI_PTR(activations + 2092);
    conv2d_7_scratch1_array.data = AI_PTR(activations + 15552);
    conv2d_7_scratch1_array.data_start = AI_PTR(activations + 15552);
    conv2d_9_scratch0_array.data = AI_PTR(activations + 2092);
    conv2d_9_scratch0_array.data_start = AI_PTR(activations + 2092);
    conv2d_9_scratch1_array.data = AI_PTR(activations + 15552);
    conv2d_9_scratch1_array.data_start = AI_PTR(activations + 15552);
    conv2d_14_scratch0_array.data = AI_PTR(activations + 15552);
    conv2d_14_scratch0_array.data_start = AI_PTR(activations + 15552);
    conv2d_14_scratch1_array.data = AI_PTR(activations + 15840);
    conv2d_14_scratch1_array.data_start = AI_PTR(activations + 15840);
    conv2d_20_scratch0_array.data = AI_PTR(activations + 10368);
    conv2d_20_scratch0_array.data_start = AI_PTR(activations + 10368);
    conv2d_21_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_21_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_21_scratch1_array.data = AI_PTR(activations + 288);
    conv2d_21_scratch1_array.data_start = AI_PTR(activations + 288);
    conv2d_23_scratch0_array.data = AI_PTR(activations + 2880);
    conv2d_23_scratch0_array.data_start = AI_PTR(activations + 2880);
    conv2d_23_scratch1_array.data = AI_PTR(activations + 0);
    conv2d_23_scratch1_array.data_start = AI_PTR(activations + 0);
    conv2d_25_scratch0_array.data = AI_PTR(activations + 2880);
    conv2d_25_scratch0_array.data_start = AI_PTR(activations + 2880);
    conv2d_25_scratch1_array.data = AI_PTR(activations + 0);
    conv2d_25_scratch1_array.data_start = AI_PTR(activations + 0);
    conv2d_29_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_29_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_29_scratch1_array.data = AI_PTR(activations + 288);
    conv2d_29_scratch1_array.data_start = AI_PTR(activations + 288);
    conv2d_34_scratch0_array.data = AI_PTR(activations + 5472);
    conv2d_34_scratch0_array.data_start = AI_PTR(activations + 5472);
    conv2d_34_scratch1_array.data = AI_PTR(activations + 0);
    conv2d_34_scratch1_array.data_start = AI_PTR(activations + 0);
    conv2d_36_scratch0_array.data = AI_PTR(activations + 2592);
    conv2d_36_scratch0_array.data_start = AI_PTR(activations + 2592);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool yolobody_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_weights_array.data = AI_PTR(weights + 0);
    conv2d_1_weights_array.data_start = AI_PTR(weights + 0);
    conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_bias_array.data = AI_PTR(weights + 216);
    conv2d_1_bias_array.data_start = AI_PTR(weights + 216);
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(weights + 248);
    conv2d_4_weights_array.data_start = AI_PTR(weights + 248);
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(weights + 320);
    conv2d_4_bias_array.data_start = AI_PTR(weights + 320);
    conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_weights_array.data = AI_PTR(weights + 352);
    conv2d_5_weights_array.data_start = AI_PTR(weights + 352);
    conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_bias_array.data = AI_PTR(weights + 480);
    conv2d_5_bias_array.data_start = AI_PTR(weights + 480);
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(weights + 544);
    conv2d_7_weights_array.data_start = AI_PTR(weights + 544);
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(weights + 2848);
    conv2d_7_bias_array.data_start = AI_PTR(weights + 2848);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(weights + 2912);
    conv2d_9_weights_array.data_start = AI_PTR(weights + 2912);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(weights + 5216);
    conv2d_9_bias_array.data_start = AI_PTR(weights + 5216);
    conv2d_14_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_weights_array.data = AI_PTR(weights + 5280);
    conv2d_14_weights_array.data_start = AI_PTR(weights + 5280);
    conv2d_14_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_bias_array.data = AI_PTR(weights + 5792);
    conv2d_14_bias_array.data_start = AI_PTR(weights + 5792);
    conv2d_20_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_weights_array.data = AI_PTR(weights + 5856);
    conv2d_20_weights_array.data_start = AI_PTR(weights + 5856);
    conv2d_20_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_bias_array.data = AI_PTR(weights + 6144);
    conv2d_20_bias_array.data_start = AI_PTR(weights + 6144);
    conv2d_21_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_weights_array.data = AI_PTR(weights + 6272);
    conv2d_21_weights_array.data_start = AI_PTR(weights + 6272);
    conv2d_21_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_bias_array.data = AI_PTR(weights + 6784);
    conv2d_21_bias_array.data_start = AI_PTR(weights + 6784);
    conv2d_23_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_weights_array.data = AI_PTR(weights + 6848);
    conv2d_23_weights_array.data_start = AI_PTR(weights + 6848);
    conv2d_23_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_bias_array.data = AI_PTR(weights + 9152);
    conv2d_23_bias_array.data_start = AI_PTR(weights + 9152);
    conv2d_25_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_weights_array.data = AI_PTR(weights + 9216);
    conv2d_25_weights_array.data_start = AI_PTR(weights + 9216);
    conv2d_25_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_bias_array.data = AI_PTR(weights + 11520);
    conv2d_25_bias_array.data_start = AI_PTR(weights + 11520);
    conv2d_29_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_weights_array.data = AI_PTR(weights + 11584);
    conv2d_29_weights_array.data_start = AI_PTR(weights + 11584);
    conv2d_29_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_bias_array.data = AI_PTR(weights + 12096);
    conv2d_29_bias_array.data_start = AI_PTR(weights + 12096);
    conv2d_34_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_weights_array.data = AI_PTR(weights + 12160);
    conv2d_34_weights_array.data_start = AI_PTR(weights + 12160);
    conv2d_34_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_bias_array.data = AI_PTR(weights + 16768);
    conv2d_34_bias_array.data_start = AI_PTR(weights + 16768);
    conv2d_36_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_weights_array.data = AI_PTR(weights + 16832);
    conv2d_36_weights_array.data_start = AI_PTR(weights + 16832);
    conv2d_36_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_bias_array.data = AI_PTR(weights + 19856);
    conv2d_36_bias_array.data_start = AI_PTR(weights + 19856);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_yolobody_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_YOLOBODY_MODEL_NAME,
      .model_signature   = AI_YOLOBODY_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 3139125,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_yolobody_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_yolobody_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_yolobody_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_yolobody_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= yolobody_configure_weights(net_ctx, &params->params);
  ok &= yolobody_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_yolobody_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_yolobody_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_YOLOBODY_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

