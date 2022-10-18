/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999-2016 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/


/** @file hal_crypto.h
 *
 * This source file defines the HAL functions related to crypto driver control
 *
 *  @author     Seonho Park (seonho.park@lge.com)
 *  @author     Seulki Kim  (seulki329.kim@lge.com)
 *  @version    5.0
 *  @date       2017.03.03
 */

/******************************************************************************
    Header File Guarder
 ******************************************************************************/
#ifndef _HAL_CRYPTO_H_
#define _HAL_CRYPTO_H_

/******************************************************************************
  #include  (File Inclusions)
 ******************************************************************************/
#include "hal_common.h"



/******************************************************************************
    Type Definitions
 ******************************************************************************/
#define HAL_CRYPTO_ARG_MAX 8

typedef struct _HAL_CRYPTO_ARG {
    UINT32 command;                          /* Command */
    UINT8  argc;                             /* Number of arguments */
    UINT8 *argv[HAL_CRYPTO_ARG_MAX]; /* Array of argument pointer */
    UINT32 argvLen[HAL_CRYPTO_ARG_MAX];   /* Array of argument length */
    BOOLEAN   out[HAL_CRYPTO_ARG_MAX];     /* Array of boolean value for out/in */
} HAL_CRYPTO_ARG_T;

/******************************************************************************
    Macro Definitions
 ******************************************************************************/

/******************************************************************************
    Global Type Definitions
 ******************************************************************************/

/******************************************************************************
    Global Variables & Function Prototypes Declarations
 ******************************************************************************/

/******************************************************************************
    Extern Variables & Function Prototype Declarations
 ******************************************************************************/

/* Netflix */
/**
* @brief Write ESN key to secure storage for provisioning
*
* @rst
* Functional Requirements
*      1. check if identifier is "idfile". other id is on failure.
*      2. verify CRC32 integrity
*      3. decrypt input data and re-encrypt with device-unique key in TEE.
*      4. store into sestore.
*      5. the data(only ESN ID) should be read via HAL_CRYPTO_NF_GetESN().
*
* Responses to abnormal situations, including
*      There is no clear requirement for response time, but a response must be received within at least 300 ms.
*
* Constraints
*      There is no constraints.
*
* Functions & Parameters
*      * DTV_STATUS_T HAL_CRYPTO_WriteSecureData(char *pIdentifier, UINT8 *pData, int dataLength)
*
*      For the data type, following data types are defined
*
*      * pIdentifier      [in]   identirier(only "idfile" is suitable)
*      * pData            [in]   ESN key data(ESN ID + Kpe + Kph)
*      * length           [in]   ESN key data length
*
* Return Value
*     Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*      .. code-block:: cpp
*
*        char *NF_KEYSET_ID = "idfile";
*        int nLength = 248;
*        UINT8 *pData;
*        DTV_STATUS_T ret;
*        ret = HAL_CRYPTO_WriteSecureData(NF_KEYSET_ID, pData, nLength);
* @endrst
*/
DTV_STATUS_T HAL_CRYPTO_WriteSecureData(char *pIdentifier, UINT8 *pData, int dataLength);

/**
* @brief Get ESN key value
*
* @rst
* Functional Requirements
*      1. check if ESN is written by HAL_CRYPTO_WriteSecureData.
*      2. the data(only ESN ID) should be read.
*
* Responses to abnormal situations, including
*      There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*      There is no constraints.
*
* Functions & Parameters
*      * DTV_STATUS_T HAL_CRYPTO_NF_GetESN(UINT8 *pEsn)
*
*      For the data type, following data types are defined
*
*      * *pEsn            [IN/OUT] ESN buffer pointer / ESN ID
*
* Return Value
*     Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*      .. code-block:: cpp
*
*        UINT8 *pEsn;
*        DTV_STATUS_T ret;
*        ret = HAL_CRYPTO_NF_GetESN(pEsn);
* @endrst
*/
DTV_STATUS_T HAL_CRYPTO_NF_GetESN(UINT8 *pEsn);

/**
* @brief encrypt data with device unique key
*
* @rst
* Functional Requirements
*      1. encrypt data with device unique key
*
* Responses to abnormal situations, including
*      There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*      There is no constraints.
*
* Functions & Parameters
*      * DTV_STATUS_T HAL_CRYPTO_NF_Encrypt(UINT8 *pData, UINT32 nLength)
*
*      For the data type, following data types are defined
*
*      * *pData           [IN/OUT] data to be encrypted
*      * length           [IN] data length
*
* Return Value
*     Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*      .. code-block:: cpp
*
*        UINT8 testStr[128] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890+/";
*        int size = strlen((const char*)testStr);
*        DTV_STATUS_T ret;
*        ret = HAL_CRYPTO_NF_Encrypt(testStr, size);
* @endrst
*/
DTV_STATUS_T HAL_CRYPTO_NF_Encrypt(UINT8 *pData, UINT32 nLength);

/**
* @brief decrypt data with device unique key
*
* @rst
* Functional Requirements
*      1. decrypt data with device unique key
*
* Responses to abnormal situations, including
*      There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*      There is no constraints.
*
* Functions & Parameters
*      * DTV_STATUS_T HAL_CRYPTO_NF_Decrypt(UINT8 *pData, UINT32 nLength)
*
*      For the data type, following data types are defined
*
*      * *pData           [IN/OUT] encrypted data(via HAL_CRYPTO_NF_Encrypt) to be decrypted
*      * length           [IN] data length
*
* Return Value
*     Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*      .. code-block:: cpp
*
*        UINT8 testStr[128] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890+/";
*        int size = strlen((const char*)testStr);
*        DTV_STATUS_T ret;
*        ret = HAL_CRYPTO_NF_Encrypt(testStr, size);
*        ret = HAL_CRYPTO_NF_Decrypt(testStr, size);
* @endrst
*/
DTV_STATUS_T HAL_CRYPTO_NF_Decrypt(UINT8 *pData, UINT32 nLength);

/**
* @brief encrypt data with device unique key and integrity check
*
* @rst
* Functional Requirements
*      1. encrypt data with device unique key and integrity check
*
* Responses to abnormal situations, including
*      There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*      There is no constraints.
*
* Functions & Parameters
*      * DTV_STATUS_T HAL_CRYPTO_NF_Encrypt_Ex(const UINT8 *pInput, UINT32 uInputSize, UINT8 **ppOutput, UINT32 *puOutputSize)
*
*      For the data type, following data types are defined
*
*      * *pInput          [IN] clear data
*      * uInputSize       [IN] input data length
*      * **ppOutput       [OUT] encrypted data with integrity check
*      * *puOutputSize    [OUT] output data length
*
* Return Value
*     Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*      .. code-block:: cpp
*
*        UINT8 testStr[128] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890+/";
*        int size = strlen((const char*)testStr);
*        unsigned char *enOutData = NULL;
*        unsigned int enOutSize = 0;
*        DTV_STATUS_T ret;
*        ret = HAL_CRYPTO_NF_Encrypt_Ex(testStr, size, &enOutData, &enOutSize);
* @endrst
*/
DTV_STATUS_T HAL_CRYPTO_NF_Encrypt_Ex(const UINT8 *pInput, UINT32 uInputSize, UINT8 **ppOutput, UINT32 *puOutputSize );

