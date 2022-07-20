/******************************************************************************
 *   TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2010-2022 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file    hal_hdcp2.h
 *
 *  Header of HDCP2 HAL Fuction for HDCP 2.x Interface Independent Adaptation.
 *
 *  @author  yujin.lee@lge.com
 *  @author  kyungnam.bae@lge.com
 *  @version 1.0
 *  @date    2013-2022
 *  @see     https://www.digital-cp.com/hdcp-specifications
 */

/******************************************************************************
    Header File Guarder
******************************************************************************/
#ifndef _COMMON_HAL_HDCP2_H_
#define _COMMON_HAL_HDCP2_H_

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
 * @brief Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   Encrypt HDCP2 RX Key Set(pKeySet) and Write Encrypted HDCP2 Key Set into
 *   Secured Storage.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 100ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pKeySet [in] 858 bytes HDCP2 Key Set. LC128(16) + Receiver ID(5) + Device
 *     public Key(131) + reserved bit(2) + Root Signature(384) + Device
 *     Private Key(320)
 *   dst_file_path [in] (Ignore it if the secure storage is supported) Storage
 *     path for the encrypted hdcp2 key.
 *   keyLength [in] (Ignore it if the secure storage is supported) The length
 *     of the pKeySet. It should be 858.
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_WriteKeySet(pKeySet, NULL, keyLength)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_WriteKeySet(unsigned char *pKeySet, unsigned char *dst_file_path,
              int keyLength);

/**
 * @brief Deprecated. Read HDCP2 RX Key from REE
 *
 * @rst
 * Functional Requirements
 *   Deprecated after enabling Secure Storage. BSP should implement Secure
 *   Storage and store the keys related in HDCP2.x into Secure Storage. Ignore
 *   the function if Secure Storage is supported. Get the Encrypted HDCP2 RX
 *   Key from Secure Storage and write this to the buffer.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   NA
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pEncHdcp2Key [out] Encrypted HDCP2 RX Key Set buffer.
 *    (Or it can be the platform specific value.)
 *   src_file_path [in] Path of the encrypted HDCP2 RX Key file.
 *   pEncKeyLength [out] Encrypted HDCP2 RX Key Size (Or the length of
 *    the platform specific value. the MAX Length = 900).
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   NA
 * @endrst
 */
int HAL_HDCP2_GetEncHdcp2Key(unsigned char *pEncHdcp2Key,
                 unsigned char *src_file_path,
                 unsigned char *pEncKeyLength);

/**
 * @brief Deprecated. Store HDCP2 RX Key into Secure Storage
 *
 * @rst
 * Functional Requirements
 *   Deprecated after enabling Secure Storage. BSP should implement Secure
 *   Storage and store the keys related in HDCP2.x into Secure Storage. Ignore
 *   the function if Secure Storage is supported. Set the encrypted HDCP2 RX
 *   Key to trust zone.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   NA
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pEncHdcp2Key [out] Encrypted HDCP2 RX Key Set buffer.
 *    (Or it can be the platform specific value.)
 *   src_file_path [in] Path of the encrypted HDCP2 RX Key file.
 *   pEncKeyLength [out] Encrypted HDCP2 RX Key Size (Or the length of
 *    the platform specific value. the MAX Length = 900).
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   NA
 * @endrst
 */
int HAL_HDCP2_SetEncHdcp2Key(unsigned char *pEncHdcp2Key);

