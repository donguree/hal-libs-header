/******************************************************************************
 *   TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999-2022 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file	hal_pvr.h
 *
 *  Header file for PVR HAL
 *
 *  @author   YoungKi Son (yk.son@lge.com)
 *  @version  2.0
 *  @date     2013.03.14 Juyoung Jo (juyoung.jo@lge.com)
 *  @date     2017.3.03
 *  @date     2022.5 Hwachin Lee (hwachin.lee@lge.com)
 *  @note     none
 *  @see
 */

#ifndef	_HAL_PVR_H_
#define	_HAL_PVR_H_

#include "hal_common.h"

/*----------------------------------------------------------------------------------------
  Type Definitions
----------------------------------------------------------------------------------------*/

typedef enum _PVR_CIPHER_T
{
  PVR_CIPHER_NONE = 0,
  PVR_CIPHER_AES_ECB,
  PVR_CIPHER_AES_CBC,
  PVR_CIPHER_MAX
} PVR_CIPHER_T;

typedef enum _PVR_CIPHER_KEY_T
{
  PVR_CIPHER_KEY_EVEN = 0,
  PVR_CIPHER_KEY_ODD
} PVR_CIPHER_KEY_T;

typedef enum _PVR_CIPHER_OPERATION_T
{
  PVR_CIPHER_OPERATION_ENCRYPT = 0,
  PVR_CIPHER_OPERATION_DECRYPT,
  PVR_CIPHER_OPERATION_NUM
} PVR_CIPHER_OPERATION_T;

typedef struct _PVR_CRYPTO_TYPE_T
{
	PVR_CIPHER_T			cipherAlgorithm;
  PVR_CIPHER_KEY_T		cipherKeyType;
  PVR_CIPHER_OPERATION_T	cipherOperation;
  UINT32					keyBitLen;		/**<  Length of the key  */
  UINT8					*pIV;			/**< A possible Initialization Vector for ciphering */
  UINT8					*pCipherKey;
} PVR_CRYPTO_TYPE_T;

/*----------------------------------------------------------------------------------------
  Function Prototype Declaration
----------------------------------------------------------------------------------------*/

/**
 * @brief Initialize PVR Crypto
 *
 * @rst
 * Description
 *   Initialize the encryption related module of PVR. Internally initialize the Cryptograph Driver-related module of the chipset, and if there is a resource to be created internally in the HAL in relation to the encryption module, it is created here. This API is called once after power on.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_InitializeCrypto(void)
 *
 * Parameters
 *   None
 *
 * Return Value
 *   If the function succeeds, the return value is OK.
 *   If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_InitializeCrypto()
 *     {
 *         CALL Chip vendor's PVR Crypto related initialization function
 *         IF success THEN
 *             RETURN OK
 *         ELSE
 *             RETURN NOT_OK
 *         ENDIF
 *     }
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *     DTV_STATUS_T     ret;
 *     ret = HAL_PVR_InitializeCrypto();
 *     if(ret == NOT_OK)
 *     {
 *         printf("Fail to initialize PVR Crypto\n");
 *         return NOT_OK;
 *     }
 *
 * See Also
 *   - HAL_PVR_FinalizeCrypto
 * @endrst
 */
DTV_STATUS_T HAL_PVR_InitializeCrypto(void);

/**
 * @brief Finalize PVR Crypto
 *
 * @rst
 * Description
 *   Finalize the encryption related module of PVR. Close all resources for encryption
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_FinalizeCrypto(void)
 *
 * Parameters
 *   None
 *
 * Return Value
 *   If the function succeeds, the return value is OK.
 *   If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_FinalizeCrypto()
 *     {
 *         CALL Chip vendor's PVR Crypto related initialization function
 *         IF success THEN
 *             RETURN OK
 *         ELSE
 *             RETURN NOT_OK
 *         ENDIF
 *     }
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *     DTV_STATUS_T     ret;
 *     ret = HAL_PVR_FinalizeCrypto();
 *     if(ret == NOT_OK)
 *     {
 *         printf("Fail to finalize PVR Crypto\n");
 *         return NOT_OK;
 *     }
 *
 * See Also
 *   - HAL_PVR_InitializeCrypto
 * @endrst
 */
DTV_STATUS_T HAL_PVR_FinalizeCrypto(void);

