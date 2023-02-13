/******************************************************************************
 *   TV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2023 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file       optee_keymaster3_device.h
 *
 *  This source file defines WebOS Secure Storage Function
 *
 *  @author     hedaesik.kim@lge.com
 *  @author     hedaesik.kim@lge.com
 *  @version    1.0
 *  @date       2023.1
 */

/******************************************************************************
    Header File Guarder
******************************************************************************/
#ifndef _OPTEE_KEYMASTER3_DEVICE_H_
#define _OPTEE_KEYMASTER3_DEVICE_H_

/******************************************************************************
 #include File Inclusions
******************************************************************************/

// Below two or more header is needed to include for inherit android keymaster

#include <vector>
#include <types.h>
#include <optee_keymaster.h>
#include <keymaster_defs.h>

/******************************************************************************
  Type Definitions
******************************************************************************/

/******************************************************************************
    Macro Definitions
******************************************************************************/

/******************************************************************************
   Local Constant Definitions
******************************************************************************/

/******************************************************************************
    Local Type Definitions
******************************************************************************/

/******************************************************************************
    Global Type Definitions
******************************************************************************/

/******************************************************************************
    Extern Variables & Function Prototype Declarations
******************************************************************************/

/******************************************************************************
    Static Variables & Function Prototypes Declarations
******************************************************************************/

/******************************************************************************
    Local Variables & Function Prototypes Declarations
******************************************************************************/

/******************************************************************************
    Global Variables & Function Prototypes Declarations
******************************************************************************/

/******************************************************************************
    Function Definitions
******************************************************************************/

namespace keymaster {

using namespace std;

// The namespace below is the namespace defined in type.h provided by android keymaster3.
using ::keymaster::V3_0::ErrorCode;
using ::keymaster::V3_0::KeyCharacteristics;
using ::keymaster::V3_0::KeyFormat;
using ::keymaster::V3_0::KeyParameter;
using ::keymaster::V3_0::KeyPurpose;

class KmParamSet : public keymaster_key_param_set_t {
  public:
        KmParamSet(const vector<KeyParameter> &keyParams);

  KmParamSet(KmParamSet&& other) noexcept
        : keymaster_key_param_set_t{other.params, other.length} {
            other.length = 0;
            other.params = nullptr;
        }

  KmParamSet(const KmParamSet&) = delete;
        ~KmParamSet() { delete[] params; }

};

inline vector<KeyParameter> kmParamSet2Vec(const keymaster_key_param_set_t& set);

class OpteeKeymaster3Device {

	public:
/**
 * @brief Initialize funtion of keymaster3device class
 *
 * @rst
 * Functional Requirements
 *   Initialize funtion of keymaster3device class
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function should return an error code.
 *
 * Performance Requirements
 *   There are no specific performance restrictions.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *  * OpteeKeymaster3Device(OpteeKeymaster* impl);
 *
 *  For the data type, following data types are defined
 *
 *  * OpteeKeymaster         	[IN]      
 *
 * Return Value
 *   ex) KM_ERROR_OK(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     auto optee_keymaster = new keymaster::OpteeKeymaster();
 *     int err = optee_keymaster->Initialize();	// Connect to OPTEE TA
 *     if(err != 0) {
 *         // handling error
 *     }
 *     keymaster_ = new ::keymaster::OpteeKeymaster3Device(optee_keymaster);
 *
 * @endrst
 */
    OpteeKeymaster3Device(OpteeKeymaster* impl);
    virtual ~OpteeKeymaster3Device();

/**
 * @brief Respond to the characteristics of the Keymaster. 
 *
 * @rst
 * Functional Requirements
 *   Respond to the characteristics of the Keymaster. On webOS,
 *   Since CA and TA operate in the same version, the is the CA.
 *   Respond to the corresponding characteristics.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function should return an error code.
 *
 * Performance Requirements
 *   There are no specific performance restrictions.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *  * keymaster_error_t  getHardwareFeatures(bool & is_secure, bool & supports_ec, bool & supports_symmetric_cryptography,
 *  											bool & supports_attestation, bool & supportsAllDigests,
 *  											string & keymasterName, string & keymasterAuthorName);
 *
 *  For the data type, following data types are defined
 *
 *  * is_secure         				[OUT]      Return True because key data is not exposed to REE
 *  * supports_ec             			[OUT]      Return True because (P-224, P-256, P-384, P-521) are supported
 *  * supports_symmetric_cryptography   [OUT]      Return True because AES/H-MAC are supported
 *  * supports_attestation              [OUT]      Return True when keymaster attestation is supported
 *  * supportsAllDigests        		[OUT]      Return True when MD5/SHA1/SHA-224/SHA-256/SHA-384/SHA-512 are supported
 *  * keymasterName              		[OUT]      Return keymaster name
 *  * keymasterAuthorName           	[OUT]      Return keymaster author name
 *
 * Return Value
 *   ex) KM_ERROR_OK(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     if (KM_ERROR_OK != keymaster3device->getHardwareFeatures(is_secure_, supports_ec_, supports_symmetric_, supports_attestation_ \
 *         										supports_all_digests_, name_, author_)) {
 *         // handling error
 *     }
 * @endrst
 */