/**
* @brief decrypt data with device unique key and integrity check
*
* @rst
* Functional Requirements
*      1. decrypt data with device unique key and integrity check
*
* Responses to abnormal situations, including
*      There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*      There is no constraints.
*
* Functions & Parameters
*      * DTV_STATUS_T HAL_CRYPTO_NF_Decrypt_Ex(const UINT8 *pInput, UINT32 uInputSize, UINT8 **ppOutput, UINT32 *puOutputSize )
*
*      For the data type, following data types are defined
*
*      * *pInput          [IN] encrypted data(via HAL_CRYPTO_NF_Encrypt_Ex) with integrity check to be decrypted
*      * uInputSize       [IN] input data length
*      * **ppOutput       [OUTPUT] clear data
*      * *puOutputSize    [OUTPUT] clear data length
*
* Return Value
*     Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*      .. code-block:: cpp
*
*        UINT8 testStr[128] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890+/";
*        int size = strlen((const char*)testStr);
*        unsigned char *enOutData = NULL;
*        unsigned int enOutSize = 0;
*        unsigned char *deOutData = NULL;
*        unsigned int deOutSize = 0;
*        DTV_STATUS_T ret;
*        ret = HAL_CRYPTO_NF_Encrypt_Ex(testStr, size, &enOutData, &enOutSize);
*        ret = HAL_CRYPTO_NF_Decrypt_Ex(enOutData, enOutSize, &deOutData, &deOutSize);
* @endrst
*/
DTV_STATUS_T HAL_CRYPTO_NF_Decrypt_Ex(const UINT8 *pInput, UINT32 uInputSize, UINT8 **ppOutput, UINT32 *puOutputSize );

/**
* @brief Write App Data to Secure Store
*
* @rst
* Functional Requirements
*      1. Write App Data to Secure Store
*
* Responses to abnormal situations, including
*      There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*      There is no constraints.
*
* Functions & Parameters
*      * DTV_STATUS_T HAL_CRYPTO_NF_WriteAppData(char *pDataId, UINT8 *pData, int length)
*
*      For the data type, following data types are defined
*
*      * *pDataId         [IN] Data Identifier
*      * *pData           [IN] Data to be encrypted
*      * length           [IN] Data length
*
* Return Value
*     Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*      .. code-block:: cpp
*
*        char *NF_KEYSET_ID = "idfile";
*        int nLength = 248;
*        UINT8 *pData;
*        DTV_STATUS_T ret;
*        ret = HAL_CRYPTO_WriteAppData(NF_KEYSET_ID, pData, nLength);
 * @endrst
*/
DTV_STATUS_T HAL_CRYPTO_NF_WriteAppData(char *pDataId, UINT8 *pData, int length);

/**
* @brief Read App Data to Secure Store.
*
* @rst
* Functional Requirements
*      1. Read App Data to Secure Store.
*
* Responses to abnormal situations, including
*      There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*      There is no constraints.
*
* Functions & Parameters
*      * DTV_STATUS_T HAL_CRYPTO_NF_ReadAppData(char *pDataId, UINT8 *pData, int length)
*
*      For the data type, following data types are defined
*
*      * *pDataId         [IN] Data Identifier
*      * *pData           [IN/OUT] Decrypted data
*      * length           [IN] Data length
*
* Return Value
*     Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*      .. code-block:: cpp
*
*        char *NF_KEYSET_ID = "idfile";
*        int nLength = 248;
*        UINT8 *pData;
*        DTV_STATUS_T ret;
*        ret = HAL_CRYPTO_ReadAppData(NF_KEYSET_ID, pData, nLength);
 * @endrst
*/
DTV_STATUS_T HAL_CRYPTO_NF_ReadAppData(char *pDataId, UINT8 *pData, int length);

/**
* @brief Netflix crypto TEE operations(generate keys / encrypt / decrypt / HMAC)
*
* @rst
* Functional Requirements
*      1. Netflix crypto TEE operations(generate keys / encrypt / decrypt / HMAC)
*      2. Meet Netflix version spec for parameter
*
* Responses to abnormal situations, including
*      There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*      There is no constraints.
*
* Functions & Parameters
*      * DTV_STATUS_T HAL_CRYPTO_NF_Operate(HAL_CRYPTO_ARG_T *tCommon)
*
*      For the data type, following data types are defined
*
*      * pComm                [IN/OUT] crypto structure
*      * pComm->command       [IN]  crypto operations
*      * pComm->argc          [IN] : number of arguments
*      * pComm->argv[0]       [IN] : request data pointer
*      * pComm->argvLen[0]    [IN] : request data size
*      * pComm->argv[1]       [OUT] : response data pointer
*      * pComm->argvLen[1]    [OUT]  : response data size
*
* Return Value
*     Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*      .. code-block:: cpp
*
*        HAL_CRYPTO_ARG_T pComm;
*        DTV_STATUS_T ret;
*        ret = HAL_CRYPTO_NF_Operate(&pComm);
 * @endrst
*/
DTV_STATUS_T HAL_CRYPTO_NF_Operate(HAL_CRYPTO_ARG_T *tCommon);

/**
* @brief Init Netflix Crypto
*
* @rst
* Functional Requirements
*      1. Init Netflix Crypto
*      2. Before using WebCrypto, Initialize something here. If there is nothing to initialize, please return OK
*
* Responses to abnormal situations, including
*      There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*      There is no constraints.
*
* Functions & Parameters
*      * DTV_STATUS_T HAL_CRYPTO_NF_Init(void)
*
*      For the data type, following data types are defined
*
* Return Value
*     Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*      .. code-block:: cpp
*
*        DTV_STATUS_T ret;
*        ret = HAL_CRYPTO_NF_Init();
 * @endrst
*/
DTV_STATUS_T HAL_CRYPTO_NF_Init(void);

