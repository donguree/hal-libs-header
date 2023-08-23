Airplay
==========

History
-------

======= ========== =============== =======
Version Date       Changed by      Comment
======= ========== =============== =======
2.0     2019-12-27 kyungnam.bae    Handle the short MFi Private Key when implementing HAL_AIRPLAY_MFi_GetSignature
1.9     2019-07-11 byounghyun.shin Add note for implementing HAL_AIRPLAY_MFi_GetSignature
1.8     2019-03-21 kyungnam.bae    Add new function - HAL_AIRPLAY_MFi_DeleteKeySet / Modify function - HAL_AIRPLAY_MFi_GetKeyInfo2
1.7     2019-03-15 kyungnam.bae    Modify function - HAL_AIRPLAY_MFi_GetKeyInfo2
1.6     2018-12-21 kyungnam.bae    Modify functions - HAL_AIRPLAY_MFi_GetKeyInfo, HAL_AIRPLAY_MFi_GetKeyInfo2
1.5     2018-12-14 kyungnam.bae    Add new function - HAL_AIRPLAY_MFi_GetKeyInfo2
1.4     2018-12-03 kyungnam.bae    Modify functions description - HAL_AIRPLAY_MFi_WriteKeySet, HAL_AIRPLAY_MFi_VerifyKeySet
1.3     2018-10-31 kyungnam.bae    Modify function description - HAL_AIRPLAY_MFi_GetKeyInfo
1.2     2018-08-30 chihyoung.kim   Implement function - HAL_AIRPLAY_FairPlay_VerifyObject
1.1     2018-08-21 byounghyun.shin Implement functions - HAL_AIRPLAY_MFi_VerifyProvisioningObject, HAL_AIRPLAY_MFi_GetCertificate, HAL_AIRPLAY_MFi_GetSignature
1.0     2018-06-23 kyungnam.bae    Implement functions - HAL_AIRPLAY_MFi_WriteKeySet, HAL_AIRPLAY_MFi_VerifyKeySet, HAL_AIRPLAY_MFi_GetKeyInfo
======= ========== ============== =======

Overall Description
----------------------

Airplay module is to support Apple MFi key based operations.
The main features provided are :

  * Write MFi key
  * Verify MFi key
  * Delete Mfi key
  * Get Mfi key information
  * Get MFi key certification
  * Get Mfi key signature
  * Verify MFi/FairPlay provisioing object

Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

================================= ======================================
Definition                        Description
================================= ======================================
MFi                               Made for iPhone/iPod/iPad
FairPlay                          Digital rights management(DRM) technology developed by Apple
================================= ======================================

System Context
^^^^^^^^^^^^^^

We will update the content soon.

Performance Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^
There are no performance requirements.

Design Constraints
^^^^^^^^^^^^^^^^^^^
There must be symmetric key exchanged with Apple on the board.
If there is no symmetric key, all APIs cannot be tested.

The real MFi key can be downloaded from LG SDP server in the webOS environment.
If it is impossible to download the key from LG SDP server,
LG MFi key engineer must provide the test MFi key to download manually.
If there is no MFi key, some APIs cannot be tested.

Functional Requirements
-----------------------
The data types and functions used in this module are as follows.

Function Calls
^^^^^^^^^^^^

  * :cpp:func:`HAL_AIRPLAY_MFi_WriteKeySet` //except from socts, it can be only verified by BIT
  * :cpp:func:`HAL_AIRPLAY_MFi_VerifyKeySet` //except from socts, it can be only verified by BIT
  * :cpp:func:`HAL_AIRPLAY_MFi_DeleteKeySet` //except from socts, it can be only verified by BIT
  * :cpp:func:`HAL_AIRPLAY_MFi_GetKeyInfo` //except from socts, it is deprecated
  * :cpp:func:`HAL_AIRPLAY_MFi_GetKeyInfo2` //except from socts, it can be only verified by BIT
  * :cpp:func:`HAL_AIRPLAY_MFi_VerifyProvisioningObject` //except from socts, it can be only verified by BIT
  * :cpp:func:`HAL_AIRPLAY_MFi_GetCertificate` //except from socts, it can be only verified by BIT
  * :cpp:func:`HAL_AIRPLAY_MFi_GetSignature` //except from socts, it can be only verified by BIT
  * :cpp:func:`HAL_AIRPLAY_FairPlay_VerifyObject` //except from socts, it can be only verified by BIT
