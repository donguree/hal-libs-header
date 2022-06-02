UCOM
==========

History
-------

======= ========== ============== =====================================
Version Date       Changed by     Comment
======= ========== ============== =====================================
1.0.0   2022-04-13 joonwoo.hong   First release
1.0.1   2022-06-02 joonwoo.hong   Modify documentation format
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
Definitions of terms and abbreviations used in this document are as follows.

================================= ===============================================================
Definition                        Description
================================= ===============================================================
IR                                infrared, used for remote control
RTC                               Real Time Clock
CEC                               Consumer Electronics Control
WOL/WOWL                          Wake On LAN / Wake On Wireless LAN
ADC                               Analog to Digital Converter
ISR                               Interrupt Service Routine
Instant Boot                      same with QSM+ boot or STR boot
BDP                               Burnt Detect Protection
Micom-libs                        Execute IPC communication between micom F/W and other services.
================================= ===============================================================

System Context
^^^^^^^^^^^^^^
.. image:: /ucom/micom_system_context.png
  :width: 100%
  :alt: UCOM system context


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

typedef UINT32 (* UCOM_KEY_CALLBACK_T) (UINT8 value, UINT8 repeat );

typedef enum {
	OK					= 0,
	NOT_OK				= -1,
	INVALID_PARAMS		= -2,
	TIMEOUT 			= -3,
} DRV_STATUS_T;

typedef struct KEY_DATA_T {
	UINT8 Cus;
	UINT8 xorCus;
	UINT8 Key;
	UINT8 xorKey;
} KEY_DATA;

typedef enum PWM_ChNum {
	PWM_CH0,
	PWM_CH1,
	PWM_CH2,
	PWM_CH3,
	PWM_CH4,
	PWM_CH5,
	PWM_CH6,
	PWM_CH7,
} PWM_ChNum;

typedef struct TIME_T {
	UINT8 YearHigh;
	UINT8 YearLow;
	UINT8 Month;
	UINT8 Week;
	UINT8 Day;
	UINT8 Hour;
	UINT8 Min;
	UINT8 Sec;
	UINT8 Mode;
	UINT8 enable_flag;
	UINT8 force_disable;
} TIME;

typedef enum UART_BAUDRATE_T
{
	BAUDRATE_2400 = 0,
	BAUDRATE_4800,
	BAUDRATE_9600,
	BAUDRATE_14400,
	BAUDRATE_19200,
	BAUDRATE_38400,
	BAUDRATE_57600,
	BAUDRATE_115200,
	BAUDRATE_460800,
	BAUDRATE_UNKNOWN
} UART_BAUDRATE_TYPE;

Function Calls
^^^^^^^^^^^^^^

  * :func:`HAL_UCOM_Initialize`
  * :func:`HAL_UCOM_ReadCommand`
  * :func:`HAL_UCOM_WriteCommand`
  * :func:`HAL_UCOM_WholeChipReset`

*. UCOM FW DRV Function List The definition below is MICOM-related Driver Function List information.
   Functions such as simple port change are replaced with Description.
   The sample is written in any one of SoC Vendor because the driver's internal implementation method is different for each SoC.
   Therefore, it is used as a reference, not a mandatory requirement.


Reference Function Calls
^^^^^^^^^^^^^^^^^^^^^^^^

  * :func:`DRV_PowerOff`
  * :func:`DRV_PowerOn`
  * :func:`DRV_IR_Init`
  * :func:`DRV_IR_Enable`
  * :func:`DRV_IR_Disable`
  * :func:`DRV_IR_GetRawData`
  * :func:`DRV_IR_ClearBuf`
  * :func:`DRV_ADC_Init`
  * :func:`DRV_ADC_Read`
  * :func:`DRV_CEC_Init`
  * :func:`DRV_CEC_Enable`
  * :func:`DRV_CEC_Disable`
  * :func:`DRV_CEC_SendMessage`
  * :func:`DRV_CEC_ReceiveMessage`
  * :func:`DRV_WOL_Enable`
  * :func:`DRV_WOL_Disable`
  * :func:`DRV_WOL_Get_Status`
  * :func:`DRV_WOWL_Enable`
  * :func:`DRV_WOWL_Disable`
  * :func:`DRV_WOV_Enable`
  * :func:`DRV_WOV_Disable`
  * :func:`DRV_IPC_Init`
  * :func:`DRV_IPC_ReadBuffer`
  * :func:`DRV_IPC_WriteBuffer`
  * :func:`DRV_NVM_Init`
  * :func:`DRV_NVM_Read`
  * :func:`DRV_NVM_Write`
  * :func:`DRV_PWM_Init`
  * :func:`DRV_PWM_SetDuty`
  * :func:`DRV_PWM_GetDuty`
  * :func:`DRV_RTC_Init`
  * :func:`DRV_RTC_SetCounter`
  * :func:`DRV_RTC_GetCounter`
  * :func:`DRV_GPIO_init`
  * :func:`DRV_GPIO_Set`
  * :func:`DRV_GPIO_Get`
  * :func:`DRV_GPIO_SetDirection`
  * :func:`DRV_TIMER_Init`
  * :func:`DRV_TIMER_Delayms`
  * :func:`DRV_UART_Init`
  * :func:`DRV_UART_Enable`
  * :func:`DRV_UART_Disable`
  * :func:`DRV_UART_GetLine`
  * :func:`DRV_UART_ClearBuf`
  * :func:`DRV_UART_SetBaudrate`

