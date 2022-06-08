/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/


/** @file hal_mmc.h
 *
 *  EMMC related header file
 *
 *  @author	Kwangseok Kim (kwangseok.kim@lge.com)
 *  @version	1.0
 *  @date		2012.10.15
 *  @note
 *  @see		hal_mmc.c
 */

/******************************************************************************
 	Header File Guarder
******************************************************************************/
#ifndef _hal_mmc_h_
#define _hal_mmc_h_

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

typedef enum {
	REGISTER_ECSD = 0,
	REGISTER_CSD = 1,
	REGISTER_CID = 2,
}MMC_REGISTER_TYPE_T;


/******************************************************************************
        Function Declaration
******************************************************************************/
/**
 * @brief Open MMC device
 *
 * @rst
 * Functional Requirements
 *   There are no functional requirements.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *    DTV_STATUS HAL_MMC_Open(void);
 *
 * Return Value
 *   Success: 0
 *   Fail: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ret = HAL_MMC_Open();
 *
 * @endrst
 */
DTV_STATUS_T HAL_MMC_Open(void);

/**
 * @brief Close MMC device
 *
 * @rst
 * Functional Requirements
 *   There are no functional requirements
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *    DTV_STATUS HAL_MMC_Close(void);
 *
 * Return Value
 *   Success: 0
 *   Fail: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ret = HAL_MMC_Close();
 *
 * @endrst
 */
DTV_STATUS_T HAL_MMC_Close(void);

/**
 * @brief Set PON(Power Off Notification) with short time
 *
 * @rst
 * Functional Requirements
 *   There are no functional requirements
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *  .. code-block:: cpp
 *
 *    DTV_STATUS HAL_MMC_PON_Short();
 *
 * Return Value
 *   Success: 0
 *   Fail: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ret = HAL_MMC_PON_Short();
 *
 * @endrst
 */
DTV_STATUS_T HAL_MMC_PON_Short(void);

/**
 * @brief Set PON(Power Off Notification) with long time
 *
 * @rst
 * Functional Requirements
 *   There are no functional requirements
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *    DTV_STATUS HAL_MMC_PON_Long();
 *
 * Return Value
 *   Success: 0
 *   Fail: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ret = HAL_MMC_PON_Long();
 *
 * @endrst
 */
DTV_STATUS_T HAL_MMC_PON_Long(void);

/**
 * @brief Get MMC CID(Card IDentification)
 *
 * @rst
 * Functional Requirements
 *   There are no functional requirements
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *    DTV_STATUS HAL_MMC_Get_CID(unsigned char *buff);
 *
 * Return Value
 *   Success: 0
 *   Fail: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     unsigned char* buff;
 *     ret =  HAL_MMC_Get_CID(buff);
 *
 * @endrst
 */
DTV_STATUS_T HAL_MMC_Get_CID(unsigned char *buff);

/**
 * @brief Get MMC usage information. (SMART : Self Monitoring, Analysis and Reporting Technology)
 *
 * @rst
 * Functional Requirements
 *   There are no functional requirements
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *    DTV_STATUS HAL_MMC_Get_SMART_Report(unsigned char *buff, unsigned int *len);
 *
 * Return Value
 *   Success: 0
 *   Fail: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     unsigned char* buff;
 *     unsigned int *len;
 *     ret =  HA HAL_MMC_Get_SMART_Report(buff, len);
 *
 * @endrst
 */
DTV_STATUS_T HAL_MMC_Get_SMART_Report(unsigned char *buff, unsigned int *len);

/**
 * @brief Get MMC register's information.
 *
 * @rst
 * Functional Requirements
 *   There are no functional requirements
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *    DTV_STATUS HAL_MMC_Get_Register(MMC_REGISTER_TYPE_T mmcRegisterType, unsigned char *buff);
 *
 * Return Value
 *   Success: 0
 *   Fail: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     unsigned char* buff;
 *     MMC_REGISTER_TYPE_T mmcRegisterType;
 *     ret =  HAL_MMC_Get_Register(mmcRegisterType, buff);
 *
 * @endrst
 */
DTV_STATUS_T HAL_MMC_Get_Register(MMC_REGISTER_TYPE_T mmcRegisterType, unsigned char *buff);
#endif  /* _hal_mmc.h_ */

