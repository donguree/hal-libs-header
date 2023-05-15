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
/******************************************************************************
Function Name
    HAL_CRYPTO_WriteSecureData

Function Description
    write Netflix ESN(ESN ID + Kpe + Kph) into secure storage for provisioning

Requirement
    1. check if identifier is "idfile". other id is on failure.
    2. verify CRC32 integrity
    3. decrypt input data and re-encrypt with device-unique key in TEE.
    4. store into sestore.
    5. the data(only ESN ID) should be read via HAL_CRYPTO_NF_GetESN().

Function Parameters
    INT8 *pIdentifier   [IN] identirier(only "idfile" is suitable)
    UINT8 *pData        [IN] ESN key data(ESN ID + Kpe + Kph)
    INT32 length        [IN] ESN key data length


Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_WriteSecureData(char *pIdentifier, UINT8 *pData, int dataLength);

/******************************************************************************
Function Name
    HAL_CRYPTO_NF_GetESN

Function Description
    get ESN

Function Parameters
    UINT8 *pEsn [IN/OUT] ESN buffer pointer / ESN ID

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_NF_GetESN(UINT8 *pEsn);

/******************************************************************************
Function Name
    HAL_CRYPTO_NF_Encrypt

Function Description
    encrypt data with device unique key

Function Parameters
    UINT8 *pData    [IN/OUT] data to be encrypted
    UINT32 length   [IN] data length

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_NF_Encrypt(UINT8 *pData, UINT32 nLength);

/******************************************************************************
Function Name
    HAL_CRYPTO_NF_Decrypt

Function Description
    decrypt data with device unique key

Function Parameters
    UINT8 *pData    [IN/OUT] encrypted data(via HAL_CRYPTO_NF_Encrypt) to be decrypted
    UINT32 length   [IN] data length

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_NF_Decrypt(UINT8 *pData, UINT32 nLength);

/******************************************************************************
Function Name
    HAL_CRYPTO_NF_Encrypt_Ex

Function Description
    encrypt data with device unique key and integrity check

Function Parameters
    const UINT8 *pInput     [IN] clear data
    UINT32 uInputSize       [IN] input data length
    UINT8 **ppOutput        [OUT] encrypted data with integrity check
    UINT32 *puOutputSize    [OUT] output data length

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_NF_Encrypt_Ex(const UINT8 *pInput, UINT32 uInputSize, UINT8 **ppOutput, UINT32 *puOutputSize );

/******************************************************************************
Function Name
    HAL_CRYPTO_NF_Decrypt_Ex

Function Description
    decrypt data with device unique key and integrity check

Function Parameters
    UINT8 *pInput           [IN] encrypted data(via HAL_CRYPTO_NF_Encrypt_Ex) with integrity check to be decrypted
    UINT32 uInputSize       [IN] input data length
    UINT8 **ppOutput        [OUTPUT] clear data
    UINT32 *puOutputSize    [OUTPUT] clear data length

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_NF_Decrypt_Ex(const UINT8 *pInput, UINT32 uInputSize, UINT8 **ppOutput, UINT32 *puOutputSize );

/******************************************************************************
Function Name
    HAL_CRYPTO_NF_WriteAppData

Function Description
    Write App Data to Secure Store

Function Parameters
    char *pDataId       [IN]            Data Identifier
    UINT8 *pData        [IN]            Data to be encrypted
    int length          [IN]            Data length

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_NF_WriteAppData(char *pDataId, UINT8 *pData, int length);

/******************************************************************************
Function Name
    HAL_CRYPTO_NF_ReadAppData

Function Description
    Read App Data to Secure Store.

Function Parameters
    char *pDataId       [IN]            Data Identifier
    UINT8 *pData        [IN/OUT]        Decrypted data
    int length          [IN]            Data length

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_NF_ReadAppData(char *pDataId, UINT8 *pData, int length);


/*  LG TEE Implementation        */
/******************************************************************************
Function Name
    HAL_CRYPTO_NF_Operate

Function Description
    Netflix crypto TEE operations(generate keys / encrypt / decrypt / HMAC)

Function Parameters
    pComm                [IN/OUT] crypto structure
    pComm->command       [IN]  crypto operations
    pComm->argc          [IN] : number of arguments
    pComm->argv[0]       [IN] : request data pointer
    pComm->argvLen[0]    [IN] : request data size
    pComm->argv[1]       [OUT] : response data pointer
    pComm->argvLen[1]    [OUT]  : response data size

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    typedef enum
    {
        nfTOB_UNDEFINED = 0,
        *
         * Some messages are for TEE (or VM) management. Those start at offset 0
         *
        nfTOB_TEE_MGMT = 1,
        *
         * We're not implementing REE/TEE session management in the first revision, but we'll
         * need it later, so let's allocate a slot for that.
         *
        nfTOB_TEE_SESSION = 2048,
        *
         * The first TA we'll implement is the crypto agent. This agent is used for all
         * webcrypto/msl operations, and also can provide secure store crypto services.
         *
        nfTOB_CRYPTO_AGENT = 4096,
        *
         * PlayReady integration is a stretch goal for the first revision, so let's
         * allocate a slot for it.
         *
        nfTOB_DRM_AGENT = 6144,
        *
         * The storage agent only manages the manufacturing secure store
         * in the first release.
         *
        nfTOB_STORAGE_AGENT = 8192,
    } nfTeeOperationBase_t;
    */
    /*
    * This will be passed as pComm->command of Crypto arguments.
    * Crypto operation definitions: all TEE operations are represented
    * as a 32-bit value. Each module (like cryptoAgent) has its own pool
    * of values that start at a pre-defined offset. These offsets are
    * defined in CommTypes.h. Following are the currently defined crypto
    * operations.

    typedef enum
    {
        nfTO_CRYPTO_OP_UNWRAP_KEY = nfTOB_CRYPTO_AGENT + 1,
        nfTO_CRYPTO_OP_EXPORT_SEALED_KEY,
        nfTO_CRYPTO_OP_IMPORT_SEALED_KEY,
        nfTO_CRYPTO_OP_DELETE_KEY,
        nfTO_CRYPTO_OP_GET_KEY_INFO,
        nfTO_CRYPTO_OP_GET_NAMED_KEY_HANDLE,
        nfTO_CRYPTO_OP_GET_ESN,
        nfTO_CRYPTO_OP_AES_CBC_ENCRYPT, // atomic encrypt
        nfTO_CRYPTO_OP_AES_CBC_ENCRYPT_INIT,
        nfTO_CRYPTO_OP_AES_CBC_ENCRYPT_UPDATE,
        nfTO_CRYPTO_OP_AES_CBC_ENCRYPT_FINAL,
        nfTO_CRYPTO_OP_AES_CBC_DECRYPT, // atomic decrypt
        nfTO_CRYPTO_OP_AES_CBC_DECRYPT_INIT,
        nfTO_CRYPTO_OP_AES_CBC_DECRYPT_UPDATE,
        nfTO_CRYPTO_OP_AES_CBC_DECRYPT_FINAL,
        nfTO_CRYPTO_OP_AES_CTR, // atomic encrypt
        nfTO_CRYPTO_OP_AES_CTR_INIT,
        nfTO_CRYPTO_OP_AES_CTR_UPDATE,
        nfTO_CRYPTO_OP_AES_CTR_FINAL,
        nfTO_CRYPTO_OP_EXPORT_KEY,
        nfTO_CRYPTO_OP_IMPORT_KEY,
        nfTO_CRYPTO_OP_HMAC_SHA256, // atomic hmac_sha256
        nfTO_CRYPTO_OP_HMAC_SHA256_INIT,
        nfTO_CRYPTO_OP_HMAC_SHA256_UPDATE,
        nfTO_CRYPTO_OP_HMAC_SHA256_FINAL,
        nfTO_CRYPTO_OP_HMAC_SHA256_VERIFY, // atomic hmac_sha256_verify
        nfTO_CRYPTO_OP_HMAC_SHA256_VERIFY_INIT,
        nfTO_CRYPTO_OP_HMAC_SHA256_VERIFY_UPDATE,
        nfTO_CRYPTO_OP_HMAC_SHA256_VERIFY_FINAL,
        nfTO_CRYPTO_OP_DH_GEN_KEYS,
        nfTO_CRYPTO_OP_NFLX_DH_DERIVE,
        nfTO_CRYPTO_OP_CLEARKEYS,
        // insert new message types here...
        nfTO_CRYPTO_OP_INVALID // leave this last!!
    } nfTeeOperation_CryptoOp_t;
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_NF_Operate(HAL_CRYPTO_ARG_T *tCommon);

/******************************************************************************
Function Name
    HAL_CRYPTO_NF_Init

Function Description
    Init Netflix Crypto
    Before using WebCrypto, Initialize something here. If there is nothing to initialize, please return OK

Function Parameters
    void

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    Some of platforms use this function.
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_NF_Init(void);

/******************************************************************************
Function Name
    HAL_CRYPTO_NF_CleanUp

Function Description
    To clean up Netflix webCrypto and SoC TEE operation

Function Parameters
    void

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    Some of platforms use this function.
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_NF_CleanUp(void);

/******************************************************************************
Function Name
    HAL_CRYPTO_NF_DestroyContext

Function Description
    Destroy context

Function Parameters
    void *pContext [IN]

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    Some of platforms use this function.
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_NF_DestroyContext(void *pContext);

/* NYX */
DTV_STATUS_T HAL_CRYPTO_NYX_AES_GenerateSecureKey(unsigned char *pSecureKey, int keyLength);
DTV_STATUS_T HAL_CRYPTO_NYX_AES_CryptCBC(unsigned char *pSecureKey, int keyLength, int bEncrypt,
    unsigned char *pSrc, int srcLength, unsigned char *pDst, int *pDstLength);
