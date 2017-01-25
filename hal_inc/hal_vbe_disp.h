/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file hal_vsc.h
 *
 *  It is the header file for controling VIDEO function.
 *  The header of VIDEO DDI is controlled by this file.
 *
 *  @author	Lee, Jong-Heon(jongheon.lee@lge.com)
 *  @version	0.1
 *  @date		2011.03.18
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
#define DISP_RES_WIDTH(_v)			((_v & 0xffff) << 12  )
#define DISP_RES_HEIGHT(_v)			((_v & 0xfff)         )

#define DISP_RES_1920X1080			( DISP_RES_WIDTH(1920) | DISP_RES_HEIGHT(1080) )
#define DISP_RES_1366X768			( DISP_RES_WIDTH(1366) | DISP_RES_HEIGHT(768) )
#define DISP_RES_1365X768			( DISP_RES_WIDTH(1365) | DISP_RES_HEIGHT(768) )
#define DISP_RES_1024X768			( DISP_RES_WIDTH(1024) | DISP_RES_HEIGHT(768) )

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
 * DISPLAY Window ID.
 *
 * @see DDI Implementation Guide
*/
 typedef enum
{
	DISP_WINDOW_0,
	DISP_WINDOW_1,
} DISP_WINDOW_T;

/**
  * Panel interface
  */
 typedef enum {
	DISP_PANEL_LVDS = 0,
	DISP_PANEL_HSLVDS,
 	DISP_PANEL_EPI,
 	DISP_PANEL_Vx1,
 	DISP_PANEL_MAX
 } DISP_PANEL_INTERFACE_T;

/**
* EPI Panel type
*/
typedef enum {
	DISP_EPI_PANEL_V12 = 0,
	DISP_EPI_PANEL_V13,
	DISP_EPI_PANEL_V14,
	DISP_EPI_PANEL_V15,
	DISP_EPI_PANEL_V16,
	DISP_EPI_PANEL_MAX
} DISP_EPI_PANEL_TYPE_T;

/**
* FRC Chip type
*/
typedef enum {
	DISP_FRC_CHIP_NONE = 0,
	DISP_FRC_CHIP_INTERNAL,
	DISP_FRC_CHIP_UD_BE_FRC,
	DISP_FRC_CHIP_UD_BE_URSA7,
	DISP_FRC_CHIP_UD_BE_URSA9,
	DISP_FRC_CHIP_UD_BE_URSA9P,
	DISP_FRC_CHIP_UD_BE_URSA11,
	DISP_FRC_CHIP_UD_BE_URSA11P,
	DISP_FRC_CHIP_UD_BE_F16,
	DISP_FRC_CHIP_UD_BE_MAX
} DISP_FRC_CHIP_TYPE_T;

/**
* Panel Cell type
*/
typedef enum {
	DISP_CELL_TYPE_RGB = 0,
	DISP_CELL_TYPE_RGBW,
	DISP_CELL_TYPE_MAX
} DISP_CELL_TYPE_T;

/**
 * Panel size Enum.
*/
typedef enum {
	DISP_PANEL_INCH_32 = 0,
	DISP_PANEL_INCH_39,
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
	DISP_PANEL_INCH_77,
	DISP_PANEL_INCH_79,
	DISP_PANEL_INCH_84,
	DISP_PANEL_INCH_98,
	DISP_PANEL_INCH_105, // TV model

	DISP_PANEL_INCH_23,
	DISP_PANEL_INCH_24,
	DISP_PANEL_INCH_26,
	DISP_PANEL_INCH_27, // Smart Monitor TV

	DISP_PANEL_INCH_22,
	DISP_PANEL_INCH_28,

	DISP_PANEL_INCH_BASE
} DISP_PANEL_INCH_T;

/**
 * Backlight Type Enum.
*/
typedef enum {
	DISP_BL_DIRECT_M = 0,
	DISP_BL_DIRECT_L,
	DISP_BL_EDGE_LED,
	DISP_BL_ALEF_LED,
	DISP_BL_OLED,
	DISP_BL_END
} DISP_BACKLIGHT_TYPE_T;

