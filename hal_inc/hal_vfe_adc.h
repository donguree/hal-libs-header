/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file hal_vfe_adc.h
 *
 *  It is the header file for controling VIDEO function.
 *  The header of VIDEO DDI is controlled by this file.
 *
 *  @author		Ahn, sangwoo(sangwoo.ahn@lge.com)
 *  @version	0.3
 *  @date		2013.03.11
 *  @note
 *  @see		
 */

/*-----------------------------------------------------------------------------
	Header File Guarder
------------------------------------------------------------------------------*/
#ifndef	_HAL_ADC_H_
#define	_HAL_ADC_H_

/*-----------------------------------------------------------------------------
	Control Constants
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
    File Inclusions
------------------------------------------------------------------------------*/
//#include "common.h"
//#include "global_configurations.h"
#include "hal_vsc.h"
#include "hal_common.h"


/*-----------------------------------------------------------------------------
	Constant Definitions
------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
	(Extern Variables & Function Prototype Declarations)
------------------------------------------------------------------------------*/
/**
 * type of adc adjusting.
 *
 * @see DDI Implementation Guide
*/
typedef struct
{
    UINT16  rGain  ;
    UINT16  gGain  ;
    UINT16  bGain  ;
    UINT16  rOffset;
    UINT16  gOffset;
    UINT16  bOffset;

} ADC_CAL_DATA_T;

/**
 * Adjust ADC Calibration Type
 *
 * @see DIL Implementation Guide
*/
typedef enum{
    ADC_CAL_TYPE_OTP      = 0,
    ADC_CAL_TYPE_EXTERNAL    ,
    ADC_CAL_TYPE_INTERNAL    ,
    ADC_CAL_TYPE_USER        ,
    ADC_CAL_TYPE_MAX         ,
}ADC_CAL_TYPE_T;


/**
 * type of adc  input source
*/
typedef enum
{
    ADC_SRC_TYPE_COMP      ,     /**< adc input*/
    ADC_SRC_TYPE_SCART     ,     /**< adc input*/
    ADC_SRC_TYPE_VGA	     ,     /**< adc input*/
    ADC_SRC_TYPE_MAX       ,     /**< adc input*/
}ADC_SRC_TYPE_T;


/**
 * type of adc adjusting.
 *
 * @see DDI Implementation Guide
*/
typedef enum
{
    ADC_PORT_FIRST   = 0,     /**< adc input*/
    ADC_PORT_SECOND     ,     /**< adc input*/
    ADC_PORT_THIRD      ,
    ADC_PORT_MAX        ,     /**< adc input*/
}ADC_PORT_T;


/**
 * Video Window Rect.
 *
 * @see DDI Implementation Guide
*/
typedef struct
{
    ADC_SRC_TYPE_T srcType;
    ADC_PORT_T srcPort;
}ADC_SRC_T;


/**
 * Video Timing Information.
 *
 * @see DDI Implementation Guide
*/
typedef struct
{
   	UINT32       format  ;/**< ... */
	UINT16       hFreq   ;/**< ... */
	UINT16       vFreq   ;/**< ... */
	UINT16       hTotal  ;/**< ... */
	UINT16       vTotal  ;/**< ... */
	UINT16       hPorch  ;/**< ... */
	UINT16       vPorch  ;/**< ... */
	VIDEO_RECT_T active  ;/**< ... */
	UINT16       scanType;/**< ... */
	UINT16       phase   ;/**< ... */
}ADC_TIMING_INFO_T;


typedef struct
{
	UINT32 cgmsAPS               : 4 ;  // Header[6-bits] + {PayLoad + CRC}[14-bits]
										// CGMS-A 2-bits = CGMS20BitsVBI & (BIT6 | BIT7) >> 6
										// APS        2-bits = CGMS20BitsVBI & (BIT8 | BIT9) >> 8
	UINT32 copyRight             : 2 ;  // Copy Right		 	= CopyInfo576i576p >> 0
										// Copy Protection		= CopyInfo576i576p >> 1
	UINT32 PseudosyncColorStripe : 2 ;  // 00:no apps, 01:PSP on,cstripe off, 10:PSP on,2-line cstripe on, 11:PSP on,4-line cstripe on
	UINT32 ACPReserved           : 24;  // not used
}ADC_COPY_PROTECT_T;

typedef enum
{
	ADJ_PC_AUTO = 0,	// PC Auto
	ADJ_PC_H_POS,		// PC H Position
	ADJ_PC_V_POS,		// PC V Position
	ADJ_PC_HV_POS,		
	ADJ_PC_CLOCK,		// PC Clock
	ADJ_PC_PHASE,		// PC Phase
} ADJ_PC_MODE_T;

typedef struct
{
	SINT16	pcHDelay;	   /**< Horizontal Sync Delay value */
	SINT16	pcVDelay;	   /**< Vertical Sync Delay value */
	SINT8	pcClock;		 /**< Clock value */
	UINT8	pcPhase;		 /**< Phase value */
} ADJ_PC_T;
//////////////////////////////////////
// start of video common ddi functions

/*==================      BASIC FUNCTION      =====================*/

DTV_STATUS_T	HAL_VFE_ADC_Initialize(void);
DTV_STATUS_T	HAL_VFE_ADC_Uninitialize(void);
DTV_STATUS_T	HAL_VFE_ADC_Open(void);
DTV_STATUS_T	HAL_VFE_ADC_Close(void);
DTV_STATUS_T	HAL_VFE_ADC_Connect(ADC_SRC_T src);
DTV_STATUS_T	HAL_VFE_ADC_Disconnect(void);




/*==================      SIGNAL Info. FUNCTION      =========================*/

DTV_STATUS_T 	HAL_VFE_ADC_GetTimingInfo(ADC_TIMING_INFO_T *pInfo);




/*==================      CoptyRight FUNCTION      ==========================*/

DTV_STATUS_T 	HAL_VFE_ADC_GetCopyProtect(ADC_COPY_PROTECT_T *pProtectInfo);
DTV_STATUS_T	HAL_VFE_ADC_FlushCopyProtect(void);




/*==================      Calibration FUNCTION      ==========================*/

DTV_STATUS_T	HAL_VFE_ADC_GetCALData(ADC_CAL_DATA_T *pAdcData);
DTV_STATUS_T    HAL_VFE_ADC_SetCALData(ADC_CAL_DATA_T *pAdcData);
DTV_STATUS_T	HAL_VFE_ADC_GetOTPData(ADC_CAL_DATA_T pAdcData[]);
DTV_STATUS_T    HAL_VFE_ADC_AdjustCalibration(ADC_CAL_TYPE_T adcType);
DTV_STATUS_T 	HAL_VFE_ADC_ResetCALData(void);
DTV_STATUS_T  	HAL_VFE_ADC_FastSwitchingMode(BOOLEAN  bEnable);

DTV_STATUS_T 	HAL_VFE_ADC_Resume(void);


/*==================      RGB PC FUNCTION (for Signage TV)     ==========================*/
DTV_STATUS_T  	HAL_VFE_ADC_AdjustPC(ADJ_PC_MODE_T mode, SINT16 value);
DTV_STATUS_T  	HAL_VFE_ADC_AdjustPCAuto(void *pfnAdjustPCAuto);
DTV_STATUS_T  	HAL_VFE_ADC_SetPCResolution(SINT32 remapResolution);
DTV_STATUS_T  	HAL_VFE_ADC_ReadExternalEDID(UINT8 port, UINT8 *pData);
DTV_STATUS_T  	HAL_VFE_ADC_WriteExternalEDID(UINT8 port, UINT8 *pData);

#endif

