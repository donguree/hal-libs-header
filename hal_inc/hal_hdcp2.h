/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999-2016 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file 		hal_hdcp2.h
 *
 *  header of Common Interface HAL Fuction.
 *
 *
 *  @author		kyungnam.bae
 *  @version	1.0
 *  @date		2013.3.5
 *  @date
 *  @note		Additional information.
 *  @see
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
/* HDCP2 */

/**
 * HAL_HDCP2_WriteKeySet
 * @pKeySet: [in] 858 bytes HDCP2 Key Set.
 *	LC128(16) + Receiver ID(5) + Device public Key(131) + reserved bit(2) +
 *	Root Signature(384) + Device Private Key(320)
 * @dst_file_path: [in] (Ignore it if the secure storage is supported)
 *	storage path for the encrypted hdcp2 key.
 * @keyLength: [in] (Ignore it if the secure storage is supported)
 *	The length of the pKeySet. it should be 858.
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Encrypt HDCP2 RX Key Set(pKeySet) and Write Encrypted HDCP2 Key Set(pKeySet)
 *	into Secured Storage. If the platform does not support Secure Storage,
 *	write the file into the path of the dst_file_path param.
 */
int HAL_HDCP2_WriteKeySet(unsigned char *pKeySet, unsigned char *dst_file_path,
			  int keyLength);

/**
 * HAL_HDCP2_GetEncHdcp2Key
 * @pEncHdcp2Key: [out] Encrypted HDCP2 RX Key Set buffer.
 *	(Or it can be the platform specific value.)
 * @src_file_path: [in] Path of the encrypted HDCP2 RX Key file.
 * @pEncKeyLength: [out] Encrypted HDCP2 RX Key Size (Or the length of
 *	the platform specific value. the MAX Length = 900).
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Ignore the function if Secure Storage is supported. Get the Encrypted HDCP2
 *	RX Key from Secure Storage and write this to the buffer.
 */
int HAL_HDCP2_GetEncHdcp2Key(unsigned char *pEncHdcp2Key,
			     unsigned char *src_file_path,
			     unsigned char *pEncKeyLength);

/**
 * HAL_HDCP2_SetEncHdcp2Key
 * @pEncHdcp2Key: [in] Output value of HAL_HDCP2_GetEncHdcp2Key function.
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Ignore the function if Secure Storage is supported.
 * Set the encrypted HDCP2 RX Key to trust zone.
 */
int HAL_HDCP2_SetEncHdcp2Key(unsigned char *pEncHdcp2Key);

/**
 * HAL_HDCP2_GetRootPublicKey
 * @pRootPublicKey: [out] A decrypted Root Public Key (= Kpubdcp).
 * @src_file_path: [in] (Ignore it if the secure storage is supported)
 *	An encrypted TX Key Set file path.
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * pre-condition
 *	SoC should store an encrypted HDCP2 TX Key Set file in Secure Storage
 *	or a specific path.
 * Operation
 *	1. Decrypt an encrypted TX Key Set located in src_file_path.
 *	2. Operate SHA1 for validating Root Public Key.
 *	3. Set value to the pRootPublicKey variable.
 */
int HAL_HDCP2_GetRootPublicKey(unsigned char *pRootPublicKey,
			       unsigned char *src_file_path);

/**
 * HAL_HDCP2_UseTestVector
 * @argc: [in] arguments count for the argv param.
 * @argv: [in]
 *  argv[0] = LC128 value (16bytes)
 *  argv[1] = Km value (16bytes)
 *  argv[2] = Ks value (16bytes)
 *  argv[3] = seed for EME-OAEP encoding (32bytes)
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * If the argc param is not 0, some HAL_HDCP2* functions should not make the values
 * received from the argv argument. Set the argv[*] values to the Secure DRAM
 * in order to use it at the HDCP2 authentication.
 * If it's 0, do not use test vector. Clear Secure DRAM values and
 * HAL_HDCP2* functions are operated as the Production(=user) mode.
 */
int HAL_HDCP2_UseTestVector(unsigned int argc, void **argv);

/**
 * HAL_HDCP2_GetCertInfo has been deprecated and should not be used in
 *	newly-written code. Just use HAL_HDCP2_GetCertInfo2().
 */
int HAL_HDCP2_GetCertInfo(unsigned char *pReceiverID, unsigned char *pPubKey,
			  unsigned char *pRootSign);

