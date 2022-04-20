/******************************************************************************
 *   TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2018 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file hal_ecp.h
 *
 * This header file defines the HAL functions related to CI+ ECP
 *
 *  @author     Sunwoong Yoo (sunwoong.yoo@lge.com)
 *  @version    1.0
 *  @date       2018.05.30
 *  @date
 *  @note	    Additional information.
 *  @see
 */

/******************************************************************************
    Header File Guarder
******************************************************************************/
#ifndef	_HAL_ECP_H_
#define	_HAL_ECP_H_

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
/**
* CIPLUS_CRYPTOGRAPHY_T
*
* @see
*/
typedef enum
{
	CIPLUS_CRYPTOGRAPHY_DES 				= 0,
	CIPLUS_CRYPTOGRAPHY_AES 				= 1
} CIPLUS_CRYPTOGRAPHY_T;

/**
* CIPLUS_CHIPHER_KEY
*
* @see
*/
typedef enum
{
	CIPLUS_CIPHER_KEY_EVEN					= 0,
	CIPLUS_CIPHER_KEY_ODD					= 1
} CIPLUS_CIPHER_KEY_T;

/**
* CIPLUS_DECRYPT_KEY_DST_T
*
* @see
*/
typedef enum
{
	CIPLUS_DECRYPT_KEY_DST_SDEC_INPUT_CH_A		= 0x0,
	CIPLUS_DECRYPT_KEY_DST_SDEC_INPUT_CH_B		= 0x1,
	CIPLUS_DECRYPT_KEY_DST_SDEC_INPUT_CH_C		= 0x2,
	CIPLUS_DECRYPT_KEY_DST_SDEC_INPUT_CH_D		= 0x3,
	CIPLUS_DECRYPT_KEY_DST_DEMUX_OUT_CI_CH_0	= 0x10,
	CIPLUS_DECRYPT_KEY_DST_DEMUX_OUT_CI_CH_1	= 0x11,
	CIPLUS_DECRYPT_KEY_DST_DEMUX_OUT_CI_CH_2	= 0x12,
	CIPLUS_DECRYPT_KEY_DST_DEMUX_OUT_CI_CH_3	= 0x13,
	CIPLUS_DECRYPT_KEY_DST_MAX					= 0xff,
} CIPLUS_DECRYPT_KEY_DST_T;
/******************************************************************************
    Function Declaration
******************************************************************************/

/**
 * @brief Initialize ECP driver
 *
 * @rst
 * Functional Requirements
 *  I assumed HAL_ECP_CI_PLUS_Initialize will operate below things,
 *  - In driver level, ECP resource init or preparations for using ECP driver API like HAL_ECP_XXX and ECP_TA_XXX functions.
 *  - If there is no need to ready for using the ECP driver API, then you can make it with empty function.
 *  - HAL_ECP_CI_PLUS_Finalize is the opposite
 *  HAL_ECP_CI_PLUS_Initialize will be called,
 *  1) when CI service is started after boot. This call time is same with legacy HAL_CI_Init.
 *  - This is not related with CAM detection status.
 *  - If TV model supports CI+ ECP, this API will be called after boot.
 *  2) when legacy-broadcast service(=tvservice) respawn by any error.
 *
 * Responses to abnormal situations, including
 *  - If the function success, the return value is OK.
 *  - If the function fails, the return value is NOK.
 *
 * Performance Requirements
 *   NA
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   None
 *
 * Return Value
 *   If success OK, else an one of error in DTV_STATUS_T.
 *
 * Example
 *   NA
 *
 * @endrst
 */
DTV_STATUS_T HAL_ECP_CI_PLUS_Initialize(void);

/**
 * @brief Finalize ECP driver
 *
 * @rst
 * Functional Requirements
 *  HAL_ECP_CI_PLUS_Finalize is the opposite of HAL_ECP_CI_PLUS_Initialize.
 *  - If this API is no need, then you can make it with empty function.
 *
 * Responses to abnormal situations, including
 *  - If the function success, the return value is OK.
 *  - If the function fails, the return value is NOK.
 *
 * Performance Requirements
 *   NA
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   None
 *
 * Return Value
 *   If success OK, else an one of error in DTV_STATUS_T.
 *
 * Example
 *   NA
 *
 * @endrst
 */
DTV_STATUS_T HAL_ECP_CI_PLUS_Finalize(void);

