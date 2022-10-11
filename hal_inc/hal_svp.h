/*
 * Copyright (c) 2013-2022 LG Electronics Inc.
 *
 * This program or software including the accompanying associated documentation
 * ("Software") is the proprietary software of LG Electronics Inc. and or its
 * licensors, and may only be used, duplicated, modified or distributed pursuant
 * to the terms and conditions of a separate written license agreement between
 * you and LG Electronics Inc. ("Authorized License").
 * Except as set forth in an Authorized License, LG Electronics Inc. grants no
 * license (express or implied), rights to use, or waiver of any kind with
 * respect to the Software, and LG Electronics Inc. expressly reserves all
 * rights in and to the Software and all intellectual property therein. If you
 * have no Authorized License, then you have no rights to use the Software in
 * any ways, and should immediately notify LG Electronics Inc. and discontinue
 * all use of the Software.
*/

#ifndef _HAL_SVP_H_
#define _HAL_SVP_H_

#include <stdint.h>

#include "hal_svp_legacy.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  HAL_SVP_SUCCESS = 0,                   /* Success */
  HAL_SVP_ERROR_GENERAL = 1,             /* Generic errors */
  HAL_SVP_ERROR_INVALID_PARAMS = 2,      /* Invalid parameter */
  HAL_SVP_ERROR_NOT_ENOUGH_RESOURCE = 3, /* Insufficient resources */
} HAL_SVP_RESULT_T;

typedef struct {
  uint64_t vdec_handle; /* [IN] handler from VDEC. If '__UINT64_MAX__', SEBUF is not required,
                                but if '0', invalid handle */
  uint32_t drm_type;    /* [IN] drm-type fourcc */
  uint64_t session_id;  /* [OUT] session identifier related with a session created by SoC vender */
} HAL_SVP_OPEN_PARAM_T;

typedef struct {
  uint64_t session_id; /* [IN] ID from HAL_SVP_Open() for the session to be closed */
} HAL_SVP_CLOSE_PARAM_T;

typedef struct {
  uint64_t session_id; /* [IN] ID from HAL_SVP_Open() for the session to be used */
  struct {
    uint32_t semem;    /* [OUT] current capacity(bytes) of SEMEM,
                                it will be static since initial state in general */
    uint32_t sebuf;    /* [OUT] current capacity(bytes) of SEBUF,
                                it will be dynamic in playing state */
  } capacity;
} HAL_SVP_STAT_PARAM_T;

typedef struct {
  uint64_t session_id; /* [IN] ID from HAL_SVP_Open() for the session to be used */
  uint32_t offset;     /* [IN] SEMEM offset where data will be copied */
  uint32_t length;     /* [IN] length of input data to be copied */
  uint8_t* source;     /* [IN] source pointer of input data to be copied */
} HAL_SVP_SEMEM_PARAM_T;

typedef struct {
  uint64_t session_id; /* [IN] ID from HAL_SVP_Open() for the session to be used */
  struct {
    uint32_t offset;   /* [IN/OUT] SEBUF offset where data to be written. When write operation is done,
                                   it must be adjusted to the next write offset by the function. */
    uint32_t length;   /* [IN] input length to be written */
  } writing;
  struct {
    uint32_t offset;   /* [OUT] output offset where video data is written */
    uint32_t length;   /* [OUT] output length where video data is written */
  } written;
} HAL_SVP_SEBUF_PARAM_T;

typedef struct {
  uint64_t session_id; /* [IN] ID from HAL_SVP_Open() for the session to be used */
} HAL_SVP_FLUSH_PARAM_T;

