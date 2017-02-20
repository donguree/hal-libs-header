/******************************************************************************
 *   LCD TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2011 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/


/** @file hal_vt.h
 *
 *  HAL VT (VT:Video Texture)
 *
 *  @author     JinHyuk Hong (jinhyuk.hong@lge.com)
 *  @version    1.0
 *  @date       	2013.11.29
 *  @note
 *  @see
 */


#ifndef _HAL_VT_H_
#define _HAL_VT_H_

/*---------------------------------------------------------
    #include ÆÄÀÏµé
    (File Inclusions)
---------------------------------------------------------*/

/*----------------------------------------------------------------------------------------
	Extern Function Prototype Declaration
----------------------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "hal_common.h"

/**
 * @brief This enumeration describes the supported number of plane corresponding to plane type of video frame buffer.
 */
typedef enum
{
	HAL_VT_VIDEO_FRAME_BUFFER_PLANE_INTERLEAVED = 1,
	HAL_VT_VIDEO_FRAME_BUFFER_PLANE_SEMI_PLANAR,
	HAL_VT_VIDEO_FRAME_BUFFER_PLANE_PLANAR
} HAL_VT_VIDEO_FRAME_BUFFER_PLANE_NUMBER_T;

/**
 * @brief This enumeration describes the supported pixel format of video frame buffer.
 */
typedef enum
{
	HAL_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_PLANAR = 0,
	HAL_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_SEMI_PLANAR,
	HAL_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV420_INTERLEAVED,
	HAL_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_PLANAR,
	HAL_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_SEMI_PLANAR,
	HAL_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV422_INTERLEAVED,
	HAL_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_PLANAR,
	HAL_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_SEMI_PLANAR,
	HAL_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_YUV444_INTERLEAVED,
	HAL_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_RGB,
	HAL_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_ARGB
} HAL_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T;

/**
 * @brief This enumeration describes the supported video window.
 */
typedef enum
{
	HAL_VT_VIDEO_INVALID_WINDOW = -1,
	HAL_VT_VIDEO_WINDOW_0 = 0,
	HAL_VT_VIDEO_WINDOW_1 = 1,
	HAL_VT_VIDEO_WINDOW_2 = 2
} HAL_VT_VIDEO_WINDOW_TYPE_T;

/**
 * @brief This enumeration describes flags for state of video frame output device setting.
 */
typedef enum
{
	HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_NOFX 			= 0x00000000,
	HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_ENABLED 			= 0x00000001,
	HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FREEZED			= 0x00000002,
	HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_APPLIED_PQ		= 0x00000004,
	HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FRAMERATE_DIVIDE	= 0x00000010
} HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FLAGS_T;

/**
 * @brief This enumeration describes the dump location of video memory.
 */
typedef enum
{
	HAL_VT_SCALER_OUTPUT = 0,
	HAL_VT_DISPLAY_OUTPUT
} HAL_VT_DUMP_LOCATION_TYPE_T;

/**
 * @brief This enumeration describes the type of video.
 */
typedef enum
{
	HAL_VT_VIDEO_INTERLACED	= 0,
	HAL_VT_VIDEO_PROGRESSIVE
} HAL_VT_VIDEO_TYPE_T;

/**
 * @brief This structure describes a rectangle specified by a point and a dimension.
 */
typedef struct
{
	unsigned short	x;
	unsigned short	y;
	unsigned short	w;
	unsigned short	h;
} HAL_VT_RECT_T;

/**
 * @brief This structure describes the capability of video device.
 */
typedef struct
{
	unsigned int	numOfVideoWindow;
} HAL_VT_DEVICE_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the capability of video frame buffer.
 */
typedef struct 
{
	unsigned int numOfVideoFrameBuffer;
	HAL_VT_VIDEO_FRAME_BUFFER_PLANE_NUMBER_T numOfPlane;
} HAL_VT_VIDEO_FRAME_BUFFER_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the capability of video frame output device.
 */
