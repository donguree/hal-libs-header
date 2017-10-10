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
 *  hal vpq type definition.
 *
 *  @author	Youngin Choi(youngin.choi@lge.com)
 *  @version	1.0
 *  @date		2017.03.06
 *  @see
 */

#ifndef	_HAL_VPQ_DEF_H_
#define	_HAL_VPQ_DEF_H_

/*******************************************************************
	#include 파일들
	(File Inclusions)
*******************************************************************/

#include "hal_vpq_def_common.h"


/*******************************************************************
	상수 정의
	(Constant Definitions)
*******************************************************************/
#define HAL_VPQ_USE_DOLBY_FUNCTION

/* histogram bin, chroma bin num */
#define HAL_VPQ_BIN_NUM			64
#define HAL_VPQ_C_BIN_NUM		32
#define HAL_VPQ_H_BIN_NUM		32

/* preferred color selection */
#define HAL_VPQ_PREFERRED_SKIN		0
#define HAL_VPQ_PREFERRED_BSKY		1
#define HAL_VPQ_PREFERRED_GRASS		2

/*******************************************************************
	매크로 함수 정의
	(Macro Definitions)
*******************************************************************/

/*******************************************************************
   	 형 정의
 	 (Type Definitions)
*******************************************************************/
/**
*	inner pattern ire enum
*	- should be same with DIL_VPQ_INNER_PATTERN_IRE_T
*/
typedef enum
{
	HAL_VPQ_INNER_PATTERN_IRE_0 = 0,	///< ire 0
	HAL_VPQ_INNER_PATTERN_IRE_5,		///< ire 5
	HAL_VPQ_INNER_PATTERN_IRE_10,		///< ire 10
	HAL_VPQ_INNER_PATTERN_IRE_15,		///< ire 15
	HAL_VPQ_INNER_PATTERN_IRE_20,		///< ire 20
	HAL_VPQ_INNER_PATTERN_IRE_25,		///< ire 25
	HAL_VPQ_INNER_PATTERN_IRE_30,		///< ire 30
	HAL_VPQ_INNER_PATTERN_IRE_35,		///< ire 35
	HAL_VPQ_INNER_PATTERN_IRE_40,		///< ire 40
	HAL_VPQ_INNER_PATTERN_IRE_45,		///< ire 45
	HAL_VPQ_INNER_PATTERN_IRE_50,		///< ire 50
	HAL_VPQ_INNER_PATTERN_IRE_55,		///< ire 55
	HAL_VPQ_INNER_PATTERN_IRE_60,		///< ire 60
	HAL_VPQ_INNER_PATTERN_IRE_65,		///< ire 65
	HAL_VPQ_INNER_PATTERN_IRE_70,		///< ire 70
	HAL_VPQ_INNER_PATTERN_IRE_75,		///< ire 75
	HAL_VPQ_INNER_PATTERN_IRE_80,		///< ire 80
	HAL_VPQ_INNER_PATTERN_IRE_85,		///< ire 85
	HAL_VPQ_INNER_PATTERN_IRE_90,		///< ire 90
	HAL_VPQ_INNER_PATTERN_IRE_95,		///< ire 95
	HAL_VPQ_INNER_PATTERN_IRE_100		///< ire 100
}
HAL_VPQ_INNER_PATTERN_IRE_T;

/**
*	input type enum
*/
typedef enum
{
	HAL_VPQ_INPUT_ATV = 0,			///< analog rf
	HAL_VPQ_INPUT_AV,				///< cvbs,svideo
	HAL_VPQ_INPUT_SCARTRGB,			///< scart-rgb
	HAL_VPQ_INPUT_COMP,				///< component
	HAL_VPQ_INPUT_RGB_PC,			///< rgb-pc
	HAL_VPQ_INPUT_HDMI_TV,			///< hdmi non-pc(hdmi-av,dvi-dtv,mcam)
	HAL_VPQ_INPUT_HDMI_PC,			///< hdmi pc(dvi-pc)
	HAL_VPQ_INPUT_DTV,				///< digital rf
	HAL_VPQ_INPUT_PICWIZ,			///< dtv pic wiz
	HAL_VPQ_INPUT_PICTEST,			///< dtv pic test
	HAL_VPQ_INPUT_MEDIA_MOVIE,		///< divx, cp-divx
	HAL_VPQ_INPUT_MEDIA_PHOTO,		///< photo, cp-photo
	HAL_VPQ_INPUT_CAMERA,			///< vcs
	HAL_VPQ_INPUT_PVR_DTV,			///< pvr dtv
	HAL_VPQ_INPUT_PVR_ATV,			///< pvr atv
	HAL_VPQ_INPUT_PVR_AV,			///< pvr av,scart-rgb
	HAL_VPQ_INPUT_MAX				///< max num
}
HAL_VPQ_INPUT_T;