Implementation
--------------

DRV_PowerOff
^^^^^^^^^^^^

.. function:: DRV_PowerOff(BOOLEAN fSTR)

    **Description**

        Set 'SoC Vendor' Driver Power Off Sequence Start (LG power off flow -> Driver power off flow)

    **Syntax**

        DRV_STATUS_T DRV_PowerOff(BOOLEAN fSTR)

    **Parameters**

        BOOLEAN fSTR

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_PowerOff(BOOLEAN fSTR) {
          IF DRV Power Off succeeds THEN
            RETURN OK
          ELSE
            RETURN NOT_OK
        ENDIF
        }

    **See Also**

        None

DRV_PowerOn
^^^^^^^^^^^

.. function:: DRV_PowerOn(void)

    **Description**

        Set SoC Vendor¡± Driver Power On Sequence Start (LG power on flow -> Driver power on flow)

    **Syntax**

        DRV_STATUS_T DRV_PowerOn(void)

    **Parameters**

        None

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_PowerOn(void) {

          IF DRV Power On succeeds THEN
            RETURN OK
          ELSE
            RETURN NOT_OK
          ENDIF
        }

    **See Also**

        None

DRV_IR_Init
^^^^^^^^^^^

.. function:: DRV_IR_Init(void)

    **Description**

        Set Remocon Driver Settings Initialize in this function

    **Syntax**

        void DRV_IR_Init(void)

    **Parameters**

        None

    **Return Value**

        None

    **Remarks**

        None

    **Pseudo Code**

        void DRV_IR_Init(void) {

          Set Remocon Driver Settings Initialize

        }

    **See Also**

        None

DRV_IR_Enable
^^^^^^^^^^^^^

.. function:: DRV_IR_Enable(void)

    **Description**

        Set Remocon Process Start in this function

    **Syntax**

        void DRV_IR_Enable(void)

    **Parameters**

        None

    **Return Value**

        None

    **Remarks**

        None

    **Pseudo Code**

        void DRV_IR_Enable(void) {

          Set Remocon Process Start
        }

    **See Also**

        None

DRV_IR_Disable
^^^^^^^^^^^^^^

.. function:: DRV_IR_Disable(void)

    **Description**

        Set Remocon Process Stop in this function(during key block mode)

    **Syntax**

        void DRV_IR_Disable(void)

    **Parameters**

        None

    **Return Value**

        None

    **Remarks**

        None

    **Pseudo Code**

        void DRV_IR_Disable(void) {

          Set Remocon Process Stop

        }

    **See Also**

        None

DRV_IR_GetRawData
^^^^^^^^^^^^^^^^^

.. function:: DRV_IR_GetRawData(KEY_DATA *raw_data, UINT8 *keytype)

    **Description**

        Read Remocon Raw Data from Driver in this function (Driver send Original IR received data to LG application)

    **Syntax**

        DRV_STATUS_T DRV_IR_GetRawData(KEY_DATA *raw_data, UINT8 *keytype)

    **Parameters**

        KEY_DATA *raw_data UINT8 *keytype

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_IR_GetRawData(KEY_DATA *raw_data, UINT8 *keytype) {

          // Read Remocon Raw Data from Driver IF Read Data succeeds THEN

            RETURN OK

          ELSE
            RETURN NOT_OK
          ENDIF
        }

    **See Also**

        None

