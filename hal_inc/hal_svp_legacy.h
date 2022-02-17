/******************************************************************************
 *   TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2013-2022 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file		hal_svp_legacy.h
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
#ifndef	_HAL_SVP_LEGACY_H_
#define	_HAL_SVP_LEGACY_H_

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
SVP_STATUS_T HAL_SVP_OpenSecureCpbEx(UINT32 secCpbAddr, SINT32 secCpbSize,SINT32 align);
SVP_STATUS_T HAL_SVP_CloseSecureCpb(void);
SVP_STATUS_T HAL_SVP_CloseSecureCpbEx(UINT32 secCpbAddr, SINT32 secCpbSize);
BOOLEAN HAL_SVP_IsSecureReformatterSupported(void);
SVP_STATUS_T HAL_SVP_SetSecureReformatter(SVP_REFORMATTER_T reformatterType);
SVP_STATUS_T HAL_SVP_SetSecureReformatterEx(UINT32 secCpbAddr, SVP_REFORMATTER_T reformatterType);
SVP_STATUS_T HAL_SVP_GetSecureCpbInformation (ULONG vdecHandle,
	ULONG *pSecCpbAddr, SINT32 *pSecCpbSize, SINT32 *pReadOffset, SINT32 *pWriteOffset);
SVP_STATUS_T HAL_SVP_GetSecureDecryptBufferHandle(UINT32 *pSecDecBufHandle, UINT32 *pSecDecBufSize);
SVP_STATUS_T HAL_SVP_GetSecureDecryptBufferHandleEx(UINT32 secCpbAddr, UINT32 *pSecDecBufHandle, UINT32 *pSecDecBufSize);
SVP_STATUS_T HAL_SVP_GetAuInformation(UINT32 *pAuWritePosition, SINT32 *pAuWriteLength,
	UINT32 *pWritePosition, UINT32 readPosition, UINT32 secDecBufHandle, UINT32 srcLength);
SVP_STATUS_T HAL_SVP_CheckAuTypeIsDolbyHdrMeta(UINT32 auWritePosition, SINT32 auWriteLength, BOOLEAN *pIsMetaType);
SVP_STATUS_T HAL_SVP_FlushSecureDecryptBuffer(void);
SVP_STATUS_T HAL_SVP_FlushSecureDecryptBufferEx(UINT32 secCpbAddr);

SVP_STATUS_T HAL_SVP_WidevineSelectKey(UINT32 session, const UINT8 *key_id, size_t key_id_length);
SVP_STATUS_T HAL_SVP_WidevineSelectKey_OverV14(UINT32 session, const UINT8 *key_id, size_t key_id_length, SINT32 cipherMode);
SVP_STATUS_T HAL_SVP_WidevineDecryptCTR(UINT32 session, const UINT8 *data_addr, size_t data_length, BOOLEAN is_encrypted,
	const UINT8 *iv, size_t block_offset, const void *out_buffer, UINT8 subsample_flags);

SVP_STATUS_T HAL_SVP_WidevineDecryptCENC(UINT32 session, const UINT8 *data_addr, size_t data_length, BOOLEAN is_encrypted,
	const UINT8 *iv, size_t block_offset, const void *out_buffer, const void *pattern, UINT8 subsample_flags);
SVP_STATUS_T HAL_SVP_WidevineDecryptCENC_V16(UINT32 session,
                                             void *samples,
                                             size_t samples_length,
                                             void *pattern,
                                             UINT32 *oec_return);

SVP_STATUS_T HAL_SVP_CopyToSecureDecryptBuffer(UINT32 secDecBufHandle, UINT32 secDecBufwriteOffset,
	UINT8 *pSrc, SINT32 length);

SVP_STATUS_T HAL_SVP_CopyFromSecureBuffer(UINT32 srcHandle, UINT8 *pOutput, SINT32 length);

#endif /* _HAL_SVP_LEGACY_H_ */

