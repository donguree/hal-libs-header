/******************************************************************
 *	 DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *	 Copyright(c) 1999 by LG Electronics Inc.
 *
 *	 All rights reserved. No part of this work may be reproduced, stored in a
 *	 retrieval system, or transmitted by any means without prior written
 *	 permission of LG Electronics Inc.
 ******************************************************************/

/** @file hal_vpq_def.h
 *
 *  soc driver definition header.
 *
 *  @author	ysjun(greenco@lge.com)
 *  @author	Kim, Kyoung-Hoan(dreamerkim@lge.com)
 *  @version	1.0
 *  @date		2007.02.23
 *  @see
 */

#ifndef	_HAL_VPQ_DEF_MSD93XBG_H_
#define	_HAL_VPQ_DEF_MSD93XBG_H_

/******************************************************************
	#include 파일들
	(File Inclusions)
*******************************************************************/

/******************************************************************
	상수 정의
	(Constant Definitions)
*******************************************************************/
#define CHIP_CM_REGION_WHITE	0
#define CHIP_CM_REGION_WHT_BLU	1
#define CHIP_CM_REGION_BLACK	2
#define CHIP_CM_REGION_SKIN		3
#define CHIP_CM_REGION_GRN		4
#define CHIP_CM_REGION_BLU		5
#define CHIP_CM_REGION_RED		6
#define CHIP_CM_REGION_YEL		7
#define CHIP_CM_REGION_MGT		8
#define CHIP_CM_REGION_CYN		9
#define CHIP_CM_REGION_A		10
#define CHIP_CM_REGION_B		11
#define CHIP_CM_REGION_C		12
#define CHIP_CM_REGION_D		13
#define CHIP_CM_REGION_E		14
#define CHIP_CM_REGION_F		15

#define CHIP_CM_TBLPOINT		8
#define CHIP_CM_REGION_MAX		15
#define CHIP_CM_REGION_NUM		(CHIP_CM_REGION_MAX+1)
#define CHIP_CM_DELTANUM		6
#define CHIP_CM_CW_NUM			16
#define CHIP_CM_CW_GAINTB		5

#define PICTURE_CTRL_CONTRAST		0x00000001
#define PICTURE_CTRL_BRIGHTNESS		0x00000002
#define PICTURE_CTRL_SATURATION		0x00000004
#define PICTURE_CTRL_TINT			0x00000008

#define SUPPORT_EXTEND_PQTABLE 1 //Enable after APP supports it

/*******************************************************************
	매크로 함수 정의
	(Macro Definitions)
*******************************************************************/






///// the below is modified by choonghoon.park for hal implementation guide.

/*******************************************************************
   	 형 정의
 	 (Type Definitions)
*******************************************************************/


#define MAX_REG_LIST_NUM	40 // number of register list for edition values from pql coeff table

// Dynamic Clear White
typedef enum
{
	BLUE_SAT_RANGE_MIN = 0,
	BLUE_SAT_RANGE_MAX,
	BLUE_SAT_RANGE_NUM,
} BLUE_SATURATION_RANGE_T;

typedef enum
{
	BLUE_STRETCH_OFF = 0,
	BLUE_STRETCH_MIN,
//	BLUE_STRETCH_MID,
	BLUE_STRETCH_MAX,
	BLUE_STRETCH_NUM,
} BLUE_STRETCH_T;

typedef enum
{
	BLUE_SAT_TH1 = 0,
	BLUE_SAT_TH2,
	BLUE_SAT_NUM,
} BLUE_SATURATION_TH_T;


/**
*	pql data
*	update when pql is initialized
*/
typedef enum
{
	PICTURE_CONTROL_CONTRAST	= 0x00000001,
	PICTURE_CONTROL_BRIGHTNESS	= 0x00000002,
	PICTURE_CONTROL_SATURATION	= 0x00000004,
	PICTURE_CONTROL_TINT		= 0x00000008,
} CHIP_PICTURE_CONTROL_FLAG_T;

/**
*	define Picture Control ( PC )
*/
typedef struct CHIP_PC
{
	CHIP_PICTURE_CONTROL_FLAG_T ePictureControl;
	SINT32 sContrast;
	SINT32 sBrightness;
	SINT32 sSaturation;
	SINT32 sHue;
	SINT16 sDimming;	/* 2007.03.28 ysjun add */
} CHIP_PC_T;


/**
*	input csc (black level)
*/
typedef struct CHIP_CSC_COEFF
{
	UINT8 uEnableCsc;
	UINT8 uCscIndex;
	UINT8 uDLControlIndex;
} CHIP_CSC_COEFF_T;


/**
*	gamut csc
*/
typedef struct CHIP_GAMUT
{
	UINT8 uCurrentSelection; // 0:Color Gamut, 1:xvYCC
	UINT8 *pstGamutCommonTable;
	UINT8 *pstGamutMainTable;
} CHIP_GAMUT_T;

/**
 * CHIP Nr main control parameter type
 */
