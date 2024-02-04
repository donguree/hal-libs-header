DRM
###

Introduction
************
| This document describes the requirements and implementation guide for common DRM Functions of webOS and functions requiring encryption/decryption.

Revision History
================

======= ========== ============== ===============================
Version Date       Changed by     Comment
======= ========== ============== ===============================
2.0.0   23.11.21   cs.jung        Change format & Update contents
1.0.0   22.05.25   cs.jung
======= ========== ============== ===============================

Terminology
===========
| The key words “must”, “must not”, “required”, “shall”, “shall not”, “should”, “should not”, “recommended”, “may”, and “optional” in this document are to be interpreted as described in RFC2119.

| The following table lists the terms used throughout this document:

====== =========================================
Term   Description
====== =========================================
HDCP   High-bandwidth Digital Content Protection
TEE    Trusted Execution Environment
UHDCP  Ultra High Definition Content Protection
====== =========================================

Technical Assistance
====================

For assistance or clarification on information in this guide, please create an issue in the LGE JIRA project and contact the following person:

====== ==================
Module Owner
====== ==================
DRM    cs.jung@lge.com
HDCP   jihoons@lge.com
====== ==================

Overview
********

General Description
===================

DRM is a function for managing digital rights. webOS supports PlayReady, Widevine, and Fairplay.
For information on Widevine and PlayReady, please refer to the individual guides below. 

:doc:`{linuxtv-ext-header/documentation/source/media/widevine} </part2/linuxtv-ext-header/documentation/source/media/widevine>`

:doc:`{linuxtv-ext-header/documentation/source/media/playready} </part2/linuxtv-ext-header/documentation/source/media/playready>`

Fairplay follows Apple's implementation.

This documents commonly used functions or other functions involving DRM and encryption/decryption.

Features
========

Architecture
============

The functions covered in this document are Read / Write / Decryption functions that are used independently, so no explanation of the architecture is required.

Requirements
************

Functional Requirements
=======================

Please refer to each function's description and requirement.


Quality and Constraints
=======================

Requirements regarding the performance (execution speed) required by each function are described in each function part.

Implementation
**************

This section provides materials that are useful for DRM implementation.

- The `File Location`_ section provides the location of the Git repository where you can get the header file in which the interface for the DRM implementation is defined.
- The `API List`_ section provides a brief summary of DRM APIs that you must implement.
- The `Implementation Details`_ section sets implementation guidance and example code for some major functionalities.


File Location
=============

The DRM interfaces are defined in the hal_drm.h header file, which can be obtained from https://wall.lge.com/.

- Git repository: bsp/ref/hal-libs-header

API List
========

The DRM module implementation must adhere to the interface specifications defined and implements its functions. Refer to the API Reference for more details.

Data Types
----------

======================== ===============================
Name                     Description
======================== ===============================
:cpp:type:`DTV_STATUS_T` Result codes for HAL functions.
======================== ===============================

Functions
---------

=============================================== ====================================================================================================================
Function                                        Description
=============================================== ====================================================================================================================
:cpp:func:`HAL_DRM_GetSecureData`               Gets data from the secure storage where cannot be accessed with general file I/O
:cpp:func:`HAL_DRM_SetSecureData`               Sets data to the secure storage where cannot be accessed with general file I/O
:cpp:func:`HAL_DRM_DeleteSecureData`            Delete data in a secure storage area where cannot be access with general file I/O
:cpp:func:`HAL_DRM_IsSecureDataExist`           Check whether secure data exists or not
:cpp:func:`HAL_DRM_GetHWRandomData`             Get random data which is generated from a physical process(i.e. a hardware) to get true random number
:cpp:func:`HAL_DRM_GetSecureClock`              Get Secured Clock(GMT TIME) from RTC(Real Time clock)
:cpp:func:`HAL_DRM_SetSecureClock`              Set Secured Clock(GMT TIME) to [in]secure_clock. If secure_clock is 0, this function has to get time from NTP server
:cpp:func:`HAL_DRM_AESHWInit`                   Initialize AES hardware block and allocate resources for AES operation
:cpp:func:`HAL_DRM_AESHWUpdate`                 Execute AES hardware block. This function performs the essential role for AES data processing.
:cpp:func:`HAL_DRM_AESHWFinish`                 Process residual data and finish AES hardware block
:cpp:func:`HAL_DRM_WriteWidevineKeyBox`         Store widevine keybox data to secure storage
:cpp:func:`HAL_DRM_GetWidevineDeviceID`         Read device ID of widevine keybox
:cpp:func:`HAL_DRM_UHDCP_SetCW`                 Send KID(Key Identifier) and CW(Control Word) to Descrambler to TEE
:cpp:func:`HAL_DRM_UHDCP_Decrypt`               Descramble an scrambled ATSC 3.0 terrestrial UHDTV broadcast stream
:cpp:func:`HAL_DRM_HDMI_SetSecureDataforHDCP22` Store HDCP2.2 RX key to a secure storage
:cpp:func:`HAL_DRM_HDMI_GetSecureDataforHDCP22` Gets HDCP2.2 key from the secure storage where cannot be accessed with general file I/O
:cpp:func:`HAL_DRM_VerifyHDCP22forHDMI`         Check validity of encrypted HDCP2.2 key which is stored in secure storage area
=============================================== ====================================================================================================================

Implementation Details
======================

In common, validation must be implemented for all parameters. In particular, null checking is performed on pointer parameters.

The padding rules for functions HAL_DRM_AESHWInit, HAL_DRM_AESHWUpdate, HAL_DRM_AESHWFinish follow PKCS#7. The return of each function can refer to openssl's libcrypto.

Testing
*******

DRM HAL Funtions are tested by the webOS TV SoCTS (SoC Test Suite). Prior to this test, sample widevine key, HDCP key are needed. See :doc:`the SoCTS documentation on this. </part4/socts/Documentation/source/producer-manual/producer-manual_hal/producer-manual_hal-drm>`

References
**********

| Refer to https://wiki.openssl.org/index.php/EVP_Symmetric_Encryption_and_Decryption to implement AES Crypto Funtions
