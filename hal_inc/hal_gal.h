/******************************************************************************
 *   LCD TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2011 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/


/** @file appfrwk_openapi_gal.h
 *
 *  Graphic Abstraction Layer header
 *
 *  @author     JinHyuk Hong (jinhyuk.hong@lge.com)
 *  @version    1.0
 *  @date       	2013.02.25
 *  @note
 *  @see
 */


#ifndef _HAL_GAL_H_
#define _HAL_GAL_H_

/*---------------------------------------------------------
    (File Inclusions)
---------------------------------------------------------*/

/*----------------------------------------------------------------------------------------
	Extern Function Prototype Declaration
----------------------------------------------------------------------------------------*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "hal_common.h"

#define CURSOR_INDEX			2	/*cursor id */

#define	HAL_GAL_PHYS_OSD_MAX	2	/*GFXOSD_NUM_OF_OSDS*/		/** hooked from gfxosd ddi */

/**
 * @brief This enumeration describes the GAL API return type.
 */
typedef enum
{
	HAL_GAL_OK						=	 0,
	HAL_GAL_ERROR     				=	-1,		/**< General ERROR				*/
	HAL_GAL_INVALID_PARAM			=	-2,		/**< PARAMETER ERROR		*/
	HAL_GAL_NOT_AVAILABLE			=	-3,		/**< NOT_ENOUGH_RESOURCE	*/
	HAL_GAL_NOT_CALLABLE			=	-4,		/**< NOT_SUPPORTED		*/
	HAL_GAL_ERR_LENGTH				=	-5,		/**< NOT_PERMITTED		*/
	HAL_GAL_ERR_TIMEOUT				=	-6,		/**< TIMEOUT				*/

	HAL_GAL_ERR_OBJ_DELETED			=	-101        /**< OBJ DELETED ERROR */

} HAL_GAL_STATE_T;

/**
 * @brief This enumeration describes the supported functions.
 */
typedef enum {
	HAL_GAL_ACCEL_NONE				= 0x00000000,	/**< none of these */
	HAL_GAL_ACCEL_FILLRECTANGLE 	= 0x00000001,	/**< HAL_GAL_FillRectangle is accelerated */
	HAL_GAL_ACCEL_DRAWRECTANGLE 	= 0x00000002,	/**< HAL_GAL_DrawRectangle is accelerated */
	HAL_GAL_ACCEL_DRAWLINE			= 0x00000004,	/**< HAL_GAL_DrawLine is accelerated */
	HAL_GAL_ACCEL_FILLTRIANGLE		= 0x00000008,	/**< reserved */
	HAL_GAL_ACCEL_BLIT				= 0x00010000,	/**< HAL_GAL_Blit is accelerated */
	HAL_GAL_ACCEL_STRETCHBLIT		= 0x00020000,	/**< HAL_GAL_StretchBlit is accelerated */
	HAL_GAL_ACCEL_TEXTRIANGLES		= 0x00040000,	/**< reserved */
	HAL_GAL_ACCEL_TRAPEZOIDBLIT 	= 0x00080000,	/**< HAL_GAL_TrapezoidBlit is accelerated */
	HAL_GAL_ACCEL_DECODEIMAGE		= 0x00100000,	/**< HAL_GAL_DecodeImage is accelerated */
	HAL_GAL_ACCEL_DRAWSTRING		= 0x01000000,	/**< reserved */
	HAL_GAL_ACCEL_FLIP				= 0x02000000, 	/**< Flip operation is supported */
	HAL_GAL_ACCEL_ALL				= 0x031F000F,  	/**< All functions */
	HAL_GAL_ACCEL_ALL_DRAW			= 0x0000000F,	/**< All draw functions */
	HAL_GAL_ACCEL_ALL_BLIT			= 0x011F0000,	/**< All blit functions */
} HAL_GAL_SUPPORTED_FUNC_MASK_T;

/**
 * @brief This enumeration describes the supported pixel formats.
 */
typedef enum
{
	HAL_GAL_PIXEL_FORMAT_ARGB = 0,	/**< 32 bit ARGB (4 byte, alpha 8\@24, red 8\@16, green 8\@8, blue 8\@0) */
	HAL_GAL_PIXEL_FORMAT_LUT8, 		/**< 8 bit LUT (8 bit color and alpha lookup from palette) */
	HAL_GAL_PIXEL_FORMAT_ARGB1555, 	/**< 16 bit ARGB (2 byte, alpha 1\@15, red 5\@10, green 5\@5, blue 5\@0) */
	HAL_GAL_PIXEL_FORMAT_RGB16, 	/**< 16 bit RGB (2 byte, red 5\@11, green 6\@5, blue 5\@0) */
	HAL_GAL_PIXEL_FORMAT_ARGB4444, 	/**< 16 bit ARGB (2 byte, alpha 4\@12, red 4\@8, green 4\@4, blue 4\@0) */
	HAL_GAL_PIXEL_FORMAT_A8, 		/**< 8 bit A (1 byte, alpha 8\@0) */
	HAL_GAL_PIXEL_FORMAT_FBC,		/**< FBC pixel format (frame buffer compression for 32bit ARGB) */
	HAL_GAL_PIXEL_FORMAT_MAX		/**< Maximum number of HAL_GAL_PIXEL_FORMAT_T */
} HAL_GAL_PIXEL_FORMAT_T;

//FIXME : In the future, It should be integrated into one.
/**
 * @brief This structure describes surface pool.
 */
typedef struct {
	UINT32	physicalAddr;		/**< physical address of surface pool base */
	UINT32	virtualAddr;		/**< virtual address of surface pool base */
	UINT32	startOffset;		/**< the end of allocated layers (surface pool start with zero offset.) */
	UINT32	size;				/**< size of surface pool (in bytes). It is not from startOffset but zero offset which means base point of surface pool. */
	UINT16	byteOffsetAlign;	/**< bytes alignment constraint for the offset value of each surface allocation */
	UINT16	bytePitchAlign;		/**< bytes alignment constraint for the surface's pitch value */
} HAL_GAL_SURFACE_POOL_INFO_T;

/**
 * @brief This enumeration describes a information about image format.
 */
typedef enum {
	HAL_GAL_IMAGE_FORMAT_JPEG		=0x0,
	HAL_GAL_IMAGE_FORMAT_PNG,
	HAL_GAL_IMAGE_FORMAT_GIF,
	HAL_GAL_IMAGE_FORMAT_BMP,
	HAL_GAL_IMAGE_FORMAT_BUFFER,
	HAL_GAL_IMAGE_FORMAT_MAX,
} HAL_GAL_IMAGE_FORMAT_T;


/**
 * @brief This structure describes a rectangle specified by a point and a dimension.
 */
typedef struct
{
	UINT16	x;	/**< x cordinate of its top-letf point */
	UINT16	y;	/**< y cordinate of its top-left point */
	UINT16	w;	/**< width of it */
	UINT16	h;	/**< height of it */
} HAL_GAL_RECT_T;


/**
 * @brief This structure describes a line specified by two points.
 */
typedef struct
{
	UINT16	x1;	/**< x cordinate of its top-letf point1 */
	UINT16	y1;	/**< y cordinate of its top-left point1 */
	UINT16	x2;	/**< x cordinate of its top-letf point2 */
	UINT16	y2;	/**< y cordinate of its top-left point2 */
} HAL_GAL_LINE_T;

/**
 * @brief This structure describes position information.
 */
typedef struct
{
	SINT16 x;
	SINT16 y;
} HAL_GAL_POSITION_T;

/**
 * @brief This structure describes the palette information of the surface.
 */
typedef struct
{
	UINT32	palette[256]; /**< palette array */
	UINT32	length;		  /**< size of palette (max: 256) */
} HAL_GAL_PALETTE_INFO_T;

/**
 * @brief This structure describes a surface specified by graphic memory offset, pitch and bpp.
 */
typedef struct
{
	UINT32					offset;				/**< bytes offset from the start of graphic memory */
	UINT32					physicalAddress;  /**< physical address of surface */
	UINT16					pitch;				/**< pitch: length of horizontal line */
	UINT16					bpp;				/**< bits per pixel */
	UINT16					width;				/**< width of surface */
	UINT16					height;				/**< height of surface */
	HAL_GAL_PIXEL_FORMAT_T	pixelFormat;		/**< pixel format of surface */
	HAL_GAL_PALETTE_INFO_T	paletteInfo;		/**< palette information, this field is used when the surface's pixel format is based on indexed color. */
	union
	{
		UINT32 property; 						/**< reserved for future use */
		UINT32 length;							/**< allocated size of the surface */
	};
	UINT32					vendorData;			/**< reserved for chip vendor */
} HAL_GAL_SURFACE_INFO_T;