typedef struct
{
	UINT8 uNrMainCtrlIndex;
	UINT8 *pstNrMainCoeffId;
	UINT8 *pstNrDnrTable;
	UINT8 *pstNrSnrTable;
	UINT8 *pstNrPostsnrTable;
	UINT8 *pstNrUcnrTable;
	UINT8 *pstNrSpfmnrTable;
#if (SUPPORT_EXTEND_PQTABLE)
	// Add
	UINT8 *pstNrPresnrTable;
	UINT8 *pstNrColornrTable;
	UINT8 *pstNrPnrTable;
	UINT8 *pstNrPostccsTable;
	UINT8 *pstNrSpikenrTable;
	//UINT8 *pstNrDmsTable;
	UINT8 *pstNrVipnmrTable;
	UINT8 *pstNrHcoringTable;
	UINT8 *pstNrCdnrareaTable;
	UINT8 *pstNrCdnrgainTable;
	//
#endif
}
CHIP_NR_MAIN_T;

//LG request add temporaly
/**
 * CHIP Nr main control parameter type
 */
typedef struct
{
	UINT8 uNrMainCtrlIndex;
	UINT8 *pstNrMainCoeffId;
	UINT8 *pstNrDnrTable;
	UINT8 *pstNrSnrTable;
	UINT8 *pstNrPostsnrTable;
	UINT8 *pstNrUcnrTable;
	UINT8 *pstNrSpfmnrTable;
	// Add
	UINT8 *pstNrPresnrTable;
	UINT8 *pstNrColornrTable;
	UINT8 *pstNrPnrTable;
	UINT8 *pstNrPostccsTable;
	UINT8 *pstNrSpikenrTable;
	//UINT8 *pstNrDmsTable;
	UINT8 *pstNrVipnmrTable;
	UINT8 *pstNrHcoringTable;
	UINT8 *pstNrCdnrareaTable;
	UINT8 *pstNrCdnrgainTable;
	//
}
CHIP_NR_MAIN01_T;

/**
 * CHIP Mpeg Nr main control parameter type
 */
typedef struct
{
	UINT8 uMpegNrMainCtrlIndex;
	UINT8 *pstMpegNrTable;
	UINT8 *pstNrDmsTable;
}
CHIP_MPEG_NOISE_REDUCTION_T;


/**
 * CHIP Sharpness Edge Enhance parameter type
 */
typedef struct
{
	UINT8 uShpEdgeCtrlIndex;
	UINT8 *pstShpEdgeCoeffId;
	UINT8 *pstShpEdgeTable;
}
CHIP_EDGE_ENHANCE_T;

//LG ask temporaly added
/**
 * CHIP Sharpness main control parameter type
 */
typedef struct
{
	UINT8 uShpMainCtrlIndex;
	UINT8 *pstShpMainCoeffId;
	UINT8 *pstShpMainTable;
	UINT8 *pstShpMainDeringTable;
	UINT8 *pstShpMainCoringTable;
	UINT8 *pstShpMainLtiTable;
	// Add
	UINT8 *pstShpMainCtiTable;
	UINT8 *pstShpMainPeakingTable;
	UINT8 *pstShpMainPeakingadapTable;
	UINT8 *pstShpMainEdgeTable;
	UINT8 *pstShpMainSysldeTable;
	UINT8 *pstShpMainColoradapTable;
	UINT8 *pstShpMainYadpTable;
	UINT8 *pstShpMainScalingTable;
	//
}
CHIP_SHARPNESS_T;


/**
 * CHIP Sharpness main control parameter type
 */
typedef struct
{
	UINT8 uShpMainCtrlIndex;
	UINT8 *pstShpMainCoeffId;
	UINT8 *pstShpMainTable;
	UINT8 *pstShpMainDeringTable;
	UINT8 *pstShpMainCoringTable;
	UINT8 *pstShpMainLtiTable;
#if (SUPPORT_EXTEND_PQTABLE)
	// Add
	UINT8 *pstShpMainCtiTable;
	UINT8 *pstShpMainPeakingTable;
	UINT8 *pstShpMainPeakingadapTable;
	UINT8 *pstShpMainEdgeTable;
	UINT8 *pstShpMainSysldeTable;
	UINT8 *pstShpMainColoradapTable;
	UINT8 *pstShpMainYadpTable;
	UINT8 *pstShpMainScalingTable;
	//
#endif
}
CHIP_SHP_MAIN_T;

/**
*	Super Resolution MAIN Param stucture.
*/
typedef struct
{
	UINT8 uSrCtrlIndex;
	UINT8 *pstSrCoeffId;
	UINT8 *pstSrTable;
}
CHIP_SUPER_RESOLUTION_T;


typedef struct
{
	UINT8 uRegIdx;
	UINT8 uRegMask;
	UINT8 uRangeMax;
	UINT8 uRangeMin;
}
CHIP_REG_LIST_T;


/**
*	Blue Stretch param structure.
*/
typedef struct
{
	UINT16 uSatRegRange[BLUE_SAT_RANGE_NUM];
	UINT8 uTh[BLUE_SAT_NUM];
	CHIP_REG_LIST_T stRegList[MAX_REG_LIST_NUM];
	float fMinGain[BLUE_STRETCH_NUM];
}
CHIP_BLUE_STRETCH_T;

