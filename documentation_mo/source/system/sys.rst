SYS
####

.. _khkh.lee: khkh.lee@lge.com
.. _denis.hong: dinis.hong@lge.com
.. _kwangseok.kim: kwangseok.kim@lge.com
.. _abhishek.p: abhishek.p@lge.com
.. _jaesung5.lee: jaesung5.lee@lge.com 
.. _hedaesik.kim: hedaesik.kim@lge.com
.. _jongyeon.yoon : jongyeon.yoon@lge.com

Introduction
************

| This document describes the common system function in the HAL(Hardware Abstraction Layer). This document provides details about its functionalities and implementation requirements.


Revision History
================

======= ========== ===================== =============
Version  Date        Changed by          Description
======= ========== ===================== =============
2.0.0   2023.11      `khkh.lee`_         Change format & Update contents
1.0.0   2022.6.14    `denis.hong`_       First release
======= ========== ===================== =============

Terminology
===========

| The following table lists the terms used in the webOS. HAL_SYS functions to support some modules. so you shuold also refer to the modules related the fuction. 

**webOS TV & System specification**

=============================== ===============================
Term                            Description
=============================== =============================== 
STD(Suspend)                    refer to `STD document <http://10.157.97.250:8000/linuxtv/master/latest_html/system/std.html>`_ 
STR(Resume)                     refer to `STR document <http://10.157.97.250:8000/linuxtv/master/latest_html/system/str.html>`_
Fan Contoller                   webOS system service. Fan Controller is a S/W developed to control the installed fan H/W to reduce the temperature inside the TV and provide temperature information of the SoC and external FRC chip.
DFT                             Digital Function Test System. the PCB is inspected in the factory first before manufacturing. So we should offer functions for DFT inspection.
WOL                             Wake On Lan. To power on by network.
PWM                             Pulse Width Modulation
Debug Port                      Debug port is for debugging port such as Jtag or etc.
=============================== ===============================

Technical Assistance
====================

For assistance or clarification on information in this guide, please create an issue in the LGE JIRA project and contact the following person:

================== ==============================================
Module             Owner
================== ==============================================
Fan Contoller(PWM) `kwangseok.kim`_
STD/STR            `abhishek.p`_
WOL                `jaesung5.lee`_
Security(RPMB)     `hedaesik.kim`_
etc..              `khkh.lee`_ & `denis.hong`_ & `kwangseok.kim`_
================== ==============================================

Overview
********

General Description
===================

SYS is to support for various functions associated with the system or others.
The main features provided are :
  * Lock debug port(T32, register tool, debug tool)
  * DDR memory test in DFT process
  * Get PWM capability from Fan controller
  * Set PWM for Fan controller
  * Get PWM data from Fan controller
  * STD/STR
  * RPMB
  * etc

Architecture
============

SYS is is to support for various functions associated with the system or others.
Please refer to each modules. 

Requirements
************
They are simple functions for each modules. and they are in header file. 
please refer to `hal_sys.h <https://wall.lge.com/gitweb?p=bsp/ref/hal-libs-header.git;a=blob;f=hal_inc/hal_sys.h;h=858195c036d04e836f6e839aac036d48352a1474;hb=refs/heads/master>`_

Functional Requirements
=======================
Please refer to each function's requirements.

Quality and Constraints
=======================
Please refer to each function's constraints.


Implementation
**************

| This section provides supplementary materials that are useful for SYS Function implementation

File Location
=============
| The Git repository is available at `hal-libs-header <https://wall.lge.com/admin/repos/bsp/ref/hal-libs-header>`_ . This Git repository contains the header files for the SYS implementation as well as documentation for the SYS implementation guide and SYS API reference.

API List
========
The SYS implementation must adhere to the interface specifications defined and implements its functions. Refer to the API Reference for more details.

Data Types
----------

Extented Structures
^^^^^^^^^^^^^^^^^^^^

=========================================== ===========================================================
Name                                        Description
=========================================== ===========================================================
:c:macro:`HAL_SYS_PWM_CAPABILITY_INFO_T`      Structure of PWM Capability Infomaition
=========================================== ===========================================================


Extented Enumerations
^^^^^^^^^^^^^^^^^^^^

=========================================== ===========================================================
Name                                        Description
=========================================== ===========================================================
:c:macro:`SUSPEND_MODE_T`                     About suspend mode. 
:c:macro:`DFT_MEM_TEST_RESULT_T`              About Memory Test Result 
=========================================== ===========================================================


Functions
---------

Extented Functions
^^^^^^^^^^^^^^^^^^

=========================================== ===========================================================
Function                                    Description
=========================================== ===========================================================
:cpp:func:`HAL_SYS_LockDebugPort`           Enable/Disable debug port(T32, register tool, debug tool)    
:cpp:func:`HAL_SYS_SetWolOnOff`             Enable/Disable WOL. 
:cpp:func:`HAL_SYS_GetWolStatus`            Get WOL Status.
:cpp:func:`HAL_SYS_Suspend`                 SIC only used. 
:cpp:func:`HAL_SYS_Resume`                  SIC only used. 
:cpp:func:`HAL_SYS_WakeUpInternalMicom`     RTK only used. WAKE Up Internal Micom.
:cpp:func:`HAL_SYS_ReadBootData`            MTK only used. Read/Write for boot area.
:cpp:func:`HAL_SYS_WriteBootData`           MTK only used. Read/Write for boot area.
:cpp:func:`HAL_SYS_ReadPMData`              MTK only used. Read/Write for Internal Micom.
:cpp:func:`HAL_SYS_WritePMData`             MTK only used. Read/Write for Internal Micom.
:cpp:func:`HAL_IPC_Write`                   RTK only used. For WebOS and Internal Micom communicatoin
:cpp:func:`HAL_IPC_Read`                    RTK only used. For WebOS and Internal Micom communicatoin
:cpp:func:`HAL_SYS_CheckRPMBPartition`      Check RPMB Partition.(this is for security team)
:cpp:func:`HAL_SYS_CheckModelIdStatus`      Check model id is stored in RPMB (this is for security team)         
:cpp:func:`HAL_SYS_StartDFTMemTest`         DDR memory test in DFT proces.
:cpp:func:`HAL_SYS_GetDFTMemTestResult`     Get DDR memory test results in DFT process
:cpp:func:`HAL_SYS_GetPWMCapability`        Get PWM Capability for Fan controller
:cpp:func:`HAL_SYS_SetPWM`                  Set PWM for Fan controller
:cpp:func:`HAL_SYS_GetPWMData`              Get PWM Data for Fan controller
=========================================== ===========================================================

Implementation Details
======================

| SYS API is common API based HW Layer(HAL) for various modules. So SYS API is simple and the header file already has details comment for each functions. 

| please refer to `hal_sys.h <https://wall.lge.com/gitweb?p=bsp/ref/hal-libs-header.git;a=blob;f=hal_inc/hal_sys.h;h=858195c036d04e836f6e839aac036d48352a1474;hb=refs/heads/master>`_
