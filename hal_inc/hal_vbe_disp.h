/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file hal_dil_vbe_disp.h
 *
 *  It is the header file for controling VBE function.
 *  The header of VBE DIL is controlled by this file.
 *
 *  @author	sungjun.gi(sungjun.gi@lge.com)
 *  @version	1.0
 *  @date	2017.02.20
 *  @note
 *  @see
 */

/*-----------------------------------------------------------------------------
	Header File Guarder
------------------------------------------------------------------------------*/
#ifndef _HAL_VBE_DISP_H_
#define _HAL_VBE_DISP_H_

/*-----------------------------------------------------------------------------
	Control Constants
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 	File Inclusions
------------------------------------------------------------------------------*/
#include "hal_common.h"


/*-----------------------------------------------------------------------------
	Constant Definitions
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
	Macro Definitions
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
	Extern Variables & Function Prototype Declarations
------------------------------------------------------------------------------*/

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
	Static Variables & Function Prototypes Declarations
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
	Global Variables & Function Prototypes Declarations
------------------------------------------------------------------------------*/

/**
 * Panel Inch related with Tool OPT
*/
typedef enum {
	DISP_PANEL_INCH_22 = 0,
	DISP_PANEL_INCH_23,
	DISP_PANEL_INCH_24,
	DISP_PANEL_INCH_26,
	DISP_PANEL_INCH_27,
	DISP_PANEL_INCH_28,
	DISP_PANEL_INCH_32,
	DISP_PANEL_INCH_39,
	DISP_PANEL_INCH_40,
	DISP_PANEL_INCH_42,
	DISP_PANEL_INCH_43,
	DISP_PANEL_INCH_47,
	DISP_PANEL_INCH_49,
	DISP_PANEL_INCH_50,
	DISP_PANEL_INCH_55,
	DISP_PANEL_INCH_58,
	DISP_PANEL_INCH_60,
	DISP_PANEL_INCH_65,
	DISP_PANEL_INCH_70,
	DISP_PANEL_INCH_75,
	DISP_PANEL_INCH_77,
	DISP_PANEL_INCH_79,
	DISP_PANEL_INCH_84,
	DISP_PANEL_INCH_86,
	DISP_PANEL_INCH_98,
	DISP_PANEL_INCH_105,
	DISP_PANEL_INCH_48,	// 17Y Added
	DISP_PANEL_INCH_MAX
} DISP_PANEL_INCH_T;

/**
 * panel maker  related with Tool OPT
*/
typedef enum {
	DISP_PANEL_MAKER_LGD = 0,
	DISP_PANEL_MAKER_AUO,
	DISP_PANEL_MAKER_SHARP,
	DISP_PANEL_MAKER_BOE,
	DISP_PANEL_MAKER_CSOT,
	DISP_PANEL_MAKER_INNOLUX,
	DISP_PANEL_MAKER_LGD_M,
	DISP_PANEL_MAKER_ODM_B,
	DISP_PANEL_MAKER_BOE_TPV,
	DISP_PANEL_MAKER_HKC,
	DISP_PANEL_MAKER_MAX
}DISP_PANEL_MAKER_T;

/**
 * Panel interface
 */
typedef enum {
	DISP_PANEL_EPI = 0,
 	DISP_PANEL_LVDS,
 	DISP_PANEL_Vx1,
 	DISP_PANEL_CEDS,
 	DISP_PANEL_EPI_QSAC,
  	DISP_PANEL_RESERVED1,
    DISP_PANEL_RESERVED2,
 	DISP_PANEL_INTERFACE_MAX
}DISP_PANEL_INTERFACE_T;

