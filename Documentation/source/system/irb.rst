IRB
==========

History
-------

======= ========== ============== =======
Version Date       Changed by     Comment
======= ========== ============== =======
1.0.0   22.3.30    sanghyun.baek         
======= ========== ============== =======

Overall Description
--------------------

The IR Blaster generates an IR signal for the desired key on the SoC to control external equipment.
IR for controlling external devices is generated through IR parameters provided by UEI company.
The IRB HAL layer serves to generate IR waveforms with the received IR parameters.

Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

================================= ======================================
Definition                        Description
================================= ======================================
IRB	                              IR Blaster
================================= ======================================

System Context
^^^^^^^^^^^^^^

Please refer to the UEI-450 Harmony page.
(LG TV 2020 SW Block Diagram for IR blaster 190530_forLGE.pdf)
If you don't have access, you need to request permission.

Performance Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^

It is determined according to the time generated for each IR waveform.

Design Constraints
^^^^^^^^^^^^^^^^^^^

Please refer to the UEI-450 Harmony page.
(LG TV 2020 SW Block Diagram for IR blaster 190530_forLGE.pdf)
If you don't have access, you need to request permission.

Functional Requirements
-----------------------

The data types and functions used in this module are as follows.

Data Types
^^^^^^^^^^^^
  * :cpp:any:`uei_irb_waveform_s`

Function Calls
^^^^^^^^^^^^^^^

  * :cpp:func:`HAL_IRB_GenerateUEIWaveform` //except from socts, external UEI test
