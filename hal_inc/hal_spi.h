/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2017 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.

 *****************************************************************************/

/** @file hal_spi.h
  *
  *  System related header file
  *
  *  @author		Lee-hwan Noh (roy.noh@lge.com)
  *  @version		 1.0
  *  @date		2017.07.03
  *  @note
  *  @see		hal_spi.c
*/

/******************************************************************************
        Header File Guarder
******************************************************************************/
#ifndef _HAL_SPI_H_
#define _HAL_SPI_H_

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
        Enum Definitions
******************************************************************************/
/******************************************************************************
        Function Declaration
******************************************************************************/
/* SPI Read Write function
 * requester: roy.noh
 */
DTV_STATUS_T HAL_SPI_Init(void);
DTV_STATUS_T HAL_SPI_SetConfig(UINT8 u8Channel,  UINT32 u32speed) ;
DTV_STATUS_T HAL_SPI_Write(UINT8 u8Channel, UINT32 u32addrToWrite, UINT8* u8dataToWrite, UINT32 u32size);
DTV_STATUS_T HAL_SPI_Read(UINT8 u8Channel, UINT32 u32addrToRead, UINT8* u8dataToRead, UINT32 u32size);





#endif  /* _HAL_SPI_H_ */
