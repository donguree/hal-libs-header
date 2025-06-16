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
    HAL_VO_PIXEL_FORMAT_NONE = 0,   /**< none of these */
    HAL_VO_PIXEL_FORMAT_PALETTE,    /**< palette color type */
    HAL_VO_PIXEL_FORMAT_GRAYSCALE,  /**< 8bit gray scale */
    HAL_VO_PIXEL_FORMAT_RGB,    /**< 24bit RGB */
    HAL_VO_PIXEL_FORMAT_BGR,    /**< 24bit RGB */
    HAL_VO_PIXEL_FORMAT_ARGB,   /**< 32bit ARGB */
    HAL_VO_PIXEL_FORMAT_ABGR,   /**< 32bit ABGR */
    HAL_VO_PIXEL_FORMAT_YUV444P,  /**< planar format with each U/V values plane (YYYY UUUU VVVV) */
    HAL_VO_PIXEL_FORMAT_YUV444I,  /**< planar format with interleaved U/V values (YYYY UVUVUVUV) */
    HAL_VO_PIXEL_FORMAT_YUV422P,  /**< semi-planar format with each U/V values plane (2x1 subsampling ; YYYY UU VV) */
    HAL_VO_PIXEL_FORMAT_YUV422I,  /**< semi-planar format with interleaved U/V values (2x1 subsampling ; YYYY UVUV) */
    HAL_VO_PIXEL_FORMAT_YUV422YUYV, /**< interleaved YUV values (Y0U0Y0V0Y1U1Y1V1) for MStar Chip Vender */
    HAL_VO_PIXEL_FORMAT_YUV420P,  /**< semi-planar format with each U/V values plane (2x2 subsampling ; YYYYYYYY UU VV) */
    HAL_VO_PIXEL_FORMAT_YUV420I,  /**< semi-planar format with interleaved U/V values (2x2 subsampling ; YYYYYYYY UVUV) */
    HAL_VO_PIXEL_FORMAT_YUV400,   /**< 8bit Y plane without U/V values */
    HAL_VO_PIXEL_FORMAT_YUV224P,  /**< semi-planar format with each U/V values plane, 1 Ysamples has 2 U/V samples to horizontal (Y0Y1 U0U0U1U1V0V0V1V1) */
    HAL_VO_PIXEL_FORMAT_YUV224I,  /**< semi-planar format with interleaved U/V values (Y0Y1 U0V0U0V0U1V1U1V1) */
    HAL_VO_PIXEL_FORMAT_YUV444SP,  /**< sequential packed with non-planar (YUVYUVYUV...) */
    HAL_VO_PIXEL_FORMAT_ALPHAGRAYSCALE,    /**< gray scale with alpha */
    HAL_VO_PIXEL_FORMAT_MAX,    /**< maximum number of HAL_VO_PIXEL_FORMAT */
} HAL_VO_PIXEL_FORMAT;

/**
 * @brief This enumeration describes a video output (VO) configuration set.
 **/
typedef enum {
    HAL_VO_PANEL_TYPE_NONE = 0, /**< none of these */
    HAL_VO_PANEL_TYPE_FHD,  /**< full HD panel (1920x1080) */
    HAL_VO_PANEL_TYPE_UHD,  /**< ultra HD panel (3840x2160) */
    HAL_VO_PANEL_TYPE_8K_UHD,  /**< 8K UHD panel (7680X4320) */
    HAL_VO_PANEL_TYPE_HD1024X768,   /**< HD panel (1024x768) */
    HAL_VO_PANEL_TYPE_HD1280X720,   /**< HD panel (1280x720) */
    HAL_VO_PANEL_TYPE_HD1366X768,   /**< HD panel (1366x768) */
    HAL_VO_PANEL_TYPE_QHD,   /**< QHD panel (2560x1440) */
    HAL_VO_PANEL_TYPE_MAX,  /**< maximum number of HAL_VO_PANEL_TYPE */
} HAL_VO_PANEL_TYPE;

/**
 * @brief This enumeration describes a video output (VO) configuration set.
 **/
