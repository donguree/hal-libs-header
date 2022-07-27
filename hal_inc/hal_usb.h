/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2022 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/


/** @file hal_usb.h
 *
 *  This header file declares the data types and HAL functions to control the USB
 *
 *  @author Junmo Kang (jm0122.kang@lge.com)
 *  @version  1.1
 *  @date   2022.07.28
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
/**
 * @brief Enable USB3.0 (Super speed) by enable xhci controller
 *
 * @rst
 * Functional Requirements
 *   Turn on super speed port
 *   Recovery USB 3.0 PHY to work on the super speed mode
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 100ms.
 *
 * Constraints
 *   Implementation is required only if there is a USB3.0 (xhci) controller.
 *
 * Functions & Parameters
 *   ============ ===========
 *   type         name
 *   ============ ===========
 *   unsigned int busNumber
 *   unsigned int portNumber
 *   ============ ===========
 *
 * Return Value
 *   If the function succeeds, the return value is Zero(0).
 *   If the function fails, the return value is non-Zero(-1 or errno).
 *
 * Pseudo Code
 *   .. code-block:: cpp
 *
 *   DTV_STATUS_T HAL_USB_SuperSpeedPortUp(unsigned int busNumber, unsigned int portNumber)
 *   {
 *       Turn on super speed port
 *       IF any error occurred THEN
 *           RETURN NOT_OK
 *       END IF
 *       RETURN OK
 *   }
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T retVal;
 *     retVal = HAL_USB_SuperSpeedPortUp(2, 1);
 *     if (RetVal != OK) {
 *         //error handling
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_USB_SuperSpeedPortUp(UINT32 busNum, UINT32 portNum);
/**
 * @brief Disable USB3.0 (Super speed) by disable xhci controller
 *
 * @rst
 * Functional Requirements
 *   Turn off super speed port
 *   Disable USB 3.0 PHY to not work on the super speed mode
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 100ms.
 *
 * Constraints
 *   Implementation is required only if there is a USB3.0 (xhci) controller.
 *
 * Functions & Parameters
 *   ============ ===========
 *   type         name
 *   ============ ===========
 *   unsigned int busNumber
 *   unsigned int portNumber
 *   ============ ===========
 *
 * Return Value
 *   If the function succeeds, the return value is Zero(0).
 *   If the function fails, the return value is non-Zero(-1 or errno).
 *
 * Pseudo Code
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T HAL_USB_SuperSpeedPortOff (unsigned int busNumber, unsigned int portNumber)
 *     {
 *         Turn off USB super speed port
 *         IF any error occurred THEN
 *             RETURN NOT_OK
 *         END IF
 *         RETURN OK
 *     }
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T retVal;
 *         retVal = HAL_USB_SuperSpeedPortOff(2, 1);
 *         if (RetVal != OK) {
 *             //error handling
 *         }
 * @endrst
 */
DTV_STATUS_T HAL_USB_SuperSpeedPortOff(UINT32 busNum, UINT32 portNum);
/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *   NA
 *
 * Responses to abnormal situations, including
 *   NA
 *
 * Performance Requirements
 *   NA
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   NA
 *
 * Return Value
 *   NA
 *
 * Example
 *   NA
 * @endrst
 */
#endif  /* _HAL_USB_H_ */
