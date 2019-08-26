/******************************************************************************
 *   LCD TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2011 - 2017 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/


/** @file hal_vo.h
 *
 *  Video Output (VO) Abstraction Layer header
 *
 *  @note This file is a prototype to provide each chip vender (MTK, MStar, SIC).
 *  @date 2017.02.13.
 **/

#ifndef _HAL_VO_H_
#define _HAL_VO_H_


#include "hal_common.h"

/**
 * @brief This enumeration describes the supported pixel formats.
 **/
typedef enum {
    HAL_VO_PIXEL_FORMAT_NONE = 0,   /* none of these */
    HAL_VO_PIXEL_FORMAT_PALETTE,    /* palette color type */
    HAL_VO_PIXEL_FORMAT_GRAYSCALE,  /* 8bit gray scale */
    HAL_VO_PIXEL_FORMAT_RGB,    /* 24bit RGB */
    HAL_VO_PIXEL_FORMAT_BGR,    /* 24bit RGB */
    HAL_VO_PIXEL_FORMAT_ARGB,   /* 32bit ARGB */
    HAL_VO_PIXEL_FORMAT_ABGR,   /* 32bit ABGR */
    HAL_VO_PIXEL_FORMAT_YUV444P,  /* planar format with each U/V values plane (YYYY UUUU VVVV) */
    HAL_VO_PIXEL_FORMAT_YUV444I,  /* planar format with interleaved U/V values (YYYY UVUVUVUV) */
    HAL_VO_PIXEL_FORMAT_YUV422P,  /* semi-planar format with each U/V values plane (2x1 subsampling ; YYYY UU VV) */
    HAL_VO_PIXEL_FORMAT_YUV422I,  /* semi-planar format with interleaved U/V values (2x1 subsampling ; YYYY UVUV) */
    HAL_VO_PIXEL_FORMAT_YUV422YUYV, /* interleaved YUV values (Y0U0Y0V0Y1U1Y1V1) for MStar Chip Vender */
    HAL_VO_PIXEL_FORMAT_YUV420P,  /* semi-planar format with each U/V values plane (2x2 subsampling ; YYYYYYYY UU VV) */
    HAL_VO_PIXEL_FORMAT_YUV420I,  /* semi-planar format with interleaved U/V values (2x2 subsampling ; YYYYYYYY UVUV) */
    HAL_VO_PIXEL_FORMAT_YUV400,   /* 8bit Y plane without U/V values */
    HAL_VO_PIXEL_FORMAT_YUV224P,  /* semi-planar format with each U/V values plane, 1 Ysamples has 2 U/V samples to horizontal (Y0Y1 U0U0U1U1V0V0V1V1) */
    HAL_VO_PIXEL_FORMAT_YUV224I,  /* semi-planar format with interleaved U/V values (Y0Y1 U0V0U0V0U1V1U1V1) */
    HAL_VO_PIXEL_FORMAT_YUV444SP,  /* sequential packed with non-planar (YUVYUVYUV...) */
    HAL_VO_PIXEL_FORMAT_ALPHAGRAYSCALE,    /* gray scale with alpha */
    HAL_VO_PIXEL_FORMAT_MAX,    /* maximum number of HAL_VO_PIXEL_FORMAT */
} HAL_VO_PIXEL_FORMAT;

/**
 * @brief This enumeration describes a video output (VO) configuration set.
 **/
typedef enum {
    HAL_VO_PANEL_TYPE_NONE = 0, /* none of these */
    HAL_VO_PANEL_TYPE_FHD,  /* full HD panel (1920x1080) */
    HAL_VO_PANEL_TYPE_UHD,  /* ultra HD panel (3840x2160) */
    HAL_VO_PANEL_TYPE_8K_UHD,  /* 8K UHD panel (7680X4320) */
    HAL_VO_PANEL_TYPE_HD1024X768,   /* HD panel (1024x768) */
    HAL_VO_PANEL_TYPE_HD1280X720,   /* HD panel (1280x720) */
    HAL_VO_PANEL_TYPE_HD1366X768,   /* HD panel (1366x768) */
    HAL_VO_PANEL_TYPE_MAX,  /* maximum number of HAL_VO_PANEL_TYPE */
} HAL_VO_PANEL_TYPE;

