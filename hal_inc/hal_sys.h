/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2008 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.

 *****************************************************************************/

/** @file hal_sys.h
  *
  *  System related header file
  *
  *  @author		kwangseok.kim (kwangseok.kim@lge.com)
  *  @version		 1.0
  *  @date		2017.02.23
  *  @note
  *  @see		hal_sys.c
*/

/******************************************************************************
        Header File Guarder
******************************************************************************/
#ifndef _HAL_SYS_H_
#define _HAL_SYS_H_

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
* DRAM bandwidth  information
*
* @see
*/
typedef struct
{
    UINT32  totalBytes_chA;
    UINT32  percent_chA;                //ratio for how much bandwidth of the channel A is used.
    UINT32  totalBytes_chB;
    UINT32  percent_chB;                //ratio for how much bandwidth of the channel B is used.
    UINT32  totalBytes_chC;
    UINT32  percent_chC;                //ratio for how much bandwidth of the channel C is used.
} DRAM_BW_INFO_T;

/******************************************************************************
        Enum Definitions
******************************************************************************/

/* SPREAD SPECTRUM ENUMERATIONS HAVE TO BE SAME AS KAPI */
typedef enum
{
	SPREAD_SPECTRUM_MODULE_CPU = 0,		// CPU PLL
	SPREAD_SPECTRUM_MODULE_MAIN_0,		// Main PLL 0
	SPREAD_SPECTRUM_MODULE_MAIN_1,		// Main PLL 1
	SPREAD_SPECTRUM_MODULE_MAIN_2,		// Main PLL 2
	SPREAD_SPECTRUM_MODULE_DISPLAY,		// Display PLL
} SPREAD_SPRECTRUM_MODULE_T;

typedef enum
{
	SPREAD_SPECTRUM_OFF = 0,
	SPREAD_SPECTRUM_RATIO_0_25,		// 0.25%
	SPREAD_SPECTRUM_RATIO_0_50,		// 0.50%
	SPREAD_SPECTRUM_RATIO_0_75,		// 0.75%
	SPREAD_SPECTRUM_RATIO_1_00,		// 1.00%
	SPREAD_SPECTRUM_RATIO_1_25,		// 1.25%
	SPREAD_SPECTRUM_RATIO_1_50,		// 1.50%
	SPREAD_SPECTRUM_RATIO_1_75,
} SPREAD_SPECTRUM_RATIO_T;

typedef enum
{
	SUSPEND_MODE_SNAPSHOT		= 0,	// SNAPSHOT mode
	SUSPEND_MODE_HIBERNATION	= 1,	// HIBERNATION/IBOOT mode
} SUSPEND_MODE_T;

/******************************************************************************
        Function Declaration
******************************************************************************/
DTV_STATUS_T HAL_SYS_SetDramBWEnable(BOOLEAN bOnOff);
DTV_STATUS_T HAL_SYS_GetDramBWInfo(DRAM_BW_INFO_T *pstBWInfo);
DTV_STATUS_T HAL_SYS_LockDebugPort(BOOLEAN bLock);
DTV_STATUS_T HAL_SYS_SetSpreadSpectrum(SPREAD_SPRECTRUM_MODULE_T module, SPREAD_SPECTRUM_RATIO_T ratio);

/* WOL */
DTV_STATUS_T HAL_SYS_SetWolOnOff(BOOLEAN bOnOff);
DTV_STATUS_T HAL_SYS_GetWolStatus(BOOLEAN *Status);
DTV_STATUS_T HAL_SYS_InitEthernet(void);//reset PHY
DTV_STATUS_T HAL_SYS_SetWarmWolOnOff(BOOLEAN bOnOff);
DTV_STATUS_T HAL_SYS_GetWarmWolStatus(BOOLEAN *Status);
DTV_STATUS_T HAL_SYS_ResetWol(void);
DTV_STATUS_T HAL_SYS_InitEthernet(void);

/* SUSPEND/RESUME, SIC chip only used */
DTV_STATUS_T HAL_SYS_Suspend(SUSPEND_MODE_T syspendMode);
DTV_STATUS_T HAL_SYS_Resume (void);

/* WAKE Up Internal Micom, RTK chip only used */
DTV_STATUS_T HAL_SYS_WakeUpInternalMicom(void);

/* Internal Micom ?, Mstar chip only used */
DTV_STATUS_T HAL_SYS_ReadBootData(unsigned char *pBootData, unsigned int bootDataSize);
DTV_STATUS_T HAL_SYS_WriteBootData(unsigned char *pBootDataPath, unsigned int bootDataSize);
DTV_STATUS_T HAL_SYS_ReadPMData(unsigned char *pPMDataPath, unsigned int PMDataSize);
DTV_STATUS_T HAL_SYS_WritePMData(unsigned char *pPMDataPath, unsigned int PMDataSize);

#endif  /* _HAL_SYS_H_ */
