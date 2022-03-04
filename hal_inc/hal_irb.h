/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2019 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/
/** @file hal_irb.h
 *
 *  This c file defines the HAL functions related to IR Blaster Driver.
 *
 *  @author     jeonghyeon.joo (jeonghyeon.joo@lge.com)
 *  @version    0.1
 *  @date       2019.07.22
 *  @note
 *  @see
 */

/*****************************************************************************
	Header File Guarder
*****************************************************************************/
#ifndef _HAL_IRB_H_
#define _HAL_IRB_H_

/******************************************************************************
        File Inclusions
******************************************************************************/
#include "hal_common.h"

/*****************************************************************************
	Constant Definitions
*****************************************************************************/

/******************************************************************************
        Type Definitions
******************************************************************************/
/**
 * type definition for uei waveform information
 *
 * numToggleIndex      It is for the Philips protocols and for configuring the toggle bit.
                       The value (1,2 or 4) is the number of waveform (Don't care in driver layer)
 * dutyCycle           duty cycle
 * carrierFrequency    carrier frequency
 * numCharTimes        The number of the characteristic time
 * characteristicTime  Time value to be composed of MAKE/REPEAT/BREAK signal
 * numMakeTimes        The number of the MAKE time
 * makeTimes           Index of the characteristic to construct the MAKE waveform
 * numRepeatTimes      The number of the REPEAT time
 * repeatTimes         Index of the characteristic to construct the REPEAT waveform
 * numBreakTimes       The number of the BREAK time
 * breakTimes          Index of the characteristic to construct the BREAK waveform
 */
typedef struct uei_irb_waveform_s {
    int numToggleIndex;
    int dutyCycle;
    int carrierFrequency;
    int numCharTimes;
    int *characteristicTime;
    int numMakeTimes;
    int *makeTimes;
    int numRepeatTimes;
    int *repeatTimes;
    int numBreakTimes;
    int *breakTimes;
} uei_irb_waveform_t;

/******************************************************************************
        Function Declaration
******************************************************************************/
/*
 * Generate IR waveform with UEI timing information
 *
 * param    waveform [IN]  timing information to generate IR waveform
 * return   If the function succeeds, the return value is OK.
            Else, thereturn value is one of error in DTV_STATUS_T
 */
DTV_STATUS_T HAL_IRB_GenerateUEIWaveform(uei_irb_waveform_t *waveform);

#endif	/* _HAL_IRB_H_ */