/**
  * Panel Resolution
  */
 typedef enum {
	DISP_PANEL_RESOLUTION_1024X768 = 0,
	DISP_PANEL_RESOLUTION_1280X720,
 	DISP_PANEL_RESOLUTION_1366X768,
 	DISP_PANEL_RESOLUTION_1920X1080,
 	DISP_PANEL_RESOLUTION_2560X1080,
 	DISP_PANEL_RESOLUTION_3840X2160,
 	DISP_PANEL_RESOLUTION_5120X2160,
 	DISP_PANEL_RESOLUTION_7680X4320,
  	DISP_PANEL_RESOLUTION_RESERVED1,
    DISP_PANEL_RESOLUTION_RESERVED2,
    DISP_PANEL_RESOLUTION_RESERVED3,
    DISP_PANEL_RESOLUTION_RESERVED4,
    DISP_PANEL_RESOLUTION_RESERVED5,
 	DISP_PANEL_RESOLUTION_MAX
 } DISP_PANEL_RESOLUTION_T;

/**
* Panel version
*/
typedef enum {
	DISP_PANEL_NONE = 0,
	DISP_PANEL_V12,
	DISP_PANEL_V13,
	DISP_PANEL_V14,
	DISP_PANEL_V15,
	DISP_PANEL_V16,
	DISP_PANEL_V17,
	DISP_PANEL_V18,
	DISP_PANEL_MAX
} DISP_PANEL_VERSION_T;

/**
* Panel Framerate
*/
typedef enum {
	DISP_PANEL_FRAMERATE_60HZ,
	DISP_PANEL_FRAMERATE_120HZ,
	DISP_PANEL_FRAMERATE_MAX
} DISP_PANEL_FRAMERATE_T;

/**
 * Backlight Type Enum  related with Tool OPT
*/
typedef enum {
	DISP_PANEL_BL_DIRECT_L = 0,
	DISP_PANEL_BL_EDGE_LED,
	DISP_PANEL_BL_OLED,
	DISP_PANEL_BL_DIRECT_VI,
	DISP_PANEL_BL_DIRECT_SKY,
	DISP_PANEL_BL_MAX
} DISP_PANEL_BACKLIGHT_TYPE_T;

/**
* Panel Led_bar Type Enum  related with Tool OPT
*/
typedef enum {
	DISP_PANEL_LED_BAR_6 = 0,
	DISP_PANEL_LED_BAR_12,
	DISP_PANEL_LED_BAR_36,
	DISP_PANEL_LED_BAR_40,
	DISP_PANEL_LED_BAR_48,
	DISP_PANEL_LED_BAR_50,
	DISP_PANEL_LED_BAR_96,
	DISP_PANEL_LED_BAR_MAX
}DISP_PANEL_LED_BAR_TYPE_T;

/**
* Panel Cell type
*/
typedef enum {
	DISP_PANEL_CELL_TYPE_RGB = 0,
	DISP_PANEL_CELL_TYPE_RGBW,
	DISP_PANEL_CELL_TYPE_MAX
} DISP_PANEL_CELL_TYPE_T;

/**
* Display Output Lane Bandwidth.
*/
typedef enum {
	DISP_OUTPUT_LANE_BANDWIDTH_DEFAULT = 0,
	DISP_OUTPUT_LANE_BANDWIDTH_1_5G,
	DISP_OUTPUT_LANE_BANDWIDTH_2_1G,
	DISP_OUTPUT_LANE_BANDWIDTH_3_0G,
	DISP_OUTPUT_LANE_BANDWIDTH_MAX
}DISP_OUTPUT_LANE_BANDWIDTH_T;

/**
* FRC Chip type
*/
typedef enum {
	DISP_FRC_CHIP_NONE = 0,
	DISP_FRC_CHIP_INTERNAL,
	DISP_FRC_CHIP_EXTERNAL1,	//Reserved1
	DISP_FRC_CHIP_EXTERNAL2,	//Reserved2
	DISP_FRC_CHIP_TPYE_MAX
} DISP_FRC_CHIP_TYPE_T;

/**
 * LVDS bit depth.
*/
typedef enum {
	DISP_COLOR_DEPTH_8BIT,
	DISP_COLOR_DEPTH_10BIT,
	DISP_COLOR_DEPTH_MAX
}DISP_LVDS_COLORDEPTH_T;

