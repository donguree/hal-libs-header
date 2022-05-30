/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/*!@defgroup venc Video Encoder HAL APIs
 *
 * @{
 */

/** @file hal_venc.h
 *
 *  Video Encoder HAL function header file.
 *	HAL VENC API Functions(video encoder, recoding and codec encoding)
 *
 *	@author		YoungKi Son (yk.son@lge.com)
 *  @version	1.1
 *  @date		2013.03.13 Jaeseop So (jaeseop.so@lge.com)
 *  @date		2017.03.03
 *  @see
 */

#ifndef _HAL_VENC_H_
#define _HAL_VENC_H_

/******************************************************************************
 #include files (File Inclusions)
******************************************************************************/

//#include <osa_api.h>
#ifndef WIN32_SIM // Modified by dilly97: fix include
#include "hal_common.h"
#else
#include "common_win32.h"
#endif


/**
 * @brief infomation of recored frame
 */
typedef struct VENC_MSG_TYPE
{
	UINT32	channel;	/**< Port Id */
	UINT8	pictype;	/**< Picture Type IDC:1 I:2 P:4 B:8 */
	UINT64	pts;		/**< PTS */
	UINT8	*pData;		/**< pointer to Video Data */
	UINT32	dataLen;	/**< Video Data Length */
	UINT8	*pRStart;	/**< start pointer of buffer */
	UINT8	*pREnd;		/**< end pointer of buffer */
	UINT8	*pDataPhysical;
}VENC_MSG_TYPE_T;

/**
 * @brief recoding data callback function Type
 */
typedef DTV_STATUS_T (*pfnVENCDataHandlingCB)(VENC_MSG_TYPE_T *pMsg);

/**
 * @brief recoding input source types
 */
typedef enum
{
	VENC_INPUT_MAIN = 0,/**< Main Video source */
	VENC_INPUT_SUB,		/**< Sub Video source */
	VENC_INPUT_EXT,		/**< Extra Video source */
	VENC_INPUT_NUM
}VENC_INPUT_TYPE_T;

/**
 * @brief venc codec formats
 */
typedef enum
{
	VENC_CODEC_H264 = 0,/**< H264 format */
	VENC_CODEC_VP8		/**< VP8 format */
}VENC_CODEC_T;

/**
 * @brief recoding frame rate
 */
typedef enum
{
	VENC_FRAMERATE_AUTO = 0,	// Optimal frame rate for this Encoder. (60p -> 30p, 50p -> 25p...)
	VENC_FRAMERATE_ASIS,	// Use original framerate
	VENC_FRAMERATE_60P,	//60Hz progressive (reserved not used)
	VENC_FRAMERATE_60I,	//60Hz interlaced (reserved not used)
	VENC_FRAMERATE_50P,	//50Hz progressive (reserved not used)
	VENC_FRAMERATE_50I,	//50Hz interlaced (reserved not used)
	VENC_FRAMERATE_30P,	//30Hz progressive
	VENC_FRAMERATE_30I,	//30Hz interlaced (reserved not used)
	VENC_FRAMERATE_25P,	//25Hz progressive (reserved not used)
	VENC_FRAMERATE_25I,	//25Hz interlaced (reserved not used)
	VENC_FRAMERATE_24P,	//24Hz progressive (reserved not used)
	VENC_FRAMERATE_24I,	//24Hz interlaced (reserved not used)
	VENC_FRAMERATE_INVALID
}VENC_FRAMERATE_T;

/**
 * @brief venc profiles
 */
typedef enum
{
	VENC_PROFILE_BASE = 0,
	VENC_PROFILE_MAIN,
	VENC_PROFILE_EXT,
	VENC_PROFILE_HIGH
}VENC_PROFILE_T;

/**
 * @brief profile levels
 */
typedef enum
{
	VENC_PROFILELEVEL_30 = 0,
	VENC_PROFILELEVEL_31,
	VENC_PROFILELEVEL_40,
	VENC_PROFILELEVEL_41
}VENC_PROFILELEVEL_T;

/**
 * @brief Rate conotrol mode
 */
typedef enum {
	VENC_RATECONTROL_VBR = 0,	/**< Variable Bit Rate (VBR) mode */
	VENC_RATECONTROL_CBR = 1,	/**< Constant Bit Rate (CBR) mode */
} VENC_RATECONTROL_T;

/**
 * @brief venc recoding parameter types
 */
