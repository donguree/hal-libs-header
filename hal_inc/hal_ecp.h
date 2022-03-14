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
DTV_STATUS_T HAL_ECP_CI_PLUS_Initialize(void);
DTV_STATUS_T HAL_ECP_CI_PLUS_Finalize(void);
int HAL_ECP_CA_CI_PLUS_ExecuteTEE(int func_id, void *ptr, int size);
DTV_STATUS_T HAL_ECP_CI_PLUS_LoadKeyMaterials(void);
DTV_STATUS_T HAL_ECP_CI_PLUS_LoadCertKey(void);
DTV_STATUS_T HAL_ECP_CI_PLUS_WriteCertKey(UINT8 *pData , int dataSize);
DTV_STATUS_T HAL_ECP_CI_PLUS_SetCryptographyByChannel(SINT32 deviceHandle, CIPLUS_DECRYPT_KEY_DST_T eDecryptKeyDst, CIPLUS_CRYPTOGRAPHY_T eCryptography);
DTV_STATUS_T HAL_ECP_CI_PLUS_SetCipherKeysByChannel(SINT32 deviceHandle, CIPLUS_DECRYPT_KEY_DST_T eDecryptKeyDst, CIPLUS_CRYPTOGRAPHY_T eCryptography, CIPLUS_CIPHER_KEY_T eKey);

#endif /* _HAL_ECP_H_ */