/**
 * @brief Setting encryption status
 *
 * @rst
 * Description
 *   Enable or disable encryption related API functions when recording PVR. If set to Disable(FALSE), all PVR encryption related HAL APIs do not work.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_CRYPTO_SetEncryptionState(BOOLEAN encryptEnable)
 *
 * Parameters
 *   - encryptEnable                    [IN] Encryption Enable/Disable flag
 *
 * Return Value
 *   If the function succeeds, the return value is OK.
 *   If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_CRYPTO_SetEncryptionState(BOOLEAN encryptEnable)
 *     {
 *         SET encryption state of SoC driver.
 *         IF success THEN
 *             RETURN OK
 *         ELSE
 *             RETURN NOT_OK
 *         ENDIF
 *     }
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *     DTV_STATUS_T     ret;
 *     ret = HAL_PVR_CRYPTO_SetEncryptionState(TRUE);
 *     if(ret == NOT_OK)
 *     {
 *         printf("Fail to set PVR Crypto encryption status\n");
 *         return NOT_OK;
 *     }
 *
 * See Also
 *   - HAL_PVR_CRYPTO_SetCipherKeys
 *   - HAL_PVR_CRYPTO_SetCipherAlgorithm
 * @endrst
 */
DTV_STATUS_T HAL_PVR_CRYPTO_SetEncryptionState(BOOLEAN encryptEnable);

/**
 * @brief Setting encryption cipher algorithm
 *
 * @rst
 * Description
 *   Specifies the algorithm (ECB/CBC) method used in the AES-128 encryption/decryption API.
 *   Currently, only the ECB (PVR_CIPHER_AES_ECB) method is used.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_CRYPTO_SetCipherAlgorithm(PVR_CIPHER_T cipherAlgorithm)
 *
 * Parameters
 *   - cipherAlgorithm                  [IN] Cipher Algorithm for setting to SoC driver [PVR_CIPHER_NONE/PVR_CIPHER_AES_ECB/PVR_CIPHER_AES_CBC]
 *
 * Return Value
 *   If the function succeeds, the return value is OK.
 *   If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_CRYPTO_SetCipherAlgorithm(PVR_CIPHER_T cipherAlgorithm)
 *     {
 *         SET cipher algorithm of SoC driver.
 *         IF success THEN
 *             RETURN OK
 *         ELSE
 *             RETURN NOT_OK
 *         ENDIF
 *     }
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *     DTV_STATUS_T     ret;
 *     ret = HAL_PVR_CRYPTO_SetCipherAlgorithm(PVR_CIPHER_AES_ECB);
 *     if(ret == NOT_OK)
 *     {
 *         printf("Fail to set PVR Cipher algorithm\n");
 *         return NOT_OK;
 *     }
 *
 * See Also
 *   - HAL_PVR_SetEncryptionState
 *   - HAL_PVR_CRYPTO_SetCipherKeys
 * @endrst
 */
DTV_STATUS_T HAL_PVR_CRYPTO_SetCipherAlgorithm(PVR_CIPHER_T cipherAlgorithm);

/**
 * @brief Getting encryption secure key
 *
 * @rst
 * Description
 *   Retrieves the PVR master key stored in the secure area.
 *   This API calls the API that accesses the Secure Partition of the SoC internally to get the key.
 *   (The corresponding API depends on the internal implementation of SoC vendors)
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_CRYPTO_GetSecureKey(UINT8 *pPath, UINT8 *pKey)
 *
 * Parameters
 *   - pPath                               [IN]     Path name (not used now)
 *   - pKey                                [OUT]    DVR Master Key stored in the secure area of SoC.
 *
 * Return Value
 *   If the function succeeds, the return value is OK.
 *   If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_CRYPTO_GetSecureKey(UINT8 *pPath, UINT8 *pKey)
 *     {
 *         Get a DVR Master Key from secure area of SoC driver.
 *         IF success THEN
 *             RETURN OK
 *         ELSE
 *             RETURN NOT_OK
 *         ENDIF
 *     }
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *     DTV_STATUS_T     ret;
 *     UINT8 pPath[255], pKey[255];
 *     ret = HAL_PVR_CRYPTO_GetSecureKey(pPath, pKey);
 *     if(ret == NOT_OK)
 *     {
 *         printf("Fail to get PVR secure key\n");
 *         return NOT_OK;
 *     }
 *
 * See Also
 *   - HAL_PVR_SetEncryptionState
 *   - HAL_PVR_CRYPTO_SetCipherKeys
 *   - HAL_PVR_CRYPTO_SetCipherAlgorithm
 * @endrst
 */
