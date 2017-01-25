/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2008 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file demod_lg115x_dvb.h
 *
 *  DVB T/C Demod.
 *
 *  @author		Jeongpil Yun(jeongpil.yun@lge.com)
 *  @version	0.1
 *  @date		2010.01.13
 *  @see
 */

/******************************************************************************
	Header File Guarder
******************************************************************************/
#ifndef _HAL_DEMOD_DVB_H_
#define	_HAL_DEMOD_DVB_H_

#include "hal_demod_common.h"

/******************************************************************************
	Control Constants
******************************************************************************/
//#define FPGA_DEMOD_TEST


/******************************************************************************
	File Inclusions
******************************************************************************/



/******************************************************************************
 	Constant Definitions
******************************************************************************/


/******************************************************************************
	Macro Definitions
******************************************************************************/

#define GBB_DEMOD_PRINT FE_PRINT_0
//#define GBB_DEMOD_PRINT OSA_PRINT //FE_PRINT_0
#define DEFINE_SEPARATE_RESET 1

#define	__F__		__FUNCTION__
#define	__L__		__LINE__
/* Nordig SSI Reference Vale */
/* QPSK */
#define GBB_DVB_DVBT_QPSK_1_2_REF			-93 //-81
#define GBB_DVB_DVBT_QPSK_2_3_REF			-91 //-79
#define GBB_DVB_DVBT_QPSK_3_4_REF			-90 //-78
#define GBB_DVB_DVBT_QPSK_5_6_REF			-89 //-77
#define GBB_DVB_DVBT_QPSK_7_8_REF			-88 //-76


/* 16QAM */
#define GBB_DVB_DVBT_16QAM_1_2_REF			-87 //-75
#define GBB_DVB_DVBT_16QAM_2_3_REF			-85 //-73
#define GBB_DVB_DVBT_16QAM_3_4_REF			-84 //-72
#define GBB_DVB_DVBT_16QAM_5_6_REF			-83 //-71
#define GBB_DVB_DVBT_16QAM_7_8_REF			-82 //-70


/* 64QAM */
#define GBB_DVB_DVBT_64QAM_1_2_REF			-82 //-69
#define GBB_DVB_DVBT_64QAM_2_3_REF			-80 //-68
#define GBB_DVB_DVBT_64QAM_3_4_REF			-78 //-66
#define GBB_DVB_DVBT_64QAM_5_6_REF			-77 //-65
#define GBB_DVB_DVBT_64QAM_7_8_REF			-76 //-64


/* DVBC */
#define GBB_DVB_DVBC_16QAM_REF				-77 //-65
#define GBB_DVB_DVBC_32QAM_REF				-77 //-65
#define GBB_DVB_DVBC_64QAM_REF				-77 //-65
#define GBB_DVB_DVBC_128QAM_REF				-72 //-60
#define GBB_DVB_DVBC_256QAM_REF				-72 //-60

#define	GBB_DVB_SIGNAL_VALID_COUNT			5


// unit : need to be modify for MSB1228
#define	GBB_DVB_DVBT_LOCK_DELAY_DEFAULT		1500	// for AGC/SYM Lock
#define	GBB_DVB_DVBT_LOCK_DELAY_OFDM		5000	// for OFDM
#define	GBB_DVB_DVBT_LOCK_DELAY_FEC			5000	// for FEC
#define	GBB_DVB_DVBT_LOCK_DELAY_AUTO		1500	// for Auto Scan
#define GBB_DVB_DVBT_LOCK_DELAY_TPS			5000
#define GBB_DVB_DVBT_LOCK_DELAY_7MHZ		2000	// MSB1228 not support Never for 7MHz


/* DVB-C Lock Time */
#define	GBB_DVB_DVBC_LOCK_DELAY_DEFAULT		2000		// Frame Lock Waiting Lock
#define	GBB_DVB_DVBC_LOCK_DELAY_CONST		800		//2000	// for AGC/SYM Lock
#define	GBB_DVB_DVBC_LOCK_DELAY_TR			3000	// for DVBC
#define	GBB_DVB_DVBC_LOCK_DELAY_AUTO_DETECT	2000	// for AGC/SYM Lock
#define	GBB_DVB_DVBC_LOCK_DELAY_DEMOD		4000	// for DEMOC

