UCOM
==========

History
-------

======= ========== ============== =====================================
Version Date       Changed by     Comment
======= ========== ============== =====================================
1.0.0   2022-04-13 joonwoo.hong   1st edit for API Implementation Guide
0.0.0   ...        ...            ...
======= ========== ============== =====================================

Overall Description
--------------------

The Internal Micom module is included inside the Main SOC.
This is controlled using IPC communication between Main SOC and Micom.(ex. MailBox Commuication)

The main features are as follows.
   1. Remote control and local key scan function.
   2. External interrupt processing through GPIO port control(AMP Mute, WOL/WOWL, etc)
   3. RTC function
   4. Timer function(On Timer, Reservation, OTA, etc)
   5. Power Management

After the Micom standardization work, the inside of FW is also divided into LG Application Layer (common area) and Driver Layer (separated area).
LG Application <-> API is provided to exchange information between drivers.

Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

================================= ======================================
Definition                        Description
================================= ======================================
IR                                infrared, used for remote control
RTC                               Real Time Clock
CEC                               Consumer Electronics Control
WOL/WOWL                          Wake On LAN / Wake On Wireless LAN
ADC                               Analog to Digital Converter
ISR                               ISRÀº Interrupt Handler Routine
Instant Boot                      same with QSM+ boot or STR boot
BDP                               Burnt Detect Protection
================================= ======================================

System Context
^^^^^^^^^^^^^^
.. image:: micom_system_context.png
  :width: 100%
  :alt: UCOM system context

================================= ===============================================================
Definition                        Description
================================= ===============================================================
Micom-libs                        Execute IPC communication between micom F/W and other services.
================================= ===============================================================

Performance Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^

It'll be updated continuous.

Design Constraints
^^^^^^^^^^^^^^^^^^^

It'll be updated continuous.

Functional Requirements
-----------------------

The data types and functions used in this module are as follows.

Data Types
^^^^^^^^^^^^

1. HAL_UCOM_Initialize(UCOM_KEY_CALLBACK_T   pIRCallback, UCOM_KEY_CALLBACK_T   pLKCallback)

Description
Initialize IR / Local Key process in this function

Syntax
DTV_STATUS_T HAL_UCOM_Initialize(UCOM_KEY_CALLBACK_T   pIRCallback, UCOM_KEY_CALLBACK_T   pLKCallback)

Parameters
UCOM_KEY_CALLBACK_T   pIRCallback
UCOM_KEY_CALLBACK_T   pLKCallback

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DTV_STATUS_T HAL_UCOM_Initialize(UCOM_KEY_CALLBACK_T   pIRCallback, UCOM_KEY_CALLBACK_T   pLKCallback)
{
     IF UCOM initialization succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF

 }

See Also
None

======================================================================================================

2. HAL_UCOM_WriteCommand(UINT8 *pCmd, UINT16 size)
Description
Set Write Command between MainSOC and PM

Syntax
DTV_STATUS_T HAL_UCOM_WriteCommand(UINT8 *pCmd, UINT16 size)

Parameters
UINT8 *pCmd
UINT16 size

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DTV_STATUS_T HAL_UCOM_WriteCommand(UINT8 *pCmd, UINT16 size)
{

     IF UCOM write succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF

 }

See Also
None

======================================================================================================

3.HAL_UCOM_ReadCommand(UINT8 cmd, UINT16 dataSize, UINT8 *pData)
Description
Set Read Command between MainSOC and PM

Syntax
DTV_STATUS_T HAL_UCOM_ReadCommand(UINT8 cmd, UINT16 dataSize, UINT8 *pData)

Parameters
UINT8 cmd
UINT16 dataSize
UINT8 *pData

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DTV_STATUS_T HAL_UCOM_ReadCommand(UINT8 cmd, UINT16 dataSize, UINT8 *pData)
{

     IF UCOM read succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF

 }

See Also
None

======================================================================================================

4. HAL_UCOM_WholeChipReset(void)
Description
Set Micom & SoC Reset Function

Syntax
void HAL_UCOM_WholeChipReset(void)

Parameters
None

Return Value
None

Remarks
None

Pseudo Code
void HAL_UCOM_WholeChipReset(void)
{

    // Set PM & SoC Reset Operation Register

 }

