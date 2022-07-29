DRM
==========

History
-------

======= ========== ============== =======
Version Date       Changed by     Comment
======= ========== ============== =======
1.0.0   22.05.25   cs.jung
======= ========== ============== =======

Overall Description
--------------------

This document describes how to use and implement the HAL functions, which are available in the webOS TV 23. All the HAL functions in this document are supposed to be implemented by main SoC vendor.

Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

================================= =========================================
Definition                        Description
================================= =========================================
--------------------------------- -----------------------------------------
HDCP                              High-bandwidth Digital Content Protection
--------------------------------- -----------------------------------------
TEE                               Trusted Execution Environment
--------------------------------- -----------------------------------------
UHDCP                             Ultra High Definition Content Protection
================================= =========================================

System Context
^^^^^^^^^^^^^^

NA

Performance Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^

NA

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

  * :cpp:func:`HAL_DRM_GetSecureData`
  * :cpp:func:`HAL_DRM_SetSecureData`
  * :cpp:func:`HAL_DRM_DeleteSecureData`
  * :cpp:func:`HAL_DRM_GetHWRandomData`
  * :cpp:func:`HAL_DRM_GetSecureClock`
  * :cpp:func:`HAL_DRM_SetSecureClock`
  * :cpp:func:`HAL_DRM_GetClearDataLength` //except from socts, this will be deleted
  * :cpp:func:`HAL_DRM_AESHWInit`
  * :cpp:func:`HAL_DRM_AESHWUpdate`
  * :cpp:func:`HAL_DRM_AESHWFinish`
  * :cpp:func:`HAL_DRM_GetHWID` //except from socts, this will be deleted
  * :cpp:func:`HAL_DRM_IsSecureDataExist`
  * :cpp:func:`HAL_DRM_InitDrv`
  * :cpp:func:`HAL_DRM_GetSecureDataProtected` //except from socts, this will be deleted
  * :cpp:func:`HAL_DRM_WriteWidevineKeyBox`
  * :cpp:func:`HAL_DRM_GetWidevineDeviceID`
  * :cpp:func:`HAL_DRM_UHDCP_SetCW`
  * :cpp:func:`HAL_DRM_UHDCP_Decrypt`
  * :cpp:func:`HAL_DRM_HDMI_SetSecureDataforHDCP22`
  * :cpp:func:`HAL_DRM_HDMI_GetSecureDataforHDCP22`
  * :cpp:func:`HAL_DRM_VerifyHDCP22forHDMI`