DRV_IR_ClearBuf
^^^^^^^^^^^^^^^

.. function:: DRV_IR_ClearBuf(void)

    **Description**

        Set Remocon buffer and values clear in this function

    **Syntax**

        void DRV_IR_ClearBuf(void)

    **Parameters**

        None

    **Return Value**

        None

    **Remarks**

        None

    **Pseudo Code**

        void DRV_IR_ClearBuf(void) {

          // Clear Driver Buffer

        }

    **See Also**

        None

DRV_ADC_Init
^^^^^^^^^^^^

.. function:: DRV_ADC_Init(void)

    **Description**

        Set Local Key Driver Settings Initialize in this function

    **Syntax**

        void DRV_ADC_Init(void)

    **Parameters**

        None

    **Return Value**

        None

    **Remarks**

        None

    **Pseudo Code**

        void DRV_ADC_Init(void) {

          // Initialize Local Key Driver Settings

        }

    **See Also**

        None

DRV_ADC_Read
^^^^^^^^^^^^

.. function:: DRV_ADC_Read(UINT8 index)

    **Description**

        Read Local Key ADC Data from Driver in this function

    **Syntax**

        UINT8 DRV_ADC_Read(UINT8 index)

    **Parameters**

        UINT8 index

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        UINT8 DRV_ADC_Read(UINT8 index) {

          // Read Local Key ADC Data from Driver IF Read Data succeeds THEN

            RETURN OK
          ELSE
            RETURN NOT_OK
          ENDIF
        }

    **See Also**

        None

DRV_CEC_Init
^^^^^^^^^^^^

.. function:: DRV_CEC_Init(void)

    **Description**

        Set CEC host controller Initialize in this function

    **Syntax**

        DRV_STATUS_T DRV_CEC_Init(void)

    **Parameters**

        None

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_CEC_Init(void) {
          // CEC host controller Initialize IF CEC initialize succeeds THEN
            RETURN OK
          ELSE
            RETURN NOT_OK
          ENDIF
        }

    **See Also**

        None

DRV_CEC_Enable
^^^^^^^^^^^^^^

.. function:: DRV_CEC_Enable(void)

    **Description**

        Set CEC host controller Enable in this function (LG application get CEC data from ¡°SoC Vendor¡± Driver)

    **Syntax**

        DRV_STATUS_T DRV_CEC_Enable(void)

    **Parameters**

        None

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_CEC_Enable(void) {

          // CEC host controller Enable IF CEC enable succeeds THEN

            RETURN OK

          ELSE
            RETURN NOT_OK

          ENDIF
        }

    **See Also**

        None

DRV_CEC_Disable
^^^^^^^^^^^^^^^

.. function:: DRV_CEC_Disable(void)

    **Description**

        Set CEC host controller Disable in this function (LG application didn¡¯t get CEC data from ¡°SoC Vendor¡± Driver)

    **Syntax**

        DRV_STATUS_T DRV_CEC_Disable(void)

    **Parameters**

        None

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_CEC_Disable(void) {

          // CEC host controller Disable IF CEC disable succeeds THEN

            RETURN OK

          ELSE
            RETURN NOT_OK

          ENDIF
        }

    **See Also**

        None

DRV_CEC_SendMessage
^^^^^^^^^^^^^^^^^^^

.. function:: DRV_CEC_SendMessage(UINT8 dest, UINT8* send_data, UINT8 send_len)

    **Description**

        Set Data to a specified CEC device

    **Syntax**

        DRV_STATUS_T DRV_CEC_SendMessage(UINT8 dest, UINT8* send_data, UINT8 send_len)

    **Parameters**

        UINT8 dest UINT8* send_data UINT8 send_len

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_CEC_SendMessage(UINT8 dest, UINT8* send_data, UINT8 send_len) {

          // Set Data to a specified CEC device IF Send CEC message Data succeeds THEN

            RETURN OK

          ELSE
            RETURN NOT_OK

          ENDIF
        }

    **See Also**

        None

DRV_CEC_ReceiveMessage
^^^^^^^^^^^^^^^^^^^^^^

