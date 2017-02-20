/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2006 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file 		hal_vdec.h
 *
 *  header of Mpeg2 Video Decoder DDI Fuction.
 *
 *  @author		Oh, Kyong-Joo (kjoh@lge.com)
 *  @version	1.0
 *  @date		2007.8.1     porting on GNSS platform
 *  @date		2007.12.27   Y2DTV
 *  @note		Additional information.
 *  @see
 */

#ifndef _hal_vdec_h_
#define _hal_vdec_h_


#ifndef WIN32_SIM
#else
#include "common_win32.h"
#endif

#include "hal_common.h"



#define HD1920   0
#define HD1280   1
#define SD720    2

#define VDEC_NORMAL_PLAY_SPEED 1000
#define	VDEC_MAX_CH_NUM			2

/** UI Messaging System에 사용되어지는 Callback 함수를 위한 정의.
 *	API_UTIL_InitUIMessagingSystem 함수 호출 시 사용되어진다.
 */
#define  MAX_VDEC2UI_MSG_PARAM 	4



/**
 * VDEC status
 */
typedef enum
{
	VDEC_NOT_INIT	= 0,
	VDEC_INIT,
	VDEC_PLAYING,
	VDEC_STOPPED,
	VDEC_FREEZED,
	VDEC_NO_DATA,
	VDEC_RUNNING,
	VDEC_GET_SYNC
} VDEC_STATE_T;


/**
 * codec type
 */
typedef enum
{
	VDEC_CODEC_NONE	= 0,
	VDEC_CODEC_MPEG1,		/* deprecated */
	VDEC_CODEC_MPEG2,
	VDEC_CODEC_MPEG4_PART2,	/* deprecated */
	VDEC_CODEC_H264_MPEG4AVC,
	VDEC_CODEC_AVS,
	VDEC_CODEC_VC1,			/* deprecated */
	VDEC_CODEC_DIVX,		/* deprecated */
	VDEC_CODEC_HEVC,

	VDEC_CODEC_MIN = VDEC_CODEC_NONE,
	VDEC_CODEC_MAX = VDEC_CODEC_HEVC,
} VDEC_CODEC_T;


/**
 * Drip type ; I frame
 */
typedef enum
{
	VDEC_DRIP_I_FRAME	= 0,
	VDEC_DRIP_NORMAL	= 1
} VDEC_DRIP_TYPE_T;


/**
 * constant about Good video
 */
typedef enum
{
	VDEC_BAD_VIDEO		= 0,
	VDEC_GOOD_VIDEO		= 1
} VDEC_VIDEO_STATUS_T;


/**
 * video의 size, bitrate등을 얻고자 할 경우에 쓰이는데 주로 메모리 MAP관련시에 쓰인다.
 */
typedef enum {
	VDEC_HDR_V_SIZE                    = 0,		/**< vertical size */
	VDEC_HDR_H_SIZE                    = 1,		/**< horizontal size */
	VDEC_HDR_VIDEO_FORMAT              = 2,		/**< video format */
	VDEC_HDR_FRAME_RATE                = 3,		/**< frame rate */
	VDEC_HDR_ASPECT_RATIO              = 4,		/**< aspect ratio */
	VDEC_HDR_BIT_RATE                  = 5,		/**< bit rate*/
	VDEC_HDR_PROGRESSIVE_SEQUENCE      = 6,		/**< progressive sequence */
	VDEC_HDR_PICTURE_TYPE              = 7,		/**< picture type */
	VDEC_HDR_TEMP_REF                  = 8,		/**< temporal reference */
	VDEC_HDR_PICTURE_STRUCT            = 9,		/**< picture reference */
	VDEC_HDR_TOP_FF                    = 10,	/**< top field first */
	VDEC_HDR_REPT_FF                   = 11,	/**< repeat field first */
	VDEC_HDR_PROGRESSIVE_FRAME         = 12,	/**< progressive frame */
	VDEC_HDR_INVALID                   = 13
} VDEC_HDR_T;


