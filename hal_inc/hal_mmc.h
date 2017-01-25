/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/


/** @file hal_mmc.h
 *
 *  EMMC related header file
 *
 *  @author	Kwangseok Kim (kwangseok.kim@lge.com)
 *  @version	1.0
 *  @date		2012.10.15
 *  @note
 *  @see		hal_mmc.c
 */

/******************************************************************************
 	Header File Guarder
******************************************************************************/
#ifndef _hal_mmc_h_
#define _hal_mmc_h_

/******************************************************************************
	#include 파일들 (File Inclusions)
******************************************************************************/
#include "hal_common.h"

/******************************************************************************
 	상수 정의(Constant Definitions)
******************************************************************************/
typedef enum {
REGISTER_ECSD = 0,
REGISTER_CSD = 1,
REGISTER_CID = 2,
}MMC_REGISTER_TYPE_T;

/******************************************************************************
    매크로 함수 정의 (Macro Definitions)
******************************************************************************/

/******************************************************************************
	형 정의 (Type Definitions)
******************************************************************************/

/******************************************************************************
	함수 선언 (Function Declaration)
******************************************************************************/

DTV_STATUS_T HAL_MMC_Open(void);
DTV_STATUS_T HAL_MMC_Close(void);
DTV_STATUS_T HAL_MMC_PON_Short(void);
DTV_STATUS_T HAL_MMC_PON_Long(void);
DTV_STATUS_T HAL_MMC_Get_CID(unsigned char *buff);
DTV_STATUS_T HAL_MMC_Get_SMART_Report(unsigned char *buff, unsigned int *len);
DTV_STATUS_T HAL_MMC_Get_Register(MMC_REGISTER_TYPE_T mmcRegisterType, unsigned char* buff);

#endif  /* _hal_mmc.h_ */