/**
 * @brief This enumeration describes the flags controlling blitting commands.
 */
typedef enum
{
	HAL_GAL_BLIT_NOFX					= 0x00000000, /**< uses none of the effects */
	HAL_GAL_BLIT_BLEND_ALPHACHANNEL		= 0x00000001, /**< enables blending and uses
													  alphachannel from source */
	HAL_GAL_BLIT_BLEND_COLORALPHA		= 0x00000002, /**< enables blending and uses
													  alpha value from color */
	HAL_GAL_BLIT_COLORIZE				= 0x00000004, /**< modulates source color with
													  the color's r/g/b values */
	HAL_GAL_BLIT_SRC_COLORKEY			= 0x00000008, /**< don't blit pixels matching the source color key */
	HAL_GAL_BLIT_DST_COLORKEY			= 0x00000010, /**< write to destination only if the destination pixel
													  matches the destination color key */
	HAL_GAL_BLIT_SRC_PREMULTIPLY		= 0x00000020, /**< modulates the source color with the (modulated)
													  source alpha */
	HAL_GAL_BLIT_DST_PREMULTIPLY		= 0x00000040, /**< modulates the dest. color with the dest. alpha */
	HAL_GAL_BLIT_DEMULTIPLY				= 0x00000080, /**< divides the color by the alpha before writing the
													  data to the destination */
	HAL_GAL_BLIT_DEINTERLACE			= 0x00000100, /**< deinterlaces the source during blitting by reading
													  only one field (every second line of full
													  image) scaling it vertically by factor two */
	HAL_GAL_BLIT_SRC_PREMULTCOLOR		= 0x00000200, /**< modulates the source color with the color alpha */
	HAL_GAL_BLIT_XOR					= 0x00000400, /**< bitwise xor the destination pixels with the
													 source pixels after premultiplication */
	HAL_GAL_BLIT_INDEX_TRANSLATION		= 0x00000800, /**< do fast indexed to indexed translation,
													 this flag is mutual exclusive with all others */
	HAL_GAL_BLIT_ROTATE90				= 0x00001000, /**< rotate the image by 90 degree clockwise */
	HAL_GAL_BLIT_ROTATE180				= 0x00002000, /**< rotate the image by 180 degree clockwise */
	HAL_GAL_BLIT_ROTATE270				= 0x00004000, /**< rotate the image by 270 degree clockwise */
	HAL_GAL_BLIT_COLORKEY_PROTECT		= 0x00010000, /**< make sure written pixels don't match color key (internal only ATM) */
	HAL_GAL_BLIT_SRC_MASK_ALPHA			= 0x00100000, /**< modulate source alpha channel with alpha channel from source mask */
	HAL_GAL_BLIT_SRC_MASK_COLOR			= 0x00200000, /**< modulate source color channels with color channels from source mask */

	HAL_GAL_BLIT_VERTICAL_MIRROR		= 0x00400000,  /**< flip vertically (x positon is not changed)*/
	HAL_GAL_BLIT_HORIZONTAL_MIRROR		= 0x00800000,  /**< flip horizontally (y positon is not changed)*/

	HAL_GAL_BLIT_BLEND_ALPHACHANNEL_BCM				= 0x01000000, /**< BCM specific mechanism similar to SRC_PREMULTCOLOR | BLEND_ALPHACHANNEL | DST_PREUMLTCOLOR */
	HAL_GAL_BLIT_BLEND_ALPHACHANNEL_COLORALPHA_BCM	= 0x02000000, /**< BCM specific mechanism similar to SRC_PREMULTCOLOR | BLEND_ALPHACHANNEL | BLEND_COLORALPHA | DST_PREUMLTCOLOR */
	HAL_GAL_BLIT_BLEND_ALPHACHANNEL_COLORIZE_BCM	= 0x04000000, /**< BCM specific mechanism similar to SRC_PREMULTCOLOR | BLEND_ALPHACHANNEL | COLORIZE | DST_PREUMLTCOLOR */

	HAL_GAL_BLIT_MAX  /**< the maximum value */

} HAL_GAL_BLIT_FLAGS_T;


/**
 * @brief This enumeration describes the flags controlling drawing commands.
 */
typedef enum
{
	HAL_GAL_DRAW_NOFX					= 0x00000000, /**< uses none of the effects */
	HAL_GAL_DRAW_BLEND					= 0x00000001, /**< uses alpha from color */
	HAL_GAL_DRAW_DST_COLORKEY			= 0x00000002, /**< write to destination only if the destination pixel matches the destination color key */
	HAL_GAL_DRAW_SRC_PREMULTIPLY		= 0x00000004, /**< muliplies the color's rgb channels by the alpha channel before drawing */
	HAL_GAL_DRAW_DST_PREMULTIPLY		= 0x00000008, /**< modulates the dest. color with the dest. alpha */
	HAL_GAL_DRAW_DEMULTIPLY				= 0x00000010, /**< divides the color by the alpha before writing the data to the destination */
	HAL_GAL_DRAW_XOR					= 0x00000020, /**< bitwise xor the destination pixels with the specified color after premultiplication */
	HAL_GAL_DRAW_MAX  /**< the maximum value */
} HAL_GAL_DRAW_FLAGS_T;


/**
 * @brief This enumeration describes the blend functions to use for source and destination blending.
 */
typedef enum
{
	HAL_GAL_BLEND_UNKNOWN			= 0,  /**< Unknown blending function */
	HAL_GAL_BLEND_ZERO				= 1,  /**< zero or, 0 */
	HAL_GAL_BLEND_ONE				= 2,  /**< 1 */
	HAL_GAL_BLEND_SRCCOLOR			= 3,  /**< source color */
	HAL_GAL_BLEND_INVSRCCOLOR		= 4,  /**< inverse source alpha */
	HAL_GAL_BLEND_SRCALPHA			= 5,  /**< source alpha */
	HAL_GAL_BLEND_INVSRCALPHA		= 6,  /**< inverse source alpha (1-Sa)*/
	HAL_GAL_BLEND_DESTALPHA			= 7,  /**< destination alpha */
	HAL_GAL_BLEND_INVDESTALPHA		= 8,  /**< inverse destination lapha (1-Da)*/
	HAL_GAL_BLEND_DESTCOLOR			= 9,  /**< destination color */
	HAL_GAL_BLEND_INVDESTCOLOR		= 10, /**< inverse destination color */
	HAL_GAL_BLEND_SRCALPHASAT		= 11, /**< source alpha saturation */
	HAL_GAL_BLEND_MAX  /**< the maximum value */
} HAL_GAL_BLEND_FUNCTION_T;

/**
 * @brief This enumeration describes Flags controlling surface masks set.
 */
typedef enum {
	HAL_GAL_SURFACE_MASK_NONE      = 0x00000000,  /**< none of these. */
	HAL_GAL_SURFACE_MASK_STENCIL   = 0x00000001,  /**< Take <b>x</b> and <b>y</b> as fixed start coordinates in the mask. */
	HAL_GAL_SURFACE_MASK_ALL       = 0x00000001,  /**< all of these. */
} HAL_GAL_SURFACE_MASK_FLAGS_T;

/**
 * @brief This enumeration describes supported image format for HW decoding.
 */
typedef enum {
	HAL_GAL_IMAGE_FORMAT_NONE_SUPPORTED		= 0x00000000,
	HAL_GAL_IMAGE_FORMAT_JPEG_SUPPORTED		= 0x00000001,
	HAL_GAL_IMAGE_FORMAT_PNG_SUPPORTED		= 0x00000002,
	HAL_GAL_IMAGE_FORMAT_GIF_SUPPORTED		= 0x00000004,
	HAL_GAL_IMAGE_FORMAT_BMP_SUPPORTED		= 0x00000008,
	HAL_GAL_IMAGE_FORMAT_BUFFER_SUPPORTED	= 0x00000010,
	HAL_GAL_IMAGE_FORMAT_ALL				= 0x0000001F,
} HAL_GAL_SUPPORTED_IMAGE_FORMAT_FLAGS_T;

/**
 * @brief Information of gfx device limitations
 */