/**
* @brief To clean up Netflix webCrypto and SoC TEE operation
*
* @rst
* Functional Requirements
*      1. To clean up Netflix webCrypto and SoC TEE operation
*      2. If there is nothing to cleanup, please return OK
*
* Responses to abnormal situations, including
*      There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*      There is no constraints.
*
* Functions & Parameters
*      * DTV_STATUS_T HAL_CRYPTO_NF_CleanUp(void)
*
*      For the data type, following data types are defined
*
* Return Value
*     Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*      .. code-block:: cpp
*
*        DTV_STATUS_T ret;
*        ret = HAL_CRYPTO_NF_CleanUp();
 * @endrst
*/
DTV_STATUS_T HAL_CRYPTO_NF_CleanUp(void);

/**
* @brief Destroy context.
*
* @rst
* Functional Requirements
*      1. Destroy context.
*      2. If there is nothing to destory, please return OK
*
* Responses to abnormal situations, including
*      There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*      There is no constraints.
*
* Functions & Parameters
*      * DTV_STATUS_T HAL_CRYPTO_NF_DestroyContext(void *pContext)
*
*      For the data type, following data types are defined
*
*      * void *pContext   [IN]
*
* Return Value
*     Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*      .. code-block:: cpp
*
*        void *pContext = NULL;
*        DTV_STATUS_T ret;
*        ret = HAL_CRYPTO_NF_DestroyContext(pContext);
 * @endrst
*/
DTV_STATUS_T HAL_CRYPTO_NF_DestroyContext(void *pContext);

/* NYX */

/**
 * @brief Generate aes key for encryption and decrytion
 *
 * @rst
 * Functional Requirements
 *   Returns a randomly generated encryption key,
 *   but that key must be data encrypted by a TEE generated Device Unique Key, not in plain form.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *   * DTV_STATUS_T HAL_CRYPTO_NYX_AES_GenerateSecureKey(unsigned char *pSecureKey, int keyLength)
 *
 *   For the data type, following data types are defined
 *
 *   * pSecureKey   [out]   buffer for generated for aes encryption/decryption. this is secure data encrypted in TEE instead of plain data.
 *   * keyLength    [in]    aes key size (16 or 32)
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     unsigned char* key16 = NULL;
 *     key16 = (unsigned char*) malloc(sizeof(char) * 16);
 *     if (0 != HAL_CRYPTO_NYX_AES_GenerateSecureKey(key16, 16)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_CRYPTO_NYX_AES_GenerateSecureKey(unsigned char *pSecureKey, int keyLength);

/**
 * @brief Perform TEE AES encryption
 *
 * @rst
 * Functional Requirements
 *   Perform TEE AES encryption or decryption with secured key data which is maded by HAL_CRYPTO_NYX_AES_GenerateSecureKey
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *   * DTV_STATUS_T HAL_CRYPTO_NYX_AES_CryptCBC(unsigned char *pSecureKey, int keyLength, int bEncrypt,
 *                                              unsigned char *pSrc, int srcLength, unsigned char *pDst, int *pDstLength);
 *
 *   For the data type, following data types are defined
 *
 *   * pSecureKey   [in]    buffer of secured key data which is maded by HAL_CRYPTO_NYX_AES_GenerateSecureKey
 *   * keyLength    [in]    aes key size (16 or 32)
 *   * bEncrypt     [in]    encrypt:1 / decrypt:0
 *   * pSrc         [in]    buffer for data to be encrypted
 *   * srcLength    [in]    sizeof pSrc
 *   * pDst         [out]   buffer for encrypted data
 *   * pDstLength   [out]   sizeof pDst
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != CRYPTO_NYX_AES_CryptCBC(key, keyLen, 1, pOriginalData, originalSize, pEncryptResult, &encrpytedLen);
 *         // handling error
 *     }
 *     if (0 != CRYPTO_NYX_AES_CryptCBC(key, keyLen, 0, pEncryptResult, encrpytedLen, pDecryptResult, &decrpytedLen);
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_CRYPTO_NYX_AES_CryptCBC(unsigned char *pSecureKey, int keyLength, int bEncrypt,
    unsigned char *pSrc, int srcLength, unsigned char *pDst, int *pDstLength);

/**
 * @brief Transform secure data from RSA key
 *
 * @rst
 * Functional Requirements
 *   Transform secure data from RSA key. Input RSA key data should be encrypted in TEE with DUK
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *   * DTV_STATUS_T HAL_CRYPTO_NYX_RSA_TransformSecureKey(unsigned char *pSecureKey, int *pKeyLength,
 *                                                        unsigned char *pRSAKey, int rsaKeyLength);
 *
 *   For the data type, following data types are defined
 *
 *   * pSecureKey     [out]   buffer for encrypted RSA Key in TEE by DUK
 *   * pKeyLength     [out]   sizeof pSecureKey
 *   * pRSAKey        [in]    generated private key and it is encoded to PKCS#1
 *   * rsaKeyLength   [in]    sizeof pRSAKey
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     RSA *rsa = RSA_new();
 *     BIGNUM *bn = BN_new();
 *     BN_set_word(bn, RSA_F4);
 *     RSA_generate_key_ex(rsa, keylen, bn, NULL);
 *     BIO *privKeyBio = NULL;
 *     privKeyBio = BIO_new(BIO_s_mem());
 *     i2d_RSAPrivateKey_bio(privKeyBio, rsa);
 *     unsigned char *privKeyBuf = NULL;
 *     BIO_get_mem_data(privKeyBio, &privKeyBuf);
 *
 *     if (0 != HAL_CRYPTO_NYX_RSA_TransformSecureKey(pSecureKey, &keyLength, privKeyBuf, sizeof(privKeyBuf)))
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_CRYPTO_NYX_RSA_TransformSecureKey(unsigned char *pSecureKey, int *pKeyLength,
    unsigned char *pRSAKey, int rsaKeyLength);

/**
 * @brief Perform TEE RSA encryption or decryption
 *
 * @rst
 * Functional Requirements
 *   Perform TEE RSA encryption or decryption
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *   * DTV_STATUS_T HAL_CRYPTO_NYX_RSA_Crypt(unsigned char *pSecureKey, int keyLength, int bEncrypt,
 *                                           unsigned char *pSrc, int srcLength, unsigned char *pDst, int *pDstLength);
 *
 *   For the data type, following data types are defined
 *
 *   * pSecureKey           [in]    secureData of RSA key which is made by HAL_CRYPTO_NYX_RSA_TransformSecureKey
 *   * keyLength            [in]    sizeof pSecureKey
 *   * bEncrypt             [in]    encryption:1 / decryption:0
 *   * pSrc                 [in]    buffer for data to be encrypted/decrypted
 *   * srcLength            [in]    sizeof pSrc
 *   * pDst                 [out]   buffer for encrypted/decrypted data
 *   * pDstLength           [out]   sizeof pDst
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_CRYPTO_NYX_RSA_Crypt(pSecureKey, keyLength, 1, pSrc, srcLength, pEncrypted, &encryptedLength))
 *         // handling error
 *     }
 *     if (0 != HAL_CRYPTO_NYX_RSA_Crypt(pSecureKey, keyLength, 0, pEncrypted, encryptedLength, pDecrypted, &decryptedLength))
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_CRYPTO_NYX_RSA_Crypt(unsigned char *pSecureKey, int keyLength, int bEncrypt,
    unsigned char *pSrc, int srcLength, unsigned char *pDst, int *pDstLength);
/**
 * @brief Transform secure data from RSA key
 *
 * @rst
 * Functional Requirements
 *   Transform secure data from RSA key. Input RSA key data should be encrypted in TEE with DUK
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *   * DTV_STATUS_T HAL_CRYPTO_NYX_RSA_ExportPublicKey(unsigned char *pPublicKey, int *pPublicKeyLength,
 *                                                     unsigned char *pSecureKey, int keyLength);
 *
 *   For the data type, following data types are defined
 *
 *   * pPublicKey           [out]   buffer for public key
 *   * pPublicKeyLength     [out]   sizeof pPublicKey
 *   * pSecureKey           [in]    buffer of encrypted RSA key which is made by HAL_CRYPTO_NYX_RSA_TransformSecureKey
 *   * keyLength            [in]    sizeof pSecureKey
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_CRYPTO_NYX_RSA_ExportPublicKey(pPublicKey, &publicKeyLength, pSecureKey, keyLength))
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_CRYPTO_NYX_RSA_ExportPublicKey(unsigned char *pPublicKey, int *pPublicKeyLength,
    unsigned char *pSecureKey, int keyLength);

/* Debug Menu API (debug - g2 ) */
DTV_STATUS_T HAL_CRYPTO_Debug(void);

