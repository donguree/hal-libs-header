/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2008 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file hal_demod_dtmb.h
 *
 *  HAL for DTMB
 *
 *	@author		Mundeok Heo(mundeok.heo@lge.com)
 *  @version	1.0
 *  @date		2017.02.07
 *  @note		HAL Intergration
 *  @see
 */

/******************************************************************************
	Header File Guarder
******************************************************************************/
#ifndef _HAL_DEMOD_DTMB_H_
#define	_HAL_DEMOD_DTMB_H_

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
#define	__F__		__FUNCTION__
#define	__L__		__LINE__

/******************************************************************************
	Type Definitions
******************************************************************************/

/******************************************************************************
	Function Declaration
******************************************************************************/
extern  UINT32	HAL_DEMOD_VQI_DTMB_Probe(UINT8  portI2C);
extern  int		HAL_DEMOD_VQI_DTMB_Initialize(void);
extern  int		HAL_DEMOD_VQI_DTMB_ChangeTransSystem(HAL_DEMOD_TRANS_SYSTEM_T transSystem);
extern  int  	HAL_DEMOD_VQI_DTMB_SetDemod(HAL_DEMOD_DTMB_SET_PARAM_T paramStruct);
extern  int		HAL_DEMOD_VQI_DTMB_TunePostJob(BOOLEAN *pFinished);
extern 	int 	HAL_DEMOD_VQI_DTMB_CheckLock(HAL_DEMOD_LOCK_STATE_T *pLockState);
extern 	int 	HAL_DEMOD_VQI_DTMB_CheckSpecialData(HAL_DEMOD_SPECDATA_DTMB_T *pSpecDTMB);
extern	int		HAL_DEMOD_VQI_DTMB_CheckSignalStatus(HAL_DEMOD_SIGNAL_STATE_T *pSignalState);
extern	int 	HAL_DEMOD_VQI_DTMB_CheckFrequencyOffset(SINT32 *pFreqOffset);
extern 	int 	HAL_DEMOD_VQI_DTMB_ControlTSMode(BOOLEAN bIsSerial);
extern	int		HAL_DEMOD_VQI_DTMB_ControlOutput(BOOLEAN bEnableOutput);
extern  int     HAL_DEMOD_VQI_DTMB_GetFWVersion(UINT32 *pFWVersion);

extern	int		HAL_DEMOD_DTMB_GetSQI(UINT8 *pSQI); 
extern	int		HAL_DEMOD_DTMB_GetPacketError(UINT32 *pPacketError);
extern	int		HAL_DEMOD_DTMB_GetBER(UINT32 *pBER);
extern	int		HAL_DEMOD_DTMB_GetAGC(UINT32 *pAGC);
extern	int		HAL_DEMOD_DTMB_GetSNR(UINT32 *pSNR);
extern 	int 	HAL_DEMOD_DTMB_DebugMenu(void);

#ifdef __cplusplus
}
#endif
#endif /* End of _HAL_DEMOD_DTMB_H_ */