typedef struct{
	UINT32		hwDecodeMinLimitWidth;									/**< Minimum limitation of supported width for HW decoding (Zero means no limitation) */
	UINT32		hwDecodeMinLimitHeight;									/**< Minimum limitation of supported height for HW decoding (Zero means no limitation) */
	UINT16		hwDecodeMaxLimitWidth;									/**< Maximum limitation of supported width for HW decoding (Zero means no limitation) */
	UINT16		hwDecodeMaxLimitHeight;									/**< Maximum limitation of supported height for HW decoding (Zero means no limitation) */
	UINT32		hwDecodeMaxLimitArea;									/**< Maximum limitation of supported area (width*height) for HW decoding (Zero means no limitation). This value may mean the size of allocated surface. */
	UINT32		maxScaleUpFactor;										/**< maximum factor on scaling up (stretchblit).  */
	UINT32		minScaleDownFactor; 									/**< minimum factor on scaling down (stretchblit) */
	UINT32		swBlitArea;												/**< if width*height < swBlitArea then, SW blit operation may be faster. */
	UINT16		hwBlitLimitWidth;										/**< Limitation of supported width for HW blit (Zero means no limitation) */
	UINT16		hwBlitLimitHeight;										/**< Limitation of supported height for HW blit (Zero means no limitation) */
	UINT32		hwBlitLimitArea;										/**< Limitation of supported area (width*height) for HW blit (Zero means no limitation) */
} HAL_GAL_DEVICE_LIMITATION_INFO_T;

/**
 * @brief This structure describes the 2D graphic capability of device.
 */
typedef struct {
	UINT8						bAllocatorSupported;					/**< whether the allocator is supported, or not (if supported, then this value is TRUE otherwise FALSE.) */
	HAL_GAL_BLIT_FLAGS_T			blitFlags;								/**< supported blit flags */
	HAL_GAL_DRAW_FLAGS_T			drawFlags;								/**< supported draw flags */
	HAL_GAL_SUPPORTED_FUNC_MASK_T	supportedFunctions;					/**< supported functions */
	UINT8						maxNumOfLayers;							/**< the maximum number of supported layers */
	UINT8						maxNumOfFBHWControllers;				/**< the maximum number of supported FB HW Controller */
	UINT32						physicalAddrOfBase;						/**< physical address of graphic memory start (or base of offset) */
	UINT32						gfxMemorySize;							/**< The total size of gfx memory */
	UINT32						virtualAddrOfBase;						/**< virtual address of graphic memory start (or base of offset). This value will be filled at upper level(by LG). Chip vendor need to fill physicalAddrOfBase and offset value of surface. */
	HAL_GAL_SUPPORTED_IMAGE_FORMAT_FLAGS_T		supportedImageFormat; 	/**< Image format that can be decoded by HW decoder */
	HAL_GAL_DEVICE_LIMITATION_INFO_T		deviceLimitationInfo;			/**< Information of gfx device limitations */
	UINT8 						bFBCSupported;							  /**< whether the FBC (Frame Buffer Compression) is supported, or not (if supported, then this value is TRUE otherwise FALSE.) */
} HAL_GAL_DEVICE_CAPABILITY_INFO_T;

/**
 * @brief This structure describes source mask.
 */
typedef struct
{
	UINT32						offset;	/**< bytes offset from the start of graphic memory */
	UINT16						x;		/**< x */
	UINT16						y;		/**< y */
	HAL_GAL_SURFACE_MASK_FLAGS_T	flags;	/**< STENCIL or not*/
} HAL_GAL_SOURCE_MASK_T;


/**
 * @brief This structure describes settings for draw operation.
 */
typedef struct
{
	HAL_GAL_BLEND_FUNCTION_T	srcBlend;		/**< source blend function */
	HAL_GAL_BLEND_FUNCTION_T	dstBlend;		/**< destination blend function */
	UINT32					dstColorkey;	/**< destination colorkey */
} HAL_GAL_DRAW_SETTINGS_T;


/**
 * @brief This structure describes settings for blit operation.
 */
typedef struct
{
	HAL_GAL_BLEND_FUNCTION_T	srcBlend;		/**< source blend function */
	HAL_GAL_BLEND_FUNCTION_T	dstBlend;		/**< destination blend function */
	UINT32					alpha;			/**< global alpha value */
	UINT32					color;			/**< global color value */
	UINT32					srcColorkey;	/**< source colorkey */
	UINT32					dstColorkey;	/**< destination colorkey */
	HAL_GAL_SOURCE_MASK_T		srcMask;		/**< source mask information*/
} HAL_GAL_BLIT_SETTINGS_T;


/**
 * @brief This structure describes the trapezoid rendering.
 */
typedef struct
{
	HAL_GAL_RECT_T	srcRect;			/**< source rectangular which represents source image */
	UINT8		alphaConst;			/**< constant alpha blending (range: 0~255) */
	UINT8		bAntiAliasing;		/**< antialising option for trapezoid edge smoothing (0:off, 1:on) */
	UINT8		trapDir;			/**< Trapezoid direction mode (0: vertical trapezoid rendering mode, 1: horizontal rendering mode */
	UINT8		srcRectRotateDir;	/**< Source rectangular clockwise rotation (0: 0 degree, 1: 90, 2: 180 degree, 3: 270 degree) */
	UINT8		dstTrapRotateDir;	/**< Destination trapezoid clockwise rotation (0: 0 degree, 1: 90 degree, 2: 180 degree, 3: 270 degree) */
	UINT16		dstTrapEdge0Pos;	/**< y-coor for vertical trapezoid, x-coor for horizontal trapezoid */
	UINT16		dstTrapEdge0St;		/**< x-coor for vertical trapezoid, y-coor for horizontal trapezoid */
	UINT16		dstTrapEdge0End;	/**< x-coor for vertical trapezoid, y-coor for horizontal trapezoid */
	UINT16		dstTrapEdge1St;		/**< x-coor for vertical trapezoid, y-coor for horizontal trapezoid */
	UINT16		dstTrapEdge1End;	/**< x-coor for vertical trapezoid, y-coor for horizontal trapezoid */
	UINT16		dstTrapDistance;	/**< the distance between destination parallel edge0 and parallel edge1 */
} HAL_GAL_TRAPEZOID_T;


/**
 * @brief This structure describes information about image.
 */
typedef struct
{
	HAL_GAL_IMAGE_FORMAT_T 	imageFormat;
	HAL_GAL_RECT_T			rect;
	UINT32				imageLength;
	HAL_GAL_PIXEL_FORMAT_T	pixelFormat;
	UINT8				bImageFromBuffer;
	CHAR				*imagePath;
	UINT32				*imagePtr;
} HAL_GAL_IMAGE_INFO_T;

/**
 * @brief This enumeration describes the flags controlling decoded image.
 */
typedef enum
{
	HAL_GAL_DECODEIMAGE_NOFX               = 0x00000000, /**< uses none of the effects */
	HAL_GAL_DECODEIMAGE_PREMULTIPLY        = 0x00000001, /**< modulates the image color with the image alpha */
	HAL_GAL_DECODEIMAGE_ROTATE90           = 0x00000010, /**< rotate the image by 90 degree clockwise */
	HAL_GAL_DECODEIMAGE_ROTATE180          = 0x00000020, /**< rotate the image by 180 degree clockwise */
	HAL_GAL_DECODEIMAGE_ROTATE270          = 0x00000040, /**< rotate the image by 270 degree clockwise */
	HAL_GAL_DECODEIMAGE_VERTICAL_MIRROR    = 0x00000100, /**< flip vertically (x positon is not changed)*/
	HAL_GAL_DECODEIMAGE_HORIZONTAL_MIRROR  = 0x00000200, /**< flip horizontally (y positon is not changed)*/
	HAL_GAL_DECODEIMAGE_ALL                = 0x000003b1  /**< all */
} HAL_GAL_DECODEIMAGE_FLAGS_T;

/**
 * @brief This enumeration describes the window ID.
 * This enum is deprecated.
 */
typedef enum
{
	/**<Layer -1  Group : No Need Focus */
	HAL_GAL_WINDOW_ACC = 0,
	HAL_GAL_WINDOW_DCC,
	HAL_GAL_WINDOW_ADCC,
	HAL_GAL_WINDOW_DIVX,
	HAL_GAL_WINDOW_SUBTITLE,
	HAL_GAL_WINDOW_JCAPCAPTION,
	HAL_GAL_WINDOW_MHP_IFRAME,
	HAL_GAL_WINDOW_PDPCOLORWASH,

	/**<Layer -2 Group : Data Broadcast*/
	HAL_GAL_WINDOW_MHEG,
	HAL_GAL_WINDOW_MHP,
	HAL_GAL_WINDOW_TTX,
	HAL_GAL_WINDOW_BML,
	HAL_GAL_WINDOW_EMM,
	HAL_GAL_WINDOW_HBBTV,

	/**<Layer -3 Group: Application*/
	HAL_GAL_WINDOW_NATIVEUI,
	HAL_GAL_WINDOW_FX_HOMEDASHBOARD,
	HAL_GAL_WINDOW_FX_TERMS,
	HAL_GAL_WINDOW_FX_ADPREMIUM,
	HAL_GAL_WINDOW_FX_POPUPUI,
	HAL_GAL_WINDOW_BROWSER,
	HAL_GAL_WINDOW_ADOBEAIR,
	HAL_GAL_WINDOW_DEFAULT, //Downloaded CP( game, ..)
	HAL_GAL_WINDOW_VUDU,
	HAL_GAL_WINDOW_CINEMANOW,
	HAL_GAL_WINDOW_NETFLIX,
	HAL_GAL_WINDOW_WASU,
	HAL_GAL_WINDOW_CNTV,
	HAL_GAL_WINDOW_EMANUAL,
	HAL_GAL_WINDOW_ESTREAMER,

	/**<Layer -4 Group : Application*/
	HAL_GAL_WINDOW_COMMONUI,

	/**<Layer -5 Group*/
	HAL_GAL_WINDOW_CRASHLOG,

	/**<Layer -6 Group*/
	HAL_GAL_WINDOW_CURSOR,

	/**<Non layer Group*/
	HAL_GAL_WINDOW_MERGE,
	/**<Non layer Group : Live TV(video) */
	HAL_GAL_WINDOW_LIVETV,
	HAL_GAL_WINDOW_ID_LAST
}HAL_GAL_WINDOW_ID_T;