/**
 * LVDS type.
*/
typedef enum {
	DISP_LVDS_TYPE_VESA,
	DISP_LVDS_TYPE_JEIDA,
	DISP_LVDS_TYPE_MAX
}DISP_LVDS_TYPE_T;

/**
* Display User Option
*/
typedef union {
 	UINT32 all;
 	struct
 	{
		UINT32
		SocOptionBIT0	:1,
		SocOptionBIT1	:1,
		SocOptionBIT2	:1,
		SocOptionBIT3	:1,
		SocOptionBIT4	:1,
		SocOptionBIT5	:1,
		SocOptionBIT6	:1,
		SocOptionBIT7	:1,
		SocOptionBIT8	:1,
		SocOptionBIT9	:1,
		SocOptionBIT10	:1,
		SocOptionBIT11	:1,
		SocOptionBIT12	:1,
		SocOptionBIT13	:1,
		SocOptionBIT14	:1,
		SocOptionBIT15	:1,
		SocOptionBIT16	:1,
		SocOptionBIT17	:1,
		SocOptionBIT18	:1,
		SocOptionBIT19	:1,
		SocOptionBIT20	:1,
		SocOptionBIT21	:1,
		SocOptionBIT22	:1,
		SocOptionBIT23	:1,
		SocOptionBIT24	:1,
		SocOptionBIT25	:1,
		SocOptionBIT26	:1,
		SocOptionBIT27	:1,
		SocOptionBIT28	:1,
		SocOptionBIT29	:1,
		SocOptionBIT30	:1,
		SocOptionBIT31	:1;
 	} flags;
} DISP_USER_OPTION_T;

/**
* Panel information
*/
typedef struct {
  	DISP_PANEL_INCH_T panelInch;					// Panel Inch
  	DISP_PANEL_MAKER_T panelMaker;	  				// Panel maker
  	DISP_PANEL_INTERFACE_T panelInterface;  		// Panel Interface
  	DISP_PANEL_RESOLUTION_T panelResolution;		// Panel Resolution
 	DISP_PANEL_VERSION_T panelVersion;				// Panel Version
	DISP_PANEL_FRAMERATE_T panelFrameRate;			// Panel Frame Rate
  	DISP_PANEL_LED_BAR_TYPE_T panelLedBarType;		// LED bar type
  	DISP_PANEL_BACKLIGHT_TYPE_T panelBacklightType;	// LED Backlight type
	DISP_PANEL_CELL_TYPE_T panelCellType;			// Panel Cell type
	DISP_OUTPUT_LANE_BANDWIDTH_T dispOutLaneBW;		// Ouput lane bandwidth
 	DISP_FRC_CHIP_TYPE_T frcType;					// FRC type
 	DISP_LVDS_COLORDEPTH_T   lvdsColorDepth;  		// LVDS Color depth
 	DISP_LVDS_TYPE_T   lvdsType;					// LVDS Type
	DISP_USER_OPTION_T userSpecificOption;			// Reserved Options
} DISP_PANEL_INFO_T;

 /**
  * panel Signal Timing.
  *
  * @see
 */