typedef struct
{
	unsigned char	bSupportedControlEnabled;
	unsigned char	bSupportedControlFreezed;
	unsigned char	bSupportedControlFramerateDivide;
	unsigned char	bSupportedControlPQ;
} HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_CAPABILITY_INFO_T;

/**
 * @brief This structure describes the limitation of video frame output device.
 */
typedef struct {
	HAL_VT_RECT_T 	maxResolution;
	unsigned char	bLeftTopAlign;
	unsigned char	bSupportInputVideoDeInterlacing;
	unsigned char	bSupportDisplayVideoDeInterlacing;
	unsigned char	bSupportScaleUp;
	unsigned int	scaleUpLimitWidth;
	unsigned int	scaleUpLimitHeight;
	unsigned char	bSupportScaleDown;
	unsigned int	scaleDownLimitWidth;
	unsigned int	scaleDownLimitHeight;
} HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_LIMITATION_INFO_T;

/**
 * @brief This structure describes the constant property of video frame buffer.
 * These member values are unique properties of video frame buffer. it is not able to be changed.
 */
typedef struct
{
	HAL_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T pixelFormat;
	unsigned int	stride;
	unsigned int	width;
	unsigned int	height;
	unsigned int**	ppPhysicalAddress;
} HAL_VT_VIDEO_FRAME_BUFFER_PROPERTY_INFO_T;

/**
 * @brief This structure describes state information of video frame output device.
 */
typedef struct
{
	unsigned char	bEnabled;
	unsigned char	bFreezed;
	unsigned char	bAppliedPQ;
	unsigned int	framerateDivide;
} HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T;

/**
 * @brief This structure describes property information of video frame output device.
 */
typedef struct
{
	HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T stateInfo;
	unsigned int framerate;
	HAL_VT_DUMP_LOCATION_TYPE_T dumpLocation;
	HAL_VT_RECT_T outputRegion;
	unsigned char bBlockState;
} HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_PROPERTY_INFO_T;

/**
 * @brief This structure describes information of input video.
 */
typedef struct {
	HAL_VT_VIDEO_TYPE_T			type;
	HAL_VT_RECT_T				region;
	unsigned char				bIs3DVideo;
} HAL_VT_INPUT_VIDEO_INFO_T;

/**
 * @brief This structure describes information of output video.
 */
typedef struct {
	HAL_VT_VIDEO_TYPE_T			type;
	HAL_VT_RECT_T				maxRegion;
	HAL_VT_RECT_T				activeRegion;
} HAL_VT_OUTPUT_VIDEO_INFO_T;

/**
 * @brief This structure describes output information of video frame output device.
 */
typedef struct {
	unsigned int	stride;
	HAL_VT_RECT_T	maxRegion;
	HAL_VT_RECT_T	activeRegion;
} HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_OUTPUT_INFO_T;

/**
 * @brief This structure describes information of captured video frame
 * 		This legacy structure will be used to support legacy chipset. (M14, H13)
 * 		Then this legacy structure is not used from latest chip (H15, LM15U).
 */
typedef struct
{
	HAL_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T pixelFormat;
	unsigned short	stride;
	unsigned short	width;
	unsigned short	height;
	unsigned char	*pVideoFrameAddress[3];
} HAL_VT_LEGACY_VIDEO_FRAME_INFO_T;

