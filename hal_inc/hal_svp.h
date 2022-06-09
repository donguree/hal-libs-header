/******************************************************************************
 *   TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2013-2022 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file    hal_svp.h
 *
 *  Hardware Abstration Layer for DRM
 *
 *  @author  cs.jung@lge.com
 *  @version 1.1
 *  @date    2013-2022
 */

/******************************************************************************
    Header File Guarder
******************************************************************************/
#ifndef	_HAL_SVP_H_
#define	_HAL_SVP_H_

/******************************************************************************
    Control Constants
******************************************************************************/

/******************************************************************************
    File Inclusions
******************************************************************************/
#include "hal_common.h"

/******************************************************************************
    Constant Definitions
******************************************************************************/

/******************************************************************************
    Macro Definitions
******************************************************************************/

/******************************************************************************
    Type Definitions
******************************************************************************/

/* Refer to <stdint.h> for primitive types */

typedef enum {
  HAL_SVP_SUCCESS = 0,                   /* Success */
  HAL_SVP_ERROR_GENERAL = 1,             /* Generic errors */
  HAL_SVP_ERROR_INVALID_PARAMS = 2,      /* Invalid parameter */
  HAL_SVP_ERROR_NOT_ENOUGH_RESOURCE = 3, /* Insufficient resources */
} HAL_SVP_RESULT_T;

typedef enum {
  HAL_SVP_ERROR = -1,
  HAL_SVP_OK = 0,
  HAL_SVP_NO_AU = 1,
  HAL_SVP_WAIT = 2
} SVP_STATUS_T;

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

/******************************************************************************
    Function Declaration
******************************************************************************/

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
 *   TBD
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
 *   TBD
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
 *   TBD
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
 *   TBD
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
 *   TBD
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
 *   TBD
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

/**
 * @brief Select content key for decryption of the encrypted video in TEE.
 *
 * @rst
 * Functional Requirements
 *   This function is used when video and audio are being fed in separate processes.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in SVP_STATUS_T.
 *
 * Performance Requirements
 *   TBD
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     session [in] an opaque handle that the crypto firmware uses session
 *     key_id [in] identify the key for contents
 *     key_id_length [in] key_id’s size
 *     cipherMode [in] crypto algorithm
 *
 * Return Value
 *   HAL_SVP_OK(0) if the function success, or returns proper value in SVP_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     SVP_STATUS_T retVal;
 *
 *     unsigned int oec_session;
 *     uint8_t* key_id;
 *     uint32_t key_id_length;
 *     int cipherMode; // kCenc or kCbcs
 *     retVal = HAL_SVP_WidevineSelectKey(oec_session, key_id, key_id_length, cipherMode);
 *     if(retVal == HAL_SVP_ERROR) {
 *       //error handling
 *     }
 *
 *     retVal = HAL_SVP_WidevineDecryptCENC(oec_session, data,
 *                                          data_length, true,
 *                                          iv, block_offset,
 *                                          (void*)buffer_descriptor,
 *                                          (void*)pattern, subsample_flags);
 *     if(retVal == HAL_SVP_ERROR) {
 *       //error handling
 *     }
 * @endrst
 */
SVP_STATUS_T HAL_SVP_WidevineSelectKey_OverV14(UINT32 session, const UINT8 *key_id, size_t key_id_length, SINT32 cipherMode);

/**
 * @brief Decrypt given encrypted data
 *
 * @rst
 * Functional Requirements
 *   Given data should be encrypted with Widevine Modular.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in SVP_STATUS_T.
 *
 * Performance Requirements
 *   TBD
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     session [in] Crypto session identifier. The crypto session in which decrypt is to be performed.
 *     samples [in] A caller-owned array of OEMCrypto_SampleDescription structures. Each entry in this array contains one sample of the content.
 *     samples_length [in] The length of the array pointed to by the samples parameter.
 *     pattern [in] A caller-owned structure indicating the encrypt/skip pattern as specified in the ISO-CENC standard.
 *     oec_return [out] return value of OEMCrypto_DecryptCENC
 *
 * Return Value
 *   HAL_SVP_OK(0) if the function success, or returns proper value in SVP_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     typedef struct BufferDescriptor {
 *       BufferTypes type;
 *       union {
 *          struct { // type == bufferTypeClear
 *           uint8_t* address;
 *           size_t max_length;
 *         } clear;
 *         struct { // type == bufferTypeSecure
 *           void* handle;
 *           size_t max_length;
 *           size_t offset;
 *         } secure;
 *         struct { // type == bufferTypeDirect
 *           bool is_video;
 *         } direct;
 *       } buffer;
 *     } DescryptorStruct;
 *
 *     typedef struct {
 *       const uint8_t* input_data;                        // source for encrypted data.
 *       size_t input_data_length;                           // length of encrypted data.
 *       DescryptorStruct output_descriptor;     // destination for clear data.
 *     } InputOutputPair;
 *
 *     typedef struct {
 *       size_t num_bytes_clear;
 *       size_t num_bytes_encrypted;
 *       uint8_t subsample_flags;         // is this the first/last subsample in a sample?
 *       size_t block_offset;                    // used for CTR "cenc" mode only.
 *     } SubSampleDescription;
 *
 *     typedef struct {
 *       InputOutputPair buffers;                                  // The source and destination buffers.
 *       uint8_t iv[16];                                                        // The IV for the initial subsample.
 *       const SubSampleDescription* subsamples; // subsamples array.
 *       size_t subsamples_length;                                 // the number of subsamples in the sample.
 *     } SampleDescription;
 *
 *     typedef struct {
 *       size_t encrypt;          // number of 16 byte blocks to decrypt.
 *       size_t skip;                 // number of 16 byte blocks to leave in clear.
 *     } CENCEncryptPatternDesc;
 *
 *     SampleDescription samples[sample_length];
 *     std::vector<SubSampleDescription> subsamples;
 *
 *     // setting subsamples to samples
 *     CdmCencPatternEncryptionDescriptor *pattern;
 *     retVal = HAL_SVP_WidevineSelectKey(oec_session,key_id,key_id_length);
 *     if(retVal == HAL_SVP_ERROR) {
 *       //error handling
 *     }
 *     if (0 != HAL_SVP_WidevineDecryptCENC_V16(oec_session_,  samples,
 *                                              sample_length, pattern,
 *                                              &oec_return)) {
 *
 *       if (39 == oec_return) {              //  OEMCrypto_ERROR_BUFFER_TOO_LARGE returned
 *         //  Try 1 sample decryption
 *         for (int i = 0; i < sample_length; i++) { 
 *           if (0 != HAL_SVP_WidevineDecryptCENC_V16(oec_session_, samples[i],
 *                                                    1, pattern,
 *                                                    &oec_return)) {
 *             //error handling
 *           }
 *         }
 *       } else {
 *         //error handling
 *       }
 *     }
 * @endrst
 */