/**
 * HAL_HDCP2_GetCertInfo2
 * @pReceiverID: [out] HDCP2 RX ID.
 * @pPubKey: [out] HDCP2 RX public key.
 * @pReserved: [out] HDCP2 RX reserved bit.
 * @pRootSign: [out] HDCP2 RX Root Signature.
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Read the certification information(CertRx) of HDCP2 RX Key.
 * The execution time of the function (=performance) should be less than 20ms.
 */
int HAL_HDCP2_GetCertInfo2(unsigned char *pReceiverID, unsigned char *pPubKey,
			   unsigned char *pReserved, unsigned char *pRootSign);

/**
 * HAL_HDCP2_Decrypt_RSAES_OAEP
 * @pEkpub_km: [in] Encrypted km with kpubrx (128byte).
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * It decrypts the km and stores the decrypted km to the secure store.
 * All RSA decryption and Store data shall be in the Secure world.
 * RSAES-OAEP encryption scheme must be used as defined by
 *	PKCS #1 V2.1:RAS Cryptography Standard. The mask generation function used
 *	is MGF1 which uses SHA-256 as its underlying hash function.
 * The execution time of the function (=performance) should be less than 50ms.
 */
int HAL_HDCP2_Decrypt_RSAES_OAEP(unsigned char *pEkpub_km);

/**
 * HAL_HDCP2_Encrypt_RSAES_OAEP
 * @pEkpub_km: [out] Encrypted km with kpubrx (128byte).
 * @pKpubrx: [in] kpubrx value (131byte).
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Encrypts km with kpubrx (Ekpub (km)).
 * RSAES-OAEP encryption scheme must be used as defined by PKCS #1 V2.1:
 * RSA Cryptography Standard. SHA-256 is the underlying hash function.
 * The mask generation function used is MGF1 which uses SHA-256 as its
 * underlying hash function.
 *
 * If HAL_HDCP2_UseTestVector with argv != 0 is already called, use 'km'
 * (i.e. argv[1] in HAL_HDCP2_UseTestVector) instead of generating
 * random km value and 'seed' (i.e. argv[3] in HAL_HDCP2_UseTestVector)
 * when making the dkmask by MGF1.
 */
int HAL_HDCP2_Encrypt_RSAES_OAEP(unsigned char *pEkpub_km, unsigned char *pKpubrx);

/**
 * HAL_HDCP2_Kd_Key_Derivation
 * @pRtx: [in] A 64bit random value generated in the HDCP 2 TX.
 * @pRrx: [in] A 64bit random value generated in the HDCP 2 RX.
 * @version: [in] This number indicates HDCP2.x version.
 *	If versionNumber == 0 or 1 (default) : AES-CTR(Km, pRtx || ctr)
 *	If versionNumber == 2 : AES-CTR(Km, pRtx || (pRrx XOR ctr))
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * It does a key derivation. It makes kd value in the secure world.
 * Two times of AES-CTR crypto is required with different counter value.
 * The HAL generates dkey0 and dkey1 using the ctr 0 and 1 respectively.
 *	Kd = dkey0 || dkey1 (32 bytes). And derived kd is stored in secure stored.
 * The execution time of the function (=performance) should be less than 1ms.
 */
int HAL_HDCP2_Kd_Key_Derivation(unsigned char *pRtx, unsigned char *pRrx,
				unsigned int version);

/**
 * HAL_HDCP2_Compute_H_Prime
 * @pHPrime: [out] Output buffer.
 * @repeater: [in] repeater flag (1byte) (0x00 or 0x01).
 * @pRtx: [in] A random value (8bytes).
 * @deviceOptionInfo: [in] Optional device info (6bytes).
 *	AKE_Receiver_Info.VERSION || AKE_Receiver_Info.RECEIVER_CAPABILITY_MASK ||
 *	AKE_Transmitter_Info.VERSION ||
 *	AKE_Transmitter_Info.TRANSMITTER_CAPABILITY_MASK
 * @version: [in] This number indicates HDCP2.x version.
 *	If versionNumber == 0 or 1 : (default) HMAC-SHA256(pRtx XOR Repeater, kd)
 *	If versionNumber == 2 : HMAC-SHA256(pRtx XOR (Repeater || deviceOptionInfo), kd)
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * It generates hash code using HMAC-SHA256.
 *	Key - kd (kd from secure DRAM).
 *	Key length - 32 bytes.
 *	Message length - 8 bytes.
 *	Target message - pRtx XOR Repeater [|| deviceOptionInfo].
 *	Output hashed value - pHPrime(32 bytes).
 * The execution time of the function (=performance) should be less than 1ms.
 */
