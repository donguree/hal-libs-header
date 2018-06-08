/******************************************************************************
 *   DTV LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2016 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   permission of LG Electronics Inc.
 *****************************************************************************/

/** @file	hal_delivery.h
 *
 *  Header file for delivery HAL interface
 *
 *  @author   Ilkyu Kim (ilkyu.kim@lge.com)
 *  @version  0.1
 *  @date     2016.03.22
 *
 *  @note      none
 *  @see
 */

#ifndef	_HAL_DELIVERY_H_
#define	_HAL_DELIVERY_H_

/*----------------------------------------------------------------------------------------
  File Inclusions
----------------------------------------------------------------------------------------*/
#include "hal_common.h"


/*----------------------------------------------------------------------------------------
  Control Constants
----------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------
  Constant Definitions
----------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------
  Macro Definitions
----------------------------------------------------------------------------------------*/
#define DELIVERY_MAX_IP_LENGTH     4
#define DELIVERY_INFINIT_TIMEOUT   (UINT32)(-1)

/*----------------------------------------------------------------------------------------
  Type Definitions
----------------------------------------------------------------------------------------*/
typedef enum
{
	DELIVERY_CH_A = 0,
	DELIVERY_CH_B,
	DELIVERY_CH_C,
	DELIVERY_CH_MAX
} DELIVERY_CHANNEL_T;

typedef enum
{
	DELIVERY_INPUT_SERIAL = 0,
	DELIVERY_INPUT_PARALLEL,
	DELIVERY_INPUT_ENABLE,
	DELIVERY_INPUT_DISABLE,
	DELIVERY_INPUT_MEM,
	DELIVERY_INPUT_MAX,
} DELIVERY_INPUT_TYPE_T;

typedef enum
{
	DELIVERY_AV_TYPE_VIDEO = 0,
	DELIVERY_AV_TYPE_AUDIO,
	DELIVERY_AV_TYPE_SUBTITLE,
	DELIVERY_AV_TYPE_MAX,
} DELIVERY_AV_TYPE_T;

typedef enum
{
	DELIVERY_PORT_NONE = 0,			/* No Port */
	DELIVERY_PORT_IN_DEMOD0,		/* Input From Internal Demodulator */
	DELIVERY_PORT_IN_DEMOD1,		/* Input From Internal Demodulator */
	DELIVERY_PORT_EXT_INPUT0,		/* External Demodulator0 */
	DELIVERY_PORT_EXT_INPUT1,		/* External Demodulator1 */
	DELIVERY_PORT_EXT_INPUT2,		/* External Demodulator2 */
	DELIVERY_PORT_FROM_MEM,			/* Input From Memory */
	DELIVERY_PORT_MAX,
} DELIVERY_INPUT_PORT_T;

typedef enum
{
	DELIVERY_PROTOCOL_LINK_SIGNAL		= 0x100,

	DELIVERY_PROTOCOL_LLS				= 0x200,

	DELIVERY_PROTOCOL_ROUTE_SLS			= 0x300,
	DELIVERY_PROTOCOL_ROUTE_AV,
	DELIVERY_PROTOCOL_ROUTE_OBJECT,
	DELIVERY_PROTOCOL_ROUTE_CAS,

	DELIVERY_PROTOCOL_MMT_SLS			= 0x400,
	DELIVERY_PROTOCOL_MMT_AV,

} DELIVERY_PROTOCOL_TYPE_T;

typedef enum
{
    DELIVERY_ROUTE_SEGMENT	= 0,
    DELIVERY_ROUTE_MDE		= 1,
} DELIVERY_ROUTE_MODE_T;

typedef enum
{
	DELIVERY_DEMOD_TYPE_LG_A = 0,	/* B17 A0 */
	DELIVERY_DEMOD_TYPE_LG_B,		/* B17 B0 */
	DELIVERY_DEMOD_TYPE_LG_C,		/* B17 B1 ~ */
	DELIVERY_DEMOD_TYPE_LG_D		/* B17 C0 ~ */
} DELIVERY_DEMOD_TYPE_T;