SVP_STATUS_T HAL_SVP_WidevineDecryptCENC_V16(UINT32 session,
                                             void *samples,
                                             size_t samples_length,
                                             void *pattern,
                                             uint32_t *oec_return);

/* Folling legacy functions will be removed after new HAL functions are implemented */
SVP_STATUS_T HAL_SVP_OpenSecureCpb(UINT32 secCpbAddr, SINT32 secCpbSize);
SVP_STATUS_T HAL_SVP_CloseSecureCpb(void);
BOOLEAN HAL_SVP_IsSecureReformatterSupported(void);
SVP_STATUS_T HAL_SVP_SetSecureReformatter(SVP_REFORMATTER_T reformatterType);
SVP_STATUS_T HAL_SVP_GetSecureCpbInformation (ULONG vdecHandle,
        ULONG *pSecCpbAddr, SINT32 *pSecCpbSize, SINT32 *pReadOffset, SINT32 *pWriteOffset);
SVP_STATUS_T HAL_SVP_GetSecureDecryptBufferHandle(UINT32 *pSecDecBufHandle, UINT32 *pSecDecBufSize);
SVP_STATUS_T HAL_SVP_GetAuInformation(UINT32 *pAuWritePosition, SINT32 *pAuWriteLength,
        UINT32 *pWritePosition, UINT32 readPosition, UINT32 secDecBufHandle, UINT32 srcLength);
SVP_STATUS_T HAL_SVP_CheckAuTypeIsDolbyHdrMeta(UINT32 auWritePosition, SINT32 auWriteLength, BOOLEAN *pIsMetaType);
SVP_STATUS_T HAL_SVP_FlushSecureDecryptBuffer(void);

SVP_STATUS_T HAL_SVP_Widevine_DecryptVideo(UINT8 *pIv, UINT8 *pSrc, UINT32 srcLength,
        UINT32 secDecBufHandle, UINT32 secDecBufwriteOffset, UINT32 *pOutputLength);
SVP_STATUS_T HAL_SVP_Widevine_DecryptAudio(UINT8 *pIv, UINT8 *pSrc, UINT32 srcLength,
        UINT8 *pOutput, UINT32 *pOutputLength);

SVP_STATUS_T HAL_SVP_WidevineSelectKey(UINT32 session, const UINT8 *key_id, size_t key_id_length);
SVP_STATUS_T HAL_SVP_WidevineDecryptCTR(UINT32 session, const UINT8 *data_addr, size_t data_length, BOOLEAN is_encrypted,
        const UINT8 *iv, size_t block_offset, const void *out_buffer, UINT8 subsample_flags);

SVP_STATUS_T HAL_SVP_WidevineDecryptCENC(UINT32 session, const UINT8 *data_addr, size_t data_length, BOOLEAN is_encrypted,
        const UINT8 *iv, size_t block_offset, const void *out_buffer, const void *pattern, UINT8 subsample_flags);

SVP_STATUS_T HAL_SVP_CopyToSecureDecryptBuffer(UINT32 secDecBufHandle, UINT32 secDecBufwriteOffset,
        UINT8 *pSrc, SINT32 length);

SVP_STATUS_T HAL_SVP_CopyFromSecureBuffer(UINT32 srcHandle, UINT8 *pOutput, SINT32 length);
/* end of legacy functions */

#endif /* _HAL_SVP_H_ */

