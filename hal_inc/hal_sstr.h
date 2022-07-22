/******************************************************************************
 *   TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2016-2017 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file       hal_sstr.h
 *
 *  This source file defines WebOS Secure Storage Function
 *
 *  @author     seonho.park@lge.com
 *  @author     stan.kim@lge.com
 *  @version    1.0
 *  @date       2016.4
 */

/******************************************************************************
    Header File Guarder
******************************************************************************/
#ifndef _HAL_SSTR_H_
#define _HAL_SSTR_H_

/******************************************************************************
 #include File Inclusions
******************************************************************************/
#include "hal_common.h"

/******************************************************************************
  Type Definitions
******************************************************************************/
// Common Error Code
typedef enum {
    HAL_SSTR_R_OK               = 0,    /**< OK */
    HAL_SSTR_R_GENERAL_ERROR    = -1,   /**< unspecified error */
    HAL_SSTR_R_TEE_FAILURE      = -2,   /**< TEE Problem */
    HAL_SSTR_R_INVALID_BUFSIZE  = -3,   /**< Given buffer size is not enough */
    HAL_SSTR_R_INVALID_KEY      = -4,   /**< pKey is not a type of "Protected SDHK" */
    HAL_SSTR_R_NOT_MATCH        = -5,   /**< HMAC value is not matched */
} HAL_SSTR_R_T;

/******************************************************************************
    Macro Definitions
******************************************************************************/

/******************************************************************************
   Local Constant Definitions
******************************************************************************/

/******************************************************************************
    Local Type Definitions
******************************************************************************/

/******************************************************************************
    Global Type Definitions
******************************************************************************/

/******************************************************************************
    Extern Variables & Function Prototype Declarations
******************************************************************************/

/******************************************************************************
    Static Variables & Function Prototypes Declarations
******************************************************************************/

/******************************************************************************
    Local Variables & Function Prototypes Declarations
******************************************************************************/

/******************************************************************************
    Global Variables & Function Prototypes Declarations
******************************************************************************/

/******************************************************************************
    Function Definitions
******************************************************************************/

/**
 * @brief making SecureData (normal or in-memory protection), and storing sedata into the SoC secure store
 *
 * @rst
 * Functional Requirements
 *   This API performs making SecureData (normal or in-memory protection),
 *   and storing sedata into the SoC secure store.
 *
 *   - SecureData format:
 *   - SecureData =  E_DUK(SDEK) || E_SDEK(Data), where size of SecureData = 32+size of Data
 *
 *       - E_K(data) : encrypting data with a key K
 *       - DUK : Device Unique Key (stored in OTP)
 *       - SDEK : SecureData Encryption Key. The key encryption key to be used to make a SecureData
 *         (encrypt data). This key is randomly generated each time that making SecureData
 *         is requested.
 *
 *   The "in-memory protection" means that data is protected by TEE-encryption and it never be
 *   able to be decrypted in REE side. (It doesn't mean any kernel or SoC level memory protection
 *   featuree). The "in-memory protection" SecureData has a SoC-defined format and can be
 *   decrypted *  only in SoC TEE internal side.
 *
 * Responses to abnormal situations, including
 *   ex) In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   ex) There is no constraints.
 *   ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *   it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *   * HAL_SSTR_R_T HAL_SSTR_MakeSecureData(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData, char *pszDataType)
 *
 *   For the data type, following data types are defined
 *
 *   * nSrcLen     [in]    size of pSrcData
 *   * pSrcData    [in]    buffer for data to be encrypted
 *   * pDstLen     [out]   sizeof pDstData
 *   * pDstData    [out]   buffer to store SecureData
 *   * pszDataType [in]    data type
 *
 *   ============ ========== =============================================
 *   DATA TYPE    pSrcData   pDstData
 *   ============ ========== =============================================
 *   general      Plaintext  SecureData
 *   general_tee  Plaintext  in-memory protection SecureData
 *   sedata       sedata     SecureData
 *   sedata_tee   sedata     in-memory protection SecureData
 *   {key_id}     sedata     NULL (storing data into SoC secure store)
 *   ============ ========== =============================================
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     if (0 != HAL_SSTR_MakeSecureData(nSrcLen, *pSrcData, *pDstLen,
 *                                    *pDstData, *pszDataType)) {
 *         // handling error
 *     }
 * @endrst
 */

