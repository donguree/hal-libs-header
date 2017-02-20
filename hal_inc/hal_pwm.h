/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file hal_pwm.h
 *
 *	This header file defines the driver functions related to i2c Driver
 *
 *	@author 	dj911.kim (dj911.kim@lge.com)
 *	@version	0.9
 *	@date		2016.08.25
 *	@note		
 *	@see
 */

/******************************************************************************
 	Header File Guarder
******************************************************************************/
#ifndef _HAL_PWM_H_
#define _HAL_PWM_H_

/******************************************************************************
	#include 파일들 (File Inclusions)
******************************************************************************/
//#include <osa_api.h>
//#include <osa_kadp.h>
#include <hal_common.h>

/******************************************************************************
 	상수 정의(Constant Definitions)
******************************************************************************/


/******************************************************************************
    매크로 함수 정의 (Macro Definitions)
******************************************************************************/


/******************************************************************************
	형 정의 (Type Definitions)
******************************************************************************/

/**
* type definition about PWM device's index
*
*/
typedef enum {
	PWM_DEV_PIN0	= 0,	/**< PWM# 0 */
	PWM_DEV_PIN1,			/**< PWM# 1 */
	PWM_DEV_PIN2,			/**< PWM# 2 */
	PWM_DEV_PIN3,			/**< PWM# 3 */
	PWM_DEV_PIN4,			/**< PWM# 4 */
	PWM_DEV_MAX,			/**< PWM# MAX */
	PWM_DEV_NONE	= 0xFF,	/**< PWM# Not used */
} PWM_PIN_SEL_T;

/**
* type definition about PWM device's index mask
*
*/
typedef enum {
	PWM_DEV_PIN_0_MASK		= 1 << PWM_DEV_PIN0,	/**< PWM# 0 */
	PWM_DEV_PIN_1_MASK		= 1 << PWM_DEV_PIN1,	/**< PWM# 1 */
	PWM_DEV_PIN_2_MASK		= 1 << PWM_DEV_PIN2,	/**< PWM# 2 */
	PWM_DEV_PIN_3_MASK		= 1 << PWM_DEV_PIN3,	/**< PWM# 3 */
	PWM_DEV_PIN_4_MASK		= 1 << PWM_DEV_PIN4,	/**< PWM# 4 */

	PWM_DEV_PIN_0_1_MASK	= PWM_DEV_PIN_0_MASK|PWM_DEV_PIN_1_MASK,	/**< PWM# 0/1 */
	PWM_DEV_PIN_0_2_MASK	= PWM_DEV_PIN_0_MASK|PWM_DEV_PIN_2_MASK,	/**< PWM# 0/2 */
	PWM_DEV_PIN_1_2_MASK	= PWM_DEV_PIN_1_MASK|PWM_DEV_PIN_2_MASK,	/**< PWM# 1/2 */

	/* If necessary, add case */

	PWM_DEV_PIN_ALL_MASK	=  PWM_DEV_PIN_0_MASK|PWM_DEV_PIN_1_MASK|PWM_DEV_PIN_2_MASK \
									|PWM_DEV_PIN_3_MASK|PWM_DEV_PIN_4_MASK,	/**< PWM# 0/1/2/3/4 */

	PWM_DEV_PIN_DEFAULT_MASK		/**< depended on pwmIndex setting of HAL_PWM_SetParam function */
} PWM_PIN_SEL_MASK_T;

/**
 * PWM Output Frequency
 */
typedef struct {
	UINT32			pwmfreq_48nHz;		// PWM frequency 48xN Hz from DB table
	UINT32			pwmfreq_50nHz;		// PWM frequency 50xN Hz from DB table
	UINT32			pwmfreq_60nHz;		// PWM frequency 60xN Hz from DB table
} PWM_FREQ_DB_T;

/**
 * PWM Frequency Parameter
 */
typedef struct {
	UINT32			pwm_adapt_freq_enable;
	UINT32			pwmfreq_48nHz;		// PWM frequency 48xN Hz from DB table
	UINT32			pwmfreq_50nHz;		// PWM frequency 50xN Hz from DB table
	UINT32			pwmfreq_60nHz;		// PWM frequency 60xN Hz from DB table
//	PWM_FREQ_DB_T	pwm_adpat_freq_db;
} PWM_ADAPT_FREQ_PARAM_T;

/**
 * PWM Scanning Parameter
 */
typedef struct {
	UINT32	pwm_scanning_enable;
	UINT32	pwm_pos_start;
} PWM_SCANNING_PARAM_T;

/**
 * PWM Setting Parameter
 */
typedef struct {
	UINT32					pwm_enable;
	UINT32					pwm_duty;
	UINT32					pwm_frequency; // If pwm_adapt_freq_enable == TRUE, ignored
	PWM_ADAPT_FREQ_PARAM_T	pwm_adapt_freq_param;
	UINT32					pwm_lock;
	UINT32					pwm_pos_start;
	UINT32					pwm_scanning_enable;
	UINT32					pwm_low_power_enable;
} PWM_PARAM_T;

/******************************************************************************
	함수 선언 (Function Declaration)
******************************************************************************/

extern DTV_STATUS_T HAL_PWM_Init (void);
extern DTV_STATUS_T HAL_PWM_SetAdaptFreqCtrl (PWM_PIN_SEL_T pwmIndex, BOOLEAN onOff, PWM_FREQ_DB_T pwmFreqDb);
extern DTV_STATUS_T HAL_PWM_SetFrequency(PWM_PIN_SEL_T pwmIndex, UINT32 data);
extern DTV_STATUS_T HAL_PWM_SetDutyCycle (PWM_PIN_SEL_T pwmIndex, UINT32 data);
extern DTV_STATUS_T HAL_PWM_SetEnable (PWM_PIN_SEL_T pwmIndex, BOOLEAN data);
extern DTV_STATUS_T HAL_PWM_SetPulseWidth (PWM_PIN_SEL_T pwmIndex, UINT32 data);
extern DTV_STATUS_T HAL_PWM_SetVsyncAlign(PWM_PIN_SEL_T pwmIndex, BOOLEAN data);

// NC5 new interface
extern DTV_STATUS_T HAL_PWM_SetParam(PWM_PIN_SEL_T pwmIndex, PWM_PARAM_T* pstPWMParam);
extern DTV_STATUS_T HAL_PWM_GetParam(PWM_PIN_SEL_T pwmIndex, PWM_PARAM_T* pstPWMParam);
extern DTV_STATUS_T HAL_PWM_ApplyParamSet(PWM_PIN_SEL_MASK_T pwmIndex_mask);

#endif /* _HAL_PWM_H_ */