typedef struct
{
	UINT32		sec;		/* seconds */
	UINT32		nsec;		/* nanoseconds */
	UINT8		wall_clock;
} DELIVERY_TIME_T;

typedef struct
{
	UINT32		hi;			/* seconds */
	UINT32		lo;			/* a multiple of 1/2^32 of a second in NTP */
} DELIVERY_TIMESTAMP_T;

typedef struct
{
	UINT8		current_utc_offset;
	UINT16		ptp_prepend;
	UINT8
		leap59		: 1,
		leap61		: 1,
		reserved	: 6;
} DELIVERY_SYSTEM_TIME_INFO_T;

typedef struct
{
	UINT8	src_ip[DELIVERY_MAX_IP_LENGTH];
	UINT8	dst_ip[DELIVERY_MAX_IP_LENGTH];
	UINT16	dst_port;
} DELIVERY_IP_UDP_T;

typedef enum
{
	DELIVERY_FILTER_CLEAN_ALL = 0,
	DELIVERY_FILTER_CLEAN_LLS,
	DELIVERY_FILTER_CLEAN_ROUTE,
	DELIVERY_FILTER_CLEAN_MMT,
} DELIVERY_FILTER_CLEAN_SCOPE_T;

/* requested filter types */
typedef struct
{
	UINT32				transaction_id; 		/**< Transaction ID */
	UINT8				plp_id;
	UINT8				signal_type;
	UINT16				signal_type_extension;
	UINT8				signal_version;
	UINT8
		oneshot_mode				: 1,		/* only one packet */
		type_filter					: 1,
		type_extension_filter		: 1,
		version_filter				: 1,
		not_version_filter			: 1,
		plp_id_filter				: 1,
		not_plp_id_filter			: 1,
		reserved_filter				: 1;
} DELIVERY_LINK_SIGNAL_FILTER_T;

typedef struct
{
	UINT32				transaction_id; 		/**< Transaction ID */
	UINT8				plp_id;
    DELIVERY_IP_UDP_T	ip_udp;

	UINT8				table_id;
	UINT8				group_id;
	UINT8				table_version;
	UINT8
		oneshot_mode				: 1,		/* only one packet */
		table_id_filter				: 1,
		group_id_filter				: 1,
		table_version_filter		: 1,
		not_table_version_filter	: 1,
		not_group_id_filter			: 1,
		plp_id_filter				: 1,
		not_plp_id_filter			: 1;
} DELIVERY_LLS_FILTER_T;

typedef struct
{
	UINT32				transaction_id; 		/**< Transaction ID */
	UINT8				plp_id;
	DELIVERY_IP_UDP_T	ip_udp;

	UINT32				tsi;					/* Transport Session Identifier */

	UINT8				reserved; //TODO: Check with MW modification
	UINT16				fragment_included;
	UINT8				version;
	UINT8
		oneshot_mode				: 1,		/* only one packet */
		fragment_included_filter	: 1,
		version_filter				: 1,
		not_version_filter			: 1,
		reserved_filter				: 4;

} DELIVERY_ROUTE_SLS_FILTER_T;

typedef struct
{
	UINT8				code_point;		/* code point */
	UINT8				fec_payload_id;	/* exist or not */
	UINT16				reserved;
} DELIVERY_ROUTE_PAYLOAD_INFO_T;

typedef struct
{
	UINT32				transaction_id; 	/**< Transaction ID */
	UINT8				plp_id;
	DELIVERY_IP_UDP_T	ip_udp;

	UINT32				tsi;				/* Transport Session Identifier */
	UINT32				init_toi;
	UINT32				start_number;

	DELIVERY_ROUTE_PAYLOAD_INFO_T	*payload_info;
	UINT32				num_payload_info;

	DELIVERY_AV_TYPE_T	type;
} DELIVERY_ROUTE_AV_FILTER_T;