typedef struct {
	// Panel Signal Timing
	UINT32 MinDclkHz;			 /** Panel Min Dclk [KHz] */
	UINT32 TypDclkHz;			 /** Panel Typ Dclk [KHz] */
	UINT32 MaxDclkHz;			 /** Panel Max Dclk [KHz] */
	UINT16 horizTypPeriod; 		 /** panel Horizon Period */
	UINT16 vertTypPeriod60Hz;	 /** panel Vertical Period for NTSC*/
	UINT8 vertSyncWidth60Hz;	 /** panel Vertical Sync Width for NTSC*/
	UINT8 vertBackPorch60Hz;	 /** panel Vertical Back Porch for NTSC*/
	UINT8 horizSyncWidth60Hz;	 /** panel Horizontal Sync Width for NTSC*/
	UINT8 horizBackPorch60Hz;	 /** panel Horizontal Back Porch for NTSC*/
	UINT16 vertTypPeriod50Hz;	 /** panel Vertical Period for PAL*/
	UINT8 vertSyncWidth50Hz;	 /** panel Vertical Sync Width for PAL*/
	UINT8 vertBackPorch50Hz;	 /** panel Vertical Back Porch for PAL*/
	UINT8 horizSyncWidth50Hz;	 /** panel Horizontal Sync Width for PAL*/
	UINT8 horizBackPorch50Hz;	 /** panel Horizontal Back Porch for PAL*/
	UINT16 vertTypPeriod48Hz;	 /** panel Vertical Period for 48Hz*/
	UINT8 vertSyncWidth48Hz;	 /** panel Vertical Sync Width for 48Hz*/
	UINT8 vertBackPorch48Hz;	 /** panel Vertical Back Porch for 48Hz*/
	UINT8 horizSyncWidth48Hz;	 /** panel Horizontal Sync Width for 48Hz*/
	UINT8 horizBackPorch48Hz;	 /** panel Horizontal Back Porch for 48Hz*/
}DISP_PANEL_SIGNAL_TIMING_T;

/**
* BOE version
*/
typedef struct {
	UINT8 b0;
	UINT8 b1;
	UINT8 b2;
} DISP_BOE_VERSION_T;

/**
  * MLE mode for M+ panel
 */
typedef enum {
	DISP_HIGH_LUM1_MSE_ON = 0,
	DISP_HIGH_LUM2,
	DISP_LOW_POWER1,
	DISP_MLE_MODE_OFF,
	DISP_HIGH_LUM1_MSE_OFF,
	DISP_LOW_POWER2,
	DISP_LOW_POWER2_SC_OFF,
	DISP_MLE_MODE_MAX
} DISP_MPLUS_MODE_T;

/**
 * LSR user mode
**/
typedef enum{
	DISP_LOGO_LUMY_ADJUST_OFF = 0,
	DISP_LOGO_LUMY_ADJUST_LIGHT,
	DISP_LOGO_LUMY_ADJUST_STRONG,
	DISP_LOGO_LUMY_ADJUST_MAX
}DISP_LSR_ADJUST_MODE_T;

/**
 * LSR tunning factor
 **/
typedef struct{
	UINT8	IIR;
	UINT8	APL_LUT[8];
	UINT16	GB_LUT[8];
	UINT16	OFFSET[15];
	UINT32	COUNT[3];
}DISP_LSR_TUNNING_VAL_T; 

/**
 * CPC tunning factor
 **/
typedef struct{
	UINT16	APL_LUT[4];
	UINT16	EDGE_LUT[4];
	UINT8	STEP[2];
}DISP_CPC_TUNNING_VAL_T; 



/**
 * TSCIC data structure
 **/
typedef struct {
	UINT8 *u8pControlTbl;
	UINT32 u32Ctrlsize;
	UINT32 *u32pTSCICTbl;
	UINT32 u32Tscicsize;
}DISP_PANEL_TSCIC_T;


/*-----------------------------------------------------------------------------
	Local Variables & Function Prototypes Declarations
------------------------------------------------------------------------------*/
/* Below functions are releated with Init & Uninit & Resume */
DTV_STATUS_T HAL_VBE_DISP_Initialize(DISP_PANEL_INFO_T *panelInfo);
DTV_STATUS_T HAL_VBE_DISP_Uninitialize(void);
DTV_STATUS_T HAL_VBE_DISP_Resume(DISP_PANEL_INFO_T *panelInfo);

/* Below functions are releated with Tx Data  */
DTV_STATUS_T HAL_VBE_DISP_SetDisplayOutput(BOOLEAN bOnOff);
DTV_STATUS_T HAL_VBE_DISP_SetDisplayFormat(DISP_PANEL_SIGNAL_TIMING_T *panelSignalTiming, DISP_PANEL_INFO_T *panelInfo, UINT8 frameRate);
DTV_STATUS_T HAL_VBE_DISP_GetOutputFrameRate(UINT8 *pFrameRate);
DTV_STATUS_T HAL_VBE_DISP_SetOutputFrameRate(BOOLEAN isForceFreeRun, UINT8 frameRates);
DTV_STATUS_T HAL_VBE_DISP_SetEPIDataScramble(BOOLEAN bOnOff);
DTV_STATUS_T HAL_VBE_DISP_SetAdvanced10bit(BOOLEAN bOnOff);


