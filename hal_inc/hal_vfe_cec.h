/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file hal_vfe_cec.h
 *
 *  It is the header file for controling Analog-Video-Decoder function.
 *  The header of Analog-Video-Decoder function DDI is controlled by this file.
 *
 *  @author	hyungyong.park(hyungyong.park@lge.com)
 *  @version	0.1
 *  @date		2013.03.14
 *  @note
 *  @see
 */

/*-----------------------------------------------------------------------------
	Header File Guarder
------------------------------------------------------------------------------*/
#ifndef _HAL_VFE_CEC_H_
#define _HAL_VFE_CEC_H_

void HAL_VFE_CEC_Initialize(void);
DTV_STATUS_T HAL_VFE_CEC_ReadCECCommand(UINT8 *pData); 
DTV_STATUS_T HAL_VFE_CEC_ReadCECResult(UINT8 *pData); 
DTV_STATUS_T HAL_VFE_CEC_WriteCECCommand(UINT8 *pCmd);
UINT16 HAL_VFE_CEC_ReadCECResponse(void); 


#endif /* _VIDEO_SOC_VBI_DDI_H_ */