.. function:: DRV_CEC_ReceiveMessage(UINT8* p_hdr, UINT8* p_buff, UINT8 buff_size, UINT8* p_rcv_len)

    **Description**

        Read Data from CEC Controller

    **Syntax**

        DRV_STATUS_T DRV_CEC_ReceiveMessage(UINT8* p_hdr, UINT8* p_buff, UINT8 buff_size, UINT8* p_rcv_len)

    **Parameters**

        UINT8* p_hdr UINT8* p_buff UINT8 buff_size UINT8* p_rcv_len

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_CEC_ReceiveMessage(UINT8* p_hdr, UINT8* p_buff, UINT8 buff_size, UINT8* p_rcv_len) {

          // Read Data from CEC Controller IF Read Data succeeds THEN

            RETURN OK

          ELSE
            RETURN NOT_OK

          ENDIF
        }

    **See Also**

        None

DRV_WOL_Enable
^^^^^^^^^^^^^^

.. function:: DRV_WOL_Enable(void)

    **Description**

        Set WOL wake up operation Enable (Driver change to wake up settings on)

    **Syntax**

        DRV_STATUS_T DRV_WOL_Enable(void)

    **Parameters**

        None

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_WOL_Enable(void) {

          // Set wake up operation ON

        }

    **See Also**

        None

DRV_WOL_Disable
^^^^^^^^^^^^^^^

.. function:: DRV_WOL_Disable(void)

    **Description**

        Set WOL wake up operation Disable (Driver set to wake up mode off)

    **Syntax**

        DRV_STATUS_T DRV_WOL_Disable(void)

    **Parameters**

        None

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_WOL_Disable(void) {

          // Set wake up operation OFF

        }

    **See Also**

        None

DRV_WOL_Get_Status
^^^^^^^^^^^^^^^^^^

.. function:: DRV_WOL_Get_Status(void)

    **Description**

        Read WOL wake up signal from ¡°SoC Vendor¡± Driver

    **Syntax**

        UINT32 DRV_WOL_Get_Status(void)

    **Parameters**

        None

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        UINT32 DRV_WOL_Get_Status(void) {

          // Get wake up signal happened or not

        }

    **See Also**

        None

DRV_WOWL_Enable
^^^^^^^^^^^^^^^

.. function:: DRV_WOWL_Enable(void)

    **Description**

        Set WOWL wake up operation Enable (Driver change to wake up settings on)

    **Syntax**

        DRV_STATUS_T DRV_WOWL_Enable(void)

    **Parameters**

        None

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_WOWL_Enable(void) {

          // Set wake up operation ON

        }

    **See Also**

        None

DRV_WOWL_Disable
^^^^^^^^^^^^^^^^

.. function:: DRV_WOWL_Disable(void)

    **Description**

        Set WOWL wake up operation Disable (Driver set to wake up mode off)

    **Syntax**

        DRV_STATUS_T DRV_WOWL_Disable(void)

    **Parameters**

        None

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_WOWL_Disable(void) {

          // Set wake up operation OFF

        }

    **See Also**

        None

DRV_WOV_Enable
^^^^^^^^^^^^^^

.. function:: DRV_WOV_Enable(void)

    **Description**

        Set WOV wake up operation Enable (Driver change to wake up settings on)

    **Syntax**

        DRV_STATUS_T DRV_WOV_Enable(void)

    **Parameters**

        None

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_WOV_Enable(void) {

          // Set wake up operation ON

        }

    **See Also**

        None

DRV_WOV_Disable
^^^^^^^^^^^^^^

.. function:: DRV_WOV_Disable(void)

    **Description**

        Set WOV wake up operation Disable (Driver set to wake up mode off)

    **Syntax**

        DRV_STATUS_T DRV_WOV_Disable(void)

    **Parameters**

        None

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_WOV_Disable(void) {

          // Set wake up operation OFF

        }

    **See Also**

        None

DRV_IPC_Init
^^^^^^^^^^^^

.. function:: DRV_IPC_Init(void)

    **Description**

        Set IPC Settings Initialize in this function (Main SoC <-> Micom FW communication feature)

    **Syntax**

        void DRV_IPC_Init(void)

    **Parameters**

        None

    **Return Value**

        None

    **Remarks**

        None

    **Pseudo Code**

        void DRV_IPC_Init(void) {

          // Set IPC Settings Initialize

        }

    **See Also**

        None

DRV_IPC_ReadBuffer
^^^^^^^^^^^^^^^^^^