/**
*	dynamic clear white
*/
typedef struct
{
	UINT8 uDynamicWhiteCtrlIndex;
	UINT8 uEzpicContrastValue;
	//FW region
	UINT8 *pstFcFwTable;
}
CHIP_COLOR_WHITE_T;


/**
 *	set fresh color type
 */
typedef struct
{
	UINT8 uFcCtrlIndex;
	UINT16 *pstFcIccRegionTable;
	UINT8 *pstFcIccTable;
	UINT16 *pstFcIhcRegionTable;
	UINT8 *pstFcIhcTable;
	UINT8 *pstFcIbcRegionTable;
	UINT8 *pstFcIbcTable;
}
CHIP_CM_DYNAMIC_COLOR_T;

typedef CHIP_CM_DYNAMIC_COLOR_T 	CHIP_CM_INIT_ADV_COLOR_T

/**
 *	set preferred color type
 */
typedef struct
{
	UINT8 *pstFcIhcTable;
}
CHIP_COLOR_CONTROL_T;

/**
 *	init exp color type
 */
typedef struct
{
	UINT8 uCmCtrlIndex;
	UINT16 *pstCmIccRegionTable;
	UINT16 *pstCmIhcRegionTable;
}
CHIP_CM_INIT_EXP_COLOR_T;

/**
 *	set color menagement type
 */
typedef struct
{
	UINT8 uCmRegionID;		///< region ID
	UINT8 uCmCtrlIndex;		///< region gain
	UINT8 uCmSatMinusGain; ///< Staturation minus gain
	SINT8 sCmSatGainValue;					///< saturation gain
	SINT8 sCmHueGainValue;					///< hue gain
	SINT8 sCmLumGainValue;					///< value gain
}
CHIP_CM_DATA_T;


/**
 *	structure for HAL_VPQ_LED_LDSetDBLUT
 */

typedef struct
{
	UINT32 *pu32Ptr;
	UINT32 u32Size;
} HAL_LED_LUT_INFO;

typedef struct
{
	HAL_LED_LUT_INFO uiOff;
	HAL_LED_LUT_INFO uiLow;
	HAL_LED_LUT_INFO uiMedium;
	HAL_LED_LUT_INFO uiHigh;
} HAL_LED_UI_LUT_INFO_T;

typedef struct
{
	HAL_LED_LUT_INFO sbiHCoef;
	HAL_LED_LUT_INFO sbiVCoef;
	HAL_LED_LUT_INFO lres1TabCoef;
	HAL_LED_LUT_INFO lres5TabCoef;
} HAL_LED_DB_LIGHT_PROFILE_LUT_T;

typedef struct
{
	HAL_LED_UI_LUT_INFO_T upperCurve;
	HAL_LED_UI_LUT_INFO_T lowerCurve;
} HAL_LED_DB_DIMMING_CURVE_LUT_T;

/**
 * LED LUT DB
 */
typedef struct
{
	UINT32 u32LutVersion;
	HAL_LED_LUT_INFO pq_common_lut;
	HAL_LED_LUT_INFO module_lut;
	HAL_LED_LUT_INFO unsharpMask_lut;
	HAL_LED_DB_LIGHT_PROFILE_LUT_T lightProfile_lut;
	HAL_LED_DB_DIMMING_CURVE_LUT_T dimmingCurve_lut;
	HAL_LED_UI_LUT_INFO_T pqUi_lut;
	HAL_LED_UI_LUT_INFO_T pixelCompensation_lut;
} HAL_LED_DB_LUT_T;


/**
 * CHIP Nr main control parameter type
 */
typedef struct
{
        UINT8 uNrMainCtrlIndex;
        UINT8 *pstNrMainCoeffId;
        UINT8 *pstNrDnrTable;
        UINT8 *pstNrSnrTable;
        UINT8 *pstNrPostsnrTable;
        UINT8 *pstNrUcnrTable;
        UINT8 *pstNrSpfmnrTable;
#if (SUPPORT_EXTEND_PQTABLE)
        // Add
        UINT8 *pstNrPresnrTable;
        UINT8 *pstNrColornrTable;
        UINT8 *pstNrPnrTable;
        UINT8 *pstNrPostccsTable;
        UINT8 *pstNrSpikenrTable;
        //UINT8 *pstNrDmsTable;
        UINT8 *pstNrVipnmrTable;
        UINT8 *pstNrHcoringTable;
        UINT8 *pstNrCdnrareaTable;
        UINT8 *pstNrCdnrgainTable;
        //
#endif
}
CHIP_NOISE_REDUCTION_T;

typedef struct {
	UINT8 uNullVal;
} CHIP_DC2P_DYNAMIC_CONTRAST_T;


/******************************************************************************
	Extern 전역변수와 함수 prototype 선언
	(Extern Variables & Function Prototype Declarations)
*******************************************************************/

#endif	/* _HAL_VPQ_DEF_H_ */

