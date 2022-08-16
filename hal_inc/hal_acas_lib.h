/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 1999 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file 		hal_acas_lib.h
 *
 *  header of ACAS LIB HAL Fuction.
 *
 *
 *  @author		Takashi Matsumoto (takashi.matsumoto@lgjlab.com)
 *  @author
 *  @version	1.0
 *  @date		2018.8.29 Takashi Matsumoto (takashi.matsumoto@lgjlab.com)
 *  @date		2018.8.29 Created
 *  @date
 *  @note		Additional information.
 *  @see
 */

/******************************************************************************
 	Header File Guarder
******************************************************************************/
#ifndef _ACAS_LIB_HAL_H_
#define _ACAS_LIB_HAL_H_

/******************************************************************************
	Control Constants
******************************************************************************/

/******************************************************************************
	File Inclusions
******************************************************************************/
#include "hal_common.h"

/******************************************************************************
	Constant Definitions
******************************************************************************/

/******************************************************************************
	Macro Definitions
******************************************************************************/

/******************************************************************************
	Type Definitions
******************************************************************************/
/**
 * @brief Defines return values for ACAS Library functions
 */
typedef enum
{
    HAL_ACAS_LIB_OK                         =   0,
    HAL_ACAS_LIB_NOT_OK                     =   -1,

    HAL_ACAS_LIB_PARAMETER_ERROR            =   -2,
    HAL_ACAS_LIB_INVALID_PARAMS             =   -2,
    HAL_ACAS_LIB_GETRANDOMDATA_FAILED       =   -3,
    HAL_ACAS_LIB_GETSECUREDATA_FAILED       =   -4,
    HAL_ACAS_LIB_CRC_FAILED                 =   -5,
    HAL_ACAS_LIB_SHA_FAILED                 =   -6,
    HAL_ACAS_LIB_AES_FAILED                 =   -7,
    HAL_ACAS_LIB_NOT_READY                  =   -8,
    HAL_ACAS_LIB_INSTANCE_FULL              =   -9,
    HAL_ACAS_LIB_INSTANCE_ALREADY_ADDED     =   -10,
    HAL_ACAS_LIB_INSTANCE_NOT_FOUND         =   -11,

}   _HAL_ACAS_LIB_STATE_T;
#define HAL_ACAS_LIB_STATE_T    _HAL_ACAS_LIB_STATE_T

/**
 * @brief Odd/Even definition of descrambling key
 */
typedef enum
{
    ACAS_KEY_ODD                    =   1,
    ACAS_KEY_EVEN                   =   0,
}   _ACAS_KEY_STATE_T;
#define ACAS_KEY_STATE_T    _ACAS_KEY_STATE_T

/**
 * @brief This structure contains the scrambled packets and descrambling info
 */
typedef struct {
	/** Specify odd/even key */
	unsigned int keyFlag;
	/** Initial counter value, See ARIB spec for details */
	unsigned char counterValue[ 20 ];
	/** Input scrambled packets, output descrambled packets */
	unsigned char *pInOutData;
	/** pInOutData length */
	unsigned int dataLen;
} ACAS_LIB_DESCRAMBLE_INFO;

/******************************************************************************
	Function Declaration
******************************************************************************/
/**
 * @brief Clear each parameter, should be called only once at startup.
 *
 * @rst
 * Functional Requirements
 *   Clear each parameter, should be called only once at startup.
 *
 * Responses to abnormal situations, including
 *   No abnormal cases, always successful.
 *
 * Performance Requirements
 *   None
 *
 * Constraints
 *   Since each parameter is cleared,
 *   call it only once at begin regardless of the number of tuners.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *	   dev_index [in] Since this value isn't referenced, any value can be used.
 *
 * Return Value
 *   Returns the value of HAL_ACAS_LIB_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if( 0 == HAL_ACAS_LIB_Initialize( 1 ) ) {
 *       printf( "HAL_ACAS_LIB_OK" );
 *     }
 *     else {
 *       printf( "System error" );
 *     }
 *
 * @endrst
 */
DTV_STATUS_T HAL_ACAS_LIB_Initialize( unsigned int dev_index );

