Crypto
==========

History
-------

======= ========== ============== =======
Version Date       Changed by     Comment
======= ========== ============== =======
1.0.0   2022.07.28 hedaesik.kim   Add new document
1.1.0   2023.09.05 hwachin.lee    Add function for google cast
======= ========== ============== =======

Overall Description
--------------------

Provision the encrypted injection key injected from the factory to the TEE secure storage.
TEE supports encryption and decryption.
Trigger the operation of the specific TAs.

webOS Secure Store (Platform Layer Secure Store)

  - Until webOS 3.0, webOS platform uses only SoC implemented Secure Store, but from webOS 4.0, webOS secure store that uses TEE cryptographic functions but not specific to SoC implementation.
    Therefore almost sedata keys and the other run-time generated keys will be stored in webOS secure store. But several keys should be directly accessed by SoC, not via upper layer (webOS secure store APIs),
    to comply with a CP or DRM security regulations, for example, playready keys, Netflix keys. So, the existing SoC secure store should be also provided. It will use same emmc partition and same structure,
    but many HAL APIs to read sedata keys in secure store will be deprecated.
    For the webOS secure store, several additional HAL APIs should be provided and their API specification is described in http://collab.lge.com/main/pages/viewpage.action?pageId=517788406.
    In HAL_CRYPTO, several new APIs for the new webOS secure store are also introduced. They will be used for crypto operations with webOS secure store keys not being exposed to REE by passing the protected keys to API.

SoC Secure Store

  - Netflix and vudu keys will be stored in SoC Secure Store because their keys should be directly accessed by TEE. Several playready keys are also stored in SoC Secure Store.

Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

================================= ======================================
Definition                        Description
================================= ======================================
Device Unique Key (DUK)           The key that is unique per device. Every secure store keys are encrypted by their own unique
                                  "key encryption key(KEK)" and the KEK is also encrypted by the DUK. That is, this is an anchor point to chain of trust in TEE and
                                  the root of every key chains of secure store keys. This is also called OTP key because it is stored in OTP memory. In this document, we call it DUK.

SecureData                        The result from encrypting data using TEE Crypto API. The encryption key(SDEK) is unique key that is randomly generated per SecureData
                                  when requested and encrypted by DUK. The SecureData includes the encryption result and the encrypted SDEK (Protected SDEK).
ecureData Encryption Key (SDEK)   The key encryption key to be used to make a SecureData (encrypt data).
                                  This key is randomly generated each time that making SecureData is requested.
SecureData HMAC Key (SDHK)        The HMAC Key to be used to generate and verify HMAC value of Secure Data.
                                  This key is randomly generated each time that HMAC generation API is called. The key size is 32 bytes.
Protected SDEK                    The encrypted SDEK ( EDUK(SDEK) ). This data is attached in front of SecureData, and used to decrypt SecureData in TEE.
Protected SDHK                    The encrypted SDHK ( EDUK(SDHK) ).
================================= ======================================

System Context
^^^^^^^^^^^^^^

NA

Performance Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^

Please refer to the performance requirements of each API function.

Design Constraints
^^^^^^^^^^^^^^^^^^^

Please refer to the constraints of each API function.

Functional Requirements
-----------------------

The data types and functions used in this module are as follows.

Data Types
^^^^^^^^^^^^
Please refer to the each API function.

Function Calls
^^^^^^^^^^^^^^^
  * :cpp:func:`HAL_CRYPTO_WriteSecureData`
  * :cpp:func:`HAL_CRYPTO_NF_GetESN`
  * :cpp:func:`HAL_CRYPTO_NF_Encrypt`
  * :cpp:func:`HAL_CRYPTO_NF_Decrypt`
  * :cpp:func:`HAL_CRYPTO_NF_Encrypt_Ex`
  * :cpp:func:`HAL_CRYPTO_NF_Decrypt_Ex`
  * :cpp:func:`HAL_CRYPTO_NF_WriteAppData`
  * :cpp:func:`HAL_CRYPTO_NF_ReadAppData`
  * :cpp:func:`HAL_CRYPTO_NF_Operate`
  * :cpp:func:`HAL_CRYPTO_NF_Init`
  * :cpp:func:`HAL_CRYPTO_NF_CleanUp`
  * :cpp:func:`HAL_CRYPTO_NF_DestroyContext`
  * :cpp:func:`HAL_CRYPTO_NYX_AES_GenerateSecureKey` //except from socts, The function owner is unknown by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_NYX_AES_CryptCBC` //except from socts, The function owner is unknown by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_NYX_RSA_TransformSecureKey` //except from socts, The function owner is unknown by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_NYX_RSA_Crypt` //except from socts, The function owner is unknown by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_NYX_RSA_ExportPublicKey` //except from socts, The function owner is unknown by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_Debug` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_SFU_Initialize` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_SFU_Finalize` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_SFU_GetRSAKey` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_SFU_GetAESKey` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_ReadMskToSecureStore` //except from socts, The function owner is unknown and this is not used in DILE by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_WriteMskToSecureStore` //except from socts, The function owner is unknown and this is not used in DILE by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_ReadNLPSecret` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_BBC_ReadClientKey` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_ReadPrsSecret` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_CIPLUS_GetCiPlusSslPubKey` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_CI_PLUS_GetCiPlusSslPubKey`
  * :cpp:func:`HAL_CRYPTO_CI_PLUS_GetCiPlusStdKey`
  * :cpp:func:`HAL_CRYPTO_CI_PLUS_GetCiPlusDhKey`
  * :cpp:func:`HAL_CRYPTO_GetDebugKey` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_ReadDVRDeviceSecret`
  * :cpp:func:`HAL_CRYPTO_WriteDVRDeviceSecret`
  * :cpp:func:`HAL_CRYPTO_TNM_ReadSecretKey` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_TNM_WriteSecretKey` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_HYBRIDCAST_ReadSecret` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_CIPLUS_GetCiCanalReadyKey` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_Multiple_ReadClientKey` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_ReadSkypeSecret` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_ReadRemoteDiagSecret` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_SDI_ReadPrivKeyAndID` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_ReadRDXSecret` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_SDP_ReadCommonKey` //except from socts, The function owner is unknown and this is not used in DILE by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_TWINTV_ReadSecret` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_ReadFreeViewPrivateKey`
  * :cpp:func:`HAL_CRYPTO_ReadMVPDSecret`
  * :cpp:func:`HAL_CRYPTO_WriteMVPDSecret`
  * :cpp:func:`HAL_CRYPTO_WriteHDCPOnSecure` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_ReadHDCPFromSecure` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_AES_Encrypt` //except from socts, The function owner is unknown and this is not used in DILE by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_AES_Decrypt` //except from socts, The function owner is unknown and this is not used in DILE by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_RSA_Encrypt` //except from socts, The function owner is unknown and this is not used in DILE by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_RSA_Decrypt` //except from socts, The function is not used by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_RSA_Sign` //except from socts, The function owner is unknown and this is not used in DILE by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_RSA_Verify` //except from socts, The function owner is unknown and this is not used in DILE by TVPLAT-197745.
  * :cpp:func:`HAL_CRYPTO_EncryptDbgData`
  * :cpp:func:`HAL_CRYPTO_DecryptDbgData`
  * :cpp:func:`HAL_CRYPTO_Encrypt`
  * :cpp:func:`HAL_CRYPTO_Decrypt`
  * :cpp:func:`HAL_CRYPTO_CastGenerateClientAuth`
  * :cpp:func:`HAL_CRYPTO_CastSignHash`