/**
 * Decoding speed of video decoder
 *
 */
typedef enum VDEC_DECODING_SPEED
{
    VDEC_DECODE_SPEED_PAUSE  =    0,
    VDEC_DECODE_SPEED_SLOW   =  500,
    VDEC_DECODE_SPEED_NORMAL = 1000,
}VDEC_DECODING_SPEED_T;

/**
 * Vdec decode mode.
 */
typedef enum	VDEC_DECODE_MODE
{
	VDEC_DECODE_ALL,
	VDEC_DECODE_IP,
	VDEC_DECODE_I
} VDEC_DECODE_MODE_T;

/* [L8] kangsik.yoon (2011/04/13)
 * vdec internal buffer flush
 */
typedef enum	VDEC_FLUSH_MODE
{
	VDEC_FLUSH_CPB,
	VDEC_FLUSH_CMD,
	VDEC_FLUSH_CPB_CMD,
	VDEC_FLUSH_ALL
} VDEC_FLUSH_MODE_T;


/**
 * VDEC input video DTV format.
 *
 * @see
*/
typedef enum VDEC_DTV_FORMAT
{
	DTV1920X1080		= 0,
	DTV1440X1080		= 1,
	DTV1280X1080		= 2,
	DTV1280X720 		= 3,
	DTV960X720 			= 4,
	DTV720X576			= 5,
	DTV704X576			= 6,
	DTV640X576			= 7,
	DTV544X576			= 8,
	DTV480X576			= 9,
	DTV352X576			= 10,
	DTV352X288			= 11,
	DTV768X576			= 12,
	DTV528X576			= 13,
	DTV768X480			= 14,
	DTV720X480			= 15,
	DTV704X480			= 16,
	DTV640X480			= 17,
	DTV544X480			= 18,
	DTV528X480			= 19,
	DTV480X480			= 20,
	DTV352X480			= 21,
	DTV352X240			= 22,
	DTV_FORMAT_INVALID	= 23
} VDEC_DTV_FORMAT_T;

/**
 * AFD Mode Information
 *
 */
typedef enum VDEC_AFD_MODE
{
	VDEC_AFD_4_3_1000		= 0x08,// AFD_43_SAME
	VDEC_AFD_4_3_1001		= 0x09,// AFD_43_TO_43
	VDEC_AFD_4_3_1010		= 0x0a,// AFD_43_TO_169
	VDEC_AFD_4_3_1011		= 0x0b,// AFD_43_TO_149
	VDEC_AFD_4_3_1100		= 0x0c,// AFD_43_TO_RSVD
	VDEC_AFD_4_3_1101		= 0x0d,// AFD_43_TO_43SP149
	VDEC_AFD_4_3_1110		= 0x0e,// AFD_43_TO_169SP149
	VDEC_AFD_4_3_1111		= 0x0f,// AFD_43_TO_SP43
	VDEC_AFD_4_3_INVALID	= 0x00,// AFD_43_INVALID
	VDEC_AFD_16_9_1000		= 0x18,// AFD_169_SAME
	VDEC_AFD_16_9_1001		= 0x19,// AFD_169_TO_43
	VDEC_AFD_16_9_1010		= 0x1a,// AFD_169_TO_169
	VDEC_AFD_16_9_1011		= 0x1b,// AFD_169_TO_149
	VDEC_AFD_16_9_1100		= 0x1c,// AFD_169_TO_RSVD
	VDEC_AFD_16_9_1101		= 0x1d,// AFD_169_TO_43SP149
	VDEC_AFD_16_9_1110		= 0x1e,// AFD_169_TO_169SP149
	VDEC_AFD_16_9_1111		= 0x1f,// AFD_169_TO_SP43
	VDEC_AFD_16_9_INVALID	= 0x10,// AFD_169_INVALID
} VDEC_AFD_MODE_T;


/**
 * Pciture type
 *
 */
