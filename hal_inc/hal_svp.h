/******************************************************************************
 *   TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2013-2017 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file		hal_svp.h
 *
 *  Hardware Abstration Layer for DRM
 *
 *  @author
 *  @version	1.0
 *  @date		2014.07.
 *  @note
 *  @see
 */

/******************************************************************************
    Header File Guarder
******************************************************************************/
#ifndef	_HAL_SVP_H_
#define	_HAL_SVP_H_

/******************************************************************************
    Control Constants
******************************************************************************/

/******************************************************************************
    File Inclusions
******************************************************************************/
#include "hal_common.h"

/******************************************************************************
    Constant Definitions
******************************************************************************/

/******************************************************************************
    Macro Definitions
******************************************************************************/

/******************************************************************************
    Type Definitions
******************************************************************************/
typedef enum {
  HAL_SVP_REFORMATTER_NONE           = 0,
  HAL_SVP_REFORMATTER_AVC            = 1,
  HAL_SVP_REFORMATTER_HEVC           = 2,
  HAL_SVP_REFORMATTER_HEVC_COMPLETE  = 3,
} SVP_REFORMATTER_T;

typedef enum {
  HAL_SVP_ERROR	= -1,
  HAL_SVP_OK    = 0,
  HAL_SVP_NO_AU	= 1,
  HAL_SVP_WAIT	= 2
} SVP_STATUS_T;

/******************************************************************************
    Function Declaration
******************************************************************************/

SVP_STATUS_T HAL_SVP_OpenSecureCpb(UINT32 secCpbAddr, SINT32 secCpbSize);
SVP_STATUS_T HAL_SVP_OpenSecureCpbEx(UINT32 secCpbAddr, SINT32 secCpbSize, SINT32 align);
SVP_STATUS_T HAL_SVP_CloseSecureCpb(void);
SVP_STATUS_T HAL_SVP_CloseSecureCpbEx(UINT32 secCpbAddr, SINT32 secCpbSize);
BOOLEAN HAL_SVP_IsSecureReformatterSupported(void);
SVP_STATUS_T HAL_SVP_SetSecureReformatter(SVP_REFORMATTER_T reformatterType);
SVP_STATUS_T HAL_SVP_SetSecureReformatterEx(UINT32 secCpbAddr, SVP_REFORMATTER_T reformatterType);
SVP_STATUS_T HAL_SVP_GetSecureCpbInformation (ULONG vdecHandle,
	ULONG *pSecCpbAddr, SINT32 *pSecCpbSize, SINT32 *pReadOffset, SINT32 *pWriteOffset);
SVP_STATUS_T HAL_SVP_GetSecureDecryptBufferHandle(UINT32 *pSecDecBufHandle, UINT32 *pSecDecBufSize);
SVP_STATUS_T HAL_SVP_GetSecureDecryptBufferHandleEx(UINT32 secCpbAddr, UINT32 *pSecDecBufHandle, UINT32 *pSecDecBufSize);
SVP_STATUS_T HAL_SVP_GetAuInformation(UINT32 *pAuWritePoSINT32, SINT32 *pAuWriteLength,
	UINT32 *pWritePoSINT32, UINT32 readPoSINT32, UINT32 secDecBufHandle, UINT32 srcLength);
SVP_STATUS_T HAL_SVP_CheckAuTypeIsDolbyHdrMeta(UINT32 auWritePoSINT32, SINT32 auWriteLength, BOOLEAN *pIsMetaType);
SVP_STATUS_T HAL_SVP_FlushSecureDecryptBuffer(void);
SVP_STATUS_T HAL_SVP_FlushSecureDecryptBufferEx(UINT32 secCpbAddr);

SVP_STATUS_T HAL_SVP_Widevine_DecryptVideo(UNIT8 *pIv, UNIT8 *pSrc, UINT32 srcLength,
	UINT32 secDecBufHandle, UINT32 secDecBufwriteOffset, UINT32 *pOutputLength);
SVP_STATUS_T HAL_SVP_Widevine_DecryptAudio(UNIT8 *pIv, UNIT8 *pSrc, UINT32 srcLength,
	UNIT8 *pOutput, UINT32 *pOutputLength);

SVP_STATUS_T HAL_SVP_WidevineSelectKey(UINT32 session, const UNIT8 *key_id, size_t key_id_length);
SVP_STATUS_T HAL_SVP_WidevineDecryptCTR(UINT32 session, const UNIT8 *data_addr, size_t data_length, SINT8 is_encrypted,
	const UNIT8 *iv, size_t block_offset, const void *out_buffer, UNIT8 subsample_flags);

SVP_STATUS_T HAL_SVP_CopyToSecureDecryptBuffer(UINT32 secDecBufHandle, UINT32 secDecBufwriteOffset,
	UNIT8 *pSrc, SINT32 length);

SVP_STATUS_T HAL_SVP_CopyFromSecureBuffer(UINT32 srcHandle, UNIT8 *pOutput, SINT32 length);

#endif /* _HAL_SVP_H_ */

