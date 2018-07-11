/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2018 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file 		hal_criu.h
 *
 *  header of Common Interface HAL Fuction.
 *
 *  @author		juhyun121.kim
 *  @version	1.0
 *  @date		2018.7.11
 *  @date
 *  @note		Additional information.
 *  @see
 */

/******************************************************************************
	Header File Guarder
******************************************************************************/
#ifndef _COMMON_HAL_CRIU_H_
#define _COMMON_HAL_CRIU_H_

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

/******************************************************************************
	Function Declaration
******************************************************************************/
int HAL_CRIU_PreCheckpointNotify(void);
int HAL_CRIU_PostDumpNotify(void);
int HAL_CRIU_PostRestoreNotify(void);

#endif				/* _COMMON_HAL_CRIU_H_ */