See Also
None

======================================================================================================

*. UCOM FW DRV Function List
The definition below is MICOM-related Driver Function List information.
Functions such as simple port change are replaced with Description.\

The sample is written in any one of "SoC Vendor" because the driver's internal implementation method is different for each SoC.
Therefore, it is used as a reference, not a mandatory requirement.

==== =============================================================================== ========================================================================
No   Function Name                                                                   Description
==== =============================================================================== ========================================================================
1    DRV_STATUS_T DRV_PowerOff(BOOLEAN fSTR)                                         Set "SoC Vendor" Driver Power Off Sequence Start
                                                                                     (LG power off flow ¡æ Driver power off flow)
2	 DRV_STATUS_T DRV_PowerOn(void)	Set                                              "SoC Vendor" Driver Power On Sequence Start
                                                                                     (LG power on flow ¡æ Driver power on flow)
3	 void DRV_IR_Init(void)	                                                         Set Remocon Driver Settings Initialize in this function
4	 void DRV_IR_Enable(void)	                                                     Set Remocon Process Start in this function
5	 void DRV_IR_Disable(void)	                                                     Set Remocon Process Stop in this function(during key block mode)
6	 DRV_STATUS_T DRV_IR_GetRawData(KEY_DATA *raw_data, UINT8 *keytype)	             Read Remocon Raw Data from Driver in this function
                                                                                     (Driver send Original IR received data to LG application)
7	 void DRV_IR_ClearBuf(void)	                                                     Set Remocon buffer and values clear in this function
8	 void DRV_ADC_Init(void)	                                                     Set Local Key Driver Settings Initialize in this function
9	 UINT8 DRV_ADC_Read(UINT8 index)	                                             Read Local Key ADC Data from Driver in this function
10	 DRV_STATUS_T DRV_CEC_Init(void)	                                             Set CEC host controller Initialize in this function
11	 DRV_STATUS_T DRV_CEC_Enable(void)	                                             Set CEC host controller Enable in this function
                                                                                     (LG application get CEC data from "SoC Vendor" Driver)
