USB
==========

History
-------

======= ========== ============== =======
Version Date       Changed by     Comment
======= ========== ============== =======
1.1.0   2022-07-28 jm0122.kang    Remove unused api (HAL_USB_SuperSpeedVBusControl)
1.0.0   2022-04-28 jm0122.kang    1st edit for API Implementation Guide
0.0.0   ...        ...            ...
======= ========== ============== =======

Overall Description
--------------------
USB is a general driver of the kernel, but there is a hal for the operation for the exceptional part.
The exceptional case is a problem with the device manufacturer
that is usb I/O not work correctly with usb 3.0 speed with some devices made by that usb device manufacturer.
For avoid this issue, webOS TV use the usb HAL API.
You can turn on/off the xhci controller through that API.
If this API is used, the above abnormal devices (black list devices) are recognized as usb 2.0 instead of usb 3.0.
By doing so, black devices help normal I/O to occur.
This API controls usb 3.0 by enabling/disabled xhci of a specific usb port to operate as echi.

Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

================================= ======================================
Definition                        Description
================================= ======================================
xhci                              xHCI(eXtensible Host Controller Interface)
ehci                              EHCI (Enhanced Host Controller Interface)
================================= ======================================

System Context
^^^^^^^^^^^^^^
NA

Performance Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^
It should return within 100ms.

Design Constraints
^^^^^^^^^^^^^^^^^^^
Implementation is required only on SoCs that support xhci.

Functional Requirements
-----------------------
The data types and functions used in this module are as follows.

HAL_USB_SuperSpeedPortOff
^^^^^^^^^^^^^^^^^^^^^^^^

Description
###########

Turn off super speed port
Disbale USB 3.0 PHY to work on the super speed mode

Syntax
######

DTV_STATUS_T HAL_USB_SuperSpeedPortOff (unsigned int busNumber, unsigned int portNumber)

Parameters
##########

============ ===========
type         name
============ ===========
unsigned int busNumber
unsigned int portNumber
============ ===========

Return Value
############

If the function succeeds, the return value is Zero(0).
If the function fails, the return value is non-Zero(-1 or errno).

HAL_USB_SuperSpeedPortUp
^^^^^^^^^^^^^^^^^^^^^^^^

Description
###########

Turn on super speed port
Recovery USB 3.0 PHY to work on the super speed mode

Syntax
######
DTV_STATUS_T HAL_USB_SuperSpeedPortUp(unsigned int busNumber, unsigned int portNumber)

Parameters
##########

============ ===========
type         name
============ ===========
unsigned int busNumber
unsigned int portNumber
============ ===========

Return Value
############

If the function succeeds, the return value is OK.
If the function fails, the return value is NOT_OK.

Function Calls
^^^^^^^^^^^^^^^

  * :cpp:func:`HAL_USB_SuperSpeedPortUp`
  * :cpp:func:`HAL_USB_SuperSpeedPortOff`