/* T2 Lock Time	*/ //add update 0823
#define GBB_DVB_DVBT2_LOCK_DELAY_DEFAULT    3000
#define GBB_DVB_DVBT2_LOCK_DELAY_L1         2000
#define GBB_DVB_DVBT2_LOCK_DELAY_P1         1500	//700		//2000
#define GBB_DVB_DVBT2_LOCK_DELAY_FEC        8000


#define	GBB_DVB_AUTO_BOOSTER_DELAY			300		// XC5000 + MSB1228 Do not use Auto Booster

#define GBB_DVB_DVBC_SCAN_OFFSET_COUNT		3

#define GBB_DVB_DEMOD_LOCK_COUNT			10
#define GBB_DVB_DEMOD_LOCK_DELAY			50 /* msec delay */

/* GBB DVB-C Const. */
#define GBB_DVB_DVBC_CONST_16QAM			0
#define GBB_DVB_DVBC_CONST_32QAM			1
#define GBB_DVB_DVBC_CONST_64QAM			2
#define GBB_DVB_DVBC_CONST_128QAM			3
#define GBB_DVB_DVBC_CONST_256QAM			4


//#define DBG_PRINT printf
/******************************************************************************
	Type Definitions
******************************************************************************/
// DVB Lock State
typedef enum
{
	// =============================================== //
	// ------- these locks are treated as 'locked' when scan mode --------- //
	MSB1228_LOCK_OK			= 0x00,	// 0000 XXXX	// keep the position and value !!!

	MSB1228_LOCK_FEC_LOCK	= 0x10,		// DVB-T
	MSB1228_LOCK_SYNC_LOCK,				// DVB-T
	MSB1228_LOCK_TPS_LOCK,				// DVB-T
	MSB1228_LOCK_OFDM_LOCK,				// DVB-T
	MSB1228_LOCK_DEMOD_LOCK,			// DVB-C
	MSB1228_LOCK_TR_LOCK,				// DVB-C
	MSB1228_LOCK_P1_LOCK,				//DVB-T2
	// =============================================== //

	// =============================================== //
	// ------- these locks are treated as 'not locked' when scan mode ------- //
	MSB1228_LOCK_NOT_LOCKED	= 0x20,		// keep the position and value !!!
	MSB1228_LOCK_UNLOCK,
	MSB1228_LOCK_NEVER_LOCK,
	MSB1228_LOCK_NO_CH,
	MSB1228_LOCK_FOUND_DVBT2,
	// =============================================== //

	MSB1228_LOCK_UNKNOWN		= 0x80,	// 0010 XXXX	// keep the position and value !!!
	MSB1228_LOCK_OTHERS,				// 0010 XXXX	// keep the position and value
	//MSB1228_LOCK_NEVER_LOCK,

	MSB1228_LOCK_MASK			= 0xF0
} MSB1228_LOCK_STATE_T;

// MSB1228 Signal State
typedef enum
{
	// =============================================== //
	MSB1228_POWER_VALID		= 0x00,
	MSB1228_NO_CHANNEL_POWER,
	MSB1228_CHECKING_POWER,
	MSB1228_CHECKING_CCI,
	MSB1228_CCI_VALID,
	MSB1228_CCI_VALID_CHECK_FINISHED,
	MSB1228_SIGNAL_UNKNOWN		= 0x80
	// =============================================== //
} MSB1228_SIGNAL_STATE_T;

typedef enum HAL_DEMOD_DVB_TU_FLAG
{
	HAL_DEMOD_DVB_TU_FLAG_DVBC_AUTO_MODE = 0x10,
	HAL_DEMOD_DVB_TU_FLAG_DVBC_MANUAL_MODE = 0x20,

	HAL_DEMOD_DVB_TU_FLAG_START		= 0x90,
	HAL_DEMOD_DVB_TU_FLAG_ING,
	HAL_DEMOD_DVB_TU_FLAG_STOP,
	HAL_DEMOD_DVB_TU_FLAG_FINISH,

//	TU_FLAG_UNKNOWN 	= 0xF0
} HAL_DEMOD_DVB_TU_FLAG_T;


/**
 * GBB Signal State
*/
typedef enum /*LG1150 Signal State */
{
	// =============================================== //
	GBB_DVB_POWER_VALID		= 0x00,
	GBB_DVB_NO_CHANNEL_POWER,
	GBB_DVB_CHECKING_POWER,
	GBB_DVB_SIGNAL_UNKNOWN		= 0x80
	// =============================================== //
} GBB_DVB_SIGNAL_STATE_T;

