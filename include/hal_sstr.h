/******************************************************************************
 *   TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999-2016 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/


/** @file       hal_sstr.h
 *
 *  This source file defines the HAL functions related to webOS Secure Store
 *
 *  @author
 *  @version	1.0
 *  @date		2016.05.16
 *  @note
 *  @see
 *
 *  TEE crypto functions for webOS Secure Store (Platform Layer Secure Store)
 *
 */

/******************************************************************************
 	Header File Guarder
******************************************************************************/
#ifndef	_HAL_SSTR_H_
#define	_HAL_SSTR_H_

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
	HAL_SSTR_R_OK				= 0,	/**< OK */
	HAL_SSTR_R_GENERAL_ERROR	= -1,	/**< unspecified error */
	HAL_SSTR_R_TEE_FAILURE		= -2,	/**< TEE Problem */
	HAL_SSTR_R_INVALID_BUFSIZE	= -3,	/**< Given buffer size is not enough */
	HAL_SSTR_R_INVALID_KEY		= -4,	/**< pKey is not a type of "Protected SDHK" */
	HAL_SSTR_R_NOT_MATCH		= -5,	/**< HMAC value is not matched */
} HAL_SSTR_R_T;



/**
 *  Terminologies
 *  Device Unique Key (DUK)  : The key that is unique per device. Every secure store keys are encrypted by their own unique "key encryption key(KEK)" and the KEK is also encrypted by the DUK.
 *                             That is, this is an anchor point to chain of trust in TEE and the root of every key chains of secure store keys. This is also called OTP key because it is stored in OTP memory.
 *                              In this document, we call it DUK.
 *  SecureData : The result from encrypting data using TEE Crypto API. The encryption key(SDEK) is unique key that is randomly generated per SecureData when requested and encrypted by DUK.
 *               The SecureData includes the encryption result and the encrypted SDEK (Protected SDEK).
 *              ( SecureData =  EDUK(SDEK) || ESDEK(Data), where size of SecureData = 32+size of Data )
 *  SecureData Encryption Key (SDEK) : The key encryption key to be used to make a SecureData (encrypt data). This key is randomly generated each time that making SecureData is requested.
 *  SecureData HMAC Key (SDHK) : The HMAC Key to be used to generate and verify HMAC value of Secure Data. This key is randomly generated each time that HMAC generation API is called. The key size is 32 bytes.
 *  Protected SDEK : The encrypted SDEK ( EDUK(SDEK) ). This data is attached in front of SecureData, and used to decrypt SecureData in TEE.
 *  Protected SDHK : The encrypted SDHK ( EDUK(SDHK) ).
 */


/******************************************************************************
    Function Declaration
******************************************************************************/

/**
 *
 *  Make SecureData by encrypting the source data pSrcData of which the size is nSrcLen, and copy it to the buffer pointed by pDstData and its size to pDstLen.
 *  The data type pszDataType indicates how to process the given data. Probably the given data may have to be stored in SoC Secure Store and its SecureData never be exposed to REE.
 *  Some data may be clear data and some other data may be already encrypted by SoC common key encryption (e.g. sedata).
 *  The data type gives the information to decide a way to process the given data as whether sedata or not, or whether returning the SecureData to REE or storing SoC Secure Store.
 *    - "general" : General case. Just encrypt the given data and make SecureData and return it.
 *    - "sedata"  : srcDataBuf is a type of sedata. That is, it is already encrypted by a device common key. Therefore it should be decrypted before encrypting it with SDEK in TEE.
 *    - key ID : The given data should be stored in SoC secure store. In this case, the SecureData should not be returned from TEE (never exposed to REE).
 *      Ex: tee_bgroupcert.dat, tee_keyhistory.dat, tee_zgpriv.dat, vudu_m2m, vudu_ca
 *
 *   Format of SecureData :  SecureData =  EDUK(SDEK) || ESDEK(Data), where size of SecureData = 32+size of Data
 *   lEncryption Algorithm : AES-256-ECB (The other mode can be used, but output size should be "32+size of Data".
 *
 *   @param   pSrcLen         [IN]      size of pSrcData
 *   @param   pSrcData        [IN]      Buffer for data to be Encrypted
 *   @param   pDstLen         [OUT]     sizeof pDstData
 *   @param   pDstData        [OUT]     buffer to store SecureData
 *   @param   pszDataType     [IN]      data type. "general", "sedata", or key ID such as "tee_bgroupcert.dat", "vudu_m2m".
 *
 */
HAL_SSTR_R_T HAL_SSTR_MakeSecureData(UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData, char *pszDataType);

/**
 *  Decrypt SecureData that is made by HAL_SSTR_MakeSecureData.
 *   data = DSDEK(SecureData), where SDEK = DDUK(Protected SDEK)
 *
 *   @param   pSrcLen         [IN]      size of pSrcData
 *   @param   pSrcData        [IN]      Buffer for data to be decrypted
 *   @param   pDstLen         [OUT]     sizeof pDstData
 *   @param   pDstData        [OUT]     buffer to store SecureData
 */
HAL_SSTR_R_T HAL_SSTR_GetDataFromSecureData (UINT32 nSrcLen, UINT8 *pSrcData, UINT32 *pDstLen, UINT8 *pDstData);

/**
 *  Given a pData of which the size is nDataSize, calculate HMAC and return it with the Protected SDHK. The SDHK is randomly generated for each API calls and its size is 32 bytes.
 *  HMAC algorithm is HMAC_SHA256 and should be performed in TEE.
 *
 *   @param   nDataSize    [IN]      size of pSrcData
 *   @param   pData        [IN]      Buffer for data to be decrypted
 *   @param   pKey         [OUT]     sizeof pDstData
 *   @param   pHMAC        [OUT]     buffer to store SecureData
 */
HAL_SSTR_R_T HAL_SSTR_GetHMAC (UINT32 nDataSize, UINT8 *pData, UINT8 *pKey, UINT8 *pHMAC);

/*
 *  Verify the data pData of which the size is nDataSize with the HMAC value pHMAC. The key data pKey is a protected SDHK that is provided by HAL_SSTR_GetHMAC API.
 *  According to the validation result, HAL_SSTR_R_OK or HAL_SSTR_NOT_MATCH is returned.
 *
 *   @param   nDataSize    [IN]         size of pSrcData
 *   @param   pData        [IN]         Buffer for data to be decrypted
 *   @param   pKey         [IN]         sizeof pDstData
 *   @param   pHMAC        [IN]         buffer to store SecureData
 */
HAL_SSTR_R_T HAL_SSTR_VerifyHMAC (UINT32 nDataSize, UINT8 *pData, UINT8 *pKey, UINT8 *pHMAC);

/*
 * Generate a random data of which the size is nSize and transform it to SecureData, and copy it to the buffer pointed by pKey.
 *
 *  @param   nSize    [IN]         Size of key to be generated
 *  @param   pKey     [OUT]         Buffer to store the generated key
 */
HAL_SSTR_R_T HAL_SSTR_GenAESKey (UINT32 nSize, UINT8 *pKey);

#endif		//_HAL_SSTR_H_
