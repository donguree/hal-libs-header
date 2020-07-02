/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/*!@defgroup venc Video Encoder HAL APIs
 *
 * @{
 */

/** @file hal_venc.h
 *
 *  Video Encoder HAL function header file.
 *	HAL VENC API Functions(video encoder, recoding and codec encoding)
 *
 *	@author		YoungKi Son (yk.son@lge.com)
 *  @version	1.1
 *  @date		2013.03.13 Jaeseop So (jaeseop.so@lge.com)
 *  @date		2017.03.03
 *  @see
 */

/*! \mainpage HAL VENC APIs
 * \section recodring_sec Recoding APIs
 *
 * VENC supports Recoding APIs for DVR feature.
 *
 * \section codecapi_sec Codec APIs
 *
 * VENC supports Codec APIs for H264 and VP8 encoding.
 *
 */

#ifndef _HAL_VENC_H_
#define _HAL_VENC_H_

/******************************************************************************
 #include files (File Inclusions)
******************************************************************************/

//#include <osa_api.h>
#ifndef WIN32_SIM // Modified by dilly97: fix include
#include "hal_common.h"
#else
#include "common_win32.h"
#endif


/**
 * @brief infomation of recored frame
 */
typedef struct VENC_MSG_TYPE
{
	UINT32	channel;	/**< Port Id */
	UINT8	pictype;	/**< Picture Type IDC:1 I:2 P:4 B:8 */
	UINT64	pts;		/**< PTS */
	UINT8	*pData;		/**< pointer to Video Data */
	UINT32	dataLen;	/**< Video Data Length */
	UINT8	*pRStart;	/**< start pointer of buffer */
	UINT8	*pREnd;		/**< end pointer of buffer */
}VENC_MSG_TYPE_T;

/**
 * @brief recoding data callback function Type
 */
typedef DTV_STATUS_T (*pfnVENCDataHandlingCB)(VENC_MSG_TYPE_T *pMsg);

/**
 * @brief recoding input source types
 */
typedef enum
{
	VENC_INPUT_MAIN = 0,/**< Main Video source */
	VENC_INPUT_SUB,		/**< Sub Video source */
	VENC_INPUT_EXT,		/**< Extra Video source */
	VENC_INPUT_NUM
}VENC_INPUT_TYPE_T;

/**
 * @brief venc codec formats
 */
typedef enum
{
	VENC_CODEC_H264 = 0,/**< H264 format */
	VENC_CODEC_VP8		/**< VP8 format */
}VENC_CODEC_T;

/**
 * @brief recoding frame rate
 */
typedef enum
{
	VENC_FRAMERATE_AUTO = 0,	// Optimal frame rate for this Encoder. (60p -> 30p, 50p -> 25p...)
	VENC_FRAMERATE_ASIS,	// Use original framerate
	VENC_FRAMERATE_60P,	//60Hz progressive (reserved not used)
	VENC_FRAMERATE_60I,	//60Hz interlaced (reserved not used)
	VENC_FRAMERATE_50P,	//50Hz progressive (reserved not used)
	VENC_FRAMERATE_50I,	//50Hz interlaced (reserved not used)
	VENC_FRAMERATE_30P,	//30Hz progressive
	VENC_FRAMERATE_30I,	//30Hz interlaced (reserved not used)
	VENC_FRAMERATE_25P,	//25Hz progressive (reserved not used)
	VENC_FRAMERATE_25I,	//25Hz interlaced (reserved not used)
	VENC_FRAMERATE_24P,	//24Hz progressive (reserved not used)
	VENC_FRAMERATE_24I,	//24Hz interlaced (reserved not used)
	VENC_FRAMERATE_INVALID
}VENC_FRAMERATE_T;

/**
 * @brief venc profiles
 */
typedef enum
{
	VENC_PROFILE_BASE = 0,
	VENC_PROFILE_MAIN,
	VENC_PROFILE_EXT,
	VENC_PROFILE_HIGH
}VENC_PROFILE_T;

/**
 * @brief profile levels
 */
typedef enum
{
	VENC_PROFILELEVEL_30 = 0,
	VENC_PROFILELEVEL_31,
	VENC_PROFILELEVEL_40,
	VENC_PROFILELEVEL_41
}VENC_PROFILELEVEL_T;

/**
 * @brief Rate conotrol mode
 */
typedef enum {
	VENC_RATECONTROL_VBR = 0,	/**< Variable Bit Rate (VBR) mode */
	VENC_RATECONTROL_CBR = 1,	/**< Constant Bit Rate (CBR) mode */
} VENC_RATECONTROL_T;

/**
 * @brief venc recoding parameter types
 */
typedef enum {
	VENC_INFO_FRAMERATE = 0,
	VENC_INFO_WIDTH,
	VENC_INFO_HEIGHT,
	VENC_INFO_ASPECTRATIOIDC,
	VENC_INFO_SARWIDTH,
	VENC_INFO_SARHEIGHT,
	VENC_INFO_INPUT,
	VENC_INFO_BITRATE,
	VENC_INFO_PROFILE,
	VENC_INFO_PROFILELEVEL,
	VENC_INFO_CODEC,
	VENC_INFO_RATECONTROL,
	VENC_INFO_GOPLENGTH,
	VENC_INFO_QP,
	VENC_INFO_SOURCE,
	VENC_INFO_NUM
}VENC_INFO_T;


