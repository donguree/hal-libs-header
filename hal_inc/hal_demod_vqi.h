/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2008 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file hal_demod_vqi.h
 *
 *  HAL for VQI
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
#ifndef _HAL_DEMOD_VQI_H_
#define _HAL_DEMOD_VQI_H_

#ifdef __cplusplus
extern "C"
{
#endif
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

/******************************************************************************
    Type Definitions
******************************************************************************/

/******************************************************************************
    Function Declaration
******************************************************************************/
extern UINT32   HAL_DEMOD_VQI_Probe(UINT8  portI2C);
extern int HAL_DEMOD_VQI_Initialize(void);
extern int HAL_DEMOD_VQI_ChangeTransSystem(HAL_DEMOD_TRANS_SYSTEM_T transSystem);
extern int HAL_DEMOD_VQI_ATSC_SetDemod(HAL_DEMOD_ATSC_SET_PARAM_T paramStruct);
extern int HAL_DEMOD_VQI_VSB_TunePostJob(BOOLEAN *pFinished);
extern int HAL_DEMOD_VQI_QAM_TunePostJob(BOOLEAN *pFinished);
extern int HAL_DEMOD_VQI_VSB_CheckLock(HAL_DEMOD_LOCK_STATE_T *pLockState);
extern int HAL_DEMOD_VQI_QAM_CheckLock(HAL_DEMOD_LOCK_STATE_T *pLockState);
extern int HAL_DEMOD_VQI_QAM_CheckSpecialData(HAL_DEMOD_SPECDATA_QAM_T *pSpecQAM);
extern int HAL_DEMOD_VQI_CheckSignalStatus(HAL_DEMOD_SIGNAL_STATE_T *pSignalState);
extern int HAL_DEMOD_VQI_CheckFrequencyOffset(SINT32 *pFreqOffset);
extern int HAL_DEMOD_VQI_ControlTSMode(BOOLEAN bIsSerial);
extern int HAL_DEMOD_VQI_ControlOutput(BOOLEAN bEnableOutput);
extern int HAL_DEMOD_VQI_Set_Frame_resynchronizaiton(BOOLEAN bEnable);
extern int HAL_DEMOD_VQI_GetFWVersion(UINT32 *pFWVersion);
extern int HAL_DEMOD_VQI_GetSQI(UINT8 *pSQI);
extern int HAL_DEMOD_VQI_GetPacketError(UINT32 *pPacketError);
extern int HAL_DEMOD_VQI_GetBER(UINT32 *pBER);
extern int HAL_DEMOD_VQI_GetAGC(UINT32 *pAGC);
extern int HAL_DEMOD_VQI_GetSNR(UINT32 *pSNR);
extern int HAL_DEMOD_VQI_DebugMenu(void);

#ifdef __cplusplus
}
#endif
#endif /* End of _HAL_DEMOD_VQI_H_ */
