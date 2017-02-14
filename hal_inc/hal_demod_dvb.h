/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2008 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file hal_demod_dvb.h
 *
 *  HAL for DVB
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
#ifndef _HAL_DEMOD_DVB_H_
#define	_HAL_DEMOD_DVB_H_

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
//Common
extern	UINT32	HAL_DEMOD_DVB_Probe(UINT8 portI2C);
extern	int		HAL_DEMOD_DVB_Initialize(void);
extern	int		HAL_DEMOD_DVB_ChangeTransMedia(HAL_DEMOD_TRANS_SYSTEM_T transSystem);
extern	int		HAL_DEMOD_DVB_OperMode(HAL_DEMOD_TRANS_SYSTEM_T *pOperMode);
extern	int		HAL_DEMOD_DVB_CheckFrequencyOffset(SINT32 *pFreqOffset);
extern 	int		HAL_DEMOD_DVB_GetCellID(UINT16 *pCellID);
extern	int		HAL_DEMOD_DVB_ControlTSMode(BOOLEAN bIsSerial);
extern	int 	HAL_DEMOD_DVB_ControlOutput(BOOLEAN bEnableOutput);
extern	int 	HAL_DEMOD_DVB_PKT_ERR(UINT32 *pPKT_Err_Acu, BOOLEAN bReset);
extern 	int 	HAL_DEMOD_DVB_GetPacketError(UINT32 *pPacketError);
extern 	int 	HAL_DEMOD_DVB_GetSQI(UINT8 *pSQI);
extern 	int 	HAL_DEMOD_DVB_GetBER(UINT32 *pBER);
extern 	int 	HAL_DEMOD_DVB_GetAGC(UINT32 *pAGC);
extern 	int 	HAL_DEMOD_DVB_GetSNR(UINT32 *pSNR);
extern	int 	HAL_DEMOD_DVB_GetFWVersion(UINT32 *pFWVersion);
extern	int 	HAL_DEMOD_DVB_DebugMenu(void);

//DVB-T/T2
extern	int		HAL_DEMOD_DVB_DVBT_SetDemod(HAL_DEMOD_DVBT_SET_PARAM_T paramStruct);
extern	int		HAL_DEMOD_DVB_DVBT2_SetDemod(HAL_DEMOD_DVBT2_SET_PARAM_T paramStruct);
extern	int 	HAL_DEMOD_DVB_DVBT_TunePostJob(BOOLEAN *pFinished);
extern	int		HAL_DEMOD_DVB_DVBT_CheckLock(HAL_DEMOD_LOCK_STATE_T *pLockState);
extern	int		HAL_DEMOD_DVB_DVBT_GetSignalState(HAL_DEMOD_SIGNAL_STATE_T *pSignalState);
extern	int		HAL_DEMOD_DVB_DVBT2_GetSignalState(HAL_DEMOD_SIGNAL_STATE_T *pSignalState);
extern	int		HAL_DEMOD_DVB_DVBT_CheckSpecialData(HAL_DEMOD_SPECDATA_DVBT_T *pSpecDVBT);
extern  int		HAL_DEMOD_DVB_DVBT2_CheckSpecialData(HAL_DEMOD_SPECDATA_DVBT2_T *pSpecDVBT2);
extern  int		HAL_DEMOD_DVB_DVBT2_ChangePLP(UINT8 unPLP);
extern  int		HAL_DEMOD_DVB_DVBT2_GetMultiPLPInfo(HAL_MULTI_TS_INFO_T *pPlpInfo);

//DVB-C
extern  int		HAL_DEMOD_DVB_DVBC_SetDemod(HAL_DEMOD_DVBC_SET_PARAM_T paramStruct);
extern	int 	HAL_DEMOD_DVB_DVBC_TunePostJob(BOOLEAN *pFinished);
extern	int		HAL_DEMOD_DVB_DVBC_CheckLock(HAL_DEMOD_LOCK_STATE_T *pLockState);
extern	int 	HAL_DEMOD_DVB_DVBC_GetSignalState(HAL_DEMOD_SIGNAL_STATE_T *pSignalState);
extern	int		HAL_DEMOD_DVB_DVBC_CheckSpecialData(HAL_DEMOD_SPECDATA_DVBC_T *pSpecDVBC);

//DVB-S/S2
extern	int		HAL_DEMOD_DVB_DVBS_SetDemod(HAL_DEMOD_DVBS_SET_PARAM_T halDVBSParam);
extern	int		HAL_DEMOD_DVB_DVBS_TunePostJob(BOOLEAN *pFinished);
extern	int		HAL_DEMOD_DVB_DVBS2_TunePostJob(BOOLEAN *pFinished);
extern	int		HAL_DEMOD_DVB_DVBS_CheckLock(HAL_DEMOD_LOCK_STATE_T *pLockState);
extern	int		HAL_DEMOD_DVB_DVBS_GetSignalState(HAL_DEMOD_SIGNAL_STATE_T *pSignalState);
extern	int		HAL_DEMOD_DVB_DVBS_CheckSpecialData(HAL_DEMOD_SPECDATA_DVBS_T *pSpecDVBS);
extern	int		HAL_DEMOD_DVB_DVBS_22Khz_Tone(BOOLEAN b22kOn);
extern	int		HAL_DEMOD_DVB_DVBS_Send_Diseqc(UINT8* pCmd, UINT8 u8CmdSize);
extern	int		HAL_DEMOD_DVB_DVBS_Send_Tone_Burst(BOOLEAN bTone1);
extern	int		HAL_DEMOD_DVB_DVBS_BlindScan_Init(UINT32 StartFreqMhz, UINT32 EndFreqMhz);
extern	int 	HAL_DEMOD_DVB_DVBS_BlindScan_GetTunerFreq(UINT32 *TunerCenterFreqMhz, UINT32 *TunerCutOffFreqKhz);
extern	int 	HAL_DEMOD_DVB_DVBS_BlindScan_NextFreq(BOOLEAN *bBlindScanEnd);
extern	int 	HAL_DEMOD_DVB_DVBS_BlindScan_GetStatus(UINT8 *Status, BOOLEAN *bBlindScanLock);
extern	int 	HAL_DEMOD_DVB_DVBS_BlindScan_End(void);
extern	int 	HAL_DEMOD_DVB_DVBS_BlindScan_GetFoundTP(UINT32 *FreqMhz, UINT32 *SymbolRateKhz);
extern	int 	HAL_DEMOD_DVB_DVBS_GetPacketError(UINT32 *pPacketError);
extern	int 	HAL_DEMOD_DVB_DVBS_GetSQI(UINT8 *pSQI);
extern	int 	HAL_DEMOD_DVB_DVBS_GetBER(UINT32 *pBER);
extern	int 	HAL_DEMOD_DVB_DVBS_GetAGC(UINT32 *pAGC);
extern	int 	HAL_DEMOD_DVB_DVBS_GetSNR(UINT32 *pSNR);

#ifdef __cplusplus
}
#endif
#endif /* End of _DEMOD_LG115X_DVB_H_ */

