/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/


/** @file hal_usb.h
 *
 *  This header file declares the data types and DDI functions to control the USB
 *
 *  @author Shinhoe Kim (shnihoe.kim@lge.com)
 *  @version  1.0
 *  @date   2013.12.18
 *  @note   Additional information.
 *  @see
 */

/******************************************************************************
  Header File Guarder
******************************************************************************/
#ifndef _HAL_USB_H_
#define _HAL_USB_H_

/******************************************************************************
  File Inclusions
******************************************************************************/
//#include "usb_kadp.h"
#include "hal_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
  Constant Definitions
******************************************************************************/
#define HAL_USB_SUPERSPEED_BUSNUM       2
#define HAL_USB_SUPERSPEED_PORTNUM      1
/******************************************************************************
  Macro Definitions
******************************************************************************/

/******************************************************************************
  Type Definitions
******************************************************************************/


/******************************************************************************
  Function Declaration
******************************************************************************/
/*USB 3.0 Enable,Disable*/
DTV_STATUS_T HAL_USB_SuperSpeedPortUp(UINT32 busNum, UINT32 portNum);
DTV_STATUS_T HAL_USB_SuperSpeedPortOff(UINT32 busNum, UINT32 portNum);
DTV_STATUS_T HAL_USB_SuperSpeedVBusControl(BOOLEAN bOn, UINT32 busNum, UINT32 portNum);
/* Dummy functions */
DTV_STATUS_T HAL_USB_SuperSpeedDisable(UINT32 busNum, UINT32 portNum);

#ifdef __cplusplus
}
#endif

#endif  /* _HAL_USB_H_ */

