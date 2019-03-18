/******************************************************************************
 *	 DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *	 Copyright(c) 2019 by LG Electronics Inc.
 *
 *	 All rights reserved. No part of this work may be reproduced, stored in a
 *	 retrieval system, or transmitted by any means without prior written
 *	 permission of LG Electronics Inc.
 *****************************************************************************/

#ifndef _HAL_GFX_H_
#define _HAL_GFX_H_

#ifdef __cplusplus
extern "C" {
#endif

#define HAL_GFX_RELEASE_VERSION (2)

#ifndef hal_gfx_ptr
typedef	void *__hal_gfx_ptr;
#define hal_gfx_ptr __hal_gfx_ptr
#endif

#ifndef hal_gfx_int
typedef	int __hal_gfx_int;
#define hal_gfx_int __hal_gfx_int
#endif

#ifndef hal_gfx_int32
typedef	signed int __hal_gfx_int32;
#define hal_gfx_int32 __hal_gfx_int32
#endif

#define HG_OK       (0x00)  /* work well */
#define HG_NOTOK    (0xff)  /* abnormal behavior */

typedef enum {
    Surface_Format_Unknown = 0,
    Surface_Format_A8R8G8B8,
    Surface_Format_FBC,
} hal_gfx_surface_format;

typedef struct {
    hal_gfx_int32 x;
    hal_gfx_int32 y;
    hal_gfx_int32 width;
    hal_gfx_int32 height;
} hal_gfx_rect;

typedef struct {
    hal_gfx_surface_format format;
    hal_gfx_int32 width;
    hal_gfx_int32 height;
    hal_gfx_int32 stride;
} hal_gfx_surface_attr;

typedef struct {
    hal_gfx_surface_attr attribute;
    hal_gfx_int fd;
    hal_gfx_ptr handle;
} hal_gfx_surface;

typedef struct {
    hal_gfx_surface src;
    hal_gfx_rect in_region;
} hal_gfx_blit_param;

hal_gfx_int
hal_gfx_import_surface_by_fd(hal_gfx_int fd,
                             hal_gfx_surface_attr attr,
                             hal_gfx_ptr *handle);

hal_gfx_int
hal_gfx_release_surface(hal_gfx_ptr handle);

hal_gfx_int
hal_gfx_blit(hal_gfx_surface dst,
             hal_gfx_blit_param *params,
             hal_gfx_int params_len);

#ifdef __cplusplus
}
#endif

#endif /* _HAL_GFX_H_ */