HAL_SSTR_R_T HAL_SSTR_MakeSecureData(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                                     UINT8 *pDstData, char *pszDataType);

/**
 * @brief ex) brief contents
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs ....................
 *
 * Responses to abnormal situations, including
 *   ex) In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   ex) There is no constraints.
 *   ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *   it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * HAL_SSTR_R_T HAL_SSTR_GetDataFromSecureData(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData)
 *
 *  For the data type, following data types are defined
 *
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     if (0 != HAL_SSTR_GetDataFromSecureData(nSrcLen, *pSrcData, *pDstLen, *pDstData)) {
 *         // handling error
 *     }
 * @endrst
 */
HAL_SSTR_R_T HAL_SSTR_GetDataFromSecureData(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                                            UINT8 *pDstData);

/**
 * @brief ex) brief contents
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs ....................
 *
 * Responses to abnormal situations, including
 *   ex) In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   ex) There is no constraints.
 *   ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *   it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * HAL_SSTR_R_T HAL_SSTR_GetHMAC(UINT32 nDataSize, UINT8 *pData, UINT8 *pKey, UINT8 *pHMAC)
 *
 *  For the data type, following data types are defined
 *
 *  * nDataSize   [in]    size of pData
 *  * pData       [in]    source data for HMAC
 *  * pKey        [out]   Buffer for Protected SDHK generated by TEE.
 *  * pHMAC       [out]   Buffer to store HMAC value calculated by TEE
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     if (0 != HAL_SSTR_GetDataFromSecureData(nSrcLen, *pSrcData, *pDstLen, *pDstData)) {
 *         // handling error
 *     }
 * @endrst
 */
HAL_SSTR_R_T HAL_SSTR_GetHMAC(UINT32 nDataSize, UINT8 *pData, UINT8 *pKey, UINT8 *pHMAC);

/**
 * @brief ex) brief contents
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs ....................
 *
 * Responses to abnormal situations, including
 *   ex) In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   ex) There is no constraints.
 *   ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *   it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * HAL_SSTR_R_T HAL_SSTR_VerifyHMAC(UINT32 nDataSize, UINT8 *pData, UINT8 *pKey, UINT8 *pHMAC)
 *
 *  For the data type, following data types are defined
 *
 *  * nDataSize   [in]    size of pData
 *  * pData       [in]    source data for HMAC
 *  * pKey        [in]    Protected SDHK
 *  * pHMAC       [in]    HMAC value
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     if (0 != HAL_SSTR_GetDataFromSecureData(nSrcLen, *pSrcData, *pDstLen, *pDstData)) {
 *         // handling error
 *     }
 * @endrst
 */
HAL_SSTR_R_T HAL_SSTR_VerifyHMAC(UINT32 nDataSize, UINT8 *pData, UINT8 *pKey, UINT8 *pHMAC);

/**
 * @brief ex) brief contents
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs ....................
 *
 * Responses to abnormal situations, including
 *   ex) In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   ex) There is no constraints.
 *   ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *   it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * HAL_SSTR_R_T HAL_SSTR_GenAESKey(UINT32 nSize, UINT8 *pKey)
 *
 *  For the data type, following data types are defined
 *
 *  * nSize   [in]    Size of key to be generated
 *  * pKey    [out]   Buffer to store the generated key
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     if (0 != HAL_SSTR_GetDataFromSecureData(nSrcLen, *pSrcData, *pDstLen, *pDstData)) {
 *         // handling error
 *     }
 * @endrst
 */