/**
 * @brief Run ECP_TA(Trusted Application) APIs in TEE
 *
 * @rst
 * Functional Requirements
 *  This HAL API is to communicate with ECP_TA based on SoC own TEE system.
 *  HAL_ECP_CA_CI_PLUS_ExecuteTEE is in/out param. So, you need to copy data to shared memory for response data back to the client.
 *
 * Responses to abnormal situations, including
 *  - This function returns the error which is defined by SoC because ECP TA will use the parameter without using this return value
 *  - In other words, SoC can use this return value to check error in SoC own CA interface code
 *  - Share the definition of return value to LG
 *  - For example
 *   .. code-block:: cpp
 *
 *      - If the error type of CA interface code is A(OK case), then return 0
 *      - If the error type of CA interface code is B, then return -1
 *      - If the error type of CA interface code is C, then return -2
 *      - ...
 *
 * Performance Requirements
 *   NA
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *  - When ptr is NULL and size is zero, do NOT handle this to error.
 *  - Because parameter can be set with the value for TA operation of void type.
 *  - Maximum size : 10K
 *   .. code-block:: cpp
 *
 *      func_id  [IN]
 *      ptr      [IN/OUT]
 *      size     [IN]
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *  int HAL_ECP_CA_CI_PLUS_ExecuteTEE ( int func_id, void* ptr, int size )
 *  {
 *    1. Run CA Interface Code to communicate with TA
 *    2. Set Input Parameter
 *    3. Run the TA Operation of ECP_TA_CI_PLUS_ExecuteTEE in TA Library(.a)
 *    4. Set Output Parameter from TA
 *    5. Return the Result
 *        IF the error type of CA interface code is A(OK case) THEN
 *            RETURN 0
 *        ELSE IF the error type of CA interface code is B THEN
 *            RETURN -1
 *        ...
 *        ENDIF
 *  }
 *
 *  void ECP_TA_CI_PLUS_ExecuteTEE ( int func_id, void* ptr, int size )
 *    : This function is in TA Library(.a)
 *
 * @endrst
 */
int HAL_ECP_CA_CI_PLUS_ExecuteTEE(int func_id, void *ptr, int size);

/**
 * @brief Load ECP Key materials
 *
 * @rst
 * Functional Requirements
 *  This API will load the ci_ecp_ssl_pub_key, ci_ecp_key and ci_ecp_dh_key from Sestore to Secure RAM(TEE memory).
 *  This function is called from REE(CI MW).
 *
 *  According to security part, we must use the scrambed key id, not raw id.
 *  - ci_ecp_ssl_pub_key → scrambled ID: 985685EB
 *  - ci_ecp_key         → scrambled ID: D6C0C1CB
 *  - ci_ecp_dh_key      → scrambled ID: E09A6198
 *
 * Responses to abnormal situations, including
 *  - If the function success, the return value is OK.
 *  - If the function fails, the return value is NOK.
 *
 * Performance Requirements
 *   NA
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   None
 *
 * Return Value
 *   If success OK, else an one of error in DTV_STATUS_T.
 *
 * Example
 *   NA
 *
 * @endrst
 */
DTV_STATUS_T HAL_ECP_CI_PLUS_LoadKeyMaterials(void);

/**
 * @brief Load ECP Cert Key
 *
 * @rst
 * Functional Requirements
 *  This API will load the ECP Cert key from Sestore to Secure RAM(TEE memory).
 *  This function is called from REE(CI MW).
 *
 *  According to security part, we must use the scrambed key id, not raw id.
 *  - ci_ecp_cert_key → scrambled ID: 21C97958
 *
 * Responses to abnormal situations, including
 *  - If the function success, the return value is OK.
 *  - If the function fails, the return value is NOK.
 *
 * Performance Requirements
 *   NA
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   None
 *
 * Return Value
 *   If success OK, else an one of error in DTV_STATUS_T.
 *
 * Example
 *   NA
 *
 * @endrst
 */
DTV_STATUS_T HAL_ECP_CI_PLUS_LoadCertKey(void);

/**
 * @brief Write ECP Cert Key
 *
 * @rst
 * Functional Requirements
 *  This API will write the ECP key buffer to Sestore.
 *  This function is called from REE when CI+ ECP Key is downloaded by Key Write Tool in Factory.
 *  This is to save the ci_ecp_cert_key (scrambled ID: 21C97958).
 *
 * Responses to abnormal situations, including
 *  - If the function success, the return value is OK.
 *  - If the function fails, the return value is NOK.
 *
 * Performance Requirements
 *   NA
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pData    [IN]
 *      dataSize [IN]
 *
 * Return Value
 *   If success OK, else an one of error in DTV_STATUS_T.
 *
 * Example
 *   NA
 *
 * @endrst
 */
