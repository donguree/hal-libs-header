/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/
/** @file hal_i2c.h
 *
 *  This c file defines the HAL functions related to I2C Driver.
 *
 *  @author		kwangseok.kim (kwangseok.kim@lge.com)
 *  @version		0.1
 *  @date		2017.02.22
 *  @note
 *  @see
 */

/*****************************************************************************
	Header File Guarder
*****************************************************************************/
#ifndef _HAL_I2C_H_
#define _HAL_I2C_H_

/******************************************************************************
        File Inclusions
******************************************************************************/
#include "hal_common.h"

/*****************************************************************************
	Constant Definitions
*****************************************************************************/
#define I2C_OK				 0
#define I2C_ERROR			-1

/******************************************************************************
        Type Definitions
******************************************************************************/

/**
 * type definition about i2c speed
 *
*/
typedef enum
{
	I2C_MODE_NORMAL 	=	0,		/**< normal speed	: 100K	*/
	I2C_MODE_FAST		=	1,		/**< fast speed 	: 400K	*/
	I2C_MODE_SLOW		=	2,		/**< slow speed 	:  50K	*/
	I2C_MODE_DOWNLOAD1	=	3,		/**< download speed 	: 700K	*/
	I2C_MODE_DOWNLOAD2	=	4,		/**< download speed 	: 800K	*/
}	I2C_MODE_T;


/******************************************************************************
        Function Declaration
******************************************************************************/
extern DTV_STATUS_T HAL_I2C_Init (void);
extern DTV_STATUS_T HAL_I2C_Read (UINT8 ChNum, I2C_MODE_T transMode, UINT8 slaveAddr, UINT32 subAddrMode,
									   UINT8 *subAddr, UINT16 nBytes, UINT8 *rxBuf, UINT32 retry);
extern DTV_STATUS_T HAL_I2C_Write(UINT8 ChNum, I2C_MODE_T transMode, UINT8 slaveAddr, UINT32 subAddrMode,
								 	   UINT8 *subAddr, UINT16 nBytes, UINT8 *txBuf, UINT32 retry);

#endif	/* _HAL_I2C_H_ */
