Behavioral Perspective Design
==============================

.. Document Descriptions:

Document Descriptions
----------------------

======= ========== ============== =====================================
Version Date       Changed by     Comment
======= ========== ============== =====================================
1.0.0   2022-04-22 sungbae.park   1st release
======= ========== ============== =====================================

.. The Purpose of Document:

The Purpose of Document
^^^^^^^^^^^^^^^^^^^^^^^^

It's not enough to understand basic flow of the UCOM module referring to UCOM implementation guide
only for new SoC vendor.
This document is written to reduce useless communication between SoC vendor and LGE
and to help the developer's understanding.

.. The Scope of Document:

The Scope of Document
^^^^^^^^^^^^^^^^^^^^^^
This document describes dynamic perspectives and dynamic behavior of the driver modules and user services
those are related with hal_ucom in BSP.

.. The Organization of Document:

The Organization of Document
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
1. `Document Descriptions`_

    1.1 `The Purpose of Document`_

    1.2 `The Scope of Document`_

    1.3 `The Organization of Document`_

    1.4 `Terminology and Definitions`_

2. `Architecture Design`_

    2.1 `Dynamic Perspectives`_

    2.2 `Sequence Diagram for Write Operation`_

    2.2 `Sequence Diagram for Read Operation`_

3. `Reference`_

.. Terminology and Definitions:

Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

================================= ======================================
Definition                        Description
================================= ======================================
Luna Service                      Luna Service Interface
IPC                               Inter-Process Communication
================================= ======================================

.. Architecture Design:

Architecture Design
---------------------
This chapter describes the architecture design for the system.

.. Dynamic Perspectives:

Dynamic Perspectives
^^^^^^^^^^^^^^^^^^^^^
[Figure 1-1] describes the relationship between the BSP driver module and user service from a dynamic perspective.

-----

**[Figure 1-1] Dynamic Perspective**

.. image:: /ucom/ucom_dynamic_perspective.png
  :width: 100%
  :alt: UCOM Dynamic Perspective

-----

Responsibility for Architectural Elements in [Figure 1-1] is as shown in [Table 1-1].

-----

**[Table 1-1] Element Responsibility**

================================= ====================================================================================================
Element                           Responsibility
================================= ====================================================================================================
Factory Manager                   - This service is in charge of necessary operations related to TV production.
TvpowerD                          - This service is in charge of necessary operations related to TV's Power On/Off.
Micom Service                     - This service is in charge of TV key processing and interface operation with external services.
PQ controller                     - The PQ Controller controls the quality of the video output on the TV screen.
                                  - The purpose is to show the optimal picture quality to the user by using the picture quality
                                  - setting values (Picture Mode, Color Gamut, Gamma, White Balance, etc.) set in the TV and the sensor.
Panel controller                  - The Panel Controller controls the power sequence and panel-related functions to display the screen.
                                  - Power sequence sets the panel, inverter, and Main / Sub PMIC (Power Management IC) according to
                                  - the specifications of the panel.
Micom Library                     - It is responsible for communication and information transfer between external services and Micom FW
                                  - using BSP's Hal Ucom Driver.
================================= ====================================================================================================

-----

.. Dynamic Behavior:

Dynamic Behavior
^^^^^^^^^^^^^^^^^
[Figure 2-1] describes the process of exchanging messages with the user service and the BSP driver.

.. important::

  In the same service, the Initialize function is performed only the first time.

  After that, the Hal Ucom Initialize operation is skipped as determined by micom-libs.

-----

**[Figure 2-1] Dynamic Behavior**

.. image:: /ucom/ucom_dynamic_behavior.png
  :width: 100%
  :alt: UCOM Dynamic Behavior

-----

[Table 2-1] and [Table 2-2] describe in detail the process of setting the BSP driver
by the user service in [Figure 2-1].

-----

**[Table 2-1] Write Command Operation with Ucom Driver**

