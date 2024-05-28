/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2008-2023 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.

 *****************************************************************************/

/** @file hal_sys.h
  *
  *  System related header file
  *
  *  @author		kwangseok.kim (kwangseok.kim@lge.com)
  *  @version		 1.0
  *  @date		2017.02.23
  *  @note
  *  @see		hal_sys.c
*/

/******************************************************************************
        Header File Guarder
******************************************************************************/
#ifndef _HAL_SYS_H_
#define _HAL_SYS_H_

/******************************************************************************
        File Inclusions
******************************************************************************/
#include "hal_common.h"

/******************************************************************************
        Constant Definitions
******************************************************************************/
#define HAL_SYS_VERSION  1

#define PWM_TYPE_NONE    0x0
#define PWM_TYPE_FAN     0x1
#define MAX_PWM_NUM      8

/******************************************************************************
        Macro Definitions
******************************************************************************/

/******************************************************************************
        Type Definitions
******************************************************************************/
typedef struct
{
	unsigned int pwm_type;
	unsigned int period_ns; /* resolution=25Khz --> period=40,000ns */
}HAL_SYS_PWM_CAPABILITY_INFO_T;

/******************************************************************************
        Enum Definitions
******************************************************************************/
typedef enum
{
	SUSPEND_MODE_SNAPSHOT		= 0,	// SNAPSHOT mode
	SUSPEND_MODE_HIBERNATION	= 1,	// HIBERNATION/IBOOT mode
} SUSPEND_MODE_T;

typedef enum
{
	DFT_MEM_TEST_RESULT_OK = 0,
	DFT_MEM_TEST_RESULT_NG = 1,
	DFT_MEM_TEST_RESULT_BUSY = 2,
}DFT_MEM_TEST_RESULT_T;

/******************************************************************************
        Function Declaration
******************************************************************************/
/* Enable/Disable debug port(T32, register tool, debug tool)
 * requester: khkh.lee jongyeon.yoon denis.hong
 */
 /**
 * @brief Lock debug port(T32, register tool, debug tool)
 *
 * @rst
 * Functional Requirements
 *   There are no functional requirements
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   The Lock works when debugstatus is Release Mode.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *    DTV_STATUS HAL_SYS_LockDebugPort(BOOLEAN bLock);
 *
 * Return Value
 *   Success: 0
 *   Fail: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret;
 *     ret = HAL_SYS_LockDebugPort(1);
 *
 * @endrst
 */
DTV_STATUS_T HAL_SYS_LockDebugPort(BOOLEAN bLock);

/* WOL
 * requester: jaesung5.lee
 */
DTV_STATUS_T HAL_SYS_SetWolOnOff(BOOLEAN bOnOff);
DTV_STATUS_T HAL_SYS_GetWolStatus(BOOLEAN *Status);

/* SUSPEND/RESUME, SIC chip only used
 * requester: juno.choi(request for instant boot)
 */
 /**
 * @brief responsible for putting the system into a low-power state.
 *
 * @rst
 * Functional Requirements
 *   There are no functional requirements
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1 ie NOT_OK.
 *
 * Performance Requirements
 *   The response time of this function should be within 50ms.
 *
 * Constraints
 *   There is no constraits
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T HAL_SYS_Suspend(SUSPEND_MODE_T syspendMode);
 *
 * Return Value
 *   Success:  0
 *   Fail   : -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret;
 *     ret = HAL_SYS_Suspend(SUSPEND_MODE_T syspendMode);
 *
 * @endrst
 */
 DTV_STATUS_T HAL_SYS_Suspend(SUSPEND_MODE_T syspendMode);

/* notify driver to enter into suspend mode
 * requester: juno.choi
 */
 /**
 * @brief responsible for reinitialize and restore the system to its operational state.
 *
 * @rst
 * Functional Requirements
 *   There are no functional requirements
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1 ie NOT_OK.
 *
 * Performance Requirements
 *   The response time of this function should be within 50ms.
 *
 * Constraints
 *   There is no constraits
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T HAL_SYS_Resume (void);
 *
 * Return Value
 *   Success:  0
 *   Fail   : -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret;
 *     ret = HAL_SYS_Resume(void);
 *
 * @endrst
 */
 DTV_STATUS_T HAL_SYS_Resume (void);

/* WAKE Up Internal Micom, RTK chip only used
 * requester: kwangseok.kim
 */
DTV_STATUS_T HAL_SYS_WakeUpInternalMicom(void);

/* Read/Write for boot area, MStar chip only used
 * requester: khkh.lee
 */
DTV_STATUS_T HAL_SYS_ReadBootData(unsigned char *pBootData, unsigned int bootDataSize);
DTV_STATUS_T HAL_SYS_WriteBootData(unsigned char *pBootDataPath, unsigned int bootDataSize);

/* Internal Micom, Mstar chip only used
 * requester: sungbae.park
 */
DTV_STATUS_T HAL_SYS_ReadPMData(unsigned char *pPMDataPath, unsigned int PMDataSize);
DTV_STATUS_T HAL_SYS_WritePMData(unsigned char *pPMDataPath, unsigned int PMDataSize);

