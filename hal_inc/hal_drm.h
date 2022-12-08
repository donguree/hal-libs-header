
/******************************************************************************
 *   TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2013-2022 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/
/** @file    hal_drm.h
 *
 *  Hardware Abstration Layer for DRM
 *
 *  @author  yujin.lee@lge.com
 *  @author  cs.jung@lge.com
 *  @version 1.1
 *  @date    2013-2022
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
 * @brief Gets data from the secure storage where cannot be accessed with general file I/O.
 *
 * @rst
 * Functional Requirements
 *   It should be impossible to access with a file system access method such as the linux shell.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 100ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     data_id [in] identifier of stored secure data
 *     data    [out] secure data buffer
 *     length  [in/out] length of secure data to read / length of data actually read
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     char *data_id = "secureStore.dat";
 *     unsigned char *data = NULL;
 *     unsigned int length = 32;
 *     data = (unsigned char*)malloc(length);
 *     ret_val = HAL_DRM_GetSecureData(data_id, data, &length);
 *     if (ret_val != OK) {
 *       // error handling
 *       if (ret_val == INVALID_PARAMS) {
 *         // Check parameters
 *       }
 *       else if (ret_val == NOT_PERMITTED) {
 *         // Check permission for the secure storage path
 *       }
 *       else {
 *         // Unknown error
 *       }
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_GetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 *pLength);
/**
 * @brief Sets data to the secure storage where cannot be accessed with general file I/O.
 *
 * @rst
 * Functional Requirements
 *   It should be impossible to access with a file system access method such as the linux shell.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 200ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     data_id [in] identifier of stored secure data
 *     data    [out] secure data buffer
 *     length  [in/out] length of secure data to read / length of data actually read
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     char *data_id = "secureStore.dat";
 *     unsigned char *data = "This is secure data";
 *     ret_val = HAL_DRM_SetSecureData(data_id, data, strlen(data));
 *     if (ret_val != OK) {
 *       // error handling
 *       if (ret_val == INVALID_PARAMS) P
 *         // Check parameters
 *       }
 *       else if (ret_val == NOT_PERMITTED) {
 *         // Check permission for the secure storage path
 *       }
 *       else {
 *         // Unknown error
 *       }
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_SetSecureData (SINT8 *pDataPath, UINT8 *pData, UINT32 length);
/**
 * @brief Delete data in a secure storage area where cannot be access with general file I/O.
 *
 * @rst
 * Functional Requirements
 *   It should be impossible to access with a file system access method such as the linux shell.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 200ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     data_id [in] identifier of stored secure data
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     char *data_id = "secureStore.dat";
 *     unsigned char *data = "This is secure data";
 *     ret_val = HAL_DRM_DeleteSecureData(data_id);
 *     if (ret_val != OK) {
 *       // error handling
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_DeleteSecureData (SINT8 *pDataPath);
/**
 * @brief Get random data which is generated from a physical process(i.e. a hardware) to get true random number.
 *
 * @rst
 * Functional Requirements
 *   The random number should be unpredictable because it is used for data encryption.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 1ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     data [out] identifier of stored secure data
 *     digit [in] digit of random data
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     unsigned char data[32] = {0,};
 *     ret_val = HAL_DRM_GetHWRandomData(data, 32);
 *     if (ret_val != OK) {
 *       // error handling
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_GetHWRandomData (UINT8 *pData, UINT32 digit);
/**
 * @brief Get Secured Clock(GMT TIME) from RTC(Real Time clock).
 *
 * @rst
 * Functional Requirements
 *   RTC should be set by HAL_DRM_SetSecureClock() in advance. Secured Clock means that user can’t change time.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 30ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     secure_clock [out] secure clock(GMT time)
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     unsigned long long secure_clock;
 *     ret_val = HAL_DRM_GetSecureClock(&secure_clock);
 *     if (ret_val != OK) {
 *       // error handling
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_GetSecureClock (UINT64 *pSecureClock);
/**
 * @brief Set Secured Clock(GMT TIME) to [in]secure_clock. If secure_clock is 0, this function has to get time from NTP server.
 *
 * @rst
 * Functional Requirements
 *   It should not be possible to modify this time in any way other than this function.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 30ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     secure_clock [in] secure clock(GMT time)
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     unsigned int year, month, day;
 *     struct tm cur_time;
 *     unsigned long long secure_clock;
 *
 *     cur_time.tm_year = year – 1900;
 *     cur_time.tm_mon = month – 1;
 *     cur_time.tm_day = day;
 *     secure_clock = mktime(&cur_time);
 *     ret_val = HAL_DRM_GetSecureClock(&secure_clock);
 *     if (ret_val != OK) {
 *       // error handling
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_SetSecureClock (UINT64 secureClock);
DTV_STATUS_T HAL_DRM_GetClearDataLength (SINT8 *pDataPath, UINT32 *pLength);
/**
 * @brief  Initialize AES hardware block and allocate resources for AES operation
 *
 * @rst
 * Functional Requirements
 *   This function should be called before calling HAL_DRM_AESHWUpdate
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 1ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     mode [in] AES Mode(0:CBC, 1:CTR, 2:ECB)
 *     key [in] Key for AES decryption/encrypion
 *     iv [in] initialization vector
 *     operation [in] AES operation(0:Encrypt, 1:Decrypt)
 *     is_padding [in] Is padding used(0:no padding, 1:padding)
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     unsigned char *key = "0123456789abcdef";
 *     unsigned char iv[16] = {0, };
 *     ret_val = HAL_AESHWInit(AES_MODE_CBC, key , iv, AES_OP_ENC, AES_PAHALNG);
 *     if (ret_val != OK) {
 *       // error handling
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_AESHWInit (SINT32 mode, UINT8 *pKey, UINT8 *pIV, SINT32 operation, SINT32 isPadding);
/**
 * @brief  Execute AES hardware block. This function performs the essential role for AES data processing. For big data, this function can be called repeatedly. To process residual data, the HAL_DRM_AESHWFinish() function should be called instead of this function.
 *
 * @rst
 * Functional Requirements
 *   This function should be called after HAL_DRM_AESHWInit
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     out_data [out] Updated data buffer
 *     out_length [out] Updated data size
 *     in_data [in] Data buffer to be updated
 *     in_length [in] Data size to be updated
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     unsigned char *key = "0123456789abcdef";
 *     unsigned char iv[16] = {0, };
 *     unsigned char in_data[16] = {'a', 'b', 'c', 'd',
 *                                  'e', 'f', 'g', 'h',
 *                                  'i', 'j', 'k', 'l',
 *                                  'm', 'n', 'o', 'p'};
 *     unsigned int in_size = sizeof(in_data);
 *     unsigned char out_data[16];
 *     unsigned int out_size = 0;
 *     ret_val = HAL_DRM_AES_HWInit(AES_MODE_CBC, key , iv, AES_OP_ENC, AES_PAHALNG);
 *     if (retVal != OK) {
 *       // error handling
 *     } else {
 *       ret_val = HAL_DRM_AESHWUpdate(out_data, &out_size, in_data, in_size);
 *       if (ret_val != OK) {
 *         // error handling
 *       }
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_AESHWUpdate (UINT8 *pOutData, UINT32 *pOutDataSize, UINT8 *pInData, UINT32 nInDataSize);
/**
 * @brief  Process residual data and finish AES hardware block
 *
 * @rst
 * Functional Requirements
 *   This function should be called after finishing the HAL_DRM_AESHWUpdate
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     out_data [out] Updated data buffer
 *     out_length [out] Updated data size
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     unsigned char *key = "0123456789abcdef";
 *     unsigned char iv[16] = {0, };
 *     unsigned char in_data[16] = {'a', 'b', 'c', 'd',
 *                                  'e', 'f', 'g', 'h',
 *                                  'i', 'j', 'k', 'l',
 *                                  'm', 'n', 'o', 'p'};
 *     unsigned int in_size = sizeof(in_data);
 *     unsigned char out_data[16];
 *     unsigned int out_size = 0;
 *     unsigned int out_length = 0;
 *     ret_val = HAL_DRM_AESHWInit(AES_MODE_CBC, key , iv, AES_OP_ENC, AES_PAHALNG);
 *     if (ret_val != OK) {
 *       // error handling
 *     } else {
 *       ret_val = HAL_DRM_AESHWUpdate(out_data, &out_size, in_data, in_size);
 *       if (ret_val != OK) {
 *         // error handling
 *       }
 *       ret_val = HAL_DRM_AESHWFinish(out_data + out_size, &out_length);
 *       if (ret_val != OK) {
 *         // error handling
 *       }
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_AESHWFinish (UINT8 *pOutData, UINT32 *pOutDataSize);
DTV_STATUS_T HAL_DRM_GetHWID(UINT8 *pOutData, UINT32 *pOutDataSize);
/**
 * @brief Check whether secure data exists or not
 *
 * @rst
 * Functional Requirements
 *   It should be impossible to access with a file system access method such as the linux shell.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 50ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     data_id [in] identifier of stored secure data
 *
 * Return Value
 *   OK if the data exists, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     char *data_id = "secureStore.dat";
 *     ret_val = HAL_DRM_IsSecureDataExist(data_id);
 *     if (ret_val == OK) {
 *       // HAL_DRM_GetSecureData() ...
 *       // HAL_DRM_DeleteSecureData() ...
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_IsSecureDataExist(SINT8 *pDataPath);
/**
 * @brief Initialize device drivers for other HAL functions to perform their functions successfully.
 *
 * @rst
 * Functional Requirements
 *   It should be called before other HAL functions. If another function can be used without this function, it is implemented with return OK.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 50ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     None
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     ret_val = HAL_DRM_InitDrv();
 *     if (ret_val != OK) {
 *       // error handling
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_InitDrv(void);
DTV_STATUS_T HAL_DRM_GetSecureDataProtected(SINT8 *pID, UINT8 *pData, UINT32 *pLength);
/**
 * @brief  Store widevine keybox data to secure storage.
 *
 * @rst
 * Functional Requirements
 *   Only one widevine key can be stored. If the key already exists, it is overwritten. Arbitrary access to this data is not permitted.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 200ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     data [in] keybox data
 *     length [in] size of keybox
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     unsigned char wv_key[256];
 *     int length = sizeof(wv_key);
 *     FILE *fp = fopen("widevine.pak", "rb");
 *     fread(wv_key, 1, 256, fp);
 *     fclose(fp);
 *     ret_val = HAL_DRM_WriteWidevineKeyBox(data, length);
 *     if (ret_val != OK) {
 *       // error handling
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_WriteWidevineKeyBox(UINT8 *pData, SINT32 dataLength);
/**
 * @brief  Read device ID of widevine keybox.
 *
 * @rst
 * Functional Requirements
 *   Without validating the validity of the widevine key, we just get the device ID.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 100ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     device_id [out] device ID of stored widevine keybox
 *     length [out] length of the ID
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     unsigned char device_id[32];
 *     int length = sizeof(device_id);
 *
 *     ret_val = HAL_DRM_GetWidevineDeviceID(device_id, &length);
 *     if (ret_val != OK) {
 *       // error handling
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_GetWidevineDeviceID(UINT8 *pDeviceID,  SINT32 *pIdLength);

// UHDCP(CAS PROTECTION)
/**
 * @brief  Send KID(Key Identifier) and CW(Control Word) to Descrambler to TEE.
 *
 * @rst
 * Functional Requirements
 *   This function is used only for UHDCP client and TEE.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     kid [in] It is the identifier of CW that is required for descrambling of the scrambled stream
 *     cw [in] It is used as the 16Byte key value when descrambling the scrambled stream.
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     unsigned char kid_sample[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 *                                   0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
 *     unsigned char cw_sample[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                                   0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
 *
 *     ret_val = HAL_DRM_UHDCP_SetCW(kid_sample, cw_sample);
 *     if (ret_val != OK) {
 *       // error handling
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_UHDCP_SetCW(UINT8 *KID, UINT8 *CW);
/**
 * @brief  Descramble an scrambled ATSC 3.0 terrestrial UHDTV broadcast stream.
 *
 * @rst
 * Functional Requirements
 *   This function support 'cenc' Protection Scheme (AES-128 Counter Mode) defined in CENC(ISO/IEC * 23001-7) Standard.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 1600ms(parameter 1mb, call function 100 times) and 200ms(parameter 23kb, call function 100 times).
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     data [in/out] data buffer to be descrambled. The descrambling is handled in place mode.
 *     data_size [in] The actual size of the data buffer to be descrambled.
 *     iv [in] initialization vector used as a counter in AES-128 Counter Mode
 *     kid [in] the identifier of CW that is required for descrambling of the scrambled stream. The length of pKID is 16bytes.
 *     block_offset [in] AES block offset in the payload (sample data).
 *     byte_offset [in] byte offset in the AES block.
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     unsigned char kid_sample[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 *                                   0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
 *     unsigned char cw_sample[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 *                                  0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
 *     unsigned char iv_sample[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 *                                 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
 *     unsigned int data[16384];
 *     ret_val = HAL_DRM_UHDCP_SetCW(kid_sample, cw_sample);
 *     if(ret_val == OK) {
 *       ret_val = DILE_UHDCP_Decrypt(data, sizeof(data), iv_sample, kid_sample, 0, 0);
 *       if (ret_val != OK) {
 *         // error handling
 *       }
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_UHDCP_Decrypt(UINT8 *pData, UINT32 data_size,
                                   UINT8 *pIV, UINT8 *pKID, ULONG block_offset, UINT16 byte_offset);
/**
 * @brief Store HDCP2.2 key to a secure storage.
 *
 * @rst
 * Functional Requirements
 *   It should be impossible to access with a file system access method such as the linux shell.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 200ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     data_id [in] identifier of stored secure data. In this case, ID is "HDCP22_HDMI_KEY".
 *     data [out] key data buffer
 *     length [in] size of key data
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     char *data_id = "HDCP22_HDMI_KEY";
 *     unsigned char data[HDCP22_KEY_LENGTH];
 *     ret_val = HAL_DRM_HDMI_SetSecureDataforHDCP22(data_id, data, HDCP22_KEY_LENGTH);
 *     if (ret_val != OK) {
 *       // error handling
 *       if (ret_val == INVALID_PARAMS) {
 *         // Check parameters
 *       }
 *       else if (ret_val == NOT_PERMITTED) {
 *         // Check permission for the secure storage path
 *       }
 *       else {
 *         // Unknown error
 *       }
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_HDMI_SetSecureDataforHDCP22(SINT8 *KeyID, UINT8 *pData, UINT32 DataLength);
/**
 * @brief Gets HDCP2.2 key from the secure storage where cannot be accessed with general file I/O.
 *
 * @rst
 * Functional Requirements
 *   It should be impossible to access with a file system access method such as the linux shell.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 100ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     data_id [in] identifier of stored secure data. In this case, ID is "HDCP22_HDMI_KEY".
 *     data [out] key data buffer
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     char *data_id = "HDCP22_HDMI_KEY";
 *     unsigned char data[HDCP22_KEY_LENGTH];
 *     unsigned int length = HDCP22_KEY_LENGTH;
 *     ret_val = HAL_DRM_HDMI_GetSecureDataforHDCP22(data_id, data);
 *     if (ret_val != OK) {
 *       // error handling
 *       if (ret_val == INVALID_PARAMS) {
 *         // Check parameters
 *       }
 *       else if (ret_val == NOT_PERMITTED) {
 *         // Check permission for the secure storage path
 *       }
 *       else {
 *         // Unknown error
 *       }
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_HDMI_GetSecureDataforHDCP22(SINT8 *KeyID, UINT8 *pData);
/**
 * @brief Check validity of encrypted HDCP2.2 key which is stored in secure storage area.
 *
 * @rst
 * Functional Requirements
 *   The HDDP2.2 key should be written before this function called.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function returns proper value in DTV_STATUS_T.
 *
 * Performance Requirements
 *   The response time of this function should be within 50ms.
 *
 * Constraints
 *   There is no special constraints.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *     None
 *
 * Return Value
 *   OK if the function success, or returns proper value in DTV_STATUS_T
 *
 * Example
 *   .. code-block:: cpp
 *
 *     DTV_STATUS_T ret_val;
 *     ret_val = HAL_DRM_VerifyHDCP22forHDMI();
 *     if (ret_val != OK) {
 *         // error handling
 *     }
 * @endrst
 */
DTV_STATUS_T HAL_DRM_VerifyHDCP22forHDMI(void);

#endif /* _HAL_DRM_H_ */

