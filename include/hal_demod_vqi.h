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
extern  int 	HAL_DEMOD_VQI_ISDBT_CheckSpecialData(HAL_DEMOD_SPECDATA_ISDBT_T *pSpecISDBT);
extern	int		HAL_DEMOD_VQI_CheckSignalStatus(HAL_DEMOD_SIGNAL_STATE_T *pSignalState);
extern	int 	HAL_DEMOD_VQI_CheckFrequencyOffset(SINT32 *pFreqOffset);
extern 	int 	HAL_DEMOD_VQI_ControlTSMode(BOOLEAN bIsSerial);
extern	int		HAL_DEMOD_VQI_ControlOutput(BOOLEAN bEnableOutput);
extern  int 	HAL_DEMOD_VQI_Set_Frame_resynchronizaiton(BOOLEAN bEnable);
extern 	int 	HAL_DEMOD_VQI_DebugMenu(void)
;
#endif /* End of _DEMOD_LG115X_VQI_H_ */
