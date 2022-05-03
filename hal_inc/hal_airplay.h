/******************************************************************************
 *   TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2018-2022 by LG Electronics Inc.
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
 *  @version		2.0
 *  @date		2019.12.27
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
/**
 * @brief Write MFi Key into the Secure Storage
 *
 * @rst
 * Functional Requirements
 *   Write MFi Key into the Secure Storage.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *	   argc [in] : currently it must be 8. it can be changed after release.
 *	   argv [in] :
 *     argv[0] org_key_file_name (string): original MFi key file name. to track records.
 *     argv[1] index (string): index of the orginal MFi key file.
 *     argv[2] mfi_obj_id (string): MFi auth provisioning object ID.
 *     argv[3] ppid (string): PPID (Product Plan ID).
 *     argv[4] generation (string): Generation id for revocation.
 *     argv[5] base64_mfi_obj (string): base64 encoded MFi auth provisioning object.
 *     argv[6] base64_fairplay_secret (string): base64 encoded FairPlay Secret.
 *     argv[7] lgcrc32 (string): lgcrc32 value to check the mfi_obj and the fairplay_secret are valid.
 *
 * Return Value
 *   Success: 0
 *   Fail: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     gchar const *hal_key_argv[8] = { 0, };
 *     hal_key_argv[0] = file_name;
 *     hal_key_argv[1] = index;
 *     hal_key_argv[2] = mfi_obj_id;
 *     hal_key_argv[3] = ppid;
 *     hal_key_argv[4] = generation;
 *     hal_key_argv[5] = base64_mfi_obj;
 *     hal_key_argv[6] = base64_fairplay;
 *     hal_key_argv[7] = lg_crc32;
 *
 *     ret = HAL_AIRPLAY_MFi_WriteKeySet(sizeof(hal_key_argv) / sizeof(gchar *), (void **)hal_key_argv);
 *
 * @endrst
 */
int HAL_AIRPLAY_MFi_WriteKeySet(unsigned int argc, void **argv);

/**
 * @brief Check lgcrc32 by using base64 decoded mfi_obj and fairplay_secret
 *
 * @rst
 * Functional Requirements
 *   Check lgcrc32 by using base64 decoded mfi_obj and fairplay_secret.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   None
 *
 * Return Value
 *   Success: 0
 *   Fail: -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if(HAL_AIRPLAY_MFi_VerifyKeySet() == 0) {
 *       printf("verified lgcrc32");
 *     }
 *     else {
 *       printf("verification fail of lgcrc32");
 *     }
 *
 * @endrst
 */
int HAL_AIRPLAY_MFi_VerifyKeySet(void);

/**
 * @brief Delete MFi Key into the Secure Storage
 *
 * @rst
 * Functional Requirements
 *   Delete MFi Key into the Secure Storage.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -2.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   None
 *
 * Return Value
 *   Success: 0
 *   No MFi key : -1
 *   Deletion fail : -2
 *
 * Example
 *   .. code-block:: cpp
 *
 *     int ret = HAL_AIRPLAY_MFi_DeleteKeySet ();
 *
 *     if (ret == 0) { delete ok }
 *     else if (ret == -1) { there is no key }
 *     else if (ret == -2) { deletion fail }
 *     else { unknown error }
 *
 * @endrst
 */
int HAL_AIRPLAY_MFi_DeleteKeySet(void);

/**
 * @brief Read values from Secure Storage and set the values into the out param (deprecated)
 *
 * @rst
 * Functional Requirements
 *   Read values from Secure Storage and set the values into the out param.
 *   It's deprecated after webOS 4.5 MR update. just implement the dummy to avoid the compile error.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return one of the negative number defined below.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   None
 *
 * Return Value
 *   Success: 0
 *   No MFi key : -1
 *   No symmetric key : -3
 *   SoC doesn't support AirPlay feature : -5
 *
 * Example
 *   .. code-block:: cpp
 *
 *     unsigned char *out_org_key_file_name= NULL;
 *     unsigned char *out_index= NULL;
 *     unsigned char *out_mfi_obj_id= NULL;
 *     unsigned char *out_ppid= NULL;
 *     int ret = 0;
 *
 *     ret = HAL_AIRPLAY_MFi_GetKeyInfo (&out_org_key_file_name, &out_index, &out_mfi_obj_id, &out_ppid);
 *
 *     if (ret == 0) {
 *       printf("%s, %s, %s, %s", out_org_key_file_name, out_index, out_mfi_obj_id, out_ppid);
 *       free(out_org_key_file_name);
 *       free(out_index);
 *       free(out_mfi_obj_id);
 *       free(out_ppid);
 *     } else if (ret == -1) {
 *       printf("there is no mfi key in the secure storage");
 *     } else if (ret == -3) {
 *       printf("there is no symmetric key in OTP area");
 *     } else {
 *       printf("unknown error");
 *     }
 *
 * @endrst
 */