typedef enum {
	VENC_INFO_FRAMERATE = 0,
	VENC_INFO_WIDTH,
	VENC_INFO_HEIGHT,
	VENC_INFO_ASPECTRATIOIDC,
	VENC_INFO_SARWIDTH,
	VENC_INFO_SARHEIGHT,
	VENC_INFO_INPUT,
	VENC_INFO_BITRATE,
	VENC_INFO_PROFILE,
	VENC_INFO_PROFILELEVEL,
	VENC_INFO_CODEC,
	VENC_INFO_RATECONTROL,
	VENC_INFO_GOPLENGTH,
	VENC_INFO_QP,
	VENC_INFO_SOURCE,
	VENC_INFO_SECURE,
	VENC_INFO_NUM
}VENC_INFO_T;


typedef enum {
    VENC_SOURCE_ATV = 0,
    VENC_SOURCE_AV,
    VENC_SOURCE_SCARTIN,
    VENC_SOURCE_NUM
} VENC_SOURCE_T;


/**
 * @brief VENC Open for recoding
 *
 * @rst
 * Description
 *   Initializes and open VENC driver. Perform basic setting work to operate VENC.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_Open(void)
 *
 * Parameters
 *   None
 *
 * Return Value
 *
 *   - If the function succeeds, the return value is OK.
 *   - If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   Since this function is called every time recording is done, make sure that the resource allocation code that can affect the performance inside this function is not repeatedly called.
 *   In other words, memory / semaphore allocation is designed to be performed only once through the first use check.
 *   The above function mainly contains memory / parameter / status reset.
 *
 * Pseudo Code
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_Open(void)
 *     {
 *          IF(this call is firstcall from boot)
 *              CREATE semaphore
 *              CREATE resources(message queue, task …) if necessary
 *          END IF
 *
 *          SET VENC status global variable to initial value
 *
 *          IF any error THEN
 *              RETURN NOT_OK
 *          ELSE
 *              RETURN OK
 *          END IF
 *     }
 *
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *     DTV_STATUS_T RetVal;
 *
 *     RetVal = HAL_VENC_Open();
 *     if(RetVal!= OK )
 *     {
 *         PRINTF("Error HAL_VENC_Open\n");
 *         return RetVal;
 *     }
 *
 * See Also
 *   - HAL_VENC_Close
 *   - HAL_VENC_OpenEx
 * @endrst
 */
DTV_STATUS_T	HAL_VENC_Open(void);


/**
 * @brief VENC Finalizing after recoding
 *
 * @rst
 * Description
 *   Close VENC driver.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_Close();
 *
 * Parameters
 *   None
 *
 * Return Value
 *
 *   - If the function succeeds, the return value is OK.
 *   - If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   Since it is always called when recording is finished, codes such as memory release and semaphore deletion are not used like HAL_VENC_Open.
 *   The general call sequence is as follows:
 *
 *     - HAL_VENC_Open()
 *     - HAL_VENC_Connect()
 *     - HAL_VENC_SetParam()'s
 *     - HAL_VENC_Start()
 *     - HAL_VENC_Stop()
 *     - HAL_VENC_Close()
 *
 *   If channel switching is repeated quickly in TimeShift ON state, HAL_VENC_Close may be called before HAL_VENC_Stop is called.
 *   In this case, HAL_VENC_Close should handle VENC stop first before closing the resource.
 *   When using a task for the encoding process, it is common to delete the task in HAL_VENC_Close(), but
 *   There may be memory leaks in task creation/deletion depending on the system, so if there is no problem in operation, it is recommended to use the task without deleting it.
 *
 * Pseudo Code
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_Close(void)
 *     {
 *         IF VENC is not stop
 *             STOP VENC.
 *         RESET memory that is used for VENC
 *         RESET parameters that is used for VENC
 *         IF any error THEN
 *             RETURN NOT_OK
 *         ELSE
 *             RETURN OK
 *         END IF
 *     }
 *
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *    DTV_STATUS_T RetVal;
 *    RetVal = HAL_VENC_Close();
 *    if(RetVal!= OK )
 *    {
 *        PRINTF("Error HAL_VENC_Close\n");
 *        return RetVal;
 *    }
 *
 * See Also
 *
 *   - HAL_VENC_Stop
 *   - HAL_VENC_Open
 *
 * @endrst
 */
DTV_STATUS_T	HAL_VENC_Close(void);




