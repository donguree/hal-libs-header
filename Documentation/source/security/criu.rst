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
- http://collab.lge.com/main/pages/viewpage.action?pageId=1697529562

System Context
^^^^^^^^^^^^^^

Refer to criu lld documents.
- http://collab.lge.com/main/pages/viewpage.action?pageId=1697529562

Performance Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^

NA

Design Constraints
^^^^^^^^^^^^^^^^^^^

NA

Functional Requirements
-----------------------

NA

Data Types
^^^^^^^^^^^^

NA

Function Calls
^^^^^^^^^^^^^^^

  * :cpp:func:`HAL_CRIU_PreCheckpointNotify`
  * :cpp:func:`HAL_CRIU_PostDumpNotify` //except from socts, TAS test by criu feature bat
  * :cpp:func:`HAL_CRIU_PostRestoreNotify` //except from socts, TAS test by criu feature bat
