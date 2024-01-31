Documentation
#############

.. warning::

  Follow the guide below to write a Module Implementation Guid.

  The main purpose of the Module Implementation Guid is to clearly communicate the background technical information, requirements, API specification information, etc. required for module development to enhance the SoC Vendor's module implementation completeness.

  Due to the characteristics of each module, there may be cases where the contents described below are not applicable or not appropriate to apply, in which case they can be omitted or modified.


.. contents:: Table of Contents
   :depth: 3
   :local: 

Introduction
************

Describe what is covered in the Module Implementation Guide and state any prerequisite conditions (knowledge of specific field/technology) required to understand the document.

.. panels::
  :column: col-lg-12 p-2

  Example
  ^^^^^^^

  *For example, the following is an introduction to the VSC module.*

  This document describes the Video Scaler (VSC) driver in the kernel space. The document gives an overview of the VSC driver and provides details about its functionalities and implementation requirements. 

  The VSC driver is based on the V4L2 framework. Therefore, the document assumes that the readers are familiar with the V4L2 API and framework principles, which include knowledge of V4L2 controls, buffer mana  gement, and streaming handling, among others.

  The VSC driver is responsible for performing video signal processing, video scaling, and video capture. Therefore, it is necessary to understand video processing techniques and scaling algorithms, including k  nowledge of video formats, resolutions, frame rates, color formats, etc.

Revision History
================

Provide the revision history for the Module Implementation Guide in the following format.

.. panels::
  :column: col-lg-12 p-2

  Template
  ^^^^^^^^

  .. list-table:: 
    :header-rows: 1

    * - Version
      - Date
      - Changed by
      - Description
    * - *Document version*
      - *Change date*
      - *Author of the change*
      - *Description of major changes*
    * - 1.0
      - 2023.xx.xx
      - xxx@lge.com
      - First release


Terminology
===========

Provide the technical terms, including abbreviations, used in the guide in the following format and sort them alphabetically.

Include only the full name for abbreviations of terms that are commonly used in the industry, and include both the full name and an explanation for terms that are defined by LGE or have a special meaning in this module guide.

.. panels::
  :column: col-lg-12 p-2

  Template
  ^^^^^^^^

  The key words "must", "must not", "required", "shall", "shall not", "should", "should not", "recommended", "may", and "optional" in this document are to be interpreted as described in RFC2119. 

  The following table lists the terms used throughout this document: 

  .. list-table:: 
    :header-rows: 1

    * - Term
      - Description
    * - English abbreviations or terms
      - The full name of the abbreviation in English (required). Description of the abbreviation (recommended)
    * - HDMI
      - High-Definition Multimedia Interface.
    * - SDP
      - Secondary Data Packet. Data transported over the Main-Link which is not main video stream data, such as audio data and Infoframe SDPs.


Technical Assistance
====================

Provide the email address of the LGE engineer responsible for technical support of the module.

.. panels::
  :column: col-lg-12 p-2

  Template
  ^^^^^^^^

  For assistance or clarification on information in this guide, please create an issue in the LGE JIRA project and contact the following person:

  .. list-table:: 
    :header-rows: 1

    * - Module
      - Owner
    * - Module name
      - xxx@lge.com

Overview
********

Provide the information necessary to understand the module before implementing it, including its role and key features, architecture information, and overall operational flow.

General Description
===================

A general introduction to the module, focusing on the role or responsibility of the module.

* If it is an industry-standard technology, provide a brief explanation of the standard (technical definition).
* The role and responsibilities of the module.
  *Why is this module necessary in webOS TV and what role does it play?


Features 
========

List the main features supported by the module.

* What functionalities does this module provide?
* Are there any LGE proprietary features?
* If there are any features or limitations not supported compared to the standard, mention them.
.. warning::

  If the length of the Features section is short, it can be included in the General Description.

Architecture
============

Provide architecture information that helps understand the overall structure and functionality of the module. Show an architecture diagram of the module and explain the roles of the components within the diagram.