/* Secure Firmware Update */
DTV_STATUS_T HAL_CRYPTO_SFU_Initialize(void);
DTV_STATUS_T HAL_CRYPTO_SFU_Finalize(void);
DTV_STATUS_T HAL_CRYPTO_SFU_GetRSAKey(UINT8 *pRsaKey);
DTV_STATUS_T HAL_CRYPTO_SFU_GetAESKey(UINT8 *pAesKey);

/* Read/Write Secret keys */
DTV_STATUS_T HAL_CRYPTO_ReadMskToSecureStore(UINT8 *pData, int *pLength);
DTV_STATUS_T HAL_CRYPTO_WriteMskToSecureStore(UINT8 *pData, int length);
DTV_STATUS_T HAL_CRYPTO_ReadNLPSecret(UINT8 *pSecret, char *pSecretID);
DTV_STATUS_T HAL_CRYPTO_BBC_ReadClientKey(UINT8 *pKey);
DTV_STATUS_T HAL_CRYPTO_ReadPrsSecret(UINT8 *pSecret);

 /**
 * @brief Get the ci_ssl_pub_key data from sestore (for tvserivce before webOS5.0)
 *
 * @rst
 * Functional Requirements
 *   Get the ci_ssl_pub_key data from sestore
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *   * DTV_STATUS_T HAL_CRYPTO_CIPLUS_GetCiPlusSslPubKey(UINT8 *pPath, UINT8 *dKey)
 *
 *   For the data type, following data types are defined
 *
 *   * pPath                [in]    Not used
 *   * pKey                 [out]    ci_ssl_pub_key key data
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     UINT8 buffer[272];
 *     DTV_STATUS_T ret;
 *     ret = HAL_CRYPTO_CIPLUS_GetCiPlusSslPubKey("not used", buffer);
 * @endrst
 */
DTV_STATUS_T HAL_CRYPTO_CIPLUS_GetCiPlusSslPubKey(UINT8 *pPath, UINT8 *dKey);


/**
* @brief Get the ci_ssl_pub_key data from sestore
*
* @rst
* Functional Requirements
*   Get the ci_ssl_pub_key data from sestore
*   ci_ssl_pub_key → scrambled ID: 13E46CF3, size: 272 byte
*
* Responses to abnormal situations, including
*   In abnormal case, the BSP should return an non-Zero.
*
* Performance Requirements
*   There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*   There is no constraints.
*
* Functions & Parameters
*   * DTV_STATUS_T HAL_CRYPTO_CI_PLUS_GetCiPlusSslPubKey(UINT8 *dKey)
*
*   For the data type, following data types are defined
*
*   * pKey               [out]    13E46CF3 (ci_ssl_pub_key)
*
* Return Value
*   Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*   .. code-block:: cpp
*
*     UINT8 buffer[272];
*     DTV_STATUS_T ret;
*     ret = HAL_CRYPTO_CI_PLUS_GetCiPlusSslPubKey(buffer);
* @endrst
*/
DTV_STATUS_T HAL_CRYPTO_CI_PLUS_GetCiPlusSslPubKey(UINT8 *dKey);

/**
* @brief Get the ci_key data from sestore
*
* @rst
* Functional Requirements
*   Get the ci_key data from sestore
*   ci_key → scrambled ID: 34E26C55, size: 16 byte
*
* Responses to abnormal situations, including
*   In abnormal case, the BSP should return an non-Zero.
*
* Performance Requirements
*   There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*   There is no constraints.
*
* Functions & Parameters
*   * DTV_STATUS_T HAL_CRYPTO_CI_PLUS_GetCiPlusStdKey(UINT8 *dKey)
*
*   For the data type, following data types are defined
*
*   * pKey               [out]    34E26C55 (ci_key)
*
* Return Value
*   Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*   .. code-block:: cpp
*
*     UINT8 buffer[16];
*     DTV_STATUS_T ret;
*     ret = HAL_CRYPTO_CI_PLUS_GetCiPlusStdKey(buffer);
* @endrst
*/
DTV_STATUS_T HAL_CRYPTO_CI_PLUS_GetCiPlusStdKey(UINT8 *dKey);

/**
* @brief Get the ci_dh_key data from sestore
*
* @rst
* Functional Requirements
*   Get the ci_dh_key data from sestore
*   ci_dh_key → scrambled ID: 38195B00, size: 609 byte
*
* Responses to abnormal situations, including
*   In abnormal case, the BSP should return an non-Zero.
*
* Performance Requirements
*   There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*   There is no constraints.
*
* Functions & Parameters
*   * DTV_STATUS_T HAL_CRYPTO_CI_PLUS_GetCiPlusDhKey(UINT8 *dKey)
*
*   For the data type, following data types are defined
*
*   * pKey               [out]    38195B00 (ci_dh_key)
*
* Return Value
*   Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*   .. code-block:: cpp
*
*     UINT8 buffer[609];
*     DTV_STATUS_T ret;
*     ret = HAL_CRYPTO_CI_PLUS_GetCiPlusDhKey(buffer);
* @endrst
*/
DTV_STATUS_T HAL_CRYPTO_CI_PLUS_GetCiPlusDhKey(UINT8 *dKey);

