/**
  ******************************************************************************
  * @file    chatbot.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Jan  5 11:17:07 2022
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "chatbot.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"

#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 5
#define AI_TOOLS_VERSION_MINOR 1
#define AI_TOOLS_VERSION_MICRO 0


#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 3
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_chatbot
 
#undef AI_CHATBOT_MODEL_SIGNATURE
#define AI_CHATBOT_MODEL_SIGNATURE     "e4fff005384b7a49f46ea08b45822007"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.1.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Jan  5 11:17:07 2022"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_CHATBOT_N_BATCHES
#define AI_CHATBOT_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array dense_2_bias_array;   /* Array #0 */
AI_STATIC ai_array dense_2_weights_array;   /* Array #1 */
AI_STATIC ai_array dense_1_bias_array;   /* Array #2 */
AI_STATIC ai_array dense_1_weights_array;   /* Array #3 */
AI_STATIC ai_array dense_bias_array;   /* Array #4 */
AI_STATIC ai_array dense_weights_array;   /* Array #5 */
AI_STATIC ai_array input_0_output_array;   /* Array #6 */
AI_STATIC ai_array dense_output_array;   /* Array #7 */
AI_STATIC ai_array dense_nl_output_array;   /* Array #8 */
AI_STATIC ai_array dense_1_output_array;   /* Array #9 */
AI_STATIC ai_array dense_1_nl_output_array;   /* Array #10 */
AI_STATIC ai_array dense_2_output_array;   /* Array #11 */
AI_STATIC ai_array dense_2_nl_output_array;   /* Array #12 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor dense_2_bias;   /* Tensor #0 */
AI_STATIC ai_tensor dense_2_weights;   /* Tensor #1 */
AI_STATIC ai_tensor dense_1_bias;   /* Tensor #2 */
AI_STATIC ai_tensor dense_1_weights;   /* Tensor #3 */
AI_STATIC ai_tensor dense_bias;   /* Tensor #4 */
AI_STATIC ai_tensor dense_weights;   /* Tensor #5 */
AI_STATIC ai_tensor input_0_output;   /* Tensor #6 */
AI_STATIC ai_tensor dense_output;   /* Tensor #7 */
AI_STATIC ai_tensor dense_nl_output;   /* Tensor #8 */
AI_STATIC ai_tensor dense_1_output;   /* Tensor #9 */
AI_STATIC ai_tensor dense_1_nl_output;   /* Tensor #10 */
AI_STATIC ai_tensor dense_2_output;   /* Tensor #11 */
AI_STATIC ai_tensor dense_2_nl_output;   /* Tensor #12 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain dense_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain dense_nl_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain dense_1_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain dense_1_nl_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain dense_2_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain dense_2_nl_chain;   /* Chain #5 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_dense dense_layer; /* Layer #0 */
AI_STATIC ai_layer_nl dense_nl_layer; /* Layer #1 */
AI_STATIC ai_layer_dense dense_1_layer; /* Layer #2 */
AI_STATIC ai_layer_nl dense_1_nl_layer; /* Layer #3 */
AI_STATIC ai_layer_dense dense_2_layer; /* Layer #4 */
AI_STATIC ai_layer_nl dense_2_nl_layer; /* Layer #5 */


