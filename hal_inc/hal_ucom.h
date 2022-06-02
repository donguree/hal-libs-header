/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/


/** @file ucom_ddi.h
*
*	Internal Micom Interface header file( ONLY for MSTAR(SATURN)platform).
*
*	@author Dong-Jun Lee(athens@lge.com) 	- modifier
*	@author Kun-IL Lee(dreamer@lge.com) 	- modifier
*	@version	1.0
*	@date	  2006.07.08
*	@note
*/

/*---------------------------------------------------------
    (Header File Guarder )
---------------------------------------------------------*/
#ifndef _HAL_UCOM_H_
#define _HAL_UCOM_H_

/*---------------------------------------------------------
    Control »ó¼ö Á¤ÀÇ
    (Control Constants)
---------------------------------------------------------*/

/*---------------------------------------------------------
    #include ÆÄÀÏµé
    (File Inclusions)
---------------------------------------------------------*/
#include "hal_common.h"

/*---------------------------------------------------------
    »ó¼ö Á¤ÀÇ
    (Constant Definitions)
---------------------------------------------------------*/

#define MICOM_SIZE_OF_POWER_ERR_DATA			(15)
#define MICOM_ADDR_OF_POWER_ERR_DATA			(128)

#define MICOM_SIZE_OF_TOUCH_KEY_DATA			(60)
#define MICOM_ADDR_OF_TOUCH_KEY_DATA			(150)

#ifndef CEC_CONTROLLED_BY_CPU
#define CEC_CONTROLLED_BY_CPU
#endif

/*---------------------------------------------------------
    ¸ÅÅ©·Î ÇÔ¼ö Á¤ÀÇ
    (Macro Definitions)
---------------------------------------------------------*/

/*---------------------------------------------------------
    Type Á¤ÀÇ
    (Type Definitions)
---------------------------------------------------------*/

typedef UINT32 (* UCOM_KEY_CALLBACK_T) (UINT8 value, UINT8 repeat );
typedef UINT32 (* UCOM_TV_LINK_CALLBACK_PTR_T) (UINT8* pData );

/*---------------------------------------------------------
    ÇÔ¼ö ¼±¾ð
    (Function Declaration)
---------------------------------------------------------*/

/*=======================================================
	UCOM Interface Function ¼±¾ð (ucom_ddi.c)
=======================================================*/

/**
 * @brief Initialize IR / Local Key process in this function.
 *
 * @rst
 * Parameters
 *   UCOM_KEY_CALLBACK_T pIRCallback, UCOM_KEY_CALLBACK_T pLKCallback
 *
 * Return Values
 *   If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK
 *
 * Pseudocode
 *
 *     DTV_STATUS_T HAL_UCOM_Initialize(UCOM_KEY_CALLBACK_T pIRCallback, UCOM_KEY_CALLBACK_T pLKCallback) {
 *       IF UCOM initialization succeeds THEN
 *         RETURN OK
 *       ELSE
 *         RETURN NOT_OK
 *       ENDIF
 *     }
 *
 * @endrst
 **/
extern DTV_STATUS_T	HAL_UCOM_Initialize( UCOM_KEY_CALLBACK_T pIRCallback, UCOM_KEY_CALLBACK_T pLKCallback);

/**
 * @brief Set Read Command between MainSOC and PM.
 *
 * @rst
 * Parameters
 *   UINT8 cmd UINT16 dataSize UINT8 *pData
 *
 * Return Values
 *   If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK
 *
 * Pseudocode
 *
 *     DTV_STATUS_T HAL_UCOM_ReadCommand(UINT8 cmd, UINT16 dataSize, UINT8 *pData) {
 *       IF UCOM read succeeds THEN
 *	       RETURN OK
 *       ELSE
 *	       RETURN NOT_OK
 *       ENDIF
 *     }
 *
 * @endrst
 **/
extern DTV_STATUS_T	HAL_UCOM_ReadCommand(  UINT8 cmd,   UINT16 dataSize, UINT8 *pData );

/**
 * @brief Set Write Command between MainSOC and PM.
 *
 * @rst
 * Parameters
 *   UINT8 *pCmd UINT16 size
 *
 * Return Values
 *   If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK
 *
 * Pseudocode
 *
 *     DTV_STATUS_T HAL_UCOM_WriteCommand(UINT8 *pCmd, UINT16 size) {
 *       IF UCOM write succeeds THEN
 *	       RETURN OK
 *       ELSE
 *	       RETURN NOT_OK
 *       ENDIF
 *     }
 *
 * @endrst
 **/
extern DTV_STATUS_T	HAL_UCOM_WriteCommand( UINT8 *pCmd, UINT16 size );

#ifdef	CEC_CONTROLLED_BY_CPU
extern	DTV_STATUS_T	HAL_UCOM_ReadCECCommand(UINT8 *pData );
extern	DTV_STATUS_T	HAL_UCOM_ReadCECResult(UINT8 *pData);
extern	DTV_STATUS_T	HAL_UCOM_WriteCECCommand( UINT8 *pCmd);
extern	void        	HAL_UCOM_InitCECModule(void);
extern	UINT16       	HAL_UCOM_ReadCECResponse(void);
#endif

/*	Get KEY(IR & LOCAL) EVENT */
DTV_STATUS_T	HAL_UCOM_GetKeyEvent( UINT32* pEvent, UINT32 timeout );
DTV_STATUS_T	HAL_UCOM_GetIrEvent( UINT32* pEvent, UINT32 timeout );
DTV_STATUS_T	HAL_UCOM_GetLocalKeyEvent( UINT32* pEvent, UINT32 timeout );
DTV_STATUS_T	HAL_UCOM_WakeUpKeyEvent( void );
void HAL_UCOM_SetTouchScanMode( UINT8 bonoff);
void HAL_UCOM_GetTouchScanData( UINT16 *u16ScanData);

/*	TV LINK MODE */
DTV_STATUS_T	HAL_UCOM_EnableTVLinkMode( BOOLEAN bEnabled, UCOM_TV_LINK_CALLBACK_PTR_T pTVLinkCallback );

/*	WB CODE MODE */
DTV_STATUS_T	HAL_UCOM_EnableWBCodeMode( BOOLEAN bEnabled, UCOM_TV_LINK_CALLBACK_PTR_T pWBCodeCallback );

DTV_STATUS_T	HAL_UCOM_GetADC_Value( UINT8 channel,UINT8 *pAdcData );

void HAL_UCOM_PMStop(void);
void HAL_UCOM_PMResume(void);
void HAL_UCOM_PMReset(void);

/**
 * @brief Set Micom & SoC Reset Function.
 *
 * @rst
 * Parameters
 *   None
 *
 * Return Values
 *   None
 *
 * Pseudocode
 *
 *     void HAL_UCOM_WholeChipReset(void) {
 *       // Set PM & SoC Reset Operation Register
 *     }
 *
 * @endrst
 **/
void HAL_UCOM_WholeChipReset(void);

#endif /* #ifndef _HAL_UCOM_H_ */
