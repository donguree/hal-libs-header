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
 *  @author	    Stan Kim (stan.kim@lge.com)
 *  @author	    Seonho Park (seonho.park@lge.com)
 *  @author	    Yongjoon Cho (seonho.park@lge.com)
 *  @version	4.0
 *  @date		2010.08.09
 *  @note
 *  @see
 */

/******************************************************************************
 	Header File Guarder
******************************************************************************/
#ifndef	_HAL_CRYPTO_H_
#define	_HAL_CRYPTO_H_

/******************************************************************************
 #include ÆÄÀÏµé (File Inclusions)
******************************************************************************/
#include "hal_common.h"

/******************************************************************************
	Çü Á¤ÀÇ (Type Definitions)
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
    ¸ÅÅ©·Î ÇÔ¼ö Á¤ÀÇ (Macro Definitions)
******************************************************************************/

/******************************************************************************
   ·ÎÄÃ »ó¼ö Á¤ÀÇ (Local Constant Definitions)
******************************************************************************/

/******************************************************************************
    ·ÎÄÃ Çü Á¤ÀÇ (Local Type Definitions)
******************************************************************************/

/******************************************************************************
    Àü¿ª Çü Á¤ÀÇ (Global Type Definitions)
******************************************************************************/
typedef enum {
	CRYPTO_HDCP_14,  //HDCP 1.4
	CRYPTO_HDCP_22,  //HDCP 2.2
	CRYPTO_HDCP_MAX,
} CRYPTO_HDCP_T;	// For HAL_CRYPTO_WriteHDCPOnSecure()/HAL_CRYPTO_ReadHDCPFromSecure()

/******************************************************************************
    Extern Àü¿ªº¯¼ö¿Í ÇÔ¼ö prototype ¼±¾ð
    (Extern Variables & Function Prototype Declarations)
******************************************************************************/

/******************************************************************************
    Static º¯¼ö¿Í ÇÔ¼ö prototype ¼±¾ð
    (Static Variables & Function Prototypes Declarations)
******************************************************************************/

/******************************************************************************
    ·ÎÄÃ º¯¼ö¿Í ÇÔ¼ö prototype ¼±¾ð
    (Local Variables & Function Prototypes Declarations)
******************************************************************************/

/******************************************************************************
    Àü¿ª º¯¼ö¿Í ÇÔ¼ö prototype ¼±¾ð
    (Global Variables & Function Prototypes Declarations)
******************************************************************************/

/******************************************************************************
	ÇÔ¼ö Á¤ÀÇ (Function Definitions)
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
    HAL_CRYPTO_NF_WriteAppData

Function Description
    Write App Data to Secure Store

Function Parameters
    void *pDataId		[IN]			Data Identifier
    UINT8 *pData		[IN]			Data
    int	length		    [IN]			Data length

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
    void *pDataId		[IN]			Data Identifier
    UINT8 *pData		[IN]			Data
    int	length		    [IN]			Data length

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_NF_ReadAppData(char *pDataId, UINT8 *pData, int length);


/*	LG TEE Implementation		 */
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
    /*
    typedef enum
    {
        nfTOB_UNDEFINED = 0,
        /*
         * Some messages are for TEE (or VM) management. Those start at offset 0
         *
        nfTOB_TEE_MGMT = 1,
        /*
         * We're not implementing REE/TEE session management in the first revision, but we'll
         * need it later, so let's allocate a slot for that.
         *
        nfTOB_TEE_SESSION = 2048,
        /*
         * The first TA we'll implement is the crypto agent. This agent is used for all
         * webcrypto/msl operations, and also can provide secure store crypto services.
         *
        nfTOB_CRYPTO_AGENT = 4096,
        /*
         * PlayReady integration is a stretch goal for the first revision, so let's
         * allocate a slot for it.
         *
        nfTOB_DRM_AGENT = 6144,
        /*
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

/* Dummy for Compatablity */
DTV_STATUS_T HAL_CRYPTO_Debug(void);

/* Secure Firmware Update */
DTV_STATUS_T HAL_CRYPTO_SFU_Initialize(char *pSeedPath);
DTV_STATUS_T HAL_CRYPTO_SFU_Finalize(void);
DTV_STATUS_T HAL_CRYPTO_SFU_GetRSAKey(UINT8 *pRsaKey);
DTV_STATUS_T HAL_CRYPTO_SFU_GetAESKey(UINT8 *pAesKey);