/**
 * This enumeration describes flags for stereoscope mode setting.
 * This enum is deprecated.
 */
typedef enum
{
	HAL_GAL_STEREOSCOPE_2D_TO_3D = 0,
	HAL_GAL_STEREOSCOPE_S3D,
	HAL_GAL_STEREOSCOPE_LAST
}HAL_GAL_STEREOSCOPE_TYPE_T;

/**
 * This enumeration describes the flags controlling osd path.
 * This enum is deprecated.
 */
typedef enum
{
	HAL_GAL_OSD_SEPARATE_MODE = 0,
	HAL_GAL_OSD_BLEND_MODE = 1
} HAL_GAL_OSD_PATH_MODE_FLAGS_T;

/**
 * This enumeration describes the flags controlling 3D mode of OSD.
 * This enum is deprecated.
 */
typedef enum
{
	HAL_GAL_3D_MODE_OFF = 0,
	HAL_GAL_3D_MODE_ON = 1
} HAL_GAL_3D_MODE_T;

/**
 * This enumeration describes the flags controlling 3D type of OSD.
 * This enum is deprecated.
 */
typedef enum
{
	HAL_GAL_3D_TYPE_2D	=	0,
	HAL_GAL_3D_TYPE_TOP_BOTTEM	=	1,
	HAL_GAL_3D_TYPE_SIDE_BY_SIDE	=	2,
	HAL_GAL_3D_TYPE_CHECKER_BOARD	=	3,
	HAL_GAL_3D_TYPE_FRAME_SEQUENCE	=	4,
	HAL_GAL_3D_TYPE_COLUMN_INTERLEAVE	=	5,
	HAL_GAL_3D_TYPE_LINE_INTERLEAVE_HALF	=	6,
	HAL_GAL_3D_TYPE_FRAME_PACKING	=	7,
	HAL_GAL_3D_TYPE_FIELD_ALTERNATIVE	=	8,
	HAL_GAL_3D_TYPE_LINE_ALTERNATIVE	=	9,
	HAL_GAL_3D_TYPE_SIDE_BY_SIDE_FULL	=	10,
	HAL_GAL_3D_TYPE_DUAL_STREAM	=	11,
	HAL_GAL_3D_TYPE_2D_TO_3D	=	12,
	HAL_GAL_3D_TYPE_MAX	=	HAL_GAL_3D_TYPE_2D_TO_3D
} HAL_GAL_3D_TYPE_T;

/**
 * This enumeration describes the flags controlling mirror mode.
 */
typedef enum
{
	HAL_GAL_NONE_MIRROR			=	0x00000000,	/**< Not uses mirror mode */
	HAL_GAL_HORIZONTAL_MIRROR	=	0x00000001,	/**< Flip horizontally (y position is not changed */
	HAL_GAL_VERTICAL_MIRROR		=	0x00000010,	/**< Flip vertically (x position is not changed */
	HAL_GAL_EPI_MIRROR			=	0x00000020,	/**< determine whether use EPI panel or not  */
	HAL_GAL_ALL					=	0x00000031	/**< All */
} HAL_GAL_MIRROR_FLAGS_T;

/**
 * This enumeration describes flags for framebuffer property setting.
 * This enum is deprecated.
 */
typedef enum
{
	HAL_GAL_FRAMEBUFFER_PROPERTY_NOFX		=	0x00000000,	/**< None */
	HAL_GAL_FRAMEBUFFER_PROPERTY_VIEWRECT	=	0x00000001, /**< viewRect region on the framebuffer */
	HAL_GAL_FRAMEBUFFER_PROPERTY_DISPRECT	=	0x00000010,	/**< dispRect region on the framebuffer */
	HAL_GAL_FRAMEBUFFER_PROPERTY_STEREOSCOPE=	0x00000020, /**< Stereoscope on, off */
	HAL_GAL_FRAMEBUFFER_PROPERTY_ALL		=	0x00000031,	/**< dispRect region on the framebuffer */
} HAL_GAL_FRAMEBUFFER_PROPERTY_FLAGS_T;

/**
 * This enumeration describes flags for cursor hotspot type.
 */
typedef enum
{
	HAL_GAL_CURSOR_HOTSPOT_LEFTTOP			=	0x00000000,	/**< None */
	HAL_GAL_CURSOR_HOTSPOT_USERSETTING		=	0x00000001, /**< viewRect region on the framebuffer */
	HAL_GAL_CURSOR_HOTSPOT_LAST				=	0x00000010,	/**< dispRect region on the framebuffer */
} HAL_GAL_CURSOR_HOTSPOT_TYPES_T;


/**
* This structure is for a resolution info such as width and height.
*/
typedef struct
{
	unsigned short		width;
	unsigned short		height;
}
HAL_GAL_RESOLUTION_T;

typedef struct
{
	HAL_GAL_POSITION_T		position;			// cursor position
	unsigned short			width;				// image width
	unsigned short			height;				// image height
	HAL_GAL_CURSOR_HOTSPOT_TYPES_T	hotspot;	// hotspot type
	HAL_GAL_POSITION_T		cursorGapPosition;	// hotspot pos info
} HAL_GAL_CURSOR_POSITION_INFO_T;

/**
 * This enumeration describes the supported pixel formats for framebuffer.
 */
typedef enum
{
	HAL_GAL_PIXEL_FORMAT_ARGB_EX				=	0x00000000,	/**< 32 bit ARGB (4 byte, alpha 8\@24, red 8\@16, green 8\@8, blue 8\@0) */
	HAL_GAL_PIXEL_FORMAT_YUV_EX				=	0x00000001, /**< YUV */
	HAL_GAL_PIXEL_FORMAT_MAX_EX				=	0x00000010,	/**< Maximum number of HAL_GAL_PIXEL_FORMAT_EX_T */
} HAL_GAL_PIXEL_FORMAT_EX_T;

/**
 * This enumeration describes framebuffer property information.
 */
typedef struct
{
	HAL_GAL_RECT_T	viewRect;	/**< viewRect region on the framebuffer */
	HAL_GAL_RECT_T	dispRect;	/**< dispRect region on the framebuffer */
} HAL_GAL_FRAMEBUFFER_PROPERTY_INFO_T;

typedef struct
{
	HAL_GAL_RECT_T viewRect;	/**< viewRect region on the framebuffer */
	HAL_GAL_RECT_T dispRect;	/**< dispRect region on the framebuffer */
	unsigned char bStereoscope;
	HAL_GAL_STEREOSCOPE_TYPE_T stereoscopeType;	/**< This enumeration describes flags for stereoscope mode setting */
} HAL_GAL_FRAMEBUFFER_PROPERTY_EXTENDED_INFO_T;


/**
 * This structure describes 2D graphic memory information
 */
typedef struct
{
	UINT32	gfxMemTotalSize;
	UINT32	allocatedMemTotalSize;
	UINT32	freeMemTotalSize;
	UINT32	largestFreeMemSize;
} HAL_GAL_GRAPHIC_MEM_INFO_T;

/**
 * This structure describes for control to visibility of framebuffer
 */
typedef struct
{
	UINT32	fbHWControllerIndex;
	BOOLEAN	bVisibility;
} HAL_GAL_FRAMEBUFFER_VISIBILITY_INFO_T;

/**
 * This structure describes cursor property information.
 */
typedef struct
{
	HAL_GAL_POSITION_T	position;
	UINT32				panelWidth;
	UINT32				panelHeight;
	UINT32				width;
	UINT32				height;
	HAL_GAL_CURSOR_HOTSPOT_TYPES_T	hotspot;
	HAL_GAL_POSITION_T	cursorGapPosition;
} HAL_GAL_CURSOR_PROPERTY_INFO_T;

