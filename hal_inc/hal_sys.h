/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2008-2021 by LG Electronics Inc.
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
#define HAL_SYS_VERSION  1

#define PWM_TYPE_NONE    0x0
#define PWM_TYPE_FAN     0x1
#define MAX_PWM_NUM      8

/******************************************************************************
        Macro Definitions
******************************************************************************/

/******************************************************************************
        Type Definitions
******************************************************************************/
typedef struct
{
	unsigned int pwm_type;
	unsigned int period_ns; /* resolution=25Khz --> period=40,000ns */
}HAL_SYS_PWM_CAPABILITY_INFO_T;

/******************************************************************************
        Enum Definitions
******************************************************************************/
typedef enum
{
	SUSPEND_MODE_SNAPSHOT		= 0,	// SNAPSHOT mode
	SUSPEND_MODE_HIBERNATION	= 1,	// HIBERNATION/IBOOT mode
} SUSPEND_MODE_T;

typedef enum
{
	DFT_MEM_TEST_RESULT_OK = 0,
	DFT_MEM_TEST_RESULT_NG = 1,
	DFT_MEM_TEST_RESULT_BUSY = 2,
}DFT_MEM_TEST_RESULT_T;

/******************************************************************************
        Function Declaration
******************************************************************************/
/* Enable/Disable debug port(T32, register tool, debug tool)
 * requester: jeonghyeon.joo
 */
DTV_STATUS_T HAL_SYS_LockDebugPort(BOOLEAN bLock);

/* WOL
 * requester: jaesung5.lee
 */
DTV_STATUS_T HAL_SYS_SetWolOnOff(BOOLEAN bOnOff);
DTV_STATUS_T HAL_SYS_GetWolStatus(BOOLEAN *Status);

/* SUSPEND/RESUME, SIC chip only used
 * requester: donghwan.jung(request for instant boot)
 */
DTV_STATUS_T HAL_SYS_Suspend(SUSPEND_MODE_T syspendMode);
DTV_STATUS_T HAL_SYS_Resume (void);

/* WAKE Up Internal Micom, RTK chip only used
 * requester: kwangseok.kim
 */
DTV_STATUS_T HAL_SYS_WakeUpInternalMicom(void);

/* Read/Write for boot area, MStar chip only used
 * requester: jeonghyeon.joo
 */
DTV_STATUS_T HAL_SYS_ReadBootData(unsigned char *pBootData, unsigned int bootDataSize);
DTV_STATUS_T HAL_SYS_WriteBootData(unsigned char *pBootDataPath, unsigned int bootDataSize);

/* Internal Micom, Mstar chip only used
 * requester: sunghoon.jang
 */
DTV_STATUS_T HAL_SYS_ReadPMData(unsigned char *pPMDataPath, unsigned int PMDataSize);
DTV_STATUS_T HAL_SYS_WritePMData(unsigned char *pPMDataPath, unsigned int PMDataSize);

/* temporary use, Internal Micom, Realtek chip only used
 * requester: jinsuk.her
 */
DTV_STATUS_T HAL_IPC_Write(UINT8 nCmdMode, UINT8 *pCmd, UINT8 nBytes, UINT8 *pBuf, UINT8 retry);
DTV_STATUS_T HAL_IPC_Read(UINT8 nCmdMode, UINT8 *pCmd, UINT8 nBytes, UINT8 *pBuf, UINT8 retry);

/* Check RPMB Partition
 * requester: jongseong.kim
 */
DTV_STATUS_T HAL_SYS_CheckRPMBPartition(void);

/*
 * DDR memory test in DFT process
 * requester: kwangseok.kim
 */
DTV_STATUS_T HAL_SYS_StartDFTMemTest(void);
DFT_MEM_TEST_RESULT_T HAL_SYS_GetDFTMemTestResult(void);

/*
 * PWM
 * requester: kwangseok.kim
 */
DTV_STATUS_T HAL_SYS_GetPWMCapability(unsigned int *pNum_of_pwm, HAL_SYS_PWM_CAPABILITY_INFO_T *pstPWMCapability);
DTV_STATUS_T HAL_SYS_SetPWM(unsigned int pwm_id, unsigned int period_ns, unsigned int duty_ns);
DTV_STATUS_T HAL_SYS_GetPWMData(unsigned int pwm_id, void *pData);

#endif  /* _HAL_SYS_H_ */
