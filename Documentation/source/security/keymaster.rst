KEYMASTER
==========

History
-------

======= ========== ============== =======
Version Date       Changed by     Comment
======= ========== ============== =======
1.0.0   2023.01.31 hedaesik.kim   Add Doc.
======= ========== ============== =======

Overall Description
--------------------

The webos keymaster is an android-based keymaster.
TEE protects the key and supports encryption and decryption.


Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

================================= ======================================
Definition                        Description
================================= ======================================
================================= ======================================

System Context
^^^^^^^^^^^^^^

Performance Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^

There is no clear requirement for response time, but a response must be received within at least 100 ms.

Design Constraints
^^^^^^^^^^^^^^^^^^^

Functional Requirements
-----------------------

================================= ======================================
REQ-ID                            Requirement
================================= ======================================
================================= ======================================

Data Types
^^^^^^^^^^^^

Function Calls
^^^^^^^^^^^^^^^

  * :cpp:func:`keymaster::OpteeKeymaster3Device::getHardwareFeatures`
  * :cpp:func:`keymaster::OpteeKeymaster3Device::addRngEntropy`
  * :cpp:func:`keymaster::OpteeKeymaster3Device::generateKey`
  * :cpp:func:`keymaster::OpteeKeymaster3Device::getKeyCharacteristics`
  * :cpp:func:`keymaster::OpteeKeymaster3Device::importKey`
  * :cpp:func:`keymaster::OpteeKeymaster3Device::importSecKey`
  * :cpp:func:`keymaster::OpteeKeymaster3Device::exportKey`
  * :cpp:func:`keymaster::OpteeKeymaster3Device::begin`
  * :cpp:func:`keymaster::OpteeKeymaster3Device::update`
  * :cpp:func:`keymaster::OpteeKeymaster3Device::finish`
  * :cpp:func:`keymaster::OpteeKeymaster3Device::abort`
