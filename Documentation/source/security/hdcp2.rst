HDCP2
==========

History
-------

======= ========== ============== =======
Version Date       Changed by     Comment
======= ========== ============== =======
1.0.0   22.03.28   kyungnam.bae
======= ========== ============== =======

Overall Description
--------------------

To meet the requirements of confidentiality and integrity for values within
HDCP2.x IIA specification. HAL_HDCP2 functions support that the a confidential
value must never be revealed and the integrity of many values in the system is
protected by fail-safe mechanisms of the protocol.

Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Refer to the HDCP2.x IIA specifications

System Context
^^^^^^^^^^^^^^

Refer to the HDCP2.x IIA specifications

Performance Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^

Check the requirements of each HAL_HDCP2 functions.

Design Constraints
^^^^^^^^^^^^^^^^^^^

NA

Functional Requirements
-----------------------

NA

Data Types
^^^^^^^^^^^^
NA

Function Calls
^^^^^^^^^^^^^^^

  * :cpp:func:`HAL_HDCP2_WriteKeySet`
  * :cpp:func:`HAL_HDCP2_GetEncHdcp2Key`
  * :cpp:func:`HAL_HDCP2_SetEncHdcp2Key`
  * :cpp:func:`HAL_HDCP2_GetRootPublicKey`
  * :cpp:func:`HAL_HDCP2_UseTestVector`
  * :cpp:func:`HAL_HDCP2_GetCertInfo`
  * :cpp:func:`HAL_HDCP2_GetCertInfo2`
  * :cpp:func:`HAL_HDCP2_Decrypt_RSAES_OAEP`
  * :cpp:func:`HAL_HDCP2_Encrypt_RSAES_OAEP`
  * :cpp:func:`HAL_HDCP2_Kd_Key_Derivation`
  * :cpp:func:`HAL_HDCP2_Compute_H_Prime`
  * :cpp:func:`HAL_HDCP2_Compute_L_Prime`
  * :cpp:func:`HAL_HDCP2_Compute_Kh`
  * :cpp:func:`HAL_HDCP2_Encrypt_Km_using_Kh`
  * :cpp:func:`HAL_HDCP2_Decrypt_Km_using_Kh`
  * :cpp:func:`HAL_HDCP2_Decrypt_EKs`
  * :cpp:func:`HAL_HDCP2_HMAC_SHA256_with_kd`
  * :cpp:func:`HAL_HDCP2_XOR_Ks_with_LC128`
  * :cpp:func:`HAL_HDCP2_Generate_Km`
  * :cpp:func:`HAL_HDCP2_Generate_Ks`
  * :cpp:func:`HAL_HDCP2_Write_StoredKm`
  * :cpp:func:`HAL_HDCP2_Select_StoredKm`
  * :cpp:func:`HAL_HDCP2_SHA256`
  * :cpp:func:`HAL_HDCP2_AES_CTR`
  * :cpp:func:`HAL_HDCP2_GetProtectedDecryptionKey`
  * :cpp:func:`HAL_HDCP2_SetProtectedDecryptionKey`
  * :cpp:func:`HAL_HDCP2_Data_Decrypt`
  * :cpp:func:`HAL_HDCP2_Data_Encrypt`
  * :cpp:func:`HAL_HDCP2_Compute_V_Prime`
  * :cpp:func:`HAL_HDCP2_Compute_M_Prime`
  * :cpp:func:`HAL_HDCP2_HMAC_SHA256`
  * :cpp:func:`HAL_HDCP2_SHA1`