12	 DRV_STATUS_T DRV_CEC_Disable(void)	                                             Set CEC host controller Disable in this function
                                                                                     (LG application didn't get CEC data from "SoC Vendor" Driver)
13	 DRV_STATUS_T DRV_CEC_SendMessage(UINT8 dest, UINT8* send_data, UINT8 send_len)	 Set Data to a specified CEC device
14	 DRV_STATUS_T DRV_CEC_ReceiveMessage                                             Read Data from CEC Controller
     (UINT8* p_hdr, UINT8* p_buff, UINT8 buff_size, UINT8* p_rcv_len)
15	 DRV_STATUS_T DRV_WOL_Enable(void)	                                             Set WOL wake up operation Enable (Driver change to wake up settings on)
16	 DRV_STATUS_T DRV_WOL_Disable(void)	                                             Set WOL wake up operation Disable (Driver set to wake up mode off)
17	 UINT32 DRV_WOL_Get_Status(void)	                                             Read WOL wake up signal from "SoC Vendor" Driver
18	 void DRV_WOWL_Enable(void)	                                                     Set WOWL wake up operation Enable (Driver change to wake up settings on)
19	 void DRV_WOWL_Disable(void)	                                                 Set WOWL wake up operation Disable (Driver set to wake up mode off)
20	 DRV_STATUS_T DRV_WOV_Enable(void)	                                             Set WOV wake up operation Enable (Driver change to wake up settings on)
21	 DRV_STATUS_T DRV_WOV_Disable(void)	                                             Set WOV wake up operation Disable (Driver set to wake up mode off)
22	 void DRV_IPC_Init(void)	                                                     Set IPC Settings Initialize in this function
                                                                                     (Main SoC ¡ê Micom FW communication feature)
23	 DRV_STATUS_T DRV_IPC_ReadBuffer(UINT8 *len ,UINT8 *data)	                     Read IPC buffer data (Read data from share memory)
24	 DRV_STATUS_T DRV_IPC_WriteBuffer(UINT8 nLength , UINT8* pData)	                 Write IPC buffer data (Write data to share memory)
25	 DRV_STATUS_T DRV_NVM_Init(void)	                                             Set NVM Settings Initialize in this function
                                                                                     (Main SoC EEPROM access feature)
26	 DRV_STATUS_T DRV_NVM_Read(UINT16 addr, UINT8 *rdata, UINT8 rdata_len)	         Read NVM buffer data (Read data from EEPROM's micomDB)
27	 DRV_STATUS_T DRV_NVM_Write(UINT16 addr, UINT8 *wdata, UINT16 wdata_len)	     Write NVM buffer data (Write data to EEPROM's micomDB)
28	 void DRV_PWM_Init(void)	                                                     Set PWM Settings Initialize in this function
29	 DRV_STATUS_T DRV_PWM_SetDuty(PWM_ChNum idx, UINT8 pwm_duty)	                 Set PWM Duty change in this function
30	 UINT8 DRV_PWM_GetDuty(PWM_ChNum idx)	                                         Get current PWM Duty value
31	 DRV_STATUS_T DRV_RTC_Init(void)	                                             Set RTC Settings Initialize in this function
32	 DRV_STATUS_T DRV_RTC_SetCounter(TIME *gSystemTime)	                             Set Current Time in this function
33	 DRV_STATUS_T DRV_RTC_GetCounter(TIME *gSystemTime)	                             Get Current Time in this function
34	 DRV_STATUS_T DRV_GPIO_init(void)	                                             Set GPIO Settings Initialize in this function
                                                                                     (Port Map Table, Port Property, Port Default Value, ....)
35	 DRV_STATUS_T DRV_GPIO_Set(UINT8 port, UINT8 value)	                             Set GPIO Settings
36	 DRV_STATUS_T DRV_GPIO_Get(UINT8 port)	                                         Get GPIO Settings
37	 DRV_STATUS_T DRV_GPIO_SetDirection(UINT8 port, UINT8 direction)	             Set GPIO Driections
38	 void DRV_TIMER_Init(void)	                                                     Set Timer Settings Initialize in this function
39	 void DRV_TIMER_Delayms(UINT32 msec)	                                         Set Timer Delay in this function (base on millisecond)
==== =============================================================================== ========================================================================

Description
Set "SoC Vendor" Driver Power Off Sequence Start
(LG power off flow ¡æ Driver power off flow)

Syntax
DRV_STATUS_T DRV_PowerOff(BOOLEAN fSTR)

Parameters
BOOLEAN fSTR

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_PowerOff(BOOLEAN fSTR)
{
     IF DRV Power Off succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF

 }

Example


See Also
None

=======================================================================================================

Description
Set SoC Vendor" Driver Power On Sequence Start
(LG power on flow ¡æ Driver power on flow)

Syntax
DRV_STATUS_T DRV_PowerOn(void)

Parameters
void

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_PowerOn(void)
{
     IF DRV Power On succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF

 }

Example


See Also
None

=======================================================================================================

Description
Set Remocon Driver Settings Initialize in this function

Syntax
void DRV_IR_Init(void)

Parameters
None

Return Value
None

Remarks
None

Pseudo Code
void DRV_IR_Init(void)
{
     Set Remocon Driver Settings Initialize
}

Example
None

See Also
None

=======================================================================================================

Description
Set Remocon Process Start in this function

Syntax
void DRV_IR_Enable(void)

Parameters
None

Return Value
None

Remarks
None

Pseudo Code
void DRV_IR_Enable(void)
{
     Set Remocon Process Start
}

Example
None

See Also
None

=======================================================================================================

Description
Set Remocon Process Stop in this function(during key block mode)

Syntax
void DRV_IR_Disable(void)

Parameters
None

Return Value
None

Remarks
None

Pseudo Code
void DRV_IR_Disable(void)
{
     Set Remocon Process Stop
}

Example
None

See Also
None

=======================================================================================================

Description
Read Remocon Raw Data from Driver in this function
(Driver send Original IR received data to LG application)

Syntax
DRV_STATUS_T DRV_IR_GetRawData(KEY_DATA *raw_data, UINT8 *keytype)

Parameters
KEY_DATA *raw_data
UINT8 *keytype

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_IR_GetRawData(KEY_DATA *raw_data, UINT8 *keytype)
{
     // Read Remocon Raw Data from Driver
     IF Read Data succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF

}

Example


See Also
None

=======================================================================================================

Description
Set Remocon buffer and values clear in this function

Syntax
void DRV_IR_ClearBuf(void)

Parameters
None

Return Value
None

Remarks
None

Pseudo Code
void DRV_IR_ClearBuf(void)
{
     // Clear Driver Buffer
}

Example
None

See Also
None

=======================================================================================================

Description
Set Local Key Driver Settings Initialize in this function

Syntax
void DRV_ADC_Init(void)

Parameters
None

Return Value
None

Remarks
None

Pseudo Code
void DRV_ADC_Init(void)
{
     // Initialize Local Key Driver Settings
}

Example
None

See Also
None

=======================================================================================================

Description
Read Local Key ADC Data from Driver in this function

Syntax
UINT8 DRV_ADC_Read(UINT8 index)

Parameters
UINT8 index

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
UINT8 DRV_ADC_Read(UINT8 index)
{
     // Read Local Key ADC Data from Driver
     IF Read Data succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF

}

Example


See Also
None

=======================================================================================================

Description
Set CEC host controller Initialize in this function

Syntax
DRV_STATUS_T DRV_CEC_Init(void)

Parameters
None

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_CEC_Init(void)
{
     // CEC host controller Initialize
     IF CEC initialize succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF

}

Example
None

See Also
None

=======================================================================================================

Description
Set CEC host controller Enable in this function
(LG application get CEC data from "SoC Vendor" Driver)

Syntax
DRV_STATUS_T DRV_CEC_Enable(void)

Parameters
None

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_CEC_Enable(void)
{
     // CEC host controller Enable
     IF CEC enable succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF

}

Example


See Also
None

=======================================================================================================

Description
Set CEC host controller Disable in this function
(LG application didn't get CEC data from "SoC Vendor" Driver)

Syntax
DRV_STATUS_T DRV_CEC_Disable(void)

Parameters
None

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_CEC_Disable(void)
{
     // CEC host controller Disable
     IF CEC disable succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF

}

Example


See Also
None

=======================================================================================================

Description
Set Data to a specified CEC device

Syntax
DRV_STATUS_T DRV_CEC_SendMessage(UINT8 dest, UINT8* send_data, UINT8 send_len)

Parameters
UINT8 dest
UINT8* send_data
UINT8 send_len

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_CEC_SendMessage(UINT8 dest, UINT8* send_data, UINT8 send_len)
{
     // Set Data to a specified CEC device
     IF Send CEC message Data succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF

}

Example


See Also
None

=======================================================================================================

Description
Read Data from CEC Controller

Syntax
DRV_STATUS_T DRV_CEC_ReceiveMessage(UINT8* p_hdr, UINT8* p_buff, UINT8 buff_size, UINT8* p_rcv_len)

Parameters
UINT8* p_hdr
UINT8* p_buff
UINT8 buff_size
UINT8* p_rcv_len

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_CEC_ReceiveMessage(UINT8* p_hdr, UINT8* p_buff, UINT8 buff_size, UINT8* p_rcv_len)
{
     // Read Data from CEC Controller
     IF Read Data succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF

}

Example


See Also
None

=======================================================================================================

Description
Set WOL wake up operation Enable (Driver change to wake up settings on)

Syntax
DRV_STATUS_T DRV_WOL_Enable(void)

Parameters
None

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_WOL_Enable(void)
{
     // Set wake up operation ON
}

Example


See Also
None

=======================================================================================================

Description
Set WOL wake up operation Disable (Driver set to wake up mode off)

Syntax
DRV_STATUS_T DRV_WOL_Disable(void)

Parameters
None

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_WOL_Disable(void)
{
     // Set wake up operation OFF
}

Example


See Also
None

=======================================================================================================

Description
Read WOL wake up signal from "SoC Vendor" Driver

Syntax
UINT32 DRV_WOL_Get_Status(void)

Parameters
None

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
UINT32 DRV_WOL_Get_Status(void)
{
     // Get wake up signal happened or not
}

Example
None

See Also
None

=======================================================================================================

Description
Set WOWL wake up operation Enable (Driver change to wake up settings on)

Syntax
DRV_STATUS_T DRV_WOWL_Enable(void)

Parameters
None

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_WOWL_Enable(void)
{
     // Set wake up operation ON
}

Example


See Also
None

=======================================================================================================

Description
Set WOWL wake up operation Disable (Driver set to wake up mode off)

Syntax
DRV_STATUS_T DRV_WOWL_Disable(void)

Parameters
None

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_WOWL_Disable(void)
{
     // Set wake up operation OFF
}

Example


See Also
None

=======================================================================================================

Description
Set WOV wake up operation Enable (Driver change to wake up settings on)

Syntax
DRV_STATUS_T DRV_WOV_Enable(void)

Parameters
None

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_WOV_Enable(void)
{
     // Set wake up operation ON
}

Example


See Also
None

=======================================================================================================

Description
Set WOV wake up operation Disable (Driver set to wake up mode off)

Syntax
DRV_STATUS_T DRV_WOV_Disable(void)

Parameters
None

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_WOV_Disable(void)
{
     // Set wake up operation OFF
}

Example


See Also
None

=======================================================================================================

Description
Set IPC Settings Initialize in this function
(Main SoC ¡ê Micom FW communication feature)

Syntax
void DRV_IPC_Init(void)

Parameters
None

Return Value
None

Remarks
None

Pseudo Code
void DRV_IPC_Init(void)
{
     // Set IPC Settings Initialize
}

Example


See Also
None

=======================================================================================================

Description
Read IPC buffer data (Read data from share memory)

Syntax
DRV_STATUS_T DRV_IPC_ReadBuffer(UINT8 *len ,UINT8 *data)

Parameters
UINT8 *len
UINT8 *data

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_IPC_ReadBuffer(UINT8 *len ,UINT8 *data)
{
     // Read IPC buffer data
     IF Read buffer data succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF
}

Example


See Also
None

=======================================================================================================

Description
Write IPC buffer data (Write data to share memory)

Syntax
DRV_STATUS_T DRV_IPC_WriteBuffer(UINT8 nLength , UINT8* pData)

Parameters
UINT8 nLength
UINT8* pData

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_IPC_WriteBuffer(UINT8 nLength , UINT8* pData)
{
     // Write IPC buffer data
     IF Write buffer data succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF
}

Example


See Also
None

=======================================================================================================

Description
Set NVM Settings Initialize in this function
(Main SoC EEPROM access feature)

Syntax
DRV_STATUS_T DRV_NVM_Init(void)

Parameters
None

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_NVM_Init(void)
{
     // NVM Settings Initialize
}

Example


See Also
None

=======================================================================================================

Description
Read NVM buffer data (Read data from EEPROM's micomDB)

Syntax
DRV_STATUS_T DRV_NVM_Read(UINT16 addr, UINT8 *rdata, UINT8 rdata_len)

Parameters
UINT16 addr
UINT8 *rdata
UINT8 rdata_len

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_NVM_Read(UINT16 addr, UINT8 *rdata, UINT8 rdata_len)
{
     // Read NVM buffer data
     IF Read buffer data succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF
}

Example


See Also
None

=======================================================================================================

Description
Write NVM buffer data (Write data to EEPROM's micomDB)

Syntax
DRV_STATUS_T DRV_NVM_Write(UINT16 addr, UINT8 *wdata, UINT16 wdata_len)

Parameters
UINT16 addr
UINT8 *wdata
UINT16 wdata_len

Return Value
If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

Remarks
None

Pseudo Code
DRV_STATUS_T DRV_NVM_Write(UINT16 addr, UINT8 *wdata, UINT16 wdata_len)
{
     // Write NVM buffer data
     IF Write buffer data succeeds THEN
          RETURN OK

     ELSE
          RETURN NOT_OK

     ENDIF
}

Example


See Also
None

Function Calls
^^^^^^^^^^^^^^^

  * :cpp:func:`HAL_UCOM_Initialize`
  * :cpp:func:`HAL_UCOM_ReadCommand`
  * :cpp:func:`HAL_UCOM_WriteCommand`
  * :cpp:func:`HAL_UCOM_WholeChipReset`

