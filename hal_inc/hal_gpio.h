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
 *  This c file defines the DDI functions related to I2C Driver.
 *
 *  @author		dhjung(dhjung77@lge.com)
 *  @version	0.1
 *  @date		2008.02.12
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
extern SINT32 gHalGpioLogmFd;
#define HAL_GPIO_LOGM 						"hal-gpio"
#define HAL_GPIO_ERROR(fmt,args...)		KADP_LOGM_PRINT(gHalGpioLogmFd, LX_LOGM_LEVEL_ERROR, 	fmt, ##args)
#define HAL_GPIO_WARN(fmt,args...)		KADP_LOGM_PRINT(gHalGpioLogmFd, LX_LOGM_LEVEL_WARNING, fmt, ##args)
#define HAL_GPIO_NOTI(fmt,args...)		KADP_LOGM_PRINT(gHalGpioLogmFd, LX_LOGM_LEVEL_NOTI, 	fmt, ##args)
#define HAL_GPIO_INFO(fmt,args...)		KADP_LOGM_PRINT(gHalGpioLogmFd, LX_LOGM_LEVEL_INFO, 	fmt, ##args)
#define HAL_GPIO_DEBUG(fmt,args...)		KADP_LOGM_PRINT(gHalGpioLogmFd, LX_LOGM_LEVEL_DEBUG, 	fmt, ##args)
#define HAL_GPIO_TRACE(fmt,args...)		KADP_LOGM_PRINT(gHalGpioLogmFd, LX_LOGM_LEVEL_TRACE, 	fmt, ##args)

/* CMIO GPIO */
/**
 * type definition about gpio group
 *
*/
typedef enum
{
	GPIO_GROUP_GPIO = 1,	/**< gpio group */
	GPIO_GROUP_GPI,			/**< gpi group */
	GPIO_GROUP_GPO			/**< gpo group */

}	GPIO_GROUP_T;

/**
* type definition about gpio high low
*
*/
typedef enum
{
	GPIO_LOW  = 0,			/**< gpio low */
	GPIO_HIGH 				/**< gpio high */
} GPIO_VALUE_T;


/* CMNIO GPIO */
extern DTV_STATUS_T	HAL_GPIO_Init (UINT8 boardType);
extern DTV_STATUS_T	HAL_GPIO_InitEx( UINT8 boardType, UINT8 resolution );
extern DTV_STATUS_T	HAL_GPIO_SetPortDirection(UINT32 portIndex, BOOLEAN direction);
extern DTV_STATUS_T	HAL_GPIO_SetPortDirection_SP(UINT32 portIndex, BOOLEAN direction); //sungwoo.han 1234
extern DTV_STATUS_T	HAL_GPIO_SetOutputPort(UINT32 portIndex, UINT8 data);
extern DTV_STATUS_T	HAL_GPIO_SetOutputPhysicalPort( UINT32 portNum, UINT8 data, UINT32 mode );
extern DTV_STATUS_T	HAL_GPIO_GetInputPhysicalPort( UINT32 portNum, UINT8 *pData, UINT32 mode );
extern DTV_STATUS_T	HAL_GPIO_SetPhysicalPortDirection( UINT32 portNum, BOOLEAN direction, UINT32 mode );

#if 1 /* Jason Lim, for fast I2C */
extern DTV_STATUS_T HAL_GPIO_I2C_ReadWriteByte(UINT32 portIndex_sda, UINT32 portIndex_scl, BOOLEAN bWrite, UINT8 *pData);
#endif


extern DTV_STATUS_T	HAL_GPIO_GetInputPort(UINT32 portIndex, UINT8 *pData);
extern DTV_STATUS_T	HAL_GPIO_SetOutputPortArray(UINT32 numArray, UINT32 portArray[], UINT8 dataArray[]);
extern DTV_STATUS_T	HAL_GPIO_GetInputPortArray(UINT32 numArray, UINT32 portArray[], UINT8 dataArray[]);
extern DTV_STATUS_T	HAL_GPIO_SetIntrCallBack(UINT32 portIndex, void (*pfnGPIO_CB)(UINT32), UINT32 enable);
extern DTV_STATUS_T HAL_GPIO_GetIntrCount(UINT32 portIndex, UINT32 *pcount, UINT32 *pmsec);




#endif	/* _HAL_GPIO_H_ */