In this section, you can provide the following types of architecture information:

  .. list-table:: 
    :header-rows: 1

    * - Architecture Type
      - Mandatory status
      - Description
    * - Driver Archiecture
      - Mandatory
      - - Demonstrates how the driver/module interacts and establishes relationships with the upper and lower layers from a platform architecture perspective.
        - You can utilize the existing diagram in the System Context section and make sure it reflects the following points: 
        
          - Is the diagram divided into User space, Kernel space, and Hardware layers?
        
          - Is it distinguished and indicated which parts are provided by the webOS platform and which parts should be implemented by the SoC Vendor, with a legend added for webOS and Vendor Specific?
    * - Hardware Architecture
      - Optional
      - - Shows how the hardware IP associated with the driver/module is configured in detail.
    * - Internal Architecture
      - Optional
      - - Shows how the internal components of the module are configured.

Overall Workflow (Optional)
===========================

Explain the overall flow of the main functions provided by the module using the following diagram:

- State diagram
- Call sequence
- Logic sequence


Requirements
************

Describes the requirements that must be met when implementing the module by a SoC vendor, divided into "Functional Requirements" and "Non-functional Requirements".

.. warning::

  When writing the Requirements section, specify the level of requirements according to the keyword criteria defined in RFC2119.

  The use of “MUST”, “MUST NOT”, “REQUIRED”, “SHALL”, “SHALL NOT”, “SHOULD”, “SHOULD NOT”, “RECOMMENDED”, “MAY”, and “OPTIONAL” is per the IETF standard defined in `RFC2119 <https://datatracker.ietf.org/doc/html/rfc2119>`_.

    .. list-table:: 
      :header-rows: 1

      * - Keyword
        - Different Expression
        - Meaning and Usage
      * - MUST
        - REQUIRED, SHALL
        - Means an absolute requirement that must be strictly followed.
      * - MUST NOT
        - SHALL NOT
        - Menas an absolute prohibition that must not be done under any circumstances.
      * - SHOULD
        - RECOMMENDED
        - Means that there may exist valid reasons in particular circumstances to ignore a particular item, but the full implications must be understood and carefully weighed before choosing a different course.
      * - SHOULD NOT
        - NOT RECOMMENDED
        - Means that there may exist valid reasons in particular circumstances when the particular behavior is acceptable or even useful, but the full implications should be understood and the case carefully weighed before implementing any behavior described with this label.
      * - MAY
        - OPTIONAL
        - Mean that an item is truly optional.

Functional Requirements
=======================

Describes the functional requirements that must be met when implementing the module.

Provides a detailed explanation of each specific functionality unit that can be performed through one or multiple APIs, including the roles and scenarios of each functionality and the requirements that must be met when implementing the functionality.

- An introduction/definition of the functionality provided
- Requirements for the flow of operations for each functionality
- Requirements for data processing and error handling for each functionality
- Requirements for the interface that the functionality provides to other modules

Quality and Constraints
=======================

Describes the non-functional requirements that must be met when implementing the module. Non-functional requirements include quality requirements and constraints. 

- Quality requirements describes the performance, security, reliability, compatibility, and other requirements that must be met from the perspective of the module's operation and usage scenarios (these are module-level requirements, not API-level requirements).
  - Requirements for security features that must be supported.
  - Minimum performance requirements to ensure consistent speed and responsiveness.
  - Requirements for reliability and interface compatibility to ensure stable operation, etc.

  .. panels::
    :column: col-lg-12 p-2

    Example
    ^^^^^^^^

    - The module must implement access control mechanisms to prevent unauthorized access to data.
    - The module must support fast switching, such as Instaport (HDMI quick switch). The input switching time between DisplayPort ports must be less than one second, assuming a webOS application is running in the background.
    - The module must have a fast startup time, with the video being displayed within 3 seconds after DC power is turned on.