/**
* This enum is deprecated.
*/
typedef enum
{
	HAL_GAL_OSD_ROTATE_NONE = 0,
	HAL_GAL_OSD_ROTATE_90_DEGREE,
	HAL_GAL_OSD_ROTATE_270_DEGREE,
}
HAL_GAL_OSD_ROTATE_TYPE_T;

/**
* This enum is deprecated.
*/
typedef enum
{
    GAL_OSD_PORTRAIT_ARC_ORIGINAL_MODE = 0,
    GAL_OSD_PORTRAIT_ARC_FULL_MODE
} HAL_GAL_OSD_PORTRAIT_ARC_MODE_T;

/*----------------------------------------------------------------------------------------
    Type Definitions - end
----------------------------------------------------------------------------------------*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*----------------------------------------------------------------------------------------
    Initialize / Finalize Operation
----------------------------------------------------------------------------------------*/
/**
 * @brief Initializes GAL module.
 *
 * @rst
 * Functional Requirements
 *  Initializes GFX driver which is 2D graphics hardware accelerator engine.
 *  Call Chipset driver initialization function and create resources for GAL module such as OSD framebuffer.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 100ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *  None
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      if( HAL_GAL_Init() !=  HAL_GAL_OK) {
 *          // Error handling
 *      }
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_Init(void);

/**
 * @brief Finalize GAL module.
 *
 * @rst
 * Functional Requirements
 *  Finalize GFX driver and free OSD framebuffer.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 100ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *  None
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      if( HAL_GAL_Finalize() !=  HAL_GAL_OK) {
 *          // Error handling
 *      }
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_Finalize(void);

 /**
 * @brief Get the capabilities of GFX driver.
 *
 * @rst
 * Functional Requirements
 *  Get the capabilities of GFX driver.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 10ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pDeviceCapabilityInfo [IN]  2D graphic capability of device.
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Remarks
 *  The "/dev/gfx" file that is mapping with gfx physical memory space is needed.
 *  And that file is possible to mmap to mapping with virtual address.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      HAL_GAL_DEVICE_CAPABILITY_INFO_T deviceCapabilityInfo = {0,};
 *
 *      if( HAL_GAL_GetDeviceCapability(deviceCapabilityInfo) !=  HAL_GAL_OK) {
 *          // Error handling
 *      }

 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_GetDeviceCapability(HAL_GAL_DEVICE_CAPABILITY_INFO_T *pDeviceCapabilityInfo);


/*----------------------------------------------------------------------------------------
    resource create/destroy/get/set
----------------------------------------------------------------------------------------*/