/**
 * @brief VENC Open for multi encoding
 *
 * @rst
 * Description
 *   This is for only LG SIC. For others implement it as empty.
 *   Initializes and open VENC driver. Perform basic setting work to operate VENC. Encoding port number can be set as parameter.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_OpenEx(void)
 *
 * Parameters
 *   None
 *
 * Return Value
 *
 *   - If the function succeeds, the return value is OK.
 *   - If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   Since this function is called every time recording is done, make sure that the resource allocation code that can affect the performance inside this function is not repeatedly called.
 *   In other words, memory / semaphore allocation is designed to be performed only once through the first use check.
 *   The above function mainly contains memory / parameter / status reset.
 *
 * Pseudo Code
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_OpenEx(UINT8 port)
 *     {
 *          IF(this call is firstcall from boot)
 *              CREATE semaphore
 *              CREATE resources(message queue, task …) if necessary
 *          END IF
 *
 *          SET VENC status global variable to initial value
 *
 *          IF any error THEN
 *              RETURN NOT_OK
 *          ELSE
 *              RETURN OK
 *          END IF
 *     }
 *
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *     DTV_STATUS_T RetVal;
 *
 *     RetVal = HAL_VENC_OpenEx(1);
 *     if(RetVal!= OK )
 *     {
 *         PRINTF("Error HAL_VENC_Open\n");
 *         return RetVal;
 *     }
 *
 * See Also
 *   HAL_VENC_Close
 * @endrst
 */
DTV_STATUS_T	HAL_VENC_OpenEx(UINT8 port);


/**
 * @brief VENC Finalizing for multi encoding
 *
 * @rst
 * Description
 *   Close VENC driver.
 *   This is for only LG SIC. For others implement it as empty.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_Close(UINT8 port);
 *
 * Parameters
 *   None
 *
 * Return Value
 *
 *   - If the function succeeds, the return value is OK.
 *   - If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   It is same to HAL_VENC_Close except port setting parameter
 *
 * Pseudo Code
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_Close(void)
 *     {
 *         IF VENC is not stop
 *             STOP VENC.
 *         RESET memory that is used for VENC
 *         RESET parameters that is used for VENC
 *         IF any error THEN
 *             RETURN NOT_OK
 *         ELSE
 *             RETURN OK
 *         END IF
 *     }
 *
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *    DTV_STATUS_T RetVal;
 *    RetVal = HAL_VENC_Close(1);
 *    if(RetVal!= OK )
 *    {
 *        PRINTF("Error HAL_VENC_Close\n");
 *        return RetVal;
 *    }
 *
 * See Also
 *   - HAL_VENC_OpenEx
 * @endrst
 */
DTV_STATUS_T	HAL_VENC_CloseEx(UINT8 port);


/**
 * @brief Select Video source
 *
 * @rst
 * Description
 *   Set VENC input video source.
 *   Depending on the SOC structure, the module that supplies Raw-Video-Data to VENC may be AVD (Analog-Video-Decoder, when using VENC's own dedicated buffer memory).
 *   It can also be VSC1 (when using Sub-Video-Scaler, Video-Path).
 *   According to the above structure, it is decided whether the module to be connected by VENC is AVD (Analog-Video-Decoder) or VSC1 (Sub-Video-Scaler).
 *   This function determines which module VENC will connect with.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_Connect(UINT8 port, VENC_INPUT_TYPE_T input)
 *
 * Parameters
 *
 *   - port             [IN]  VENC port
 *   - input            [IN]  VENC source index (See VENC_INPUT_TYPE_T)
 *
 * Return Value
 *
 *   - If the function succeeds, the return value is OK.
 *   - If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   The BSP-Resource connection structure according to the type of module connected by VENC and the value of the input parameter of this Hal function are as follows.
 *
 *   - When VENC is connected with AVD (input Enum value : DIL_VENC_INPUT_EXT , BSP-Resource : AVD -> VENC)
 *   - When VENC is connected to VSC1 (input Enum value : DIL_VENC_INPUT_SUB , BSP-Resource : AVD -> VSC1 -> VENC)
 *
 *   In case 1 above, that is, if the module that delivers Video raw data to VENC is not a scaler, if a separate connect operation is not required using the VENC dedicated scaler, HAL_VENC_Connect() operation can be ignored.
 *
 * Pseudo Code
 *   .. code-block::
 *
 *    DTV_STATUS_T HAL_VENC_Connect(UINT8 port, VENC_INPUT_TYPE_T input)
 *    {
 *        IF input >= VENC_INPUT_NUM THEN
 *            RETURN NOT_OK
 *        END iF
 *
 *        VENC_lock(wait_semaphore)
 *        Check validity of Video source
 *        Connect VENC to Video source of (input)
 *        VENC_unlock(post_semaphore)
 *
 *        IF any error THEN
 *            RETURN NOT_OK
 *        ELSE
 *            RETURN OK
 *        END IF
 *    }
 *
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *    DTV_STATUS_T RetVal;
 *    RetVal = HAL_VENC_Connect(0, VENC_INPUT_SUB);
 *    if(RetVal!= OK )
 *    {
 *        PRINTF("Error HAL_VENC_Connect\n");
 *        return RetVal;
 *    }
 *
 * See Also
 *   None
 * @endrst
 */