DTV_STATUS_T HAL_CRYPTO_NYX_RSA_TransformSecureKey(unsigned char *pSecureKey, int *pKeyLength,
    unsigned char *pRSAKey, int rsaKeyLength);
DTV_STATUS_T HAL_CRYPTO_NYX_RSA_Crypt(unsigned char *pSecureKey, int keyLength, int bEncrypt,
    unsigned char *pSrc, int srcLength, unsigned char *pDst, int *pDstLength);
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
 *  This API is needed for Legacy Tvservice, not SEETV
 *  This API will output the CI+ Public Key from sestore to the parameter
 *
 *  @param  pPath  [in]  pPath // it's not used
 *  @param  dKey  [out]  (ci_ssl_pub_key)
 *  @return succeeded - OK, if not - NOT_OK.
 */
DTV_STATUS_T HAL_CRYPTO_CIPLUS_GetCiPlusSslPubKey(UINT8 *pPath, UINT8 *dKey);

/**
 *  This API is needed for SEETV
 *  This API will output the CI+ Public Key from sestore to the parameter
 *
 *  @param  dKey  [out]  (ci_ssl_pub_key)
 *  @return succeeded - OK, if not - NOT_OK.
 */
DTV_STATUS_T HAL_CRYPTO_CI_PLUS_GetCiPlusSslPubKey(UINT8 *dKey);