/**
 * @brief Create a surface
 *
 * @rst
 * Functional Requirements
 *  Allocates memory buffer for a surface in the video memory area. (for using H/W accerated graphics)
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 50ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      width 		[IN]  surface width in pixels
 *      height		[IN]  surface height in pixels
 *      pixelFormat	[IN]  pixel format
 *      pSurfaceInfo	[OUT]  Pointer to a HAL_GAL_SURFACE_INFO_T structure to information about newly allocated surface
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Remarks
 *  When called this API, do not need surface clear.
 *  If pixel format is 8bpp, palette values must be initialized as NULL(0x0) using SetSurfacePalette().
 *
 * Example
 *   .. code-block:: cpp
 *
 *      HAL_GAL_DEVICE_CAPABILITY_INFO_T deviceCapabilityInfo = {0,};
 *
 *      if( HAL_GAL_GetDeviceCapability(deviceCapabilityInfo) !=  HAL_GAL_OK) {
 *          // Error handling
 *      }
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_CreateSurface(UINT16 width, UINT16 height, HAL_GAL_PIXEL_FORMAT_T pixelFormat, HAL_GAL_SURFACE_INFO_T *pSurfaceInfo);

/**
 * @brief Destroy the surface
 *
 * @rst
 * Functional Requirements
 *  Dellocates buffer for a surface in the video memory area.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 10ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pSurfaceInfo	[IN]  Pointer to a HAL_GAL_SURFACE_INFO_T structure to information
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      UINT16 w = 1920;
 *      UINT16 h = 1080;
 *      HAL_GAL_PIXEL_FORMAT_T pixelFormat = HAL_GAL_PIXEL_FORMAT_ARGB;
 *      HAL_GAL_SURFACE_INFO_T surf;
 *
 *      if(HAL_GAL_CreateSurface(w, h, pixelFormat, &surf) != HAL_GAL_OK) {
 *      	// Error handling
 *      }

 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_DestroySurface(HAL_GAL_SURFACE_INFO_T *pSurfaceInfo);

/*----------------------------------------------------------------------------------------
    2D graphic drawing operation
----------------------------------------------------------------------------------------*/
/**
 * @brief Blit an area from one surface to other surface based on blit flags.
 *
 * @rst
 * Functional Requirements
 *  Blit an area from one surface to other surface based on blit flags.
 *
 *  This entire operation must be assured critical section (using Lock/Unlock) until the operation is completed.
 *  Because some blitFlags may require operation more than twice internal operations.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 10ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pSrcSurface	[IN]  source surface handler
 *      pSrcRect		[IN]  source rectangle which represent blited area in the source surface
 *      pDstSurface	[IN]  destination surface handler
 *      dx			[IN]  x in destination surface
 *      dy			[IN]  y in destination surface
 *      pBlitFlags		[IN] blitFlags blitting flags which indicate various blit operations
 *      pBlitSettings	[IN] blitSettings settings for blit operation
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      HAL_GAL_STATE_T retVal;
 *      HAL_GAL_SURFACE_INFO_T srcSurface, dstSurface;
 *      HAL_GAL_CreateSurface(200, 200, HAL_GAL_PIXEL_FORMAT_ARGB, &srcSurface);
 *      HAL_GAL_CreateSurface(200, 200, HAL_GAL_PIXEL_FORMAT_ARGB, &dstSurface);
 *      HAL_GAL_RECT_T srcRect = {100, 100, 100, 100};
 *      UINT16 dx=10, dy=10;
 *      HAL_GAL_BLIT_FLAGS_T blitFlags = HAL_GAL_BLIT_BLEND_COLORALPHA| HAL_GAL_BLIT_BLEND_ALPHACHANNEL| HAL_GAL_BLIT_SRC_PREMULTIPLY;
 *      blitSettings.srcBlend = HAL_GAL_BLEND_ONE;
 *      blitSettings.dstBlend = HAL_GAL_BLEND_ INVSRCALPHA;
 *      HAL_GAL_BLIT_SETTINGS_T blitSettings;
 *      blitSettings.alpha = 0xe0; // almost opaque global alpha
 *      blitSettings.srcColorkey = 0x0;
 *      blitSettings.dstColorkey = 0x0;
 *
 *      retVal = HAL_GAL_Blit(&srcSurface, &srcRect, &dstSurface, dx, dy, &blitFlags, &blitSettings);
 *      if (retVal != HAL_GAL_OK) {
 *      	// Error handling
 *      }
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_Blit(HAL_GAL_SURFACE_INFO_T* pSrcSurface, HAL_GAL_RECT_T* pSrcRect, HAL_GAL_SURFACE_INFO_T* pDstSurface, UINT16 dx, UINT16 dy, HAL_GAL_BLIT_FLAGS_T* pBlitFlags, HAL_GAL_BLIT_SETTINGS_T* pBlitSettings);

/**
 * @brief Stretch blit an area from one surface to other surface based on blit flags.
 *
 * @rst
 * Functional Requirements
 *  Stretch blit an area from one surface to other surface based on blit flags.
 *
 *  This entire operation must be assured critical section (using Lock/Unlock) until the operation is completed.
 *  Because some blitFlags may require operation more than twice internal operations.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 10ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pSrcSurface	[IN]  source surface handler
 *      pSrcRect		[IN]  source rectangle which represent blited area in the source surface
 *      pDstSurface	[IN]  destination surface handler
 *      pDstRect		[IN]  destination rectangle which represent blited area in the source surface
 *      pBlitFlags		[IN]  blitting flags which indicate various blit operations
 *      pBlitSettings	[IN]  settings for blit operation
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      HAL_GAL_STATE_T retVal;
 *      HAL_GAL_SURFACE_INFO_T srcSurface, dstSurface;
 *      HAL_GAL_CreateSurface(200, 200, HAL_GAL_PIXEL_FORMAT_ARGB, &srcSurface);
 *      HAL_GAL_CreateSurface(500, 500, HAL_GAL_PIXEL_FORMAT_ARGB, &dstSurface);
 *
 *      HAL_GAL_RECT_T srcRect, dstRect;
 *      srcRect.x = 100;
 *      srcRect.y = 100;
 *      srcRect.w = 100;
 *      srcRect.h = 100;
 *      dstRect.x = 200;
 *      dstRect.y = 200;
 *      dstRect.w = 300;
 *      dstRect.h = 300;
 *
 *      HAL_GAL_BLIT_FLAGS_T blitFlags = HAL_GAL_BLIT_BLEND_COLORALPHA| HAL_GAL_BLIT_BLEND_ALPHACHANNEL| HAL_GAL_BLIT_SRC_PREMULTIPLY;
 *      HAL_GAL_BLIT_SETTINGS_T blitSettings;
 *      blitSettings.srcBlend = HAL_GAL_BLEND_ONE;
 *      blitSettings.dstBlend = HAL_GAL_BLEND_ INVSRCALPHA;
 *      blitSettings.alpha = 0xe0; // almost opaque global alpha
 *      blitSettings.srcColorkey = 0x0;
 *      blitSettings.dstColorkey = 0x0;
 *
 *      retVal = HAL_GAL_StretchBlit(&srcSurface, &srcRect, &dstSurface, &dstRect, &blitFlags,&blitSettings);
 *      if(retVal != HAL_GAL_OK) {
 *      	// Error handling
 *      }
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_StretchBlit(HAL_GAL_SURFACE_INFO_T* pSrcSurface, HAL_GAL_RECT_T* pSrcRect, HAL_GAL_SURFACE_INFO_T* pDstSurface, HAL_GAL_RECT_T* pDstRect, HAL_GAL_BLIT_FLAGS_T* pBlitFlags, HAL_GAL_BLIT_SETTINGS_T* pBlitSettings);

/**
 * @brief Fill a rectangle to a destination surface based on drawing flags.
 *
 * @rst
 * Functional Requirements
 *  Fill a rectangle to a destination surface based on drawing flags.
 *
 *  This entire operation must be assured critical section (using Lock/Unlock) until the operation is completed.
 *  Because some blitFlags may require operation more than twice internal operations.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 10ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pDstSurface	[IN]  destination surface handler
 *      pDstRect		[IN]  rectangle which represent drawing area in the destination surface
 *      color		[IN]  color value for the drawing
 *      pDrawFlags	[IN]  drawing flags which indicate various blit operations
 *      pDrawSettings	[IN]  settings for draw operation
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      HAL_GAL_STATE_T retVal;
 *      HAL_GAL_SURFACE_INFO_T srcSurface, dstSurface;
 *      HAL_GAL_CreateSurface(200, 200, HAL_GAL_PIXEL_FORMAT_ARGB, &srcSurface);
 *      HAL_GAL_CreateSurface(500, 500, HAL_GAL_PIXEL_FORMAT_ARGB, &dstSurface);
 *
 *      HAL_GAL_RECT_T srcRect, dstRect;
 *      srcRect.x = 100;
 *      srcRect.y = 100;
 *      srcRect.w = 100;
 *      srcRect.h = 100;
 *      dstRect.x = 200;
 *      dstRect.y = 200;
 *      dstRect.w = 300;
 *      dstRect.h = 300;
 *
 *      HAL_GAL_BLIT_FLAGS_T blitFlags = HAL_GAL_BLIT_BLEND_COLORALPHA| HAL_GAL_BLIT_BLEND_ALPHACHANNEL| HAL_GAL_BLIT_SRC_PREMULTIPLY;
 *      HAL_GAL_BLIT_SETTINGS_T blitSettings;
 *      blitSettings.srcBlend = HAL_GAL_BLEND_ONE;
 *      blitSettings.dstBlend = HAL_GAL_BLEND_ INVSRCALPHA;
 *      blitSettings.alpha = 0xe0; // almost opaque global alpha
 *      blitSettings.srcColorkey = 0x0;
 *      blitSettings.dstColorkey = 0x0;
 *
 *      retVal = HAL_GAL_StretchBlit(&srcSurface, &srcRect, &dstSurface, &dstRect, &blitFlags,&blitSettings);
 *      if(retVal != HAL_GAL_OK) {
 *      	// Error handling
 *      }
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_FillRectangle(HAL_GAL_SURFACE_INFO_T* pDstSurface, HAL_GAL_RECT_T* pDstRect, UINT32 color, HAL_GAL_DRAW_FLAGS_T* pDrawFlags, HAL_GAL_DRAW_SETTINGS_T* pDrawSettings);

/**
 *  @brief Draw a rectangle to a destination surface based on drawing flags.
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pDstSurface	[IN]  destination surface handler
 *      pDstRect		[IN]  rectangle which represent drawing area in the destination surface
 *      color		       [IN]  color value for the drawing
 *      pDstRect		[IN]  drawing flags which indicate various blit operations
 *      pDrawSettings	[IN]  settings for draw operation
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_DrawRectangle(HAL_GAL_SURFACE_INFO_T* pDstSurface, HAL_GAL_RECT_T* pDstRect, UINT32 color, HAL_GAL_DRAW_FLAGS_T* pDrawFlags, HAL_GAL_DRAW_SETTINGS_T* pDrawSettings);

/**
 *  @brief Draws a line to a destination surface based on drawing flags.
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pDSurface	[IN]  destination surface handler
 *      pDstLine		[IN]  line which represent drawing area in the surface
 *      color		[IN]  color value for the drawing
 *      pDrawFlags	[IN]  drawing flags which indicate various blit operations
 *      pDrawSettings	[IN]  settings for draw operation
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_DrawLine(HAL_GAL_SURFACE_INFO_T* pDSurface, HAL_GAL_LINE_T* pDstLine, UINT32 color, HAL_GAL_DRAW_FLAGS_T* pDrawFlags, HAL_GAL_DRAW_SETTINGS_T* pDrawSettings);


/*----------------------------------------------------------------------------------------
    Set Operation
----------------------------------------------------------------------------------------*/
/**
 *  @brief Get surface palette for 8bpp surface
 *
 * @rst
 * Functional Requirements
 *  Get surface palette for 8bpp surface
 *  Read entries to the palette of a surface which is indexed color format such as CPU PIXEL_FORMAT_LUT8.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 10ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pSurface		[IN] surface handler
 *      pPalette		[OUT] palette which is array of 32bit ARGB color entries
 *      paletteLength	[IN] number of entries of palette
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      HAL_GAL_STATE_T retVal;
 *      HAL_GAL_SURFACE_INFO_T surface;
 *
 *      UINT32 palette[256];
 *      SINT32 paletteLegnth = 256;
 *
 *      HAL_GAL_CreateSurface(600, 400, HAL_GAL_PIXEL_FORMAT_LUT8, &surface);
 *      retVal = HAL_GAL_GetSurfaceSetPalette(surface, palette, paletteLegnth);
 *      if(retVal != HAL_GAL_OK) {
 *      	// Error handling
 *      }
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_GetSurfacePalette(HAL_GAL_SURFACE_INFO_T* pSurface, UINT32* pPalette, SINT32 paletteLength);

/**
 *  @brief Set surface palette for 8bpp surface
 *
 * @rst
 * Functional Requirements
 *  Set surface palette for 8bpp surface
 *  Writes entries to the palette of a surface which is indexed color format such as CPU PIXEL_FORMAT_LUT8.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 10ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pSurface		[IN] surface handler
 *      pPalette		[IN] palette which is array of 32bit ARGB color entries
 *      paletteLength	[IN] number of entries of palette
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Remarks
 *  1. You have to register the palette info to your own surface handler because palette info needs to be referred from your own surface handler in blit or fillrect function. 'Your own surface handler' means the handler that is implemented as 'hash table' or 'linked-list' or 'array' for maintaining surface allocation.
 *  2. If pPalette is NULL, you have to do initialize as 0x0
 *
 * Example
 *   .. code-block:: cpp
 *
 *      HAL_GAL_STATE_T retVal;
 *      HAL_GAL_SURFACE_INFO_T surface; *
 *      UINT32 palette[256]= {
 *         // Black, W, R, G, B, C, Y, M,
 *         0xff000000, 0xffffffff, 0xffff0000, 0xff00ff00, 0xff0000ff, 0xff00ffff, 0xffffff00, 0xffff00ff,0x0 };
 *      SINT32 paletteLegnth = 256;
 *
 *      HAL_GAL_CreateSurface(600, 400, HAL_GAL_PIXEL_FORMAT_LUT8, &surface);
 *      retVal = HAL_GAL_SetSurfaceSetPalette(surface, palette, paletteLegnth);
 *      if(retVal != HAL_GAL_OK) {
 *      	// Error handling
 *      }
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_SetSurfacePalette(HAL_GAL_SURFACE_INFO_T* pSurface, UINT32* pPalette, SINT32 paletteLength);



/*----------------------------------------------------------------------------------------
    Control Operation
----------------------------------------------------------------------------------------*/
/**
 *  @brief Set surface as framebuffer
 *
 * @rst
 * Functional Requirements
 *  Set surface as framebuffer at specific hw controller such as fbdev0 or fbdev1.
 *  And chip vendor need to consider to vsync wait to avoid flikerling problem.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 20ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pSurface		[IN] surface handler
 *      fbHWControllerIndex	[IN] identifier of framebuffer hw controller(number)
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      HAL_GAL_STATE_T retVal;
 *      HAL_GAL_SURFACE_INFO_T surface;
 *
 *      HAL_GAL_CreateSurface(1920, 1080, HAL_GAL_PIXEL_FORMAT_ARGB, &surface);
 *      ret = HAL_GAL_SetFrameBuffer(&surface, 0);
 *      if(retVal != HAL_GAL_OK) {
 *      	// Error handling
 *      }
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_SetFrameBuffer(HAL_GAL_SURFACE_INFO_T *pSurface, UINT32 fbHWControllerIndex);

/**
 *  @brief Sets region(viewRect/dispRect) about framebuffer.
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  The response time of this function should be within 20ms.
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      fbHWControllerIndex 	[IN] Identifier of framebuffer hw controller(number)
 *      fbPropertyFlags		[IN] flags for framebuffer property setting
 *      pFbPropertyInfo		[IN] information about framebuffer property
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_SetFrameBufferProperty(UINT32 fbHWControllerIndex, HAL_GAL_FRAMEBUFFER_PROPERTY_FLAGS_T fbPropertyFLags, HAL_GAL_FRAMEBUFFER_PROPERTY_INFO_T* pFbPropertyInfo);


/**
 * @brief Sets region(viewRect/dispRect) and Stereoscope(on/off, stereoscope type) about framebuffer.
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  The response time of this function should be within 20ms.
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      fbHWControllerIndex		[IN] Identifier of framebuffer hw controller(number)
 *      fbPropertyFlags		[IN] flags for framebuffer property setting
 *      pFbPropertyInfo		[IN] information about framebuffer property
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_SetFrameBufferWithProperty(HAL_GAL_SURFACE_INFO_T *pSurface, UINT32 fbHWControllerIndex, HAL_GAL_FRAMEBUFFER_PROPERTY_FLAGS_T fbPropertyFlags,HAL_GAL_FRAMEBUFFER_PROPERTY_EXTENDED_INFO_T *pFbPropertyExInfo);

/**
 *  @brief Reset associated resource of FrameBuffer
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  The response time of this function should be within 20ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      fbHWControllerIndex	[IN] identifier of framebuffer hw controller(number)
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
 HAL_GAL_STATE_T  HAL_GAL_ResetFrameBuffer(UINT32 fbHWControllerIndex);

/**
 *  @brief Conrol to visility of specified pChangedFbList according to number of changedFbNum
 *
 * @rst
 * Functional Requirements
 *  Conrol to visility of specified pChangedFbList according to number of changedFbNum.
 *  Its operation must not have flikerling problem.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 20ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pChangedFbList		[IN] changed the framebuffer list
 *      changedFbNum		[IN] changed the number of framebuffer list
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      HAL_GAL_STATE_T retVal;
 *      ret = HAL_GAL_SetFrameBuffer(&surface, 0);
 *
 *      UINT32 changedFbNum = 2 ;
 *      HAL_GAL_FRAMEBUFFER_VISIBILITY_INFO_T changedFBList[2];
 *
 *      changedFBList[0].fbHWControllerIndex = 0;
 *      changedFBList[0].bVisibility = TRUE;
 *
 *      changedFBList[1].fbHWControllerIndex = 1;
 *      changedFBList[1].bVisibility = FALSE;
 *
 *      retVal = HAL_GAL_SetFBHWControllerVisibility(changedFBList, changedFbNum);
 *      if(retVal != HAL_GAL_OK) {
 *      	// Error handling
 *      }
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_SetFBHWControllerVisibility(HAL_GAL_FRAMEBUFFER_VISIBILITY_INFO_T *pChangedFbList, UINT32 changedFbNum);

/**
 *  @brief Get visibility for frame buffer of H/W controllers
 *
 * @rst
 * Functional Requirements
 *  Get visibility for frame buffer of H/W controllers
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 10ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      fbHWControllerIndex             [IN]        Framebuffer index
 *      pbVisibility                          [OUT]     Visibility on/off
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      HAL_GAL_STATE_T retVal;
 *      BOOLEAN visibilty = FALSE;

 *      ret = HAL_GAL_GetFBHWControllerVisibility(CURSOR_INDEX, &visibilty);
 *      if(retVal != HAL_GAL_OK) {
 *      	// Error handling
 *      }
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_GetFBHWControllerVisibility(UINT32 fbHWControllerIndex, BOOLEAN *pbVisibility);
/**
 *  @brief Decide whether to use vsync operation of specified FBHWController or not.
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      fbHWControllerIndex	[IN] identifier of framebuffer hw controller(number)
 *      bVsync [IN] vsync usage state of framebuffer
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_SetFBHWControllerVsync(UINT32 fbHWControllerIndex, BOOLEAN bVsync);

/**
 *  @brief Select output path mode of framebuffer HW controller between main chip and external FRC chip.
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  The response time of this function should be within 50ms.
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      fbHWControllerIndex	[IN] identifier of framebuffer hw controller(number)
 *      osdPathMode			[IN] select osd path mode
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_SetFBHWControllerPathMode(UINT32 fbHWControllerIndex, HAL_GAL_OSD_PATH_MODE_FLAGS_T osdPathMode);

/**
 *  @brief Waits for the all the H/W accelerated graphics operations to be done.
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *  None
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_SyncGraphic(void);

/*----------------------------------------------------------------------------------------
    Additional Feautres (ex: 2D-to-3D OSD, Mirror Mode, VCOM pattern, Filter Attribute setting)
----------------------------------------------------------------------------------------*/
/**
 *  @brief Flip screen (all OSDs) vertically and/or horizontally.
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      mirrorModeFlags	[IN] mirror mode information
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_SetScreenMirrorMode(HAL_GAL_MIRROR_FLAGS_T mirrorModeFlags);

/**
 *  @brief Sets 3D mode(3D on/off) and 3D type(top&bottom, SideBySide ...) of FrameBuffer.
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      osd3DOnOffMode 		[IN] select osd 3D on/off mode
 *      osd3DType			[IN] select osd 3D type
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_Set3DMode(HAL_GAL_3D_MODE_T osd3DOnOffMode, HAL_GAL_3D_TYPE_T osd3DType);

/**
 *  @brief Sets region(viewRect/dispRect) about framebuffer.
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      fbHWControllerIndex 	[IN] Identifier of framebuffer hw controller(number)
 *      bStereoscope			[IN] stereoscope mode on/off
 *      stereoscopeType		[IN] type of stereoscope (2D-to-3D, S3D)
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_SetFBHWControllerStereoscope(UINT32 fbHWControllerIndex, BOOLEAN bStereoscope, HAL_GAL_STEREOSCOPE_TYPE_T stereoscopeType);

/**
 *  @brief Change pixelFormat of framebuffer
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      fbHWControllerIndex 	[IN] Identifier of framebuffer hw controller(number)
 *      pixelFormat 			[IN]  pixel format
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_SetFrameBufferPixelFormat(UINT32 fbHWControllerIndex, HAL_GAL_PIXEL_FORMAT_EX_T pixelFormat);

/**
 *  @brief Get pixelFormat of framebuffer
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      fbHWControllerIndex 	[IN] Identifier of framebuffer hw controller(number)
 *      pixelFormat 			[OUT]  pixel format
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_GetFrameBufferPixelFormat(UINT32 fbHWControllerIndex, HAL_GAL_PIXEL_FORMAT_EX_T *pPixelFormat);

/**
 *  @brief Get currently enabled framebuffer list
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      ppSurfaceInfoList             [OUT]        information of framebuffer
 *      pNumOfSurface               [OUT]        The number of enabled framebuffer
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_GetFrameBufferList( HAL_GAL_SURFACE_INFO_T** ppSurfaceInfoList, UINT32* pNumOfSurface );

/**
 *  @brief Reset boot logo
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   None
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_ResetBootLogo(void);

/**
 *  @brief Set OSD rotation mode
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      type 	[IN] rotation degree
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T HAL_GAL_SetOSDRotationMode(HAL_GAL_OSD_ROTATE_TYPE_T type);

/**
 *  @brief Set OSD portrait mode
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      type 	[IN] rotation degree
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_SetOSDPortraitMode(HAL_GAL_OSD_ROTATE_TYPE_T type);

/**
 *  @brief Set OSD portrait ARC mode
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      gal_osd_portrait_arc_mode 	[IN] portrait ARC mode
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_SetOSDPortraitARCMode(HAL_GAL_OSD_PORTRAIT_ARC_MODE_T gal_osd_portrait_arc_mode);

/**
 *  @brief Get sharpness (0~255) of specific framebuffer hw controller
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      fbHWControllerIndex  [IN] Identifier of framebuffer hw controller(number)
 *      sharpness            [OUT] Sharpness value (0~255)
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T HAL_GAL_GetFBHWControllerSharpness(UINT32 fbHWControllerIndex, UINT8* sharpness);

/**
 *  @brief Set sharpness (0~255) of specific framebuffer hw controller
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      fbHWControllerIndex  [IN] Identifier of framebuffer hw controller(number)
 *      sharpness            [IN] Sharpness value (0~255)
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T HAL_GAL_SetFBHWControllerSharpness(UINT32 fbHWControllerIndex, UINT8 sharpness);

/**
 *  @brief Draw an image from encoded image to destination surface based on imageFromBuffer flags.
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  The response time of this function should be within 100ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pImageInfo	[IN]  source image information
 *      pDestSurface	[IN]  destination surface handler
 *      decodeFlags	[IN]	decode image flags
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_DecodeImage(HAL_GAL_IMAGE_INFO_T* pImageInfo, HAL_GAL_SURFACE_INFO_T* pDestSurface, HAL_GAL_DECODEIMAGE_FLAGS_T decodeFlags);

/**
 * @brief Set graphic output resolution of main OSD
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  The response time of this function should be within 20ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *       width [IN] Width for graphic output resolution
 *       height [IN] Height for graphic output resolution
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T	HAL_GAL_SetGraphicOutputResolution(HAL_GAL_RESOLUTION_T graphicOutputResolution);

/**
 * @brief Get graphic output resolution of main OSD
 *
 * @rst
 * Functional Requirements
 *  This function is deprecated.
 *
 * Responses to abnormal situations, including
 *  NA
 *
 * Performance Requirements
 *  NA
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *       pOSDOutputResolution [OUT] OSD resolution
 *
 * Return Value
 *  HAL_GAL_NOT_CALLABLE
 *
 * @endrst
 */