DTV_STATUS_T HAL_CRYPTO_GetDebugKey(UINT8 *pKey);
/**
* @brief Get the dvr secret key from secure storage
*
* @rst
* Functional Requirements
*	Get the dvr secret key from secure storage.
*
* Responses to abnormal situations, including
*	In abnormal case, the BSP should return an non-Zero.
*
* Performance Requirements
*	There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*	There is no constraints.
*
* Functions & Parameters
*	* DTV_STATUS_T HAL_CRYPTO_ReadDVRDeviceSecret(UINT8 *pSecret)
*
*	For the data type, following data types are defined
*
*	* pSecret	[out]	dvr secret key data
*
* Return Value
*	Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*	.. code-block:: cpp
*
*	  UINT8 wrappingKey[24];
*	  DTV_STATUS_T ret;
*	  ret = HAL_CRYPTO_ReadDVRDeviceSecret(wrappingKey);
* @endrst
*/
DTV_STATUS_T HAL_CRYPTO_ReadDVRDeviceSecret(UINT8 *pSecret);
/**
* @brief Write the dvr secret key to secure storage
*
* @rst
* Functional Requirements
*	Write the dvr secret key to secure storage
*
* Responses to abnormal situations, including
*	In abnormal case, the BSP should return an non-Zero.
*
* Performance Requirements
*	There is no clear requirement for response time, but a response must be received within at least 300 ms.
*
* Constraints
*	There is no constraints.
*
* Functions & Parameters
*	* DTV_STATUS_T HAL_CRYPTO_WriteDVRDeviceSecret(UINT8 *pSecret, int length)
*
*	For the data type, following data types are defined
*
*	* pSecret	[in]	dvr secret key data
*	 length		[in]	size of dvr secret key
*
* Return Value
*	Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*	.. code-block:: cpp
*
*	  UINT8 wrappingKey[24];
*	  DTV_STATUS_T ret;
*	  // Make wrappingKey with AES_wrap_key
*
*	  if (0 != HAL_CRYPTO_WriteDVRDeviceSecret(wrappingKey, 24))
*	    // handling error
*	  }
* @endrst
*/
DTV_STATUS_T HAL_CRYPTO_WriteDVRDeviceSecret(UINT8 *pSecret, int length);
DTV_STATUS_T HAL_CRYPTO_TNM_ReadSecretKey(UINT8 *pSecret);
DTV_STATUS_T HAL_CRYPTO_TNM_WriteSecretKey(UINT8 *pSecret, int length);
DTV_STATUS_T HAL_CRYPTO_HYBRIDCAST_ReadSecret(UINT8 *pSecret);
DTV_STATUS_T HAL_CRYPTO_CIPLUS_GetCiCanalReadyKey(UINT8 *pPath, UINT8 *pKey);
DTV_STATUS_T HAL_CRYPTO_Multiple_ReadClientKey(UINT8 *pKey);
DTV_STATUS_T HAL_CRYPTO_ReadSkypeSecret(UINT8 *pSecret, int *pLength);
DTV_STATUS_T HAL_CRYPTO_ReadRemoteDiagSecret(UINT8 *pSecret, int *pLength);
DTV_STATUS_T HAL_CRYPTO_SDI_ReadPrivKeyAndID(UINT8 *pPrivKeyBuf, int *pPrivKeySize, UINT8 *pIdBuf, int *pIdLength);
DTV_STATUS_T HAL_CRYPTO_ReadRDXSecret(UINT8 *pSecret, int *pLength);
DTV_STATUS_T HAL_CRYPTO_SDP_ReadCommonKey(UINT8 *pKey, int *pLength);
DTV_STATUS_T HAL_CRYPTO_TWINTV_ReadSecret(UINT8 *pSecret, int *pLength);
/**
* @brief Read the freeview private key for certification
*
* @rst
* Functional Requirements
*	Read the freeview private key for certification
*
* Responses to abnormal situations, including
*	In abnormal case, the BSP should return an non-Zero.
*
* Performance Requirements
*	There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*	There is no constraints.
*
* Functions & Parameters
*	* DTV_STATUS_T HAL_CRYPTO_ReadFreeViewPrivateKey(unsigned char *pKeyBuf, int *pSize)
*
*	For the data type, following data types are defined
*
*	* pKeyBuf	[in]	freeview play private key buffer
*	 pSize		[in]	size of freeview play private key
*
* Return Value
*	Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*	.. code-block:: cpp
*
*	  unsigned char *keyBuf[24];
*
*	  if (0 != HAL_CRYPTO_ReadFreeViewPrivateKey(keyBuf, 24))
* @endrst
*/
DTV_STATUS_T HAL_CRYPTO_ReadFreeViewPrivateKey(unsigned char *pKeyBuf, int *pSize);

/**
* @brief Read Secure Data from Secure Store for Amazon
*
* @rst
* Functional Requirements
*	Read Secure Data from Secure Store for Amazon
*
* Responses to abnormal situations, including
*	In abnormal case, the BSP should return an non-Zero.
*
* Performance Requirements
*	There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*	There is no constraints.
*
* Functions & Parameters
*	* DTV_STATUS_T HAL_CRYPTO_ReadMVPDSecret(char *pPath, UINT8 *pData)
*
*	For the data type, following data types are defined
*
*	* pPath     [in]    Path to read secure data.
*	* pData     [out]   Secure Data.
*
* Return Value
*	Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*	.. code-block:: cpp
*
*	  UINT8 *encodedCipher=NULL;
*	  char *pPath=NULL;
*	  DTV_STATUS_T ret;
*	  ret = HAL_CRYPTO_ReadMVPDSecret(pPath, encodedCipher);
* @endrst
*/
DTV_STATUS_T HAL_CRYPTO_ReadMVPDSecret(char *pPath, UINT8 *pData);
/**
* @brief Write Secure Data into Secure Store for Amazon
*
* @rst
* Functional Requirements
*	Write Secure Data into Secure Store for Amazon
*
* Responses to abnormal situations, including
*	In abnormal case, the BSP should return an non-Zero.
*
* Performance Requirements
*	There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*	There is no constraints.
*
* Functions & Parameters
*	* DTV_STATUS_T HAL_CRYPTO_WriteMVPDSecret(char *pPath, UINT8 *pData, int length)
*
*	For the data type, following data types are defined
*
*	* pPath     [in]    Path to write secure data.
*	* pData     [in]    Secure Data.
*	* length    [in]    Data Length.
*
* Return Value
*	Zero(0) if the function success, non-Zero otherwise or Common Error Code.
*
* Example
*	.. code-block:: cpp
*
*	  UINT8 *encodedCipher=NULL;
*	  char *pPath=NULL;
*	  int encodedCipherLen=0;
*	  DTV_STATUS_T ret;
*	  ret = HAL_CRYPTO_WriteMVPDSecret(pPath, encodedCipher, encodedCipherLen);
* @endrst
*/
DTV_STATUS_T HAL_CRYPTO_WriteMVPDSecret(char *pPath, UINT8 *pData, int length);

