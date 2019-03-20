/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2018 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file 		hal_airplay.h
 *
 *  header of Common Interface HAL Fuction.
 *
 *  @author		kyungnam.bae
 *  @version	1.0
 *  @date		2018.6.26
 *  @date
 *  @note		Additional information.
 *  @see
 */

/******************************************************************************
	Header File Guarder
******************************************************************************/
#ifndef _COMMON_HAL_AIRPLAY_H_
#define _COMMON_HAL_AIRPLAY_H_

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
int HAL_AIRPLAY_MFi_WriteKeySet(unsigned int argc, void **argv);
int HAL_AIRPLAY_MFi_VerifyKeySet(void);
int HAL_AIRPLAY_MFi_DeleteKeySet(void);
int HAL_AIRPLAY_MFi_GetKeyInfo(unsigned char **out_org_key_file_name,
		unsigned char **out_index, unsigned char **out_mfi_obj_id,
		unsigned char **out_ppid);
int HAL_AIRPLAY_MFi_GetKeyInfo2(char **out_key_info);
int HAL_AIRPLAY_MFi_VerifyProvisioningObject(void);
int HAL_AIRPLAY_MFi_GetCertificate(unsigned char **out_certificate,
		size_t *out_certificate_len);
int HAL_AIRPLAY_MFi_GetSignature(unsigned char *digest, size_t digest_len,
		unsigned char **out_signature, size_t *out_signature_len);
int HAL_AIRPLAY_FairPlay_VerifyObject(void);
#endif				/* _COMMON_HAL_AIRPLAY_H_ */
