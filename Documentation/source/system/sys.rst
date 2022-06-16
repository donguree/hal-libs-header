SYS
==========

History
-------

======= ========== ===================== =============
Version  Date        Changed by          Description
======= ========== ===================== =============
1.0.0   2022.6.14    `denis.hong`         First release
======= ========== ===================== =============


Overall Description
--------------------
SYS module is to support for various functions associated with the system.
The main features provided are :
  * Lock debug port(T32, register tool, debug tool)
  * DDR memory test in DFT process
  * Get PWM capability from Fan controller
  * Set PWM for Fan controller
  * Get PWM data from Fan controller

Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^


================= ==================================================
Definition                Description
================= ==================================================
PWM                Pulse Width Modulation
================= ==================================================

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

  * :cpp:func:`HAL_SYS_LockDebugPort`
  * :cpp:func:`HAL_SYS_SetWolOnOff` //except from socts, right assignment is required
  * :cpp:func:`HAL_SYS_GetWolStatus` //except from socts, right assignment is required
  * :cpp:func:`HAL_SYS_Suspend` //except from socts, this function supports up to webOS4.5
  * :cpp:func:`HAL_SYS_Resume` //except from socts, this function supports up to webOS4.5
  * :cpp:func:`HAL_SYS_WakeUpInternalMicom` //except from socts, this function supports up to webOS4.5
  * :cpp:func:`HAL_SYS_ReadBootData` //except from socts, this function supports up to webOS4.5
  * :cpp:func:`HAL_SYS_WriteBootData` //except from socts, this function supports up to webOS4.5
  * :cpp:func:`HAL_SYS_ReadPMData` //except from socts, right assignment is required
  * :cpp:func:`HAL_SYS_WritePMData` //except from socts, right assignment is required
  * :cpp:func:`HAL_IPC_Write` //except from socts, right assignment is required
  * :cpp:func:`HAL_IPC_Read` //except from socts, right assignment is required
  * :cpp:func:`HAL_SYS_CheckRPMBPartition` //except from socts, right assignment is required
  * :cpp:func:`HAL_SYS_StartDFTMemTest`
  * :cpp:func:`HAL_SYS_GetDFTMemTestResult`
  * :cpp:func:`HAL_SYS_GetPWMCapability`
  * :cpp:func:`HAL_SYS_SetPWM`
  * :cpp:func:`HAL_SYS_GetPWMData`