/* Read/Write Secret Values */
DTV_STATUS_T HAL_CRYPTO_ReadMskToSecureStore(UINT8 *pData, int *pLength);
DTV_STATUS_T HAL_CRYPTO_WriteMskToSecureStore(UINT8 *pData, int length);
DTV_STATUS_T HAL_CRYPTO_ReadNLPSecret(UINT8 *pSecret, char *pSecretID);
DTV_STATUS_T HAL_CRYPTO_BBC_ReadClientKey(UINT8 *pKey);
DTV_STATUS_T HAL_CRYPTO_ReadPrsSecret(UINT8 *pSecret);
DTV_STATUS_T HAL_CRYPTO_CIPLUS_GetCiPlusSslPubKey(UINT8 *pPath, UINT8 *dKey);
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

DTV_STATUS_T HAL_CRYPTO_WriteHDCPOnSecure(unsigned int hdcpType, unsigned char *pHDCPKey, unsigned int hdcpSize);
DTV_STATUS_T HAL_CRYPTO_ReadHDCPFromSecure(unsigned int hdcpType, unsigned char *pHDCPKey, unsigned int *pHDCPSize);


/* Vudu */
/******************************************************************************
Function Name
    HAL_CRYPTO_VUDU_OpenM2mKeySlot

Function Description
    Allocate Memory to Memory Keyslot Handle

Function Parameters
    None

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_VUDU_OpenM2mKeySlot(void);

/******************************************************************************
Function Name
    HAL_CRYPTO_VUDU_CloseM2mKeySlot

Function Description
    Free Memory to Memory Keyslot Handle

Function Parameters
    None

Return Value
    If the function succeeds, the return value is OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_VUDU_CloseM2mKeySlot(void);

/******************************************************************************
Function Name
    HAL_CRYPTO_VUDU_SelectM2mKeyAlgorithm

Function Description
    Select Encryption/Decryption Algorithm

Function Parameters
    alg	[IN] 		Select Algorithm
    dir	[IN]		Select Mode

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_VUDU_SelectM2mKeyAlgorithm(UINT8 alg, UINT8 dir);

/******************************************************************************
Function Name
    HAL_CRYPTO_VUDU_LoadClearM2mKey

Function Description
    Loads a Clear Key and a Clear IV to KeySlot.

Function Parameters
    keyLen	[IN] 		Key Length
    pKeyData	[IN]		Key Data
    ivLen		[IN]		Initial Vector Length
    pIvData	[IN]		Initial Vector Data

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_VUDU_LoadClearM2mKey(const UINT32 keyLen, const UINT8 *pKeyData, const UINT32 ivLen, const UINT8 *pIvData);

/******************************************************************************
Function Name
    HAL_CRYPTO_VUDU_LoadWrappedM2mKey

Function Description
    Loads a Wrapped Key and a Wrapped IV to KeySlot

Function Parameters
    keyLen	[IN] 		Key Length of pKey4Data and pIvData
    pKey3Data	[IN]		Seed of Session Key
    pKey4Data	[IN]		Seed of Control Word
    pIvData	[IN]		Initial Vector Data

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_VUDU_LoadWrappedM2mKey(const UINT32 keyLen, const UINT8 *pKey3Data, const UINT8 *pKey4Data, const UINT8 *pIvData);

/******************************************************************************
Function Name
    HAL_CRYPTO_VUDU_LoadWrappedM2mKeyClearIv

Function Description
    Loads a Wrapped Key and a Clear IV to KeySlot

Function Parameters
    keyLen	[IN] 		Key Length of pKey4Data and pIvData
    pKey3Data	[IN]		Seed of Session Key
    pKey4Data	[IN]		Seed of Control Word
    ivLen		[IN]		Initial Vector Length
    pIvData	[IN]		Initial Vector Data

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_VUDU_LoadWrappedM2mKeyClearIv(const UINT32 keyLen, 	const UINT8 *pKey3Data, const UINT8 *pKey4Data, const UINT32 ivLen, const UINT8 *pIvData);

/******************************************************************************
Function Name
    HAL_CRYPTO_VUDU_RunM2mKey

Function Description
    Start the Cipher Process

Function Parameters
    length		[IN] 		Length of Both Src and Dst
    pSrc		[IN]		Source Pointer
    pDst		[OUT]	Destination Pointer

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_VUDU_RunM2mKey(const UINT32 length, const UINT8 *pSrc, UINT8 *pDst);


/* Play API */
/******************************************************************************
Function Name
    HAL_CRYPTO_VUDU_OpenCAKeySlotHandle

Function Description
    Allocate VUDU CA Descramble Handle

Function Parameters
    None

Return Value
    If the function succeeds, the return value is handle value.
    If the function fails, the return value is 0.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_VUDU_OpenCAKeySlotHandle(void);


/******************************************************************************
Function Name
    HAL_CRYPTO_VUDU_CloseCAKeySlotHandle

Function Description
    Free VUDU CA Descramble Handle

Function Parameters
    None

Return Value
    If the function succeeds, the return value is 0.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_VUDU_CloseCAKeySlotHandle(void);


/******************************************************************************
Function Name
    HAL_CRYPTO_VUDU_GetCAKeySlotHandle

Function Description
    Allocate VUDU CA Descramble Handle

Function Parameters
    None

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_VUDU_GetCAKeySlotHandle(void);

/******************************************************************************
Function Name
    HAL_CRYPTO_VUDU_SetWrappedCAKey

Function Description
    Load Wrapping Key to CA Descrambler

Function Parameters
    pKey			[IN]		CA Initial Vector
    pUniqueKey	[IN]		CA Wrapping Key
    keyType		[IN]		CA Key Type

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_VUDU_SetWrappedCAKey(const UINT8 *pKey, const UINT8 *pUniqueKey, UINT8 keyType);


/******************************************************************************
Function Name
    HAL_CRYPTO_VUDU_SetWrappedAllCAKey

Function Description
    Load Wrapping Keys to CA Descrambler

Function Parameters
    pOddKey		[IN]		CA Initial Odd Vector
    pEvenKey		[IN]		CA Initial Even Vector
    pUniqueKey	[IN]		CA Wrapping Key

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_VUDU_SetWrappedAllCAKey(const UINT8 *pOddKey, const UINT8 *pEvenKey, const UINT8 *pUniqueKey);


/******************************************************************************
Function Name
    HAL_CRYPTO_VUDU_LoadCAClearKey

Function Description
    Load Clear Key to CA Descrambler

Function Parameters
    pKey			[IN]		CA Initial Vector
    keyType		[IN]		CA Key Type

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_VUDU_LoadCAClearKey(const UINT8 *pKey, UINT8 keyType);


/******************************************************************************
Function Name
    HAL_CRYPTO_VUDU_StartTSDecrypt

Function Description
    Start the TS Decrypt

Function Parameters
    srcLength	[IN] 		Length of Src
    pSrc		[IN]		Source Pointer (Encrypeted VUDU TS stream)
    pDstLength	[OUT]	Length of Dst
    pDst		[OUT]	Destination Pointer (the Result should be clear TS)

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CRYPTO_VUDU_StartTSDecrypt(const UINT32 srcLength, const UINT8 *pSrc, UINT32 *pDstLength, UINT8 *pDst);

DTV_STATUS_T HAL_CRYPTO_VUDU_SetOddEvenCAKey(const UINT8 *pOddKey, const UINT8 *pEvenKey, UINT8 keyType);
//DTV_STATUS_T HAL_CRYPTO_VUDU_StartCADecrypt(void);

/* Vudu SVP : Security Level 1 */