DTV_STATUS_T	HAL_VENC_Connect(UINT8 port, VENC_INPUT_TYPE_T input);


/**
 * @brief Start Video Encoding
 *
 * @rst
 * Description
 *   Starts VENC encoding.
 *   ES data is newly generated per every video-frame is input.
 *   New ES data is saved in ES-Buffer
 *   A Callback is generated from driver to Upper-SW-Layer
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_Start(UINT8 port)
 *
 * Parameters
 *
 *   - port             [IN]  VENC port
 *
 * Return Value
 *
 *   - If the function succeeds, the return value is OK.
 *   - If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   HAL_VENC_Open must be called before calling HAL_VENC_Start.
 *   If without calling HAL_VENC_Open (or after calling HAL_VENC_Close)
 *   If HAL_VENC_Start is called, an error is returned and encoding does not start.
 *   Just before calling HAL_VENC_Start, pre-environment settings related to recording are made through calling HAL_VEC_SetParam.
 *   Various environment setting values are reflected in actual operation by calling HAL_VENC_Start.
 *
 * Pseudo Code
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_Start(UINT8 port)
 *     {
 *         VENC_lock(wait_semaphore)
 *         Reset VENC resources
 *         Start VENC encoding
 *         VENC_unlock(post_semaphore)
 *         IF any error THEN
 *             RETURN NOT_OK
 *         ELSE
 *             RETURN OK
 *         END IF
 *     }
 *
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *    DTV_STATUS_T retVal;
 *
 *    retVal = HAL_VENC_Open();
 *    retVal = HAL_VENC_Connect(0, VENC_INPUT_SUB);
 *    retVal = HAL_VENC_SetParam(0, VENC_INFO_FRAMERATE, VENC_FRAMERATE_AUTO);
 *    retVal = HAL_VENC_SetParam(0, VENC_INFO_CODEC, VENC_CODEC_H264);
 *    retVal = HAL_VENC_SetParam(0, VENC_INFO_BITRATE, 4000); // 4M bps
 *    retVal = HAL_VENC_SetParam(0, VENC_INFO_PROFILE, VENC_PROFILE_MAIN);
 *    retVal = HAL_VENC_SetParam(0, VENC_INFO_PROFILELEVEL, VENC_PROFILELEVEL_31);
 *
 *    retVal = HAL_VENC_Start(0);
 *
 *    if(retVal != OK)
 *    {
 *        printf(“Error in HAL_VENC_Start()\n”);
 *    }
 *
 * See Also
 *   HAL_VENC_Stop
 * @endrst
 */
DTV_STATUS_T	HAL_VENC_Start(UINT8 port);


/**
 * @brief Stop Video Encoding
 *
 * @rst
 * Description
 *   Stops VENC encoding.
 *   ES data is not newly generated,
 *   New ES data is not saved in ES-Buffer
 *   No Callback is generated from driver to Upper-SW-Layer
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_Stop(UINT8 port)
 *
 * Parameters
 *
 *   - port             [IN]  VENC port
 *
 * Return Value
 *
 *   - If the function succeeds, the return value is OK.
 *   - If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   If the call of HAL_VENC_Stop is later than HAL_VENC_Close, HAL_VENC_Close performs the encoding stop operation.
 *   At this time, HAL_VENC_Stop returns an error because it is called after VENC is closed.
 *
 * Pseudo Code
 *   .. code-block::
 *
 *    DTV_STATUS_T HAL_VENC_Stop(UINT8 port)
 *    {
 *        VENC_lock(wait_semaphore)
 *        Stop VENC encoding
 *        Suspend VENC thread
 *        VENC_unlock(post_semaphore)
 *        IF any error THEN
 *            RETURN NOT_OK
 *        ELSE
 *            RETURN OK
 *        END IF
 *    }
 *
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *    DTV_STATUS_T retVal;
 *    retVal = HAL_VENC_Stop(0);
 *    retVal = HAL_VENC_Close();
 *
 *    if(retVal != OK)
 *    {
 *        printf(“Error in HAL_VENC_Stop()\n”);
 *    }
 *
 * See Also
 *   HAL_VENC_Start
 * @endrst
 */