.. function:: DRV_IPC_ReadBuffer(UINT8 *len ,UINT8 *data)

    **Description**

        Read IPC buffer data (Read data from share memory)

    **Syntax**

        DRV_STATUS_T DRV_IPC_ReadBuffer(UINT8 *len ,UINT8 *data)

    **Parameters**

        UINT8 *len, UINT8 *data

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_IPC_ReadBuffer(UINT8 *len ,UINT8 *data) {

          // Read IPC buffer data IF Read buffer data succeeds THEN

            RETURN OK

          ELSE
            RETURN NOT_OK

          ENDIF
        }

    **See Also**

        None

DRV_IPC_WriteBuffer
^^^^^^^^^^^^^^^^^^^

.. function:: DRV_IPC_WriteBuffer(UINT8 nLength , UINT8* pData)

    **Description**

        Write IPC buffer data (Write data to share memory)

    **Syntax**

        DRV_STATUS_T DRV_IPC_WriteBuffer(UINT8 nLength , UINT8* pData)

    **Parameters**

        UINT8 nLength, UINT8* pData

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        Pseudo Code DRV_STATUS_T DRV_IPC_WriteBuffer(UINT8 nLength , UINT8* pData) {

          // Write IPC buffer data IF Write buffer data succeeds THEN

            RETURN OK

          ELSE
            RETURN NOT_OK

          ENDIF
        }

    **See Also**

        None

DRV_NVM_Init
^^^^^^^^^^^^

.. function:: DRV_NVM_Init(void)

    **Description**

        Set NVM Settings Initialize in this function (Main SoC EEPROM access feature)

    **Syntax**

        DRV_STATUS_T DRV_NVM_Init(void)

    **Parameters**

        None

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_NVM_Init(void) {

          // NVM Settings Initialize

        }

    **See Also**

        None

DRV_NVM_Read
^^^^^^^^^^^^

.. function:: DRV_NVM_Read(UINT16 addr, UINT8 *rdata, UINT8 rdata_len)

    **Description**

        Read NVM buffer data (Read data from EEPROM¡¯s micomDB)

    **Syntax**

        DRV_STATUS_T DRV_NVM_Read(UINT16 addr, UINT8 *rdata, UINT8 rdata_len)

    **Parameters**

        UINT16 addr, UINT8 *rdata, UINT8 rdata_len

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_NVM_Read(UINT16 addr, UINT8 *rdata, UINT8 rdata_len) {

          // Read NVM buffer data IF Read buffer data succeeds THEN

            RETURN OK

          ELSE
            RETURN NOT_OK

          ENDIF
        }

    **See Also**

        None

DRV_NVM_Write
^^^^^^^^^^^^^

.. function:: DRV_NVM_Write(UINT16 addr, UINT8 *wdata, UINT16 wdata_len)

    **Description**

        Write NVM buffer data (Write data to EEPROM¡¯s micomDB)

    **Syntax**

        DRV_STATUS_T DRV_NVM_Write(UINT16 addr, UINT8 *wdata, UINT16 wdata_len)

    **Parameters**

        UINT16 addr, UINT8 *wdata, UINT16 wdata_len

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_NVM_Write(UINT16 addr, UINT8 *wdata, UINT16 wdata_len) {

          // Write NVM buffer data IF Write buffer data succeeds THEN

            RETURN OK

          ELSE
            RETURN NOT_OK

          ENDIF
        }

    **See Also**

        None

DRV_PWM_Init
^^^^^^^^^^^^

.. function:: DRV_PWM_Init(void)

    **Description**

        Set PWM Settings Initialize in this function

    **Syntax**

        void DRV_PWM_Init(void)

    **Parameters**

        None

    **Return Value**

        None

    **Remarks**

        None

    **Pseudo Code**

        void DRV_PWM_Init(void) {
          // PWM Settings Initialize
        }

    **See Also**

        None

DRV_PWM_SetDuty
^^^^^^^^^^^^^^^

.. function:: DRV_PWM_SetDuty(PWM_ChNum idx, UINT8 pwm_duty)

    **Description**

        Set PWM Duty change in this function

    **Syntax**

        DRV_STATUS_T DRV_PWM_SetDuty(PWM_ChNum idx, UINT8 pwm_duty)

    **Parameters**

        PWM_ChNum idx, UINT8 pwm_duty

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_PWM_SetDuty(PWM_ChNum idx, UINT8 pwm_duty) {
          // Set PWM Duty
        }

    **See Also**

        None