/**
 * @brief Creates SVP session, allocates SVP resources and initializes global variables with given information.
 *
 * @rst
 * Functional Requirements
 *   Creates SVP session, allocates SVP resources and initializes global variables with given information.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in HAL_SVP_RESULT_T.
 *
 * Performance Requirements
 *   The minimum requirement is that 1 loop of decryption(or copy), stat, and write of 1 sample (1 Au) be performed within 16ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     open_param [in/out] open_param is described in type HAL_SVP_OPEN_PARAM_T
 *
 * Return Value
 *   HAL_SVP_SUCCESS(0) if the function success, or returns proper value in HAL_SVP_RESULT_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     HAL_SVP_OPEN_PARAM_T open_param;
 *     open_param.vdec_handle = vdec_handle;
 *     open_param.drm_type = SVP_DRM_FOURCC_prdy;
 *     open_param.session_id = 0;
 *
 *     if (HAL_SVP_SUCCESS != HAL_SVP_Open(&open_param) || open_param.session_id == 0)
 *       // Error handling
 * @endrst
 */
HAL_SVP_RESULT_T HAL_SVP_Open(HAL_SVP_OPEN_PARAM_T* open_param);

/**
 * @brief Release SVP resources to system, initializes global variables and closes SVP session with given information.
 *
 * @rst
 * Functional Requirements
 *   Returns SVP resources to system, initializes global variables and closes SVP session with given information.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in HAL_SVP_RESULT_T.
 *
 * Performance Requirements
 *   The minimum requirement is that 1 loop of decryption(or copy), stat, and write of 1 sample (1 Au) be performed within 16ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     close_param [in] close_param is described in type HAL_SVP_CLOSE_PARAM_T
 *
 * Return Value
 *   HAL_SVP_SUCCESS(0) if the function success, or returns proper value in HAL_SVP_RESULT_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     HAL_SVP_Open(&open_param);
 *
 *     HAL_SVP_CLOSE_PARAM_T close_param;
 *     close_param.session_id = open_param.session_id;
 *
 *     if (HAL_SVP_SUCCESS != HAL_SVP_Close(&close_param))
 *        // Error handling
 * @endrst
 */
HAL_SVP_RESULT_T HAL_SVP_Close(HAL_SVP_CLOSE_PARAM_T* close_param);

/**
 * @brief Get current capacities of SVP resources(aka. 'SEMEM' and 'SEBUF').
 *
 * @rst
 * Functional Requirements
 *   Get current capacities of SVP resources(aka. 'SEMEM' and 'SEBUF').
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in HAL_SVP_RESULT_T.
 *
 * Performance Requirements
 *   The minimum requirement is that 1 loop of decryption(or copy), stat, and write of 1 sample (1 Au) be performed within 16ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     stat_param [in/out] stat_param is described in type HAL_SVP_STAT_PARAM_T
 *
 * Return Value
 *   HAL_SVP_SUCCESS(0) if the function success, or returns proper value in HAL_SVP_RESULT_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     HAL_SVP_Open(&open_param);
 *
 *     HAL_SVP_STAT_PARAM_T stat_param;
 *     stat_param.session_id = open_param.session_id;
 *
 *     if (HAL_SVP_SUCCESS != HAL_SVP_Stat(&stat_param))
 *       // Error handling
 * @endrst
 */
HAL_SVP_RESULT_T HAL_SVP_Stat(HAL_SVP_STAT_PARAM_T* stat_param);

/**
 * @brief Copy data to 'SEMEM' with given information.
 *
 * @rst
 * Functional Requirements
 *   Copy data to 'SEMEM' with given information.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in HAL_SVP_RESULT_T.
 *
 * Performance Requirements
 *   The minimum requirement is that 1 loop of decryption(or copy), stat, and write of 1 sample (1 Au) be performed within 16ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     semem_param [in] semem_param is described in type HAL_SVP_SEMEM_PARAM_T
 *
 * Return Value
 *   HAL_SVP_SUCCESS(0) if the function success, or returns proper value in HAL_SVP_RESULT_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     HAL_SVP_Open(&open_param);
 *
 *     HAL_SVP_SEMEM_PARAM_T semem_param;
 *     semem_param.session_id = open_param.session_id;
 *     semem_param.offset = 0;
 *     semem_param.length = data_size;
 *     semem_param.source = data;
 *
 *     if (HAL_SVP_SUCCESS != HAL_SVP_Copy(&semem_param))
 *       // Error handling
 * @endrst
 */