DTV_STATUS_T	HAL_VENC_Stop(UINT8 port);


/**
 * @brief Set encoding parameter
 *
 * @rst
 * Description
 *   Set VENC encoding ES parameters.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_SetParam(UINT8 port, VENC_INFO_T info, SINT32 value)
 *
 * Parameters
 *
 *   - port         [IN] VENC port
 *   - info         [IN] Type of info to set (See VENC_INFO_T)
 *   - value        [IN] Value to set
 *
 * Return Value
 *
 *   - If the function succeeds, the return value is OK.
 *   - If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   This function sets VENC output parameters. With this function user can change following output parameters.
 *
 *   - VENC_INFO_FRAMERATE
 *   - VENC_INFO_WIDTH (only for LG SIC)
 *   - VENC_INFO_HEIGHT (only for LG SIC)
 *   - VENC_INFO_INPUT
 *   - VENC_INFO_BITRATE
 *   - VENC_INFO_PROFILE
 *   - VENC_INFO_PROFILELEVEL
 *   - VENC_INFO_CODEC
 *
 *   The HAL_VEN_SetParam function call is made immediately before the HAL_VENC_Start function call.
 *   The actual operation of the changed Param value is applied when the HAL_VENC_Start function is called.
 *
 * Pseudo Code
 *   .. code-block::
 *
 *    DTV_STATUS_T HAL_VENC_SetParam(UINT8 port, VENC_INFO_T info, SINT32 value)
 *    {
 *        IF info >= VENC_INFO_NUM THEN
 *            RETURN NOT_OK
 *        END iF
 *
 *        VENC_lock(wait_semaphore)
 *        IF info == VENC_INFO_FRAMERATE THEN
 *            SET value TO output_framerate
 *        ELSE IF info == VENC_INFO_CODEC THEN
 *            SET value TO encoding__codec
 *        ELSE IF info == VENC_INFO_BITRATE THEN
 *            SET value TO output_bitrate
 *        ELSE IF info == VENC_INFO_PROFILE THEN
 *            SET value TO output_profile
 *        ELSE IF info == VENC_INFO_PROFILELEVEL THEN
 *            SET value TO output_profilelevel
 *        ELSE
 *            ERROR
 *        END IF
 *
 *        VENC_unlock(post_semaphore)
 *
 *        IF any error THEN
 *            RETURN NOT_OK
 *        ELSE
 *            RETURN OK
 *        END IF
 *    }
 *
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *    DTV_STATUS_T retVal;
 *
 *    retVal = HAL_VENC_SetParam(0, VENC_INFO_FRAMERATE, VENC_FRAMERATE_AUTO);
 *    retVal = HAL_VENC_SetParam(0, VENC_INFO_CODEC, VENC_CODEC_H264);
 *    retVal = HAL_VENC_SetParam(0, VENC_INFO_BITRATE, 4000); // 4M bps
 *    retVal = HAL_VENC_SetParam(0, VENC_INFO_PROFILE, VENC_PROFILE_MAIN);
 *    retVal = HAL_VENC_SetParam(0, VENC_INFO_PROFILELEVEL, VENC_PROFILELEVEL_31);
 *
 *    retVal = HAL_VENC_Start(0);
 *
 *    if (retVal != OK)
 *    {
 *        //error handling
 *    }
 *
 * See Also
 *   HAL_VENC_GetParam
 * @endrst
 */
DTV_STATUS_T	HAL_VENC_SetParam(UINT8 port, VENC_INFO_T info, SINT32 value);