DTV_STATUS_T HAL_PVR_CRYPTO_GetSecureKey(UINT8 *pPath, UINT8 *pKey);

/**
 * @brief Setting encryption cipher key
 *
 * @rst
 * Description
 *   Set the encryption/decryption key information. including below data
 *     - Cipher algorithm
 *     - Cipher key type
 *     - cipher operation : encryption or decryption
 *     - key bit length
 *     - initial vector
 *     - key data
 *   You can set and use the keys used for Encrypt and Decrypt separately.
 *   If the 'cipherOperation' parameter is 'PVR_CIPHER_OPERATION_ENCRYPT', it means that the key is set for encryption.
 *   And if 'PVR_CIPHER_OPERATION_DECRYPT', it means that it is set for decryption.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_CRYPTO_SetCipherKeys(PVR_CRYPTO_TYPE_T cryptoInfo)
 *
 * Parameters
 *   - cryptoInfo         [IN]        Crypto information from PVR DIL.
 *
 * Return Value
 *   - If the function succeeds, the return value is OK.
 *   - If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_CRYPTO_SetCipherKeys(PVR_CRYPTO_TYPE_T cryptoInfo)
 *     {
 *         Set the PVR Cipher Key to PVR SoC driver.
 *         IF success THEN
 *             RETURN OK
 *         ELSE
 *             RETURN NOT_OK
 *         ENDIF
 *     }
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *     DTV_STATUS_T     ret;
 *     PVR_CRYPTO_TYPE_T cryptoInfo;
 *
 *     // Set the 'cryptoInfo' structure.
 *
 *     ret = HAL_PVR_CRYPTO_SetCipherKeys(cryptoInfo);
 *     if(ret == NOT_OK)
 *     {
 *         printf("Fail to set PVR cipher key\n");
 *         return NOT_OK;
 *     }
 * @endrst
 *
 * See Also
 *   - HAL_PVR_SetEncryptionState
 *   - HAL_PVR_CRYPTO_GetCipherKeys
 *   - HAL_PVR_CRYPTO_SetCipherAlgorithm
 */
DTV_STATUS_T HAL_PVR_CRYPTO_SetCipherKeys(PVR_CRYPTO_TYPE_T cryptoInfo);

/**
 * @brief Getting encryption cipher key
 *
 * @rst
 * Description
 *   This API uses HAL_PVR_CRYPTO_SetCipherKeys() to obtain key related information set on the SoC driver side.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_CRYPTO_GetCipherKeys(PVR_CIPHER_OPERATION_T cipherOperation, PVR_CRYPTO_TYPE_T *pCryptoInfo)
 *
 * Parameters
 *   - cipherOperation             [IN]       Select cipher operation by this parameter.
 *   - pCryptoInfo                 [OUT]      Crypto information from PVR DIL.
 *
 * Return Value
 *   If the function succeeds, the return value is OK.
 *   If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_CRYPTO_GetCipherKeys(PVR_CIPHER_OPERATION_T cipherOperation, PVR_CRYPTO_TYPE_T *pCryptoInfo)
 *     {
 *         Get the PVR Cipher Key for 'cipherOperation' from PVR SoC driver.
 *         Store cipher information to *pCryptoInfo structure.
 *         IF success THEN
 *             RETURN OK
 *         ELSE
 *             RETURN NOT_OK
 *         ENDIF
 *     }
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *     DTV_STATUS_T     ret;
 *     PVR_CIPHER_OPERATION_T cipherOperation;
 *     PVR_CRYPTO_TYPE_T cryptoInfo;
 *
 *     cipherOperation = PVR_CIPHER_OPERATION_ENCRYPT;
 *
 *     ret = HAL_PVR_CRYPTO_GetCipherKeys(cipherOperation, &cryptoInfo);
 *     if(ret == NOT_OK)
 *     {
 *         printf("Fail to get PVR cipher key\n");
 *         return NOT_OK;
 *     }
 * @endrst
 *
 * See Also
 *   - HAL_PVR_SetEncryptionState
 *   - HAL_PVR_CRYPTO_SetCipherKeys
 *   - HAL_PVR_CRYPTO_SetCipherAlgorithm
 */
