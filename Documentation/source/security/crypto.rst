Crypto
==========

History
-------

======= ========== ============== =======
Version Date       Changed by     Comment
======= ========== ============== =======
1.0.0   2022.07.28 hedaesik.kim   Add new document
======= ========== ============== =======

Overall Description
--------------------

Provision the encrypted injection key injected from the factory to the TEE secure storage.
TEE supports encryption and decryption.
Trigger the operation of the specific TAs.

Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

================================= ======================================
Definition                        Description
================================= ======================================
We will update the content soon.  We will update the content soon.
================================= ======================================

System Context
^^^^^^^^^^^^^^

We will update the content soon.

Performance Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^

We will update the content soon.

Design Constraints
^^^^^^^^^^^^^^^^^^^

We will update the content soon.

Functional Requirements
-----------------------

The data types and functions used in this module are as follows.

Data Types
^^^^^^^^^^^^
We will update the content soon.

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