HAL_SVP_RESULT_T HAL_SVP_Copy(HAL_SVP_SEMEM_PARAM_T* semem_param);

/**
 * @brief Write data from 'SEMEM' to 'SEBUF' with given information.
 *
 * @rst
 * Functional Requirements
 *   Writes data from 'SEMEM' to 'SEBUF' with given information.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in HAL_SVP_RESULT_T.
 *
 * Performance Requirements
 *   The minimum requirement is that 1 loop of decryption(or copy), stat, and write of 1 sample (1 Au) be performed within 16ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     sebuf_param [in/out] sebuf_param is described in type HAL_SVP_SEBUF_PARAM_T
 *
 * Return Value
 *   HAL_SVP_SUCCESS(0) if the function success, or returns proper value in HAL_SVP_RESULT_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     HAL_SVP_Open(&open_param);
 *
 *     HAL_SVP_STAT_PARAM_T stat_param;
 *     stat_param.session_id = open_param.session_id;
 *
 *     HAL_SVP_SEBUF_PARAM_T sebuf_param;
 *     sebuf_param.session_id = open_param.session_id;
 *     sebuf_param.writting.offset = 0;
 *
 *     while (PLAYING) {
 *       HAL_SVP_Stat(&stat_param);
 *       if (stat_param.capacity.sebuf < total_data_length) {
 *         sleep(); //<-- give a chance for 'SEBUF' to be consumed
 *         continue;
 *       }
 *
 *       sem_wait(); //<-- lock semaphore to guarantee synchronous data flow from 'SEMEM' to 'SEBUF'
 *
 *       while (i == NUMBER_OF_DATA) {
 *         HAL_SVP_Copy(&semem_param); //<-- This can be replaced to DRM decrypt operation
 *         semem_param.offset += data_length[i];
 *         i++;
 *       }
 *
 *       sebuf_param.writting.length = semem_param.offset;
 *       semem_param.offset = 0;
 *
 *       HAL_SVP_RESULT_T ret = HAL_SVP_SUCCESS;
 *       ret = HAL_SVP_Write(&sebuf_param);
 *
 *       sem_post(); //<-- unlock semaphore regardless of return value
 *                   //    to give a chance for copy or decrypt operation of different process
 *
 *       if (ret == HAL_SVP_ERROR_NOT_ENOUGH_RESOURCE) {
 *         sleep(); //<-- give a chance for 'SEBUF' to be consumed
 *         continue; //<-- data processing will be retried from copy or decrypt operation
 *       } else if (ret != HAL_SVP_SUCCESS) {
 *         // Error handling
 *       }
 *     }
 * @endrst
 */
HAL_SVP_RESULT_T HAL_SVP_Write(HAL_SVP_SEBUF_PARAM_T* sebuf_param);

/**
 * @brief Flush SVP resources. This function can be called when SEEK operation of Media player.
 *
 * @rst
 * Functional Requirements
 *   Flush SVP resources. This function can be called when SEEK operation of Media player.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in HAL_SVP_RESULT_T.
 *
 * Performance Requirements
 *   The minimum requirement is that 1 loop of decryption(or copy), stat, and write of 1 sample (1 Au) be performed within 16ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     flush_param [in] flush_param is described in type HAL_SVP_FLUSH_PARAM_T
 *
 * Return Value
 *   HAL_SVP_SUCCESS(0) if the function success, or returns proper value in HAL_SVP_RESULT_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     HAL_SVP_Open(&open_param);
 *
 *     HAL_SVP_FLUSH_PARAM_T flush_param;
 *     flush_param.session_id = open_param.session_id;
 *
 *     if (HAL_SVP_SUCCESS != HAL_SVP_Flush(&flush_param))
 *       // Error handling
 * @endrst
 */
HAL_SVP_RESULT_T HAL_SVP_Flush(HAL_SVP_FLUSH_PARAM_T* flush_param);

#ifdef __cplusplus
}
#endif

#endif /* _HAL_SVP_H_ */