DTV_STATUS_T HAL_PVR_CRYPTO_GetCipherKeys(PVR_CIPHER_OPERATION_T cipherOperation, PVR_CRYPTO_TYPE_T *pCryptoInfo);

/**
 * @brief Perform data encryption
 *
 * @rst
 * Description
 *   Encrypt the original TS stream data. The encryption key is set in advance using the HAL_PVR_CRYPTO_SetCipherKeys() API.
 *   The two parameters pDst & pSrc can be called with the same address. (In this case, the encrypted stream is overwritten as it is)
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_CRYPTO_EncryptData(UINT8 *pDst, UINT8 *pSrc, UINT32 size)
 *
 * Parameters
 *   - pDst             [IN/OUT]            Destination pointer to store encrypted stream.
 *   - pSrc             [OUT]               Source address in which the original stream is stored.
 *   - size             [IN]                Size of the input stream array.
 *
 * Return Value
 *   If the function succeeds, the return value is OK.
 *   If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_CRYPTO_EncryptData(UINT8 *pDst, UINT8 *pSrc, UINT32 size)
 *     {
 *         Call the SoC's H/W encryption function to encrypt stream.
 *         IF success THEN
 *             RETURN OK
 *         ELSE
 *             RETURN NOT_OK
 *         ENDIF
 *     }
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *     DTV_STATUS_T     ret;
 *     UINT8 *pSrc, pDst[192];
 *     UINT32 size;
 *
 *     // set pSrc to stream address for encryption
 *     // Set size of the stream
 *
 *     cipherOperation = PVR_CIPHER_OPERATION_ENCRYPT;
 *
 *     ret = HAL_PVR_CRYPTO_EncryptData(pDst, pSrc, size);
 *     if(ret == NOT_OK)
 *     {
 *         printf("Fail to encrypt\n");
 *         return NOT_OK;
 *     }
 * @endrst
 *
 * See Also
 *   - HAL_PVR_SetEncryptionState
 *   - HAL_PVR_CRYPTO_SetCipherKeys
 *   - HAL_PVR_CRYPTO_SetCipherAlgorithm
 *   - HAL_PVR_CRYPTO_DecryptData
 */
DTV_STATUS_T HAL_PVR_CRYPTO_EncryptData(UINT8 *pDst, UINT8 *pSrc, UINT32 size);

/**
 * @brief Perform data decrypt
 *
 * @rst
 * Description
 *   Decrypts encrypted TS stream data. The decryption key is set in advance using the HAL_PVR_CRYPTO_SetCipherKeys() API.
 *   The two parameters pDst & pSrc can be called with the same value (in this case, the decrypted stream is overwritten as it is)
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_CRYPTO_DecryptData(UINT8 *pDst, UINT8 *pSrc, UINT32 size)
 *
 * Parameters
 *   - pDst             [IN/OUT]            Destination pointer to store decrypted(original) stream.
 *   - pSrc             [OUT]               Source address in which the encrypted stream is stored.
 *   - size             [IN]                Size of the input stream array.
 *
 * Return Value
 *   If the function succeeds, the return value is OK.
 *   If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_PVR_CRYPTO_DecryptData(UINT8 *pDst, UINT8 *pSrc, UINT32 size)
 *     {
 *         Call the SoC's H/W decryption function to decrypt stream.
 *         IF success THEN
 *             RETURN OK
 *         ELSE
 *             RETURN NOT_OK
 *         ENDIF
 *     }
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *     DTV_STATUS_T     ret;
 *     UINT8 *pSrc, pDst[192];
 *     UINT32 size;
 *
 *     // set pSrc to stream address for decryption
 *     // Set size of the stream
 *
 *     ret = HAL_PVR_CRYPTO_EncryptData(pDst, pSrc, size);
 *     if(ret == NOT_OK)
 *     {
 *         printf("Fail to decrypt\n");
 *         return NOT_OK;
 *     }
 * @endrst
 *
 * See Also
 *   - HAL_PVR_SetEncryptionState
 *   - HAL_PVR_CRYPTO_SetCipherKeys
 *   - HAL_PVR_CRYPTO_SetCipherAlgorithm
 *   - HAL_PVR_CRYPTO_EncryptData
 */
DTV_STATUS_T HAL_PVR_CRYPTO_DecryptData(UINT8 *pDst, UINT8 *pSrc, UINT32 size);


#endif /* _HAL_PVR_H_ */