/**
* Panel Led_bar Type Enum.
*/
typedef enum {
	DISP_LED_BAR_6 = 0,
	DISP_LED_BAR_12,
	DISP_LED_BAR_16,
	DISP_LED_BAR_20,
	DISP_LED_BAR_240,
	DISP_LED_BAR_V8,
	DISP_LED_BAR_MAX
} DISP_LED_BAR_TYPE_T;

 /**
  * panel type.
  *
  * @see
 */
 typedef enum
 {
	 DISP_PANEL_TYPE_LCD,
	 DISP_PANEL_TYPE_LCD_TCON,	 // shjang_090904
	 DISP_PANEL_TYPE_LCD_FRC,

	 DISP_PANEL_TYPE_PDP,
	 DISP_PANEL_TYPE_LED,
	 DISP_PANEL_TYPE_OLED,

	 DISP_PANEL_TYPE_NUM,
 }DISP_PANEL_TYPE_T;

 /**
  * panel maker.
  *
  * @see
 */
 typedef enum
 {
	 DISP_LCD_PANEL_MAKER_LGD,
	 DISP_LCD_PANEL_MAKER_CMI,
	 DISP_LCD_PANEL_MAKER_AUO,
	 DISP_LCD_PANEL_MAKER_SHARP,
	 DISP_LCD_PANEL_MAKER_IPS,
	 DISP_LCD_PANEL_MAKER_BOE,
	 DISP_PDP_PANEL_MAKER_LGE,
	 DISP_PANEL_MAKER_NUM,
 }DISP_PANEL_MAKER_T;

 /**
  * LVDS bit depth.
  *
  * @see
 */
 typedef enum
 {
	 DISP_COLOR_DEPTH_8BIT,
	 DISP_COLOR_DEPTH_10BIT,
	 DISP_COLOR_DEPTH_NUM,
 }DISP_COLOR_DEPTH_T;

 /**
  * LVDS chanel info.
  *
  * @see
 */
 typedef enum
 {
	 DISP_LVDS_PIXEL_SINGLE,  //HD 60hz
	 DISP_LVDS_PIXEL_DUAL,	 //FHD 60hz
	 DISP_LVDS_PIXEL_QUAD,	 //FHD 120hz
	 DISP_LVDS_PIXEL_NUM,
 }DISP_LVDS_PIXEL_T;

 /**
  * LVDS type.
  *
  * @see
 */
 typedef enum
 {
	 DISP_LVDS_SELECT_VESA,
	 DISP_LVDS_SELECT_JEIDA,
	 DISP_LVDS_SELECT_NUM,
 }DISP_LVDS_SELECT_T;

 typedef enum
 {
 	DISP_HDMI_HDCP_NONE = 0,
	DISP_HDMI_HDCP_14,
	DISP_HDMI_HDCP22,
	DISP_HDMI_HDCP_MAXNUM
 }DISP_HDMI_HDCP_TYPE_T;


/**
* Display Output Resolution
*/
typedef struct {
 	UINT32 video_width;
 	UINT32 video_height;
 	UINT32 osd_width;
 	UINT32 osd_height;
} DISP_OUTPUT_RESOLUTION_T;

/**
* Panel information
*/
typedef struct {
  	UINT8 panel_inch; 	  // panel size 		  ex) 47, 55
  	UINT8 panel_bl_type;		  // led backlight type 	  ex) alef, edge
  	UINT8 panel_maker;	  // panel maker		  ex) lgd, auo
  	UINT8 led_bar_type;		 // led bar type		 ex) h6,h12, v12
  	
  	DISP_PANEL_INTERFACE_T panelInterface;  // LVDS,EPI,Vx1
 	DISP_EPI_PANEL_TYPE_T epi_panel_type;
 	DISP_FRC_CHIP_TYPE_T frc_type;
	DISP_CELL_TYPE_T cell_type;
 	DISP_OUTPUT_RESOLUTION_T disp_out_resolution;
 	DISP_COLOR_DEPTH_T   lvds_bit_mode;  /**COLOR_DEPTH_T */
 	DISP_LVDS_SELECT_T   lvds_type;	 /**LVDS_SELECT_T */
} DISP_PANEL_INFO_T;

typedef struct {
	UINT8 panel_inch;	   // panel size		   ex) 47, 55
	UINT8 panel_bl_type;		   // led backlight type	   ex) alef, edge
	UINT8 panel_maker;    // panel maker		   ex) lgd, auo
	DISP_PANEL_INTERFACE_T panelInterface;  // LVDS,EPI,Vx1

	//Added for Instant Boot
	DISP_EPI_PANEL_TYPE_T epi_panel_type;
	UINT8 led_bar_type;	  // led bar type		  ex) h6,h12, v12
	UINT8 useInternalFrc;
	DISP_OUTPUT_RESOLUTION_T disp_out_resolution;
	DISP_COLOR_DEPTH_T   lvds_bit_mode;  /**COLOR_DEPTH_T */
	DISP_LVDS_SELECT_T   lvds_type;  /**LVDS_SELECT_T */
} DISP_PANEL_INFO_TEMP_T;

 /**
  * panel attribute.
  *
  * @see
 */
 typedef struct
 {
	 DISP_PANEL_TYPE_T	 ePanelType; /**PANEL_TYPE_T */
	 DISP_COLOR_DEPTH_T	 eColorDepth;	 /**COLOR_DEPTH_T */
	 DISP_LVDS_SELECT_T	 eLVDSSelect;	 /**LVDS_SELECT_T */
	 DISP_LVDS_PIXEL_T	 eLVDSPixel; /**LVDS_PIXEL_T */
	 DISP_PANEL_INTERFACE_T	 ePanelInterface;/**PANEL_INTERFACE_T*/
	 UINT8 eFRCType;/**FRC_CHIP_TYPE_T*/

	 SINT32 panelResolution;	 /** */
	 UINT8 ePanelInch;		 /** */
	 //------------ signal timing -----------------
	 //UINT16 TypDclkHz;		 /** panel D clock*/
	 UINT16 horizTypPeriod; 	 /** panel Horizon Period */
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
}DISP_PANEL_ATTRIBUTE_T;