// Call Sequnce Note :
//
//	[1. Initialize]
//
//	... Allocate and set CPB from/to VDEC (Note : Size must be 8 MBytes, and align value also must be 8 MBytes)
//	HAL_CRYPTO_VUDU_SVP_Init(base, size);
//
//
//	[2. Decrypt -> Reformatting -> Put into Secure CPB]
//
//	while (...) {	// Playback Loop
//
//		HAL_CRYPTO_VUDU_SVP_TSDecrypt(...);	// Decyrption
//
//  again :
//		... Get rPtr, wPtr from VDEC
//		switch (HAL_CRYPTO_VUDU_SVP_GetAU(...)) {	// Reformatting & Put into CPB
//			case HAL_CRYPTO_VUDU_SVP_OK : // Get AU
//				... Send AU and CPB Update Info to VDEC
//				goto again;
//
//			case HAL_CRYPTO_VUDU_SVP_NO_AU :
//				break;	// Get next data packet
//
//			case HAL_CRYPTO_VUDU_SVP_WAIT :
//				... sleep to give vdec a delay to decode and display
//				goto again;	// Try to put CPB again.
//
//			default :	// Error
//				... Error Handling
//		}
//		... Do others
//	}	// Playback Loop
//
//
//	[3. Release]
//
//	HAL_CRYPTO_VUDU_SVP_Release();
//
//
//	[4. Flush]
//
//	... Flush VDEC
//	HAL_CRYPTO_VUDU_SVP_Flush();

