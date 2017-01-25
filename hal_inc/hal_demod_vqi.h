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
#ifndef _HAL_DEMOD_VQI_H_
#define	_HAL_DEMOD_VQI_H_

//#include "demod_kadp.h"  /* to fix compile error in dil/tu/tu_atsc_lg115x.c */
#include "hal_demod_common.h"



/******************************************************************************
	Control Constants
******************************************************************************/


/******************************************************************************
	File Inclusions
******************************************************************************/


//#define	GBB_QV_I2C_ID_DTV 	0XB2	// LGDT1150-VSB/QAM   // jeongpil.yun

/******************************************************************************
 	Constant Definitions
******************************************************************************/
//#define FPGA_DEMOD_TEST

/******************************************************************************
	Macro Definitions
******************************************************************************/
#define GBB_DEMOD_PRINT	FE_PRINT_0
//#define GBB_DEMOD_PRINT	OSA_PRINT //FE_PRINT_0
#define TU_I2C_HANDLE 	TU_HANDLE
#define TU_HANDLE 		UINT32
#define	TU_INVAL_HANDLE			0x00
/******************************************************************************
	Type Definitions
******************************************************************************/
/**
 * GBB RF mode
 */
typedef enum
{
	GBB_AIR_MODE = 0,				///< mode type is air band
	GBB_CABLE_MODE = 1				///< mode type is cable band
} GBB_VQI_MODE_T;

/**
 * GBB Cable channel mode
 */
typedef enum
{
	GBB_STD_BAND = 0,				///< frequency band is STD
	GBB_IRC_BAND,					///< frequency band is IRC
	GBB_HRC_BAND					///< frequency band is HRC
} GBB_VQI_BAND_T;

/**
 * GBB  channel table
 */
typedef struct
{
	UINT8	chanIndex;				///< channel index
	UINT32	freqCenter;				///< center frequency
	UINT8	count;					///< channel count
	UINT16  offset;					///< frequency offset
} GBB_VQI_TABLE_CHANNEL_T;
/*Need check*/
/**
 * structure for strength and quality scaling.
*/
#if 0
typedef struct		// cannot be changed in any other files
{
	UINT8	index;
	UINT8	activeWidth;
	UINT8	oldestValue;
	UINT16	sum;

} TU_SCALE_INFO_T;
/**
 * TU_FLAG.
 */
typedef enum TU_FLAG
{
	TU_FLAG_ON			= 0x30,
	TU_FLAG_OFF,

	TU_FLAG_VALID		= 0x40,
	TU_FLAG_INVALID,

	TU_FLAG_SUCCESS 	= 0x50,
	TU_FLAG_FAIL,

	TU_FLAG_ENABLE		= 0x60,
	TU_FLAG_DISABLE,

	TU_FLAG_START		= 0x90,
	TU_FLAG_ING,
	TU_FLAG_STOP,
	TU_FLAG_FINISH,
	TU_FLAG_COMPLETE,

	TU_FLAG_UNKNOWN 	= 0xF0
} TU_FLAG_T;
typedef struct
{
    /* HANDLE (I2C or CHIP) */
	TU_HANDLE	                   handleDTV;
	TU_HANDLE	                   handleATV;
	TU_HANDLE	                   handlePLL;
	BOOLEAN                        bInitDTV;
	BOOLEAN                        bInitATV;
	BOOLEAN                        bInitPLL;	
                                   
	GBB_VQI_MODE_T                 transMedia;
	HAL_DEMOD_TRANS_SYSTEM_T	   transSystem;
                                   
	HAL_DEMOD_TUNE_MODE_T	 	   tuneMode;
                                   
	UINT8                          unPLP;
	//UINT8                        unGroupID;
	UINT32                         freqTuned;
	UINT32                         freqCenter;
                                   
	UINT32                         analogIF;
	UINT32                         digitalIF;
	HAL_DEMOD_CHANNEL_BW_T 		   channelBW;

	HAL_DEMOD_SPECDATA_VSB_T       specVSBData;
    HAL_DEMOD_SPECDATA_QAM_T       specQAMData;
	BOOLEAN                        bIsSerial;
	BOOLEAN                        bWithCAM;

	BOOLEAN                        bLockStable;
	HAL_DEMOD_LOCK_STATE_T         lockState;

	BOOLEAN                        bSignalStable;
	HAL_DEMOD_SIGNAL_STATE_T       signalState;


	TU_SCALE_INFO_T                scaleInfoStrength;
	TU_SCALE_INFO_T                scaleInfoQuality;

	BOOLEAN                        bMotEnable;
	BOOLEAN                        bLNBVoltageEnable;
	BOOLEAN                        b22KhzOnOff;
} TUNER_INFO_T;
/**
 * DDI Parameter : Set PLL.
 */