typedef enum {
    HAL_VO_CFG_TYPE_NONE = 0,   /**< none of these */
    HAL_VO_CFG_TYPE_ALPHA_BLEND,    /**< set alpha blend */
    HAL_VO_CFG_TYPE_INPUT_RECT, /**< set video input source */
    HAL_VO_CFG_TYPE_OUTPUT_RECT,    /**< set video output source */
    HAL_VO_CFG_TYPE_PIXEL_FORMAT,   /**< set pixel format of video source */
    HAL_VO_CFG_TYPE_FRAME_RATE, /**< set frame rate */
    HAL_VO_CFG_TYPE_TIMES,      /**< set frame rate magnification */
    HAL_VO_CFG_TYPE_MAX,    /**< maximum number of HAL_VO_CONFIG_TYPE */
} HAL_VO_CFG_TYPE;

/**
 * @brief This enumeration describes supported pixel format for a video output (VO).
 **/
typedef enum {
    HAL_VO_SUPPORT_PIXEL_FORMAT_NONE = 0x00000000, /**< none of these */
    HAL_VO_SUPPORT_PIXEL_FORMAT_PALETTE = 0x00000001,    /**< palette color type */
    HAL_VO_SUPPORT_PIXEL_FORMAT_GRAYSCALE = 0x00000002,    /**< 8bit gray scale */
    HAL_VO_SUPPORT_PIXEL_FORMAT_RGB = 0x00000004,  /**< 24bit RGB */
    HAL_VO_SUPPORT_PIXEL_FORMAT_BGR = 0x00000008,  /**< 24bit BGR */
    HAL_VO_SUPPORT_PIXEL_FORMAT_ARGB = 0x00000010, /**< 32bit ARGB */
    HAL_VO_SUPPORT_PIXEL_FORMAT_ABGR = 0x00000020, /**< 32bit ABGR */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV444P = 0x00000040,  /**< planar format with each U/V values plane (YYYY UUUU VVVV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV444I = 0x00000080,  /**< planar format with interleaved U/V values (YYYY UVUVUVUV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV422P = 0x00000100,  /**< semi-planar format with each U/V values plane (2x1 subsampling ; YYYY UU VV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV422I = 0x00000200,  /**< semi-planar format with interleaved U/V values (2x1 subsampling ; YYYY UVUV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV422YUYV = 0x00000400,   /**< interleaved YUV values (Y0U0Y0V0Y1U1Y1V1) for MStar Chip Vender */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV420P = 0x00000800,  /**< semi-planar format with each U/V values plane (2x2 subsampling ; YYYYYYYY UU VV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV420I = 0x00001000,  /**< semi-planar format with interleaved U/V values (2x2 subsampling ; YYYYYYYY UVUV) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV400 = 0x00002000,   /**< 8bit Y plane without U/V values */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV224P = 0x00004000,  /**< semi-planar format with each U/V values plane, 1 Ysamples has 2 U/V samples to horizontal (Y0Y1 U0U0U1U1V0V0V1V1) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV224I = 0x00008000,  /**< semi-planar format with interleaved U/V values (Y0Y1 U0V0U0V0U1V1U1V1) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_YUV444SP = 0x00010000,  /**< sequential packed with non-planar (YUVYUVYUV...) */
    HAL_VO_SUPPORT_PIXEL_FORMAT_ALPHAGRAYSCALE = 0x00020000,    /**< gray scale with alpha */
} HAL_VO_SUPPORT_PIXEL_FORMAT_T;

/**
 * @brief This enumeration describes supported panel type for a video output (VO).
 **/