typedef struct
{
	UINT32				transaction_id; 	/**< Transaction ID */
	UINT8				plp_id;
	DELIVERY_IP_UDP_T	ip_udp;

	UINT32				tsi;				/* Transport Session Identifier */
	UINT32				toi;
	UINT32				toi_mask;

	DELIVERY_ROUTE_PAYLOAD_INFO_T	*payload_info;
	UINT32				num_payload_info;

	UINT8
		ignore_duplicate_data		: 1,	/* only send different data */
		oneshot_mode				: 1,	/* only one packet */
		reserved					: 6;

} DELIVERY_ROUTE_OBJECT_FILTER_T;

typedef struct
{
	UINT32				transaction_id; 	/**< Transaction ID */
	UINT8				plp_id;
	DELIVERY_IP_UDP_T	ip_udp;

	UINT32				tsi;				/* Transport Session Identifier */
	UINT8				system_type;
	UINT8				system_id;
	UINT8				data_type;
	UINT16				version;

	DELIVERY_ROUTE_PAYLOAD_INFO_T	*payload_info;
	UINT32				num_payload_info;

	UINT8
		oneshot_mode				: 1,	/* only one packet */
		system_id_filter			: 1,
		version_filter				: 1,
		not_version_filter			: 1,
		reserved					: 4;

} DELIVERY_ROUTE_CAS_FILTER_T;

typedef struct
{
	UINT32				transaction_id;			/**< Transaction ID */
	UINT8				plp_id;
	DELIVERY_IP_UDP_T	ip_udp;
	UINT16				packet_id;
	UINT16				message_id;
	UINT16				message_id_filter_mask;
	UINT8				message_version;
	UINT8				table_id;
	UINT8				table_version;
	UINT16				content_type;
	UINT8				content_version;
	UINT8
			oneshot_mode				: 1,	/** only one packet */
			message_version_filter		: 1,
			not_message_version_filter	: 1,
			table_id_filter				: 1,
			table_version_filter		: 1,
			not_table_version_filter	: 1,
			content_version_filter		: 1,
			not_content_version_filter	: 1;
} DELIVERY_MMT_SLS_FILTER_T;

typedef struct
{
	UINT32				transaction_id;			/**< Transaction ID */
	UINT8				plp_id;
	DELIVERY_IP_UDP_T	ip_udp;
	UINT16				packet_id;

	DELIVERY_AV_TYPE_T	type;
} DELIVERY_MMT_AV_FILTER_T;


/* message types */
typedef struct
{
	UINT8				signal_type;
	UINT8				signal_version;
	UINT16				signal_type_extension;
	UINT8				signal_format	: 2,
						signal_encoding	: 2,
						reserved		: 4;
} DELIVERY_LINK_SIGNAL_INFO_T;

typedef struct
{
    UINT8				is_encoded;
    UINT16				fragment_included;
    UINT8				version;
} DELIVERY_ROUTE_SLS_INFO_T;

typedef struct
{
	UINT32				toi;
} DELIVERY_ROUTE_OBJECT_INFO_T;

typedef struct
{
	UINT32					toi;

	UINT8					is_mde_mode;	/* TRUE : MDE with RAP */

	DELIVERY_TIMESTAMP_T	sender_current_time;
	DELIVERY_TIMESTAMP_T	presentation_time;

	UINT32					total_len;	/* Object Length(total) */
										/* MDE with RAP offset = Refer len in FILTER_MSG_T */
} DELIVERY_ROUTE_AV_INFO_T;

typedef struct
{
	UINT8					system_type;
	UINT8					system_id;
	UINT8					data_type;
	UINT16					version;
} DELIVERY_ROUTE_CAS_INFO_T;