typedef enum {
    VENC_SOURCE_ATV = 0,
    VENC_SOURCE_AV,
    VENC_SOURCE_SCARTIN,
    VENC_SOURCE_NUM
} VENC_SOURCE_T;

/**
 * VENC Open for recoding
 *
 * @return  DTV_STATUS_T
 * @retval	OK
 * @retval	NOT_OK
 */
DTV_STATUS_T	HAL_VENC_Open(void);

/**
 * VENC Finalizing after recoding
 * @return  DTV_STATUS_T
 * @retval	OK
 * @retval	NOT_OK
 */
DTV_STATUS_T	HAL_VENC_Close(void);

/**
 * Select Video source
 *
 * @param[in]	port		port of video encoder(reserved)
 * @param[in]	input		input source
 * @return  DTV_STATUS_T
 * @retval	OK
 * @retval	NOT_OK
 */
DTV_STATUS_T	HAL_VENC_Connect(UINT8 port, VENC_INPUT_TYPE_T input);

/**
 * Start Video Encoding
 *
 * @param[in]	port		port of video encoder(reserved)
 * @return  DTV_STATUS_T
 * @retval	OK
 * @retval	NOT_OK
 */

DTV_STATUS_T	HAL_VENC_Start(UINT8 port);

/**
 * Stop Video Encoding
 *
 * @param[in]	port		port of video encoder(reserved)
 * @return  DTV_STATUS_T
 * @retval	OK
 * @retval	NOT_OK
 */
DTV_STATUS_T	HAL_VENC_Stop(UINT8 port);

/**
 * Set Parameter
 *
 * @param[in]	port		port of video encoder(reserved)
 * @param[in]	info		type of info to set
 * @param[in]	value		value to set
 * @return  DTV_STATUS_T
 * @retval	OK
 * @retval	NOT_OK
 */

DTV_STATUS_T	HAL_VENC_SetParam(UINT8 port, VENC_INFO_T info, SINT32 value);

/**
 * VENC Get infomation
 *
 * @param[in]	port		port of video encoder(reserved)
 * @param[in]	info		Type of info to set
 * @param[in] 	pValue		Pointer to set result value
 * @return  DTV_STATUS_T
 * @retval	OK
 * @retval	NOT_OK
 */
DTV_STATUS_T	HAL_VENC_GetParam(UINT8 port, VENC_INFO_T info, void *pValue);

/**
 * Register Callback function for every frame
 *
 * @param[in]	port		port of video encoder(reserved)
 * @param[in]	pfnCallBack	pointer of callback function
 * @return  DTV_STATUS_T
 * @retval	OK
 * @retval	NOT_OK
 */
DTV_STATUS_T	HAL_VENC_RegisterEncoderCallback(UINT8 port, pfnVENCDataHandlingCB pfnCallBack);

/**
 * Copy Encoded Data to Destination
 *
 * @param[in]	port		port of video encoder(reserved)
 * @param[in]	pDest		Destination to Copy Data
 * @param[in]	pBufAddr	Encoded data start point
 * @param[in]	datasize	Encoded data length
 * @param[in]	pRStart		Start point of RingBuffer
 * @param[in]	pREnd		End point of RingBuffer
 * @return  DTV_STATUS_T
 * @retval	OK
 * @retval	NOT_OK
 */
DTV_STATUS_T	HAL_VENC_CopyData(UINT8 port, UINT8 *pDest, UINT8 *pBufAddr, UINT32 datasize, UINT8 *pRStart, UINT8 *pREnd);

/**
 * Release Encoded Data buffer
 * @param[in]	port		port of video encoder(reserved)
 * @param[in]	pBufAddr	Encoded data start point
 * @param[in]	datasize	Encoded data length
 * @return  DTV_STATUS_T
 * @retval	OK
 * @retval	NOT_OK
 */
DTV_STATUS_T	HAL_VENC_ReleaseData(UINT8 port, UINT8 *pBufAddr,UINT32 datasize);

/**
 * Get Thumbnail Data
 *
 * @param[in]	port		port of video encoder(reserved)
 * @param[in]	width		width of thumbnail
 * @param[in]	height		height of thumbnail
 * @param[in]	pBufAddr	Pointer to save thumbnail data
 * @param[in]	datasize	Thumbnail data length
 * @return  DTV_STATUS_T
 * @retval	OK
 * @retval	NOT_OK
 */
DTV_STATUS_T	HAL_VENC_GetThumbnail(UINT8 port, UINT32 width, UINT32 height, UINT8 *pBufAddr, UINT32 datasize);

DTV_STATUS_T HAL_VENC_ResetGOP(UINT8 port);

void HAL_VENC_DebugMenu(void);


#endif  /*_HAL_VENC_H_ */