HAL_SSTR_R_T HAL_SSTR_GenAESKey(UINT32 nSize, UINT8 *pKey);

/**
 * @brief webOS Secure Store Support APIs for TEE Crypto
 *
 * @rst
 * Functional Requirements
 *   Perform TEE AES encryption with In-Memory Protected SecureData.
 *   128 and 256 bits key size should be supported, and PKCS#5 padding should be used.
 *   The pKey is a SecureData.
 *   ECB and CBC mode should be supported. The mode of operation is specified by the parameter
 *   pszMode of which the type is char pointer type string. "ECB" or "CBC" can be passed.
 *   When using CBC, IV value should be generated randomly in TEE and attached in front of
 *   the encrypted result buffer. For decryption, the IV is retrieved from the source buffer
 *   (16bytes in front of the encrypted data).
 *
 * Responses to abnormal situations, including
 *   ex) In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   ex) There is no constraints.
 *   ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *   it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * HAL_SSTR_R_T HAL_SSTR_AES_Encrypt(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData, char *pszMode, UINT8 *pKey, UINT32 nKeySize)
 *
 *  For the data type, following data types are defined
 *
 *  * nSrcLen    [IN]        Size of data to be encrypted
 *  * pSrcData   [IN]        Buffer for data to be encrypted
 *  * pDstLen    [OUT]       Size of output data (the result of encryption)
 *  * pDstData   [OUT]       Buffer for output data (the result of encryption)
 *  * pszMode    [IN]        Block cipher Mode ("ECB" / "CBC")
 *  * pKey       [IN]        SecureData of cipher key
 *  * nKeySize   [IN]        Size of pKey data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     if (0 != HAL_SSTR_GetDataFromSecureData(nSrcLen, *pSrcData, *pDstLen, *pDstData)) {
 *         // handling error
 *     }
 * @endrst
 */
HAL_SSTR_R_T HAL_SSTR_AES_Encrypt(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                          UINT8 *pDstData, char *pszMode, UINT8 *pKey, UINT32 nKeySize);

/**
 * @brief Perform TEE AES decryption with In-Memory Protected SecureData.
 *
 * @rst
 * Functional Requirements
 *   Perform TEE AES decryption with In-Memory Protected SecureData.
 *   128 and 256 bits key size should be supported, and PKCS#5 padding should be used.
 *   The pKey is a SecureData.
 *   ECB and CBC mode should be supported. The mode of operation is specified by the parameter
 *   pszMode of which the type is char pointer type string. "ECB" or "CBC" can be passed.
 *   When using CBC, IV value should be generated randomly in TEE and attached in front of
 *   the encrypted result buffer. For decryption, the IV is retrieved from the source buffer
 *   (16bytes in front of the encrypted data).
 *
 * Responses to abnormal situations, including
 *   ex) In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   ex) There is no constraints.
 *   ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *   it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * HAL_SSTR_R_T HAL_SSTR_AES_Decrypt(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData, char *pszMode, UINT8 *pKey, UINT32 nKeySize)
 *
 *  For the data type, following data types are defined
 *
 *  * nSrcLen     [IN]        Size of data to be decrypted
 *  * pSrcData    [IN]        Buffer for data to be decrypted
 *  * pDstLen     [OUT]       Size of output data (the result of decryption)
 *  * pDstData    [OUT]       Buffer for output data (the result of decryption)
 *  * pszMode     [IN]        Block cipher Mode (ECB / CBC)
 *  * pKey        [IN]        SecureData of cipher key
 *  * nKeySize    [IN]        Size of pKey data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     if (0 != HAL_SSTR_GetDataFromSecureData(nSrcLen, *pSrcData, *pDstLen, *pDstData)) {
 *         // handling error
 *     }
 * @endrst
 */