/**
 * @brief Read encoding parameter
 *
 * @rst
 * Description
 *   Get VENC encoding ES parameters.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_GetParam(UINT8 port, VENC_INFO_T info, void *pValue)
 *
 * Parameters
 *
 *   - port         [IN] VENC port
 *   - info         [IN] Type of info to set (See VENC_INFO_T)
 *   - pValue       [OUT] Pointer to set result value
 *
 * Return Value
 *
 *   - If the function succeeds, the return value is OK.
 *   - If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block::
 *
 *    DTV_STATUS_T HAL_VENC_GetParam(UINT8 port, VENC_INFO_T info, void *value)
 *    {
 *        IF pValue == NULL OR info>= VENC_INFO_NUM THEN
 *        RETURN NOT_OK
 *        END iF
 *
 *        VENC_lock(wait_semaphore)
 *        IF info == VENC_INFO_FRAMERATE THEN
 *            SET output_framerate TO *pValue;
 *        ELSE IF info == VENC_INFO_CODEC THEN
 *            SET encoding__codec TO *pValue;
 *        ELSE IF info == VENC_INFO_WIDTH THEN
 *            SET encoding__width TO *pValue;
 *        ELSE IF info == VENC_INFO_HEIGHT THEN
 *            SET encoding__height TO *pValue;
 *        ELSE IF info == VENC_INFO_INPUT THEN
 *            SET input_source TO *pValue;
 *        ELSE IF info == VENC_INFO_BITRATE THEN
 *            SET output_bitrate TO *pValue;
 *        ELSE IF info == VENC_INFO_PROFILE THEN
 *            SET output_profile TO *pValue;
 *        ELSE IF info == VENC_INFO_PROFILELEVEL THEN
 *            SET output_profilelevel TO *pValue;
 *        ELSE
 *            error;
 *        END IF
 *
 *        VENC_unlock(post_semaphore)
 *        IF any error THEN
 *            RETURN NOT_OK
 *        ELSE
 *            RETURN OK
 *        END IF
 *    }
 *
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *    DTV_STATUS_T retVal;
 *    VENC_FRAMERATE_T framerate;
 *    retVal = HAL_VENC_GetParam(0, VENC_INFO_FRAMERATE,(void*)&framerate);
 *
 *    VENC_CODEC_T codec;
 *    retVal = HAL_VENC_GetParam(0, VENC_INFO_CODEC, (void*)&codec);
 *
 *    UINT32 bitrate;
 *    retVal = HAL_VENC_GetParam(0, VENC_INFO_BITRATE, (void*)&bitrate);
 *
 *    VENC_PROFILE_T profile;
 *    retVal = HAL_VENC_SetParam(0, VENC_INFO_PROFILE, (void*)&profile);
 *
 *    VENC_PROFILELEVEL_T level
 *    retVal = HAL_VENC_SetParam(0, VENC_INFO_PROFILELEVEL, (void*)&level);
 *
 *    UINT32 width
 *    retVal = HAL_VENC_SetParam(0, VENC_INFO_WIDTH, (void*)&width);
 *
 *    UINT32 height
 *    retVal = HAL_VENC_SetParam(0, VENC_INFO_HEIGHT, (void*)&height);
 *
 *    if (retVal != OK)
 *    {
 *        //error handling
 *    }
 *
 * See Also
 *   HAL_VENC_SetParam
 * @endrst
 */
DTV_STATUS_T	HAL_VENC_GetParam(UINT8 port, VENC_INFO_T info, void *pValue);


 /**
 * @brief Register Callback function for every frame
 *
 * @rst
 * Description
 *   Registers callback function that receives VENC callback message.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_RegisterEncoderCallback(UINT8 port, pfnVENCDataHandlingCB pfnCallback)
 *
 * Parameters
 *
 *    - port            [IN] VENC port
 *    - pfnCallback     [IN] Call back function to receive ES callback data (*pfnVENCDataHandlingCB)
 *
 * Note
 *
 *    - typedef (*pfnVENCDataHandlingCB) (VENC_MSG_TYPE_T *pMsg)
 *    - pMsg          [IN] VENC callback data. (See VENC_MSG_TYPE_T)
 *
 * Return Value
 *
 *   - If the function succeeds, the return value is OK.
 *   - If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   After the callback function, then user must call HAL_VENC_ReleaseData.
 *   The functions called within the callback function are HAL_VENC_CopyData, HAL_VENC_ReleaseData
 *   If a function that waits for a callback thread uses the same semaphore as the above 2 HAL interfaces, be careful as deadlock occurs.
 *
 * Pseudo Code
 *   .. code-block::
 *
 *    DTV_STATUS_T HAL_VENC_RegisterEncoderCallback(UINT8 port, pfnVENCDataHandlingCB pfnCallback)
 *    {
 *        IF pfnCallback == NULL THEN
 *            RETURN NOT_OK
 *        END IF
 *        VENC_lock(wait_semaphore)
 *        SET pointer value of VENC message call back function to pfnCallBack
 *        VENC_unlock(post_semaphore)
 *
 *        IF any error THEN
 *            RETURN NOT_OK
 *        ELSE
 *            RETURN OK
 *        END IF
 *    }
 *
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *    DTV_STATUS_T retVal;
 *
 *    retVal = HAL_VENC_RegisterEncoderCallback(0, &VENCDataHandlingCallback);
 *    if(retVal != OK)
 *    {
 *        printf(“Error in HAL_VENC_RegisterEncoderCallback()\n”);
 *    }
 *
 *    retVal = HAL_VENC_Start(0);
 *    if(retVal != OK)
 *    {
 *        printf(“Error in HAL_VENC_Start()\n”);
 *    }
 *
 * See Also
 *
 *   - HAL_VENC_CopyData
 *   - HAL_VENC_ReleaseData
 *
 * @endrst
 */
