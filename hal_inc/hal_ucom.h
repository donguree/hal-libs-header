/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/


/** @file ucom_ddi.h
*
*	Internal Micom Interface header file( ONLY for MSTAR(SATURN)platform).
*
*	@author Dong-Jun Lee(athens@lge.com) 	- modifier
*	@author Kun-IL Lee(dreamer@lge.com) 	- modifier
*	@version	1.0
*	@date	  2006.07.08
*	@note
*/

/******************************************************************************
  Header File Guarder
******************************************************************************/
#ifndef _HAL_UCOM_H_
#define _HAL_UCOM_H_

/******************************************************************************
  File Inclusions
******************************************************************************/
#include "hal_common.h"

/******************************************************************************
  Constant Definitions
******************************************************************************/
#define MICOM_SIZE_OF_POWER_ERR_DATA			(15)
#define MICOM_ADDR_OF_POWER_ERR_DATA			(128)

#define MICOM_SIZE_OF_TOUCH_KEY_DATA			(60)
#define MICOM_ADDR_OF_TOUCH_KEY_DATA			(150)

#ifndef CEC_CONTROLLED_BY_CPU
#define CEC_CONTROLLED_BY_CPU
#endif

/******************************************************************************
  Macro Definitions
******************************************************************************/

/******************************************************************************
  Type Definitions
******************************************************************************/
typedef UINT32 (* UCOM_KEY_CALLBACK_T) (UINT8 value, UINT8 repeat );
typedef UINT32 (* UCOM_TV_LINK_CALLBACK_PTR_T) (UINT8* pData );

/******************************************************************************
  Function Declaration
******************************************************************************/
/**
* @brief Initialize IR / Local Key process in this function.
*
* @rst
* Functional Requirements
*    1. Initialize ipc communication
*    2. Initialize Remocon/Local Key process
*
* Responses to abnormal situations, including
*    If ipc error is occured, return NOT_OK.
*
* Performance Requirements
*    There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*    There is no constraints.
*
* Functions & Parameters
*    * DTV_STATUS_T HAL_UCOM_Initialize(UCOM_KEY_CALLBACK_T pIRCallback, UCOM_KEY_CALLBACK_T pLKCallback)
*
*    For the data type, following data types are defined
*
*    * pIRCallback           [IN] Remocon Callback data
*    * pLKCallback           [IN] Local Key Callback data
*
* Return Value
*    OK if the function success, NOT_OK otherwise.
*
* Example
*   .. code-block:: cpp
*
*     unsigned int MICOM_CallbackIR(unsigned char key, unsigned char isRepeated)
*     {
*       unsigned int eventValue = MICOM_OK;
*       return eventValue;
*     }
*
*     unsigned int MICOM_CallbackLOCAL(unsigned char key, unsigned char isRepeated)
*     {
*       unsigned int eventValue = MICOM_OK;
*       return eventValue;
*     }
*
*     DTV_STATUS_T ret;
*     ret = HAL_UCOM_Initialize(MICOM_CallbackIR, MICOM_CallbackLOCAL);
* @endrst
*/
extern DTV_STATUS_T	HAL_UCOM_Initialize( UCOM_KEY_CALLBACK_T pIRCallback, UCOM_KEY_CALLBACK_T pLKCallback);

/**
* @brief Read Command between MainSOC and Micom FW.
*
* @rst
* Functional Requirements
*    1. Read command operation through IPC communication
*
* Responses to abnormal situations, including
*    If ipc error is occured, return NOT_OK.
*
* Performance Requirements
*    There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*    There is no constraints.
*
* Functions & Parameters
*    * DTV_STATUS_T HAL_UCOM_ReadCommand(UINT8 cmd, UINT16 dataSize, UINT8 *pData)
*
*    For the data type, following data types are defined
*
*    * cmd              [IN] read command
*    * dataSize         [IN] read data size
*    * *pData           [IN/OUT] read data from micom FW
*
* Return Value
*    OK if the function success, NOT_OK otherwise.
*
* Example
*    .. code-block:: cpp
*
*      DTV_STATUS_T ret;
*      UINT8 cmd = 0x01;
*      UINT16 dataSize = 1;
*      UINT8 pData;
*      ret = HAL_UCOM_ReadCommand(cmd, dataSize, &pData);
* @endrst
*/
extern DTV_STATUS_T	HAL_UCOM_ReadCommand(  UINT8 cmd,   UINT16 dataSize, UINT8 *pData );

