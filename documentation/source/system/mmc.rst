MMC
==========

History
-------

======= ========== ===================== =============
Version  Date        Changed by          Description
======= ========== ===================== =============
1.0.0   2022.6.8    `denis.hong`         First release
======= ========== ===================== =============

Overall Description
--------------------
MMC module is to support for the block devices associated with the MMC device.
The main features provided are :
  * Open MMC device
  * Close MMC device
  * Set PON with short time
  * Set PON with long time
  * Get MMC CID
  * Get MMC usage information(SMART)
  * Get MMC register's information

Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

================= ==================================================
Definition                Description
================= ==================================================
MMC                Multi-Media Card
PON                Power Off Notification
CID                Card IDentificatoin
SMART              Self Monitoring, Analysis and Reporting Technology
================= ==================================================

System Context
^^^^^^^^^^^^^^

NA

Performance Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^

It should return within 10ms, if there are no special reasons.

Design Constraints
^^^^^^^^^^^^^^^^^^^

Please refer to each function's constraints.

Functional Requirements
-----------------------

The data types and functions used in this module are as follows.

Data Types
^^^^^^^^^^^^

Function Calls
^^^^^^^^^^^^^^^

  * :cpp:func:`HAL_MMC_Open`
  * :cpp:func:`HAL_MMC_Close`
  * :cpp:func:`HAL_MMC_PON_Short`
  * :cpp:func:`HAL_MMC_PON_Long`
  * :cpp:func:`HAL_MMC_Get_CID`
  * :cpp:func:`HAL_MMC_Get_SMART_Report`
  * :cpp:func:`HAL_MMC_Get_Register` //except from socts, it will be update if this function is to be tested.