/**
 * @brief Read HDCP2 TX Root Public Key from Secure Storage
 *
 * @rst
 * Functional Requirements
 *   Operation
 *    1. Pick 'hdcp2_txroot' key id in sedata.
 *    2. Operate SHA1 for validating Root Public Key.
 *    3. Set value to the pRootPublicKey variable.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   BSP should store an encrypted HDCP2 TX Key Set file in Secure Storage.
 *   It's located in the sedata partition as 'hdcp2_txroot' key id.
 *
 * Functions & Parameters
 *   pRootPublicKey [out] A decrypted Root Public Key (=Kpubdcp).
 *   src_file_path [in] (Ignore it if the secure storage is supported)
 *    Deprecated. An encrypted TX Key Set file path.
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_GetRootPublicKey(pRootPublicKey, NULL)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_GetRootPublicKey(unsigned char *pRootPublicKey,
                   unsigned char *src_file_path);

/**
 * @brief Use testvector internally for HDCP2.x authentication
 *
 * @rst
 * Functional Requirements
 *   If the argc param is not 0, some HAL_HDCP2 functions should not make the
 *   values received from the argv argument. Set the argv[*] values to the
 *   Secure DRAM in order to use it at the HDCP2 authentication. If it's 0, do
 *   not use test vector. Clear Secure DRAM values and HAL_HDCP2 functions are
 *   operated as the Production(=user) mode.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   BSP should store an encrypted HDCP2 TX Key Set file in Secure Storage.
 *   It's located in the sedata partition as 'hdcp2_txroot' key id.
 *
 * Functions & Parameters
 *   argc [in] arguments count for the argv param.
 *   argv [in]
 *     argv[0] = LC128 value (16bytes)
 *     argv[1] = Km value (16bytes)
 *     argv[2] = Ks value (16bytes)
 *     argv[3] = seed for EME-OAEP encoding (32bytes)
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
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
int HAL_HDCP2_UseTestVector(unsigned int argc, void **argv);

/**
 * @brief Deprecated. see HAL_HDCP2_GetCertInfo2 instead
 *
 * @rst
 * Functional Requirements
 *   NA
 *
 * Responses to abnormal situations, including
 *   NA
 *
 * Performance Requirements
 *   NA
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   NA
 *
 * Return Value
 *   NA
 *
 * Example
 *   NA
 * @endrst
 */
int HAL_HDCP2_GetCertInfo(unsigned char *pReceiverID, unsigned char *pPubKey,
              unsigned char *pRootSign);