int HAL_HDCP2_Compute_H_Prime(unsigned char *pHPrime, unsigned char repeater,
			      unsigned char *pRtx,
			      unsigned char *deviceOptionInfo,
			      unsigned int version);

/**
 * HAL_HDCP2_Compute_L_Prime
 * @pLPrime: [out] Output buffer.
 * @pRn: [in] A random value (8bytes).
 * @pRrx: [in] A random value (8bytes).
 * @version: [in] This number indicates HDCP2.x version.
 *	If versionNumber == 0 or 1 : (default) HMAC-SHA256(pRn, kd XOR pRrx)
 *	If versionNumber == 2 : HMAC-SHA256(pRn || pRn, kd XOR pRrx)
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * It generates hash code using HMAC-SHA256.
 *	Key - kd XOR pRrx (kd from secure DRAM).
 *	Key length - 32 bytes.
 *	Message length = 8 bytes.
 *	Target message - [pRn ||] pRn.
 *	Output hashed value - pLPrime(32 bytes).
 * The execution time of the function (=performance) should be less than 1ms.
 */
int HAL_HDCP2_Compute_L_Prime(unsigned char *pLPrime, unsigned char *pRn,
			      unsigned char *pRrx, unsigned int version);

/**
 * HAL_HDCP2_Compute_Kh
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Compute kh = SHA256(Kprivrx)[127:0].
 * Store the kh value between 0 and 127 bit position into the secure DRAM.
 */
int HAL_HDCP2_Compute_Kh(void);

/**
 * HAL_HDCP2_Encrypt_Km_using_Kh
 * @pEkh_km: [out] Output buffer.
 * @pM: [in] Input message of AES crypto engine (16bytes).
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Encrypted Km value using kh key by AES mechanism.
 * The execution time of the function (=performance) should be less than 1ms.
 */
int HAL_HDCP2_Encrypt_Km_using_Kh(unsigned char *pEkh_km, unsigned char *pM);

/**
 * HAL_HDCP2_Decrypt_Km_using_Kh
 * @pM: [in] A random value generated in the HDCP 2.0 TX
 * @ekh_km: [in] An encrypted value generated in the HDCP 2.0 TX
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Decrypts ekh_km using AES with the received pM as input and kh as key into
 *	the AES module. Decrypted km must store to secure storage in the secure
 *	world.
 */
int HAL_HDCP2_Decrypt_Km_using_Kh(unsigned char *pM, unsigned char *ekh_km);

/**
 * HAL_HDCP2_Decrypt_EKs
 * @pEKs: [in] A random value.
 * @pRtx: [in] A random value.
 * @pRrx: [in] A random value.
 * @pRn: [in] A random value.
 * @version: [in] This number indicates HDCP2.x version.
 *	If versionNumber == 0 or 1 : (default) AES-CTR(Km XOR rn, pRtx || ctr)
 *		IV of AES-CTR = pRtx || (00 00 00 00 00 00 00 02)
 *	If versionNumber == 2 : AES-CTR(Km XOR rn, pRtx || (pRrx XOR ctr))
 *		IV of AES-CTR = pRtx || (pRrx XOR 2)
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * ks = Edkey(Ks) XOR (dkey2 XOR rrx).
 * Decrypts ks using XOR operation with (dkey2 XOR rrx).
 * Decrypted ks must store to secure storage in the secure world.
 */
int HAL_HDCP2_Decrypt_EKs(unsigned char *pEKs, unsigned char *pRtx,
			  unsigned char *pRrx, unsigned char *pRn,
			  unsigned int version);

/**
 * HAL_HDCP2_HMAC_SHA256_with_kd
 * @pDest: [out] Output buffer.
 * @pSrc: [in] data to HAMC-SHA256.
 * @srcLength: [in] The length of the pSrc.
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * pDest = HMAC-SHA256(pSrc, kd)
 * Compute HMAC-SHA256 using the kd value as key
 */
int HAL_HDCP2_HMAC_SHA256_with_kd(unsigned char *pDest, unsigned char *pSrc, int srcLength);

/**
 * HAL_HDCP2_XOR_Ks_with_LC128
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * The lc128 is stored in Secure Storage.
 * The ks is stored in the secure DRAM.
 * Do XOR operation ks with lc128 and the results is stored in secure DRAM.
 */