/**
*	3d mode type enum
*/
typedef enum
{
	HAL_VPQ_3D_MODE_OFF = 0,		///< 3d off, 3d to 2d
	HAL_VPQ_3D_MODE_3D_TB,			///< 3d top and botom
	HAL_VPQ_3D_MODE_3D_SS,			///< 3d side by side
	HAL_VPQ_3D_MODE_3D_CB,			///< 3d checker board
	HAL_VPQ_3D_MODE_3D_FS,			///< 3d frame seq
	HAL_VPQ_3D_MODE_3D_CI,			///< 3d column interleave
	HAL_VPQ_3D_MODE_3D_LIH,			///< 3d line interleave half
	HAL_VPQ_3D_MODE_3D_FP,			///< 3d frame packing
	HAL_VPQ_3D_MODE_3D_FA,			///< 3d field alternative
	HAL_VPQ_3D_MODE_3D_LA,			///< 3d line alternative
	HAL_VPQ_3D_MODE_3D_SSF,			///< 3d side by side full
	HAL_VPQ_3D_MODE_3D_DS,			///< 3d dual stream
	HAL_VPQ_3D_MODE_2DTO3D,			///< 2d to 3d
	HAL_VPQ_3D_MODE_MAX				///< max num
}
HAL_VPQ_3D_MODE_T;

/**
*	dc2p histogram data info
*/
typedef struct
{
	UINT32 apl;								///< apl
	SINT32 min;								///< min
	SINT32 max;								///< max
	SINT32 peak_low;						///< peak low
	SINT32 peak_high;						///< peak high
	UINT32 skin_count;						///< skin count
	UINT32 sat_status;						///< saturation status
	UINT32 diff_sum;						///< diff sum
	UINT32 motion;							///< motion
	UINT32 texture;							///< texture
	UINT32 bin[HAL_VPQ_BIN_NUM];			///< count bin
	UINT32 chrm_bin[HAL_VPQ_C_BIN_NUM];		///< count chroma bin
	UINT32 hue_bin[HAL_VPQ_H_BIN_NUM];		///< count chroma bin
}
HAL_VPQ_DC2P_HISTODATA_INFO_T;

/**
*	color temperature
*/
typedef struct
{
	UINT8 rgb_gain[3];		///< gain. 0:red, 1:green, 2:blue
	UINT8 rgb_offset[3];	///< offset. 0:red, 1:green, 2:blue
}
HAL_VPQ_COLOR_TEMP_T;

/**
*	additional information of color gamut LUT
*/
typedef struct
{
	UINT32 u32Size;
	UINT32 *pu32Data;
} HAL_VPQ_GAMUT_ADD_INFO_T;

/**
*	color gamut LUT
*/
typedef struct
{
	UINT32 u32LutVersion;
	UINT32 u32TotalSectionNum;
	UINT16 *pu16SectionData;
	HAL_VPQ_GAMUT_ADD_INFO_T addInfo;
} HAL_VPQ_GAMUT_LUT_T;

/**
*	COLOR_CORRECTION
*/
typedef struct{
	UINT32 uHueBlend;	///< 0~1023
	UINT32 uSatBlend;	///< 0~1023

	UINT32 uLgainx[8];	//L gain LUT x point
	UINT32 uLgainy[8];	//L gain LUT y point

	UINT32 uSgainx[8];	//S gain LUT x point
	UINT32 uSgainy[8];	//S gain LUT y point
} HAL_VPQ_COLOR_CORRECTION_T;

typedef enum{
	HDRPATH_DEFAULT = 0,	///< not SDR2HDR
	HDRPATH_SDR2HDR = 1,	///< SDR2HDR
} HAL_VPQ_HDRPATH_T;