/**
 * @brief Read CertRx
 *
 * @rst
 * Functional Requirements
 *   Read the certification information(CertRx) of HDCP2 RX Key.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pReceiverID [out] HDCP2 RX ID.
 *   pPubKey [out] HDCP2 RX public key.
 *   pReserved [out] HDCP2 RX reserved bit.
 *   pRootSign [out] HDCP2 RX Root Signature.
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     guint8 receiver_id[LEN_RECEIVER_ID];
 *     guint8 kpubrx[LEN_KPUBRX];
 *     guint8 reserved[LEN_RESERVED];
 *     guint8 signature[LEN_SIGNATURE];
 *
 *     if (0 != HAL_HDCP2_GetCertInfo2(receiver_id, kpubrx, reserved, signature)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_GetCertInfo2(unsigned char *pReceiverID, unsigned char *pPubKey,
               unsigned char *pReserved, unsigned char *pRootSign);

/**
 * @brief Decrypt Ekpub_km using RSAES-OAEP scheme
 *
 * @rst
 * Functional Requirements
 *   It decrypts the km and stores the decrypted km to the secure store. All
 *   RSA decryption and Store data shall be in the Secure world. RSAES-OAEP
 *   encryption scheme must be used as defined by PKCS #1 V2.1:RAS Cryptography
 *   Standard. The mask generation function used is MGF1 which uses SHA-256 as
 *   its underlying hash function.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pEkpub_km [in] Encrypted km with kpubrx (128byte).
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Decrypt_RSAES_OAEP(pEkpub_km)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Decrypt_RSAES_OAEP(unsigned char *pEkpub_km);

/**
 * @brief Encrypt km using RSAES-OAEP scheme
 *
 * @rst
 * Functional Requirements
 *   Generate random km. And then encrypts km with kpubrx (Ekpub (km)).
 *   RSAES-OAEP encryption scheme must be used as defined by PKCS #1 V2.1: RSA
 *   Cryptography Standard. SHA-256 is the underlying hash function. The mask
 *   generation function used is MGF1 which uses SHA-256 as its underlying hash
 *   function.
 *
 *   If HAL_HDCP2_UseTestVector with argv != 0 is already called, use 'km'
 *   (i.e. argv[1] in HAL_HDCP2_UseTestVector) instead of generating random km
 *   value. And use 'seed' (i.e. argv[3] in HAL_HDCP2_UseTestVector) when
 *   making the dkmask by MGF1.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pEkpub_km [out] Encrypted km with kpubrx (128byte).
 *   pKpubrx [in] kpubrx value (131byte).
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Encrypt_RSAES_OAEP(pEkpub_km, pKpubrx)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Encrypt_RSAES_OAEP(unsigned char *pEkpub_km, unsigned char *pKpubrx);

/**
 * @brief Compute kd
 *
 * @rst
 * Functional Requirements
 *   It does a key derivation. It makes kd value in the secure world. Two times
 *   of AES-CTR crypto is required with different counter value.
 *   The HAL generates dkey0 and dkey1 using the ctr 0 and 1 respectively.
 *   kd = dkey0 || dkey1 (32 bytes). And derived kd is stored in secure stored.
 *   The execution time of the function should be less than 1ms.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 20ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pRtx [in] A 64bit random value generated in the HDCP 2 TX.
 *   pRrx [in] A 64bit random value generated in the HDCP 2 RX.
 *   version [in] This number indicates HDCP2.x version.
 *     If versionNumber == 0 or 1 (default) : AES-CTR(Km, pRtx || ctr)
 *     If versionNumber == 2 : AES-CTR(Km, pRtx || (pRrx XOR ctr))
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Kd_Key_Derivation(pRtx, pRrx, version)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Kd_Key_Derivation(unsigned char *pRtx, unsigned char *pRrx,
                unsigned int version);

/**
 * @brief Compute H'
 *
 * @rst
 * Functional Requirements
 *   It generates hash code using HMAC-SHA256.
 *    Key - kd (kd from secure DRAM).
 *    Key length - 32 bytes.
 *    Message length - 8 bytes.
 *    Target message - pRtx XOR Repeater [|| deviceOptionInfo].
 *    Output hashed value - pHPrime(32 bytes).
 *   The execution time of the function should be less than 1ms.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pHPrime [out] Output buffer.
 *   repeater [in] repeater flag (1byte) (0x00 or 0x01).
 *   pRtx [in] A random value (8bytes).
 *   deviceOptionInfo [in] Optional device info (6bytes).
 *     AKE_Receiver_Info.VERSION || AKE_Receiver_Info.RECEIVER_CAPABILITY_MASK
 *     || AKE_Transmitter_Info.VERSION || AKE_Transmitter_Info.TRANSMITTER_CAPABILITY_MASK
 *   version [in] This number indicates HDCP2.x version.
 *     If versionNumber == 0 or 1 :(default) HMAC-SHA256(pRtx XOR Repeater, kd)
 *     If versionNumber == 2 : HMAC-SHA256(pRtx XOR (Repeater || deviceOptionInfo), kd)
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Compute_H_Prime(pHPrime, repeater, pRtx, deviceOptionInfo, version)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Compute_H_Prime(unsigned char *pHPrime, unsigned char repeater,
                  unsigned char *pRtx,
                  unsigned char *deviceOptionInfo,
                  unsigned int version);

/**
 * @brief Compute L'
 *
 * @rst
 * Functional Requirements
 *   It generates hash code using HMAC-SHA256.
 *    Key - kd XOR pRrx (kd from secure DRAM).
 *    Key length - 32 bytes.
 *    Message length = 8 bytes.
 *    Target message - [pRn ||] pRn.
 *    Output hashed value - pLPrime(32 bytes).
 *   The execution time of the function should be less than 1ms.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 1ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pLPrime [out] Output buffer.
 *   pRn [in] A random value (8bytes).
 *   pRrx [in] A random value (8bytes).
 *   version [in] This number indicates HDCP2.x version.
 *     If versionNumber == 0 or 1 : (default) HMAC-SHA256(pRn, kd XOR pRrx)
 *     If versionNumber == 2 : HMAC-SHA256(pRn || pRn, kd XOR pRrx)
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Compute_L_Prime(pLPrime, pRn, pRrx, version)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Compute_L_Prime(unsigned char *pLPrime, unsigned char *pRn,
                  unsigned char *pRrx, unsigned int version);

/**
 * @brief Compute kh
 *
 * @rst
 * Functional Requirements
 *   Compute kh = SHA256(Kprivrx)[127:0]. Store the kh value between 0 and 127
 *   bit position into the secure DRAM.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   NA
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Compute_Kh()) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Compute_Kh(void);

/**
 * @brief Encrypt km using kh.
 *
 * @rst
 * Functional Requirements
 *   Encrypted Km value using kh key by AES mechanism. The execution time of
 *   the function should be less than 1ms.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pEkh_km [out] Output buffer.
 *   pM [in] Input message of AES crypto engine (16bytes).
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Encrypt_Km_using_Kh(pEkh_km, pM)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Encrypt_Km_using_Kh(unsigned char *pEkh_km, unsigned char *pM);

/**
 * @brief Decrypt Ekh_km using kh.
 *
 * @rst
 * Functional Requirements
 *   Decrypts ekh_km using AES with the received pM as input and kh as key into
 *   the AES module. Decrypted km must store to secure storage in the secure
 *   world.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pM [in] A random value generated in the HDCP 2.x TX
 *   ekh_km [in] An encrypted value generated in the HDCP 2.x TX
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Decrypt_Km_using_Kh(pM, ekh_km)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Decrypt_Km_using_Kh(unsigned char *pM, unsigned char *ekh_km);

/**
 * @brief Decrypt EKs
 *
 * @rst
 * Functional Requirements
 *   ks = Edkey(Ks) XOR (dkey2 XOR rrx). Decrypts ks using XOR operation with
 *   (dkey2 XOR rrx). Decrypted ks must store to secure storage in the secure
 *   world.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pEKs [in] A random value.
 *   pRtx [in] A random value.
 *   pRrx [in] A random value.
 *   pRn [in] A random value.
 *   version [in] This number indicates HDCP2.x version.
 *     If versionNumber == 0 or 1 : (default) AES-CTR(Km XOR rn, pRtx || ctr)
 *       IV of AES-CTR = pRtx || (00 00 00 00 00 00 00 02)
 *     If versionNumber == 2 : AES-CTR(Km XOR rn, pRtx || (pRrx XOR ctr))
 *       IV of AES-CTR = pRtx || (pRrx XOR 2)
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Decrypt_EKs(pEKs, pRtx, pRrx, pRn, version)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Decrypt_EKs(unsigned char *pEKs, unsigned char *pRtx,
              unsigned char *pRrx, unsigned char *pRn,
              unsigned int version);

/**
 * @brief Compute HMAC-SHA256 with kd.
 *
 * @rst
 * Functional Requirements
 *   pDest = HMAC-SHA256(pSrc, kd). Compute HMAC-SHA256 using the kd value as key
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pDest [out] Output buffer.
 *   pSrc [in] data to HAMC-SHA256.
 *   srcLength [in] The length of the pSrc.
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_HMAC_SHA256_with_kd(pDest, pSrc, srcLength)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_HMAC_SHA256_with_kd(unsigned char *pDest, unsigned char *pSrc, int srcLength);

/**
 * @brief Compute ks XOR lc128.
 *
 * @rst
 * Functional Requirements
 *   The lc128 is stored in Secure Storage. The ks is stored in the secure
 *   DRAM. Do XOR operation ks with lc128 and store the results in secure
 *   DRAM. If HAL_HDCP2_UseTestVector with argv != 0 is already called, do not
 *   read lc128 from secure storage.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   NA
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_XOR_Ks_with_LC128()) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_XOR_Ks_with_LC128(void);

/**
 * @brief Deprecated. Generate km.
 *
 * @rst
 * Functional Requirements
 *   Operation
 *    1. Generate random value for km  -16 byte
 *    2. Store the generated km value to secure storage
 *    3. Copy Km to pDB (LSB)
 *    4. XOR DB with Dbmask, result store in MaskedDB
 *    5. Adding padding 4 zero bytes
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   NA
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pMaskedDB [out] 99 bytes. XOR DB and DB mask, and adding 4bytes zero padding.
 *   pDB [in] 95 bytes. Temp DB value for RSA encryption.
 *   pDBMask [in] 95 bytes. calculated DB mask for RSA encryptionOutput.
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   NA
 * @endrst
 */
