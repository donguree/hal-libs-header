/******************************************************************************
 *   TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2013-2023 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file		hal_svp_legacy.h
 *
 *  Hardware Abstration Layer for DRM
 *
 *  @author
 *  @version	1.0
 *  @date		2014.07.
 *  @note
 *  @see
 */

/******************************************************************************
    Header File Guarder
******************************************************************************/
#ifndef	_HAL_SVP_LEGACY_H_
#define	_HAL_SVP_LEGACY_H_

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

typedef enum {
  HAL_SVP_ERROR	= -1,
  HAL_SVP_OK    = 0,
  HAL_SVP_NO_AU	= 1,
  HAL_SVP_WAIT	= 2
} SVP_STATUS_T;

/******************************************************************************
    Function Declaration
******************************************************************************/

/**
 * @brief Selects content key for decryption of the encrypted video in TEE.
 *
 * @rst
 * Functional Requirements
 *   Selects content key for decryption of the encrypted video in TEE.
 *   This function needs to be implemented at the specific status like case of using for decryption of video and audio at the each separate process to synchronize.
 *   But this API will support for over OEMCrypto v14.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in SVP_STATUS_T.
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
 *     [IN] session: an opaque handle that the crypto firmware uses session
 *     [IN] key_id: identify the key for contents
 *     [IN] key_id_length: key_id’s size
 *     [IN] cipherMode: crypto algorithm
 *
 * Return Value
 *   HAL_SVP_OK(0) if the function success, or returns proper value in SVP_STATUS_T
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block:: cpp
 *
 *     SVP_STATUS_T HAL_SVP_WidevineSelectKey_OverV14(UINT32 session,
 *                                                    const UINT8 *key_id,
 *                                                    size_t key_id_length,
 *                                                    SINT32 cipherMode)
 *     {
 *         SET key for decryption
 *
 *         IF all succeeded THEN
 *             RETURN HAL_SVP_OK
 *         ELSE
 *             RETURN HAL_SVP_ERROR
 *         ENDIF
 *     }
 *
 * Example
 *   .. code-block:: cpp
 *
 *     SVP_STATUS_T retVal;
 *     unsigned int oec_session;
 *     uint8_t* key_id;
 *     uint32_t key_id_length;
 *     int cipherMode; // kCenc or kCbcs
 *
 *     retVal = HAL_SVP_WidevineSelectKey_OverV14(oec_session, key_id, key_id_length, cipherMode);
 *     if (retVal == HAL_SVP_ERROR)
 *     {
 *         // error handling
 *     }
 * @endrst
 */
SVP_STATUS_T HAL_SVP_WidevineSelectKey_OverV14(UINT32 session, const UINT8 *key_id, size_t key_id_length, SINT32 cipherMode);

/**
 * @brief Decrypts content encrypted by Widevine Modular with contents key received from license server.
 *
 * @rst
 * Functional Requirements
 *   Decrypts content encrypted by Widevine Modular with contents key received from license server.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in SVP_STATUS_T.
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
 *     [IN] session: Crypto session identifier. The crypto session in which decrypt is to be performed.
 *     [IN] samples: A caller-owned array of OEMCrypto_SampleDescription structures. Each entry in this array contains one sample of the content.
 *     [IN] samples_length: The length of the array pointed to by the samples parameter.
 *     [IN] pattern: A caller-owned structure indicating the encrypt/skip pattern as specified in the ISO-CENC standard.
 *     [OUT] oec_return: return value of OEMCrypto_DecryptCENC
 *
 * Return Value
 *   HAL_SVP_OK(0) if the function success, or returns proper value in SVP_STATUS_T
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block:: cpp
 *
 *     SVP_STATUS_T HAL_SVP_WidevineDecryptCENC_V16(UINT32 session,
 *                                                  void *samples,
 *                                                  size_t samples_length,
 *                                                  void *pattern,
 *                                                  UINT32 *oec_return)
 *     {
 *         DO decrypt and process decrypted video data in TEE
 *
 *         UPDATE oec_return
 *
 *         IF all succeeded THEN
 *             RETURN HAL_SVP_OK
 *         ELSE
 *             RETURN HAL_SVP_ERROR
 *         ENDIF
 *     }
 *
 * Example
 *   .. code-block:: cpp
 *
 *     typedef struct BufferDescriptor {
 *       BufferTypes type;
 *       union {
 *         struct { // type == bufferTypeClear
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
 *       const uint8_t* input_data;  // source for encrypted data.
 *       size_t input_data_length;  // length of encrypted data.
 *       DescryptorStruct output_descriptor;  // destination for clear data.
 *     } InputOutputPair;
 *
 *     typedef struct {
 *       size_t num_bytes_clear;
 *       size_t num_bytes_encrypted;
 *       uint8_t subsample_flags;  // is this the first/last subsample in a sample?
 *       size_t block_offset;  // used for CTR "cenc" mode only.
 *     } SubSampleDescription;
 *
 *     typedef struct {
 *       InputOutputPair buffers;  // The source and destination buffers.
 *       uint8_t iv[16];  // The IV for the initial subsample.
 *       const SubSampleDescription* subsamples;  // subsamples array.
 *       size_t subsamples_length;  // the number of subsamples in the sample.
 *     } SampleDescription;
 *
 *     typedef struct {
 *       size_t encrypt;  // number of 16 byte blocks to decrypt.
 *       size_t skip;  // number of 16 byte blocks to leave in clear.
 *     } CENCEncryptPatternDesc;
 *
 *     unsigned int oec_session;
 *     SampleDescription samples[sample_length];
 *     CdmCencPatternEncryptionDescriptor *pattern;
 *     std::vector<SubSampleDescription> subsamples;
 *     unsigned int oec_session;
 *
 *     if (0 != HAL_SVP_WidevineDecryptCENC_V16(oec_session,
 *                                              samples,
 *                                              sample_length,
 *                                              pattern,
 *                                              &oec_return)) {
 *     if (39 == oec_return) {  //  OEMCrypto_ERROR_BUFFER_TOO_LARGE returned
 *         //  Try 1 sample decryption
 *         for (int i = 0; i < sample_length; i++) {
 *             if (0 != HAL_SVP_WidevineDecryptCENC_V16(oec_session,
 *                                                      samples[i],
 *                                                      1,
 *                                                      pattern,
 *                                                      &oec_return)) {
 *                 // error handling
 *             }
 *         }
 *     } else {
 *         // error handling
 *     }
 * @endrst
 */
SVP_STATUS_T HAL_SVP_WidevineDecryptCENC_V16(UINT32 session,
                                             void *samples,
                                             size_t samples_length,
                                             void *pattern,
                                             UINT32 *oec_return);

#endif /* _HAL_SVP_LEGACY_H_ */