/**
 * @brief This enumeration describes a video output (VO) configuration set.
 **/
typedef enum {
    HAL_VO_CFG_TYPE_NONE = 0,   /* none of these */
    HAL_VO_CFG_TYPE_ALPHA_BLEND,    /* set alpha blend */
    HAL_VO_CFG_TYPE_INPUT_RECT, /* set video input source */
    HAL_VO_CFG_TYPE_OUTPUT_RECT,    /* set video output source */
    HAL_VO_CFG_TYPE_PIXEL_FORMAT,   /* set pixel format of video source */
    HAL_VO_CFG_TYPE_MAX,    /* maximum number of HAL_VO_CONFIG_TYPE */
} HAL_VO_CFG_TYPE;

/**
 * @brief This enumeration describes supported pixel format for a video output (VO).
 **/
typedef enum {
    HAL_VO_SUPPORT_PIXEL_FORMAT_NONE = 0x00000000, /* none of these */
    HAL_VO_SUPPORT_PIXEL_FORMAT_PALETTE = 0x00000001,    /* palette color type */
    HAL_VO_SUPPORT_PIXEL_FORMAT_GRAYSCALE = 0x00000002,    /* 8bit gray scale */
    HAL_VO_SUPPORT_PIXEL_FORMAT_RGB = 0x00000004,  /* 24bit RGB */
    HAL_VO_SUPPORT_PIXEL_FORMAT_BGR = 0x00000008,  /* 24bit BGR */
    HAL_VO_SUPPORT_PIXEL_FORMAT_ARGB = 0x00000010, /* 32bit ARGB */
    HAL_VO_SUPPORT_PIXEL_FORMAT_ABGR = 0x00000020, /* 32bit ABGR */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV444P = 0x00000040,  /* planar format with each U/V values plane (YYYY UUUU VVVV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV444I = 0x00000080,  /* planar format with interleaved U/V values (YYYY UVUVUVUV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV422P = 0x00000100,  /* semi-planar format with each U/V values plane (2x1 subsampling ; YYYY UU VV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV422I = 0x00000200,  /* semi-planar format with interleaved U/V values (2x1 subsampling ; YYYY UVUV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV422YUYV = 0x00000400,   /* interleaved YUV values (Y0U0Y0V0Y1U1Y1V1) for MStar Chip Vender */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV420P = 0x00000800,  /* semi-planar format with each U/V values plane (2x2 subsampling ; YYYYYYYY UU VV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV420I = 0x00001000,  /* semi-planar format with interleaved U/V values (2x2 subsampling ; YYYYYYYY UVUV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV400 = 0x00002000,   /* 8bit Y plane without U/V values */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV224P = 0x00004000,  /* semi-planar format with each U/V values plane, 1 Ysamples has 2 U/V samples to horizontal (Y0Y1 U0U0U1U1V0V0V1V1) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV224I = 0x00008000,  /* semi-planar format with interleaved U/V values (Y0Y1 U0V0U0V0U1V1U1V1) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV444SP = 0x00010000,  /* sequential packed with non-planar (YUVYUVYUV...) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_ALPHAGRAYSCALE = 0x00020000,    /* gray scale with alpha */
} HAL_VO_SUPPORT_PIXEL_FORMAT_T;

/**
 * @brief This enumeration describes supported panel type for a video output (VO).
 **/
typedef enum {
    HAL_VO_SUPPORT_PANEL_TYPE_NONE = 0x00000000,
    HAL_VO_SUPPORT_PANEL_TYPE_HD1024X768 = 0x00000001,  /* HD panel (1024x768) */
    HAL_VO_SUPPORT_PANEL_TYPE_HD1280X720 = 0x00000002,  /* HD panel (1280x720) */
    HAL_VO_SUPPORT_PANEL_TYPE_HD1366X768 = 0x00000004,  /* HD panel (1366x768) */
    HAL_VO_SUPPORT_PANEL_TYPE_FHD = 0x00000008,         /* full HD panel (1920x1080) */
    HAL_VO_SUPPORT_PANEL_TYPE_UHD = 0x00000010,         /* ultra HD panel (3840x2160) */
} HAL_VO_SUPPORT_PANEL_TYPE_T;

