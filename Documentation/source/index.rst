LG HAL libs Implementation Guide
=======================================

(This documents is based on http://collab.lge.com/main/x/mCANN)

History
-------

======= ========== ===================== ================================== =======
Version Date       Changed by            Changed Section                    Comment
======= ========== ===================== ================================== =======
1.0     2022-03-11 donghoon.keum@lge.com                                    Initial release
======= ========== ===================== ================================== =======


Goal
----

* This is a guide document for implementing HAL libs.
* This document is used by SoC manufacturers to implement LG TV compatible drivers when developing new SoCs.
* Provide a separate CTS tool to ensure that the SoC company complies with this document.

Contents
--------

.. warning::

  아래 1-9장 순서는 추가/제거/변경하지 않습니다. 각 장의 하위 내용은 변경 가능합니다.

  Chapter 1-9 must not be modified(add/remove/re-order).
  Contents in each chapter can be updated.

.. only:: singlehtml

   .. globalindex::
      :maxdepth: 2

.. toctree::
  :maxdepth: 2
  :numbered:

  airplay
  ecp
  gal
  photo
  pvr
  security
  system
  ucom
  usb
  venc
  api/index
  documentation