/**
* @brief Write Command between MainSOC and Micom FW.
*
* @rst
* Functional Requirements
*    1. Write command operation through IPC communication
*
* Responses to abnormal situations, including
*    If ipc error is occured, return NOT_OK.
*
* Performance Requirements
*    There is no clear requirement for response time, but a response must be received within at least 100 ms.
*
* Constraints
*    There is no constraints.
*
* Functions & Parameters
*    * DTV_STATUS_T HAL_UCOM_WriteCommand(UINT8 *pCmd, UINT16 size)
*
*    For the data type, following data types are defined
*
*    * *pCmd        [IN] write command structure(command and send data value)
*    * size         [IN] write data size
*
* Return Value
*    OK if the function success, NOT_OK otherwise.
*
* Example
*    .. code-block:: cpp
*
*      DTV_STATUS_T ret;
*      UINT8 pCmd[3] = {0x01,0x02,0x03};	// 0x01 : command , {0x02, 0x03} : send data value
*      UINT16 size = 3;	// command total size
*      ret = HAL_UCOM_WriteCommand(pCmd, size);
* @endrst
*/
extern DTV_STATUS_T	HAL_UCOM_WriteCommand( UINT8 *pCmd, UINT16 size );

#ifdef	CEC_CONTROLLED_BY_CPU
/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
extern	DTV_STATUS_T	HAL_UCOM_ReadCECCommand(UINT8 *pData );

/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
extern	DTV_STATUS_T	HAL_UCOM_ReadCECResult(UINT8 *pData);

/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
extern	DTV_STATUS_T	HAL_UCOM_WriteCECCommand( UINT8 *pCmd);

/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
extern	void        	HAL_UCOM_InitCECModule(void);

/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
extern	UINT16       	HAL_UCOM_ReadCECResponse(void);
#endif

/*	Get KEY(IR & LOCAL) EVENT */
/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
DTV_STATUS_T	HAL_UCOM_GetKeyEvent( UINT32* pEvent, UINT32 timeout );

/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
DTV_STATUS_T	HAL_UCOM_GetIrEvent( UINT32* pEvent, UINT32 timeout );

/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
DTV_STATUS_T	HAL_UCOM_GetLocalKeyEvent( UINT32* pEvent, UINT32 timeout );

/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
DTV_STATUS_T	HAL_UCOM_WakeUpKeyEvent( void );

/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
void HAL_UCOM_SetTouchScanMode( UINT8 bonoff);

/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
void HAL_UCOM_GetTouchScanData( UINT16 *u16ScanData);

/*	TV LINK MODE */
/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
DTV_STATUS_T	HAL_UCOM_EnableTVLinkMode( BOOLEAN bEnabled, UCOM_TV_LINK_CALLBACK_PTR_T pTVLinkCallback );

/*	WB CODE MODE */
/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
DTV_STATUS_T	HAL_UCOM_EnableWBCodeMode( BOOLEAN bEnabled, UCOM_TV_LINK_CALLBACK_PTR_T pWBCodeCallback );

/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
DTV_STATUS_T	HAL_UCOM_GetADC_Value( UINT8 channel,UINT8 *pAdcData );

/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
void HAL_UCOM_PMStop(void);

/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
void HAL_UCOM_PMResume(void);

/**
 * @brief Deprecated. Need to delete this function.
 *
 * @rst
 * Functional Requirements
 *    NA
 *
 * Responses to abnormal situations, including
 *    NA
 *
 * Performance Requirements
 *    NA
 *
 * Constraints
 *    NA
 *
 * Functions & Parameters
 *    NA
 *
 * Return Value
 *    NA
 *
 * Example
 *    NA
 * @endrst
 */
void HAL_UCOM_PMReset(void);

/**
 * @brief Whole Chip Reset Function(Main SoC & Micom FW)
 *
 * @rst
 * Functional Requirements
 *    1. Whole Chip Reset both Main SoC and Micom FW.
 *
 * Responses to abnormal situations, including
 *    If ipc error is occured, return NOT_OK.
 *
 * Performance Requirements
 *    There is no clear requirement for response time, but a response must be received within at least 100 ms.
 *
 * Constraints
 *    There is no constraints.
 *
 * Functions & Parameters
 *    * void HAL_UCOM_WholeChipReset(void)
 *
 * Return Value
 *    NA
 *
 * Example
 *    .. code-block:: cpp
 *
 *      HAL_UCOM_WholeChipReset();
 * @endrst
 */
void HAL_UCOM_WholeChipReset(void);

#endif /* #ifndef _HAL_UCOM_H_ */