/**
*	HDR_TONEMA
*/
typedef struct{
	HAL_VPQ_HDRPATH_T hdrpath;
	UINT32 uRdata[66];	///<0~4294967295, 33point x,y data
	UINT32 uGdata[66];	///<0~4294967295, 33point x,y data
	UINT32 uBdata[66];	///<0~4294967295, 33point x,y data
} HAL_VPQ_HDR_TONEMAP_T;

/**
*	VPQ_DATA
*/
typedef struct {
	UINT32 version;		///< version = 0 : wild card(default data)
	UINT32 length;		///< pData Length
	UINT8  wId;			///< 0 : main
	UINT8* pData;		///< pData
} HAL_VPQ_DATA_T;


/**
*	Set Color Temperature
*/

typedef struct
{
     UINT16 uCtRedGain;
     UINT16 uCtGreenGain;
     UINT16 uCtBlueGain;
     UINT16 uCtRedOffset;
     UINT16 uCtGreenOffset;
     UINT16 uCtBlueOffset;
} CHIP_CT_GAIN_OFFSET_T;


/**
  * Set 3D Color Correction
  */
typedef struct
{
	UINT8 blackLevelOnoff;
	UINT8 inputInfo;
} HAL_VPQ_3D_COLOR_CORRECT_T;


/**
*	CM UI DATA
*/
typedef struct {
	UINT8 uColorRegion;
	SINT8 sCmSatGain;
	SINT8 sCmHueGain;
	SINT8 sCmLumGain;
	SINT8 sFreshColor;
} HAL_VPQ_CM_DATA_T;

/**
*	dolby picture menu
*/
typedef enum
{
	HAL_VPQ_DOLBY_BACKLIGHT = 0,		///< backlight
	HAL_VPQ_DOLBY_BRIGHTNESS,			///brightness
	HAL_VPQ_DOLBY_COLOR,			///< color
	HAL_VPQ_DOLBY_CONTRAST,			///< contrast
	HAL_VPQ_DOLBY_PICTURE_MENU_MAX				///< max num
}
HAL_VPQ_DOLBY_PICTURE_MENU_T;


/**
*	dolby picture menu data
*/
typedef struct {
	HAL_VPQ_DOLBY_PICTURE_MENU_T pictureMenu;		///< picture menu
	BOOLEAN  bOnOff;			///< true:on, false:off
	UINT8 uValue;		///< setting value
} HAL_VPQ_DOLBY_PICTURE_DATA_T;


/**
*	set real cinema data
*/
typedef struct
{
    UINT8  uFilmCtrlIndex;
    UINT8  *pstFilmCoeffId;
    UINT8  *pstFilmTable;
}
HAL_VPQ_CHIP_FILM_T;

/**
*      set POD/PCID LUT
*/
typedef struct {
  UINT8 extType;  ///< 0: POD, 1: PCID, 2: NONE
  UINT8 *pExtData; ///< LUT data
  UINT32 extLength; ///< LUT data size

} HAL_VPQ_OD_EXTENSION_T;


/**
*	dolby global dimming delay data
*/

typedef struct
{
    UINT16 uOtt_24;
    UINT16 uOtt_30;
    UINT16 uOtt_50;
    UINT16 uOtt_60;

    UINT16 uHdmi_24;
    UINT16 uHdmi_30;
    UINT16 uHdmi_50;
    UINT16 uHdmi_60;
} HAL_DOLBY_GD_DELAY_T;

typedef struct
{
    HAL_DOLBY_GD_DELAY_T standard_frc_off;
    HAL_DOLBY_GD_DELAY_T standard_frc_on;

    HAL_DOLBY_GD_DELAY_T vivid_frc_off;
    HAL_DOLBY_GD_DELAY_T vivid__frc_on;

    HAL_DOLBY_GD_DELAY_T cinema_home_frc_off;
    HAL_DOLBY_GD_DELAY_T cinema_home_frc_on;

    HAL_DOLBY_GD_DELAY_T cinema_frc_off;
    HAL_DOLBY_GD_DELAY_T cinema_frc_on;

    HAL_DOLBY_GD_DELAY_T game_frc_off;
    HAL_DOLBY_GD_DELAY_T game_frc_on;
} HAL_DOLBY_GD_DELAY_LUT_T;

#endif	/* _HAL_VPQ_DEF_H_ */