HAL_SSTR_R_T HAL_SSTR_AES_Decrypt(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                          UINT8 *pDstData, char *pszMode, UINT8 *pKey, UINT32 nKeySize);

/*
 * RSA Padding Type for HAL_SSTR_RSA_Encrypt, HAL_SSTR_RSA_Decrypt APIs.
 */
typedef enum {
    HAL_SSTR_RSA_NO_PADDING,
    HAL_SSTR_RSA_PKCS1_OAEP_PADDING
} HAL_SSTR_RSA_PADDING_T;

/**
 * @brief Perform RSA encryption with In-Memory Protected SecureData.
 *
 * @rst
 * Functional Requirements
 *   Perform RSA encryption with In-Memory Protected SecureData.
 *   The passed pKey is a type of SecureData, and original key is has a format of PKCS#1 and
 *   encoded by either DER or PEM. So, the encoding type should be passed via the parameter
 *   pszKeyType.
 *
 * Responses to abnormal situations, including
 *   ex) In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   ex) There is no constraints.
 *   ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *   it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * HAL_SSTR_R_T HAL_SSTR_RSA_Encrypt(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData, HAL_SSTR_RSA_PADDING_T padding, char *pszKeyType, UINT8 *pKey, UINT32 nKeySize)
 *
 *  For the data type, following data types are defined
 *
 *  * pSrcLen         [IN]     Size of data to be encrypted
 *  * pSrcData        [IN]     Buffer for data to be encrypted
 *  * pDstLen         [OUT]    Size of output data (the result of encryption)
 *  * pDstData        [OUT]    Buffer for output data (the result of encryption)
 *  * padding         [IN]     Padding Type (RSA_NO_PADDING or PKCS1_OAEP_PADDING)
 *  * pszKeyType      [IN]     Key Encoding Type. ("PEM" or "DER")
 *  * pKey            [IN]     SecureData of cipher key
 *  * nKeySize        [IN]     Size of pKey data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     if (0 != HAL_SSTR_GetDataFromSecureData(nSrcLen, *pSrcData, *pDstLen, *pDstData)) {
 *         // handling error
 *     }
 * @endrst
 */
HAL_SSTR_R_T HAL_SSTR_RSA_Encrypt(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                          UINT8 *pDstData, HAL_SSTR_RSA_PADDING_T padding, char *pszKeyType,
                          UINT8 *pKey, UINT32 nKeySize);

/**
 * @brief Perform RSA decryption with In-Memory Protected SecureData.
 *
 * @rst
 * Functional Requirements
 *   Perform RSA decryption with In-Memory Protected SecureData.
 *   The passed pKey is a type of SecureData, and original key is has a format of PKCS#1 and
 *   encoded by either DER or PEM. So, the encoding type should be passed via the parameter
 *   pszKeyType.
 *
 * Responses to abnormal situations, including
 *   ex) In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   ex) There is no constraints.
 *   ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *   it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * HAL_SSTR_R_T HAL_SSTR_RSA_Decrypt(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData, HAL_SSTR_RSA_PADDING_T padding, char *pszKeyType, UINT8 *pKey, UINT32 nKeySize)
 *
 *  For the data type, following data types are defined
 *
 *  * pSrcLen        [IN]      Size of data to be decrypted
 *  * pSrcData       [IN]      Buffer for data to be decrypted
 *  * pDstLen        [OUT]     Size of output data (the result of decryption)
 *  * pDstData       [OUT]     Buffer for output data (the result of encryption/decryption)
 *  * padding        [IN]     Padding Type (RSA_NO_PADDING or PKCS1_OAEP_PADDING)
 *  * pszKeyType     [IN]      Key Encoding Type. ("PEM" or "DER")
 *  * pKey           [IN]      SecureData of cipher key
 *  * nKeySize       [IN]      Size of pKey data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     if (0 != HAL_SSTR_GetDataFromSecureData(nSrcLen, *pSrcData, *pDstLen, *pDstData)) {
 *         // handling error
 *     }
 * @endrst
 */