typedef enum {
    HAL_VO_SUPPORT_PANEL_TYPE_NONE = 0x00000000,
    HAL_VO_SUPPORT_PANEL_TYPE_HD1024X768 = 0x00000001,  /**< HD panel (1024x768) */
    HAL_VO_SUPPORT_PANEL_TYPE_HD1280X720 = 0x00000002,  /**< HD panel (1280x720) */
    HAL_VO_SUPPORT_PANEL_TYPE_HD1366X768 = 0x00000004,  /**< HD panel (1366x768) */
    HAL_VO_SUPPORT_PANEL_TYPE_FHD = 0x00000008,         /**< full HD panel (1920x1080) */
    HAL_VO_SUPPORT_PANEL_TYPE_UHD = 0x00000010,         /**< ultra HD panel (3840x2160) */
    HAL_VO_SUPPORT_PANEL_TYPE_QHD = 0x00000020,         /**< quad HD panel (2560x1440) */
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
    unsigned int x; /**< x coordinate of its top-left point */
    unsigned int y; /**< y coordinate of its top-left point */
    unsigned int w; /**< width of it */
    unsigned int h; /**< height of it */
} HAL_VO_RECT_T;

/**
 * @brief This structure describes a image information to VO.
 **/
typedef struct {
    unsigned char *buf; /**< buffer pointer of decoded raw data */
    unsigned char *ofs_y;   /**< offset of Y component */
    unsigned char *ofs_uv;  /**< offset of UV components */
    unsigned int len_buf;   /**< buffer length of decoded raw data */
    unsigned int stride;    /**< stride size of decoded raw data */
    HAL_VO_RECT_T rect; /**< image data rectangular */
    HAL_VO_PIXEL_FORMAT pixel_format;   /**< pixel format of image */
} HAL_VO_IMAGE_T;

/**
 * @brief This struct describes a value set for the configuration type.
 **/
typedef struct {
    unsigned int alpha; /**< alpha blending factor (0~255) */
    HAL_VO_RECT_T rect; /**< rectangular information for the video source */
    HAL_VO_PIXEL_FORMAT pixel_format;   /**< pixel format of image */

    unsigned int frame_rate;  /**< input frame rate value */
    unsigned int vsync_times; /**< input frame rate magnification */

} HAL_VO_CFG_VALUE_T;

/**
 * @brief This structure describes a video output (VO) configuration set.
 **/
typedef struct {
    HAL_VO_CFG_TYPE type;   /**< configuration type to set VO */
    HAL_VO_CFG_VALUE_T value;   /**< configuration value */
} HAL_VO_CFG_T;

/**
 * @brief This structure describes a video output (VO) capability of device.
 **/
typedef struct {
    HAL_VO_SUPPORT_PANEL_TYPE_T support_panel_type;     /**< supported panel type */
    HAL_VO_SUPPORT_PIXEL_FORMAT_T support_pixel_format; /**< supported pixel format */
    unsigned char is_seperated_vo_port;                 /**< whether to be seperated vo port */
    unsigned char is_changeable_cs_dynamically;         /**< whether to be able to change color space dynamically */
    unsigned int vo_port_nb;                            /**< the number of vo ports */
    unsigned int framebuffer_length;                    /**< the length of framebuffer */
    HAL_VO_RECT_T framebuffer_rect;                     /**< the rect of framebuffer */
} HAL_VO_DEVICE_CAPABILITY_T;

/**
 * @brief This structure describes a framebuffer for the video output (VO).
 **/
typedef struct {
    unsigned char* buf;                 /**< buffer pointer of the framebuffer */
    unsigned int buf_length;            /**< the length of buffer */
    unsigned int stride;                /**< stride size of the framebuffer */
    HAL_VO_RECT_T resolution;           /**< resolution of the framebuffer */
    HAL_VO_PIXEL_FORMAT pixel_format;   /**< pixel format of the framebuffer */
} HAL_VO_FB_FRAMEBUFFER_T;

/**
 * @brief This structure describes a framebuffer property for the video output (VO).
 **/
typedef struct {
    HAL_VO_FB_FRAMEBUFFER_PROPERTY_FLAGS_T flags;	/**< framebuffer property flags */
    HAL_VO_PIXEL_FORMAT pixel_format;               /**< pixel format of the framebuffer */
    unsigned int alpha;                             /**< value for the alpha blending */
    HAL_VO_RECT_T input;                            /**< input rect of source */
    HAL_VO_RECT_T output;                           /**< output rect of source */
} HAL_VO_FB_FRAMEBUFFER_PROPERTY_T;

