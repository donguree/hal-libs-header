/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file 		hal_ci.h
 *
 *  header of Common Interface DDI Fuction.
 *
 *
 *  @author		hwajeong.lee
 *  @author
 *  @version	1.0
 *  @date		2007.5.1
 *  @date
 *  @note		Additional information.
 *  @see
 */

/******************************************************************************
 	Header File Guarder
******************************************************************************/
#ifndef _CI_HAL_H_
#define _CI_HAL_H_

/******************************************************************************
******************************************************************************/

/******************************************************************************
******************************************************************************/
#include "hal_common.h"
#include "hal_sdec_common.h"
/******************************************************************************
******************************************************************************/

/******************************************************************************
******************************************************************************/


/******************************************************************************
******************************************************************************/


/**
* CIPLUS_DATARATE_T
*
* @see
*/
typedef enum
{
    CIPLUS_DATARATE_72  = 0,
    CIPLUS_DATARATE_96,
} CIPLUS_DATARATE_T;

/**
* CIPLUS_CRYPTOGRAPHY_T
*
* @see
*/
typedef enum
{
    CIPLUS_CRYPTOGRAPHY_DES                 = 0,
    CIPLUS_CRYPTOGRAPHY_AES                 = 1
} CIPLUS_CRYPTOGRAPHY_T;

/**
* CIPLUS_CHIPHER_KEY
*
* @see
*/
typedef enum
{
    CIPLUS_CIPHER_KEY_EVEN                  = 0,
    CIPLUS_CIPHER_KEY_ODD                   = 1
} CIPLUS_CIPHER_KEY_T;

/**
* CIPLUS_DECRYPT_KEY_DST_T
*
* @see
*/
typedef enum
{
    CIPLUS_DECRYPT_KEY_DST_SDEC_INPUT_CH_A		= 0x0,
	CIPLUS_DECRYPT_KEY_DST_SDEC_INPUT_CH_B		= 0x1,
	CIPLUS_DECRYPT_KEY_DST_SDEC_INPUT_CH_C		= 0x2,
	CIPLUS_DECRYPT_KEY_DST_SDEC_INPUT_CH_D		= 0x3,
	CIPLUS_DECRYPT_KEY_DST_DEMUX_OUT_CI_CH_0	= 0x10,
	CIPLUS_DECRYPT_KEY_DST_DEMUX_OUT_CI_CH_1	= 0x11,
	CIPLUS_DECRYPT_KEY_DST_DEMUX_OUT_CI_CH_2	= 0x12,
	CIPLUS_DECRYPT_KEY_DST_DEMUX_OUT_CI_CH_3	= 0x13,
    CIPLUS_DECRYPT_KEY_DST_MAX					= 0xff,
} CIPLUS_DECRYPT_KEY_DST_T;

/**
* CI_ERROR_CHECK_MODE_T
*
* @see
*/
typedef enum
{
	CI_ERROR_CHECK_MODE_FULL = 0,
	CI_ERROR_CHECK_MODE_SIMPLE = 1,
	CI_ERROR_CHECK_MODE_MAX
} CI_ERROR_CHECK_MODE_T;

/**
* CI_CH_T
*
* @see
*/
typedef enum
{
    CIPLUS_CI_CH_0 = 0x0,
    CIPLUS_CI_CH_1 = 0x1,
    CIPLUS_CI_CH_2 = 0x2,
	CIPLUS_CI_CH_3 = 0x3,
	CIPLUS_CI_CH_MAX
} CIPLUS_CI_CH_T;



/**
* CIPLUS_EVENT_HANDLER_INFO_T
*
* @see
*/
typedef void (*PFN_CIPLUS_EVENT_CB) (UINT16 *pValue) ;
typedef struct CIPLUS_EVENT_HANDLER_INFO {
    CIPLUS_CI_CH_T  muxInputCh;
    UINT16 underflowThreshold;
    UINT16 overflowThreshold;
    PFN_CIPLUS_EVENT_CB			pfnUnderflowHandler;
    PFN_CIPLUS_EVENT_CB			pfnOverflowHandler;
} CIPLUS_EVENT_HANDLER_INFO_T;