typedef enum {
	HAL_CRYPTO_VUDU_SVP_ERROR	= -1,
	HAL_CRYPTO_VUDU_SVP_OK		= 0,
	HAL_CRYPTO_VUDU_SVP_NO_AU	= 1,
	HAL_CRYPTO_VUDU_SVP_WAIT	= 2,
} HAL_CRYPTO_VUDU_SVP_T;

/**
 *	Initialize SVP for VUDU.
 *
 *	@param	base	[in]	Secure CPB base.
 *	@param	size	[in]	Secure CPB size.
 *	@return	success : OK, failure : NOT_OK.
 */
DTV_STATUS_T HAL_CRYPTO_VUDU_SVP_Init(UINT32 base, int size);

/**
 *	SVP TS Decrypt for VUDU.
 *
 *	@param	srcLength	[in]	Length of Src.
 *	@param	pSrc		[in]	Source Pointer (Encrypeted VUDU TS stream).
 *	@param	pDstLength	[out]	Length of Dst.
 *	@param	pDst		[out]	Destination Pointer (the Result should be clear TS and be removed Video ES Data).
 *	@return succeeded - OK, if not - NOT_OK.
 */
DTV_STATUS_T HAL_CRYPTO_VUDU_SVP_TSDecrypt(const UINT32 srcLength, const UINT8 *pSrc, UINT32 *pDstLength, UINT8 *pDst);

/**
 *	Get AU for VUDU
 *
 *	@param	pAuAddr		[out]		physical AU address in secure CPB.
 *	@param	pAuLength	[out]		physical AU length in secure CPB.
 *	@param	pAuType		[out]		AU type (It is not available in TVP_REFORMATTER_NONE).
 *	@param	pWPtr		[in/out]	Secure CPB Write Pointer.
 *	@param	rPtr		[in]		Secure CPB Read Pointer.
 *	@param	pPTS		[out]		Representative PTS value.
 *	@return HAL_CRYPTO_VUDU_SVP_NO_AU	: Proceed next.
 *			HAL_CRYPTO_VUDU_SVP_OK		: AU Out.
 *			HAL_CRYPTO_VUDU_SVP_WAIT	: Wait because of not enough CPB.
 *			HAL_CRYPTO_VUDU_SVP_ERROR	: Error.
 */
HAL_CRYPTO_VUDU_SVP_T HAL_CRYPTO_VUDU_SVP_GetAU(unsigned int *pAuAddr, int *pAuLength, int *pAuType,
	unsigned int *pWPtr, unsigned int rPtr, unsigned long long *pPTS);

/**
 *	Flush Reformatter & TS Parser for VUDU
 *
 *	@return	success : TVP_OK, failure : TVP_ERROR.
 */
DTV_STATUS_T HAL_CRYPTO_VUDU_SVP_Flush(void);

/**
 *	Release SVP for VUDU.
 *
 *	@return	success : OK, failure : NOT_OK.
 */
DTV_STATUS_T HAL_CRYPTO_VUDU_SVP_Release(void);


