/******************************************************************
 *	 DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *	 Copyright(c) 1999 by LG Electronics Inc.
 *
 *	 All rights reserved. No part of this work may be reproduced, stored in a
 *	 retrieval system, or transmitted by any means without prior written
 *	 permission of LG Electronics Inc.
 ******************************************************************/

/** @file hal_vpq.h
 *
 *  hal vpq driver header.
 *
 *  @author	Youm, Seung-Jun(sjyoum@lge.com)
 *  @version	1.0
 *  @date		2013.05.22
 *  @see
 */

#ifndef	_HAL_VPQ_H_
#define	_HAL_VPQ_H_

/*******************************************************************
	#include 파일들
	(File Inclusions)
*******************************************************************/
#include "hal_common.h"
#include "hal_vsc.h"

#include "hal_vpq_def.h"

/*******************************************************************
	상수 정의
	(Constant Definitions)
*******************************************************************/

/*******************************************************************
	매크로 함수 정의
	(Macro Definitions)
*******************************************************************/

/*******************************************************************
   	 형 정의
 	 (Type Definitions)
*******************************************************************/


/*******************************************************************/
/**************** 	SOC DDI (defined in pql_soc.c)	****************/
/*******************************************************************/
DTV_STATUS_T HAL_VPQ_SetByPassBlocks(HAL_VPQ_DATA_T *pstData);

/* Picture Control */
DTV_STATUS_T HAL_VPQ_SetPictureCtrl(VIDEO_WID_T wId,
									SINT32 *pPcVal,
									CHIP_PC_T *pstData);
DTV_STATUS_T HAL_VPQ_SetColorTemperature(HAL_VPQ_COLOR_TEMP_T *pCscPcCtData,
                                                     CHIP_CT_GAIN_OFFSET_T *pstColorTemperature);

/* Sharpness */
DTV_STATUS_T HAL_VPQ_SetSuperResolution(VIDEO_WID_T wId,
										UINT16 uSrVal,
										CHIP_SUPER_RESOLUTION_T *pstSr);
DTV_STATUS_T HAL_VPQ_SetSharpness(VIDEO_WID_T wId,
								HAL_VPQ_DATA_T *pData,
								CHIP_SHARPNESS_T *pstShp);
DTV_STATUS_T HAL_VPQ_SetPsp(HAL_VPQ_DATA_T *pstData);

/* Init, Open, Close */
DTV_STATUS_T HAL_VPQ_Initialize(void);

/* Histogram */
DTV_STATUS_T HAL_VPQ_GetFreshContrastBypassLUT(SINT32 *pDCBypassLUT);
DTV_STATUS_T HAL_VPQ_GetHistoData(HAL_VPQ_DC2P_HISTODATA_INFO_T *pHistoInfo);
DTV_STATUS_T HAL_VPQ_SetFreshContrast(VIDEO_WID_T wId,
									UINT16 uDcVal,
									CHIP_DC2P_DYNAMIC_CONTRAST_T *pstDynamicContrast);
DTV_STATUS_T HAL_VPQ_SetFreshContrastLUT(HAL_VPQ_DATA_T *pData);
DTV_STATUS_T HAL_VPQ_SetSaturationLUT(HAL_VPQ_DATA_T *pData1,
									HAL_VPQ_DATA_T *pData2);
DTV_STATUS_T HAL_VPQ_SetLocalContrastTable(HAL_VPQ_DATA_T *pstData);
DTV_STATUS_T HAL_VPQ_SetLocalContrastParam(HAL_VPQ_DATA_T *pData);

DTV_STATUS_T HAL_VPQ_InitColorForAdvanced(VIDEO_WID_T wId,
										CHIP_CM_INIT_ADV_COLOR_T *pstInitAdv);
DTV_STATUS_T HAL_VPQ_SetFreshColor(VIDEO_WID_T wId,
								UINT32 uFcVal,
								CHIP_CM_DYNAMIC_COLOR_T *pstDynamicContrast);
DTV_STATUS_T HAL_VPQ_SetPreferredColor(VIDEO_WID_T wId,
										SINT8 *pstPfVal,
										CHIP_COLOR_CONTROL_T *pColorControlData);
DTV_STATUS_T HAL_VPQ_SetClearWhite(VIDEO_WID_T wId,
                                  UINT8 uCwVal,
                                  CHIP_COLOR_WHITE_T *pColorWhiteData);

/* Noise Reduction */
DTV_STATUS_T HAL_VPQ_SetNoiseReduction(VIDEO_WID_T wId,
										UINT16 *pNrVal,
										CHIP_NOISE_REDUCTION_T *pNoiseReductionData);
DTV_STATUS_T HAL_VPQ_SetMpegNoiseReduction(VIDEO_WID_T wId,
										UINT16 uMpegNrVal,
										CHIP_MPEG_NOISE_REDUCTION_T *pMpegNoiseReductionData);
DTV_STATUS_T HAL_VPQ_GetNoiseLevel(UINT16 *uLevel);

/* Deinterlace */
DTV_STATUS_T HAL_VPQ_SetRealCinema(VIDEO_WID_T wId,
                                   BOOLEAN bFilmMode,
                                   HAL_VPQ_CHIP_FILM_T *pstData);

/* Blacklevel */
DTV_STATUS_T HAL_VPQ_SetBlackLevel(VIDEO_WID_T wId,
									UINT8 *pBlVal,
									CHIP_CSC_COEFF_T *pstData);