/*----------------------------------------------------------------------------------------
    Type Definitions - end
----------------------------------------------------------------------------------------*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*----------------------------------------------------------------------------------------
    Initialize / Finalize Operation
----------------------------------------------------------------------------------------*/
/**
 *	@brief	Initializes Video module related to.
 *			Call Chipset driver initialization function and create resources for Video module related to VT.
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_Init(void);

/**
 *	@brief	Finalize Video module related to VT.
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_Finalize(void);

/*----------------------------------------------------------------------------------------
    Provide Capability of Device
----------------------------------------------------------------------------------------*/
/**
 *	@brief	Gets the capability of VIDEO Device.
 * 	@param	pDeviceCapabilityInfo					[OUT]	the capability of video device
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetDeviceCapability(HAL_VT_DEVICE_CAPABILITY_INFO_T *pDeviceCapabilityInfo);

/**
 *	@brief	Gets the capability of Video Frame Buffer.
 * 	@param	videoWindowID 						[IN] video window ID
 * 	@param	pVideoFrameBufferCapabilityInfo 			[OUT] the capability of video frame buffer
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetVideoFrameBufferCapability(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_VIDEO_FRAME_BUFFER_CAPABILITY_INFO_T *pVideoFrameBufferCapabilityInfo);
	
/**
 *	@brief	Gets the capability of Video Frame Output Device.
 * 	@param	videoWindowID 						[IN]		video window ID
 * 	@param	pVideoFrameOutputDeviceCapabilityInfo	[OUT]	the capability of video frame output device
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetVideoFrameOutputDeviceCapability(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_CAPABILITY_INFO_T *pVideoFrameOutputDeviceCapabilityInfo);

/**
 *	@brief	Gets the limitation of Video Frame Output Device.
 * 	@param	videoWindowID 						[IN]		video window ID
 * 	@param	pVideoFrameOutputDeviceLimitationInfo	[OUT]	the limitation of video frame output device
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetVideoFrameOutputDeviceLimitation(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_LIMITATION_INFO_T *pVideoFrameOutputDeviceLimitationInfo);

/*----------------------------------------------------------------------------------------
    Provide information of video frame buffer
----------------------------------------------------------------------------------------*/
/**
 *	@brief	Get properties of video frame buffer corresponding to videoWindowID.
 *	@param	videoWindowID						[IN]		video window ID
 *	@param	pVideoFrameOutputDeviceCapabilityInfo	[OUT]	the capability of video frame output device
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetAllVideoFrameBufferProperty(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_VIDEO_FRAME_BUFFER_PROPERTY_INFO_T *pVideoFrameBufferProperty);

/**
 *	@brief	Get index of video frame buffer corresponding to videoWindowID.
 *			The video frame buffer corresponding to current index is same with video frame buffer that last write operation is completed.
 *			This buffer may be 1~2 frame delayed buffer compared to video frame being displayed on the screen.
 *	@param	videoWindowID						[IN]		video window ID
 *	@param	pIndexOfCurrentVideoFrameBuffer		[OUT]	index of current video frame buffer
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetVideoFrameBufferIndex(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, unsigned int *pIndexOfCurrentVideoFrameBuffer);

/**
 *	@brief	Get secure video state of video frame buffer corresponding to videoWindowID.
 *			Vdec driver can know SVP state of own.
 			And VT driver can know which vdec is mapped to videoWindowID.
 			Therefore, If VT driver can get vdec's SVP state, VT driver can provide the SVP state information to VT client through this interface.
 *	@param	videoWindowID					[IN]		video window ID
 *	@param	pIsSecureVideo 					[OUT]	state of secure video corresponding to videoWIndowID
 *	@return if success API_OK, else API_ERROR.
 *	@author jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetVideoFrameBufferSecureVideoState(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, unsigned char *pIsSecureVideo);

/*----------------------------------------------------------------------------------------
    Provide control interface and information of Video Frame Output Device
----------------------------------------------------------------------------------------*/