/* temporary use, Internal Micom, Realtek chip only used
 * requester: sungbae.park
 */
DTV_STATUS_T HAL_IPC_Write(UINT8 nCmdMode, UINT8 *pCmd, UINT8 nBytes, UINT8 *pBuf, UINT8 retry);
DTV_STATUS_T HAL_IPC_Read(UINT8 nCmdMode, UINT8 *pCmd, UINT8 nBytes, UINT8 *pBuf, UINT8 retry);

/* Check RPMB Partition
 * requester: hedaesik.kim
 */
DTV_STATUS_T HAL_SYS_CheckRPMBPartition(void);

/* Check model id is stored in RPMB
 * requester: hedaesik.kim
 */
 /**
 * @brief check model id status in RPMB
 *
 * @rst
 * Functional Requirements
 *   Return ok when model id is stored in RPMB
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   The response time of this function should be within 50ms.
 *
 * Constraints
 *   There is no constraits
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *    DTV_STATUS HAL_SYS_CheckModelIdStatus(void);
 *
 * Return Value
 *   Model id is stored in RPMB : 0
 *   Model id is not stored in RPMB: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret;
 *     ret = HAL_SYS_CheckModelIdStatus();
 *
 * @endrst
 */
DTV_STATUS_T HAL_SYS_CheckModelIdStatus(void);

/*
 * DDR memory test in DFT process
 * requester: kwangseok.kim
 */
/**
 * @brief DDR memory test in DFT process
 *
 * @rst
 * Functional Requirements
 *   There are no functional requirements
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   The response time of this function should be within 100ms.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *    DTV_STATUS HAL_SYS_StartDFTMemTest(void);
 *
 * Return Value
 *   Success: 0
 *   Fail: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret;
 *     ret = HAL_SYS_StartDFTMemTest();
 *
 * @endrst
 */
DTV_STATUS_T HAL_SYS_StartDFTMemTest(void);

/**
 * @brief Get DDR memory test results in DFT process
 *
 * @rst
 * Functional Requirements
 *   There are no functional requirements
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   For a maximum of 200 calls,the response time of this function should be within 6000ms.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *    DTV_STATUS HAL_SYS_GetDFTMemTestResult(void);
 *
 * Return Value
 *   Success: 0
 *   Fail: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DFT_MEM_TEST_RESULT_T ret;
 *     ret = HAL_SYS_GetDFTMemTestResult();
 *
 * @endrst
 */
DFT_MEM_TEST_RESULT_T HAL_SYS_GetDFTMemTestResult(void);

/*
 * PWM
 * requester: kwangseok.kim
 */
/**
 * @brief Get PWM capability from Fan controller,
 *        The o22 machine of webOS22 only supports this functions.
 *
 * @rst
 * Functional Requirements
 *   There are no functional requirements
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   The response time of this function should be within 20ms.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *    DTV_STATUS  HAL_SYS_GetPWMCapability(unsigned int *pNum_of_pwm, HAL_SYS_PWM_CAPABILITY_INFO_T *pstPWMCapability);
 *
 * Return Value
 *   Success: 0
 *   Fail: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T retVal = DILE_OK;
 *     unsigned int *pNum_of_pwm
 *     HAL_SYS_PWM_CAPABILITY_INFO_T stHalPWMCapability[MAX_PWM_NUM];
 *     retVal = retVal = HAL_SYS_GetPWMCapability(pNum_of_pwm, stHalPWMCapability);
 *
 * @endrst
 */
DTV_STATUS_T HAL_SYS_GetPWMCapability(unsigned int *pNum_of_pwm, HAL_SYS_PWM_CAPABILITY_INFO_T *pstPWMCapability);

/**
 * @brief Set PWM for Fan controller,
 *        The o22 machine of webOS22 only supports this functions.
 *
 * @rst
 * Functional Requirements
 *   There are no functional requirements
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *    DTV_STATUS  HAL_SYS_SetPWM(unsigned int pwm_id, unsigned int period_ns, unsigned int duty_ns);
 *
 * Return Value
 *   Success: 0
 *   Fail: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T retVal = DILE_OK;
 *     unsigned int pwm_id;
 *     unsigned int period_ns;
 *     unsigned int duty_ns;
 *     retVal = HAL_SYS_SetPWM(pwm_id, period_ns, duty_ns);
 *
 * @endrst
 */
DTV_STATUS_T HAL_SYS_SetPWM(unsigned int pwm_id, unsigned int period_ns, unsigned int duty_ns);

/**
 * @brief Get PWM data from Fan controller,
 *        The o22 machine of webOS22 only supports this functions.
 *
 * @rst
 * Functional Requirements
 *   There are no functional requirements
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *    DTV_STATUS  HAL_SYS_GetPWMData(unsigned int pwm_id, void *pData);
 *
 * Return Value
 *   Success: 0
 *   Fail: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T retVal = DILE_OK;
 *     unsigned int pwm_id;
 *     void *pData;
 *     retVal = HAL_SYS_GetPWMData(pwm_id, pData);
 *
 * @endrst
 */
DTV_STATUS_T HAL_SYS_GetPWMData(unsigned int pwm_id, void *pData);

#endif  /* _HAL_SYS_H_ */