/**
  * MLE mode for M+ panel
  *
  * @see
 */
typedef enum
{	
	DISP_HIGH_LUM1_MSE_ON = 0,
	DISP_HIGH_LUM2,
	DISP_LOW_POWER1,
	DISP_MLE_MODE_OFF,
	DISP_HIGH_LUM1_MSE_OFF,
	DISP_LOW_POWER2,
	DISP_LOW_POWER2_SC_OFF,
	DISP_MLE_MODE_MAX
} DISP_MLE_MODE_T;

typedef enum
{
	DISP_HDMI20_TX_4K_NO_OUTPUT = 0, // Output Phy PDB Down
	DISP_HDMI20_TX_4K_60_RGB444,		// 4K 60Hz RGB 4:4:4, TMDS Clock 594MHz
	DISP_HDMI20_TX_4K_50_RGB444,		// 4K 50Hz RGB 4:4:4, TMDS Clock 594MHz
	DISP_HDMI20_TX_OUTPUT_CHANGING_BUSY,	// On changing output signal...This means TX is busy..
	DISP_HDMI20_TX_OUTPUT_MAXNUM
} DISP_HDMI_TX_OUTPUT_TYPE_T;

 /*-----------------------------------------------------------------------------
	Local Variables & Function Prototypes Declarations
------------------------------------------------------------------------------*/
DTV_STATUS_T HAL_VBE_DISP_Initialize(DISP_PANEL_INFO_T panelInfo);
DTV_STATUS_T HAL_VBE_DISP_Uninitialize(void);
DTV_STATUS_T HAL_VBE_DISP_Resume(DISP_PANEL_INFO_T panelInfo);
DTV_STATUS_T HAL_VBE_DISP_Resume_temp(DISP_PANEL_INFO_TEMP_T panelInfo);
DTV_STATUS_T HAL_VBE_DISP_Connect(DISP_WINDOW_T wId);
DTV_STATUS_T HAL_VBE_DISP_Disconnect(DISP_WINDOW_T wId);
DTV_STATUS_T HAL_VBE_DISP_SetDisplayOutput(BOOLEAN bOnOff);
DTV_STATUS_T HAL_VBE_DISP_SetMute(BOOLEAN bOnOff);
DTV_STATUS_T HAL_VBE_DISP_SetSpreadSpectrum(BOOLEAN bEnable, UINT16 u16Percent, UINT16 u16Period);
DTV_STATUS_T HAL_VBE_DISP_SetVideoMirror(BOOLEAN bIsH, BOOLEAN bIsV);
DTV_STATUS_T HAL_VBE_DISP_SetDisplayFormat(DISP_PANEL_ATTRIBUTE_T * pPanelAttr, UINT8 frameRate);
DTV_STATUS_T HAL_VBE_DISP_GetOutputFrameRate(UINT8 *pFrameRate);
DTV_STATUS_T HAL_VBE_DISP_SetFrameRate(BOOLEAN isForceFreeRun, UINT8 frameRates);
DTV_STATUS_T HAL_VBE_DISP_SetBackgroundColor(UINT8 red, UINT8 green, UINT8 blue);
DTV_STATUS_T HAL_VBE_DISP_SetODTable(UINT8 *pTable, UINT16 size);
DTV_STATUS_T HAL_VBE_DISP_SetPCIDTable(UINT8 *pTable, UINT16 size);
DTV_STATUS_T HAL_VBE_DISP_EnableOD(BOOLEAN bOnOff);
DTV_STATUS_T HAL_VBE_DISP_EnablePCID(BOOLEAN bOnOff);
DTV_STATUS_T HAL_VBE_DISP_SetMLEMode(DISP_MLE_MODE_T mode);
DTV_STATUS_T HAL_VBE_DISP_GetMPlusPwmRatio(UINT16 *pRatio);

/* 2015/03/05 : Only for H15 */
DTV_STATUS_T HAL_VBE_DISP_HDMI_Initialize(DISP_HDMI_HDCP_TYPE_T type, UINT8 *pData, int size, int isTestmode);
DTV_STATUS_T HAL_VBE_DISP_HDMI_ReadEDID(UINT8 *pData, int size, int isForceReRead, UINT8 blockNo);
DTV_STATUS_T HAL_VBE_DISP_HDMI_OutputResolution(BOOLEAN isSet, DISP_HDMI_TX_OUTPUT_TYPE_T *type);
DTV_STATUS_T HAL_VBE_DISP_HDMI_Control_AVMute(BOOLEAN isSet);

#ifdef	__cplusplus
	}
#endif /* __cplusplus */

#endif /* _HAL_VBE_DISP_H_ */