================================= ===============================================================================
Sequence                          Description
================================= ===============================================================================
1                                 * **Micom Service → Micom Library → Ucom Driver**
                                  -  Write Whole Chip Reset, Set Hal Ucom init, Call Write Command
                                  - Make write command set and Call to micom library API
                                  - Initialize : HAL_UCOM_Initialize function call
                                  - Write Command : HAL_UCOM_WholeChipReset(void) call

2                                 * **Ucom Driver → Micom Library → Micom Service**
                                  - Return to IPC operation result(SUCCESS/FAIL)

3                                 * **Panel Controller → Micom Library → Ucom Driver**
                                  - Write panel GPIO control, Set Hal Ucom init, Call Write Command
                                  - Make write command set and Call to micom library API
                                  - Initialize : HAL_UCOM_Initialize function call
                                  - Write Command : HAL_UCOM_WriteCommand(UINT8 *pCmd, UINT16 size) call

4                                 * **Ucom Driver → Micom Library → Panel Controller**
                                  - Return to IPC operation result(SUCCESS/FAIL)

5                                 * **TvpowerD → Micom Library → Ucom Driver**
                                  - Write Power On/Off control to micom FW, Set Hal Ucom init, Call Write Command
                                  - Make write command set and Call to micom library API
                                  - Initialize : HAL_UCOM_Initialize function call
                                  - Write Command : HAL_UCOM_WriteCommand(UINT8 *pCmd, UINT16 size) call

6                                 * **Ucom Driver → Micom Library → TvpowerD**
                                  - Return to IPC operation result(SUCCESS/FAIL)
================================= ===============================================================================

**[Table 2-2] Read Command Operation with Ucom Driver**

================================= ===================================================================================
Sequence                          Description
================================= ===================================================================================
7                                 * **Factory Manager → Micom Library → Ucom Driver**
                                  - Read micom FW version data, Set Hal Ucom init, Call Read Command
                                  - Make read command set and Call to micom library API
                                  - Initialize : HAL_UCOM_Initialize function call
                                  - Read Command : HAL_UCOM_ReadCommand(UINT8 cmd, UINT16 dataSize, UINT8 *pData) call

8                                 * **Ucom Driver → Micom Library → Factory Manager**
                                  - Return micom FW version data with kernel event
                                  1. Return micom FW version data(UINT8 *pData)

9                                 * **PQ Controller → Micom Library → Ucom Driver**
                                  - Read mode select duty data, Set Hal Ucom init, Call Read Command
                                  - Make read command set and Call to micom library API
                                  - Initialize : HAL_UCOM_Initialize function call
                                  - Read Command : HAL_UCOM_ReadCommand(UINT8 cmd, UINT16 dataSize, UINT8 *pData) call

10                                * **Ucom Driver → Micom Library → PQ Controller**
                                  - Return mode select duty data with kernel event
                                  1. Return mode select duty data (UINT8 /*pData)
================================= ===================================================================================

-----

.. Sequence Diagram for Write Operation:Sequence Diagram for Read Operation:

Sequence Diagram for Write Operation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

[Figure 2-2] shows the relationship between the BSP driver
and the user service as a sequence diagram of the resource setting processin [Table 2-1].

-----

**[Figure 2-2] UCOM Sequence Diagram for Write Operation**

.. image:: /ucom/ucom_write_operation.png
  :width: 100%
  :alt: UCOM Sequence Diagram for Write Operation

-----

.. Sequence Diagram for Read Operation:

Sequence Diagram for Read Operation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

[Figure 2-3] shows the relationship between the BSP driver
and the user service as a sequence diagram of the resource setting processin [Table 2-2].

-----

**[Figure 2-3] UCOM Sequence Diagram for Read Operation**

.. image:: /ucom/ucom_read_operation.png
  :width: 100%
  :alt: UCOM Sequence Diagram for Read Operation

-----

.. Reference:

Reference
----------
None
