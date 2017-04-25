/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2008 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file hal_demod_analog.h
 *
 *  ATV IC.
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
#ifndef _TU_DEMOD_ANALOG_H_
#define _TU_DEMOD_ANALOG_H_

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
extern DTV_STATUS_T HAL_ADEMOD_Probe(UINT8 portI2C, UINT32 *pHandleI2C);
extern DTV_STATUS_T HAL_ADEMOD_NTSC_Initialize(void);
extern DTV_STATUS_T HAL_ADEMOD_PAL_Initialize(void);
extern DTV_STATUS_T HAL_ADEMOD_ChangeTransMedia(HAL_DEMOD_TRANS_SYSTEM_T transMidia) ;
extern DTV_STATUS_T HAL_ADEMOD_Change_TransMedia(HAL_DEMOD_ANALOG_SET_PARAM_T *pChangeParam);
extern DTV_STATUS_T HAL_ADEMOD_SetDemod(HAL_DEMOD_ANALOG_CONFIG_T *pAnalogParam);
extern DTV_STATUS_T HAL_ADEMOD_TunePostJob(BOOLEAN *pFinished, SINT32 *pOffsetFreq, HAL_DEMOD_LOCK_STATE_T *pLockState);
extern DTV_STATUS_T HAL_ADEMOD_ControlOutput(BOOLEAN bEnableOutput);
extern DTV_STATUS_T HAL_ADEMOD_ATVIsLocked(BOOLEAN *isLocked);
extern DTV_STATUS_T HAL_ADEMOD_GetSignalQulity(UINT32 *pSignalQaulity);
extern DTV_STATUS_T HAL_ADEMOD_CheckLockState(HAL_DEMOD_LOCK_STATE_T *pLockState);
extern DTV_STATUS_T HAL_ADEMOD_SetSpecialData(HAL_DEMOD_AUDIO_SIF_SOUNDSYSTEM_T audioSystem);
extern DTV_STATUS_T HAL_ADEMOD_Handler(HAL_DEMOD_TUNE_MODE_T tune_mode);
extern int HAL_DEMOD_PAL_GetFWVersion(UINT32 *pFWVersion);
extern int HAL_DEMOD_NTSC_GetFWVersion(UINT32 *pFWVersion);
extern void HAL_ADEMOD_DebugMenu(void);


#endif /* End of _TU_DEMOD_ANALOG_H_ */

