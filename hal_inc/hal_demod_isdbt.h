/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2008 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file hal_demod_isdbt.h
 *
 *  HAL for ISDBT
 *
 *  @author     Mundeok Heo(mundeok.heo@lge.com)
 *  @version    1.0
 *  @date       2017.02.07
 *  @note       HAL Intergration
 *  @see
 */

/******************************************************************************
    Header File Guarder
******************************************************************************/
#ifndef _HAL_DEMOD_ISDB_H_
#define _HAL_DEMOD_ISDB_H_

/******************************************************************************
    Control Constants
******************************************************************************/

/******************************************************************************
    File Inclusions
******************************************************************************/
#include "hal_demod_common.h"

/******************************************************************************
    Constant Definitions
******************************************************************************/

/******************************************************************************
    Macro Definitions
******************************************************************************/
#ifndef __F__
#define	__F__		__FUNCTION__
#endif

#ifndef __L__
#define	__L__		__LINE__
#endif

/******************************************************************************
    Type Definitions
******************************************************************************/

/******************************************************************************
    Function Declaration
******************************************************************************/
extern UINT32 HAL_DEMOD_VQI_ISDBT_Probe(UINT8  portI2C);
extern int HAL_DEMOD_VQI_ISDBT_Initialize(void);
extern int HAL_DEMOD_VQI_ISDBT_ChangeTransSystem(HAL_DEMOD_TRANS_SYSTEM_T transSystem);
extern int HAL_DEMOD_VQI_ISDBT_SetDemod(HAL_DEMOD_ISDBT_SET_PARAM_T paramStruct);
extern int HAL_DEMOD_VQI_ISDBT_TunePostJob(BOOLEAN *pFinished);
extern int HAL_DEMOD_VQI_ISDBT_CheckLock(HAL_DEMOD_LOCK_STATE_T *pLockState);
extern int HAL_DEMOD_VQI_ISDBT_CheckSpecialData(HAL_DEMOD_SPECDATA_ISDBT_T *pSpecISDB);
extern int HAL_DEMOD_VQI_ISDBT_CheckSignalStatus(HAL_DEMOD_SIGNAL_STATE_T *pSignalState);
extern int HAL_DEMOD_VQI_ISDBT_CheckFrequencyOffset(SINT32 *pFreqOffset);
extern int HAL_DEMOD_VQI_ISDBT_ControlTSMode(BOOLEAN bIsSerial);
extern int HAL_DEMOD_VQI_ISDBT_ControlOutput(BOOLEAN bEnableOutput);
extern int HAL_DEMOD_VQI_ISDBT_Monitor(HAL_DEMOD_LOCK_STATE_T *pLockState);
extern int HAL_DEMOD_VQI_ISDBT_GetFWVersion(UINT32 *pFWVersion);
extern int HAL_DEMOD_VQI_ISDBT_GetSQI(UINT8 *pSQI);
extern int HAL_DEMOD_VQI_ISDBT_GetPacketError(UINT32 *pPacketError);
extern int HAL_DEMOD_VQI_ISDBT_GetBER(UINT32 *pBER);
extern int HAL_DEMOD_VQI_ISDBT_GetAGC(UINT32 *pAGC);
extern int HAL_DEMOD_VQI_ISDBT_GetSNR(UINT32 *pSNR);

extern BOOLEAN HAL_DEMOD_GetEmergencyAlertFlagStatus(void);
extern int HAL_DEMOD_ISDBT_DebugMenu(void);

#endif /* End of _HAL_DEMOD_ISDB_H_ */