/**
 * @brief Open the video output module.
 *
 * @rst
 * Functional Requirements
 *   Open the video output module.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_VO_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_VO_STATE_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 120ms.
 *
 * Constraints
 *  It has to link hal_photo.so library.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      ch  [in]    channel port number to connect with display engine
 *      def [in]    video panel type
 *
 * Return Value
 *  If success HAL_VO_STATE_OK, else an one of error in HAL_VO_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ret = HAL_VO_Open(0, HAL_VO_PANEL_TYPE_FHD);
 *     if (ret != API_OK)
 *       printf("fail to open VO");
 *
 * @endrst
 **/
DTV_STATUS_T HAL_VO_Open(unsigned int ch, HAL_VO_PANEL_TYPE def);


/**
 * @brief Configure the video output.
 *
 * @rst
 * Functional Requirements
 *   Configure the video output.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_VO_STATE_T.
 *
 * Performance Requirements
 *  The response time of this function should be within 5ms.
 *
 * Constraints
 *  It has to link hal_photo.so library.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      ch  [in]    channel port number to connect with display engine
 *      cfg [in]    configuration to set video output
 *
 * Return Value
 *  If success HAL_VO_STATE_OK, else an one of error in HAL_VO_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     HAL_VO_CFG_T config;
 *     config.type = HAL_VO_CONFIG_TYPE_PIXEL_FORMAT;
 *     config.value.pixel_format = HAL_VO_PIXEL_FORMAT_YUV420I;
 *     ret = HAL_VO_Config(0, config);
 *     if(ret != API_OK)
 *       printf("fail to configure VO");
 *
 * @endrst
 **/
DTV_STATUS_T HAL_VO_Config(unsigned int ch, HAL_VO_CFG_T *cfg);


/**
 * @brief display intput image.
 *
 * @rst
 * Functional Requirements
 *   Write the raw data to video output. Flush the video output.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_VO_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_VO_STATE_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 100ms.
 *
 * Constraints
 *  It has to link hal_photo.so library.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      ch    [in]    channel port number to connect with display engine
 *      image [in]    image to display at video
 *
 * Return Value
 *  If success HAL_VO_STATE_OK, else an one of error in HAL_VO_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ret = HAL_VO_DisplayPicture(0, image);
 *     if (ret != API_OK)
 *       printf("fail to display video output");
 *
 * @endrst
 **/
DTV_STATUS_T HAL_VO_DisplayPicture(unsigned int ch, HAL_VO_IMAGE_T *image);


/**
 * @brief Close the video output module.
 *
 * @rst
 * Functional Requirements
 *   Close the video output module.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_VO_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_VO_STATE_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 15ms.
 *
 * Constraints
 *  It has to link hal_photo.so library.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      ch  [in]    channel port number to connect with display engine
 *
 * Return Value
 *  If success HAL_VO_STATE_OK, else an one of error in HAL_VO_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ret = HAL_VO_Close (0);
 *     if (ret != API_OK)
 *       printf("fail to close VO");
 *
 * @endrst
 **/
DTV_STATUS_T HAL_VO_Close(unsigned int ch);


/**
 * @brief Get a video output (VO) capability of device.
 *
 * @rst
 * Functional Requirements
 *   Get a video output (VO) capability of device.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_VO_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_VO_STATE_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 10ms.
 *
 * Constraints
 *  It has to link hal_photo.so library.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      capability [in] pointer of the device capability instance
 *
 * Return Value
 *  If success HAL_VO_STATE_OK, else an one of error in HAL_VO_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     HAL_VO_DEVICE_CAPABILITY cap;
 *     DTV_STATUS_T ret = HAL_VO_GetDeviceCapability(cap);
 *     if (ret != API_OK)
 *       printf("fail to get device capability");
 *
 * @endrst
 **/
DTV_STATUS_T HAL_VO_GetDeviceCapability(HAL_VO_DEVICE_CAPABILITY_T* capability);


