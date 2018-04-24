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

/******************************************************************************
        Enum Definitions
******************************************************************************/

typedef enum
{
	SUSPEND_MODE_SNAPSHOT		= 0,	// SNAPSHOT mode
	SUSPEND_MODE_HIBERNATION	= 1,	// HIBERNATION/IBOOT mode
} SUSPEND_MODE_T;

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

#endif  /* _HAL_SYS_H_ */
