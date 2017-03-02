/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file 		hal_ci.h
 *
 *  header of Common Interface DDI Fuction.
 *
 *
 *  @author		hwajeong.lee
 *  @author
 *  @version	1.0
 *  @date		2007.5.1
 *  @date
 *  @note		Additional information.
 *  @see
 */

/******************************************************************************
 	Header File Guarder
******************************************************************************/
#ifndef _CI_CIPLUS_14_HAL_H_
#define _CI_CIPLUS_14_HAL_H_

/******************************************************************************
    전역 제어 상수(Control Constants)
******************************************************************************/

/******************************************************************************
	#include 파일들 (File Inclusions)
******************************************************************************/
#include "hal_common.h"
#include "SDec_Common.h"

/******************************************************************************
 	상수 정의(Constant Definitions)
******************************************************************************/

/******************************************************************************
    매크로 함수 정의 (Macro Definitions)
******************************************************************************/


/******************************************************************************
	형 정의 (Type Definitions)
******************************************************************************/

/* Newly introduced CI Plus 1.4 enum */

typedef enum
{
	CI_CH_0 = 0x0,
	CI_CH_1 = 0x1,
	CI_CH_2 = 0x2,
	CI_CH_MAX = 0x3,
} CI_CH_T;

typedef void (*PFN_CIPLUS_EVENT_CB)(UINT16 *pValue);
typedef struct CIPLUS_EVENT_HANDLER_INFO
{
	CI_CH_T						muxInputCh;
	UINT16						underflowThreshold;
	UINT16						overflowThreshold;
	PFN_CIPLUS_EVENT_CB			pfnUnderflowHandler;
	PFN_CIPLUS_EVENT_CB			pfnOverflowHandler;
} CIPLUS_EVENT_HANDLER_INFO_T;

typedef enum
{
	CIPLUS_INPUT_MULTI = 0x00,
	CIPLUS_INPUT_IP_SINGLE = 0x01,
	CIPLUS_INPUT_IP_BYPASS = 0x02,
	CIPLUS_INPUT_RF_SINGLE = 0x03,
	CIPLUS_INPUT_RF_BYPASS = 0x04,
} CIPLUS_INPUT_MODE_T;

/******************************************************************************
	함수 선언 (Function Declaration)
******************************************************************************/

int HAL_CI_PLUS14_GetUploadBuf(CI_CH_T ch, UINT8 **ppPushBuffer, UINT32 *pushSize);
int HAL_CI_PLUS14_PushUploadBuf(CI_CH_T ch, UINT8 *pPushBuffer, UINT32 pushSize);
DTV_STATUS_T HAL_CI_PLUS14_StartSendingDataToMuxInput(CI_CH_T ch);
DTV_STATUS_T HAL_CI_PLUS14_StopSendingDataToMuxInput(CI_CH_T ch);
DTV_STATUS_T HAL_CI_PLUS14_ResetUploadBuf(CI_CH_T ch);

DTV_STATUS_T HAL_CI_PLUS14_SetDownloadMode(CI_CH_T ch, BOOLEAN bSample);

int HAL_CI_PLUS14_GetDownloadBuf(CI_CH_T ch, UINT8 **streamRdPtr, UINT8 **streamWrPtr);
int HAL_CI_PLUS14_ReturnDownloadBuf(CI_CH_T ch, UINT8 *streamRdPtr, UINT8 *streamWrPtr);
DTV_STATUS_T HAL_CI_PLUS14_StartReceivingDataFromDeMuxOutput(CI_CH_T ch);
DTV_STATUS_T HAL_CI_PLUS14_StopReceivingDataFromDeMuxOutput (CI_CH_T ch);
DTV_STATUS_T HAL_CI_PLUS14_ResetDownloadBuf(CI_CH_T ch);

DTV_STATUS_T HAL_CI_PLUS14_RegisterUploadEventHandler(CIPLUS_EVENT_HANDLER_INFO_T *pEventHandle);
DTV_STATUS_T HAL_CI_PLUS14_RegisterDownloadEventHandler(CIPLUS_EVENT_HANDLER_INFO_T *pEventHandle);

DTV_STATUS_T HAL_CI_PLUS14_GetUploadBufInfo(CI_CH_T ch, UINT8 **upBufAddr, UINT32 *upBufSize);
DTV_STATUS_T HAL_CI_PLUS14_GetDownloadBufInfo(CI_CH_T ch, UINT8 **ppBufAddr, UINT32 *bufSize);

DTV_STATUS_T HAL_CI_PLUS14_SetCIPLUS14Config(SDEC_INPUT_PORT_T inputPort, CI_CH_T ch,
											SDEC_CHANNEL_T sdec_ch);

DTV_STATUS_T HAL_CI_PLUS14_AddPIDsOnPIDFilter(CI_CH_T ch, UINT8 numOfPids, UINT16* pids);
DTV_STATUS_T HAL_CI_PLUS14_RemovePIDsFromPIDFilter(CI_CH_T ch, UINT8 numOfPids, UINT16* pids);
DTV_STATUS_T HAL_CI_PLUS14_RemoveAllPIDsFromPIDFilter(CI_CH_T ch);

DTV_STATUS_T HAL_CI_PLUS14_GetCICAMInOutBitRate(UINT32 *pMuxOutputBps, UINT32 *pDeMuxInputBps);
DTV_STATUS_T HAL_CI_PLUS14_GetAllPIDsFromPIDFilter(CI_CH_T muxInputCh, UINT8 *numOfPIDs, UINT16 **ppPIDs);
#endif /*_CI_CIPLUS_14_HAL_H_ */

