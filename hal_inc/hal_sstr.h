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
 *  HAL_SSTR_MakeSecureData
 *  This API performs making SecureData (normal or in-memory protection),
 *  and storing sedata into the SoC secure store.
 *
 *  SecureData format:
 *  SecureData =  E_DUK(SDEK) || E_SDEK(Data), where size of SecureData = 32+size of Data
 *   - E_K(data) : encrypting data with a key K
 *   - DUK : Device Unique Key (stored in OTP)
 *   - SDEK : SecureData Encryption Key. The key encryption key to be used to make a SecureData
 *            (encrypt data). This key is randomly generated each time that making SecureData
 *            is requested.
 *
 *  The "in-memory protection" means that data is protected by TEE-encryption and it never be
 *  able to be decrypted in REE side. (It doesn't mean any kernel or SoC level memory protection
 *  featuree). The "in-memory protection" SecureData has a SoC-defined format and can be
 *  decrypted *  only in SoC TEE internal side.
 *
 *  For the data type, following data types are defined
 *   +========================================================================+
 *   | DATA TYPE   | pSrcData  | pDstData                                     |
 *   +-------------+-----------+----------------------------------------------+
 *   | general     | Plaintext | SecureData                                   |
 *   | general_tee | Plaintext | in-memory protection SecureData              |
 *   | sedata      | sedata    | SecureData                                   |
 *   | sedata_tee  | sedata    | in-memory protection SecureData              |
 *   | {key_id}    | sedata    | NULL (storing data into SoC secure store)    |
 *   +========================================================================+
 *
 *  @param  nSrcLen     [in]    size of pSrcData
 *  @param  pSrcData    [in]    buffer for data to be encrypted
 *  @param  pDstLen     [out]   sizeof pDstData
 *  @param  pDstData    [out]   buffer to store SecureData
 *  @param  pszDataType [in]    data type
 *  @return Common Error Code.
 */
HAL_SSTR_R_T HAL_SSTR_MakeSecureData(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                                     UINT8 *pDstData, char *pszDataType);

/**
 *  HAL_SSTR_GetDataFromSecureData
 *
 *  @param  nSrcLen     [in]    size of pSrcData
 *  @param  pSrcData    [in]    buffer for data to be decrypted
 *  @param  pDstLen     [out]   sizeof pDstData
 *  @param  pDstData    [out]   buffer to store the decrypted data
 *  @return Common Error Code.
 */
HAL_SSTR_R_T HAL_SSTR_GetDataFromSecureData(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                                            UINT8 *pDstData);

/**
 *  HAL_SSTR_GetHMAC
 *
 *  @param  nDataSize   [in]    size of pData
 *  @param  pData       [in]    source data for HMAC
 *  @param  pKey        [out]   Buffer for Protected SDHK generated by TEE.
 *  @param  pHMAC       [out]   Buffer to store HMAC value calculated by TEE
 *  @return Common Error Code.
 */
HAL_SSTR_R_T HAL_SSTR_GetHMAC(UINT32 nDataSize, UINT8 *pData, UINT8 *pKey, UINT8 *pHMAC);

/**
 *  HAL_SSTR_VerifyHMAC
 *
 *  @param  nDataSize   [in]    size of pData
 *  @param  pData       [in]    source data for HMAC
 *  @param  pKey        [in]    Protected SDHK
 *  @param  pHMAC       [in]    HMAC value
 *  @return Common Error Code.
 */
HAL_SSTR_R_T HAL_SSTR_VerifyHMAC(UINT32 nDataSize, UINT8 *pData, UINT8 *pKey, UINT8 *pHMAC);

/**
 *  HAL_SSTR_GenAESKey
 *
 *  @param  nSize   [in]    Size of key to be generated
 *  @param  pKey    [out]   Buffer to store the generated key
 *  @return Common Error Code.
 */
HAL_SSTR_R_T HAL_SSTR_GenAESKey(UINT32 nSize, UINT8 *pKey);

/* webOS Secure Store Support APIs for TEE Crypto */
/**
 * Perform TEE AES encryption with In-Memory Protected SecureData.
 * 128 and 256 bits key size should be supported, and PKCS#5 padding should be used.
 * The pKey is a SecureData.
 * ECB and CBC mode should be supported. The mode of operation is specified by the parameter
 * pszMode of which the type is char pointer type string. "ECB" or "CBC" can be passed.
 * When using CBC, IV value should be generated randomly in TEE and attached in front of
 * the encrypted result buffer. For decryption, the IV is retrieved from the source buffer
 * (16bytes in front of the encrypted data).
 *
 *  @param   nSrcLen    [IN]        Size of data to be encrypted
 *  @param   pSrcData   [IN]        Buffer for data to be encrypted
 *  @param   pDstLen    [OUT]       Size of output data (the result of encryption)
 *  @param   pDstData   [OUT]       Buffer for output data (the result of encryption)
 *  @param   pszMode    [IN]        Block cipher Mode ("ECB" / "CBC")
 *  @param   pKey       [IN]        SecureData of cipher key
 *  @param   nKeySize   [IN]        Size of pKey data
 *  @return Common Error Code.
 */