typedef struct
{
	HAL_DEMOD_TRANS_SYSTEM_T    transMedia;
	HAL_DEMOD_TUNE_MODE_T       tuneMode;

	HAL_DEMOD_SPECDATA_VSB_T    specVSBData;
	HAL_DEMOD_CHANNEL_BW_T	    channelBW;

	UINT32		frequency;		/* 0 : invalid */
	UINT32		freqCenter; 	/* 0 : invalid */

	BOOLEAN		bIsPIPMode;		// add by seonguk.je
	BOOLEAN		bIsRecMode;		// add by seonguk.je
} TU_PI_SET_PLL_T;
/*Need check*/
#endif
/******************************************************************************
	Function Declaration
******************************************************************************/

extern  UINT32	HAL_DEMOD_VQI_Probe(UINT8  portI2C);
extern  int		HAL_DEMOD_VQI_Initialize(void);
extern  int		HAL_DEMOD_VQI_ChangeTransSystem(HAL_DEMOD_TRANS_SYSTEM_T transSystem);
extern  int  	HAL_DEMOD_VQI_ATSC_SetDemod(HAL_DEMOD_ATSC_SET_PARAM_T paramStruct);
extern  int  	HAL_DEMOD_VQI_ISDBT_SetDemod(HAL_DEMOD_ISDBT_SET_PARAM_T paramStruct);
extern  int		HAL_DEMOD_VQI_VSB_TunePostJob(BOOLEAN *pFinished);
extern  int		HAL_DEMOD_VQI_QAM_TunePostJob(BOOLEAN *pFinished);
extern  int		HAL_DEMOD_VQI_ISDBT_TunePostJob(BOOLEAN *pFinished);
extern 	int 	HAL_DEMOD_VQI_VSB_CheckLock(HAL_DEMOD_LOCK_STATE_T *pLockState);
extern 	int 	HAL_DEMOD_VQI_QAM_CheckLock(HAL_DEMOD_LOCK_STATE_T *pLockState);
extern 	int 	HAL_DEMOD_VQI_ISDBT_CheckLock(HAL_DEMOD_LOCK_STATE_T *pLockState);
extern 	int 	HAL_DEMOD_VQI_QAM_CheckSpecialData(HAL_DEMOD_SPECDATA_QAM_T *pSpecQAM);
extern	int		HAL_DEMOD_VQI_CheckSignalStatus(HAL_DEMOD_SIGNAL_STATE_T *pSignalState);
extern	int 	HAL_DEMOD_VQI_CheckFrequencyOffset(SINT32 *pFreqOffset);
extern 	int 	HAL_DEMOD_VQI_ControlTSMode(BOOLEAN bIsSerial);
extern	int		HAL_DEMOD_VQI_ControlOutput(BOOLEAN bEnableOutput);
extern 	int 	HAL_DEMOD_VQI_DebugMenu(void)
;

extern int HAL_DEMOD_VQI_GetFWVersion(UINT32 *pFWVersion);
extern TU_RETURN_VALUE_T HAL_DEMOD_VQI_GetSQI(UINT8 *pSQI);
extern TU_RETURN_VALUE_T HAL_DEMOD_VQI_GetPacketError(UINT32 *pPacketError);
extern TU_RETURN_VALUE_T HAL_DEMOD_VQI_GetBER(UINT32 *pBER);
extern TU_RETURN_VALUE_T HAL_DEMOD_VQI_GetAGC(UINT32 *pAGC);
extern TU_RETURN_VALUE_T HAL_DEMOD_VQI_GetSNR (UINT32 *pSNR );

#endif /* End of _DEMOD_LG115X_VQI_H_ */