HAL_GAL_STATE_T  HAL_GAL_GetOSDOutputResolution(HAL_GAL_RECT_T *pOSDOutputResolution);

/**
 * @brief Get the information of GAL memory
 *
 * @rst
 * Functional Requirements
 *  Get the information of GAL memory
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 10ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pGraphicMemInfo [OUT] information of GAL memory
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      HAL_GAL_STATE_T retVal;
 *      HAL_GAL_GRAPHIC_MEM_INFO_T graphicMemInfo ;
 *
 *      ret= HAL_GAL_ GetGraphicMemInfo(&graphicMemInfo );
 *      if(retVal != HAL_GAL_OK) {
 *      	// Error handling
 *      }
 * @endrst
 */
 HAL_GAL_STATE_T  HAL_GAL_GetGraphicMemInfo(HAL_GAL_GRAPHIC_MEM_INFO_T *pGraphicMemInfo);

/**
 * @brief Move position of cursor.
 *
 * @rst
 * Functional Requirements
 *  Move position of cursor.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 50ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      fbHWControllerIndex	[IN]	identifier of framebuffer hw controller(number)
 *      pCursorPropert		[IN]	property information of cursor
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Remarks
 *  Size of H/W cursor is 256x256 to be based on FHD OSD.
 *  So it has to show as same size with FHD on all panel that include FHD, UHD , and so on.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      UINT32 fbHWControllerIndex = CURSOR_INDEX;
 *      HAL_GAL_CURSOR_PROPERTY_INFO_T cursorProperty;
 *      cursorProperty.position.x = 200;
 *      cursorProperty.position.y = 200;
 *      cursorProperty.panelWidth = 1920;
 *      cursorProperty.panelHeight = 1080;
 *      cursorProperty.width = 128;
 *      cursorProperty.height = 128;
 *      cursorProperty.hotspot = HAL_GAL_CURSOR_HOTSPOT_LEFTTOP;
 *
 *      retVal = HAL_GAL_MoveCursor(fbHWControllerIndex , &cursorProperty);
 *      if(retVal != HAL_GAL_OK) {
 *      	// Error handling
 *      }
 * @endrst
 */