HAL_SSTR_R_T HAL_SSTR_AES_Encrypt(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                          UINT8 *pDstData, char *pszMode, UINT8 *pKey, UINT32 nKeySize);
/*
 * Perform TEE AES decryption with In-Memory Protected SecureData.
 * 128 and 256 bits key size should be supported, and PKCS#5 padding should be used.
 * The pKey is a SecureData.
 * ECB and CBC mode should be supported. The mode of operation is specified by the parameter
 * pszMode of which the type is char pointer type string. "ECB" or "CBC" can be passed.
 * When using CBC, IV value should be generated randomly in TEE and attached in front of
 * the encrypted result buffer. For decryption, the IV is retrieved from the source buffer
 * (16bytes in front of the encrypted data).
 *
 *  @param   nSrcLen     [IN]        Size of data to be decrypted
 *  @param   pSrcData    [IN]        Buffer for data to be decrypted
 *  @param   pDstLen     [OUT]       Size of output data (the result of decryption)
 *  @param   pDstData    [OUT]       Buffer for output data (the result of decryption)
 *  @param   pszMode     [IN]        Block cipher Mode (ECB / CBC)
 *  @param   pKey        [IN]        SecureData of cipher key
 *  @param   nKeySize    [IN]        Size of pKey data
 *  @return Common Error Code.
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
/*
 * Perform RSA encryption with In-Memory Protected SecureData.
 * The passed pKey is a type of SecureData, and original key is has a format of PKCS#1 and
 * encoded by either DER or PEM. So, the encoding type should be passed via the parameter
 * pszKeyType.
 *
 *  @param   pSrcLen         [IN]     Size of data to be encrypted
 *  @param   pSrcData        [IN]     Buffer for data to be encrypted
 *  @param   pDstLen         [OUT]    Size of output data (the result of encryption)
 *  @param   pDstData        [OUT]    Buffer for output data (the result of encryption)
 *  @param   padding         [IN]     Padding Type (RSA_NO_PADDING or PKCS1_OAEP_PADDING)
 *  @param   pszKeyType      [IN]     Key Encoding Type. ("PEM" or "DER")
 *  @param   pKey            [IN]     SecureData of cipher key
 *  @param   nKeySize        [IN]     Size of pKey data
 *  @return Common Error Code.
 */
HAL_SSTR_R_T HAL_SSTR_RSA_Encrypt(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                          UINT8 *pDstData, HAL_SSTR_RSA_PADDING_T padding, char *pszKeyType,
                          UINT8 *pKey, UINT32 nKeySize);

/*
 * Perform RSA decryption with In-Memory Protected SecureData.
 * The passed pKey is a type of SecureData, and original key is has a format of PKCS#1 and
 * encoded by either DER or PEM. So, the encoding type should be passed via the parameter
 * pszKeyType.
 *
 *  @param   pSrcLen        [IN]      Size of data to be decrypted
 *  @param   pSrcData       [IN]      Buffer for data to be decrypted
 *  @param   pDstLen        [OUT]     Size of output data (the result of decryption)
 *  @param   pDstData       [OUT]     Buffer for output data (the result of encryption/decryption)
 *  @param   padding        [IN]     Padding Type (RSA_NO_PADDING or PKCS1_OAEP_PADDING)
 *  @param   pszKeyType     [IN]      Key Encoding Type. ("PEM" or "DER")
 *  @param   pKey           [IN]      SecureData of cipher key
 *  @param   nKeySize       [IN]      Size of pKey data
 *  @return Common Error Code.
 */
HAL_SSTR_R_T HAL_SSTR_RSA_Decrypt(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                          UINT8 *pDstData, HAL_SSTR_RSA_PADDING_T padding, char *pszKeyType,
                          UINT8 *pKey, UINT32 nKeySize);

/*
 * Perform RSA Signing in TEE with In-Memory Protected SecureData.
 * Signing message encoding scheme is "SHA256 / EMSA-PKCS1-v1_5 Encoding"
 * pKey is a SecureData type and its original key data is PKCS#1 format that is encoded
 * by DER or PEM.
 *
 *  @param   nDataSize         [IN]      Size of data to be signed
 *  @param   pData             [IN]      Data to be signed
 *  @param   pSigLen           [OUT]     Size of signature (pSig)
 *  @param   pSig              [OUT]     Signature data
 *  @param   pszKeyType        [IN]      Key Encoding Type. ("PEM" or "DER")
 *  @param   pKey              [IN]      SecureData of cipher key
 *  @param   nKeyLen           [IN]      Size of pKey data
 *  @return Common Error Code.
*/
HAL_SSTR_R_T HAL_SSTR_RSA_Sign(UINT32 nDataSize, UINT8 *pData, UINT32 *pSigLen, UINT8 *pSig,
                          char *pszKeyType, UINT8 *pKey, UINT32 nKeySize);

/*
 * Perform RSA signature verification in TEE with In-Memory Protected SecureData.
 * Signing message encoding scheme is "SHA256 / EMSA-PKCS1-v1_5 Encoding"
 * pKey is a SecureData type and its original key data is PKCS#1 format that is encoded
 * by DER or PEM.
 *
 *  @param   nDataSize         [IN]      Size of data to be verified
 *  @param   pData             [IN]      Data to be verified
 *  @param   nSigLen           [IN]      Size of signature (pSig)
 *  @param   pSig              [IN]      Signature data
 *  @param   pszKeyType        [IN]      Key Encoding Type. ("PEM" or "DER")
 *  @param   pKey              [IN]      SecureData of cipher key
 *  @param   nKeyLen           [IN]      Size of pKey data
 *  @return Common Error Code.
*/
HAL_SSTR_R_T HAL_SSTR_RSA_Verify(UINT32 nDataSize, UINT8 *pData, UINT32 nSigLen, UINT8 *pSig,
                          char *pszKeyType, UINT8 *pKey, UINT32 nKeySize);


#endif      //_HAL_SSTR_H_