/* webOS Secure Store Support APIs */
/**
 * Perform TEE AES encryption.
 * 128 and 256 bits key size should be supported, and PKCS#5 padding should be used. The pKey is a SecureData.
 * ECB and CBC mode should be supported. The mode of operation is specified by the parameter pszMode of which the type is char pointer type string. "ECB" or "CBC" can be passed.
 * When using CBC, IV value should be generated randomly in TEE and attached in front of the encrypted result buffer. For decryption, the IV is retrieved from the source buffer (16bytes in front of the encrypted data).
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
DTV_STATUS_T HAL_CRYPTO_AES_Encrypt (UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData, char *pszMode, UINT8 *pKey, UINT32 nKeySize);

/*
 * Perform TEE AES decryption.
 * 128 and 256 bits key size should be supported, and PKCS#5 padding should be used. The pKey is a SecureData.
 * ECB and CBC mode should be supported. The mode of operation is specified by the parameter pszMode of which the type is char pointer type string. "ECB" or "CBC" can be passed.
 * When using CBC, IV value should be generated randomly in TEE and attached in front of the encrypted result buffer. For decryption, the IV is retrieved from the source buffer (16bytes in front of the encrypted data).

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
DTV_STATUS_T HAL_CRYPTO_AES_Decrypt (UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData, char *pszMode, UINT8 *pKey, UINT32 nKeySize);

/*
 * Perform RSA encryption.
 * OAEP padding scheme is used.
 * The passed pKey is a type of SecureData, and original key is has a format of PKCS#1 and encoded by either DER or PEM. So, the encoding type should be passed via the parameter pszKeyType.
 *
 *  @param   pSrcLen         [IN]     Size of data to be encrypted
 *  @param   pSrcData        [IN]     Buffer for data to be encrypted
 *  @param   pDstLen         [OUT]    Size of output data (the result of encryption)
 *  @param   pDstData        [OUT]    Buffer for output data (the result of encryption)
 *  @param   pszKeyType      [IN]     Key Encoding Type. ("PEM" or "DER")
 *  @param   pKey            [IN]     SecureData of cipher key
 *  @param   nKeySize        [IN]     Size of pKey data
 *  @return  If the function succeeds, the return value is OK.
 *           If the function fails, the return value is NOT_OK.
 */
DTV_STATUS_T HAL_CRYPTO_RSA_Encrypt (UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData, char *pszKeyType, UINT8 *pKey, UINT32 nKeySize);

/*
 * Perform RSA decryption.
 * OAEP padding scheme is used.
 * The passed pKey is a type of SecureData, and original key is has a format of PKCS#1 and encoded by either DER or PEM. So, the encoding type should be passed via the parameter pszKeyType.
 *
 *  @param   pSrcLen          [IN]      Size of data to be decrypted
 *  @param   pSrcData         [IN]      Buffer for data to be decrypted
 *  @param   pDstLen          [OUT]     Size of output data (the result of decryption)
 *  @param   pDstData         [OUT]     Buffer for output data (the result of encryption/decryption)
 *  @param   pszKeyType       [IN]      Key Encoding Type. ("PEM" or "DER")
 *  @param   pKey             [IN]      SecureData of cipher key
 *  @param   nKeySize         [IN]      Size of pKey data
 */
DTV_STATUS_T HAL_CRYPTO_RSA_Decrypt (UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData, char *pszKeyType, UINT8 *pKey, UINT32 nKeySize);

/*
 * Perform RSA Signing in TEE
 * Signing message encoding scheme is "SHA256 / EMSA-PKCS1-v1_5 Encoding"
 * pKey is a SecureData type and its original key data is PKCS#1 format that is encoded by DER or PEM.
 *
 *  @param   nDataSize         [IN]      Size of data to be signed
 *  @param   pData             [IN]      Data to be signed
 *  @param   pSigLen           [OUT]     Size of signature (pSig)
 *  @param   pSig              [OUT]     Signature data
 *  @param   pszKeyType        [IN]      Key Encoding Type. ("PEM" or "DER")
 *  @param   pKey              [IN]      SecureData of cipher key
 *  @param   nKeyLen           [IN]      Size of pKey data
*/
DTV_STATUS_T HAL_CRYPTO_RSA_Sign (UINT32 nDataSize, UINT8 *pData, UINT32 *pSigLen, UINT8 *pSig, char *pszKeyType, UINT8 *pKey, UINT32 nKeyLen);

/*
 * Perform RSA signature verification in TEE
 * Signing message encoding scheme is "SHA256 / EMSA-PKCS1-v1_5 Encoding"
 * pKey is a SecureData type and its original key data is PKCS#1 format that is encoded by DER or PEM.
 *
 *  @param   nDataSize         [IN]      Size of data to be verified
 *  @param   pData             [IN]      Data to be verified
 *  @param   nSigLen           [IN]      Size of signature (pSig)
 *  @param   pSig              [IN]      Signature data
 *  @param   pszKeyType        [IN]      Key Encoding Type. ("PEM" or "DER")
 *  @param   pKey              [IN]      SecureData of cipher key
 *  @param   nKeyLen           [IN]      Size of pKey data
*/
DTV_STATUS_T HAL_CRYPTO_RSA_Verify (UINT32 nDataSize, UINT8 *pData, UINT32 nSigLen, UINT8 *pSig, char *pszKeyType, UINT8 *pKey, UINT32 nKeySize);

#endif		//_HAL_CRYPTO_H_


