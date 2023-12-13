UCOM
#######

.. _sungbae.park: sungbae.park@lge.com
.. _jjeonghyeon.kim: jjeonghyeon.kim@lge.com
.. _sungyun.nam: sungyun.nam@lge.com

Introduction
************

|  This document describes the UCOM driver in the hal-libs layer of the webOS.
|  The document gives an overview of the UCOM driver and provides details about its functionalities and implementation requirements.
|  Therefore, the document assumes that the readers are familiar with the IPC communication mechanism.
|  The UCOM driver is based on the IPC communication between Main SOC and Micom FW.
|  The UCOM driver reads data from micom FW or writes data to micom FW.

Revision History
================

======= ========== ===================== ======================
Version  Date        Changed by          Description
======= ========== ===================== ======================
3.0.0   2023.11.06   `sungbae.park`_     Update contents and new document form
2.0.0   2022-11-15   `sungbae.park`_     Modify documentation new format
1.0.0   2022-04-13   `sungbae.park`_     First release
======= ========== ===================== ======================

Terminology
===========

================= ==================================================
Definition                Description
================= ==================================================
IPC                Inter-Process Communication
================= ==================================================

Technical Assistance
====================
|  For assistance or clarification on information in this guide, please create an issue in the LGE JIRA project and contact the following person:

================= ============================
Module             Owner
================= ============================
UCOM               `sungbae.park` `jjeonghyeon.kim` `sungyun.nam`
================= ============================


Overview
********

General Description
===================

|  UCOM module is controlled using IPC communication between Main SOC and Micom.
|  The main features provided are :
- Initial UCOM device

- Read UCOM command
- Write UCOM command
- Whole Chip reset


Architecture
============
Please refer to the photo below.


System Context
--------------

|  This section describes the system context of hal-libs ucom.
|  Through this system context, external entities are identified and the system boundary is clarified.

.. image:: resources/ucom_dynamic_perspective.png

====================== ====================================================================================================
Associated Drawings:    Perspective : Dynamic
====================== ====================================================================================================
Entity                  Responsibility
Factory Manager         This service is in charge of necessary operations related to TV production.
TvpowerD                This service is in charge of necessary operations related to TV Power On/Off.
Micom Service           This service is in charge of TV key processing and interface operation with external services.
PQ controller           This service controls the quality of the video output on the TV screen.
Panel controller        This service controls the power sequence and panel-related functions to display the screen.
Micom Library           It is responsible for communication and information transfer between Main SOC and Micom FW.
====================== ====================================================================================================


Overal Workflow
===============

|  The sequence diagram of Write operation

.. image:: resources/ucom_write_operation.png

====================================== ====================================================================================================
Associated Drawings:                    Perspective : Dynamic
====================================== ====================================================================================================
Relationships                           Responsibility
External Service -> Micom Library       Make write command set and Call to micom library API           
Micom Library -> UCOM Driver            HAL_UCOM_Initialize function call & HAL_UCOM_WriteCommand(UINT8 *pCmd, UINT16 size) call									
UCOM Driver -> Micom Library            Return to IPC operation result(SUCCESS/FAIL)
Micom Library -> External Service       Return to IPC operation result(SUCCESS/FAIL)
====================================== ====================================================================================================

|  The sequence diagram of Read operation

.. image:: resources/ucom_read_operation.png

====================================== ====================================================================================================
Associated Drawings:                    Perspective : Dynamic
====================================== ====================================================================================================
Relationships                           Responsibility
External Service -> Micom Library       Make read command set and Call to micom library API           
Micom Library -> UCOM Driver            HAL_UCOM_Initialize function call & HAL_UCOM_ReadCommand(UINT8 cmd, UINT16 dataSize, UINT8 *pData) call									
UCOM Driver -> Micom Library            Return to IPC operation result(SUCCESS/FAIL)
Micom Library -> External Service       Return to IPC operation result(SUCCESS/FAIL)
====================================== ====================================================================================================


Requirements
************

|  They are simple functions for each modules. and they are in header file. 
|  Please refer to "hal_ucom.h"


Functional Requirments
======================

|  Please refer to the performance requirements of each API function.


Quality and Constraints
=======================

Performance Requirements
------------------------

|  It should return within 10ms, if there are no special reasons.


Implementation
**************

File Location
=============
|  The Git repository of the hal ucom module is available at "hal-libs-header".
|  This Git repository contains the header files for the hal ucom implementation as well as documentation for the ucom implementation guide and ucom API reference.

API List
========

|  The data types and functions used in this module are as follows.

Data Types
----------

Enumerations
^^^^^^^^^^^^

============================== ===================================
Name                           Description
============================== ===================================
:c:macro:`DRV_STATUS_T`        Struct for the ucom API result
============================== ===================================

Functions
---------

==================================== ======================================================
Name                                 Description
==================================== ======================================================
:cpp:func:`HAL_UCOM_Initialize`      Initialize UCOM device.
:cpp:func:`HAL_UCOM_ReadCommand`     Read opeartion from Main SoC to Micom FW.
:cpp:func:`HAL_UCOM_WriteCommand`    Write opeartion from Main SoC to Micom FW.
:cpp:func:`HAL_UCOM_WholeChipReset`  Whole chip reset operation.
==================================== ======================================================


Implementation Details
======================

| UCOM API is common API based HW Layer(HAL) for various modules.
| So UCOM API is simple and the header file already has details comment for each functions. 
| Please refer to "hal_ucom.h".


Testing
*******
|  To test the implementation of the UCOM module, webOS TV provides :doc:`SoCTS (SoC Test Suite) tests </part4/socts/Documentation/source/producer-manual/producer-manual_hal/producer-manual_hal-ucom>`.
|  The SoCTS checks the basic operations of the UCOM module.

References
**********