/**
 * @brief Connect VO with Scalar.
 *
 * @rst
 * Functional Requirements
 *   Connect VO with Scalar.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_VO_STATE_T.
 *
 * Performance Requirements
 *  None
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *   - ch  [in]    channel port number to connect with display engine
 *   - dest [in]   connected scalar index
 *
 * Return Value
 *  If success HAL_VO_STATE_OK, else an one of error in HAL_VO_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ret = HAL_VO_Connect(0, 0);
 *     if (ret != API_OK)
 *       printf("fail to open VO");
 *
 * @endrst
 **/
DTV_STATUS_T HAL_VO_Connect(unsigned int ch, unsigned int dest);


/**
 * @brief re-flush video output
 *
 * @rst
 * Parameters
 *   - ch  [in]    channel port number to connect with display engine
 *
 * Return Values
 *   If success OK, else one of error in DTV_STATUS_T.
 *
 * Pseudocode
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T HAL_VO_RedrawPicture(unsigned int ch) {
 *       Flush the video output
 *       If any eror THEN
 *         RETURN value a one of error in DTV_STATUS_T
 *       ELSE
 *         RETURN API_OK
 *       END IF
 *     }
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ret = HAL_VO_RedrawPicture(0);
 *     if (ret != API_OK)
 *       printf("fail to redraw video output");
 *
 * @endrst
 **/
DTV_STATUS_T HAL_VO_RedrawPicture(unsigned int ch);


/**
 * @brief Initialize framebuffer to render the photo
 *
 * @rst
 * Parameters
 *   - ch  [in]    channel port number to connect with display engine
 *
 * Return Values
 *   If success OK, else one of error in DTV_STATUS_T.
 *
 * Pseudocode
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T HAL_VO_FB_Initialize(unsigned int ch) {
 *       Init a video resource
 *
 *       If any eror THEN
 *         RETURN value a one of error in DTV_STATUS_T
 *       ELSE
 *         RETURN API_OK
 *       END IF
 *     }
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret = HAL_VO_FB_Initialize(0);
 *     if (ret != API_OK)
 *       printf("fail to initialize HAL_VO_FB");
 *
 * @endrst
 **/
DTV_STATUS_T HAL_VO_FB_Initialize(unsigned int ch);

/**
 * @brief Finalize the framebuffer
 *
 * @rst
 * Parameters
 *   - ch  [in]    channel port number to connect with display engine
 *
 * Return Values
 *   If success OK, else one of error in DTV_STATUS_T.
 *
 * Pseudocode
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T HAL_VO_FB_Finalize(unsigned int ch) {
 *       Final a video resource
 *
 *       If any eror THEN
 *         RETURN value a one of error in DTV_STATUS_T
 *       ELSE
 *         RETURN API_OK
 *       END IF
 *     }
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret = HAL_VO_FB_Finalize(0);
 *     if (ret != API_OK)
 *       printf("fail to finalize HAL_VO_FB");
 *
 * @endrst
 **/
DTV_STATUS_T HAL_VO_FB_Finalize(unsigned int ch);

/**
 * @brief Get a target framebuffer to draw a photo
 *
 * @rst
 * Parameters
 *   - ch  [in]    channel port number to connect with display engine
 *   - framebuffer [in] framebuffer instance pointer to update the photo
 *
 * Return Values
 *   If success OK, else one of error in DTV_STATUS_T.
 *
 * Pseudocode
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T HAL_VO_FB_GetTargetFrameBuffer(const unsigned int ch, HAL_VO_FB_FRAMEBUFFER_T* framebuffer) {
 *       FLIP current frame index
 *       SET target framebuffer to able to draw some image
 *
 *       If any eror THEN
 *         RETURN value a one of error in DTV_STATUS_T
 *       ELSE
 *         RETURN API_OK
 *       END IF
 *     }
 *
 * Example
 *   .. code-block:: cpp
 *
 *     HAL_VO_FB_FRAMEBUFFER_T framebuffer;
 *     DTV_STATUS_T ret = HAL_VO_FB_GetTargetFrameBuffer(0, &framebuffer);
 *     if (ret != API_OK)
 *     printf("fail to get target framebuffer");
 *
 *     drawImage(&framebuffer);
 *
 *     ret = HAL_VO_FB_UpdateFrameBuffer(0, &framebuffer);
 *     if (ret != API_OK)
 *       printf("fail to update framebuffer");
 *
 * @endrst
 **/