DTV_STATUS_T HAL_ECP_CI_PLUS_WriteCertKey(UINT8 *pData , int dataSize);

/**
 * @brief Set the cryptograhic mode
 *
 * @rst
 * Functional Requirements
 *  This HAL API is used to set the cryptograhic mode to the SDEC descrambler.
 *  This function is called from REE( CI MW).
 *  In case of cryptographic mode, it no needed to be hidden in secure world.
 *  So, I removed ECP_TA_CI_PLUS_SetCryptographyByChannel.
 *
 * Responses to abnormal situations, including
 *  - If the function success, the return value is OK.
 *  - If the function fails, the return value is NOK.
 *
 * Performance Requirements
 *   NA
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      deviceHandle   [IN]
 *      eDecryptKeyDst [IN]
 *      eCryptography  [IN]
 *
 * Return Value
 *   If success OK, else an one of error in DTV_STATUS_T.
 *
 * Example
 *   NA
 *
 * @endrst
 */
DTV_STATUS_T HAL_ECP_CI_PLUS_SetCryptographyByChannel(SINT32 deviceHandle, CIPLUS_DECRYPT_KEY_DST_T eDecryptKeyDst, CIPLUS_CRYPTOGRAPHY_T eCryptography);

/**
 * @brief Set the CCK key
 *
 * @rst
 * Functional Requirements
 *  This HAL API is used to set the CCK key from secure RAM(TEE memory) to the SDEC descrambler channel.
 *  This function is called from REE( CI MW)
 *
 *  (Added requirement of webOS5.0)
 *  This HAL API will be also used to save the key status to the Secure RAM(TEE memory)
 *   ※ Format of key status : unsigned char keyStatus[eDecryptKeyDst][eCryptography ][eKey]
 *   ※ Setting value : 2. 2 means that new CCK key in the Secure RAM(TEE memory) was indeed set to the SDEC descrambler channel.
 *   .. code-block:: cpp
 *
 *       ex. keyStatus[eDecryptKeyDst = 0,1,...,(N-1)][DES or AES][EVEN or ODD] = 2
 *
 * Responses to abnormal situations, including
 *  - If the function success, the return value is OK.
 *  - If the function fails, the return value is NOK.
 *
 * Performance Requirements
 *   NA
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      deviceHandle   [IN]
 *      eDecryptKeyDst [IN]
 *      eCryptography  [IN]
 *      eKey           [IN]
 *
 * Return Value
 *   If success OK, else an one of error in DTV_STATUS_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      1. (secure world) ECP TA calculates CCK key
 *      2. (secure world) ECP TA calls ECP_TA_CI_PLUS_SetCipherKeysByChannel(eDecryptKeyDst, eCryptography, eKey, pu32CipherKeys)	// (1)CCK is saved to specific Secure RAM(TEE memory) for even or odd. eCryptography is provided because aes/des key size is different. (2)keyStatus[eDecryptKeyDst][eCryptography][eKey] is saved by 1 to specific Secure RAM(TEE memory)
 *      3. (normal world) CI MW calls HAL_ECP_CI_PLUS_SetCryptographyByChannel(deviceHandle, eDecryptKeyDst, eCryptography)  // SDEC set the cryptographic mode
 *      4. (normal world) CI MW calls HAL_ECP_CI_PLUS_SetCipherKeysByChannel(deviceHandle, eDecryptKeyDst, eCryptography, eKey)  // (1)SDEC reads 'even CCK' or 'odd CCK' key from the specific Secure RAM(TEE memory) and set it to SDEC Descrambler. (2)If the CCK key is indeed set to SDEC Descrambler, then SAVE the keyStatus[eDecryptKeyDst][eCryptography][eKey] by 2 to specific Secure RAM(TEE memory)
 *
 * @endrst
 */
DTV_STATUS_T HAL_ECP_CI_PLUS_SetCipherKeysByChannel(SINT32 deviceHandle, CIPLUS_DECRYPT_KEY_DST_T eDecryptKeyDst, CIPLUS_CRYPTOGRAPHY_T eCryptography, CIPLUS_CIPHER_KEY_T eKey);

#endif /* _HAL_ECP_H_ */
