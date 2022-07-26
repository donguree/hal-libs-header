/******************************************************************************
 *   TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2013 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file		hal_drm.h
 *
 *  Hardware Abstration Layer for DRM
 *
 *  @author		Yujin, Lee (yujin.lee@lge.com)
 *  @version	1.0
 *  @date		2013.03.04
 *  @note
 *  @see
 */

/******************************************************************************
    Header File Guarder
******************************************************************************/
#ifndef	_HAL_DRM_H_
#define	_HAL_DRM_H_

/******************************************************************************
    Control Constants
******************************************************************************/

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
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_SetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 length);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_DeleteSecureData (SINT8 *pDataPath);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_GetHWRandomData (UINT8 *pData, UINT32 digit);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_GetSecureClock (UINT64 *pSecureClock);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_SetSecureClock (UINT64 secureClock);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_GetClearDataLength (SINT8 *pDataPath, UINT32 *pLength);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_AESHWInit (SINT32 mode, UINT8 *pKey, UINT8 *pIV, SINT32 operation, SINT32 isPadding);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_AESHWUpdate (UINT8 *pOutData, UINT32 *pOutDataSize, UINT8 *pInData, UINT32 nInDataSize);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_AESHWFinish (UINT8 *pOutData, UINT32 *pOutDataSize);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_GetHWID(UINT8 *pOutData, UINT32 *pOutDataSize);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_IsSecureDataExist(SINT8 *pDataPath);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_InitDrv(void);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_GetSecureDataProtected(SINT8 *pID, UINT8 *pData, UINT32 *pLength);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_WriteWidevineKeyBox(UINT8 *pData, SINT32 dataLength);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_GetWidevineDeviceID(UINT8 *pDeviceID,  SINT32 *pIdLength);

// UHDCP(CAS PROTECTION)
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_UHDCP_SetCW(UINT8 *KID, UINT8 *CW);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_UHDCP_Decrypt(UINT8 *pData, UINT32 data_size,
                                   UINT8 *pIV, UINT8 *pKID, ULONG block_offset, UINT16 byte_offset);

/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_HDMI_SetSecureDataforHDCP22(SINT8 *KeyID, UINT8 *pData, UINT32 DataLength);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_HDMI_GetSecureDataforHDCP22(SINT8 *KeyID, UINT8 *pData);
/**
 * @brief ex) Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   ex) This API performs .................... This function registers active video window callback function.
 *   (VSC RegisterActiveWindowCallback) The video window dimension is an output frame from video decoder and is not cropped.
 *   Active video window means area with real video area from pillar box or letter box video image which includes black bars.
 *
 * Responses to abnormal situations, including
 *   - ex) In abnormal case, the BSP should return an non-Zero.
 *   - ex) If abnormal data is set, the driver should return an error. The generic error codes are described at the Generic Error Codes chapter.
 *     It is guaranteed that disconnect occurs first before ‘vsc close(ex.pm suspend)’ for normal operation.
 *     However, when disconnect occurs after ‘vsc close’ as an exception, system problems(ex. kernel panic) should not occur.
 *
 * Performance Requirements
 *   ex) The response time of this function should be within 100ms.
 *
 * Constraints
 *   - ex) There is no constraints.
 *   - ex) The scaler uses the subscription function of V4L2 events. When implementing the event of the V4L2 subscription function,
 *     it must be implemented using the epoll feature provided by the kernel. In case of other constraints, please refer to the each API description.
 *
 * Functions & Parameters
 *  * ex) DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength)
 *
 *  For the data type, following data types are defined
 *
 *  * ex)
 *  * nSrcLen     [in]    size of pSrcData
 *  * pSrcData    [in]    buffer for data to be decrypted
 *  * pDstLen     [out]   sizeof pDstData
 *  * pDstData    [out]   buffer to store the decrypted data
 *
 * Return Value
 *   ex) Zero(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     guint8 tc_lc128[LEN_LC128] = {...};
 *     guint8 tc_km[LEN_KM] = {...};
 *     guint8 tc_ks[LEN_KS] = {...};
 *     guint8 tc_seed[32] = {...};
 *     guint8 *testvector[] = {tc_lc128, tc_km, tc_ks, tc_seed};
 *
 *     if (0 != HAL_HDCP2_UseTestVector (4, (void**) testvector)) {
 *         // handling error
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_VerifyHDCP22forHDMI(void);

#endif /* _HAL_DRM_H_ */