/*
    NOTE:
        CRYPTO_HDCP_T type is not used for extern APIs,
        therefore it has to be included in hal_crypto source code.
        typedef enum {
            CRYPTO_HDCP_14,  //HDCP 1.4
            CRYPTO_HDCP_22,  //HDCP 2.2
            CRYPTO_HDCP_MAX,
        } CRYPTO_HDCP_T;    // For HAL_CRYPTO_WriteHDCPOnSecure()/HAL_CRYPTO_ReadHDCPFromSecure()
*/
DTV_STATUS_T HAL_CRYPTO_WriteHDCPOnSecure(unsigned int hdcpType, unsigned char *pHDCPKey, unsigned int hdcpSize);
DTV_STATUS_T HAL_CRYPTO_ReadHDCPFromSecure(unsigned int hdcpType, unsigned char *pHDCPKey, unsigned int *pHDCPSize);

/**
 * @brief Perform TEE AES encryption
 *
 * @rst
 * Functional Requirements
 *   Perform TEE AES encryption. 128 and 256 bits key size should be supported, and PKCS#5 padding should be used.
 *   The pKey is a SecureData which is made by HAL_SSTR_MakeSecureData.
 *   ECB and CBC mode should be supported. The mode of operation is specified by the parameter.
 *   pszMode of which the type is char pointer type string. "ECB" or "CBC" can be passed.
 *   When using CBC, IV value should be generated randomly in TEE and attached in front of the
 *   encrypted result buffer. For decryption, the IV is retrieved from the source buffer (16bytes
 *   in front of the encrypted data).
 *
 * Responses to abnormal situations, including
 *   If SecureData is invalid, return error (non-Zero or Error Code).
 *
 * Performance Requirements
 *   There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *   * HAL_SSTR_R_T HAL_CRYPTO_AES_Encrypt(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData, char *pszMode, UINT8 *pKey, UINT32 nKeySize)
 *
 *   For the data type, following data types are defined
 *
 *   * nSrcLen     [in]    size of pSrcData
 *   * pSrcData    [in]    buffer for data to be encrypted
 *   * pDstLen     [out]   sizeof pDstData
 *   * pDstData    [out]   buffer to store SecureData
 *   * pszMode     [in]    Block cipher Mode ("ECB" / "CBC")
 *   * pKey        [in]    SecureData of cipher key
 *   * nKeySize    [in]    Size of pKey data
 *
 *   ============ ========== =============================================
 *   PARAMETER    DATE TYPE  DESCRIPTION
 *   ============ ========== =============================================
 *   pszMode      Plaintext  "ECB" or "CBC"
 *   pKey         SecureData SecureData which is made by HAL_SSTR_MakeSecureData
 *   ============ ========== =============================================
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     // nSrcLen = 16;
 *     UINT32 dstLen = 16; // (data size 16)
 *     UINT8 *pDstData = (UINT8 *)malloc (dstLen);
 *     if (0 != HAL_CRYPTO_AES_Encrypt(nSrcLen, pSrcData, &pDstLen,
 *                                    pDstData, "ECB", pKey, nKeySize)) {
 *         // handling error
 *     }
 *     dstLen = 32; // (iv size 16 + data size 16)
 *     pDstData = (UINT8 *)malloc (dstLen);
 *     if (0 != HAL_CRYPTO_AES_Encrypt(nSrcLen, pSrcData, &pDstLen,
 *                                    pDstData, "CBC", pKey, nKeySize)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_CRYPTO_AES_Encrypt (UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                                    UINT8 *pDstData, char *pszMode, UINT8 *pKey, UINT32 nKeySize);

/**
 * @brief Perform TEE AES decryption.
 *
 * @rst
 * Functional Requirements
 *   Perform TEE AES decryption.. 128 and 256 bits key size should be supported, and PKCS#5 padding should be used.
 *   The pKey is a SecureData which is made by HAL_SSTR_MakeSecureData.
 *   ECB and CBC mode should be supported. The mode of operation is specified by the parameter.
 *   pszMode of which the type is char pointer type string. "ECB" or "CBC" can be passed.
 *   When using CBC, IV value should be generated randomly in TEE and attached in front of the
 *   encrypted result buffer. For decryption, the IV is retrieved from the source buffer (16bytes
 *   in front of the encrypted data).
 *
 * Responses to abnormal situations, including
 *   If SecureData is invalid, return error (non-Zero or Error Code).
 *
 * Performance Requirements
 *   There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *   * HAL_SSTR_R_T HAL_CRYPTO_AES_Decrypt(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData, char *pszMode, UINT8 *pKey, UINT32 nKeySize)
 *
 *   For the data type, following data types are defined
 *
 *   * nSrcLen     [in]    size of pSrcData
 *   * pSrcData    [in]    buffer for data to be encrypted
 *   * pDstLen     [out]   sizeof pDstData
 *   * pDstData    [out]   buffer to store SecureData
 *   * pszMode     [in]    Block cipher Mode ("ECB" / "CBC")
 *   * pKey        [in]    SecureData of cipher key
 *   * nKeySize    [in]    Size of pKey data
 *
 *   ============ ========== =============================================
 *   PARAMETER    DATE TYPE  DESCRIPTION
 *   ============ ========== =============================================
 *   pSrcData     data       encrypted data by HAL_CRYPTO_AES_Encrypt. If mode is "CBC", data includes IV value (16 bytes in formt of data)
 *   pszMode      Plaintext  "ECB" or "CBC"
 *   pKey         SecureData SecureData which is made by HAL_SSTR_MakeSecureData
 *   ============ ========== =============================================
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     // nSrcLen = 16;
 *     UINT32 dstLen = 16; // (original data size 16)
 *     UINT8 *pDstData = (UINT8 *)malloc (dstLen);
 *     if (0 != HAL_CRYPTO_AES_Decrypt(nSrcLen, pSrcData, &pDstLen,
 *                                    pDstData, "ECB", pKey, nKeySize)) {
 *         // handling error
 *     }
 *     // nSrcLen = 32; // (iv size 16 + data size 16)
 *     dstLen = 16; // (original data size 16)
 *     if (0 != HAL_CRYPTO_AES_Decrypt(nSrcLen, pSrcData, &pDstLen,
 *                                    pDstData, "CBC", pKey, nKeySize)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_CRYPTO_AES_Decrypt (UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                                    UINT8 *pDstData, char *pszMode, UINT8 *pKey, UINT32 nKeySize);

/*
 * RSA Padding Type
 */