int HAL_AIRPLAY_MFi_GetKeyInfo(unsigned char **out_org_key_file_name,
		unsigned char **out_index, unsigned char **out_mfi_obj_id,
		unsigned char **out_ppid);

/**
 * @brief Read values from Secure Storage and set the values into the out param.
 *
 * @rst
 * Functional Requirements
 *   Read values from Secure Storage and set the values into the out param.
 *   Check the validation of the symmetric key in OTP area by using below method
 *     - set fixed 'plain text'
 *     - make 'crypto or hash text' of 'plain text' using 'symmetric key' in OTP securely.
 *     - compare 'crypto or hash text' and 'already known crypto or hash text'. if these are not matched, return -3
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return one of the negative number defined below.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   out_key_info [out] : string including the delimiter '\n' and end of string
 *
 * Return Value
 *   Success: 0
 *   No MFi key : -1
 *   No symmetric key : -3
 *   SoC doesn't support AirPlay feature : -5
 *   When it returns -1, -3, and -5, the memory MUST not be allocated and MUST be NULL for all out_* param.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     gchar *key_info = NULL;
 *     gint ret = HAL_AIRPLAY_MFi_GetKeyInfo2(&key_info);
 *
 *     if(ret == 0) {
 *       gchar **key_info_each = g_strsplit (key_info, "\n", 0);

 *       // use org_key_file_name, index, mfi_obj_id, ppid, generation

 *       g_strfreev(key_info_each);
 *       g_free(key_info);
 *     }
 *     else if (ret == -1) {
 *       g_print("there is no mfi key in the secure storage");
 *     }
 *     else if (ret == -3) {
 *       g_print("there is no symmetric key in OTP area");
 *     }
 *     else if (ret == -5) {
 *       g_print("this soc doesn't support airplay");
 *     }
 *     else {
 *       g_print("unknown error");
 *     }
 *
 * @endrst
 */
int HAL_AIRPLAY_MFi_GetKeyInfo2(char **out_key_info);

/**
 * @brief Validate the provisioning object
 *
 * @rst
 * Functional Requirements
 *   On receiving the provisioning object the secure task must extract the HMAC from the last 16 bytes of the object
 *   Validate it by computing HMAC-SHA512 on the rest of the object using the authentication key, truncating it to first 16 bytes and comparing it with the extracted HMAC.
 *   HMAC_SHA512(key, data) - SHA512 based HMAC, output is digest.
 *   If the HMAC tag of the payload fails to validate, returns fail.
 *   If HMAC validation succeeds, the secure task should decrypt the encrypted section of the provisioning object using the encryption key and initialization vector to retrieve the MFi private key and certificate. And returns success.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   None
 *
 * Return Value
 *   Success: 0
 *   Fail : -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (HAL_AIRPLAY_MFi_VerifyProvisioningObject() == 0) {
 *       printf("mfi obj is verified");
 *     }
 *     else {
 *       printf("mfi obj is not verified");
 *     }
 *
 * @endrst
 */
int HAL_AIRPLAY_MFi_VerifyProvisioningObject(void);