/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  dense_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  dense_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  dense_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  dense_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6528, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  input_0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 51, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  dense_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  dense_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  dense_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  dense_2_nl_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 6, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  dense_2_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 6, 1, 1), AI_STRIDE_INIT(4, 4, 4, 24, 24),
  1, &dense_2_bias_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  dense_2_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 6, 1, 1), AI_STRIDE_INIT(4, 4, 256, 1536, 1536),
  1, &dense_2_weights_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  dense_1_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &dense_1_bias_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  dense_1_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 64, 1, 1), AI_STRIDE_INIT(4, 4, 512, 32768, 32768),
  1, &dense_1_weights_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  dense_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_bias_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  dense_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 51, 128, 1, 1), AI_STRIDE_INIT(4, 4, 204, 26112, 26112),
  1, &dense_weights_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  input_0_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 51, 1, 1), AI_STRIDE_INIT(4, 4, 4, 204, 204),
  1, &input_0_output_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  dense_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_output_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  dense_nl_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_nl_output_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  dense_1_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &dense_1_output_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  dense_1_nl_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &dense_1_nl_output_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  dense_2_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 6, 1, 1), AI_STRIDE_INIT(4, 4, 4, 24, 24),
  1, &dense_2_output_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  dense_2_nl_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 6, 1, 1), AI_STRIDE_INIT(4, 4, 4, 24, 24),
  1, &dense_2_nl_output_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_weights, &dense_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_layer, 0,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &dense_nl_layer, AI_STATIC,
  .tensors = &dense_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_nl_layer, 0,
  NL_TYPE,
  nl, forward_relu,
  &AI_NET_OBJ_INSTANCE, &dense_1_layer, AI_STATIC,
  .tensors = &dense_nl_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_1_weights, &dense_1_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_1_layer, 1,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &dense_1_nl_layer, AI_STATIC,
  .tensors = &dense_1_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_1_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_1_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_1_nl_layer, 1,
  NL_TYPE,
  nl, forward_relu,
  &AI_NET_OBJ_INSTANCE, &dense_2_layer, AI_STATIC,
  .tensors = &dense_1_nl_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_1_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_2_weights, &dense_2_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_2_layer, 2,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &dense_2_nl_layer, AI_STATIC,
  .tensors = &dense_2_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_2_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_2_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_2_nl_layer, 2,
  NL_TYPE,
  nl, forward_sm,
  &AI_NET_OBJ_INSTANCE, &dense_2_nl_layer, AI_STATIC,
  .tensors = &dense_2_nl_chain, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 61208, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 768, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_CHATBOT_IN_NUM, &input_0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_CHATBOT_OUT_NUM, &dense_2_nl_output),
  &dense_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool chatbot_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, 4));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    input_0_output_array.data = AI_PTR(NULL);
    input_0_output_array.data_start = AI_PTR(NULL);
    dense_output_array.data = AI_PTR(activations + 0);
    dense_output_array.data_start = AI_PTR(activations + 0);
    dense_nl_output_array.data = AI_PTR(activations + 0);
    dense_nl_output_array.data_start = AI_PTR(activations + 0);
    dense_1_output_array.data = AI_PTR(activations + 512);
    dense_1_output_array.data_start = AI_PTR(activations + 512);
    dense_1_nl_output_array.data = AI_PTR(activations + 0);
    dense_1_nl_output_array.data_start = AI_PTR(activations + 0);
    dense_2_output_array.data = AI_PTR(activations + 256);
    dense_2_output_array.data_start = AI_PTR(activations + 256);
    dense_2_nl_output_array.data = AI_PTR(NULL);
    dense_2_nl_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool chatbot_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    dense_2_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_2_bias_array.data = AI_PTR(weights + 61184);
    dense_2_bias_array.data_start = AI_PTR(weights + 61184);
    dense_2_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_2_weights_array.data = AI_PTR(weights + 59648);
    dense_2_weights_array.data_start = AI_PTR(weights + 59648);
    dense_1_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_1_bias_array.data = AI_PTR(weights + 59392);
    dense_1_bias_array.data_start = AI_PTR(weights + 59392);
    dense_1_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_1_weights_array.data = AI_PTR(weights + 26624);
    dense_1_weights_array.data_start = AI_PTR(weights + 26624);
    dense_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_bias_array.data = AI_PTR(weights + 26112);
    dense_bias_array.data_start = AI_PTR(weights + 26112);
    dense_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_weights_array.data = AI_PTR(weights + 0);
    dense_weights_array.data_start = AI_PTR(weights + 0);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_chatbot_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_CHATBOT_MODEL_NAME,
      .model_signature   = AI_CHATBOT_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = {AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR,
                            AI_TOOLS_API_VERSION_MICRO, 0x0},

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 15386,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if ( !ai_platform_api_get_network_report(network, &r) ) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_chatbot_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_chatbot_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_chatbot_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_chatbot_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= chatbot_configure_weights(net_ctx, &params->params);
  ok &= chatbot_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_chatbot_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_chatbot_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}


#undef AI_CHATBOT_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