DRV_PWM_GetDuty
^^^^^^^^^^^^^^^

.. function:: DRV_PWM_GetDuty(PWM_ChNum idx)

    **Description**

        Get current PWM Duty value

    **Syntax**

        UINT8 DRV_PWM_GetDuty(PWM_ChNum idx)

    **Parameters**

        PWM_ChNum idx

    **Return Value**

        If this function succeeds, the return value is PWM Duty.

    **Remarks**

        None

    **Pseudo Code**

        UINT8 DRV_PWM_GetDuty(PWM_ChNum idx) {
          // Get PWM Duty
          // return PWM Duty
        }

    **See Also**

        None

DRV_RTC_Init
^^^^^^^^^^^^

.. function:: DRV_RTC_Init(void)

    **Description**

        Set RTC Settings Initialize in this function

    **Syntax**

        DRV_STATUS_T DRV_RTC_Init(void)

    **Parameters**

        None

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_RTC_Init(void) {
          // RTC Settings Initialize
        }

    **See Also**

        None

DRV_RTC_SetCounter
^^^^^^^^^^^^^^^^^^

.. function:: DRV_RTC_SetCounter(TIME *gSystemTime)

    **Description**

        Set Current Time in this function

    **Syntax**

        DRV_STATUS_T DRV_RTC_SetCounter(TIME *gSystemTime)

    **Parameters**

        TIME *gSystemTime

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_RTC_SetCounter(TIME *gSystemTime) {
          // Set RTC Time
        }

    **See Also**

        None

DRV_RTC_GetCounter
^^^^^^^^^^^^^^^^^^

.. function:: DRV_RTC_GetCounter(TIME *gSystemTime)

    **Description**

        Get Current Time in this function

    **Syntax**

        DRV_STATUS_T DRV_RTC_GetCounter(TIME *gSystemTime)

    **Parameters**

        PWM_ChNum idx

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_RTC_GetCounter(TIME *gSystemTime) {
          // Get RTC time
        }

    **See Also**

        None

DRV_GPIO_init
^^^^^^^^^^^^^

.. function:: DRV_GPIO_init(void)

    **Description**

        Set GPIO Settings Initialize in this function
        (Port Map Table, Port Property, Port Default Value, ....)

    **Syntax**

        DRV_STATUS_T DRV_GPIO_init(void)

    **Parameters**

        None

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_GPIO_init(void) {
          // GPIO Settings Initialize
        }

    **See Also**

        None

DRV_GPIO_Set
^^^^^^^^^^^^

.. function:: DRV_GPIO_Set(UINT8 port, UINT8 value)

    **Description**

        Set GPIO Settings

    **Syntax**

        DRV_STATUS_T DRV_GPIO_Set(UINT8 port, UINT8 value)

    **Parameters**

        UINT8 port, UINT8 value

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_GPIO_Set(UINT8 port, UINT8 value) {
          // Set GPIO value
        }

    **See Also**

        None

DRV_GPIO_Get
^^^^^^^^^^^^

.. function:: DRV_GPIO_Get(UINT8 port)

    **Description**

        Get GPIO Value

    **Syntax**

        DRV_STATUS_T DRV_GPIO_Get(UINT8 port)

    **Parameters**

        PWM_ChNum idx

    **Return Value**

        If this function succeeds, the return value is GPIO Level.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_GPIO_Get(UINT8 port) {
          // Get GPIO value with port
          // return GPIO level(HIGH/LOW)
        }

    **See Also**

        None

DRV_GPIO_SetDirection
^^^^^^^^^^^^^^^^^^^^^

.. function:: DRV_GPIO_SetDirection(UINT8 port, UINT8 direction)

    **Description**

        Set GPIO Driections

    **Syntax**

        DRV_STATUS_T DRV_GPIO_SetDirection(UINT8 port, UINT8 direction)

    **Parameters**

        UUINT8 port, UINT8 direction

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_GPIO_SetDirection(UINT8 port, UINT8 direction) {
          // Set GPIO direction
        }

    **See Also**

        None

DRV_TIMER_Init
^^^^^^^^^^^^^^

.. function:: DRV_TIMER_Init(void)

    **Description**

        Set Timer Settings Initialize in this function

    **Syntax**

        void DRV_TIMER_Init(void)

    **Parameters**

        None

    **Return Value**

        None

    **Remarks**

        None

    **Pseudo Code**

        void DRV_TIMER_Init(void) {
          // Timer Settings Initialize
        }

    **See Also**

        None