/**
 * GBB RF MODE
*/
typedef enum
{
	GBB_DVB_AIR_MODE = 0,
	GBB_DVB_CABLE_MODE = 1
} GBB_DVB_MODE_T;

/**
 * GBB Cable channel MODE
*/
typedef enum
{
	GBB_DVB_STD_BAND = 0,
	GBB_DVB_IRC_BAND,
	GBB_DVB_HRC_BAND
} GBB_DVB_BAND_T;

typedef struct
{
	UINT8	chanIndex;
	UINT32	freqCenter;
	UINT8	count;
	UINT16  offset;
} GBB_DVB_TABLE_CHANNEL_T;

/* oga
*  to know DVBT/DVBC, freq, TC_Tu_status.
*/
typedef struct
{
	// common
	HAL_DEMOD_TRANS_SYSTEM_T			transSystem;
	HAL_DEMOD_TUNE_MODE_T				tuneMode;
	BOOLEAN							bSpectrumInv;
	// DVBT
	HAL_DEMOD_CHANNEL_BW_T 			channelBW;
	BOOLEAN								bProfileHP;
	HAL_DEMOD_TPS_HIERARCHY_T		hierarchy;
	HAL_DEMOD_TPS_CARRIER_MODE_T	carrierMode;
	HAL_DEMOD_TPS_GUARD_INTERVAL_T	guardInterval;
	HAL_DEMOD_TPS_CODERATE_T		codeRate;

	// DVBC
	UINT32								DVBC_tunedFreq;
	UINT16 								symbolRate;
	HAL_DEMOD_TPS_CONSTELLATION_T		constellation;
} HAL_DEMOD_DVB_INFORMATION_T;



/******************************************************************************
	Function Declaration
******************************************************************************/
// 4.0
extern	UINT32	HAL_DEMOD_DVB_Probe( UINT8 portI2C);
// 4.1 Description: Initializes the specific demodulator.
extern	int		HAL_DEMOD_DVB_Initialize(void);
// 4.2 Description: Changes demodulator setting according to transmissi media
extern	int		HAL_DEMOD_DVB_ChangeTransMedia(HAL_DEMOD_TRANS_SYSTEM_T transSystem);
// 4.3-1 Description: Set Demod. with the specified parameters
extern	int		HAL_DEMOD_DVB_DVBT_SetDemod(HAL_DEMOD_DVBT_SET_PARAM_T paramStruct);
// 4.3-2 Description: Set Demod. with the specified parameters
extern  int		HAL_DEMOD_DVB_DVBC_SetDemod(HAL_DEMOD_DVBC_SET_PARAM_T paramStruct);
// 4.4-2  Description: Check the Demod. lock status after demod setting. If signal lock status is valid, set *pFishisd value as true.
extern	int 	HAL_DEMOD_DVB_DVBC_TunePostJob( BOOLEAN *pFinished);
// 4.4-1  Description: Check the Demod. lock status after demod setting. If signal lock status is valid, set *pFishisd value as true.
extern	int 	HAL_DEMOD_DVB_DVBT_TunePostJob( BOOLEAN *pFinished);
// 4.5-1 Description: Check the Demod. Lock state.
extern	int		HAL_DEMOD_DVB_DVBT_CheckLock(HAL_DEMOD_LOCK_STATE_T *pLockState);
// 4.5-2 Description: Check the Demod. Lock state.
extern	int		HAL_DEMOD_DVB_DVBC_CheckLock(HAL_DEMOD_LOCK_STATE_T *pLockState);
// 4.6-1 Description: Check signal state with the specified parameters.
extern	int		HAL_DEMOD_DVB_DVBT_GetSignalState(HAL_DEMOD_SIGNAL_STATE_T *pSignalState);
// 4.6-2 Description: Check signal state with the specified parameters.
extern	int 	HAL_DEMOD_DVB_DVBC_GetSignalState(HAL_DEMOD_SIGNAL_STATE_T *pSignalState);
// 4.7-1 Description: Check Specia Data with the specified parameters.
extern	int		HAL_DEMOD_DVB_DVBT_CheckSpecialData(HAL_DEMOD_SPECDATA_DVBT_T *pSpecDVBT);
// 4.7-2 Description: Check Specia Data with the specified parameters
extern	int		HAL_DEMOD_DVB_DVBC_CheckSpecialData(HAL_DEMOD_SPECDATA_DVBC_T *pSpecDVBC);
// 4.8 Description: Gets frequency offset
extern	int		HAL_DEMOD_DVB_CheckFrequencyOffset(SINT32 *pFreqOffset);
// 4.9
extern 	int		HAL_DEMOD_DVB_GetCellID(UINT16 *pCellID);
// 4.10
extern	int 	HAL_DEMOD_DVB_GetPacketError( UINT32 *pFecPkerr);
// 4.11
extern	int		HAL_DEMOD_DVB_ControlTSMode( BOOLEAN bIsSerial);
// 4.12
extern	int 	HAL_DEMOD_DVB_DebugMenu(void);
// 4.13
extern	int 	HAL_DEMOD_DVB_ControlOutput(BOOLEAN bEnableOutput);
//4.14
extern  int HAL_DEMOD_DVB_DVBT2_ChangePLP(UINT8 unPLP);
//4.15
extern  int HAL_DEMOD_DVB_DVBT2_GetMultiPLPInfo(HAL_MULTI_TS_INFO_T *pPlpInfo);
//4.16
extern  int HAL_DEMOD_DVB_DVBT2_CheckSpecialData(HAL_DEMOD_SPECDATA_DVBT2_T *pSpecDVBT2);
//4.17
extern int HAL_DEMOD_DVB_DVBT2_GetSignalState(HAL_DEMOD_SIGNAL_STATE_T *pSignalState);
//4.18
extern int HAL_DEMOD_DVB_OperMode(HAL_DEMOD_TRANS_SYSTEM_T *pOperMode);
//4.19
extern int HAL_DEMOD_DVB_DVBT2_SetDemod(HAL_DEMOD_DVBT2_SET_PARAM_T paramStruct);
//4.20
extern int HAL_DEMOD_DVB_DVBS_SetDemod(HAL_DEMOD_DVBS_SET_PARAM_T halDVBSParam);
//4.21
extern int HAL_DEMOD_DVB_DVBS_TunePostJob(BOOLEAN *pFinished);
//4.22
extern int HAL_DEMOD_DVB_DVBS2_TunePostJob(BOOLEAN *pFinished);
//4.23
extern int HAL_DEMOD_DVB_DVBS_CheckLock(HAL_DEMOD_LOCK_STATE_T *pLockState);
//4.24
extern int HAL_DEMOD_DVB_DVBS_GetSignalState(HAL_DEMOD_SIGNAL_STATE_T *pSignalState);
//4.25
extern int HAL_DEMOD_DVB_DVBS_CheckSpecialData(HAL_DEMOD_SPECDATA_DVBS_T *pSpecDVBS);