int HAL_HDCP2_XOR_Ks_with_LC128(void);

/**
 * HAL_HDCP2_Generate_Km
 * @pMaskedDB: [out] 99 bytes. XOR DB and DB mask, and adding 4bytes zero padding.
 * @pDB: [in] 95 bytes. Temp DB value for RSA encryption.
 * @pDBMask: [in] 95 bytes. calculated DB mask for RSA encryptionOutput.
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Operation
 *	1. Generate random value for km  -16 byte
 *	2. Store the generated km value to secure storage
 *	3. Copy Km to pDB (LSB)
 *	4. XOR DB with Dbmask, result store in MaskedDB
 *	5. Adding padding 4 zero bytes
 */
int HAL_HDCP2_Generate_Km(unsigned char *pMaskedDB, unsigned char *pDB,
			  unsigned char *pDBMask);

/**
 * HAL_HDCP2_Generate_Ks
 * @pEks: [out] 99 bytes. XOR DB and DB mask, and adding 4bytes zero padding.
 * @pRrx: [in] 95 bytes. Temp DB value for RSA encryption.
 * @pRtx: [in] 95 bytes. calculated DB mask for RSA encryptionOutput.
 * @pRn: [in] 95 bytes. calculated DB mask for RSA encryptionOutput.
 * @version: [in] This number indicates HDCP2.x version.
 *	If versionNumber == 0 or 1 : (default) AES-CTR(Km, pRtx || ctr)
 *		IV of AES-CTR = pRtx || (00 00 00 00 00 00 00 02)
 *	If versionNumber == 2 : AES-CTR(Km, pRtx || (pRrx XOR ctr))
 *		IV of AES-CTR = pRtx || (pRrx XOR 2)
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Operation
 *	1. XOR dkey2 with pRrx (LSB)
 *	2. Generate 16 byte random value (Ks)
 *	3. Store Ks to secure storage
 *	4. XOR Ks with (dkey2 XOR pRrx)
 *	5. Store result to pEks
 */
int HAL_HDCP2_Generate_Ks(unsigned char *pEks, unsigned char *pRrx,
			  unsigned char *pRtx, unsigned char *pRn,
			  unsigned int version);

/**
 * HAL_HDCP2_Write_StoredKm
 * @index: [in] Index of StoredKm slot.
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Store current kmData to selected StoredKm slot.
 */
int HAL_HDCP2_Write_StoredKm(int index);

/**
 * HAL_HDCP2_Select_StoredKm
 * @index: [in] Index of StoredKm slot.
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Select StoredKm slot and reload the StoredKm to current kmData.
 */
int HAL_HDCP2_Select_StoredKm(int index);

/**
 * HAL_HDCP2_SHA256
 * @pOutputBuf: [out] Output buffer.
 * @pInputBuf: [in] A input message.
 * @length: [in] The input message length.
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Operate SHA-256.
 */
int HAL_HDCP2_SHA256(unsigned char *pOutputBuf, unsigned char *pInputBuf,
		     int length);

/**
 * HAL_HDCP2_AES_CTR
 * @pOutputBuf: [out] Output buffer.
 * @pInputBuf: [in] A input message.
 * @length: [in] The input message length.
 * @pKey: [in] A key value.
 * @keyLength: [in] The key value length.
 * @pCounter: [in] A CTR value.
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Operate a AES_CTR function with CTR mode.
 */
int HAL_HDCP2_AES_CTR(unsigned char *pOutputBuf, unsigned char *pInputBuf,
		      int length, unsigned char *pKey, int keyLength,
		      unsigned char *pCounter);

/**
 * HAL_HDCP2_GetProtectedDecryptionKey
 * @pData: [out] Protected decryption Key for Ks XOR LC128.
 *	The key should be encrypted securely by using SoC own method.
 *	The length of pData MUST be 32.
 * @pLength: [in/out]
 *	in: It should be 32, because the max size of pData buffer is 32.
 *	out: the size of protected decryption key. The output length MUST be 32.
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Get protected decryption key (Ks XOR LC128). It should be encrypted.
 */
int HAL_HDCP2_GetProtectedDecryptionKey(unsigned char *pData, int *pLength);