/**
 *  This API is needed for SEETV
 *  This API will output the CI+ Master Key from sestore to the parameter
 *
 *  @param  dKey  [out]  (ci_key)
 *  @return succeeded - OK, if not - NOT_OK.
 */
DTV_STATUS_T HAL_CRYPTO_CI_PLUS_GetCiPlusStdKey(UINT8 *dKey);

/**
 *  This API is needed for SEETV
 *  This API will output the CI+ Credential Key from sestore to the parameter
 *
 *  @param  dKey  [out]  (ci_dh_key)
 *  @return succeeded - OK, if not - NOT_OK.
 */
DTV_STATUS_T HAL_CRYPTO_CI_PLUS_GetCiPlusDhKey(UINT8 *dKey);

DTV_STATUS_T HAL_CRYPTO_GetDebugKey(UINT8 *pKey);

DTV_STATUS_T HAL_CRYPTO_ReadDVRDeviceSecret(UINT8 *pSecret);
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
DTV_STATUS_T HAL_CRYPTO_ReadFreeViewPrivateKey(unsigned char *pKeyBuf, int *pSize);

DTV_STATUS_T HAL_CRYPTO_ReadMVPDSecret(char *pPath, UINT8 *pData);
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



/* webOS Secure Store Support APIs */
/**
 * Perform TEE AES encryption.
 * 128 and 256 bits key size should be supported, and PKCS#5 padding should be used.
 * The pKey is a SecureData.
 * ECB and CBC mode should be supported. The mode of operation is specified by the parameter
 * pszMode of which the type is char pointer type string. "ECB" or "CBC" can be passed.
 * When using CBC, IV value should be generated randomly in TEE and attached in front of the
 * encrypted result buffer. For decryption, the IV is retrieved from the source buffer (16bytes
 * in front of the encrypted data).
 *
 *  @param   nSrcLen    [IN]        Size of data to be encrypted
 *  @param   pSrcData   [IN]        Buffer for data to be encrypted
 *  @param   pDstLen    [OUT]       Size of output data (the result of encryption)
 *  @param   pDstData   [OUT]       Buffer for output data (the result of encryption)
 *  @param   pszMode    [IN]        Block cipher Mode ("ECB" / "CBC")
 *  @param   pKey       [IN]        SecureData of cipher key
 *  @param   nKeySize   [IN]        Size of pKey data
 *  @return  If the function succeeds, the return value is OK.
 *           If the function fails, the return value is NOT_OK.
 */
