/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2008 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file demod_lg115x_vq.h
 *
 *  Brief description.
 *  Detailed description starts here.
 *
 *  @author		jeongpil.yun(jeongpil.yun@lge.com)
 *  @version	0.1
 *  @date		2010.01.13
 *  @note
 *  @see
 */

/******************************************************************************
	Header File Guarder
******************************************************************************/
#ifndef _HAL_DEMOD_ISDB_H_
#define	_HAL_DEMOD_ISDB_H_

#include "hal_demod_common.h"



/******************************************************************************
	Control Constants
******************************************************************************/


/******************************************************************************
	File Inclusions
******************************************************************************/




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
/*typedef enum HAL_DEMOD_ISDB_TU_FLAG
{
	HAL_DEMOD_ISDB_TU_FLAG_START    = 0x90,
	HAL_DEMOD_ISDB_TU_FLAG_ING,
	HAL_DEMOD_ISDB_TU_FLAG_STOP,
	HAL_DEMOD_ISDB_TU_FLAG_FINISH,

	TU_FLAG_UNKNOWN 	= 0xF0
} HAL_DEMOD_ISDB_TU_FLAG_T;*/
/**
 * structure for strength and quality scaling.
*/

/******************************************************************************
	Function Declaration
******************************************************************************/
extern  UINT32	HAL_DEMOD_VQI_ISDBT_Probe(UINT8  portI2C);
extern  int		HAL_DEMOD_VQI_ISDBT_Initialize(void);
extern  int		HAL_DEMOD_VQI_ISDBT_ChangeTransSystem(HAL_DEMOD_TRANS_SYSTEM_T transSystem);
extern  int  	HAL_DEMOD_VQI_ISDBT_SetDemod(HAL_DEMOD_ISDBT_SET_PARAM_T paramStruct);
extern  int		HAL_DEMOD_VQI_ISDBT_TunePostJob(BOOLEAN *pFinished);
extern 	int 	HAL_DEMOD_VQI_ISDBT_CheckLock(HAL_DEMOD_LOCK_STATE_T *pLockState);
extern 	int 	HAL_DEMOD_VQI_ISDBT_CheckSpecialData(HAL_DEMOD_SPECDATA_ISDBT_T *pSpecISDB);
extern	int		HAL_DEMOD_VQI_ISDBT_CheckSignalStatus(HAL_DEMOD_SIGNAL_STATE_T *pSignalState);
extern	int 	HAL_DEMOD_VQI_ISDBT_CheckFrequencyOffset(SINT32 *pFreqOffset);
extern 	int 	HAL_DEMOD_VQI_ISDBT_ControlTSMode(BOOLEAN bIsSerial);
extern	int		HAL_DEMOD_VQI_ISDBT_ControlOutput(BOOLEAN bEnableOutput);
extern  int	  HAL_DEMOD_VQI_ISDBT_Monitor(HAL_DEMOD_LOCK_STATE_T *pLockState);
extern  int   HAL_DEMOD_VQI_ISDBT_GetFWVersion(UINT32 *pFWVersion);
extern 	int 	HAL_DEMOD_ISDBT_DebugMenu(void);

extern TU_RETURN_VALUE_T HAL_DEMOD_VQI_ISDBT_GetSQI(UINT8 *pSQI);
extern TU_RETURN_VALUE_T HAL_DEMOD_VQI_ISDBT_GetPacketError(UINT32 *pPacketError);
extern TU_RETURN_VALUE_T HAL_DEMOD_VQI_ISDBT_GetBER(UINT32 *pBER);
extern TU_RETURN_VALUE_T HAL_DEMOD_VQI_ISDBT_GetAGC(UINT32 *pAGC);
extern TU_RETURN_VALUE_T HAL_DEMOD_VQI_ISDBT_GetSNR (UINT32 *pSNR );
extern BOOLEAN HAL_DEMOD_GetEmergencyAlertFlagStatus(void);

#endif /* End of _DEMOD_LG115X_ISDB_H_ */
