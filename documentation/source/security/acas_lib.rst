Acas_lib
==========

History
-------

======= ========== ================= =======
Version Date       Changed by        Comment
======= ========== ================= =======
1.0.0   22.08.10   ryuji.takenaka    Add new document
======= ========== ================= =======

Overall Description
----------------------

Due to avoid secure issue, the descramble the scrambled contents is done in Secure World (TEE).
Thus ACAS Library is located in TEE.
To be the interface between Normal World (REE) and TEE, HAL_ACAS_LIB is placed as a new member of HAL functions.

Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

================================= ======================================
Definition                        Description
================================= ======================================
ACAS                              Advanced conditional access system
TEE                               Trusted Execution Environment
REE                               Rich Execution Environment
================================= ======================================

System Context
^^^^^^^^^^^^^^

NA

Performance Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^

HAL_ACAS_LIB supports up to 3 tuners for 4K broadcasting.

Design Constraints
^^^^^^^^^^^^^^^^^^^

ACAS Keys are required to use HAL_ACAS_LIB.
ACAS Keys are provided by the Advanced CAS Council and stored in SeData.

Functional Requirements
-----------------------

The data types and functions used in this module are as follows.

Data Types
^^^^^^^^^^^^

  * :cpp:type:`HAL_ACAS_LIB_STATE_T`
  * :cpp:type:`ACAS_KEY_STATE_T`
  * :cpp:type:`ACAS_LIB_DESCRAMBLE_INFO`

Function Calls
^^^^^^^^^^^^

  * :cpp:func:`HAL_ACAS_LIB_Initialize`
  * :cpp:func:`HAL_ACAS_LIB_Open`
  * :cpp:func:`HAL_ACAS_LIB_Close`
  * :cpp:func:`HAL_ACAS_LIB_DeInitialize`
  * :cpp:func:`HAL_ACAS_LIB_GetScrambleKeyProtectCommandParam`
  * :cpp:func:`HAL_ACAS_LIB_SetScrambleKeyProtectCommandRes`
  * :cpp:func:`HAL_ACAS_LIB_UpdateKey` //except from socts, it is not used
  * :cpp:func:`HAL_ACAS_LIB_SetDescrambleKey`
  * :cpp:func:`HAL_ACAS_LIB_ClearDescrambleKey`
  * :cpp:func:`HAL_ACAS_LIB_Descramble`
  * :cpp:func:`HAL_ACAS_LIB_ReadSecureData`
  * :cpp:func:`HAL_ACAS_LIB_DEBUG_SetStatus`
  * :cpp:func:`HAL_ACAS_LIB_DEBUG_GetStatus`
  * :cpp:func:`HAL_ACAS_LIB_Descramble_ext`
