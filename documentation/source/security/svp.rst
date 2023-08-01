SVP
==========

History
-------

======= ========== ============== =====================
Version Date       Changed by     Comment
======= ========== ============== =====================
1.1.0   23.08.01   sehan.yoon     Remove unused APIs, Update description, diagrams and examples
1.0.0   22.05.02   cs.jung        Initial Documentation
======= ========== ============== =====================

Overall Description
--------------------

This document describes how to use and implement the HAL functions, which are available in the webOS TV 23. All the HAL functions in this document are supposed to be implemented by main SoC vendor.

Terminology and Definitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

================================= ==============================================================================================
Definition                        Description
================================= ==============================================================================================
DSC                               Dynamic Stream Change
--------------------------------- ----------------------------------------------------------------------------------------------
REE                               Rich Execution Environment
--------------------------------- ----------------------------------------------------------------------------------------------
SEBUF                             Secure Buffer, Permanent space with clear/decrypted video data where is referenced by decoder.
--------------------------------- ----------------------------------------------------------------------------------------------
SEMEM                             Secure Memory, Temporary space with clear/decrypted video data where is referenced by SEBUF.
--------------------------------- ----------------------------------------------------------------------------------------------
TA                                Trsted Application
--------------------------------- ----------------------------------------------------------------------------------------------
TEE                               Trusted Execution Environment
--------------------------------- ----------------------------------------------------------------------------------------------
VDEC                              Video Decoder
================================= ==============================================================================================

System Context
^^^^^^^^^^^^^^

The HAL SVP functions have inter-dependencies, therefore please check the data flow with numbers below.

.. image:: resource/multi-svp-context.png
  :width: 100%
  :alt: System Context Diagram

Below diagram shows how HAL SVP functions will be operated with life cycle.

.. image:: resource/multi-svp-flow-chart.png
  :width: 100%
  :alt: Sequence Diagram

Performance Requirements
^^^^^^^^^^^^^^^^^^^^^^^^^

The minimum requirement is that 1 loop of decryption(or copy), stat, and write of 1 sample (1 Au) be performed within 16ms.

Design Constraints
^^^^^^^^^^^^^^^^^^^

All functions must be multi-thread safe.

Functional Requirements
-----------------------

The data types and functions used in this module are as follows.

Data Types
^^^^^^^^^^^^

  * :cpp:type:`HAL_SVP_RESULT_T`
  * :cpp:type:`HAL_SVP_OPEN_PARAM_T`
  * :cpp:type:`HAL_SVP_CLOSE_PARAM_T`
  * :cpp:type:`HAL_SVP_STAT_PARAM_T`
  * :cpp:type:`HAL_SVP_SEMEM_PARAM_T`
  * :cpp:type:`HAL_SVP_SEBUF_PARAM_T`
  * :cpp:type:`HAL_SVP_FLUSH_PARAM_T`
  * :cpp:type:`SVP_STATUS_T`

Function Calls
^^^^^^^^^^^^^^^

  * :cpp:func:`HAL_SVP_Open` //except from socts, it can be only verified by TAS
  * :cpp:func:`HAL_SVP_Close` //except from socts, it can be only verified by TAS
  * :cpp:func:`HAL_SVP_Stat` //except from socts, it can be only verified by TAS
  * :cpp:func:`HAL_SVP_Copy` //except from socts, it can be only verified by TAS
  * :cpp:func:`HAL_SVP_Write` //except from socts, it can be only verified by TAS
  * :cpp:func:`HAL_SVP_Flush` //except from socts, it can be only verified by TAS
  * :cpp:func:`HAL_SVP_WidevineSelectKey_OverV14` //except from socts, it can be only verified by TAS
  * :cpp:func:`HAL_SVP_WidevineDecryptCENC_V16` //except from socts, it can be only verified by TAS

Appendix
--------

Use case of SEMEM information via DRM decryption interfaces
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In this chapter, examples will be provided which describe how to pass SEMEM information via each DRM decryption interfaces.

PlayReady
*********