DTV_STATUS_T	HAL_VENC_RegisterEncoderCallback(UINT8 port, pfnVENCDataHandlingCB pfnCallBack);


 /**
 * @brief Copy Encoded Data to Destination
 *
 * @rst
 * Description
 *   Whenever a Elementary-Stream is newly generated, a callback occurs, and a Pointer-value which includes the new Elementary-Stream is returned.
 *    This Pointer value belongs to Kernel-Area-Memory. Upper-SW-Layer cannot directly access the kernel-Area-Memory.
 *    This Hal function offers the copy-operation of ES data from Kernel-memory to User-memory so that Upper-SW-Layer can edit the ES data in User-Memory-Area.
 *    (In callback function)Copy encoded ES data from VENC driver memory source to user memory destination.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_CopyData(UINT8 port, UINT8 *pDest, UINT8 *pBufAddr, UINT32 datasize, UINT8 *pRStart, UINT8 *pREnd)
 *
 * Parameters
 *
 *    - port           [IN] VENC port. This parameter will be delivered from VENC_MSG_TYPE_T::channel
 *    - pDest          [IN] Address of memory destination
 *    - pBufAddr       [IN] Address of memory source that is received at callback. This parameter will be delivered from VENC_MSG_TYPE_T::pData
 *    - datasize       [IN] Size of data to copy. This parameter will be delivered from VENC_MSG_TYPE_T::dataLen
 *    - pRStart        [IN] (If Ring buffer) Start address of ring buffer. This parameter will be delivered from VENC_MSG_TYPE_T::pRStart
 *    - pREnd          [IN] (If Ring buffer) End address of ring buffer. This parameter will be delivered from VENC_MSG_TYPE_T::pREnd
 *
 * Return Value
 *
 *   - If the function succeeds, the return value is OK.
 *   - If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   Message parameter received in callback contains the address of ES source, data size and the start/end address of ring buffer.
 *   The function registered as the callback function of the HAL_VENC_RegisterEncoderCallback function must call the following two functions in the following order.
 *   (HAL_VENC_CopyData -> HAL_VENC_ReleaseData)
 *
 * Pseudo Code
 *   .. code-block::
 *
 *    DTV_STATUS_T HAL_VENC_CopyData(UINT8 port, UINT8 *pDest, UINT8 *pBufAddr, UINT32 datasize, UINT8 *pStart, UINT8 *pEnd)
 *    {
 *        IF pDest == NULL or pBufAddr == NULL or datasize <= 0 THEN
 *            RETURN NOT_OK
 *        END IF
 *
 *        VENC_lock(wait_semaphore)
 *        Copy Memory from pBufAddr to pDest with data size
 *        VENC_unlock(post_semaphore)
 *
 *        IF any error THEN
 *            RETURN NOT_OK
 *        ELSE
 *            RETURN OK
 *        END IF
 *    }
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *    void VENCDataHandlingCallback(VENC_MSG_TYPE_T *pMsg)
 *    {
 *        UINT8 *pDest
 *        ALLOCATE MEMORY size of (pMsg->dataLen); to pDest
 *        retVal = HAL_VENC_CopyData(0, pDest, pMsg->pData, pMsg->dataLen, pMsg->pRStart, pMsg->pREnd)
 *        retVal = HAL_VENC_ReleaseData(0, pMsg->pData, pMsg->dataLen)
 *
 *        if(retVal != OK)
 *        {
 *            printf(“Error in HAL_VENC_CopyData()\n”)
 *        }
 *        //do muxing
 *    }
 *
 * See Also
 *   HAL_VENC_ReleaseData
 *
 * @endrst
 */