/**
 *	@brief	Get state information of video frame output device corresponding to videoWindowID.
 *	@param	videoWindowID						[IN]		video window ID
 *	@param	pVideoFrameOutputDeviceState			[OUT]	state info of video frame output device
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetVideoFrameOutputDeviceState(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T *pVideoFrameOutputDeviceState);

/**
 *	@brief	Set state of video frame corresponding to videoInputID.
 *	@param	videoWindowID						[IN]		video window ID
 *	@param	videoFrameOutputDeviceStateFlags		[IN]		flags to state of video frame output device
 *	@param	pVideoFrameOutputDeviceState			[OUT]	state info of video frame output device
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_SetVideoFrameOutputDeviceState(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_FLAGS_T videoFrameOutputDeviceStateFlags, HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_STATE_INFO_T *pVideoFrameOutputDeviceState);

/**
 *	@brief	Get framerate of video frame output device corresponding to videoWindowID.
 *	@param	videoWindowID						[IN]		video window ID
 *	@param	pVideoFrameOutputDeviceFramerate		[OUT]	framerate of video frame output device
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetVideoFrameOutputDeviceFramerate(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, unsigned int *pVideoFrameOutputDeviceFramerate);

/**
 *	@brief	Get dump location of video frame output device corresponding to videoWindowID.
 *	@param	videoWindowID						[IN]		video window ID
 *	@param	pDumpLocation						[OUT]	dump location of VFOD
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetVideoFrameOutputDeviceDumpLocation(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_DUMP_LOCATION_TYPE_T *pDumpLocation);

/**
 *	@brief	Set dump location of video frame output device corresponding to videoWindowID.
 *	@param	videoWindowID						[IN]		video window ID
 *	@param	pDumpLocation						[IN]		dump location of VFOD
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_SetVideoFrameOutputDeviceDumpLocation(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_DUMP_LOCATION_TYPE_T dumpLocation);

/**
 *	@brief	Get output information of video frame output device corresponding to videoWindowID.
 *	@param	videoWindowID						[IN]		video window ID
 *	@param	pDumpLocation						[IN]		dump location of VFOD
 *	@param	pOutputInfo							[OUT]	output information of VFOD
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetVideoFrameOutputDeviceOutputInfo(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_DUMP_LOCATION_TYPE_T dumpLocation, HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_OUTPUT_INFO_T *pOutputInfo);

/**
 *	@brief	Set output region information of video frame output device corresponding to videoWindowID.
 *	@param	videoWindowID						[IN]		video window ID
 *	@param	pDumpLocation						[IN]		dump location of VFOD
 *	@param	pOutputRegion						[IN]		output region of VFOD
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_SetVideoFrameOutputDeviceOutputRegion(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_DUMP_LOCATION_TYPE_T dumpLocation, HAL_VT_RECT_T *pOutputRegion);

/**
 *	@brief	Get block state of video frame output device corresponding to videoWindowID.
 *	@param	videoWindowID					[IN]		video window ID
 *	@param	pbBlockState						[OUT]	block state of VFOD corresponding to videoWIndowID
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetVideoFrameOutputDeviceBlockState(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, unsigned char *pbBlockState);

/**
 *	@brief	Set block state of video frame output device corresponding to videoWindowID.
 *	@param	videoWindowID					[IN]		video window ID
 *	@param	bBlockState						[IN]		block state
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_SetVideoFrameOutputDeviceBlockState(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, unsigned char bBlockState);

/**
 *	@brief	Get property information of video frame output device corresponding to videoWindowID.
 *	@param	videoWindowID					[IN]		video window ID
 *	@param	pVideoFrameOutputDeviceProperty	[OUT]	property information of VFOD corresponding to videoWindowID
 *	@return	if success API_OK, else API_ERROR.
 *	@author	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetVideoFrameOutputDeviceProperty(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_PROPERTY_INFO_T *pVideoFrameOutputDeviceProperty);

/**
 *	@brief	Set property information of video frame output device corresponding to videoWindowID.
 *	@param	videoWindowID					[IN]		video window ID
 *	@param	pVideoFrameOutputDeviceProperty	[IN]		property information of VFOD corresponding to videoWindowID
 *	@return 	if success API_OK, else API_ERROR.
 *	@author 	jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_SetVideoFrameOutputDeviceProperty(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_VIDEO_FRAME_OUTPUT_DEVICE_PROPERTY_INFO_T *pVideoFrameOutputDeviceProperty);

/*----------------------------------------------------------------------------------------
    Provide VFOD vsync state
----------------------------------------------------------------------------------------*/
/**
 *	@brief	Wait for to be completed what the video frame buffer is being written new data by VFOD corresponding to videoWindowID.
 *	@param	videoWindowID						[IN]		video window ID
 *	@return if success API_OK, else API_ERROR.
 *	@author jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_WaitVsync(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID);

/*----------------------------------------------------------------------------------------
    Additional Features
----------------------------------------------------------------------------------------*/
/**
 *	@brief	Get input video original region information corresponding to videoWindowID.
 *			 (input video original region is resolution of input video.)
 *	@param	videoWindowID						[IN]		video window ID
 *	@param	pInputVideoInfo						[OUT]	input video information
 *	@return if success API_OK, else API_ERROR.
 *	@author jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetInputVideoInfo(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_INPUT_VIDEO_INFO_T *pInputVideoInfo);

/**
 *	@brief	Get output video information corresponding to videoWindowID.
 *			Output video resolution may change when aspect ratio information is changed.
 *	@param	videoWindowID						[IN]		video window ID
 *	@param	pOutputVideoInfo						[OUT]	output video information
 *	@return if success API_OK, else API_ERROR.
 *	@author jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetOutputVideoInfo(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_OUTPUT_VIDEO_INFO_T *pOutputVideoInfo);

/**
 *	@brief	Get video mute status of video path corresponding to videoWindowID.
 *	@param	videoWindowID						[IN]		video window ID
 *	@param	pbOnOff								[IN]		video mute status (Mute On : 1, Mute Off : 0)
 *	@return if success API_OK, else API_ERROR.
 *	@author jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_GetVideoMuteStatus(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, unsigned char *pbOnOff);

/*----------------------------------------------------------------------------------------
    Legacy Features
----------------------------------------------------------------------------------------*/
/**
 *	@brief	Capture video frame corresponding to videoWindowID
 * 			This legacy API will be used to support legacy chipset. (M14, H13)
 * 			Then this legacy structure is not used from latest chip (H15, LM15U).
 *
 *	@param	videoWindowID						[IN]		video window ID
 *	@param	dumpLocation							[IN]		dump location of VFOD
 *	@param	captureWidth							[IN]		width that to be captured
 *	@param	captureHeight							[IN]		width that to be captured
 *	@param	pVideoFrameInfo						[OUT]	information of captured video frame
 *	@return if success API_OK, else API_ERROR.
 *	@author jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_LegacyCaptureVideoFrame(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_DUMP_LOCATION_TYPE_T dumpLocation, unsigned short captureWidth, unsigned short captureHeight, HAL_VT_LEGACY_VIDEO_FRAME_INFO_T *pVideoFrameInfo);

/**
 *	@brief	Set default window info corresponding to videoWindowID.
 *	@param	videoWindowID
 *	@param	dumpLocation	
 *	@param	pInputVideoRegion	
 *	@param	pOutputRegion	
 *	@return if success API_OK, else API_ERROR.
 *	@author jinhyuk.hong (jinhyuk.hong@lge.com)
 */