.. code-block::
   :caption: Prototype

   DRM_API DRM_RESULT DRM_CALL Drm_Reader_Bind(
       __in                           DRM_APP_CONTEXT      *f_poAppContext,
       __in_ecount( f_cRights ) const DRM_CONST_STRING     *f_rgpdstrRights[],
       __in                           DRM_DWORD             f_cRights,
       __in_opt                       DRMPFNPOLICYCALLBACK  f_pfnPolicyCallback,
       __in_opt                 const DRM_VOID             *f_pv,
       __out_opt                      DRM_DECRYPT_CONTEXT  *f_pcontextDCRY );

   DRM_API DRM_RESULT DRM_CALL Drm_Reader_DecryptOpaque(
       __in                                            DRM_DECRYPT_CONTEXT      *f_pDecryptContext,
       __in                                            DRM_DWORD                 f_cEncryptedRegionMappings,
       __in_ecount( f_cEncryptedRegionMappings ) const DRM_DWORD                *f_pdwEncryptedRegionMappings,
       __in                                            DRM_UINT64                f_ui64InitializationVector,
       __in                                            DRM_DWORD                 f_cbEncryptedContent,
       __in_bcount( f_cbEncryptedContent )       const DRM_BYTE                 *f_pbEncryptedContent,
       __out                                           DRM_DWORD                *f_pcbOpaqueClearContent,
       __deref_out_bcount( *f_pcbOpaqueClearContent )  DRM_BYTE                **f_ppbOpaqueClearContent );

   DRM_API DRM_RESULT DRM_CALL Drm_Reader_DecryptMultipleOpaque(
       __in                                                                 DRM_DECRYPT_CONTEXT      *f_pDecryptContext,
       __in                                                                 DRM_DWORD                 f_cEncryptedRegionInitializationVectors,
       __in_ecount( f_cEncryptedRegionInitializationVectors )         const DRM_UINT64               *f_pEncryptedRegionInitializationVectorsHigh,
       __in_ecount_opt( f_cEncryptedRegionInitializationVectors )     const DRM_UINT64               *f_pEncryptedRegionInitializationVectorsLow,
       __in_ecount( f_cEncryptedRegionInitializationVectors )         const DRM_DWORD                *f_pEncryptedRegionCounts,
       __in                                                                 DRM_DWORD                 f_cEncryptedRegionMappings,
       __in_ecount( f_cEncryptedRegionMappings )                      const DRM_DWORD                *f_pEncryptedRegionMappings,
       __in                                                                 DRM_DWORD                 f_cEncryptedRegionSkip,
       __in_ecount_opt( f_cEncryptedRegionSkip )                      const DRM_DWORD                *f_pEncryptedRegionSkip,
       __in                                                                 DRM_DWORD                 f_cbEncryptedContent,
       __in_bcount( f_cbEncryptedContent )                            const DRM_BYTE                 *f_pbEncryptedContent,
       __out                                                                DRM_DWORD                *f_pcbOpaqueClearContent,
       __deref_out_bcount( *f_pcbOpaqueClearContent )                       DRM_BYTE                **f_ppbOpaqueClearContent );

PlayReady Porting Kit implementation in webOSTV will be customized by LG to pass 'session_id' and 'offset' from HAL_SVP_SEMEM_PARAM_T via a member 'cipher.cipherTEE.oOEMKeyInfo' in DRM_CIPHER_CONTEXT.