- Constraints describes the software/hardware limitations and constraints that must be considered for the implementation of the module or to meet the requirements.
  - Constraints on standards that must be applied during implementation.
  - Constraints due to software or hardware limitations
  - Constraints that may be imposed by the characteristics of the module, etc.

  .. panels::
    :column: col-lg-12 p-2

    Example
    ^^^^^^^^

    - The module must be comply with ALSA standard.
    - Drivers cannot be used at the same time because the size or number of buffers to be captured differs depending on the purpose of video capture.
    - At least one Sndout Connection must be established to capture audio data.

.. warning::


  If there are multiple features provided by the module and you want to describe functional and non-functional requirements for each functional unit, you can also organize the Requirements chapter as follows:

  **Requirements**

  - Function A
    - Introduction to Function A: Describe what Function A is and provide an explanation of the related APIs.
    - Functional Requirements: Describe the functional requirements for Function A.
    - Quality and Constraints: Describe the non-functional (performance, security, quality, etc.) requirements for Function A.
  - Function B
    - Introduction to Function B: Describe what Function B is and provide an explanation of the related APIs.
    - Functional Requirements: Describe the functional requirements for Function B.
    - Quality and Constraints: Describe the non-functional (performance, security, quality, etc.) requirements for Function B.
  - ...

Implementation
**************

Describe in detail how to implement the module, including the location of the interface definition/implementation files, the order of API calls, and examples of implementations of all or major components of the module.

File Location
=============

State the path to the header file where the module's interface is defined within the BSP code delivered to the SoC vendor.

  .. panels::
    :column: col-lg-12 p-2

    Example
    ^^^^^^^^

    The OOO interfaces are defined in the OOO.h header file, which can be obtained from https://swfarmhub.lge.com/.

    - Git repository: bsp/ref/OOO-header
    - Location: [as_installed]/linux/OOO.h


API List 
========

Provide a summary of the data types and functions list for the interface of the module.

  .. panels::
    :column: col-lg-12 p-2

    Example
    ^^^^^^^^

    The OOO module implementation must adhere to the interface specifications defined and implements its functions. Refer to the API Reference (해당 모듈의 API Reference 링크 추가) for more details.

Data Types
----------

Provide a summarized list of data types for the module interface, categorized as follows. Exclude any categories that do not apply.

Standard Data Types
^^^^^^^^^^^^^^^^^^^

If there are Linux standard data types used in the module, provide a list as follows. Exclude if there are none.

.. list-table:: 
  :header-rows: 1

  * - Data Type
    - Description
  * - The name of data type (add a link to API Reference) 	
    - Description on the data type 

Extended Structures
^^^^^^^^^^^^^^^^^^^

If there is a list of extended structures defined by LGE, provide a list as follows. Exclude if there are none.

.. list-table:: 
  :header-rows: 1

  * - Data Type
    - Description
  * - The name of data type (add a link to API Reference) 	
    - Description on the data type 


Extended Enumerations
^^^^^^^^^^^^^^^^^^^^^

If there is a list of extended enumerations defined by LGE, provide a list as follows. Exclude if there are none.

.. list-table:: 
  :header-rows: 1

  * - Data Type
    - Description
  * - The name of data type (add a link to API Reference)
    - Description on the data type 

Functions
---------

Provide a summarized list of functions for the module interface, categorized as follows. Exclude any categories that do not apply.

Standard Functions
^^^^^^^^^^^^^^^^^^

If there are Linux standard functions used in the module, provide a list as follows. Exclude if there are none.

.. list-table:: 
  :header-rows: 1

  * - Function
    - Description
  * - The name of function (add a link to API Reference)
    - Brief description on the function
  * - The name of ioctl command (add a link to API Reference)	
    - Brief description on the ioctl command

Standard Control IDs
^^^^^^^^^^^^^^^^^^^^

If there are Linux standard control IDs used in the module, provide a list as follows. Exclude if there are none.