DTV_STATUS_T HAL_VO_FB_GetTargetFrameBuffer(const unsigned int ch, HAL_VO_FB_FRAMEBUFFER_T* framebuffer);

/**
 * @brief Update the framebuffer including the new photo
 *
 * @rst
 * Parameters
 *   - ch  [in]    channel port number to connect with display engine
 *   - framebuffer [in] framebuffer instance pointer to update the photo
 *
 * Return Values
 *   If success OK, else one of error in DTV_STATUS_T.
 *
 * Pseudocode
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T HAL_VO_FB_UpdateFrameBuffer(const unsigned int ch, const HAL_VO_FB_FRAMEBUFFER_T* framebuffer) {
 *       MAP input framebuffer to the port
 *
 *       If any eror THEN
 *         RETURN value a one of error in DTV_STATUS_T
 *       ELSE
 *         RETURN API_OK
 *       END IF
 *     }
 *
 * Example
 *   .. code-block:: cpp
 *
 *     HAL_VO_FB_FRAMEBUFFER_T framebuffer;
 *     DTV_STATUS_T ret = HAL_VO_FB_GetTargetFrameBuffer(0, &framebuffer);
 *     if (ret != API_OK)
 *       printf("fail to get target framebuffer");
 *
 *     drawImage( &framebuffer );
 *
 *     ret = HAL_VO_FB_UpdateFrameBuffer(0, &framebuffer);
 *     if (ret != API_OK)
 *       printf("fail to update framebuffer");
 *
 * @endrst
 **/
DTV_STATUS_T HAL_VO_FB_UpdateFrameBuffer(const unsigned int ch, const HAL_VO_FB_FRAMEBUFFER_T* framebuffer);

/**
 * @brief Update the property of the framebuffer
 *
 * @rst
 * Parameters
 *   - ch  [in]    channel port number to connect with display engine
 *   - framebuffer [in] framebuffer instance pointer to update the photo
 *   - property [in] framebuffer property information to set the parameters such as alpha and input / output region
 *
 * Return Values
 *   If success OK, else one of error in DTV_STATUS_T.
 *
 * Pseudocode
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T HAL_VO_FB_FB_UpdateFrameBufferProperty(const unsigned int ch, const HAL_VO_FB_FRAMEBUFFER_T* framebuffer, const HAL_VO_FB_FRAMEBUFFER_PROPERTY_T* property) {
 *       UPDATE the input / output rect of the port
 *       UPDATE the alpha variable of the port
 *       UPDATE the color space
 *
 *       If any eror THEN
 *         RETURN value a one of error in DTV_STATUS_T
 *       ELSE
 *         RETURN API_OK
 *       END IF
 *     }
 *
 * Example
 *   .. code-block:: cpp
 *
 *     HAL_VO_FRAMEBUFFER_T framebuffer;
 *     DTV_STATUS_T ret = HAL_VO_FB_GetTargetFrameBuffer(0, &framebuffer);
 *     if (ret != API_OK)
 *       printf("fail to get target framebuffer");
 *
 *     HAL_VO_FB_FRAMEBUFFER_PROPERTY_T property;
 *     ret = HAL_VO_FB_UpdateFrameBufferProperty(0, &framebuffer, &property);
 *     if (ret != API_OK)
 *       printf("fail to update a property of the framebuffer");
 *
 * @endrst
 **/
DTV_STATUS_T HAL_VO_FB_UpdateFrameBufferProperty(const unsigned int ch, const HAL_VO_FB_FRAMEBUFFER_T* framebuffer, const HAL_VO_FB_FRAMEBUFFER_PROPERTY_T* property);

#endif /* _HAL_VO_H_ */
