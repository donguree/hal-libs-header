/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file 		hal_acas_lib.h
 *
 *  header of ACAS LIB HAL Fuction.
 *
 *
 *  @author		Takashi Matsumoto (takashi.matsumoto@lgjlab.com)
 *  @author
 *  @version	1.0
 *  @date		2018.8.29 Takashi Matsumoto (takashi.matsumoto@lgjlab.com)
 *  @date		2018.8.29 Created
 *  @date
 *  @note		Additional information.
 *  @see
 */

/******************************************************************************
 	Header File Guarder
******************************************************************************/
#ifndef _ACAS_LIB_HAL_H_
#define _ACAS_LIB_HAL_H_

/******************************************************************************
	(Control Constants)
******************************************************************************/

/******************************************************************************
	#include (File Inclusions)
******************************************************************************/
#include "hal_common.h"

/******************************************************************************
 	(Constant Definitions)
******************************************************************************/

/******************************************************************************
    (Macro Definitions)
******************************************************************************/

/******************************************************************************
	(Type Definitions)
******************************************************************************/
/**
 * Set/Get Parameters
 */
typedef enum
{
    HAL_ACAS_LIB_OK                         =   0,
    HAL_ACAS_LIB_NOT_OK                     =   -1,

    HAL_ACAS_LIB_PARAMETER_ERROR            =   -2,
    HAL_ACAS_LIB_INVALID_PARAMS             =   -2,
    HAL_ACAS_LIB_GETRANDOMDATA_FAILED       =   -3,
    HAL_ACAS_LIB_GETSECUREDATA_FAILED       =   -4,
    HAL_ACAS_LIB_CRC_FAILED                 =   -5,
    HAL_ACAS_LIB_SHA_FAILED                 =   -6,
    HAL_ACAS_LIB_AES_FAILED                 =   -7,
    HAL_ACAS_LIB_NOT_READY                  =   -8,
    HAL_ACAS_LIB_INSTANCE_FULL              =   -9,
    HAL_ACAS_LIB_INSTANCE_ALREADY_ADDED     =   -10,
    HAL_ACAS_LIB_INSTANCE_NOT_FOUND         =   -11,

}   _HAL_ACAS_LIB_STATE_T;
#define HAL_ACAS_LIB_STATE_T    _HAL_ACAS_LIB_STATE_T


typedef enum
{
    ACAS_KEY_ODD                    =   1,
    ACAS_KEY_EVEN                   =   0,
}   _ACAS_KEY_STATE_T;
#define ACAS_KEY_STATE_T    _ACAS_KEY_STATE_T

typedef struct {
    unsigned int keyFlag;
    unsigned char counterValue[ 20 ];
    unsigned char *pInOutData;
    unsigned int dataLen;
} ACAS_LIB_DESCRAMBLE_INFO;

/******************************************************************************
	(Function Declaration)
******************************************************************************/
DTV_STATUS_T HAL_ACAS_LIB_Initialize( unsigned int dev_index );
DTV_STATUS_T HAL_ACAS_LIB_DeInitialize( unsigned int dev_index );
DTV_STATUS_T HAL_ACAS_LIB_Open( unsigned int dev_index );
DTV_STATUS_T HAL_ACAS_LIB_Close( unsigned int dev_index );
DTV_STATUS_T HAL_ACAS_LIB_GetScrambleKeyProtectCommandParam ( unsigned int dev_index, unsigned char *pOutParam, unsigned int* pOutParamSize );
DTV_STATUS_T HAL_ACAS_LIB_SetScrambleKeyProtectCommandRes ( unsigned int dev_index, unsigned char *pInRes, unsigned int nInResSize );
DTV_STATUS_T HAL_ACAS_LIB_UpdateKey( unsigned int dev_index, unsigned char *cs_key, unsigned int nKeyLength, unsigned char *ecm_data, unsigned int nLength );
DTV_STATUS_T HAL_ACAS_LIB_SetDescrambleKey( unsigned int dev_index, unsigned char *cs_key, unsigned int nKeyLength, unsigned char *ecm_data, unsigned int nLength );
DTV_STATUS_T HAL_ACAS_LIB_ClearDescrambleKey( unsigned int dev_index );
DTV_STATUS_T HAL_ACAS_LIB_Descramble( unsigned int dev_index, unsigned char* pCounterValue, unsigned int pKeyFlag, unsigned char* pInOutData, unsigned int nLength );
DTV_STATUS_T HAL_ACAS_LIB_ReadSecureData( void );
DTV_STATUS_T HAL_ACAS_LIB_DEBUG_SetStatus( void *pStatus, int nLength );
DTV_STATUS_T HAL_ACAS_LIB_DEBUG_GetStatus( void *pStatus, int *pLength );
DTV_STATUS_T HAL_ACAS_LIB_Descramble_ext(
    unsigned int dev_index,
    ACAS_LIB_DESCRAMBLE_INFO *pDescrambleInfo,
    unsigned int numInfo );
#endif /*_ACAS_LIB_HAL_H_ */