.. list-table:: 
  :header-rows: 1

  * - Function
    - Description
  * - The name of Control ID (add a link to API Reference)
    - Brief description on the function

Extended Functions
^^^^^^^^^^^^^^^^^^

If there are extended functions defined by LGE, provide a list as follows. Exclude if there are none.

.. list-table:: 
  :header-rows: 1

  * - Function
    - Description
  * - The name of function (add a link to API Reference)
    - Brief description on the function
  * - The name of ioctl command (add a link to API Reference)
    - Brief description on the ioctl command

Extended Control IDs
^^^^^^^^^^^^^^^^^^^^

If there are extended control IDs defined by LGE, provide a list as follows. Exclude if there are none.

.. list-table:: 
  :header-rows: 1

  * - Function
    - Description
  * - The name of Control ID (add a link to API Reference)
    - Brief description on the function

.. warning::

  If it is a Linux standard header, write the API List section as follows:

  **Data Types**

  Detailed description of each data type and a link to the Linux standard data type.

  **Functions**

  Detailed description of each API function and a link to the Linux standard function.

Implementation Details
======================

Provides detailed information related to module implementation, including guidelines and recommendations for enhancing implementation clarity and consistency, suggestions, implementation considerations, and example code if available.

- For the main functions of the module, describe any design peculiarities or considerations to be taken into account during implementation.

  .. panels::
    :column: col-lg-12 p-2

    Example
    ^^^^^^^^

    The OOO module includes functions to ~~ for supported devices:

    - The OOO function ~~
    - The OOO function ~~

- For the main functions of the module, describe any design peculiarities or considerations to be taken into account during implementation.
  - If there is a specific code implementation sequence, explain it with diagrams.
  - If there is an implementation checklist, describe it.

  .. panels::
    :column: col-lg-12 p-2

    Example
    ^^^^^^^^

    To implement Dynamic Aspect Ratio, complete these checklist:

      - Implement the interface that directly receives resolution, AFD, and PAR information from the VDEC driver.
      - Implement :c:macro:`V4L2_CID_EXT_VSC_ASPECTRATIO_POLICY` that receives Aspect Ratio UI and Policy from the videooutputd service
      - Implement export_vsc_adapter. Aspect Ratio Library use export_vsc_adapter to register the callback of ``aspectratiodrvCalculateWindow()``.
      - When the Adaptive Stream flag is 2 (Dynamic Aspect Ratio Mode), calculate the aspect ratio from ``aspectratiodrvCalculateWindow()`` registered in export_vsc_adapter and scaled in units of frames.
      - When scaling aspect ratio by changing resolution, AFD, and PAR, it should be applied seamlessly.

- If there are example codes for the module/driver, provide them.

Status Log (Optional)
=====================

Provides guidance on logging the status of the module (applicable to modules that support a Status Log file).

  .. panels::
    :column: col-lg-12 p-2

    Example
    ^^^^^^^^

    To examine the status and operation of the OOO module, you can use the status log file, a text-based log file. For more information, refer to Status Log File.


Debugging (Optional)
********************

If there are any tips for debugging the implemented module, describe them here.

Testing
*******

Provides guidance on SoCTS testing (applicable to modules that support SoCTS Producer).

  .. panels::
    :column: col-lg-12 p-2

    Example


    To test the implementation of the VSC driver, webOS provides SoCTS (SoC Test Suite) tests. The SoCTS checks the basic operation of the VSC driver and verifies the kernel event operation for the module by using a test execution file. For details, see OOO Unit Test in SoCTS Unit Test Specification.

References
**********

Provides a reference list of relevant technical standards or specifications that may be helpful for implementing the module.

  .. panels::
    :column: col-lg-12 p-2

    Example
    ^^^^^^^

    For additional information on related standards or technical topics, refer to:

    - Linux Documentation 
    - Wiki
    - ...

.. warning::

  | For Linux Documentation, provides a direct link to the page where the information can be referenced, rather than the home page.
  | For internal resources, provides links accessible to SoC vendors.