/**
 * @brief Clear each parameter, paired with the Initialize() function.
 *
 * @rst
 * Functional Requirements
 *   Clear each parameter, paired with the Initialize() function.
 *
 * Responses to abnormal situations, including
 *   No abnormal cases, always successful.
 *
 * Performance Requirements
 *   None
 *
 * Constraints
 *   Since each parameter is cleared,
 *   call it only once at end regardless of the number of tuners.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *	   dev_index [in] Since this value isn't referenced, any value can be used.
 *
 * Return Value
 *   Returns the value of HAL_ACAS_LIB_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if( 0 == HAL_ACAS_LIB_DeInitialize( 1 ) ) {
 *       printf( "HAL_ACAS_LIB_OK" );
 *     }
 *     else {
 *       printf( "System error" );
 *     }
 *
 * @endrst
 */
DTV_STATUS_T HAL_ACAS_LIB_DeInitialize( unsigned int dev_index );

/**
 * @brief Register the tuner to be descrambled.
 *
 * @rst
 * Functional Requirements
 *   Register the tuner to be descrambled.
 *   dev_index should be managed by the caller.
 *
 * Responses to abnormal situations, including
 *   Abnormal situations, returns *_INSTANCE_FULL or *_INSTANCE_ALREADY_ADDED.
 *
 * Performance Requirements
 *   The maximum number of tuners that can be registered is 3.
 *
 * Constraints
 *   Open() dev_index should be Close() when it is no longer needed.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *	   dev_index [in] The index of the tuner managed by the caller, any value.
 *
 * Return Value
 *   Returns the value of HAL_ACAS_LIB_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if( 0 == HAL_ACAS_LIB_Open( any tuner value ) ) {
 *       printf( "HAL_ACAS_LIB_OK" );
 *     }
 *     else {
 *       printf( "Open error" );
 *     }
 *
 * @endrst
 */
DTV_STATUS_T HAL_ACAS_LIB_Open( unsigned int dev_index );

/**
 * @brief Unregister the tuner index, must be paired with Open().
 *
 * @rst
 * Functional Requirements
 *   Unregister the tuner index, must be paired with Open().
 *
 * Responses to abnormal situations, including
 *   Abnormal situations, returns *_INSTANCE_NOT_FOUND.
 *
 * Performance Requirements
 *   None
 *
 * Constraints
 *   dev_index registered with Open() is unregistered.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *	   dev_index [in] dev_index value to unregister, registered with Open().
 *
 * Return Value
 *   Returns the value of HAL_ACAS_LIB_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if( 0 == HAL_ACAS_LIB_Close( value registered with Open() ) ) {
 *       printf( "HAL_ACAS_LIB_OK" );
 *     }
 *     else {
 *       printf( "Close error" );
 *     }
 *
 * @endrst
 */
DTV_STATUS_T HAL_ACAS_LIB_Close( unsigned int dev_index );

/**
 * @brief Get the value of the CKC command to send to ACAS.
 *
 * @rst
 * Functional Requirements
 *   Get the value of the CKC command to send to ACAS.
 *   Calculate the values required for the CKC command.
 *
 * Responses to abnormal situations, including
 *   Abnormal situations, returns the value other than *_OK.
 *
 * Performance Requirements
 *   None
 *
 * Constraints
 *   This function must be able to access the ACAS Keys stored in SeData.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *	   dev_index [in] dev_index value registered with Open().
 *	   pOutParam [out] Stores the parameters used in the CKC command.
 *	   pOutParamSize [out] Stores pOutParam length.
 *
 * Return Value
 *   Returns the value of HAL_ACAS_LIB_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     unsigned char ckcParam[ 16 ] = { 0, };
 *     unsigned int ckcParamSize = 16;
 *     if( 0 == HAL_ACAS_LIB_GetScrambleKeyProtectCommandParam(
 *         dev_index, ckcParam, &ckcParamSize ) ) {
 *       printf( "HAL_ACAS_LIB_OK" );
 *     }
 *     else {
 *       printf( "GetScrambleKeyProtectCommandParam error" );
 *     }
 *
 * @endrst
 */
DTV_STATUS_T HAL_ACAS_LIB_GetScrambleKeyProtectCommandParam ( unsigned int dev_index, unsigned char *pOutParam, unsigned int* pOutParamSize );