DTV_STATUS_T HAL_CRYPTO_AES_Encrypt (UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                                    UINT8 *pDstData, char *pszMode, UINT8 *pKey, UINT32 nKeySize);

/*
 * Perform TEE AES decryption.
 * 128 and 256 bits key size should be supported, and PKCS#5 padding should be used.
 * The pKey is a SecureData.
 * ECB and CBC mode should be supported. The mode of operation is specified by the parameter
 * pszMode of which the type is char pointer type string. "ECB" or "CBC" can be passed.
 * When using CBC, IV value should be generated randomly in TEE and attached in front of the
 * encrypted result buffer. For decryption, the IV is retrieved from the source buffer (16bytes
 * in front of the encrypted data).
 *
 *  @param   nSrcLen     [IN]        Size of data to be decrypted
 *  @param   pSrcData    [IN]        Buffer for data to be decrypted
 *  @param   pDstLen     [OUT]       Size of output data (the result of decryption)
 *  @param   pDstData    [OUT]       Buffer for output data (the result of decryption)
 *  @param   pszMode     [IN]        Block cipher Mode (ECB / CBC)
 *  @param   pKey        [IN]        SecureData of cipher key
 *  @param   nKeySize    [IN]        Size of pKey data
 *  @return  If the function succeeds, the return value is OK.
 *           If the function fails, the return value is NOT_OK.
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
/*
 * Perform RSA encryption.
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
 *  @return  If the function succeeds, the return value is OK.
 *           If the function fails, the return value is NOT_OK.
 */
DTV_STATUS_T HAL_CRYPTO_RSA_Encrypt (UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                                     UINT8 *pDstData, HAL_CRYPTO_RSA_PADDING_T padding,
                                     char *pszKeyType, UINT8 *pKey, UINT32 nKeySize);

/*
 * Perform RSA decryption.
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
 */
DTV_STATUS_T HAL_CRYPTO_RSA_Decrypt (UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen,
                                     UINT8 *pDstData, HAL_CRYPTO_RSA_PADDING_T padding,
                                     char *pszKeyType, UINT8 *pKey, UINT32 nKeySize);