typedef struct
{
    UINT32				movie_fragment_sequence_number;	// movie_fragment_sequence_number
    UINT32				sample_number;					// the number of total samples
    UINT32				offset; 						// offset of the media data of this MFU inside the referenced sample

    UINT8				priority;
    UINT8				dep_counter;
} DELIVERY_MFU_DU_HEADER_T;

typedef struct
{
	UINT32						timestamp;			// In MMTP packet header.
	UINT8						rap_flag;			// In MMTP packet header

	UINT8						mpu_fragment_type;		// MMTP payload header - 0: MPU metadata, 1:Movoie fragment metadata, 2: MFU
	UINT32              		mpu_sequence_number;	// MPU_sequence_number

 	DELIVERY_MFU_DU_HEADER_T	du_header;
} DELIVERY_MMT_AV_INFO_T;

typedef struct
{
	DELIVERY_CHANNEL_T			ch;
	DELIVERY_PROTOCOL_TYPE_T	type;
	UINT32						filter_id;
	UINT32						transaction_id;			/**< Transaction ID */
	UINT8						*data;
	UINT32						len;

	union
	{
		DELIVERY_LINK_SIGNAL_INFO_T		link_signal;
		DELIVERY_ROUTE_SLS_INFO_T		route_sls;
		DELIVERY_ROUTE_AV_INFO_T		route_av;
		DELIVERY_ROUTE_OBJECT_INFO_T	route_obj;
		DELIVERY_ROUTE_CAS_INFO_T		route_cas;
		DELIVERY_MMT_AV_INFO_T			mmt_av;
	} info;
} DELIVERY_FILTER_MSG_T;

/* In MDE mode */
typedef struct
{
	DELIVERY_PROTOCOL_TYPE_T	type;
	UINT32						filter_id;
	UINT32						transaction_id;			/**< Transaction ID */
	UINT8						*data;
	UINT32						len;
} DELIVERY_FILTER_STATUS_T;

typedef enum
{
	DELIVERY_PARAM_ROUTE_MODE = 0,
	DELIVERY_PARAM_DEMOD_TYPE,
	DELIVERY_PARAM_TIMEOUT,
	DELIVERY_PARAM_MAX
} DELIVERY_PARAM_T;

typedef struct
{
    UINT8       plp_id;
    UINT8       cc;         /* continuity counter */
    UINT16      reserved;

    UINT8       *data;      /* directly accessible memory */
    UINT32      len;
} DELIVERY_BB_FRAME_T;

typedef enum
{
	DELIVERY_MODE_ATSC30 = 0,
	DELIVERY_MODE_JAPAN4K,
	DELIVERY_MODE_MAX
} DELIVERY_MODE_T;

/*----------------------------------------------------------------------------------------
  Function Prototype Declaration
----------------------------------------------------------------------------------------*/

DTV_STATUS_T HAL_DELIVERY_SetParam(DELIVERY_PARAM_T param, UINT32 val);
DTV_STATUS_T HAL_DELIVERY_GetParam(DELIVERY_PARAM_T param, UINT32 *val);
DTV_STATUS_T HAL_DELIVERY_Initialize(void);
DTV_STATUS_T HAL_DELIVERY_Finalize(void);
DTV_STATUS_T HAL_DELIVERY_OpenChannel(DELIVERY_CHANNEL_T ch);
DTV_STATUS_T HAL_DELIVERY_CloseChannel(DELIVERY_CHANNEL_T ch);

DTV_STATUS_T HAL_DELIVERY_SetInputConfig(DELIVERY_CHANNEL_T ch,
									 	 DELIVERY_INPUT_PORT_T portType,
									  	 DELIVERY_INPUT_TYPE_T inputType,
									  	 UINT32 option);
DTV_STATUS_T HAL_DELIVERY_GetInputConfig(DELIVERY_CHANNEL_T ch,
										 DELIVERY_INPUT_PORT_T *pPortType,
										 DELIVERY_INPUT_TYPE_T *pInputType,
										 UINT32 *pOption);

