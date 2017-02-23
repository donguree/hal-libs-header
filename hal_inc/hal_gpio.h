/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/
/** @file hal_gpio.h
 *
 *  This c file defines the HAL functions related to GPIO Driver.
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
#ifndef _HAL_GPIO_H_
#define _HAL_GPIO_H_

/*****************************************************************************
	#include File
*****************************************************************************/
#include "hal_common.h"

/*****************************************************************************
	Constant Definitions
*****************************************************************************/

/* CMIO GPIO */
/**
 * type definition about gpio group
 *
*/
typedef enum
{
	GPIO_GROUP_GPIO = 1,	/**< gpio group */
	GPIO_GROUP_GPI,		/**< gpi group */
	GPIO_GROUP_GPO		/**< gpo group */

}	GPIO_GROUP_T;

/**
* type definition about gpio high low
*
*/
typedef enum
{
	GPIO_LOW  = 0,		/**< gpio low */
	GPIO_HIGH 		/**< gpio high */
} GPIO_VALUE_T;


/* CMNIO GPIO */
extern DTV_STATUS_T	HAL_GPIO_Init (UINT8 boardType);
extern DTV_STATUS_T	HAL_GPIO_InitEx( UINT8 boardType, UINT8 resolution );

extern DTV_STATUS_T	HAL_GPIO_SetPortDirection(UINT32 portIndex, BOOLEAN direction);
extern DTV_STATUS_T	HAL_GPIO_SetPortDirection_SP(UINT32 portIndex, BOOLEAN direction);
extern DTV_STATUS_T	HAL_GPIO_SetOutputPort(UINT32 portIndex, UINT8 data);
extern DTV_STATUS_T	HAL_GPIO_GetInputPort(UINT32 portIndex, UINT8 *pData);

extern DTV_STATUS_T	HAL_GPIO_SetOutputPortArray(UINT32 numArray, UINT32 portArray[], UINT8 dataArray[]);
extern DTV_STATUS_T	HAL_GPIO_GetInputPortArray(UINT32 numArray, UINT32 portArray[], UINT8 dataArray[]);

extern DTV_STATUS_T	HAL_GPIO_SetOutputPhysicalPort( UINT32 portNum, UINT8 data, UINT32 mode );
extern DTV_STATUS_T	HAL_GPIO_GetInputPhysicalPort( UINT32 portNum, UINT8 *pData, UINT32 mode );
extern DTV_STATUS_T	HAL_GPIO_SetPhysicalPortDirection( UINT32 portNum, BOOLEAN direction, UINT32 mode );

extern DTV_STATUS_T	HAL_GPIO_SetIntrCallBack(UINT32 portIndex, void (*pfnGPIO_CB)(UINT32), UINT32 enable);
extern DTV_STATUS_T	HAL_GPIO_GetIntrCount(UINT32 portIndex, UINT32 *pcount, UINT32 *pmsec);


#endif	/* _HAL_GPIO_H_ */