    keymaster_error_t  getHardwareFeatures(bool & is_secure, bool & supports_ec, bool & supports_symmetric_cryptography,
											bool & supports_attestation, bool & supportsAllDigests,
											string & keymasterName, string & keymasterAuthorName);

/**
 * @brief Add entropy to generate random numbers such as Key and IV.
 *
 * @rst
 * Functional Requirements
 *   Add entropy to generate random numbers such as Key and IV.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function should return an error code.
 *
 * Performance Requirements
 *   There are no specific performance restrictions.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *  * keymaster_error_t addRngEntropy(const vector<uint8_t> &data);
 *
 *  For the data type, following data types are defined
 *
 *  * data         				[IN]      Entropy value to add
 *
 * Return Value
 *   ex) KM_ERROR_OK(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     const vector<uint8_t>& data;
 *     // data isert
 *     // ...
 *
 *     if (KM_ERROR_OK != keymaster3device->addRngEntropy(&data)) {
 *         // handling error
 *     }
 * @endrst
 */
    keymaster_error_t addRngEntropy(const vector<uint8_t> &data);

/**
 * @brief Generate Key.
 *
 * @rst
 * Functional Requirements
 *   Respond to the characteristics of the Keymaster. On webOS,
 *   Since CA and TA operate in the same version, the is the CA.
 *   Respond to the corresponding characteristics.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function should return an error code.
 *
 * Performance Requirements
 *   There are no specific performance restrictions.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *  * keymaster_error_t generateKey(const vector<KeyParameter> &keyParams,
 *                                   KeyCharacteristics* resultCharacteristics,
 *   								 vector<uint8_t> &resultKeyBlob);
 *  * keymaster_error_t generateKey(const keymaster_key_param_set_t* keyParams,
 *                                   KeyCharacteristics* resultCharacteristics,
 *                                   vector<uint8_t> &resultKeyBlob);
 *
 *  For the data type, following data types are defined
 *
 *  * keyParams         				[IN]       Parameter value required for key generation like key size, algorithm, padding..
 *  * resultCharacteristics             [OUT]      Key parameter value included in keyblob
 *  * resultKeyBlob   					[OUT]      Encrypted Key blob data
 *
 * Return Value
 *   ex) KM_ERROR_OK(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     keymaster_key_param_set_t keyParams;
 *     keymaster_key_blob_t keyBlob;
 *     vector<uint8_t> resultKeyBlob;
 *     keymaster_error_t km_err = KM_ERROR_OK;
 *     keymaster::V3_0::KeyCharacteristics resultCharacteristics;
 *     // Set keyParams and keyBlob
 *     // ..
 *
 *     if (KM_ERROR_OK != keymaster3device->generateKey(keyParams, &resultCharacteristics, resultKeyBlob)) {
 *         // handling error
 *     }
 * @endrst
 */
    keymaster_error_t generateKey(const vector<KeyParameter> &keyParams,
                                    KeyCharacteristics* resultCharacteristics,
                                    vector<uint8_t> &resultKeyBlob);
    keymaster_error_t generateKey(const keymaster_key_param_set_t* keyParams,
                                    KeyCharacteristics* resultCharacteristics,
                                    vector<uint8_t> &resultKeyBlob);

/**
 * @brief Returns the Key parameter value of the Keyblob.
 *
 * @rst
 * Functional Requirements
 *   Check that the Client ID entered is the same as the Client ID in Keyblob
 *	 and return the Key parameter value of Keyblob.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function should return an error code.
 *
 * Performance Requirements
 *   There are no specific performance restrictions.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *  * keymaster_error_t getKeyCharacteristics(const vector<uint8_t> &keyBlob,
 *                                   const vector<uint8_t> &clientId,
 *                                   const vector<uint8_t> &appData,
 *
 *  For the data type, following data types are defined
 *
 *  * keyBlob         				[IN]      Keyblob to request key parameter value
 *  * clientId             			[IN]      Client ID entered when creating Keyblob
 *  * appData   					[IN]      App Data value entered when creating Keyblob (Currently Not Used)
 *  * resultCharacteristics         [OUT]     Key parameter value included in keyblob
 *
 * Return Value
 *   ex) KM_ERROR_OK(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     keymaster_key_blob_t keyBlob;
 *     keymaster::V3_0::KeyCharacteristics resultCharacteristics;
 *     // Set keyBlob
 *     // ..
 *
 *     if (KM_ERROR_OK != keymaster3device->getKeyCharacteristics(keyBlob, clientId, appData, &resultCharacteristics)) {
 *         // handling error
 *     }
 * @endrst
 */
    keymaster_error_t getKeyCharacteristics(const vector<uint8_t> &keyBlob,
                                    const vector<uint8_t> &clientId,
                                    const vector<uint8_t> &appData,
                                    KeyCharacteristics* resultCharacteristics);
									
/**
 * @brief Create a keyblob using a key generated outside the keymaster.
 *
 * @rst
 * Functional Requirements
 *   Create a keyblob using a key generated outside the keymaster.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function should return an error code.
 *
 * Performance Requirements
 *   There are no specific performance restrictions.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *  * keymaster_error_t importKey(const vector<KeyParameter> &params,
 *                                    KeyFormat keyFormat,
 *                                   const vector<uint8_t> &keyData,
 *                                   KeyCharacteristics* resultCharacteristics,
 *                                   vector<uint8_t> &resultKeyBlob);
 *  * keymaster_error_t importKey(const keymaster_key_param_set_t* params,
 *                                   KeyFormat keyFormat,
 *                                   const vector<uint8_t> &keyData,
 *                                   KeyCharacteristics* resultCharacteristics,
 *                                   vector<uint8_t> &resultKeyBlob);
 *
 *  For the data type, following data types are defined
 *
 *  * params         				[IN]      Information related to keyData like key size, algorithm, block mode..
 *  * keyFormat             		[IN]      Format of keyData (Raw, PKCS8)
 *  * keyData   					[IN]      Key data to generate KeyBlob
 *  * resultCharacteristics         [OUT]     Key parameter value included in keyblob
 *  * resultKeyBlob					[OUT]     Encrypted Key blob data
 *
 * Return Value
 *   ex) KM_ERROR_OK(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     keymaster_key_param_set_t params;
 *     vector<uint8_t> keyData;
 *     vector<uint8_t> resultKeyBlob;
 *     keymaster::V3_0::KeyCharacteristics resultCharacteristics;
 *     // Set keyData and params
 *     // ..
 *
 *     if (KM_ERROR_OK != keymaster3device->importKey(params, KM_KEY_FORMAT_PKCS8, keyData, &resultCharacteristics, resultKeyBlob)) {
 *         // handling error
 *     }
 * @endrst
 */									
    keymaster_error_t importKey(const vector<KeyParameter> &params,
                                    KeyFormat keyFormat,
                                    const vector<uint8_t> &keyData,
                                    KeyCharacteristics* resultCharacteristics,
                                    vector<uint8_t> &resultKeyBlob);
    keymaster_error_t importKey(const keymaster_key_param_set_t* params,
                                    KeyFormat keyFormat,
                                    const vector<uint8_t> &keyData,
                                    KeyCharacteristics* resultCharacteristics,
                                    vector<uint8_t> &resultKeyBlob);

/**
 * @brief Create a keyblob using a encrypted-key by securestore TA.
 *
 * @rst
 * Functional Requirements
 *   Create a keyblob using a encrypted-key by securestore TA.
 *	 Precisely, the encrypted key is the data encrypted by secure store TA
 *	 at the call of the HAL_SSTR_MakeSecureData function.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function should return an error code.
 *
 * Performance Requirements
 *   There are no specific performance restrictions.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *  * keymaster_error_t importSecKey(const vector<KeyParameter> &params,
 *                                    KeyFormat keyFormat,
 *                                   const vector<uint8_t> &keyData,
 *                                   KeyCharacteristics* resultCharacteristics,
 *                                   vector<uint8_t> &resultKeyBlob);
 *  * keymaster_error_t importSecKey(const keymaster_key_param_set_t* params,
 *                                   KeyFormat keyFormat,
 *                                   const vector<uint8_t> &keyData,
 *                                   KeyCharacteristics* resultCharacteristics,
 *                                   vector<uint8_t> &resultKeyBlob);
 *
 *  For the data type, following data types are defined
 *
 *  * params         				[IN]      Information related to keyData like key size, algorithm, block mode..
 *  * keyFormat             		[IN]      Format of keyData (Raw, PKCS8)
 *  * keyData   					[IN]      Encrypted key data by HAL_SSTR_MakeSecureData function
 *  * resultCharacteristics         [OUT]     Key parameter value included in keyblob
 *  * resultKeyBlob					[OUT]     Encrypted Key blob data
 *
 * Return Value
 *   ex) KM_ERROR_OK(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     keymaster_key_param_set_t params;
 *     vector<uint8_t> keyData;
 *     vector<uint8_t> resultKeyBlob;
 *     keymaster::V3_0::KeyCharacteristics resultCharacteristics;
 *     // Set keyData and params
 *     // ..
 *
 *     if (KM_ERROR_OK != keymaster3device->importSecKey(params, keyFormat, keyData, &resultCharacteristics, resultKeyBlob)) {
 *         // handling error
 *     }
 * @endrst
 */
    keymaster_error_t importSecKey(const vector<KeyParameter> &params,
                                    KeyFormat keyFormat,
                                    const vector<uint8_t> &keyData,
                                    KeyCharacteristics* resultCharacteristics,
                                    vector<uint8_t> &resultKeyBlob);
    keymaster_error_t importSecKey(const keymaster_key_param_set_t* params,
                                    KeyFormat keyFormat,
                                    const vector<uint8_t> &keyData,
                                    KeyCharacteristics* resultCharacteristics,
                                    vector<uint8_t> &resultKeyBlob);

/**
 * @brief Read the plaintext Key value from Keyblob.
 *
 * @rst
 * Functional Requirements
 *   Read the plaintext Key value from Keyblob.
 *   Symmetric Key is not supported and Asymmetric Public Key only can be return.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function should return an error code.
 *
 * Performance Requirements
 *   There are no specific performance restrictions.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *  * keymaster_error_t exportKey(KeyFormat exportFormat,
 *                               const vector<uint8_t> &keyBlob,
 *                               const vector<uint8_t> &clientId,
 *                               const vector<uint8_t> &appData,
 *                               vector<uint8_t> &resultKeyBlob);
 *
 *  For the data type, following data types are defined
 *
 *  * exportFormat         		[IN]      Only X.509 format is supported
 *  * keyBlob             		[IN]      Keyblob who wants to take out the key
 *  * clientId             		[IN]      Client ID entered when creating Keyblob
 *  * appData   				[IN]      App Data value entered when creating Keyblob (Currently Not Used)
 *  * resultKeyBlob				[OUT]     Requested key data (key data extracted from keyblob)
 *
 * Return Value
 *   ex) KM_ERROR_OK(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     keymaster::V3_0::KeyFormat key_format = (keymaster::V3_0::KeyFormat)0u;
 *     vector<uint8_t> keyBlob;
 *     vector<uint8_t> clientId;
 *     vector<uint8_t> appData;
 *     vector<uint8_t> resultKeyBlob;
 *     // Set keyBlob
 *     // ..
 *     if (KM_ERROR_OK != keymaster3device->exportKey(exportFormat, keyBlob, clientId, appData, resultKeyBlob)) {
 *         // handling error
 *     }
 * @endrst
 */
    keymaster_error_t exportKey(KeyFormat exportFormat,
                                const vector<uint8_t> &keyBlob,
                                const vector<uint8_t> &clientId,
                                const vector<uint8_t> &appData,
                                vector<uint8_t> &resultKeyBlob);

/**
 * @brief To use the cryptographic algorithm, enter Keyblob and set the parameter value.
 *
 * @rst
 * Functional Requirements
 *   To use the cryptographic algorithm, enter Keyblob and set the parameter value.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function should return an error code.
 *
 * Performance Requirements
 *   There are no specific performance restrictions.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *  * keymaster_error_t begin(keymaster_purpose_t purpose,
 *                                 const vector<uint8_t> &key,
 *                                 const vector<KeyParameter> &inParams,
 *                                 vector<KeyParameter> &resultParams,
 *                                 keymaster_operation_handle_t* op_handle);
 *  * keymaster_error_t begin(keymaster_purpose_t purpose,
 *                                 const vector<uint8_t> &key,
 *                                 const keymaster_key_param_set_t* inParams,
 *                                 vector<KeyParameter> &resultParams,
 *                                 keymaster_operation_handle_t* op_handle);
 *
 *  For the data type, following data types are defined
 *
 *  * purpose         		[IN]      Purpose of using the algorithm (encrypt, sign..)
 *  * key             		[IN]      keyblob data
 *  * inParams             	[IN]      Parameter setting values associated with the use of the algorithm (padding, block mode, digest..)
 *  * resultParams   		[OUT]     Used when parameter result value is present after setting (Not Used In Webos)
 *  * op_handle				[OUT]     Handle value for distinguishing cryptographic algorithms set for begin api
 *
 * Return Value
 *   ex) KM_ERROR_OK(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     if (KM_ERROR_OK != keymaster3device->begin(purpose, key, inParams, NULL, &op_handle)) {
 *         // handling error
 *     }
 * @endrst
 */									
    keymaster_error_t begin(keymaster_purpose_t purpose,
                                  const vector<uint8_t> &key,
                                  const vector<KeyParameter> &inParams,
                                  vector<KeyParameter> &resultParams,
                                  keymaster_operation_handle_t* op_handle);
    keymaster_error_t begin(keymaster_purpose_t purpose,
                                  const vector<uint8_t> &key,
                                  const keymaster_key_param_set_t* inParams,
                                  vector<KeyParameter> &resultParams,
                                  keymaster_operation_handle_t* op_handle);

/**
 * @brief Enter the data to perform the cryptographic algorithm operation set in begin.
 *
 * @rst
 * Functional Requirements
 *   Enter the data to perform the cryptographic algorithm operation set in begin.
 *   For the AES algorithm, we receive an intermediate result value.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function should return an error code.
 *
 * Performance Requirements
 *   There are no specific performance restrictions.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *  * keymaster_error_t update(const keymaster_operation_handle_t op_handle,
 *                                 const vector<KeyParameter> &inParams,
 *                                 const vector<uint8_t> &input,
 *                                 vector<KeyParameter> &resultParams,
 *                                 vector<uint8_t> &resultBlob,
 *                                 size_t* input_consumed);
 *  * keymaster_error_t update(const keymaster_operation_handle_t op_handle,
 *                                 const keymaster_key_param_set_t* inParams,
 *                                 const vector<uint8_t> &input,
 *                                 vector<KeyParameter> &resultParams,
 *                                 vector<uint8_t> &resultBlob,
 *                                 size_t* input_consumed);
 *
 *  For the data type, following data types are defined
 *
 *  * op_handle         	    [IN]      Handle value generated from begin api
 *  * inParams             		[IN]      Parameter value to be entered during cryptographic algorithm operation (AES GCM AAD value)
 *  * input             		[IN]      Input data
 *  * resultParams   			[OUT]     Used when parameter result value is present after setting (Not Used In Webos)
 *  * resultBlob				[OUT]     esult value after cryptographic algorithm action
 *  * input_consumed			[OUT]     
 *
 * Return Value
 *   ex) KM_ERROR_OK(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     uint64_t op_handle;
 *     vector<keymaster::KeyParameter> resultParams;
 *     vector<uint8_t> resultBlob;
 *     vector<uint8_t> input;
 *     vector<uint8_t> input_buffer;
 *     keymaster_key_param_set_t* inParams;
 *     size_t &consumed;
 *     size_t input_len = input.size();
 *     size_t pos = 0;
 *     
 *     do{
 *         if((input_len - pos) > OPTEE_BUFFER_SIZE){
 *             memcpy(&input_buffer[0], &input[pos], sizeof(uint8_t) * OPTEE_BUFFER_SIZE);
 *         }else if(input_len - pos >= 0){
 *             input_buffer.resize(input_len - pos);
 *             memcpy(&input_buffer[0], &input[pos], sizeof(uint8_t) * (input_len - pos));
 *         }
 *         if (KM_ERROR_OK != keymaster3device->update(op_handle, inParams, input_buffer, resultParams, &resultBlob, input_consumed)) {
 *             // handling error
 *         }
 *         pos += consumed;
 *     }while(input_len - pos > 0);
 * @endrst
 */
    keymaster_error_t update(const keymaster_operation_handle_t op_handle,
                                  const vector<KeyParameter> &inParams,
                                  const vector<uint8_t> &input,
                                  vector<KeyParameter> &resultParams,
                                  vector<uint8_t> &resultBlob,
                                  size_t* input_consumed);
    keymaster_error_t update(const keymaster_operation_handle_t op_handle,
                                  const keymaster_key_param_set_t* inParams,
                                  const vector<uint8_t> &input,
                                  vector<KeyParameter> &resultParams,
                                  vector<uint8_t> &resultBlob,
                                  size_t* input_consumed);
								  
/**
 * @brief Enter the final data to perform the cryptographic algorithm task set in Begin and receive the result value.
 *
 * @rst
 * Functional Requirements
 *   Enter the final data to perform the cryptographic algorithm task set in Begin and receive the result value.
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function should return an error code.
 *
 * Performance Requirements
 *   There are no specific performance restrictions.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *  * keymaster_error_t finish(const keymaster_operation_handle_t op_handle,
 *                                 const vector<KeyParameter> &inParams,
 *                                 const vector<uint8_t> &input,
 *                                 const vector<uint8_t> &signature,
 *                                 vector<KeyParameter> &resultParams,
 *                                 vector<uint8_t> &resultBlob);
 *  * keymaster_error_t finish(const keymaster_operation_handle_t op_handle,
 *                                 const keymaster_key_param_set_t* inParams,
 *                                 const vector<uint8_t> &input,
 *                                 const vector<uint8_t> &signature,
 *                                 vector<KeyParameter> &resultParams,
 *                                 vector<uint8_t> &resultBlob);
 *
 *  For the data type, following data types are defined
 *
 *  * op_handle         	[IN]      Handle value generated from begin api
 *  * inParams             	[IN]      Parameter value to be entered during cryptographic algorithm operation (AES GCM AAD value)
 *  * input             	[IN]      Input data
 *  * signature   			[IN]      Signature input data to verify
 *  * resultParams			[OUT]     Parameter result value after cryptographic algorithm operation (Not Used In Webos)
 *  * resultBlob			[OUT]     Result value after cryptographic algorithm action
 *
 * Return Value
 *   ex) KM_ERROR_OK(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *     
 *     uint64_t op_handle;
 *     vector<uint8_t> signature;
 *     vector<keymaster::KeyParameter> resultParams;
 *     vector<uint8_t> resultBlob;
 *     vector<uint8_t> input;
 *     keymaster_key_param_set_t* in_params;
 *     
 *     // Set operation handle and data and params
 *     // ..
 *     if (KM_ERROR_OK != keymaster3device->finish(op_handle, inParams, input, signature, &resultParams, resultBlob)) {
 *         // handling error
 *     }
 * @endrst
 */
    keymaster_error_t finish(const keymaster_operation_handle_t op_handle,
                                  const vector<KeyParameter> &inParams,
                                  const vector<uint8_t> &input,
                                  const vector<uint8_t> &signature,
                                  vector<KeyParameter> &resultParams,
                                  vector<uint8_t> &resultBlob);
    keymaster_error_t finish(const keymaster_operation_handle_t op_handle,
                                  const keymaster_key_param_set_t* inParams,
                                  const vector<uint8_t> &input,
                                  const vector<uint8_t> &signature,
                                  vector<KeyParameter> &resultParams,
                                  vector<uint8_t> &resultBlob);

/**
 * @brief Stop the cryptographic algorithm operation that you were working on by begin/update api
 *
 * @rst
 * Functional Requirements
 *   Stop the cryptographic algorithm operation that you were working on by begin/update api
 *
 * Responses to abnormal situations, including
 *   In abnormal case, the function should return an error code.
 *
 * Performance Requirements
 *   There are no specific performance restrictions.
 *
 * Constraints
 *   There is no constraints.
 *
 * Functions & Parameters
 *  * keymaster_error_t abort(const keymaster_operation_handle_t operationHandle);
 *
 *  For the data type, following data types are defined
 *
 *  * operationHandle         	[IN]      Handle value generated from begin api
 *
 * Return Value
 *   ex) KM_ERROR_OK(0) if the function success, non-Zero otherwise or Common Error Code.
 *
 * Example
 *   .. code-block:: cpp
 *
 *     ex)
 *
 *     uint64_t operationHandle;
 *     // Set operation handle
 *     // ..
 *     if (KM_ERROR_OK != keymaster3device->abort(operationHandle)) {
 *         // handling error
 *     }
 * @endrst
 */
    keymaster_error_t abort(const keymaster_operation_handle_t operationHandle);

  private:
    std::unique_ptr<OpteeKeymaster> impl_;
};


}  // namespace keymaster

#endif      // _OPTEE_KEYMASTER3_DEVICE_H_