/* Below functions are releated with general function */
DTV_STATUS_T HAL_VBE_DISP_SetMute(BOOLEAN bOnOff);
DTV_STATUS_T HAL_VBE_DISP_SetSpreadSpectrum(BOOLEAN bEnable, UINT16 u16Percent, UINT16 u16Period);
DTV_STATUS_T HAL_VBE_DISP_SetVideoMirror(BOOLEAN bIsH, BOOLEAN bIsV);
DTV_STATUS_T HAL_VBE_DISP_SetBackgroundColor(UINT8 red, UINT8 green, UINT8 blue);

/* Below functions are releated with OLED  */
DTV_STATUS_T HAL_VBE_DISP_SetOrbit (BOOLEAN bOnOff, BOOLEAN bAutoMode);
DTV_STATUS_T HAL_VBE_DISP_SetOLEDLSR(DISP_LSR_ADJUST_MODE_T nStep, UINT32 *LSRTbl);
DTV_STATUS_T HAL_VBE_DISP_SetOLEDLSRTunning(DISP_LSR_TUNNING_VAL_T *stLSRdata);
DTV_STATUS_T HAL_VBE_DISP_SetOLEDCPCTunning(DISP_CPC_TUNNING_VAL_T *stCPCdata);
DTV_STATUS_T HAL_VBE_DISP_SetOLEDGSR(UINT32 *GSRTbl);
DTV_STATUS_T HAL_VBE_DISP_SetCPC(BOOLEAN bOnOff);


/* Below functions are releated with  M+ Model  */
DTV_STATUS_T HAL_VBE_DISP_SetBOEMode(UINT8 *pFwData, UINT32 size);
DTV_STATUS_T HAL_VBE_DISP_GetBOEVersion(DISP_BOE_VERSION_T *pstRomVer, DISP_BOE_VERSION_T *pstFwVer);
DTV_STATUS_T HAL_VBE_DISP_SetBOERGBWBypass(BOOLEAN bOnOff);
DTV_STATUS_T HAL_VBE_DISP_SetMLEMode(DISP_MPLUS_MODE_T mode);
DTV_STATUS_T HAL_VBE_DISP_GetMPlusPwmRatio(UINT16 *pRatio);
DTV_STATUS_T HAL_VBE_DISP_SetDGA4CH (UINT32 *pRedGammaTable, UINT32 *pGreenGammaTable, UINT32 *pBlueGammaTable, UINT32 *pWhiteGammaTable);
DTV_STATUS_T HAL_VBE_DISP_SetFrameGainLimit(UINT16 nFrameGainLimit);
DTV_STATUS_T HAL_VBE_DISP_GetFrameGainLimit (UINT16 *nFrameGainLimit);
DTV_STATUS_T HAL_VBE_DISP_SetPixelGainLimit (UINT16 nPixelGainLimit);
DTV_STATUS_T HAL_VBE_DISP_GetPixelGainLimit (UINT16 *nPixelGainLimit);

/* Test Pattern */
DTV_STATUS_T HAL_VBE_DISP_SetInnerPattern(UINT8 bOnOff, UINT8 ip, UINT8 type);


/* TSCIC Load  */
DTV_STATUS_T HAL_VBE_TSCIC_Load(DISP_PANEL_TSCIC_T *tscicTbl);

DTV_STATUS_T HAL_VBE_DISP_MplusSet(void * pRegisterSet, UINT8 nPanelMaker);
DTV_STATUS_T HAL_VBE_DISP_MplusGet(void * pRegisterSet, UINT8 nPanelMaker);


#endif /* _HAL_VBE_DISP_H_ */