extern int HAL_DEMOD_DVB_PKT_ERR(UINT32 *pPKT_Err_Acu, BOOLEAN bReset);

extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_DVBS_22Khz_Tone (BOOLEAN b22kOn);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_DVBS_Send_Diseqc (UINT8* pCmd, UINT8 u8CmdSize);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_DVBS_Send_Tone_Burst (BOOLEAN bTone1);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_DVBS_BlindScan_Init(UINT32 StartFreqMhz, UINT32 EndFreqMhz);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_DVBS_BlindScan_GetTunerFreq(UINT32 *TunerCenterFreqMhz, UINT32 *TunerCutOffFreqKhz);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_DVBS_BlindScan_NextFreq(BOOLEAN *bBlindScanEnd);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_DVBS_BlindScan_GetStatus(UINT8 *Status, BOOLEAN *bBlindScanLock);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_DVBS_BlindScan_End(void);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_DVBS_BlindScan_GetFoundTP(UINT32 *FreqMhz, UINT32 *SymbolRateKhz);
extern int HAL_DEMOD_DVB_GetFWVersion(UINT32 *pFWVersion);

extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_GetSQI(UINT8 *pSQI);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_DVBS_GetSQI(UINT8 *pSQI);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_GetPacketError(UINT32 *pPacketError);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_DVBS_GetPacketError(UINT32 *pPacketError);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_GetBER(UINT32 *pBER);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_DVBS_GetBER(UINT32 *pBER);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_GetAGC(UINT32 *pAGC);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_DVBS_GetAGC(UINT32 *pAGC);
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_GetSNR (UINT32 *pSNR );
extern TU_RETURN_VALUE_T HAL_DEMOD_DVB_DVBS_GetSNR (UINT32 *pSNR );
#endif /* End of _DEMOD_LG115X_DVB_H_ */

