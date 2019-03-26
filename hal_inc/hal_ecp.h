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
#include "hal_ci.h"

/******************************************************************************
    Constant Definitions
******************************************************************************/

/******************************************************************************
    Macro Definitions
******************************************************************************/

/******************************************************************************
    Type Definitions
******************************************************************************/

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