DTV_STATUS_T HAL_VT_SetDefaultRegion(HAL_VT_VIDEO_WINDOW_TYPE_T videoWindowID, HAL_VT_DUMP_LOCATION_TYPE_T dumpLocation, HAL_VT_RECT_T *pInputVideoRegion, HAL_VT_RECT_T *pOutputRegion);

/*----------------------------------------------------------------------------------------
    API list for capturing 4 2k windows. 
----------------------------------------------------------------------------------------*/
DTV_STATUS_T HAL_VT_QUAD_Init(void);

DTV_STATUS_T HAL_VT_QUAD_Finalize(void);

DTV_STATUS_T HAL_VT_QUAD_GetFrameBufferProperty(UINT32 planeLR, HAL_VT_VIDEO_FRAME_BUFFER_PROPERTY_INFO_T *pVideoFrameBufferProperty);

DTV_STATUS_T HAL_VT_QUAD_GetFrameBufferIndex(UINT32 planeLR, unsigned int *pIndexOfCurrentVideoFrameBuffer);

DTV_STATUS_T HAL_VT_QUAD_WaitVsync(UINT32 planeLR);

/*----------------------------------------------------------------------------------------
    Provide VT Debug Test
----------------------------------------------------------------------------------------*/
void	HAL_VT_DEBUG_Test (void);