DTV_STATUS_T HAL_DELIVERY_RequestFilter(DELIVERY_CHANNEL_T ch,
										DELIVERY_PROTOCOL_TYPE_T type,
										void *pFilter,
								 		UINT32 gpbSize,
										UINT32 *pFilterIndex);
DTV_STATUS_T HAL_DELIVERY_CancelFilter(DELIVERY_CHANNEL_T ch,
								 	   UINT32 filterIndex);

DTV_STATUS_T HAL_DELIVERY_GetFilterMessage(DELIVERY_FILTER_MSG_T *pMsg,
										   UINT32 maxCount,
										   UINT32 *pReadCount,
										   UINT32 timeout /* ms */);
DTV_STATUS_T HAL_DELIVERY_GetFilterStatus(DELIVERY_CHANNEL_T ch,
										   UINT32 filterIndex,
										   DELIVERY_FILTER_STATUS_T *pStatus);

DTV_STATUS_T HAL_DELIVERY_CopyFilterData(DELIVERY_CHANNEL_T ch,
										 UINT32 filterIndex,
										 UINT8 *pDest,
										 UINT8 *pBufAddr,
										 UINT32 dataSize);
DTV_STATUS_T HAL_DELIVERY_ReturnFilterData(DELIVERY_CHANNEL_T ch,
										   UINT32 filterIndex,
										   UINT8 *pBufAddr,
										   UINT32 dataSize);

DTV_STATUS_T HAL_DELIVERY_ResetFilters(DELIVERY_CHANNEL_T ch,
									   DELIVERY_FILTER_CLEAN_SCOPE_T scope);
DTV_STATUS_T HAL_DELIVERY_StartClockRecovery(DELIVERY_CHANNEL_T ch);
DTV_STATUS_T HAL_DELIVERY_StopClockRecovery(DELIVERY_CHANNEL_T ch);
DTV_STATUS_T HAL_DELIVERY_GetCurrentTime(DELIVERY_CHANNEL_T ch,
										 DELIVERY_TIME_T *time);

DTV_STATUS_T HAL_DELIVERY_SetSystemTimeInfo(DELIVERY_CHANNEL_T ch,
											DELIVERY_SYSTEM_TIME_INFO_T *info);

DTV_STATUS_T HAL_DELIVERY_SetCurrentTime(DELIVERY_CHANNEL_T ch,
										 DELIVERY_TIME_T *time);



DTV_STATUS_T HAL_DELIVERY_RequestBBFrame(DELIVERY_CHANNEL_T ch);
DTV_STATUS_T HAL_DELIVERY_GetBBFrameBuffer(DELIVERY_CHANNEL_T ch,
										   DELIVERY_BB_FRAME_T **frame,
										   UINT32 *count,
										   UINT32 timeout /* ms */);
DTV_STATUS_T HAL_DELIVERY_ReturnBBFrameBuffer(DELIVERY_CHANNEL_T ch,
											  DELIVERY_BB_FRAME_T *frame);
DTV_STATUS_T HAL_DELIVERY_ResetBBFrame(DELIVERY_CHANNEL_T ch);
DTV_STATUS_T HAL_DELIVERY_CancelBBFrame(DELIVERY_CHANNEL_T ch);

DTV_STATUS_T HAL_DELIVERY_SetMode(DELIVERY_MODE_T mode);
DTV_STATUS_T HAL_DELIVERY_RequestData(DELIVERY_CHANNEL_T ch);
DTV_STATUS_T HAL_DELIVERY_CancelData(DELIVERY_CHANNEL_T ch);
SINT32 HAL_DELIVERY_Read(DELIVERY_CHANNEL_T ch, UINT8 *buffer, UINT32 buf_size);

DTV_STATUS_T HAL_DELIVERY_DebugCommand(const char* pszCmd,const char *pszParam,char** buffer);
/*----------------------------------------------------------------------------------------
  Extern Variables
----------------------------------------------------------------------------------------*/




#endif