/**
 * HAL_HDCP2_SetProtectedDecryptionKey
 * @pData: [out] Protected decryption Key for Ks XOR LC128. The length of pData MUST be 32.
 * @length: [in]: The output size from HAL_HDCP2_GetProtectedDecryptionKey function. It MUST be 32.
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Set protected decryption key (Ks XOR LC128)
 * It can be executed the other process with HAL_HDCP2_GetProtectedDecryptionKey function.
 */
int HAL_HDCP2_SetProtectedDecryptionKey(unsigned char *pData, int length);

/**
 * HAL_HDCP2_Data_Decrypt
 * @pOutputbuf: [out] Output buffer.
 * @pInputbuf: [in] Encrypted data.
 * @length: [in] The length of the pInputbuf.
 * @pCounter: [in] IV(initialization vector)
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Decrypt message in input buffer using ks_XOR_lc128
 */
int HAL_HDCP2_Data_Decrypt(unsigned char *pOutputbuf, unsigned char *pInputbuf,
			   int length, unsigned char *pCounter);

/**
 * HAL_HDCP2_Data_Encrypt
 * @pOutputbuf: [out] Output buffer.
 * @pInputbuf: [in] Decrypted data.
 * @length: [in] The length of the pInputbuf. The length should be multiple of 16 bytes.
 * @pCounter: [in] IV(initialization vector)
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * Encrypt message in input buffer using ks_XOR_lc128
 * If the length is not an integer multiple of 16 bytes,
 *	replace the last (length % 16) bytes as 0x00.
 */
int HAL_HDCP2_Data_Encrypt(unsigned char *pOutputBuf, unsigned char *pInputBuf,
			   int length, unsigned char *pCounter);

/**
 * HAL_HDCP2_Compute_V_Prime
 * @pVPrime: [out] Output buffer.
 * @pRxIdListsInfo: [in] The information of the RX ID lists.
 * @infoLength: [in] The length of the pRxIdListInfo.
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * HDCP2.0:
 *	pRxIdListsInfo = Receiver ID list || DEPTH || DEVICE_COUNT ||
 *		MAX_DEVS_EXCEEDED || MAX_CASCADE_EXCEEDED
 *	infoLength = 5*DEVIDE_INFO + 1 + 1 + 1 + 1
 *
 * HDCP2.1 or upper version:
 *	pRxIdListsInfo = Receiver ID list || DEPTH || DEVICE_COUNT ||
 *		MAX_DEVS_EXCEEDED || MAX_CASCADE_EXCEEDED ||
 *		HDCP2_LEGACY_DEVICE_DOWNSTREAM || HDCP1_DEVICE_DOWNSTREAM
 *	infoLength = 5*DEVICE_INFO + 1 + 1 + 1 + 1 + 1 + 1
 *
 * V' = HMAC-SHA256(pRxIdListsInfo, kd)
 * Write result V_prime value to pVPrime buffer
 */
int HAL_HDCP2_Compute_V_Prime(unsigned char *pVPrime,
			      unsigned char *pRxIdListsInfo, int infoLength);

/**
 * HAL_HDCP2_Compute_M_Prime
 * @pMPrime: [out] Output buffer.
 * @pStreamManageInfo: [in] StreamManageInfo
 * @infoLength: [in] The length of the pStreamManageInfo. ( 4 + 2 + 1 ) * k
 * Returns: Zero(0) if the function success, non-Zero otherwise.
 *
 * StreamManageInfo = STREAMID_TYPE || seq_num_M
 *	STREAMID_TYPE = streamCtr1 || ContentStreamID1 || Type || streamCtr2 ||
 *		ContentStreamID2 || Type || ... || streamCtrk || ContentStreamIDk || Type
 *
 * M' = HMAC-SHA256(StreamManageInfo, SHA256(kd))
 * Write result M_prime value to pVPrime buffer
 */
int HAL_HDCP2_Compute_M_Prime(unsigned char *pMPrime,
			      unsigned char *pStreamManageInfo, int infoLength);

/**
 * HAL_HDCP2_HMAC_SHA256 has been deprecated.
 */
int HAL_HDCP2_HMAC_SHA256(unsigned char *pOutputBuf, unsigned char *pInputBuf,
			  int length, unsigned char *pkey, int keylength);

/**
 * HAL_HDCP2_SHA1 has been deprecated.
 */
int HAL_HDCP2_SHA1(unsigned char *pOutputBuf, unsigned char *pInputBuf,
		   int length);

#endif				/* _COMMON_HAL_HDCP2_H_ */