DRV_TIMER_Delayms
^^^^^^^^^^^^^^^^^

.. function:: DRV_TIMER_Delayms(UINT32 msec)

    **Description**

        Set Timer Delay in this function (base on millisecond)

    **Syntax**

        void DRV_TIMER_Delayms(UINT32 msec)

    **Parameters**

        UINT32 msec

    **Return Value**

        UINT32 msec

    **Remarks**

        None

    **Pseudo Code**

        void DRV_TIMER_Delayms(UINT32 msec) {
          // Set Timer Delay
        }

    **See Also**

        None

DRV_UART_Init
^^^^^^^^^^^^^

.. function:: DRV_UART_Init(void)

    **Description**

        If need to initialize UART, set UART.

    **Syntax**

        void DRV_UART_Init(void)

    **Parameters**

        None

    **Return Value**

        None

    **Remarks**

        None

    **Pseudo Code**

        void DRV_UART_Init(void) {
          // set uart setting
          // reset offset to zero
        }

    **See Also**

        None

DRV_UART_Enable
^^^^^^^^^^^^^^^

.. function:: DRV_UART_Enable(void)

    **Description**

        If there is only one UART resource, enable it so that Micom can use it.

    **Syntax**

        void DRV_UART_Enable(void)

    **Parameters**

        None

    **Return Value**

        None

    **Remarks**

        None

    **Pseudo Code**

        void DRV_UART_Enable(void) {
          //disable uart interrupt in scpu
          //enable uart interrupt in emcu
          //UART Interrupt Enable
        }

    **See Also**

        None

DRV_UART_Disable
^^^^^^^^^^^^^^^^

.. function:: DRV_UART_Disable(void)

    **Description**

        If there is only one UART resource, disable it so that SoC can use it.

    **Syntax**

        void DRV_UART_Disable(void)

    **Parameters**

        None

    **Return Value**

        None

    **Remarks**

        None

    **Pseudo Code**

        void DRV_UART_Disable(void) {
          //make sure urat0 data is empty
          //disable uart interrupt in emcu
          //UART Interrupt Disable
        }

    **See Also**

        None

DRV_UART_GetLine
^^^^^^^^^^^^^^^^

.. function:: DRV_UART_GetLine(UINT8 *line)

    **Description**

        The input string for 3 seconds is passed as a parameter.

    **Syntax**

        DRV_STATUS_T DRV_UART_GetLine(UINT8 *line)

    **Parameters**

        UINT8 *line

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_UART_GetLine(UINT8 *line) {
          // Get CR/LF, return DataBuf
          // User only press CR/LF, no meaning, clear
          // if timeout, clear
          return OK;
        }

    **See Also**

        None

DRV_UART_ClearBuf
^^^^^^^^^^^^^^^^^

.. function:: DRV_UART_ClearBuf(void)

    **Description**

        After 3 seconds, the Uart buffer is cleared. There is no need if it is handled to be cleared in DRV_UART_GetLine().

    **Syntax**

        DRV_STATUS_T DRV_UART_ClearBuf(void)

    **Parameters**

        None

    **Return Value**

        If this function succeeds, the return value is OK. If this function fails, the return value is NOT_OK.

    **Remarks**

        None

    **Pseudo Code**

        DRV_STATUS_T DRV_UART_ClearBuf(void) {
          UartBufPos = 0;
          return OK;
        }

    **See Also**

        None

DRV_UART_SetBaudrate
^^^^^^^^^^^^^^^^^^^^

.. function:: DRV_UART_SetBaudrate(UART_BAUDRATE_TYPE baudrate)

    **Description**

        Set uart's baudrate to 9600 or 115200.

    **Syntax**

        void DRV_UART_SetBaudrate(UART_BAUDRATE_TYPE baudrate)

    **Parameters**

        UART_BAUDRATE_TYPE baudrate

    **Return Value**

        None

    **Remarks**

        None

    **Pseudo Code**

        void DRV_UART_SetBaudrate(UART_BAUDRATE_TYPE baudrate) {
          if(baudrate == BAUDRATE_9600)
            //set uart baudrate 9600
          else
            //set uart baudrate 115200
          }

    **See Also**

        None