/**
 * @brief This enumeration describes a framebuffer property flags for the video output (VO).
 **/
typedef enum {
    HAL_VO_FB_FRAMEBUFFER_PROPERTY_FLAGS_NONE = 0x00000000,
    HAL_VO_FB_FRAMEBUFFER_PROPERTY_FLAGS_COLORSPACE = 0x00000001,
    HAL_VO_FB_FRAMEBUFFER_PROPERTY_FLAGS_ALPHABLENDING = 0x00000002,
    HAL_VO_FB_FRAMEBUFFER_PROPERTY_FLAGS_INPUTRECT = 0x00000004,
    HAL_VO_FB_FRAMEBUFFER_PROPERTY_FLAGS_OUTPUTRECT = 0x00000008,
} HAL_VO_FB_FRAMEBUFFER_PROPERTY_FLAGS_T;

/**
 * @brief This structure describes a rectangle specified by a point and a dimension.
 **/
typedef struct {
    unsigned int x; /* x coordinate of its top-left point */
    unsigned int y; /* y coordinate of its top-left point */
    unsigned int w; /* width of it */
    unsigned int h; /* height of it */
} HAL_VO_RECT_T;

/**
 * @brief This structure describes a image information to VO.
 **/
typedef struct {
    unsigned char *buf; /* buffer pointer of decoded raw data */
    unsigned char *ofs_y;   /* offset of Y component */
    unsigned char *ofs_uv;  /* offset of UV components */
    unsigned int len_buf;   /* buffer length of decoded raw data */
    unsigned int stride;    /* stride size of decoded raw data */
    HAL_VO_RECT_T rect; /* image data rectangular */
    HAL_VO_PIXEL_FORMAT pixel_format;   /* pixel format of image */
} HAL_VO_IMAGE_T;

/**
 * @brief This struct describes a value set for the configuration type.
 **/
typedef struct {
    unsigned int alpha; /* alpha blending factor (0~255) */
    HAL_VO_RECT_T rect; /* rectangular information for the video source */
    HAL_VO_PIXEL_FORMAT pixel_format;   /* pixel format of image */
} HAL_VO_CFG_VALUE_T;

/**
 * @brief This structure describes a video output (VO) configuration set.
 **/
typedef struct {
    HAL_VO_CFG_TYPE type;   /* configuration type to set VO */
    HAL_VO_CFG_VALUE_T value;   /* configuration value */
} HAL_VO_CFG_T;

/**
 * @brief This structure describes a video output (VO) capability of device.
 **/
typedef struct {
    HAL_VO_SUPPORT_PANEL_TYPE_T support_panel_type;     /* supported panel type */
    HAL_VO_SUPPORT_PIXEL_FORMAT_T support_pixel_format; /* supported pixel format */
    unsigned char is_seperated_vo_port;                 /* whether to be seperated vo port */
    unsigned char is_changeable_cs_dynamically;         /* whether to be able to change color space dynamically */
    unsigned int vo_port_nb;                            /* the number of vo ports */
    unsigned int framebuffer_length;                    /* the length of framebuffer */
    HAL_VO_RECT_T framebuffer_rect;                     /* the rect of framebuffer */
} HAL_VO_DEVICE_CAPABILITY_T;

/**
 * @brief This structure describes a framebuffer for the video output (VO).
 **/
typedef struct {
    unsigned char* buf;                 /* buffer pointer of the framebuffer */
    unsigned int buf_length;            /* the length of buffer */
    unsigned int stride;                /* stride size of the framebuffer */
    HAL_VO_RECT_T resolution;           /* resolution of the framebuffer */
    HAL_VO_PIXEL_FORMAT pixel_format;   /* pixel format of the framebuffer */
} HAL_VO_FB_FRAMEBUFFER_T;

/**
 * @brief This structure describes a framebuffer property for the video output (VO).
 **/