HAL_SSTR_R_T HAL_SSTR_RSA_Decrypt(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                          UINT8 *pDstData, HAL_SSTR_RSA_PADDING_T padding, char *pszKeyType,
                          UINT8 *pKey, UINT32 nKeySize);

/**
 * @brief Perform RSA Signing in TEE with In-Memory Protected SecureData.
 *
 * @rst
 * Functional Requirements
 *   Perform RSA Signing in TEE with In-Memory Protected SecureData.
 *   Signing message encoding scheme is "SHA256 / EMSA-PKCS1-v1_5 Encoding"
 *   pKey is a SecureData type and its original key data is PKCS#1 format that is encoded
 *   by DER or PEM.
 *
 * Responses to abnormal situations, including
 *   ex) In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   ex) There is no constraints.
 *   ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *   it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * HAL_SSTR_R_T HAL_SSTR_RSA_Sign(UINT32 nDataSize, UINT8 *pData, UINT32 *pSigLen, UINT8 *pSig, char *pszKeyType, UINT8 *pKey, UINT32 nKeySize)
 *
 *  For the data type, following data types are defined
 *
 *  * nDataSize         [IN]      Size of data to be signed
 *  * pData             [IN]      Data to be signed
 *  * pSigLen           [OUT]     Size of signature (pSig)
 *  * pSig              [OUT]     Signature data
 *  * pszKeyType        [IN]      Key Encoding Type. ("PEM" or "DER")
 *  * pKey              [IN]      SecureData of cipher key
 *  * nKeyLen           [IN]      Size of pKey data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     if (0 != HAL_SSTR_GetDataFromSecureData(nSrcLen, *pSrcData, *pDstLen, *pDstData)) {
 *         // handling error
 *     }
 * @endrst
 */
HAL_SSTR_R_T HAL_SSTR_RSA_Sign(UINT32 nDataSize, UINT8 *pData, UINT32 *pSigLen, UINT8 *pSig,
                          char *pszKeyType, UINT8 *pKey, UINT32 nKeySize);

/**
 * @brief Perform RSA signature verification in TEE with In-Memory Protected SecureData.
 *
 * @rst
 * Functional Requirements
 *   Perform RSA signature verification in TEE with In-Memory Protected SecureData.
 *   Signing message encoding scheme is "SHA256 / EMSA-PKCS1-v1_5 Encoding"
 *   pKey is a SecureData type and its original key data is PKCS#1 format that is encoded
 *   by DER or PEM.
 *
 * Responses to abnormal situations, including
 *   ex) In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   ex) There is no constraints.
 *   ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *   it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * HAL_SSTR_R_T HAL_SSTR_RSA_Verify(UINT32 nDataSize, UINT8 *pData, UINT32 nSigLen, UINT8 *pSig, char *pszKeyType, UINT8 *pKey, UINT32 nKeySize)
 *
 *  For the data type, following data types are defined
 *
 *  * nDataSize         [IN]      Size of data to be verified
 *  * pData             [IN]      Data to be verified
 *  * nSigLen           [IN]      Size of signature (pSig)
 *  * pSig              [IN]      Signature data
 *  * pszKeyType        [IN]      Key Encoding Type. ("PEM" or "DER")
 *  * pKey              [IN]      SecureData of cipher key
 *  * nKeyLen           [IN]      Size of pKey data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     if (0 != HAL_SSTR_GetDataFromSecureData(nSrcLen, *pSrcData, *pDstLen, *pDstData)) {
 *         // handling error
 *     }
 * @endrst
 */
HAL_SSTR_R_T HAL_SSTR_RSA_Verify(UINT32 nDataSize, UINT8 *pData, UINT32 nSigLen, UINT8 *pSig,
                          char *pszKeyType, UINT8 *pKey, UINT32 nKeySize);


#endif      //_HAL_SSTR_H_