/*----------------------------------------------------------------------------------------
    HAL VTV (HAL VTV is independent module from HAL_VT. So two module should not be used at sametime.)
----------------------------------------------------------------------------------------*/
typedef struct {
    unsigned int width;
    unsigned int height;
} HAL_VTV_RESOLUTION_T;

typedef struct {
    unsigned char   bSupportInputVideoDeInterlacing;
    unsigned char   bSupportDisplayVideoDeInterlacing;
    unsigned char   bSupportScaleUp;
    unsigned char   bSupportScaleDown;
    unsigned int    scaleUpLimitWidth;
    unsigned int    scaleUpLimitHeight;
    unsigned int    scaleDownLimitWidth;
    unsigned int    scaleDownLimitHeight;
    HAL_VTV_RESOLUTION_T inputBufferMaxResolution;
    HAL_VTV_RESOLUTION_T outputBufferMaxResolution;
    unsigned int    nNumOfInputBuffer;
    unsigned int    nNumOfOutputBuffer;
    unsigned int    nNumOfPlane;
} HAL_VTV_DEVICE_CAPABILITY_INFO_T;

typedef struct
{
    HAL_VT_VIDEO_FRAME_BUFFER_PIXEL_FORMAT_T pixelFormat;
    unsigned int    stride;
    unsigned int    width;
    unsigned int    height;
    unsigned int    yFrame[3];
    unsigned int    uFrame[3];
    unsigned int    vFrame[3];
} HAL_VTV_VFB_PROPERTY_INFO_T;

typedef struct {
    HAL_VTV_VFB_PROPERTY_INFO_T inputBufferInfo;
    HAL_VTV_VFB_PROPERTY_INFO_T outputBufferInfo;
    unsigned int    inputBufferIndex;
    unsigned int    outputBufferIndex;
    unsigned int    vendorData; /**< reserved for chip vendor */
} HAL_VTV_CALLBACK_INFO_T;

typedef void (*HAL_VTV_CALLBACK)(HAL_VTV_CALLBACK_INFO_T *pInfo);

DTV_STATUS_T HAL_VTV_Init(void);
DTV_STATUS_T HAL_VTV_Finalize(void);
DTV_STATUS_T HAL_VTV_GetDeviceCapability(HAL_VTV_DEVICE_CAPABILITY_INFO_T* pCapabilityInfo);
DTV_STATUS_T HAL_VTV_RegisterCallback(HAL_VTV_CALLBACK cbFunc);
DTV_STATUS_T HAL_VTV_GetInputBufferResolution(HAL_VTV_RESOLUTION_T *pResolution);
DTV_STATUS_T HAL_VTV_SetInputBufferResolution(HAL_VTV_RESOLUTION_T *pResolution);
DTV_STATUS_T HAL_VTV_GetOutputBufferResolution(HAL_VTV_RESOLUTION_T *pResolution);
DTV_STATUS_T HAL_VTV_SetOutputBufferResolution(HAL_VTV_RESOLUTION_T *pResolution);
DTV_STATUS_T HAL_VTV_GetOutputBufferIndex(unsigned int *pIndex);
DTV_STATUS_T HAL_VTV_SetOutputBufferIndex(unsigned int index, unsigned int vendorData);
DTV_STATUS_T HAL_VTV_GetInputBufferFreeze(unsigned int bufferIndex, unsigned int *pbFreeze);
DTV_STATUS_T HAL_VTV_SetInputBufferFreeze(unsigned int bufferIndex, unsigned int bFreeze);

#ifdef __cplusplus
}
#endif
#endif