typedef enum VDEC_PIC_TYPE
{
	VDEC_SEQ_HEADER		= 0x00, // sequence header
	VDEC_I_PIC		    = 0x01, // I picture type
	VDEC_P_PIC		    = 0x02, // P picture type
	VDEC_B_PIC		    = 0x03, // B picture type
} VDEC_PIC_TYPE_T;


/**
 * userdata의 DCC type.
 * VIDEO_API.h에도 정의 됨.
 *
 * @ingroup ka_vdec_types
 */
typedef enum
{
	DCC_UNKNOWN       	= 0x0,
	DCC_EIA708        	= 0x1,	/**< EIA-708 Format */
	DCC_DVS157        	= 0x2,	/**< DVS-157 Format */
	DCC_EIA708_DVS157 	= 0x3,	/**< EIA-708 + DVS-157  Format */
	DCC_TEST1         	= 0x6,
	DCC_TEST2         	= 0xa,
	DCC_EIA608			= 0x8
} VDEC_DCC_TYPE_T;


/**
 * DTVCC Service type.
 *
 * @see DDI Implementation Guide
*/
typedef enum
{
	DTVCC_SERVICE1		= 0x1,
	DTVCC_SERVICE2		= 0x2,
	DTVCC_SERVICE3		= 0x3,
	DTVCC_SERVICE4		= 0x4,
	DTVCC_SERVICE5		= 0x5,
	DTVCC_SERVICE6		= 0x6,
	DTVCC_SERVICE_INVALID	= 0x7
} VDEC_DCC_SERVICE_NUM_T;


/**
 * Video decoder PTS
 *
 */
typedef struct VDEC_PTS
{
	UINT32				decodingPicturePTS;	   /* PTS of current decoding picture */
	UINT32				displayPicturePTS;     /* PTS of current displaying picture */
} VDEC_PTS_T;


/**
 * Video decoder status
 *
 */
typedef struct VDEC_DECODER_STATUS
{
	VDEC_STATE_T		vdecState;
	VDEC_CODEC_T		codecType;
	BOOLEAN				bLipSyncAV;
	BOOLEAN				bStillPicture;
	BOOLEAN				bDripDecoding;
	UINT32				esBufDataSize;	   /* depth in bytes of the compressed buffer */
	UINT32				decodedQueueDepth; /* the number of decoded pictures currently ready to be displayed */
	UINT32				nMBDecErrorRate;   /* Rate of MB Dec Error at one frame, nMBDecErrorRate = Err MBs / Tatal MBs */
	UINT32				bPtsMatched;	   /* Indicate PTS matched */
} VDEC_DECODER_STATUS_T;


typedef void (*PFN_PIC_INFO_TO_DVR_T)(UINT8 vdec_ch);
typedef void (*PFN_VDEC_INFO_TO_DVR_T) (UINT8 vdec_ch, UINT8 pic_type);
typedef DTV_STATUS_T (*PFN_VDEC_CAPTION_TO_SENC_T) (UINT8 * pbuf, UINT32 dataLength, UINT8 copyType);
typedef void (*DDI_VDEC_MHP_AFD_CALLBACK_PTR_T) (UINT8 afdValue);