HAL_GAL_STATE_T HAL_GAL_MoveCursor(UINT32 fbHWControllerIndex, HAL_GAL_CURSOR_PROPERTY_INFO_T *pCursorProperty);

/**
 * @brief Set position of cursor.
 *
 * @rst
 * Functional Requirements
 *  Set cursor position and property to move position or change cursor status.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 50ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pCursorPosition	[IN]	position and property information of cursor
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Remarks
 *  The cursor position is set on the basis of graphic input.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      HAL_GAL_CURSOR_POSITION_INFO_T cursorPosition;
 *      cursorPosition.position.x = 200;
 *      cursorPosition.position.y = 200;
 *      cursorPosition.width = 128;
 *      cursorPosition.height = 128;
 *      cursorPosition.hotspot = HAL_GAL_CURSOR_HOTSPOT_LEFTTOP;
 *
 *      retVal = HAL_GAL_SetCursorPosition(&cursorPosition);
 *      if(retVal != HAL_GAL_OK) {
 *      	// Error handling
 *      }
 * @endrst
 */
HAL_GAL_STATE_T HAL_GAL_SetCursorPosition(HAL_GAL_CURSOR_POSITION_INFO_T* pCursorPosition );

/**
 * @brief Set resolution of cursor.
 *
 * @rst
 * Functional Requirements
 *  This API determine cursor resolution to calculate like below fomular.
 *  - cursor width of resolution on panel = cursorImageResolution.width / cursorCoordinateResolution.width
 *  -cursor height of resolution on panel = cursorImageResolution.height/ cursorCoordinateResolution.height
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 10ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      cursorCoordinateResolution  [IN]    coordinate resolution
 *      cursorImageResolution   [IN]    original cursor image resolution
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Remarks
 *  We are going to invoke this APIS at initial time then you set cursor resolution.
 *
 * Example
 *   .. code-block:: cpp
 *
 *      HAL_GAL_RESOLUTION_T cursorCoordinateResolution, cursorImageResolution;
 *
 *      cursorCoordinateResolution.width = 1920;
 *      cursorCoordinateResolution.height = 1080;
 *      cursorImageResolution = 1920;
 *      cursorImageResolution = 1080;
 *
 *      retVal = HAL_GAL_SetCursorResolution(cursorCoordinateResolution, cursorImageResolution);
 *      if(retVal != HAL_GAL_OK) {
 *      	// Error handling
 *      }
 * @endrst
 */
HAL_GAL_STATE_T HAL_GAL_SetCursorResolution(HAL_GAL_RESOLUTION_T cursorCoordinateResolution, HAL_GAL_RESOLUTION_T cursorImageResolution);

/**
 * @brief Get a framebuffer from the fbdev to a surface
 *
 * @rst
 * Functional Requirements
 *  Get a framebuffer from the fbdev to a surface.
 *	The surface is created by user and the driver do stretch blit from the framebuffer to the surface.
 *
 * Responses to abnormal situations, including
 *  - If the function fails, the return value shall be an one of error in HAL_GAL_STATE_T.
 *  - If the function is not supported, the retur value shall be HAL_GAL_NOT_CALLABLE.
 *
 * Performance Requirements
 *  The response time of this function should be within 100ms.
 *
 * Constraints
 *  NA
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *      pSurfaceInfo [IN/OUT]  The target surface to store the read framebuffer from the fbdev
 *
 * Return Value
 *  If success HAL_GAL_OK, else an one of error in HAL_GAL_STATE_T.
 *
 * Remarks
 *  This function is supported from webOS4.5 and later and the SoC supports Linux framebuffer(fbdev).
 *
 * Example
 *   .. code-block:: cpp
 *
 *      HAL_GAL_STATE_T retVal;
 *      HAL_GAL_SURFACE_INFO_T surfaceInfo;
 *
 *      HAL_GAL_CreateSurface(1920, 1080, HAL_GAL_PIXEL_FORMAT_ARGB, &surfaceInfo);
 *      if(HAL_GAL_CaptureFrameBuffer(&surfaceInfo) != GM_OK)
 *      if(retVal != HAL_GAL_OK) {
 *      	// Error handling
 *      }
 * @endrst
 */
HAL_GAL_STATE_T HAL_GAL_CaptureFrameBuffer(HAL_GAL_SURFACE_INFO_T *pSurfaceInfo);

#endif
