/******************************************************************************
 *   TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2013 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file		hal_drm.h
 *
 *  Hardware Abstration Layer for DRM
 *
 *  @author		Yujin, Lee (yujin.lee@lge.com)
 *  @version	1.0
 *  @date		2013.03.04
 *  @note
 *  @see
 */

/******************************************************************************
    Header File Guarder
******************************************************************************/
#ifndef	_HAL_DRM_H_
#define	_HAL_DRM_H_

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

/******************************************************************************
    Function Declaration
******************************************************************************/
DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength);
DTV_STATUS_T HAL_DRM_SetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 length);
DTV_STATUS_T HAL_DRM_DeleteSecureData (SINT8 *pDataPath);
DTV_STATUS_T HAL_DRM_GetHWRandomData (UINT8 *pData, UINT32 digit);
DTV_STATUS_T HAL_DRM_GetSecureClock (UINT64 *pSecureClock);
DTV_STATUS_T HAL_DRM_SetSecureClock (UINT64 secureClock);
DTV_STATUS_T HAL_DRM_GetClearDataLength (SINT8 *pDataPath, UINT32 *pLength);
DTV_STATUS_T HAL_DRM_AESHWInit (SINT32 mode, UINT8 *pKey, UINT8 *pIV, SINT32 operation, SINT32 isPadding);
DTV_STATUS_T HAL_DRM_AESHWUpdate (UINT8 *pOutData, UINT32 *pOutDataSize, UINT8 *pInData, UINT32 nInDataSize);
DTV_STATUS_T HAL_DRM_AESHWFinish (UINT8 *pOutData, UINT32 *pOutDataSize);
DTV_STATUS_T HAL_DRM_GetHWID(UINT8 *pOutData, UINT32 *pOutDataSize);
DTV_STATUS_T HAL_DRM_IsSecureDataExist(SINT8 *pDataPath);
DTV_STATUS_T HAL_DRM_InitDrv(void);
DTV_STATUS_T HAL_DRM_JPMARLIN_CheckSecretData(SINT32 secretDataType);
DTV_STATUS_T HAL_DRM_JPMARLIN_WriteSecretData(SINT32 secretDataType,
	                                      UINT8 *pRootCert, SINT32 rootCertLen, UINT8 *pCaCert, SINT32 caCertLen,
	                                      UINT8 *pClientCert, SINT32 clientCertLen, UINT8 *pClientKey, SINT32 clientKeyLen);
DTV_STATUS_T HAL_DRM_GetSecureDataProtected(SINT8 *pID, UINT8 *pData, UINT32 *pLength);
DTV_STATUS_T HAL_DRM_WriteWidevineKeyBox(UINT8 *pData, SINT32 dataLength);
DTV_STATUS_T HAL_DRM_GetWidevineDeviceID(UINT8 *pDeviceID,  SINT32 *pIdLength);

// UHDCP(CAS PROTECTION)
DTV_STATUS_T HAL_DRM_UHDCP_SetCW(UINT8 *KID, UINT8 *CW);
DTV_STATUS_T HAL_DRM_UHDCP_Decrypt(UINT8 *pData, UINT32 data_size,
                                   UINT8 *pIV, UINT8 *pKID, ULONG block_offset, UINT16 byte_offset);

DTV_STATUS_T HAL_DRM_HDMI_SetSecureDataforHDCP22(SINT8 *KeyID, UINT8 *pData, UINT32 DataLength);
DTV_STATUS_T HAL_DRM_HDMI_GetSecureDataforHDCP22(SINT8 *KeyID, UINT8 *pData);
DTV_STATUS_T HAL_DRM_VerifyHDCP22forHDMI(void);

#endif /* _HAL_DRM_H_ */