/* Gamma */
DTV_STATUS_T HAL_VPQ_DeGammaLUT(UINT32* pRedGammaTable,
								UINT32* pGreenGammaTable,
								UINT32* pBlueGammaTable);

DTV_STATUS_T HAL_VPQ_SetGammaLUT(VIDEO_WID_T wId,
								UINT32 *pRedGammaTable,
								UINT32 *pGreenGammaTable,
								UINT32 *pBlueGammaTable);

DTV_STATUS_T HAL_VPQ_InvGammaEn(BOOLEAN bOnOff);

/* Color Gamut */
DTV_STATUS_T HAL_VPQ_SetGamutLUT(HAL_VPQ_GAMUT_LUT_T *pstGamutLut);

/* Color Manage */
DTV_STATUS_T HAL_VPQ_InitColorForExpert(VIDEO_WID_T wId,
										CHIP_CM_INIT_EXP_COLOR_T *pstData);
DTV_STATUS_T HAL_VPQ_SetColorManagement(VIDEO_WID_T wId,
										HAL_VPQ_CM_DATA_T *pCmData,
										CHIP_CM_DATA_T *pChipCmData);

/* Game Mode */
DTV_STATUS_T HAL_VPQ_SetLowDelayMode(BOOLEAN bGameMode);

/* Color Gain */
DTV_STATUS_T HAL_VPQ_SetColorGain(VIDEO_WID_T wId,
								SINT32 uCgVal);

/* IRE pattern */
DTV_STATUS_T HAL_VPQ_SetIREInnerPattern(UINT8 patternType,
								HAL_VPQ_INNER_PATTERN_IRE_T patternIre);

/* HDR */
DTV_STATUS_T HAL_VPQ_HDR_GetPicInfo(HAL_VPQ_DATA_T *pData);
DTV_STATUS_T HAL_VPQ_SetHDR3DLUT(UINT16 *pLUT);
DTV_STATUS_T HAL_VPQ_SetHDREotf(HAL_VPQ_DATA_T *pData);
DTV_STATUS_T HAL_VPQ_SetHDROetf(HAL_VPQ_DATA_T *pData);
DTV_STATUS_T HAL_VPQ_SetHDRToneMap(HAL_VPQ_DATA_T *pData);
DTV_STATUS_T HAL_VPQ_SetHDRColorCorrection(HAL_VPQ_DATA_T *pData);
DTV_STATUS_T HAL_VPQ_SetGamutMatrixPre(HAL_VPQ_DATA_T *pData);
DTV_STATUS_T HAL_VPQ_SetGamutMatrixPost(HAL_VPQ_DATA_T *pData);
DTV_STATUS_T HAL_VPQ_SetHlgYGainTable(HAL_VPQ_DATA_T *pData);
DTV_STATUS_T HAL_VPQ_SetPQModeInfo(HAL_VPQ_DATA_T *pData);
DTV_STATUS_T HAL_VPQ_GetPQModeInfo(HAL_VPQ_DATA_T *pData);
DTV_STATUS_T HAL_VPQ_SetLuminenceBoost(HAL_VPQ_DATA_T *pData);

/* ODC */
DTV_STATUS_T HAL_VPQ_SetOd(HAL_VPQ_DATA_T *pData);
DTV_STATUS_T HAL_VPQ_SetOdExtentions(HAL_VPQ_DATA_T *pData);

/* Dolby */
DTV_STATUS_T HAL_VPQ_SetDolbyPictureMode(BOOLEAN bOnOff, UINT8 uPictureMode);
DTV_STATUS_T HAL_VPQ_SetDolbyPictureMenu(HAL_VPQ_DOLBY_PICTURE_DATA_T pictureData);
DTV_STATUS_T HAL_VPQ_SetDolbyPwmRatio(UINT8 u8Percent);
void HAL_VPQ_InitDolbyPictureConfig(char* configFilePath[]);
DTV_STATUS_T HAL_VPQ_GetDolbySWVersion(char* pstVersion);
DTV_STATUS_T HAL_VPQ_SetDolbyGDDelay(HAL_DOLBY_GD_DELAY_LUT_T dolby_GDDelay_standard, HAL_DOLBY_GD_DELAY_LUT_T dolby_GDDelay_latency);
DTV_STATUS_T HAL_VPQ_SetDolbyAmbientLight(UINT32 uOnOff, UINT32 uLux, UINT32 *uRawdata);

/* Smart Color Contrast */
DTV_STATUS_T HAL_VPQ_SetDominantColorDetectRun(BOOLEAN bIsActivated, BOOLEAN bIsSecured);
DTV_STATUS_T HAL_VPQ_GetDominantColorGain(float *pfColorGain, UINT8 *pColorNum);

/* OBC */
DTV_STATUS_T HAL_VPQ_GetOBCData(HAL_VPQ_DATA_T *pstData);
DTV_STATUS_T HAL_VPQ_SetOBCLUT(HAL_VPQ_DATA_T *pstData);
DTV_STATUS_T HAL_VPQ_SetOBCCtrl(HAL_VPQ_DATA_T *pstData);
DTV_STATUS_T HAL_VPQ_NotifySensorLuxValue(UINT16 ui16LuxVal);
DTV_STATUS_T HAL_VPQ_SetExtInnerPattern(HAL_VPQ_DATA_T* pstExtPtnInfo);
#endif	/* _HAL_VPQ_H_ */
