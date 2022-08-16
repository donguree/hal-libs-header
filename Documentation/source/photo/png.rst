PNG
==========

History
-------

======= ========== ============== =======
Version Date       Changed by     Comment
======= ========== ============== =======
1.0     2013-06-20 jh0506.lee     done
1.0.1   2013-10-21 jh0506.lee     done
1.1     2014-05-13 jh0506.lee     modify
1.1.1   2014-05-22 jh0506.lee     modify
1.1.2   2014-12-01 jh0506.lee     modify
1.1.3   2018-02-26 jh0506.lee     modify
======= ========== ============== =======

Overall Description
--------------------

The photorenderer provides several interfaces which uses HW resources such as decoder and video output, so that dile_photo (driver interface library extension) is intoduces the hal_photo module (hardware abstraction layer).

Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

================================= ======================================
Definition                        Description
================================= ======================================
We will update the content soon.  We will update the content soon.
================================= ======================================

System Context
^^^^^^^^^^^^^^

Below block diagram Fig.1 represents photorenderer's module view in webOS TV.

The photorenderer provides several interfaces which uses HW resources such as decoder and video output, so that dile_photo (driver interface library extension) is intoduces the hal_photo module (hardware abstraction layer).

It includes the HW jpeg decoder / png decoder / video output, also it will have a benefit to reduce the processing load and take easy way display image through video path.

In conclusion, HAL_PHOTO has to follow as below 2, 3 section.

.. image:: /photo/jpegpng.png
  :width: 100%
  :alt: Fig.1 Block diagram for playing the photo contents. Org link http://collab.lge.com/main/display/SOCVENDOR/JPEGPNG?preview=/149490188/234914840/image2014-5-14%2013%3A41%3A7.png

Performance Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^

We will update the content soon.

Design Constraints
^^^^^^^^^^^^^^^^^^^

We will update the content soon.

Functional Requirements
-----------------------

The data types and functions used in this module are as follows.

PNG Data Types
^^^^^^^^^^^^^^^^^^^^

 * :cpp:type:`HAL_PNG_PIXEL_FORMAT`
 * :cpp:type:`HAL_PNG_DECODE_OPTION_SCALING`

 * :cpp:struct:`HAL_PNG_RECT_T`
 * :cpp:struct:`HAL_PNG_DECODE_OPTION_T`
 * :cpp:struct:`HAL_PNG_ENCODE_OPTION_T`
 * :cpp:struct:`HAL_PNG_IMAGE_T`

PNG Function Calls
^^^^^^^^^^^^^^^^^^^^^^^

  * :cpp:func:`HAL_PNG_Open` //except from socts, this will be deleted
  * :cpp:func:`HAL_PNG_Decode` //except from socts, this will be deleted
  * :cpp:func:`HAL_PNG_Encode` //except from socts, this will be deleted
  * :cpp:func:`HAL_PNG_Close` //except from socts, this will be deleted