/**
* CISTPL_DATA_T
*
* @see
*/
typedef struct CISTPL_DATA
{
    UINT8 numOfRealData;
    UINT8 data[255];
}CISTPL_DATA_T;

/******************************************************************************
******************************************************************************/
DTV_STATUS_T HAL_CI_Init(SINT32 *pDeviceHandle);
DTV_STATUS_T HAL_CI_Close(SINT32 *pDeviceHandle);
DTV_STATUS_T HAL_CI_Open(SINT32 deviceHandle);
DTV_STATUS_T HAL_CI_Connect(SINT32 deviceHandle);
DTV_STATUS_T HAL_CI_Disconnect(SINT32 deviceHandle);
UINT8 HAL_CI_DetectCard(SINT32 deviceHandle);
DTV_STATUS_T HAL_CI_Reset(SINT32 deviceHandle);
DTV_STATUS_T HAL_CI_CheckCIS(SINT32 deviceHandle);
DTV_STATUS_T HAL_CI_ReadCIS(UINT8 tupleCode, CISTPL_DATA_T *pCISTPL_Data);
DTV_STATUS_T HAL_CI_WriteCOR(SINT32 deviceHandle);
DTV_STATUS_T HAL_CI_Read(SINT32 deviceHandle, UINT8 *pData, UINT16 *pSize);
DTV_STATUS_T HAL_CI_Write(SINT32 deviceHandle, UINT8 *pData, UINT16 size);
DTV_STATUS_T HAL_CI_NegoBuf(SINT32 deviceHandle, UINT16 *pBufSize);
SINT32 HAL_CI_ReadDAStatus(SINT32 deviceHandle);
void HAL_CI_SetCardPresent(BOOLEAN cardPresent);
void HAL_CI_PLUS_GetCiPlusStdKey( UINT8 *pPath, UINT8 *dkey );
DTV_STATUS_T HAL_CI_PLUS_GetCiPlusDhKey( UINT8 *pPath, UINT8 *dkey );
DTV_STATUS_T HAL_CI_Restart( SINT32 deviceHandle );
UINT8 HAL_CI_CheckCIPLUSCapability( SINT32 deviceHandle );

/******************************************************************************
Function Name
    HAL_CI_PLUS_ResetPCMCIA

Function Description
    Physicallly resets the CICAM(Common Interface Conditional Access Module) for
    CI Plus. During reset host must set the RS(Reset) bit.
    It must be used only for CI Plus.

Function Parameters
    deviceHandle    [IN] device handle for CICAM device

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T HAL_CI_PLUS_ResetPCMCIA(SINT32 deviceHandle);

/******************************************************************************
Function Name
    HAL_CI_PLUS_ReadIIRStatus

Function Description
    Reads IIR(Initialize Interface Request) bit of status register for CI Plus.
    It must be used only for CI Plus.
    The CICAM sets this bit to request a physical interface reset. After setting
    the IIR bit, the CICAM shall not send any other APDUs to the host. The CICAM
    clears the IIR bit when the host sets the RS bit during the reset.

Function Parameters
    deviceHandle    [IN] device handle of CI device to check IIR

Return Value
    It returns the IIR bit of status register. (0,1)

Remarks
    None
******************************************************************************/
SINT32 HAL_CI_PLUS_ReadIIRStatus(SINT32 deviceHandle);

/******************************************************************************
Function Name
    HAL_CI_PLUS_GetDataRate

Function Description
    Gets the data rate on PCMICA bus for CI Plus.
    It must be used only for CI Plus.

Function Parameters
    deviceHandle    [IN] device handle of CI device

Return Value
    It returns the data rate on PCMICA bus.

Remarks
    None
******************************************************************************/
CIPLUS_DATARATE_T HAL_CI_PLUS_GetDataRate(SINT32 deviceHandle);