typedef enum {
    HAL_CRYPTO_RSA_NO_PADDING,
    HAL_CRYPTO_RSA_PKCS1_OAEP_PADDING
} HAL_CRYPTO_RSA_PADDING_T;
/**
 * @brief Perform TEE RSA encryption.
 *
 * @rst
 * Functional Requirements
 *   The passed pKey is a type of SecureData, and original key is has a format of PKCS#1 and
 *   encoded by either DER or PEM. So, the encoding type should be passed via the parameter
 *   pszKeyType.
 *
 * Responses to abnormal situations, including
 *   If SecureData of cipher key is invalid, return error (non-Zero or Error Code).
 *
 * Performance Requirements
 *   There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *   nSrcLen should be less than ((key size / 8) - 41). key size is 2048 or 1024.
 *
 * Functions & Parameters
 *   * HAL_SSTR_R_T HAL_CRYPTO_RSA_Encrypt (UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData, HAL_CRYPTO_RSA_PADDING_T padding, char *pszKeyType, UINT8 *pKey, UINT32 nKeySize)
 *
 *   For the data type, following data types are defined
 *
 *   * nSrcLen     [in]    Size of data to be encrypted
 *   * pSrcData    [in]    Buffer for data to be encrypted
 *   * pDstLen     [out]   Size of output data (the result of encryption)
 *   * pDstData    [out]   Buffer for output data (the result of encryption)
 *   * padding     [in]    Padding Type (RSA_NO_PADDING or PKCS1_OAEP_PADDING)
 *   * pszKeyType  [in]    Key Encoding Type. ("PEM" or "DER")
 *   * pKey        [in]    SecureData of cipher key
 *   * nKeySize    [in]    Size of pKey data
 *
 *   ============ ========== =============================================
 *   PARAMETER    DATE TYPE  DESCRIPTION
 *   ============ ========== =============================================
 *   padding      data       HAL_CRYPTO_RSA_NO_PADDING=0, HAL_CRYPTO_RSA_PKCS1_OAEP_PADDING=1
 *   pszKeyType   Plaintext  "PEM" or "DER"
 *   pKey         SecureData SecureData of cipher key which is made by HAL_SSTR_MakeSecureData
 *   ============ ========== =============================================
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     UINT32 dstLen = 256;
 *     UINT8 *pDstData = (UINT8 *)malloc (dstLen);
 *     if (0 != HAL_CRYPTO_RSA_Encrypt(nSrcLen, pSrcData, &pDstLen,
 *                                    pDstData, PKCS1_OAEP_PADDING, "PEM", pKey, nKeySize)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_CRYPTO_RSA_Encrypt (UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                                     UINT8 *pDstData, HAL_CRYPTO_RSA_PADDING_T padding,
                                     char *pszKeyType, UINT8 *pKey, UINT32 nKeySize);

/**
 * @brief Perform TEE RSA decryption.
 *
 * @rst
 * Functional Requirements
 *   The passed pKey is a type of SecureData, and original key is has a format of PKCS#1 and
 *   encoded by either DER or PEM. So, the encoding type should be passed via the parameter
 *   pszKeyType.
 *
 * Responses to abnormal situations, including
 *   If SecureData of cipher key is invalid, return error (non-Zero or Error Code).
 *
 * Performance Requirements
 *   There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *   pSrcData should be data which is made by HAL_CRYPTO_RSA_Encrypt before.
 *
 * Functions & Parameters
 *   * HAL_SSTR_R_T HAL_CRYPTO_RSA_Decrypt (UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData, HAL_CRYPTO_RSA_PADDING_T padding, char *pszKeyType, UINT8 *pKey, UINT32 nKeySize)
 *
 *   For the data type, following data types are defined
 *
 *   * nSrcLen     [in]    Size of data to be encrypted
 *   * pSrcData    [in]    Buffer for data to be encrypted
 *   * pDstLen     [out]   Size of output data (the result of encryption)
 *   * pDstData    [out]   Buffer for output data (the result of encryption)
 *   * padding     [in]    Padding Type (RSA_NO_PADDING or PKCS1_OAEP_PADDING)
 *   * pszKeyType  [in]    Key Encoding Type. ("PEM" or "DER")
 *   * pKey        [in]    SecureData of cipher key
 *   * nKeySize    [in]    Size of pKey data
 *
 *   ============ ========== =============================================
 *   PARAMETER    DATE TYPE  DESCRIPTION
 *   ============ ========== =============================================
 *   pSrcData     data   	 Encrypted data by HAL_CRYPTO_RSA_Encrypt
 *   padding      data       HAL_CRYPTO_RSA_NO_PADDING=0, HAL_CRYPTO_RSA_PKCS1_OAEP_PADDING=1
 *   pszKeyType   Plaintext  "PEM" or "DER"
 *   pKey         SecureData SecureData of cipher key which is made by HAL_SSTR_MakeSecureData
 *   ============ ========== =============================================
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     UINT32 dstLen = 256;
 *     UINT8 *pDstData = (UINT8 *)malloc (dstLen);
 *     if (0 != HAL_CRYPTO_RSA_Decrypt(nSrcLen, pSrcData, &pDstLen,
 *                                    pDstData, PKCS1_OAEP_PADDING, "PEM", pKey, nKeySize)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_CRYPTO_RSA_Decrypt (UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                                     UINT8 *pDstData, HAL_CRYPTO_RSA_PADDING_T padding,
                                     char *pszKeyType, UINT8 *pKey, UINT32 nKeySize);

/**
 * @brief Perform RSA Signing in TEE.
 *
 * @rst
 * Functional Requirements
 *   Signing message encoding scheme is "SHA256 / EMSA-PKCS1-v1_5 Encoding"
 *   pKey is a SecureData type and its original key data is PKCS#1 format that is encoded by DER or PEM.
 *
 * Responses to abnormal situations, including
 *   If SecureData of cipher key is invalid, return error (non-Zero or Error Code).
 *
 * Performance Requirements
 *   There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *   * HAL_SSTR_R_T HAL_CRYPTO_RSA_Sign (UINT32 nDataSize, UINT8 *pData, UINT32 *pSigLen, UINT8 *pSig, char *pszKeyType, UINT8 *pKey, UINT32 nKeyLen)
 *
 *   For the data type, following data types are defined
 *
 *   * nDataSize     [in]    Size of data to be signed
 *   * pData         [in]    Data to be signed
 *   * pSigLen       [out]   Size of signature (pSig)
 *   * pSig          [out]   Signature data
 *   * pszKeyType    [in]    Key Encoding Type. ("PEM" or "DER")
 *   * pKey          [in]    SecureData of cipher key
 *   * nKeyLen       [in]    Size of pKey data
 *
 *   ============ ========== =============================================
 *   PARAMETER    DATE TYPE  DESCRIPTION
 *   ============ ========== =============================================
 *   pszKeyType   Plaintext  "PEM" or "DER"
 *   pKey         SecureData SecureData of cipher key which is made by HAL_SSTR_MakeSecureData
 *   ============ ========== =============================================
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     UINT32 dstLen = 256;
 *     UINT8 *pDstData = (UINT8 *)malloc (dstLen);
 *     if (0 != HAL_CRYPTO_RSA_Sign(nDataSize, pData, &pSigLen,
 *                                    pSig, "PEM", pKey, nKeyLen)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_CRYPTO_RSA_Sign (UINT32 nDataSize, UINT8 *pData, UINT32 *pSigLen, UINT8 *pSig,
                                  char *pszKeyType, UINT8 *pKey, UINT32 nKeyLen);

/**
 * @brief Perform RSA signature verification in TEE
 *
 * @rst
 * Functional Requirements
 *   Signing message encoding scheme is "SHA256 / EMSA-PKCS1-v1_5 Encoding"
 *   pKey is a SecureData type and its original key data is PKCS#1 format that is encoded by DER or PEM.
 *
 * Responses to abnormal situations, including
 *   If SecureData of cipher key is invalid, return error (non-Zero or Error Code).
 *
 * Performance Requirements
 *   There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *   * HAL_SSTR_R_T HAL_CRYPTO_RSA_Verify (UINT32 nDataSize, UINT8 *pData, UINT32 nSigLen, UINT8 *pSig, char *pszKeyType, UINT8 *pKey, UINT32 nKeyLen)
 *
 *   For the data type, following data types are defined
 *
 *   * nDataSize     [in]    Size of data to be signed
 *   * pData         [in]    Data to be signed
 *   * nSigLen       [in]    Size of signature (pSig)
 *   * pSig          [in]    Signature data
 *   * pszKeyType    [in]    Key Encoding Type. ("PEM" or "DER")
 *   * pKey          [in]    SecureData of cipher key
 *   * nKeyLen       [in]    Size of pKey data
 *
 *   ============ ========== =============================================
 *   PARAMETER    DATE TYPE  DESCRIPTION
 *   ============ ========== =============================================
 *   pszKeyType   Plaintext  "PEM" or "DER"
 *   pKey         SecureData SecureData of cipher key which is made by HAL_SSTR_MakeSecureData
 *   ============ ========== =============================================
 *
 * Return Value
 *   Zero(0) if the signature verifcation is success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     UINT32 dstLen = 256;
 *     UINT8 *pDstData = (UINT8 *)malloc (dstLen);
 *     if (0 != HAL_CRYPTO_RSA_Verify(nDataSize, pData, nSigLen,
 *                                    pSig, "PEM", pKey, nKeyLen)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_CRYPTO_RSA_Verify (UINT32 nDataSize, UINT8 *pData, UINT32 nSigLen, UINT8 *pSig,
                                    char *pszKeyType, UINT8 *pKey, UINT32 nKeySize);

/**
 * @brief Perform encryption with a randomly generated encryption key on TEE for each device.
 *
 * @rst
 * Functional Requirements
 *   Input data should be encrypted with AES-ECB. And key size should be 16 bytes or 32 bytes.
 *
 * Responses to abnormal situations, including
 *   If error is occured, return error (non-Zero or Error Code).
 *
 * Performance Requirements
 *   There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *   Input data's size should be 32 bytes. And also output data's size should be 32 bytes.
 *
 * Functions & Parameters
 *   * HAL_SSTR_R_T HAL_CRYPTO_EncryptDbgData (UINT8 *pInData, int nInL, UINT8 *pOutData, int *pOutL)
 *
 *   For the data type, following data types are defined
 *
 *   * pInData        [in]    Data to be encrypted
 *   * nInL           [in]    Size of data to be encrypted
 *   * pOutData       [out]   Encrypted data
 *   * pOutL          [out]   Size of Encrypted data
 *
 * Return Value
 *   Zero(0) if encryption is success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     int pOutL = 32;
 *     UINT8 *outData = (UINT8 *)malloc(pOutL);
 *     if (0 != HAL_CRYPTO_EncryptDbgData(pInData, nInL, outData, &pOutL)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_CRYPTO_EncryptDbgData (UINT8 *pInData, int nInL, UINT8 *pOutData, int *pOutL);

/**
 * @brief Perform decryption with a randomly generated encryption key on TEE for each device.
 *
 * @rst
 * Functional Requirements
 *   Input data should be decrypted with AES-ECB. And key size should be 16 bytes or 32 bytes.
 *
 * Responses to abnormal situations, including
 *   If error is occured, return error (non-Zero or Error Code).
 *
 * Performance Requirements
 *   There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *   Input data's size should be 32 bytes. And also output data's size should be 32 bytes.
 *
 * Functions & Parameters
 *   * HAL_SSTR_R_T HAL_CRYPTO_EncryptDbgData (UINT8 *pInData, int nInL, UINT8 *pOutData, int *pOutL)
 *
 *   For the data type, following data types are defined
 *
 *   * pInData        [in]    Data to be decrypted
 *   * nInL           [in]    Size of data to be decrypted
 *   * pOutData       [out]   Decrypted data
 *   * pOutL          [out]   Size of decrypted data
 *
 * Return Value
 *   Zero(0) if decryption is success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     int pOutL = 32;
 *     UINT8 *outData = (UINT8 *)malloc(pOutL);
 *     if (0 != HAL_CRYPTO_EncryptDbgData(pInData, nInL, outData, &pOutL)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_CRYPTO_DecryptDbgData (UINT8 *pInData, int nInL, UINT8 *pOutData, int *pOutL);

#endif      //_HAL_CRYPTO_H_