/**
 * @brief Prepare the descrambling key using the ACAS response of the CKC cmd.
 *
 * @rst
 * Functional Requirements
 *   Prepare the descrambling key using the ACAS response of the CKC command.
 *
 * Responses to abnormal situations, including
 *   Abnormal situations, returns the value other than *_OK.
 *
 * Performance Requirements
 *   None
 *
 * Constraints
 *   The CKC command shall succeed and pass its response.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *	   dev_index [in] dev_index value registered with Open().
 *	   pInRes [in] Response data for CKC command.
 *	   nInResSize [in] pInRes length.
 *
 * Return Value
 *   Returns the value of HAL_ACAS_LIB_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     unsigned char ckcResponse[ 1024 ] = CKC command response;
 *     unsigned int ckcResponseLength = CKC command response length;
 *     if( 0 == HAL_ACAS_LIB_SetScrambleKeyProtectCommandRes(
 *         dev_index, ckcResponse, ckcResponseLength ) ) {
 *       printf( "HAL_ACAS_LIB_OK" );
 *     }
 *     else {
 *       printf( "SetScrambleKeyProtectCommandRes error" );
 *     }
 *
 * @endrst
 */
DTV_STATUS_T HAL_ACAS_LIB_SetScrambleKeyProtectCommandRes ( unsigned int dev_index, unsigned char *pInRes, unsigned int nInResSize );

/**
 * @brief Obsolete
 *
 * @rst
 * Functional Requirements
 *   Obsolete
 *
 * Responses to abnormal situations, including
 *   None
 *
 * Performance Requirements
 *   None
 *
 * Constraints
 *   None
 *
 * Functions & Parameters
 *   None
 *
 * Return Value
 *   None
 *
 * Example
 *   .. code-block:: cpp
 *
 *     Obsolete...
 *
 * @endrst
 */
DTV_STATUS_T HAL_ACAS_LIB_UpdateKey( unsigned int dev_index, unsigned char *cs_key, unsigned int nKeyLength, unsigned char *ecm_data, unsigned int nLength );

/**
 * @brief Generate a descrambling key using the ECM section data and response.
 *
 * @rst
 * Functional Requirements
 *   Generate a descrambling key using the ECM section data and response.
 *
 * Responses to abnormal situations, including
 *   Abnormal situations, returns the value other than *_OK.
 *
 * Performance Requirements
 *   None
 *
 * Constraints
 *   SetScrambleKeyProtectCommandRes() must have succeeded.
 *   If the ECM doesn't set the Odd/Even Key alternately, an error will occur.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *	   dev_index [in] dev_index value registered with Open().
 *	   cs_key [in] Response data for ECM command.
 *	   nKeyLength [in] cs_key length.
 *	   ecm_data [in] ECM section data.
 *	   nLength [in] ecm_data length.
 *
 * Return Value
 *   Returns the value of HAL_ACAS_LIB_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     unsigned char ecmResponse[ 1024 ] = ECM command response;
 *     unsigned int ecmResponseLength = ECM command response length;
 *     unsigned char ecmSection[ 512 ] = ECM section info;
 *     unsigned int ecmSectionLength = ecmSection length;
 *     if( 0 == HAL_ACAS_LIB_SetDescrambleKey(
 *         dev_index, ecmResponse, ecmResponseLength,
 *         ecmSection, ecmResponseLength ) ) {
 *       printf( "HAL_ACAS_LIB_OK" );
 *     }
 *     else {
 *       printf( "SetDescrambleKey error" );
 *     }
 *
 * @endrst
 */
DTV_STATUS_T HAL_ACAS_LIB_SetDescrambleKey( unsigned int dev_index, unsigned char *cs_key, unsigned int nKeyLength, unsigned char *ecm_data, unsigned int nLength );

