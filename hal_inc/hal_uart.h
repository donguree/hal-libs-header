/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/


/** @file uart_ddi.h
 *
 *  This header file declares the data types and DDI functions to control the SPI(serial peripheral interface)
 *
 *  @author	Kyoungwon Park (ryan2808@lge.com)
 *  @version	2.0
 *  @date		2009.01.15
 *  @date		2009.11.19
 *  @note		Additional information.
 *  @see
 */

/******************************************************************************
 	Header File Guarder
******************************************************************************/
#ifndef _HAL_UART_H_
#define _HAL_UART_H_

/******************************************************************************
        File Inclusions
******************************************************************************/

/******************************************************************************
        Constant Definitions
******************************************************************************/
#define	PDP_UART_PORT					1
#define	CPU_UART_PORT					2

/******************************************************************************
        Macro Definitions
******************************************************************************/

/******************************************************************************
        Type Definitions
******************************************************************************/

/******************************************************************************
        Enum Definitions
******************************************************************************/
typedef enum
{
	TOP_UART0=1,
	TOP_UART1,
	TOP_UART2,
	TOP_MAX,
} TOP_UART_T;

typedef enum
{
	UART_CPU0=1,
	UART_SP0,
	UART_LED0,
	UART_SPP0,
	UART_CPU1,
	UART_SP1,
	UART_CPU2,
	UART_SPP1,
	UART_LED1,
} TOP_UART_TYPE_T;

/******************************************************************************
        Function Declaration
******************************************************************************/
/* SIC specific model only used. */
DTV_STATUS_T HAL_UART_OPEN(int port);
DTV_STATUS_T HAL_UART_CLOSE(int port);

DTV_STATUS_T HAL_UART_Write(unsigned char *pWriteData, unsigned int  writeSize, unsigned int uart_port);
DTV_STATUS_T HAL_UART_ReadCheck(unsigned char *pCheckData, unsigned int  checkSize, unsigned int uart_port);
DTV_STATUS_T HAL_UART_READ(unsigned char *pBuf, unsigned int  sizeToRead, unsigned int uart_port,unsigned int *ret);
DTV_STATUS_T HAL_UART_Config(int port, UINT32 speed , UINT32 bit );
DTV_STATUS_T HAL_UART_Get_Status(int port,  UINT32 mode , UINT32 * status, UINT32 timeout);

#endif  /* _HAL_UART_H_ */

