/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file 		hal_acas.h
 *
 *  header of ACAS HAL Fuction.
 *
 *
 *  @author		YoungKi Son (yk.son@lge.com)
 *  @author
 *  @version	1.0
 *  @date		2018.3.13 YoungKi Son (yk.son@lge.com)
 *  @date		2018.3.13 Created
 *  @date
 *  @note		Additional information.
 *  @see
 */

/******************************************************************************
 	Header File Guarder
******************************************************************************/
#ifndef _ACAS_HAL_H_
#define _ACAS_HAL_H_

/******************************************************************************
    ���� ���� ���(Control Constants)
******************************************************************************/

/******************************************************************************
	#include ���ϵ� (File Inclusions)
******************************************************************************/
#include "hal_common.h"
#include "hal_sdec_common.h"

/******************************************************************************
 	��� ����(Constant Definitions)
******************************************************************************/

/******************************************************************************
    ��ũ�� �Լ� ���� (Macro Definitions)
******************************************************************************/

/******************************************************************************
	�� ���� (Type Definitions)
******************************************************************************/

/******************************************************************************
	�Լ� ���� (Function Declaration)
******************************************************************************/
DTV_STATUS_T HAL_ACAS_Init(UINT8 ubyChipIndex);
DTV_STATUS_T HAL_ACAS_Reset(UINT8 ubyChipIndex);
DTV_STATUS_T HAL_ACAS_TransferAPDU(UINT8 ubyChipIndex, UINT8 *commandAPDU, UINT32 commandAPDULen, UINT8 *responseAPDU, UINT32 *responseAPDULen, UINT32 maxresponseAPDULen);

#endif /*_ACAS_HAL_H_ */