int HAL_HDCP2_Generate_Km(unsigned char *pMaskedDB, unsigned char *pDB,
              unsigned char *pDBMask);

/**
 * @brief Compute ks.
 *
 * @rst
 * Functional Requirements
 *   Operation
 *    1. Derivate dkey2
 *       1-1. XOR km and pRn(LSB). Use it  as key of AES-CTR
*        1-2. Do AES-CTR (see the description of version param)
 *    2. XOR dkey2 with pRrx (LSB)
 *    3. Generate 16 byte random value (Ks)
 *       If HAL_HDCP2_UseTestVector with argv != 0 is already called, use ks
 *       from Secure DRAM instead of generating random number
 *    4. Store Ks to secure storage
 *    5. XOR Ks with (dkey2 XOR pRrx)
 *    6. Store result to pEks
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pEks [out] 99 bytes. XOR DB and DB mask, and adding 4bytes zero padding.
 *   pRrx [in] 95 bytes. Temp DB value for RSA encryption.
 *   pRtx [in] 95 bytes. calculated DB mask for RSA encryptionOutput.
 *   pRn [in] 95 bytes. calculated DB mask for RSA encryptionOutput.
 *   version [in] This number indicates HDCP2.x version.
 *     If versionNumber == 0 or 1 : (default) AES-CTR(Km, pRtx || ctr)
 *       IV of AES-CTR = pRtx || (00 00 00 00 00 00 00 02)
 *     If versionNumber == 2 : AES-CTR(Km, pRtx || (pRrx XOR ctr))
 *       IV of AES-CTR = pRtx || (pRrx XOR 2)
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Generate_Ks(pEks, pRrx, pRtx, pRn, version)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Generate_Ks(unsigned char *pEks, unsigned char *pRrx,
              unsigned char *pRtx, unsigned char *pRn,
              unsigned int version);

/**
 * @brief Store km.
 *
 * @rst
 * Functional Requirements
 *   Store current kmData to selected StoredKm slot. the stored km must not be
 *   accessed by user. Stored Km values must be stored permanently in secure
 *   world.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   index [in] Index of StoredKm slot.
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Write_StoredKm(index)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Write_StoredKm(int index);

/**
 * @brief Select km.
 *
 * @rst
 * Functional Requirements
 *   Select StoredKm slot and reload the StoredKm to current kmData. It will
 *   be used current HDCP2.x authentication.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   index [in] Index of StoredKm slot.
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Select_StoredKm(index)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Select_StoredKm(int index);

/**
 * @brief Operate SHA-256.
 *
 * @rst
 * Functional Requirements
 *   Operate SHA-256.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pOutputBuf [out] Output buffer.
 *   pInputBuf [in] A input message.
 *   length [in] The input message length.
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_SHA256(pOutputBuf, pInputBuf, length)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_SHA256(unsigned char *pOutputBuf, unsigned char *pInputBuf,
             int length);

/**
 * @brief Deprecated. Operate a AES_CTR function with CTR mode.
 *
 * @rst
 * Functional Requirements
 *   Deprecated. Operate a AES_CTR function with CTR mode.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pOutputBuf [out] Output buffer.
 *   pInputBuf [in] A input message.
 *   length [in] The input message length.
 *   pKey [in] A key value.
 *   keyLength [in] The key value length.
 *   pCounter [in] A CTR value.
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_AES_CTR(pOutputBuf, pInputBuf, length, pKey, keyLength, pCounter)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_AES_CTR(unsigned char *pOutputBuf, unsigned char *pInputBuf,
              int length, unsigned char *pKey, int keyLength,
              unsigned char *pCounter);

/**
 * @brief Get protected decryption key
 *
 * @rst
 * Functional Requirements
 *   Get protected decryption key (Ks XOR LC128). It should be encrypted.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pData [out] Protected decryption Key for Ks XOR LC128.
 *     The key should be encrypted securely by using BSP own method.
 *     The length of pData MUST be 32.
 *   pLength [in/out]
 *     in: It should be 32, because the max size of pData buffer is 32.
 *     out: the size of protected decryption key. The output length MUST be 32.
 * @return Zero(0) if the function success, non-Zero otherwise.
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_GetProtectedDecryptionKey(pData, pLength)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_GetProtectedDecryptionKey(unsigned char *pData, int *pLength);

/**
 * @brief set protected decryption key
 *
 * @rst
 * Functional Requirements
 *   Set protected decryption key (Ks XOR LC128). It can be executed the other
 *   process with HAL_HDCP2_GetProtectedDecryptionKey function.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pData [out] Protected decryption Key for Ks XOR LC128. The length of pData MUST be 32.
 *   length [in]: The output size from HAL_HDCP2_GetProtectedDecryptionKey function. It MUST be 32.
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_SetProtectedDecryptionKey(pData, length)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_SetProtectedDecryptionKey(unsigned char *pData, int length);

/**
 * @brief Decrypt data
 *
 * @rst
 * Functional Requirements
 *   Decrypt message in input buffer using ks_XOR_lc128
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pOutputbuf [out] Output buffer.
 *   pInputbuf [in] Encrypted data.
 *   length [in] The length of the pInputbuf.
 *   pCounter [in] IV(initialization vector)
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Data_Decrypt(pOutputbuf, pInputbuf, length, pCounter)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Data_Decrypt(unsigned char *pOutputbuf, unsigned char *pInputbuf,
               int length, unsigned char *pCounter);

/**
 * @brief Encrypt data
 *
 * @rst
 * Functional Requirements
 *   Encrypt message in input buffer using ks_XOR_lc128. It is equal to the
 *   HAL_HDCP2_Data_Decrypt function except it’s operated in the secure world.
 *   If the length is not an integer multiple of 16 bytes, replace the last
 *   (length % 16) bytes as 0x00.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pOutputbuf [out] Point to the user allocated buffer. The encrypted data is located in this buffer.
 *   pInputbuf [in] The plain data. It's an address for secure memory. User cannot access this address.
 *   length [in] The length of the pInputbuf. The length should be multiple of 16 bytes.
 *   pCounter [in] IV(initialization vector). It's (riv XOR streamCtr) || inputCtr.
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Data_Encrypt(pOutputbuf, pInputbuf, length, pCounter)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Data_Encrypt(unsigned char *pOutputBuf, unsigned char *pInputBuf,
               int length, unsigned char *pCounter);

/**
 * @brief Compute V prime
 *
 * @rst
 * Functional Requirements
 *   HDCP2.0:
 *    pRxIdListsInfo = Receiver ID list || DEPTH || DEVICE_COUNT ||
 *     MAX_DEVS_EXCEEDED || MAX_CASCADE_EXCEEDED
 *    infoLength = 5*DEVIDE_INFO + 1 + 1 + 1 + 1
 *
 *   HDCP2.1 or upper version:
 *    pRxIdListsInfo = Receiver ID list || DEPTH || DEVICE_COUNT ||
 *     MAX_DEVS_EXCEEDED || MAX_CASCADE_EXCEEDED ||
 *     HDCP2_LEGACY_DEVICE_DOWNSTREAM || HDCP1_DEVICE_DOWNSTREAM
 *    infoLength = 5*DEVICE_INFO + 1 + 1 + 1 + 1 + 1 + 1
 *
 *   V' = HMAC-SHA256(pRxIdListsInfo, kd). Write result V_prime value to pVPrime buffer
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pVPrime [out] Output buffer.
 *   pRxIdListsInfo [in] The information of the RX ID lists.
 *   infoLength [in] The length of the pRxIdListInfo.
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Compute_V_Prime(pVPrime, pRxIdListsInfo, infoLength)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Compute_V_Prime(unsigned char *pVPrime,
                  unsigned char *pRxIdListsInfo, int infoLength);

/**
 * @brief Compute M prime
 *
 * @rst
 * Functional Requirements
 *   StreamManageInfo = STREAMID_TYPE || seq_num_M
 *   STREAMID_TYPE = streamCtr1 || ContentStreamID1 || Type || streamCtr2 ||
 *    ContentStreamID2 || Type || ... || streamCtrk || ContentStreamIDk || Type
 *
 *   M' = HMAC-SHA256(StreamManageInfo, SHA256(kd)). Write result M_prime value
 *   to pVPrime buffer
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the BSP should return an non-Zero.
 *
 * Performance Requirements
 *   The response time of this function should be within 10ms.
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   pMPrime [out] Output buffer.
 *   pStreamManageInfo [in] StreamManageInfo
 *   infoLength [in] The length of the pStreamManageInfo. ( 4 + 2 + 1 ) * k
 *
 * Return Value
 *   Zero(0) if the function success, non-Zero otherwise.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if (0 != HAL_HDCP2_Compute_V_Prime(pMPrime, pStreamManageInfo, infoLength)) {
 *         // handling error
 *     }
 * @endrst
 */
int HAL_HDCP2_Compute_M_Prime(unsigned char *pMPrime,
                  unsigned char *pStreamManageInfo, int infoLength);

/**
 * @brief Deprecated.
 *
 * @rst
 * Functional Requirements
 *   NA
 *
 * Responses to abnormal situations, including
 *   NA
 *
 * Performance Requirements
 *   NA
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   NA
 *
 * Return Value
 *   NA
 *
 * Example
 *   NA
 * @endrst
 */
int HAL_HDCP2_HMAC_SHA256(unsigned char *pOutputBuf, unsigned char *pInputBuf,
              int length, unsigned char *pkey, int keylength);

/**
 * @brief Deprecated.
 *
 * @rst
 * Functional Requirements
 *   NA
 *
 * Responses to abnormal situations, including
 *   NA
 *
 * Performance Requirements
 *   NA
 *
 * Constraints
 *   NA
 *
 * Functions & Parameters
 *   NA
 *
 * Return Value
 *   NA
 *
 * Example
 *   NA
 * @endrst
 */
int HAL_HDCP2_SHA1(unsigned char *pOutputBuf, unsigned char *pInputBuf,
           int length);

#endif                /* _COMMON_HAL_HDCP2_H_ */