/**
 * @brief Get MFi key certification
 *
 * @rst
 * Functional Requirements
 *   Get MFi key certification
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   certificate [out] : MFi Certificate
 *   certificate_len [out] : the length of MFi Certificate
 *
 * Return Value
 *   Success: 0
 *   Fail : -1
 *   All output values should be newly memory allocated. It will be freed at the user space
 *
 * Example
 *   .. code-block:: cpp
 *
 *     unsigned char *certificate = NULL;
 *     size_t len;
 *     if (HAL_AIRPLAY_MFi_GetCertificate (&certificate, &len) == 0) {
 *       use certificate
 *       free(certificate);
 *     }
 *     else {
 *       print("cannot get certificate");
 *     }
 *
 * @endrst
 */
int HAL_AIRPLAY_MFi_GetCertificate(unsigned char **out_certificate,
		size_t *out_certificate_len);

/**
 * @brief Get MFi Private Key (P) from provisioning object
 *
 * @rst
 * Functional Requirements
 *   Get MFi Private Key (P) from provisioning object
 *   If the private key(P) is shorter than correct length, the high order bytes should be padded with 0s to a length of correct bytes.
 *   The private key is delivered in an unencrypted PKCS #8 DER envelope.
 *   However, if the high-order bytes of the private key are zero, the PKCS object will omit them, resulting in a “short” key (usually 31 bytes instead of 32.)
 *   Please check to make sure that your provisioning code and MFi signature implementation correctly handles the case of a private key shorter than 32 bytes.
 *   If the decoded key is <32 bytes, the high order bytes should be padded with 0s to a length of 32 bytes.
 *   Calculate Signature(S) using MFi Private key (P) and digest(D).
 *     S = EC_SIGN(P,D)
 *     EC_SIGN(key, digest) - NIST P256 Elliptic Curve Digital Signature Algorithm specified in FIPS 184-4. Output is the signature
 *     Copy signature(S) value and length to the output variables
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   digest [in] : digest value for calculating signature
 *   digest_len [in] : length of digest
 *   signature [out] : calculated signature using digest and private key
 *   signature_len [out] : length of signature value
 *
 * Return Value
 *   Success: 0
 *   Fail : -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     unsigned char *digest = { ... };
 *     size_t digest_len = sizeof(digest);
 *     unsigned char *signature = NULL;
 *     size_t signature_len;
 *
 *     if (HAL_AIRPLAY_MFi_GetSignature(digest, digest_len, &signature, &signature_len) == 0) {
 *       use signature
 *       free(signature);
 *     }
 *     else {
 *       print("cannot get signature");
 *     }
 *
 * Remark (optional)
 *   If the private key(P) is shorter than correct length, the high order bytes should be padded with 0s to a length of correct bytes.
 *   The private key is delivered in an unencrypted PKCS #8 DER envelope.
 *   However, if the high-order bytes of the private key are zero, the PKCS object will omit them, resulting in a “short” key (usually 31 bytes instead of 32.)
 *   Please check to make sure that your provisioning code and MFi signature implementation correctly handles the case of a private key shorter than 32 bytes.
 *   If the decoded key is <32 bytes, the high order bytes should be padded with 0s to a length of 32 bytes.
 *
 * @endrst
 */
int HAL_AIRPLAY_MFi_GetSignature(unsigned char *digest, size_t digest_len,
		unsigned char **out_signature, size_t *out_signature_len);

/**
 * @brief Verify FairPlay provisioning object
 *
 * @rst
 * Functional Requirements
 *   Compute the hash for the FairPlay Provisioning Object, and verify it against the hash value provided in the object.
 *   The last 32 bytes of the FairPlay Provisioning Object are reserved for a SHA-256 hash of the previous bytes (object length = 32bytes).
 *   If the calculated value matches the value in the object, the object integrity has been preserved.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return -1.
 *
 * Performance Requirements
 *   There are no performance requirements.
 *
 * Constraints
 *   There must be symmetric key exchanged with Apple on the board.
 *   If there is no symmetric key, this function cannot be tested.
 *
 * Functions & Parameters
 *   None
 *
 * Return Value
 *   Success: 0
 *   Fail : -1
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if(HAL_AIRPLAY_FairPlay_VerifyObjectt() == 0) {
 *       printf("Success");
 *     }
 *     else {
 *       printf("Fail");
 *     }
 *
 * @endrst
 */
int HAL_AIRPLAY_FairPlay_VerifyObject(void);
#endif				/* _COMMON_HAL_AIRPLAY_H_ */