.. code-block::
   :caption: Example

   DRM_API DRM_RESULT DRM_CALL Drm_Reader_Bind(...)
   {
       ...

       /* Cleanup oOEMKeyInfo for SVP usage later. */
       DRM_TEE_NW_BASE_FreeBlob( NULL, &pCipherCtx->cipher.cipherTEE.oOEMKeyInfo );

       ...

   ErrorExit:

       ...

       return dr;
   }

   typedef struct __tagOEM_KEY_INFO_SVP
   {
       DRM_UINT64 ui64SessionId;
       DRM_DWORD  dwOffset;
   } OEM_KEY_INFO_SVP;

   HAL_SVP_SEMEM_PARAM_T semem_param;

   OEM_KEY_INFO_SVP oem_key_info_svp;
   oem_key_info_svp.ui64SessionId = semem_param.session_id;
   oem_key_info_svp.dwOffset = semem_param.offset;

   DRM_CIPHER_CONTEXT *pCipherContext = DRM_REINTERPRET_CAST( DRM_CIPHER_CONTEXT, pDecryptContext );
   /* Fill SEMEM info before decrypt function call. */
   DRM_TEE_NW_BASE_AllocBlob(NULL,
                             DRM_TEE_BLOB_ALLOC_BEHAVIOR_COPY,
                             sizeof( oem_key_info_svp ),
                             DRM_REINTERPRET_CAST( const DRM_BYTE, &oem_key_info ),
                             &pCipherContext->cipher.cipherTEE.oOEMKeyInfo);

   Drm_Reader_Decrypt[Multiple]Opaque( pDecryptContext, cbEncryptedContent, pbEncryptedContent, ... );

   /* Free oOEMKeyInfo after decrypt function call. */
   DRM_TEE_NW_BASE_FreeBlob( NULL, &pCipherCtx->cipher.cipherTEE.oOEMKeyInfo );

Widevine Modular
****************

.. code-block::
   :caption: Prototype

   SVP_STATUS_T HAL_SVP_WidevineSelectKey_OverV14(UINT32 session,
                                                  const UINT8 *key_id,
                                                  size_t key_id_length,
                                                  SINT32 cipherMode);

   SVP_STATUS_T HAL_SVP_WidevineDecryptCENC_V16(UINT32 session,
                                                void *samples,
                                                size_t samples_length,
                                                void *pattern,
                                                UINT32 *oec_return);

SEMEM information will be set to OEMCrypto_SampleDescription and then will be passed via HAL_SVP_WidevineDecryptCENC_V16().

.. code-block::
   :caption: Example

   HAL_SVP_STAT_PARAM_T stat_param;
   HAL_SVP_SEMEM_PARAM_T semem_param;

   OEMCrypto_SampleDescription sample_desc[NUM_OF_SAMPLE];
   for (int i = 0; i < NUM_OF_SAMPLE; i++) {
     ...
     sample_desc[i].buffers.output_descriptor.secure.handle = (void*)&semem_param.session_id;
     sample_desc[i].buffers.output_descriptor.secure.handle_length = stat_param.capacity.semem;
     sample_desc[i].buffers.output_descriptor.secure.offset = semem_param.offset;
     sample_desc[i].buffers.input_data = data[i].ptr;
     sample_desc[i].buffers.input_data_length = data[i].len;
     ...
   }

   void *samples = (void*)&sample_desc;
   size_t samples_length = NUM_OF_SAMPLE;

   HAL_SVP_WidevineSelectKey_OverV14(...);

   HAL_SVP_WidevineDecryptCENC_V16(..., samples, samples_length, ...);

FairPlay
********

.. code-block::
   :caption: Prototype

   int apple_get_outsample_handle(uint32_t type,
                                  void *handle,
                                  size_t handle_size,
                                  size_t offset,
                                  uint8_t **out_sample);

   int apple_decrypt_sample(uint64_t movie_id,
                            uint64_t cryptor_id,
                            unt32_t content_type,
                            const uint8_t *in_sample,
                            size_t in_size,
                            uint8_t *out_sample,
                            sample_info *infos,
                            int num_info,
                            const uint8_t iv[16],
                            security_status_list_t *security_status,
                            int num_security_status);

SEMEM information will be passed via apple_get_outsample_handle().

.. code-block::
   :caption: Example

   HAL_SVP_STAT_PARAM_T stat_param;
   HAL_SVP_SEMEM_PARAM_T semem_param;

   void *handle = (void*)&semem_param.session_id;
   size_t handle_size = stat_param.capacity.semem;
   size_t offset = semem_param.offset;

   apple_get_outsample_handle(..., handle, handle_size, offset, ...);

   apple_decrypt_sample(...);
