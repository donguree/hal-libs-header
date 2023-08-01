/*
 * Copyright (c) 2013-2023 LG Electronics Inc.
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
 *     typedef struct {
 *       uint64_t vdec_handle; // [IN] handler from VDEC. If '__UINT64_MAX__', SEBUF is not required,
 *                             //      but if '0', invalid handle
 *       uint32_t drm_type;    // [IN] drm-type fourcc
 *       uint64_t session_id;  // [OUT] session identifier related with a session created by SoC vender
 *     } HAL_SVP_OPEN_PARAM_T;
 *
 * Return Value
 *   HAL_SVP_SUCCESS(0) if the function success, or returns proper value in HAL_SVP_RESULT_T
 *
 * Remarks
 *   If SVP will be performed without VDEC in current SoC(ex. external VDEC supported by other SoC is used), vdec_handle can be passed as '__UINT64_MAX__'.
 *   In other words, HAL SVP supports only 'SEMEM' for Copy or Decrypt operation. And data in 'SEMEM' will be processed by other content protection system such as DTCP2USB and will be passed to external VDEC.
 *   In this case, 'Acquire vdec-handle' and 'HAL_SVP_Write()' step on above sequence diagram will be omitted.
 *   This is a requirement for specific SoC which supports special feature. If your SoC doesn't required this requirement, please ignore this remark and just assume that '__UINT64_MAX__' is reserved for special feature.
 *
 *   When DSC feature is performed starting with non-DRM contents such as advertisement by player, drm_type can be passed as SVP_DRM_FOURCC_none(0x0) for first call of HAL_SVP_Open() function.
 *   And then HAL_SVP_Open() can be called once again with different drm_type when Media Pipeline gets GST_EVENT_STREAM_START event and stream-id has been changed actually.
 *
 * Pseudo Code
 *   .. code-block:: cpp
 *
 *     // SVP_MAKE_FOURCC:
 *     // @a: the first character
 *     // @b: the second character
 *     // @c: the third character
 *     // @d: the fourth character
 *     //
 *     // Transform four characters into a #uint32_t fourcc value with host
 *     // endianness.
 *     //
 *     // |[
 *     // uint32_t fourcc = SVP_MAKE_FOURCC ('M', 'J', 'P', 'G');
 *     // ]|
 *     #define SVP_MAKE_FOURCC(a,b,c,d) \
 *     ((uint32_t)(a)        | ((uint32_t) (b)) << 8  | \
 *     ((uint32_t)(c)) << 16 | ((uint32_t) (d)) << 24 )
 *
 *     // SVP_STR_FOURCC:
 *     // @f: a string with at least four characters
 *     //
 *     // Transform an input string into a #uint32_t fourcc value with host
 *     // endianness.
 *     // Caller is responsible for ensuring the input string consists of at least
 *     // four characters.
 *     //
 *     // |[
 *     // uint32_t fourcc = SVP_STR_FOURCC ("MJPG");
 *     // ]|
 *     #define SVP_STR_FOURCC(f) \
 *       ((uint32_t)(((f)[0])|((f)[1]<<8)|((f)[2]<<16)|((f)[3]<<24)))
 *
 *     #define SVP_FOURCC_null  0x0
 *
 *     #define SVP_DRM_FOURCC_none  SVP_FOURCC_null        // Unknown DRM
 *     #define SVP_DRM_FOURCC_prdy  SVP_STR_FOURCC("prdy") // Microsoft PlayReady
 *     #define SVP_DRM_FOURCC_wvmd  SVP_STR_FOURCC("wvmd") // Google Widevine Modular
 *     #define SVP_DRM_FOURCC_fpsc  SVP_STR_FOURCC("fpsc") // Apple FairPlay Streaming CDM
 *
 *     HAL_SVP_RESULT_T HAL_SVP_Open(HAL_SVP_OPEN_PARAM_T* open_param)
 *     {
 *       IF open_param == NULL THEN
 *         RETURN HAL_SVP_ERROR_INVALID_PARAMS
 *       ENDIF
 *
 *       CASE open_param->drm_type OF
 *         SVP_DRM_FOURCC_none: // We don't know what DRM will use SVP now.
 *                              // It may be full clear stream such as advertisement.
 *         SVP_DRM_FOURCC_prdy: // Microsoft PlayReady will use SVP
 *         SVP_DRM_FOURCC_wvmd: // Google Widevine Modular will use SVP
 *         SVP_DRM_FOURCC_fpsc: // Apple FairPlay Streaming CDM will use SVP
 *       ENDCASE
 *
 *       IF open_param->vdec_handle == 0 THEN
 *         RETURN HAL_SVP_ERROR_INVALID_PARAMS
 *       ELSE IF session has been already created THEN
 *         RETURN HAL_SVP_SUCCESS
 *       ELSE IF open_param->vdec_handle == __UINT_MAX__ THEN
 *         PREPARE 'SEMEM' resources
 *       ELSE
 *         PREPARE 'SEMEM' and 'SEBUF' resources refer to open_param->vdec_handle
 *       ENDIF
 *
 *       CREATE session
 *
 *       SET open_param->session_id which identifies a created session
 *
 *       RETURN HAL_SVP_SUCCESS
 *     }
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
 *     typedef struct {
 *       uint64_t session_id; // [IN] ID from HAL_SVP_Open() for the session to be closed
 *     } HAL_SVP_CLOSE_PARAM_T;
 *
 * Return Value
 *   HAL_SVP_SUCCESS(0) if the function success, or returns proper value in HAL_SVP_RESULT_T
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block:: cpp
 *
 *     HAL_SVP_RESULT_T HAL_SVP_Close(HAL_SVP_CLOSE_PARAM_T* close_param)
 *     {
 *       IF close_param == NULL OR close_param->session_id == 0 THEN
 *         RETURN HAL_SVP_ERROR_INVALID_PARAMS
 *       ENDIF
 *
 *       CLOSE session refer to close_param->session_id
 *
 *       RETURN HAL_SVP_SUCCESS
 *     }
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
 *     typedef struct {
 *       uint64_t session_id; // [IN] ID from HAL_SVP_Open() for the session to be used
 *       struct {
 *         uint32_t semem;    // [OUT] current capacity(bytes) of SEMEM,
 *                            //       it will be static since initial state in general
 *         uint32_t sebuf;    // [OUT] current capacity(bytes) of SEBUF,
 *                            //       it will be dynamic in playing state
 *       } capacity;
 *     } HAL_SVP_STAT_PARAM_T;
 *
 * Return Value
 *   HAL_SVP_SUCCESS(0) if the function success, or returns proper value in HAL_SVP_RESULT_T
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block:: cpp
 *
 *     HAL_SVP_RESULT_T HAL_SVP_Stat(HAL_SVP_STAT_PARAM_T* stat_param)
 *     {
 *       IF stat_param == NULL OR stat_param->session_id == 0 THEN
 *         RETURN HAL_SVP_ERROR_INVALID_PARAMS
 *       ENDIF
 *
 *       SET stat_param->capacity.semem with current 'SEMEM' capacity(bytes)
 *
 *       SET stat_param->capacity.sebuf with current 'SEBUF' capacity(bytes)
 *
 *       RETURN HAL_SVP_SUCCESS
 *     }
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
 *     typedef struct {
 *       uint64_t session_id; // [IN] ID from HAL_SVP_Open() for the session to be used
 *       uint32_t offset;     // [IN] SEMEM offset where data will be copied
 *       uint32_t length;     // [IN] length of input data to be copied
 *       uint8_t* source;     // [IN] source pointer of input data to be copied
 *     } HAL_SVP_SEMEM_PARAM_T;
 *
 * Return Value
 *   HAL_SVP_SUCCESS(0) if the function success, or returns proper value in HAL_SVP_RESULT_T
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block:: cpp
 *
 *     HAL_SVP_RESULT_T HAL_SVP_Copy(HAL_SVP_SEMEM_PARAM_T* semem_param)
 *     {
 *       IF semem_param == NULL OR semem_param->session_id == 0 THEN
 *         RETURN HAL_SVP_ERROR_INVALID_PARAMS
 *       ENDIF
 *
 *       COPY data to 'SEMEM' refer to semem_param->offset, semem_param->length and semem_param->source
 *
 *       RETURN HAL_SVP_SUCCESS
 *     }
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
 *     typedef struct {
 *       uint64_t session_id; // [IN] ID from HAL_SVP_Open() for the session to be used
 *       struct {
 *         uint32_t offset;   // [IN/OUT] SEBUF offset where data to be written. When write operation is done,
 *                            //          it must be adjusted to the next write offset by the function.
 *         uint32_t length;   // [IN] input length to be written
 *       } writing;
 *       struct {
 *         uint32_t offset;   // [OUT] output offset where video data is written
 *         uint32_t length;   // [OUT] output length where video data is written
 *       } written;
 *     } HAL_SVP_SEBUF_PARAM_T;
 *
 * Return Value
 *   HAL_SVP_SUCCESS(0) if the function success, or returns proper value in HAL_SVP_RESULT_T
 *
 * Remarks
 *   If HAL_SVP_Write function returns HAL_SVP_ERROR_NOT_ENOUGH_RESOURCE(3), caller will retry data flow loop again refer to capacity of SEBUF from HAL_SVP_Stat function with delay.
 *
 *   If vdec_handle was passed as '__UINT64_MAX__' via HAL_SVP_Open function, HAL_SVP_Write function will never be called during a SVP session lifecycle.
 *
 * Pseudo Code
 *   .. code-block:: cpp
 *
 *     HAL_SVP_RESULT_T HAL_SVP_Write(HAL_SVP_SEBUF_PARAM_T* sebuf_param)
 *     {
 *       IF sebuf_param == NULL OR sebuf_param->session_id == 0 THEN
 *         RETURN HAL_SVP_ERROR_INVALID_PARAMS
 *       ENDIF
 *
 *       IF 'SEBUF' is full OR space of 'SEBUF' < sebuf_param->writting.length THEN
 *         RETURN HAL_SVP_ERROR_NOT_ENOUGH_RESOURCE
 *       ENDIF
 *
 *       WRITE data from 'SEMEM' to 'SEBUF' refer to sebuf_param->writting.offset and sebuf_param->writting.length
 *
 *       ADJUST sebuf_param->writting.offset to the next write offset
 *
 *       SET sebuf_param->written.offset where data is written
 *
 *       SET sebuf_param->written.length with data length which is written
 *
 *       RETURN HAL_SVP_SUCCESS
 *     }
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
 *     typedef struct {
 *       uint64_t session_id; // [IN] ID from HAL_SVP_Open() for the session to be used
 *     } HAL_SVP_FLUSH_PARAM_T;
 *
 * Return Value
 *   HAL_SVP_SUCCESS(0) if the function success, or returns proper value in HAL_SVP_RESULT_T
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block:: cpp
 *
 *     HAL_SVP_RESULT_T HAL_SVP_Flush(HAL_SVP_FLUSH_PARAM_T* flush_param)
 *     {
 *       IF flush_param == NULL OR flush_param->session_id == 0 THEN
 *         RETURN HAL_SVP_ERROR_INVALID_PARAMS
 *       ENDIF
 *
 *       FLUSH SVP resources
 *
 *       RETURN HAL_SVP_SUCCESS
 *     }
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