/*
 * Perform RSA Signing in TEE
 * Signing message encoding scheme is "SHA256 / EMSA-PKCS1-v1_5 Encoding"
 * pKey is a SecureData type and its original key data is PKCS#1 format that is encoded by
 * DER or PEM.
 *
 *  @param   nDataSize         [IN]      Size of data to be signed
 *  @param   pData             [IN]      Data to be signed
 *  @param   pSigLen           [OUT]     Size of signature (pSig)
 *  @param   pSig              [OUT]     Signature data
 *  @param   pszKeyType        [IN]      Key Encoding Type. ("PEM" or "DER")
 *  @param   pKey              [IN]      SecureData of cipher key
 *  @param   nKeyLen           [IN]      Size of pKey data
*/
DTV_STATUS_T HAL_CRYPTO_RSA_Sign (UINT32 nDataSize, UINT8 *pData, UINT32 *pSigLen, UINT8 *pSig,
                                  char *pszKeyType, UINT8 *pKey, UINT32 nKeyLen);

/*
 * Perform RSA signature verification in TEE
 * Signing message encoding scheme is "SHA256 / EMSA-PKCS1-v1_5 Encoding"
 * pKey is a SecureData type and its original key data is PKCS#1 format that is encoded by
 * DER or PEM.
 *
 *  @param   nDataSize         [IN]      Size of data to be verified
 *  @param   pData             [IN]      Data to be verified
 *  @param   nSigLen           [IN]      Size of signature (pSig)
 *  @param   pSig              [IN]      Signature data
 *  @param   pszKeyType        [IN]      Key Encoding Type. ("PEM" or "DER")
 *  @param   pKey              [IN]      SecureData of cipher key
 *  @param   nKeyLen           [IN]      Size of pKey data
*/
DTV_STATUS_T HAL_CRYPTO_RSA_Verify (UINT32 nDataSize, UINT8 *pData, UINT32 nSigLen, UINT8 *pSig,
                                    char *pszKeyType, UINT8 *pKey, UINT32 nKeySize);

/*
 * HAL_CRYPTO_EncryptDbgData
 * Encrypt debug status data.
 *
 * @param   pInData         [IN]    Input data  (plaintext data)
 * @param   nInL            [IN]    Input data size
 * @param   pOutData        [IN]    Output data (encrypted data)
 * @param   pOutL           [IN]    Output data size
 * @return  If the function succeeds, the return value is OK.
 *          If the function fails, the return value is NOT_OK.
 */

DTV_STATUS_T HAL_CRYPTO_EncryptDbgData (UINT8 *pInData, int nInL, UINT8 *pOutData, int *pOutL);

/*
 * HAL_CRYPTO_DecryptDbgData
 * Decrypt debug status data.
 *
 * @param   pInData         [IN]    Input data  (Encrypted data)
 * @param   nInL            [IN]    Input data size
 * @param   pOutData        [IN]    Output data (Plaintext data)
 * @param   pOutL           [IN]    Output data size
 * @return  If the function succeeds, the return value is OK.
 *          If the function fails, the return value is NOT_OK.
 */
DTV_STATUS_T HAL_CRYPTO_DecryptDbgData (UINT8 *pInData, int nInL, UINT8 *pOutData, int *pOutL);

 /**
 * @brief Check tzfw version from data and compare the version in RPMB
 *
 * @rst
 * Functional Requirements
 *      Get the tzfw version from input data and compare the version in RPMB.
 *      If input tzfw's version is higher or same with the version in RPMB, return 0.
 *      If not, return not zero.
 *
 * Responses to abnormal situations, including
 *      There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *      There is no constraints.
 *
 * Functions & Parameters
 *      * HAL_CRYPTO_CheckTzfwAntirollback(UINT8 *pData, UINT32 nLength)
 *
 *      For the data type, following data types are defined
 *
 *      * *pData           [IN] tzfw binary data
 *      * nLength          [IN] data length
 *
 * Return Value
 *     Zero(0) if the input tzfw's version is higher or same with the version in RPMB, non-Zero otherwise
 *
 * Example
 *      .. code-block:: cpp
 *
 *        ret = HAL_CRYPTO_CheckTzfwAntirollback(data, size);
 *        if (ret != 0) {
 *            // Fail to downgrade
 *        }
 * @endrst
 */
 DTV_STATUS_T HAL_CRYPTO_CheckTzfwAntirollback(UINT8 *pData, UINT32 nLength);


#endif      //_HAL_CRYPTO_H_