/**
 * @brief Clear the monitor flag for setting the odd/even key alternately.
 *
 * @rst
 * Functional Requirements
 *   Odd/Even Key can't be received alternately due to channel change
 *   or switching between free/paid broadcasting.
 *   Call this function in such cases to clear the monitor flag.
 *
 * Responses to abnormal situations, including
 *   Abnormal situations, returns *_INSTANCE_NOT_FOUND.
 *
 * Performance Requirements
 *   None
 *
 * Constraints
 *   None
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *	   dev_index [in] dev_index value registered with Open().
 *
 * Return Value
 *   Returns the value of HAL_ACAS_LIB_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if( 0 == HAL_ACAS_LIB_ClearDescrambleKey( dev_index ) ) {
 *       printf( "HAL_ACAS_LIB_OK" );
 *     }
 *     else {
 *       printf( "ClearDescrambleKey error" );
 *     }
 *
 * @endrst
 */
DTV_STATUS_T HAL_ACAS_LIB_ClearDescrambleKey( unsigned int dev_index );

/**
 * @brief Descramble and return the scrambled MMTP packet.
 *
 * @rst
 * Functional Requirements
 *   Descramble and return the scrambled MMTP packet.
 *
 * Responses to abnormal situations, including
 *   Abnormal situations, returns the value other than *_OK.
 *
 * Performance Requirements
 *   Only one MMTP packet can be descrambled.
 *   Therefore, this function has a performance problem,
 *   so the Descramble_ext() function,
 *   which can descramble all at once, is mainly used.
 *
 * Constraints
 *   None
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *	   dev_index [in] dev_index value registered with Open().
 *	   pCounterValue [in] Initial counter value, see ARIB spec.
 *	   pKeyFlag [in] Specify odd/even key required for descrambling, not pointer
 *	   pInOutData [in,out] Scrambled MMTP packet. Descramble and store.
 *	   nLength [in] pInOutData length
 *
 * Return Value
 *   Returns the value of HAL_ACAS_LIB_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     char counterValue[ 16 ] = Calculated with reference to ARIB spec;
 *     unsigned int scrambleKey = ACAS_KEY_ODD or ACAS_KEY_EVEN;
 *     unsigned char mmtpPackets[ 1500 ] = MMTP packets received from broadcast;
 *     unsigned int mmtpPacketLength = mmtpPackets length;
 *     if( 0 == HAL_ACAS_LIB_Descramble(
 *         dev_index, counterValue, scrambleKey,
 *         mmtpPackets, mmtpPacketLength ) ) {
 *       printf( "HAL_ACAS_LIB_OK" );
 *     }
 *     else {
 *       printf( "Descramble error" );
 *     }
 *
 * @endrst
 */
DTV_STATUS_T HAL_ACAS_LIB_Descramble( unsigned int dev_index, unsigned char* pCounterValue, unsigned int pKeyFlag, unsigned char* pInOutData, unsigned int nLength );

/**
 * @brief Secure Data will be transferred to TEE by calling this functions.
 *
 * @rst
 * Functional Requirements
 *   This API will transfer the secure data, which are "acas_key", "acas_iv"
 *   and "acas_parameter_file", from Normal World to Secure World.
 *   Must be called before GetScrambleKeyProtectCommandParam() function.
 *
 * Responses to abnormal situations, including
 *   Abnormal situations, returns the value other than *_OK.
 *
 * Performance Requirements
 *   None
 *
 * Constraints
 *   None
 *
 * Functions & Parameters
 *   None
 *
 * Return Value
 *   Returns the value of HAL_ACAS_LIB_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     if( 0 == HAL_ACAS_LIB_ReadSecureData() ) {
 *       printf( "HAL_ACAS_LIB_OK" );
 *     }
 *     else {
 *       printf( "ReadSecureData error" );
 *     }
 *
 * @endrst
 */
DTV_STATUS_T HAL_ACAS_LIB_ReadSecureData( void );

/**
 * @brief Specify various information held by ACAS Lib.
 *
 * @rst
 * Functional Requirements
 *   Specify various information held by ACAS Lib.
 *   Get and refer to the specified parameter with GetStatus().
 *
 * Responses to abnormal situations, including
 *   Abnormal situations, returns *_INVALID_PARAMS or *_INSTANCE_NOT_FOUND.
 *
 * Performance Requirements
 *   None
 *
 * Constraints
 *   None
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *	   pStatus [in]
 *	     Specify the following character string for each info you want to get.
 *	     "version", "dev_index=", "reset_ready_for_descramble_flag"...
 *	   nLength [in]
 *	     String length including Index, used when "dev_index=" is specified.
 *
 * Return Value
 *   Returns the value of HAL_ACAS_LIB_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     char statusString[ 24 ] = "dev_index=00000001";
 *     if( 0 == HAL_ACAS_LIB_DEBUG_SetStatus(
 *         statusString, strlen( statusString ) ) ) {
 *       printf( "HAL_ACAS_LIB_OK" );
 *     }
 *     else {
 *       printf( "SetStatus error" );
 *     }
 *
 * @endrst
 */
