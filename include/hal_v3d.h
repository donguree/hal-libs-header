/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file hal_v3d.h
 *
 *  It is the header file for controling VIDEO 3D function.
 *  The header of VIDEO 3D is controlled by this file.
 *
 *  @author	Lee, Jong-Heon(jongheon.lee@lge.com)
 *  @version	0.1
 *  @date		2015.06.25
 *  @note
 *  @see
 */

/*-----------------------------------------------------------------------------
	Header File Guarder
------------------------------------------------------------------------------*/
#ifndef _HAL_V3D_H_
#define _HAL_V3D_H_

/*-----------------------------------------------------------------------------
	Control Constants
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 	File Inclusions
------------------------------------------------------------------------------*/
#include "hal_common.h"

#ifdef	__cplusplus
	extern "C"
	{
#endif /* __cplusplus */

/*-----------------------------------------------------------------------------
	Constant Definitions
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
	Macro Definitions
------------------------------------------------------------------------------*/
#if !defined(BIT0) && !defined(BIT1)
#define		BIT0		0x00000001
#define		BIT1		0x00000002
#define		BIT2		0x00000004
#define		BIT3		0x00000008
#define		BIT4		0x00000010
#define		BIT5		0x00000020
#define		BIT6		0x00000040
#define		BIT7		0x00000080
#define		BIT8		0x00000100
#endif

/**
 * 3D Video Full Timing Information.
 *
*/
typedef enum
{
	HAL_V3D_FMT_2D = 0,
	HAL_V3D_FMT_TOPNBOTTOM,
	HAL_V3D_FMT_SIDEBYSIDE,
	HAL_V3D_FMT_CHECKERBOARD, 
	HAL_V3D_FMT_FRAMESEQ,
	HAL_V3D_FMT_COLUMN_INTERLEAVE,
	HAL_V3D_FMT_LINE_INTERLEAVE_HALF,
	HAL_V3D_FMT_FRAMEPAC,
	HAL_V3D_FMT_FIELD_ALTERNATIVE,
	HAL_V3D_FMT_LINE_ALTERNATIVE,
	HAL_V3D_FMT_SIDEBYSIDE_FULL,
	HAL_V3D_FMT_DUALSTREAM,
	HAL_V3D_FMT_MAX
} HAL_V3D_FMT_TYPE_T;

/**
 * 3D L/R selection.
 *
 */
typedef enum{
	HAL_V3D_LR_SEQ = 0,
	HAL_V3D_RL_SEQ,
	HAL_V3D_LR_MAX 
} HAL_V3D_LR_SEQ_T;

/**
 * 3D Video Full Timing Information.
 *
*/
typedef enum {
	HAL_V3D_FORMAT_TOP_BOTTOM = BIT0 << 1,
	HAL_V3D_FORMAT_SIDEBYSIDE_HALF = BIT0 << 2,
	HAL_V3D_FORMAT_CHECKER_BOARD = BIT0 << 3,
	HAL_V3D_FORMAT_FRAME_SEQ = BIT0 << 4,
	HAL_V3D_FORMAT_COLUMN_INTERLEAVE = BIT0 << 5,
	HAL_V3D_FORMAT_LINE_INTERLEAVE_HALF = BIT0 << 6,
	HAL_V3D_FORMAT_FRAME_PACKING = BIT0 << 7,
	HAL_V3D_FORMAT_FIELD_ALTERNATIVE = BIT0 << 8,
	HAL_V3D_FORMAT_LINE_ALTERNATIVE = BIT0 << 9,
	HAL_V3D_FORMAT_SIDEBYSIDE_FULL = BIT0 << 10,
	HAL_V3D_FORMAT_DUAL_STREAM = BIT0 << 11,
} HAL_V3D_FORMAT_TYPE_T;

/*-----------------------------------------------------------------------------
	Extern Variables & Function Prototype Declarations
------------------------------------------------------------------------------*/
DTV_STATUS_T HAL_V3D_Initialize(void);
DTV_STATUS_T HAL_V3D_Set3DFMT (VIDEO_WID_T wid, HAL_V3D_FMT_TYPE_T in_fmt, HAL_V3D_FMT_TYPE_T out_fmt);
DTV_STATUS_T HAL_V3D_SetLRSeq(HAL_V3D_LR_SEQ_T type);
DTV_STATUS_T HAL_V3D_CtrlConvergence(SINT8 s8ConvValue);
DTV_STATUS_T HAL_V3D_CtrlDepth(UINT8 u8DepthLevel);
DTV_STATUS_T HAL_V3D_SetAutoConvEnable(BOOLEAN bOnOff);
DTV_STATUS_T HAL_V3D_GetAutoDetectingResult(HAL_V3D_FMT_TYPE_T *pVideo3Dtype);
DTV_STATUS_T HAL_V3D_SetAutoDetectingType(HAL_V3D_FORMAT_TYPE_T mode);

/*-----------------------------------------------------------------------------
	Local Constant Definitions
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
	Local Type Definitions
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
	Global Type Definitions
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
	Global Variables & Function Prototypes Declarations
------------------------------------------------------------------------------*/
 /*-----------------------------------------------------------------------------
	Local Variables & Function Prototypes Declarations
------------------------------------------------------------------------------*/
#ifdef	__cplusplus
	}
#endif /* __cplusplus */

#endif /* _HAL_V3D_H_ */
