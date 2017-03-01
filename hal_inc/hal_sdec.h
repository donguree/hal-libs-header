/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file hal_sdec.h
 *
 *  System Decoder HAL function header file.
 *
 *	@author		Kim, Soon-Tae(iamsoontae@lge.com)
 *  @version	1.0
 *  @date		2007.04.16
 *  @see		hal_sdec.c
 */

#ifndef _HAL_SDEC_H_
#define _HAL_SDEC_H_

/******************************************************************************
 #include 파일들 (File Inclusions)
******************************************************************************/
#include "SDec_Common.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
 	상수 정의(Constant Definitions)
******************************************************************************/

/******************************************************************************
    매크로 함수 정의 (Macro Definitions)
******************************************************************************/

/******************************************************************************
	형 정의 (Type Definitions)
******************************************************************************/

/******************************************************************************
	Extern 전역변수와 함수 prototype 선언
	(Extern Variables & Function Prototype Declarations)
*******************************************************************************/
DTV_STATUS_T HAL_SDEC_Initialize(HAL_SDEC_PLATFORM_T platform, HAL_SDEC_COUNTRY_T country);
DTV_STATUS_T HAL_SDEC_FinalizeModule(void);
DTV_STATUS_T HAL_SDEC_SetInputConfig(SDEC_CHANNEL_T ch, SDEC_INPUT_PORT_T portType, SDEC_INPUT_TYPE_T inputType, SDEC_CAS_TYPE_T casType);
DTV_STATUS_T HAL_SDEC_GetInputConfig(SDEC_CHANNEL_T ch, SDEC_INPUT_PORT_T *pPortType, SDEC_INPUT_TYPE_T *pInputType, SDEC_CAS_TYPE_T *pCasType);
DTV_STATUS_T HAL_SDEC_ResetFilters(SDEC_CHANNEL_T ch, SDEC_CLEANING_SCOPE_T scope);
DTV_STATUS_T HAL_SDEC_SetPID(SDEC_CHANNEL_T ch, SDEC_PID_TYPE_T pidType, UINT16 pid, SDEC_PES_DEST_T dest);
DTV_STATUS_T HAL_SDEC_GetPID(SDEC_CHANNEL_T ch, SDEC_PID_TYPE_T pidType, UINT16 *pPid, SDEC_PES_DEST_T dest);
DTV_STATUS_T HAL_SDEC_RequestSection(SDEC_CHANNEL_T ch, SDEC_SECTION_FILTER_T *pSectionFilter, UINT8 *pSecfIndex, UINT32 gpbSize, pfnSDECDataHandlingCB pfnCallBack);
DTV_STATUS_T HAL_SDEC_CancelSection(	SDEC_CHANNEL_T ch, UINT8 secfIndex);
DTV_STATUS_T HAL_SDEC_CopySectionData(SDEC_CHANNEL_T ch, UINT8 secfIndex, UINT16 pid, UINT8 *pDest, UINT8 *pBufAddr, UINT32 dataSize);
DTV_STATUS_T HAL_SDEC_ReturnSectionBuffer(SDEC_CHANNEL_T ch, UINT8 secfIndex, UINT16 pid, UINT8 *pBufAddr, UINT32 dataSize);
DTV_STATUS_T HAL_SDEC_RequestPES(SDEC_CHANNEL_T ch, SDEC_PID_TYPE_T pidType, UINT16 pesPid, UINT8 *pPesfIndex, UINT32 gpbSize, pfnSDECDataHandlingCB pfnCallBack);
DTV_STATUS_T HAL_SDEC_CancelPES(SDEC_CHANNEL_T ch, UINT8 pesfIndex);
DTV_STATUS_T HAL_SDEC_CopyPESData(SDEC_CHANNEL_T ch, UINT8 pesfIndex, UINT16 pid, UINT8 *pDest, UINT8 *pBufAddr, UINT32 dataSize);
DTV_STATUS_T HAL_SDEC_ReturnPESBuffer(SDEC_CHANNEL_T ch, UINT8 pesfIndex, UINT16 pid, UINT8 *pBufAddr, UINT32 dataSize);
DTV_STATUS_T HAL_SDEC_RequestTS(SDEC_CHANNEL_T ch, UINT16 rawPid, UINT32 bufferSz, pfnSDECDataHandlingCB pfnCallBack);
DTV_STATUS_T HAL_SDEC_CancelTS(SDEC_CHANNEL_T ch, UINT8 filterIndex);
DTV_STATUS_T HAL_SDEC_StartPCRRecovery(SDEC_CHANNEL_T ch);
DTV_STATUS_T HAL_SDEC_StopPCRRecovery(SDEC_CHANNEL_T ch);
DTV_STATUS_T HAL_SDEC_StartScrambleCheck(SDEC_CHANNEL_T ch, SDEC_PID_TYPE_T pidType, UINT16 pid);
DTV_STATUS_T HAL_SDEC_StopScrambleCheck(SDEC_CHANNEL_T ch, SDEC_PID_TYPE_T pidType, UINT16 pid);
DTV_STATUS_T HAL_SDEC_CheckScrambledStatus(SDEC_CHANNEL_T ch, SDEC_PID_TYPE_T pidType, UINT16 pid, UINT8 *bScrambled);
DTV_STATUS_T HAL_SDEC_GetCurSTC(SDEC_CHANNEL_T ch, UINT32 *pStc_hi, UINT32 *pStc_lo);
DTV_STATUS_T HAL_SDEC_SetParam (SDEC_CHANNEL_T ch, HAL_SDEC_PARAM_T param, SINT32 val);
DTV_STATUS_T HAL_SDEC_GetParam (SDEC_CHANNEL_T ch, HAL_SDEC_PARAM_T param, SINT32 *val);

/* 20131101 Descrambler Stub */
DTV_STATUS_T HAL_SDEC_InitDescrambler(SDEC_CHANNEL_T ch, SDEC_DESC_SETTING_T *p_desc_setting);
DTV_STATUS_T HAL_SDEC_SetDescramblerKey(SDEC_CHANNEL_T ch, UINT32 pid_filter_idx, SDEC_DESC_KEY_T key_type, UINT8 *p_key, UINT32 key_size);
DTV_STATUS_T HAL_SDEC_SetXCASDescramblerKey(SDEC_CHANNEL_T ch, UINT32 pid_filter_idx, SDEC_DESC_KEY_T key_type, UINT8 *p_key, UINT32 key_size);
DTV_STATUS_T HAL_SDEC_GetPidFilterIndex(SDEC_CHANNEL_T ch, UINT32 *p_pid_filter_idx, SDEC_PID_TYPE_T pid_type, UINT16 pid, SDEC_PES_DEST_T pes_dest);

/* 20150612 for debug Menu*/
void HAL_SDEC_DebugMenu(void);

#ifdef __cplusplus
}
#endif

#endif  /*_HAL_SDEC_H_ */