#ifdef __cplusplus
extern "C"
{
#endif

typedef struct VDEC_USERDATA_CALLBACK
{
	UINT8 picType;   	/**< picture type */
	UINT8 rpt_ff;     	/**< repeat first field */
	UINT8 top_ff;     	/**< top field first */
	UINT8 tmp_ref;
	UINT64 pts;

	void *offset;
	UINT32 size;
} VDEC_USERDATA_CALLBACK_T;

typedef DTV_STATUS_T (*PFN_VDEC_USERDATA_CALLBACK_T) (UINT8 port, int id, VDEC_USERDATA_CALLBACK_T *data);

typedef unsigned long OSA_MSGQ_T;


/**
 * Initialize VDEC.
 * Create semaphore and thread (process message, process AFD)
 * @return API_OK, API_ERROR when error
 */
DTV_STATUS_T HAL_VDEC_Initialize(void);


DTV_STATUS_T HAL_VDEC_Open(UINT8 nPort);


DTV_STATUS_T HAL_VDEC_Connect(UINT8 nPort, UINT8 nSrc, UINT8 nDst);


DTV_STATUS_T HAL_VDEC_Close(UINT8 nPort);


/**
 * start VDEC.
 * call GNSS gmPE_Start().
 * @param nPort [in] deprecated, set 0
 * @param codec [in] video codec to set
 * @return API_OK, API_ERROR when error
 */
DTV_STATUS_T HAL_VDEC_Start(UINT8 nPort, VDEC_CODEC_T codec);

/**
 * stop VDEC.
 * @param nPort [in] deprecated, set 0
 * @return API_OK, API_ERROR when error
 * @see gmPE_Stop()
 */
DTV_STATUS_T HAL_VDEC_Stop(UINT8 nPort);

/**
 * Pause VDEC.
 * just do not pass to display, decoding is going on.
 *
 * @param nPort [in] deprecated, set 0
 * @param frz [in] freeze: 1, melt: 0
 * @return API_OK, API_ERROR when error
 */
DTV_STATUS_T HAL_VDEC_Freeze(UINT8 nPort, UINT8 nFreeze);

/**
 * Start still-picture(I-Frame) decoding.
 * MHEG I-frame function use this function.
 *
 * @param nPort [in] deprecated, set 0
 * @param pDripData [in] ptr in system memory containing I-frame data
 * @param dripSize [in] byte size of I-frame
 * @return API_OK, API_ERROR when error
 */
DTV_STATUS_T HAL_VDEC_StartDripDec(UINT8 nPort,
		UINT8* pDripData, UINT32 dripSize,
		VDEC_DRIP_TYPE_T dripType, VDEC_CODEC_T codecType);

/**
 * Stop still-picture(I-Frame) decoding.
 * MHEG I-frame function use this function.
 *
 * @param nPort [in] deprecated, set 0
 * @return API_OK, API_ERROR when error
 */
DTV_STATUS_T HAL_VDEC_StopDripDec(UINT8 nPort);

/**
 * decode video frame and save to ppARGBData
 */
DTV_STATUS_T HAL_VDEC_SaveDripDec(UINT8 nPort,
		UINT8* pDripData, UINT32 dripsize,
		VDEC_DRIP_TYPE_T driptype, VDEC_CODEC_T codec,
		UINT8 **ppARGBData,
		UINT32* pDestSize, UINT32* pDestWidth);

/**
 * free frame memory allocated at HAL_VDEC_SaveDripDec()
 */
void HAL_VDEC_SaveDripDec_Free (UINT8 nPort, UINT8 *pARGBData);

/**
 * Get MPEG decoding information.
 * V size, H size, frame rate, aspect ratio, progressive.
 *
 * @param nPort [in] deprecated, set 0
 * @param infonum [in] info. number to get
 * @return information value
 */
SINT32 HAL_VDEC_GetVideoInfo(UINT8 nPort, VDEC_HDR_T infonum);

/**
 * Gets video decoder status.
 * It contains whether decoder start or not, lip sync status.
 *
 * @param nPort [IN] specifies a video nPort
 * @param pStatus [OUT] pointer to the variable to store the video decoder status
 * @return  DTV_STATUS_T
 **/
DTV_STATUS_T HAL_VDEC_GetDecoderStatus(UINT8 nPort, VDEC_DECODER_STATUS_T *pStatus);

/**
 * Synchronize AV.
 * @param nPort [in] deprecated, set 0
 * @param onOff [in] on off
 * @return API_OK, API_ERROR when error
 */
DTV_STATUS_T HAL_VDEC_SyncAV(UINT8 nPort , UINT8 onOff);

/**
 * return AFD value
 * @param nPort [in] deprecated, set 0
 * @return AFD value
 * @see VDEC_DecodeAFD()
 */
VDEC_AFD_MODE_T HAL_VDEC_GetAFD(UINT8 nPort);

/**
 * DDI fuction for starting to gether user data.
 *
 * @param nPort [in] deprecated, set 0
 * @return DTV_STATUS_T
 * @see HAL_VDEC_StopUserData()
 */
DTV_STATUS_T HAL_VDEC_StartUserData(UINT8 nPort);

/**
 * DDI fuction for stopping to gether user data.
 *
 * @param nPort [in] deprecated, set 0
 * @return DTV_STATUS_T
 * @see HAL_VDEC_StartUserData()
 */
DTV_STATUS_T HAL_VDEC_StopUserData(UINT8 nPort);

//void HAL_VDEC_InitCntCheck(void);

/**
 * Sets the decoding speed of the VDEC.
 * The normal decoding speed value for input parameter is 1000.
 * Please use the following value VDEC_MORMAL_PLAY_SPEED when you input the speed value.
 *
 * @param nPort [IN] specifies a video nPort.
 * @param speed [IN] decoding speed(#define VDEC_NORMAL_PLAY_SPEED 1000)
 * @return  API_OK if success, else API_ERROR
 **/
DTV_STATUS_T HAL_VDEC_SetDecodingSpeed(UINT8 nPort, VDEC_DECODING_SPEED_T speed);

#if 0
/**
 * Registers callback function for DVR middleware.
 * DVR middleware need to know the picture type information for current decoding video.
 * Picture_type is as follows.
 * - sequence header
 * - I picture type
 * - P picture type
 * - B picture type
 * After VDEC decodes a frame, notify DVR middleware the picture type(I, P, B) and vdec_ch.
 * After the sequence header is detected, notify DVR middleware the picture type(sequence header) and vdec_ch.
 *
 * @param fnCbFn [IN] callback function
 * @return void
 */
void HAL_VDEC_RegisterDVRCallback(PFN_VDEC_INFO_TO_DVR_T pfnDVRCallback);
#endif

void HAL_VDEC_RegisterUserdataCallback(UINT8 port, PFN_VDEC_USERDATA_CALLBACK_T pfnCaptionCallback);

/**
 * Frame advance is a feature to single-step decoding frame by frame.
 * It means that 1 frame forward mode(1 frame decofing and stop).
 * It is dependent on the video decoder HW performance.
 * It HW does not supnPort some speed mode, this function returns NOT_SUPPORTED error for that speed mode.
 *
 * @param bFrameAdvanceOn [IN] specifies Frame Advance mode
 * @return  DTV_STATUS_T
 **/
DTV_STATUS_T HAL_VDEC_SetFrameAdvance(UINT8 nPort, BOOLEAN bFrameAdvanceOn);


DTV_STATUS_T HAL_VDEC_SetStillPicture(UINT8 nPort, BOOLEAN bStillPicture);

/**
 * Frame advance is a feature to single-step decoding frame by frame. but it doesn't wait any response
 * It means that 1 frame forward mode(1 frame decofing and stop).
 * It is dependent on the video decoder HW performance.
 * It HW does not supnPort some speed mode, this function returns NOT_SUPPORTED error for that speed mode.
 *
 * @param bFrameAdvanceOn [IN] specifies Frame Advance mode
 * @return  DTV_STATUS_T
 **/
#if defined(MTK_PLATFORM) && (PLATFORM_TYPE == MTK_PLATFORM)
DTV_STATUS_T HAL_VDEC_SetFrameAdvanceNoSync(UINT8 nPort, BOOLEAN bFrameAdvanceOn);
#endif

/**
 * Reset video decoder. This flushes the video decoder
 *
 * @param nPort [IN] specifies a video nPort
 * @return  DTV_STATUS_T
 **/
DTV_STATUS_T HAL_VDEC_Reset(UINT8 nPort);

#if defined(LG_PLATFORM) && (PLATFORM_TYPE == LG_PLATFORM)
/* [L8] kangsik.yoon (2011/04/13)
 * vdec internal buffer flush
 */
DTV_STATUS_T HAL_VDEC_Flush(UINT8 nPort, VDEC_FLUSH_MODE_T vFlushMode);
#endif
/**
 * Get Current PTS of video decoder.
 *
 * @param nPort [IN] specifies a video nPort
 * @param pVdecPTS [OUT] PTS of video decoder
 * @return  DTV_STATUS_T
 **/
DTV_STATUS_T HAL_VDEC_GetCurPTS(UINT8 nPort, VDEC_PTS_T *pVdecPTS);


/**
 * DDI fuction for smooth fast forward
 *
 * @param  decodeMode [IN] enable/disable  drop field.
 * @return void
 */
void	HAL_VDEC_SetDecodeMode(UINT8 nPort, VDEC_DECODE_MODE_T decodeMode);

/**
 * DDI fuction for getting total number of display pictures since Start.
 * This function is used to determine if uploaded 1 frame is decoded.
 * @param void
 * @return BOOLEAN
 */
BOOLEAN		HAL_VDEC_IsFrameAdvanced(UINT8 nPort);

/**
 * VDEC debug menu.
 *
 * @param void
 * @return void
 */
void HAL_VDEC_DebugMenu(void);



typedef struct VDEC_PICINFO_MSG
{
	UINT8			ch;
	UINT16			nFramerate;

	/* MPEG2 aspect_ratio_information in sequence header */
	UINT16			aspect_ratio;
	UINT16			nHSize;
	UINT16			nVSize;
	UINT32			nBitrate;
	UINT8			afd;
	UINT8			bProgressiveSeq;
	UINT8			bProgressiveFrame;
	UINT16			nActiveX;
	UINT16			nActiveY;
	UINT16			nActiveW;
	UINT16			nActiveH;

	UINT16			display_horizontal_size;
	UINT16			display_vertical_size;

	/* H264 aspect_ratio_idc in vdu_parameters() */
	UINT8			aspect_ratio_idc;

	UINT32			sar_width;
	UINT32			sar_height;

#define HAL_VDEC_3DINFO_2D						0
#define HAL_VDEC_3DINFO_TOP_BOTTOM				1
#define HAL_VDEC_3DINFO_SIDEBYSIDE_HALF			2
#define HAL_VDEC_3DINFO_CHECKER_BOARD			3
#define HAL_VDEC_3DINFO_FRAME_SEQ				4
#define HAL_VDEC_3DINFO_COLUMN_INTERLEAVE		5
#define HAL_VDEC_3DINFO_LINE_INTERLEAVE_HALF	6
#define HAL_VDEC_3DINFO_DUALSTREAM				11
	UINT8			info3D;
} VDEC_PIC_INFO_MSG_T;

typedef void (*PFN_VDEC_PIC_INFO_T) (UINT8 port, VDEC_PIC_INFO_MSG_T *info);

/**
 * Registers callback function for middleware.  Middleware need to know the
 * time when the first I-Picture is decoded.  After VDEC decodes a I-Picture
 * frame, notify middleware the picture type and vdec_ch.
 */
DTV_STATUS_T HAL_VDEC_RegisterPicInfoCallback(UINT8 port, PFN_VDEC_PIC_INFO_T cb);


typedef struct VDEC_PICINFO_MSG_EXT
{
	/* start of struct VDEC_PICINFO_MSG */
	UINT8			ch;
	UINT16			nFramerate;
	UINT16			aspect_ratio;
	UINT16			nHSize;
	UINT16			nVSize;
	UINT32			nBitrate;
	UINT8			afd;
	UINT8			bProgressiveSeq;
	UINT8			bProgressiveFrame;
	UINT16			nActiveX;
	UINT16			nActiveY;
	UINT16			nActiveW;
	UINT16			nActiveH;
	UINT16			display_horizontal_size;
	UINT16			display_vertical_size;
	UINT8			aspect_ratio_idc;
	UINT32			sar_width;
	UINT32			sar_height;
	UINT8			info3D;
	/* end of struct VDEC_PICINFO_MSG */

	/* new members for HDR */
	UINT32			colourPrimaries;				// defined VUI
	UINT32			transferChareristics;			// defined VUI
	UINT32			matrixCoeffs;					// defined VUI

	UINT32			displayPrimariesX0;				// defined SEI
	UINT32			displayPrimariesY0;				// defined SEI
	UINT32			displayPrimariesX1;				// defined SEI
	UINT32			displayPrimariesY1;				// defined SEI
	UINT32			displayPrimariesX2;				// defined SEI
	UINT32			displayPrimariesY2;				// defined SEI

	UINT32			whitePointX;					// defined SEI
	UINT32			whitePointY;					// defined SEI
	UINT32			maxDisplayMasteringLuminance;	// defined SEI
	UINT32			minDisplayMasteringLuminance;	// defined SEI

	UINT8			overscanAppropriate;			// defined VUI
} VDEC_PIC_INFO_MSG_EXT_T;

typedef void (*PFN_VDEC_PIC_INFO_EXT_T) (UINT8 port, VDEC_PIC_INFO_MSG_EXT_T *info);

/* to support for HLG */
DTV_STATUS_T HAL_VDEC_RegisterPicInfoCallbackExt(UINT8 port, PFN_VDEC_PIC_INFO_EXT_T pfnPicInfoCallback);

typedef struct VDEC_PICINFO_MSG_V02 {
	/* start of struct VDEC_PICINFO_MSG */
	UINT8			ch;			// VDEC ch
	UINT16			nFramerate;		// Framerate of Video
	UINT16			aspect_ratio;		// aspect_ratio_information in Sequence header
	UINT16			nHSize;			// Full horizontal size of Video
	UINT16			nVSize;			// Full vertical size of Video
	UINT32			nBitrate;		// Bitrate of Video data (kbps)
	UINT8			afd;			// Afd value in picture user data
	UINT8			bProgressiveSeq; 	// Progressive sequence
	UINT8			bProgressiveFrame;	// Progressive frame
	UINT16			nActiveX;		// X position for Active area
	UINT16			nActiveY;		// Y position for Active area
	UINT16			nActiveW;		// Width of Active area
	UINT16			nActiveH;		// Height of Active area

	UINT16			display_horizontal_size;	// display_horizontal_size in Sequence Display Extension of MPEG2
	UINT16			display_vertical_size;		// display_vertical_size in Sequence Display Extension of MPEG2

	UINT8			aspect_ratio_idc;	// aspect_ratio_idc in SPS of H.264
	UINT32			sar_width;		// sar_width
	UINT32			sar_height;		// sar_height

	UINT8			info3D;			// 3D info in SEI of H.264
	/* end of struct VDEC_PICINFO_MSG */

	/* new members for HDR */
	UINT32			colourPrimaries;				// defined VUI
	UINT32			transferChareristics;			// defined VUI
	UINT32			matrixCoeffs;					// defined VUI

	UINT32			displayPrimariesX0;				// defined SEI
	UINT32			displayPrimariesY0;				// defined SEI
	UINT32			displayPrimariesX1;				// defined SEI
	UINT32			displayPrimariesY1;				// defined SEI
	UINT32			displayPrimariesX2;				// defined SEI
	UINT32			displayPrimariesY2;				// defined SEI

	UINT32			whitePointX;					// defined SEI
	UINT32			whitePointY;					// defined SEI
	UINT32			maxDisplayMasteringLuminance;	// defined SEI
	UINT32			minDisplayMasteringLuminance;	// defined SEI

	UINT8			overscanAppropriate;			// defined VUI
	/* end of new members for HDR */

	/* new members for HLG */
	UINT32			videoFullRangeFlag;				// defined VUI (HLG)
	UINT32			hdrTransferCharacteristicIdc;	// defined SEI (HLG)
	/* end of new members for HLG */
} VDEC_PIC_INFO_MSG_V02_T;

typedef DTV_STATUS_T (*PFN_VDEC_PIC_INFO_TYPE_T)(UINT8 port, UINT8 type, void* pMsg);

DTV_STATUS_T HAL_VDEC_RegisterPicInfoCallbackType(UINT8 port, UINT8 type, PFN_VDEC_PIC_INFO_TYPE_T pfnPicInfoCallback);


typedef void (*PFN_VDEC_FRAME_CALLBACK_T) (UINT8 port, VDEC_PIC_TYPE_T type, unsigned int pts);

/**
 * Registers callback function for every frame. VDEC dil need this callback
 * for Good video check.
 *
 * As soon as VDEC decodes every frame, notify VDEC dil the picture type(I, P,
 * B) , pts value and vdec_ch.  After the sequence header is detected, notify
 * VDEC dil the picture type(sequence header), pts value and vdec_ch.
 */
DTV_STATUS_T HAL_VDEC_RegisterFrameCallback (UINT8 port, PFN_VDEC_FRAME_CALLBACK_T cb);


/**
 * copy current displaying output to dest output port
 *
 * -1 for turn off mirror output.
 */
DTV_STATUS_T HAL_VDEC_MirrorOutput (UINT8 port, int dest);


typedef enum
{
	VDEC_PARAM_LIPSYNC_FIRSTCOMES,
	VDEC_PARAM_LIPSYNC_ADEC_MASTER,
	VDEC_PARAM_LIPSYNC_VDEC_MASTER,
} VDEC_PARAM_LIPSYNC_T;

typedef enum
{
	VDEC_PARAM_3DMODE = 0,		/**< Dual 3D mode on/off */
	VDEC_PARAM_NOT_USE_STC,		/**< use STC as lipsync clock source.
								  default:0 */
	VDEC_PARAM_AUDIO_CHANNEL,	/**< audio channel to keep sync with.
								  default:-1 */
	VDEC_PARAM_DISPLAY_DELAY,	/**< display delay between PTS and STC. in
								  milliseconds.  default:INT_MAX */
	VDEC_PARAM_LIPSYNC_MASTER,	/**< set lipsync master mode for NOT_USE_STC.
								  @val should be VDEC_PARAM_LIPSYNC_T */
	VDEC_PARAM_ADD_DELAY,		/**< add display delay on default delay
								  setting. default:0 */
	VDEC_PARAM_VSYNC_THRESHOLD,	/**< set display match range in milliseconds
								  unit */
	VDEC_PARAM_PVR_MODE_INFO,	/**< true for PVR mode */

	VDEC_PARAM_MAX
} VDEC_PARAM_T;

/**
 * set parameter to vdec
 */
DTV_STATUS_T HAL_VDEC_SetParam(UINT8 nPort,VDEC_PARAM_T param, SINT32 val);

/**
 * get parameter from vdec
 */
DTV_STATUS_T HAL_VDEC_GetParam(UINT8 nPort,VDEC_PARAM_T param, SINT32 *val);


/*
 * Commercial TV mode setting
 */
typedef enum
{
	VDEC_PARAM2_SECURE_CPB,		/**< protect CPB memory */
} VDEC_PARAM2_T;



typedef enum
{
	VDEC_DECODER_TYPE_DEFAULT,		/**< default decoder */
	VDEC_DECODER_TYPE_D14_MCU0,		/**< external UHD video decoder, MCU0 */
	VDEC_DECODER_TYPE_D14_MCU1,		/**< external UHD video decoder, MCU1 */
} VDEC_DECODER_TYPE_T;


#ifdef __cplusplus
}
#endif

/* vim:set ts=4 sw=4: */
#endif /*_hal_vdec.h_ */