/******************************************************************************
Function Name
    HAL_CI_PLUS_SetDataPath

Function Description
    Set the input/output datapath to TSP for CI Plus cryptography engine.

Function Parameters
    deviceHandle    [IN] device handle for CICAM device
    eInPath         [IN] input TSIF0_LIVE or TSIF0_FILE or TSIF1
    eOutPath        [IN] output PLAY_LIVE or PLAY_FILE or REC_DESCRMB
    bEnableOutputAV [IN] Enable this flag if data will output to AV fifo

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
//DTV_STATUS_T  HAL_CI_PLUS_SetDataPath(SINT32 deviceHandle,
//                                                CIPLUS_DATAPATH_T eInPath,
//                                                CIPLUS_DATAPATH_T eOutPath,
//                                                UINT16 bEnableOutputAV);

/******************************************************************************
Function Name
    HAL_CI_PLUS_SetCryptography

Function Description
    Set the cryptography to CI Plus cryptography engine.

Function Parameters
    deviceHandle    [IN] device handle for CICAM device
    eCryptography   [IN] Cryptography for protected stream: DES / AES

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
DTV_STATUS_T  HAL_CI_PLUS_SetCryptography(SINT32 deviceHandle,
                                                    CIPLUS_CRYPTOGRAPHY_T eCryptography);

/******************************************************************************
Function Name
    HAL_CI_PLUS_SetCipherKeys

Function Description
    Set the cipher keys to CI Plus cryptography engine.

Function Parameters
    deviceHandle    [IN] device handle for CICAM device
    eCryptography   [IN] Cryptography for protected stream: DES / AES
    eKey            [IN] Even or Odd chipher key of Cryptography
    UINT8FID           [IN] Pid filter number
    pUINT32CipherKeys  [IN] Content of Chipher key
                            AES: IVs 128bits + Keys 128bits,
                            DES: Keys 64bits.
                            E.g.
                                IVs[] = {0xa4,0xa3,0xa2,0xa1, 0xc4,0xc3,0xc2,0xc1, 0xb4,0xb3,0xb2,0xb1, 0xd4,0xd3,0xd2,0xd1};
                                Key[] = {0x08,0x07,0x06,0x05, 0x28,0x27,0x26,0x25, 0x18,0x17,0x16,0x15, 0x38,0x37,0x36,0x35};
                                pUINT32CipherKeys[8] = {0xA4A3A2A1, 0xC4C3C2C1, 0xB4B3B2B1, 0xD4D3D2D1,
                                                     0x08070605, 0x28272625, 0x18171615, 0x38373635};

Return Value
    If the function succeeds, the return value is OK.
    If the function fails, the return value is NOT_OK.

Remarks
    None
******************************************************************************/
UINT32 HAL_CI_PLUS_ReadVersion( SINT32 deviceHandle );
UINT32 HAL_CI_PLUS_ReadCiprof( SINT32 deviceHandle );

DTV_STATUS_T  HAL_CI_PLUS_SetCryptographyByChannel( SINT32 deviceHandle, CIPLUS_DECRYPT_KEY_DST_T eDecryptKeyDst, CIPLUS_CRYPTOGRAPHY_T eCryptography );
DTV_STATUS_T HAL_CI_PLUS_SetCipherKeysByChannel( SINT32 deviceHandle,
					   CIPLUS_DECRYPT_KEY_DST_T eDecryptKeyDst,
					   CIPLUS_CRYPTOGRAPHY_T eCryptography,
					   CIPLUS_CIPHER_KEY_T eKey,
					   UINT32* pu32CipherKeys );

DTV_STATUS_T HAL_CI_PLUS_SetCipherKeysByPIDs( SINT32 deviceHandle,
                                           CIPLUS_DECRYPT_KEY_DST_T eDecryptKeyDst,
                                           CIPLUS_CRYPTOGRAPHY_T eCryptography,
                                           CIPLUS_CIPHER_KEY_T eKey,
                                           UINT32* pu32CipherKeys,
                                           UINT16 *pPIDs,
                                           UINT16 numOfPIDs);

DTV_STATUS_T HAL_CI_SetErrorCheckMode(SINT32 deviceHandle, CI_ERROR_CHECK_MODE_T errCheckMode);
DTV_STATUS_T HAL_CI_GetErrorCheckMode(SINT32 deviceHandle, CI_ERROR_CHECK_MODE_T *perrCheckMode);
UINT32 HAL_CI_SetPCMCIASpeed(SINT32 deviceHandle, UINT8 pcmcia_speed);
void HAL_CI_DebugMenu(void);