typedef struct {
    HAL_VO_FB_FRAMEBUFFER_PROPERTY_FLAGS_T flags;	/* framebuffer property flags */
    HAL_VO_PIXEL_FORMAT pixel_format;               /* pixel format of the framebuffer */
    unsigned int alpha;                             /* value for the alpha blending */
    HAL_VO_RECT_T input;                            /* input rect of source */
    HAL_VO_RECT_T output;                           /* output rect of source */
} HAL_VO_FB_FRAMEBUFFER_PROPERTY_T;

/**
 * @brief Open the video output module.
 * @param   ch  [in]    channel port number to connect with display engine
 * @param   def [in]    video panel type
 * @return if success OK, else one of error in DTV_STATUS_T.
 **/
DTV_STATUS_T HAL_VO_Open(unsigned int ch, HAL_VO_PANEL_TYPE def);

/**
 * @brief Configure the video output
 * @param   ch  [in]    channel port number to connect with display engine
 * @param   cfg [in]    configuration to set video output
 * @return if success OK, else one of error in DTV_STATUS_T.
 **/
DTV_STATUS_T HAL_VO_Config(unsigned int ch, HAL_VO_CFG_T *cfg);

/**
 * @brief display intput image
 * @param   ch  [in]    channel port number to connect with display engine
 * @param   image   [in]    image to display at video
 * @return if success OK, else one of error in DTV_STATUS_T.
 **/
DTV_STATUS_T HAL_VO_DisplayPicture(unsigned int ch, HAL_VO_IMAGE_T *image);

/**
 * @brief re-flush video output
 * @param   ch  [in]    channel port number to connect with display engine
 * @return if success OK, else one of error in DTV_STATUS_T.
 **/
DTV_STATUS_T HAL_VO_RedrawPicture(unsigned int ch);

/**
 * @brief Close the video output module.
 * @param   ch  [in]    channel port number to connect with display engine
 * @return if success OK, else one of error in DTV_STATUS_T.
 **/
DTV_STATUS_T HAL_VO_Close(unsigned int ch);

/**
 * @brief Get a video output (VO) capability of device
 * @param capability [in] pointer of the device capability instance
 * @return if success OK, else one of error in DTV_STATUS_T
 **/
DTV_STATUS_T HAL_VO_GetDeviceCapability(HAL_VO_DEVICE_CAPABILITY_T* capability);

/**
 * @brief Initialize framebuffer to render the photo
 * @param ch [in] channel port number to connect with display engine
 * @return if success OK, else one of error in DTV_STATUS_T
 **/
DTV_STATUS_T HAL_VO_FB_Initialize(unsigned int ch);

/**
 * @brief Finalize the framebuffer
 * @param ch [in] channel port number to connect with display engine
 * @return if success OK, else one of error in DTV_STATUS_T
 **/
DTV_STATUS_T HAL_VO_FB_Finalize(unsigned int ch);

/**
 * @brief Get a target framebuffer to draw a photo
 * @param ch [in] channel port number to connect with display engine
 * @param framebuffer [in] framebuffer instance pointer to update the photo
 * @return if success OK, else one of error in DTV_STATUS_T
 **/
DTV_STATUS_T HAL_VO_FB_GetTargetFrameBuffer(const unsigned int ch, HAL_VO_FB_FRAMEBUFFER_T* framebuffer);

/**
 * @brief Update the framebuffer including the new photo
 * @param ch [in] channel port number to connect with display engine
 * @param framebuffer [in] framebuffer instance pointer to update the photo
 * @return if success OK, else one of error in DTV_STATUS_T
 **/
DTV_STATUS_T HAL_VO_FB_UpdateFrameBuffer(const unsigned int ch, const HAL_VO_FB_FRAMEBUFFER_T* framebuffer);

/**
 * @brief Update the property of the framebuffer
 * @param ch [in] channel port number to connect with display engine
 * @param framebuffer [in] framebuffer instance pointer to update the photo
 * @param property [in] framebuffer property information to set the parameters such as alpha and input / output region
 * @return if success OK, else one of error in DTV_STATUS_T
 **/
DTV_STATUS_T HAL_VO_FB_UpdateFrameBufferProperty(const unsigned int ch, const HAL_VO_FB_FRAMEBUFFER_T* framebuffer, const HAL_VO_FB_FRAMEBUFFER_PROPERTY_T* property);

#endif /* _HAL_VO_H_ */