DTV_STATUS_T HAL_ACAS_LIB_DEBUG_SetStatus( void *pStatus, int nLength );

/**
 * @brief Get the parameter specified by SetStatus().
 *
 * @rst
 * Functional Requirements
 *   Get the parameter specified by SetStatus().
 *
 * Responses to abnormal situations, including
 *   Abnormal situations, returns *_INVALID_PARAMS.
 *
 * Performance Requirements
 *   None
 *
 * Constraints
 *   SetStatus() must be specified before calling this function.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *	   pStatus [out] Store the parameters specified by SetStatus().
 *	   nLength [out] pStatus length.
 *
 * Return Value
 *   Returns the value of HAL_ACAS_LIB_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     char param[256] = { 0, };
 *     int paramLength = 0;
 *     if( 0 == HAL_ACAS_LIB_DEBUG_GetStatus( paramBuf, *paramLength ) ) {
 *       printf( "HAL_ACAS_LIB_OK" );
 *     }
 *     else {
 *       printf( "GetStatus error" );
 *     }
 *
 * @endrst
 */
DTV_STATUS_T HAL_ACAS_LIB_DEBUG_GetStatus( void *pStatus, int *pLength );

/**
 * @brief Descramble multiple scrambled MMTP packets together.
 *
 * @rst
 * Functional Requirements
 *   Descramble multiple scrambled MMTP packets together.
 *
 * Responses to abnormal situations, including
 *   Abnormal situations, returns the value other than *_OK.
 *
 * Performance Requirements
 *   None
 *
 * Constraints
 *   The maximum length of one MMTP packet is 1500 bytes.
 *   The num of packets that can be descrambled together differs for each SoC.
 *   If the number of packets to be descrambled exceeds 1800,
 *   it is better to check the size supported by the SoC.
 *
 * Functions & Parameters
 *   .. code-block:: cpp
 *
 *	   dev_index [in] dev_index value registered with Open().
 *	   pDescrambleInfo [in,out] Array pointer for ACAS_LIB_DESCRAMBLE_INFO.
 *	   numInfo [in] Number of pDescrambleInfo
 *
 * Return Value
 *   Returns the value of HAL_ACAS_LIB_STATE_T.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     char counterValue[ 16 ] = Calculated with reference to ARIB spec;
 *     unsigned int scrambleKey = ACAS_KEY_ODD or ACAS_KEY_EVEN;
 *     unsigned char mmtpPackets[ 1500 ] = MMTP packets received from broadcast;
 *     unsigned int mmtpPacketLength = mmtpPackets length;
 *
 *     ACAS_LIB_DESCRAMBLE_INFO packet;
 *     packet.keyFlag = scrambleKey;
 *     memcpy( packet.counterValue, counterValue, 16 );
 *     packet.pInOutData = mmtpPackets;
 *     packet.dataLen = mmtpPacketLength;
 *
 *     std::vector<ACAS_LIB_DESCRAMBLE_INFO> packetsArray;
 *     // Push multiple packets
 *     packetsArray.push_back( packet );
 *
 *     if( 0 == HAL_ACAS_LIB_Descramble_ext(
 *         dev_index, packetsArray.data(), packetsArray.size() ) ) {
 *       printf( "HAL_ACAS_LIB_OK" );
 *     }
 *     else {
 *       printf( "Descramble_ext error" );
 *     }
 *
 * @endrst
 */
DTV_STATUS_T HAL_ACAS_LIB_Descramble_ext(
    unsigned int dev_index,
    ACAS_LIB_DESCRAMBLE_INFO *pDescrambleInfo,
    unsigned int numInfo );
#endif /*_ACAS_LIB_HAL_H_ */