//-------------------------------
// ci plus 1.4
//-------------------------------
DTV_STATUS_T HAL_CI_PLUS14_GetCICAMInOutBitRate(UINT32 *pMuxOutputBps, UINT32 *pDeMuxInputBps);

DTV_STATUS_T HAL_CI_PLUS14_RegisterUploadEventHandler(CIPLUS_EVENT_HANDLER_INFO_T *pEventHandle);
DTV_STATUS_T HAL_CI_PLUS14_RegisterDownloadEventHandler(CIPLUS_EVENT_HANDLER_INFO_T *pEventHandle);

DTV_STATUS_T HAL_CI_PLUS14_SetCIPLUS14Config(SDEC_INPUT_PORT_T dtvStreamInputSrc, CIPLUS_CI_CH_T ciMuxInputCh, SDEC_CHANNEL_T sdecInputCh);
DTV_STATUS_T HAL_CI_PLUS14_SetDownloadMode(CIPLUS_CI_CH_T ciDeMuxOutputCh, BOOLEAN bSample);

DTV_STATUS_T HAL_CI_PLUS14_ResetUploadBuf(CIPLUS_CI_CH_T ciMuxInputCh);
DTV_STATUS_T HAL_CI_PLUS14_StartSendingDataToMuxInput(CIPLUS_CI_CH_T ciMuxInputCh);
DTV_STATUS_T HAL_CI_PLUS14_GetUploadBufInfo(CIPLUS_CI_CH_T ciMuxInputCh, UINT8 **ppStartingAddrOfUpBuf, UINT32 *pTotalSizeOfUpBuf);
int HAL_CI_PLUS14_GetUploadBuf(CIPLUS_CI_CH_T ciMuxInputCh, UINT8 **ppPushStartingAddr, UINT32 *pMaxPushSize);
int HAL_CI_PLUS14_PushUploadBuf(CIPLUS_CI_CH_T ciMuxInputCh, UINT8 *pPushStartingAddr, UINT32 pushedSize);
DTV_STATUS_T HAL_CI_PLUS14_StopSendingDataToMuxInput(CIPLUS_CI_CH_T ciMuxInputCh);

DTV_STATUS_T HAL_CI_PLUS14_ResetDownloadBuf(CIPLUS_CI_CH_T ciDeMuxOutputCh);
DTV_STATUS_T HAL_CI_PLUS14_StartReceivingDataFromDeMuxOutput(CIPLUS_CI_CH_T ciDeMuxOutputCh);
DTV_STATUS_T HAL_CI_PLUS14_GetDownloadBufInfo(CIPLUS_CI_CH_T ciDeMuxOutputCh, UINT8 **ppStartingAddrOfDownBuf, UINT32 *pTotalSizeOfDownBuf);
int HAL_CI_PLUS14_GetDownloadBuf(CIPLUS_CI_CH_T ciDeMuxOutputCh, UINT8 **ppReadStartingAddr, UINT8 **ppNextWriteStartingAddr);
int HAL_CI_PLUS14_ReturnDownloadBuf(CIPLUS_CI_CH_T ciDeMuxOutputCh, UINT8 *pReadFinishingAddr, UINT8 *pNextWriteStartingAddr);
DTV_STATUS_T HAL_CI_PLUS14_StopReceivingDataFromDeMuxOutput(CIPLUS_CI_CH_T ciDeMuxOutputCh);

DTV_STATUS_T HAL_CI_PLUS14_AddPIDsOnPIDFilter(CIPLUS_CI_CH_T ciMuxInputCh, UINT8 numOfPIDs, UINT16* pPIDs);
DTV_STATUS_T HAL_CI_PLUS14_RemovePIDsFromPIDFilter(CIPLUS_CI_CH_T ciMuxInputCh, UINT8 numOfPids, UINT16* pPIDs);
DTV_STATUS_T HAL_CI_PLUS14_RemoveAllPIDsFromPIDFilter(CIPLUS_CI_CH_T ciMuxInputCh);
DTV_STATUS_T HAL_CI_PLUS14_GetAllPIDsFromPIDFilter(CIPLUS_CI_CH_T ciMuxInputCh, UINT16 *pNumOfPids, UINT16** ppPids);



#endif /*_CI_HAL_H_ */
