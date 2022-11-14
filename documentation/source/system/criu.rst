CRIU
==========

History
-------

======= ========== ============== =======
Version Date       Changed by     Comment
======= ========== ============== =======
1.0.0   22.07.22   jaeguk.lee
======= ========== ============== =======

Overall Description
--------------------

CRIU is opensource software basically. ( https://criu.org/Main_Page )
It include some modifications and extends for webos tv.
HAL_CRIU functions is to exception handling about not supported operation
such like device files, shm, rw files.

Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Refer to criu lld documents.

If you see this page in HTML, please click below tag.
- :download:`criu_webos_20221027 <resources/criu_webos_20221027.pdf>`

If you see this page in PDF, please check the criu_webos_20221027.pdf in attachment tab of Adobe Reader
(View > Show/Hide > Navigation Panes > Attachments)

System Context
^^^^^^^^^^^^^^

Refer to criu lld documents.

If you see this page in HTML, please click below tag.
- :download:`criu_webos_20221027 <resources/criu_webos_20221027.pdf>`

If you see this page in PDF, please check the criu_webos_20221027.pdf in attachment tab of Adobe Reader
(View > Show/Hide > Navigation Panes > Attachments)

Performance Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^

Please refer to the performance requirements of each API function.

Design Constraints
^^^^^^^^^^^^^^^^^^^

There are no specific Design Constraints.

Functional Requirements
-----------------------

The data types and functions used in this module are as follows.

Data Types
^^^^^^^^^^^^

NA

Function Calls
^^^^^^^^^^^^^^^

  * :cpp:func:`HAL_CRIU_PreCheckpointNotify`
  * :cpp:func:`HAL_CRIU_PostDumpNotify` //except from socts, TAS test by criu feature bat
  * :cpp:func:`HAL_CRIU_PostRestoreNotify` //except from socts, TAS test by criu feature bat