DTV_STATUS_T	HAL_VENC_CopyData(UINT8 port, UINT8 *pDest, UINT8 *pBufAddr, UINT32 datasize, UINT8 *pRStart, UINT8 *pREnd);


 /**
 * @brief Release Encoded Data buffer
 *
 * @rst
 * Description
 *   (In callback function)Free driver memory of encoded ES data after copy.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_ReleaseData(UINT8 port, UINT8 *pBufAddr, UINT32 datasize)
 *
 * Parameters
 *
 *   - port             [IN] VENC port. This parameter will be delivered from VENC_MSG_TYPE_T::channel
 *   - pBufAddr        [IN] Address of memory source that is received at callback. This parameter will be delivered from VENC_MSG_TYPE_T::pData
 *   - datasize        [IN] Size of data to free. This parameter will be delivered from VENC_MSG_TYPE_T::dataLen
 *
 * Return Value
 *
 *   - If the function succeeds, the return value is OK.
 *   - If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   Message parameter received in callback contains the address of ES source, data size.
 *   The function registered as the callback function of the HAL_VENC_RegisterEncoderCallback function must call the following two functions in the following order.
 *   (HAL_VENC_CopyData -> HAL_VENC_ReleaseData)
 *   If HAL_VENC_Release is not called in the callback function, the resource must be released automatically after the callback function is finished.
 *
 * Pseudo Code
 *   .. code-block::
 *
 *    DTV_STATUS_T HAL_VENC_ReleaseData(UINT8 port, UINT8 *pBufAddr, UINT32 datasize)
 *    {
 *        IF pBufAddr == NULL or datasize <= 0 THEN
 *            RETURN NOT_OK
 *        END IF
 *
 *        VENC_lock(wait_semaphore)
 *        Release Memory of pBufAddr with data size.
 *        VENC_unlock(post_semaphore)
 *
 *        IF any error THEN
 *            RETURN NOT_OK
 *        ELSE
 *            RETURN OK
 *        END IF
 *    }
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *    void VENCDataHandlingCallback(VENC_MSG_TYPE_T *pMsg)
 *    {
 *        UINT8 *pDest;
 *        ALLOCATE MEMORY size of (pMsg->dataLen); to pDest;
 *        retVal = HAL_VENC_CopyData(0, pDest, pMsg->pData, pMsg->dataLen, pMsg->pRStart, pMsg->pREnd);
 *        retVal = HAL_VENC_ReleaseData(0, pMsg->pData, pMsg->dataLen);
 *        if(retVal != OK)
 *        {
 *            printf(“Error in HAL_VENC_ReleaseData()\n”);
 *        }
 *        //do muxing
 *    }
 *
 * See Also
 *   HAL_VENC_CopyData
 *
 * @endrst
 */
DTV_STATUS_T	HAL_VENC_ReleaseData(UINT8 port, UINT8 *pBufAddr,UINT32 datasize);

DTV_STATUS_T	HAL_VENC_GetThumbnail(UINT8 port, UINT32 width, UINT32 height, UINT8 *pBufAddr, UINT32 datasize);

/**
 * @brief Make GOP reset during encoding
 *
 * @rst
 * Description
 *   This is for only LG SIC. For others implement it as empty.
 *   Request IDR frame data by calling HAL_VENC_ResetGOP. The IDR picture data should be passed VENC picture callback within 200ms.
 *
 * Syntax
 *   .. code-block::
 *
 *     DTV_STATUS_T HAL_VENC_ResetGOP(UINT8 port)
 *
 * Parameters
 *
 *   - port              [IN] VENC port
 *
 * Return Value
 *   If the function succeeds, the return value is OK.
 *   If the function fails, the return value is NOT_OK.
 *
 * Remarks
 *   None
 *
 * Pseudo Code
 *   .. code-block::
 *
 *    DTV_STATUS_T HAL_VENC_ResetGOP(UINT8 port)
 *    {
 *        Reset GOP from VENC
 *        IF the result is success return OK
 *        ELSE return NOT_OK
 *    }
 *
 * Function Calling Examle
 *   .. code-block::
 *
 *    retVal = HAL_VENC_ResetGOP(0);
 *
 *    if (retVal != OK){
 *        //error handling
 *    } else {
 *        //do something
 *
 *    }
 *
 * See Also
 *   - None
 * @endrst
 */
DTV_STATUS_T HAL_VENC_ResetGOP(UINT8 port);

void HAL_VENC_DebugMenu(void);


#endif  /*_HAL_VENC_H_ */

