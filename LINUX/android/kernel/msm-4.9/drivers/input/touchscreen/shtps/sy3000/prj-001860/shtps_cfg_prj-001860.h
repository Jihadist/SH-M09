/* drivers/input/touchscreen/shtps/sy3000/prj-001860/shtps_cfg_prj-001860.h
 *
 * Copyright (c) 2017, Sharp. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef __SHTPS_CFG_PRJ_001860_H__
#define __SHTPS_CFG_PRJ_001860_H__

#define SHTPS_DRIVER_CONFIG_ID		"PRJ-001860"

/* ===================================================================================
 * [ Debug ]
 */
//#define SHTPS_DEVELOP_MODE_ENABLE

//#define SHTPS_RELEASE_FOR_MANUFACTURER

#ifdef	SHTPS_DEVELOP_MODE_ENABLE
	//#define SHTPS_PERFORMANCE_CHECK_ENABLE
	//#define SHTPS_LOG_SEQ_ENABLE
	//#define SHTPS_LOG_SPIACCESS_SEQ_ENABLE
	#define SHTPS_LOG_DEBUG_ENABLE
	#define	SHTPS_LOG_EVENT_ENABLE
	#define	SHTPS_MODULE_PARAM_ENABLE
	#define	SHTPS_DEBUG_VARIABLE_DEFINES
	#define SHTPS_CREATE_KOBJ_ENABLE
	#define SHTPS_DEVICE_ACCESS_LOG_ENABLE
#endif

#define	SHTPS_LOG_ERROR_ENABLE
//#define SHTPS_DEF_RECORD_LOG_FILE_ENABLE

#ifdef SHTPS_LOG_EVENT_ENABLE
	#define SHTPS_LOG_OUTPUT_SWITCH_ENABLE
#endif /* #if defined( SHTPS_LOG_EVENT_ENABLE ) */

#if defined(SHTPS_PERFORMANCE_CHECK_ENABLE)
	#define SHTPS_PERFORMANCE_CHECK_PIN_ENABLE
	//#define SHTPS_PERFORMANCE_TIME_LOG_ENABLE
#endif /* SHTPS_PERFORMANCE_CHECK_ENABLE */

/* ===================================================================================
 * [ Diag ]
 */
#ifdef	SHTPS_FACTORY_MODE_ENABLE
	#undef	SHTPS_BOOT_FWUPDATE_ENABLE
	#undef	SHTPS_BOOT_FWUPDATE_FORCE_UPDATE
	#define	SHTPS_FMODE_GESTURE_ENABLE
	#define SHTPS_TPIN_CHECK_ENABLE
	#define	SHTPS_CHECK_CRC_ERROR_ENABLE
#else
	#define	SHTPS_BOOT_FWUPDATE_ENABLE
	#undef	SHTPS_BOOT_FWUPDATE_FORCE_UPDATE
	#undef	SHTPS_FMODE_GESTURE_ENABLE
	#undef	SHTPS_TPIN_CHECK_ENABLE
	#undef	SHTPS_CHECK_CRC_ERROR_ENABLE
#endif

#define	SHTPS_SMEM_BASELINE_ENABLE

#define SHTPS_DIAGPOLL_TIME							100


/* ===================================================================================
 * [ Firmware update ]
 */
//#define SHTPS_MULTI_FW_ENABLE
//#define SHTPS_CHECK_HWID_ENABLE
#define SHTPS_SPI_FWBLOCKWRITE_ENABLE
#define	SHTPS_FWUPDATE_BUILTIN_ENABLE
//#define SHTPS_CHECK_LCD_RESOLUTION_ENABLE

#define SHTPS_GET_HW_VERSION_RET_ES0_ES1	0
#define SHTPS_GET_HW_VERSION_RET_PP1		2
#define SHTPS_GET_HW_VERSION_RET_PP2		1
#define SHTPS_GET_HW_VERSION_RET_MP			3
#define SHTPS_GET_HW_VERSION_RET_UNKNOWN	0xFF

#if defined(SHTPS_BOOT_FWUPDATE_ENABLE)
	#if defined(SHTPS_CHECK_HWID_ENABLE)
//		#define SHTPS_BOOT_FWUPDATE_ONLY_ON_HANDSET
//		#define	SHTPS_BOOT_FWUPDATE_SKIP_ES0_ENABLE
	#endif /* SHTPS_CHECK_HWID_ENABLE */
#endif

#define SHTPS_FWUPDATE_PRODUCTID		"PRJ-001860"
#define SHTPS_FWUPDATE_PRODUCTID2		"PRJ-001860"


#if defined(SHTPS_MULTI_FW_ENABLE)
	#include "prj-001860/shtps_fw_prj-001860_pp1.h"
	#include "prj-001860/shtps_fw_prj-001860.h"

	#define SHTPS_FW_KIND_PP2				0
	#define SHTPS_FW_KIND_PP1				1
	#define SHTPS_FW_KIND_UNKNOWN			0xFF

	typedef struct {
		unsigned char		fwkind;
		const unsigned char	*data;
		int					size;
		unsigned short		ver;
		char				*name;
	} shtps_multi_fw_info_t;

	static const shtps_multi_fw_info_t SHTPS_MULTI_FW_INFO_TBL[] = {
		{ SHTPS_FW_KIND_PP2,		tps_fw_data,		SHTPS_FWSIZE_NEWER,		SHTPS_FWVER_NEWER,		"PP2"			},
		{ SHTPS_FW_KIND_PP1,		tps_fw_data_pp1,	SHTPS_FWSIZE_NEWER_PP1,	SHTPS_FWVER_NEWER_PP1,	"PP1"			},
		{ SHTPS_FW_KIND_UNKNOWN,	NULL,				0,						0,						"NOT SUPPORT"	},
	};
	static const int SHTPS_MULTI_FW_INFO_SIZE = sizeof(SHTPS_MULTI_FW_INFO_TBL) / sizeof(shtps_multi_fw_info_t);
#else
	#include "prj-001860/shtps_fw_prj-001860.h"
#endif /* SHTPS_MULTI_FW_ENABLE */

#if defined(SHTPS_CHECK_LCD_RESOLUTION_ENABLE)
	#define SHTPS_LCD_RESOLUTION_KIND_WQHD			0
	#define SHTPS_LCD_RESOLUTION_KIND_FHD			1
#endif /* SHTPS_CHECK_LCD_RESOLUTION_ENABLE */

/* ===================================================================================
 * [ Model specifications ]
 */
#define CONFIG_SHTPS_SY3000_LCD_SIZE_HD_X		720
#define CONFIG_SHTPS_SY3000_LCD_SIZE_HD_Y		1280
#define CONFIG_SHTPS_SY3000_LCD_SIZE_FHD_X		1080
#define CONFIG_SHTPS_SY3000_LCD_SIZE_FHD_Y		1920
#define CONFIG_SHTPS_SY3000_LCD_SIZE_WQHD_X		1440
#define CONFIG_SHTPS_SY3000_LCD_SIZE_WQHD_Y		2560
#define CONFIG_SHTPS_SY3000_LCD_SIZE_CORNER_R_FHD_X		1080
#define CONFIG_SHTPS_SY3000_LCD_SIZE_CORNER_R_FHD_Y		2032
#define CONFIG_SHTPS_SY3000_LCD_SIZE_CORNER_R_WQHD_X	1440
#define CONFIG_SHTPS_SY3000_LCD_SIZE_CORNER_R_WQHD_Y	3040

#define CONFIG_SHTPS_SY3000_LCD_SIZE_DEFAULT_X	CONFIG_SHTPS_SY3000_LCD_SIZE_CORNER_R_WQHD_X
#define CONFIG_SHTPS_SY3000_LCD_SIZE_DEFAULT_Y	CONFIG_SHTPS_SY3000_LCD_SIZE_CORNER_R_WQHD_Y

#define CONFIG_SHTPS_SY3000_LCD_SIZE_X			gShtps_panel_size_x
#define CONFIG_SHTPS_SY3000_LCD_SIZE_Y			gShtps_panel_size_y

#define SHTPS_COORDINATES_POINT_SYMMETRY_ENABLE
#define SHTPS_SENSOR_POINT_SYMMETRY_ENABLE

//#define CONFIG_SHTPS_SY3000_FACETOUCH_DETECT
//#define CONFIG_SHTPS_SY3000_FACETOUCH_OFF_DETECT

#define SHTPS_IRQ_LEVEL_ENABLE
//#define SHTPS_SYSTEM_BOOT_MODE_CHECK_ENABLE
#define SHTPS_IRQ_LOADER_CHECK_INT_STATUS_ENABLE

#define SHTPS_GLOVE_DETECT_ENABLE
#define SHTPS_LPWG_MODE_ENABLE
#define SHTPS_COVER_ENABLE

#if defined( SHTPS_LPWG_MODE_ENABLE )
	#define SHTPS_HOST_LPWG_MODE_ENABLE
#endif /* SHTPS_LPWG_MODE_ENABLE */

#define SHTPS_LOW_POWER_MODE_ENABLE

#define SHTPS_QOS_LATENCY_DEF_VALUE	 			34

#define SHTPS_BASELINE_OFFSET_DISABLE_WAIT_ENABLE

#define SHTPS_NOTIFY_TOUCH_MINOR_ENABLE

#define SHTPS_VAL_FINGER_WIDTH_MAXSIZE (50)

//#define SHTPS_POWER_ON_CONTROL_ENABLE

//#define SHTPS_POWER_OFF_IN_SLEEP_ENABLE

/* ===================================================================================
 * [ Firmware control ]
 */
#define SHTPS_DEF_FWCTL_IC_TYPE_3400
//#define SHTPS_DEF_FWCTL_IC_TYPE_3700

#define SHTPS_DEF_FWCTL_PROTOCOL_SPI
//#define SHTPS_DEF_FWCTL_PROTOCOL_I2C

#define SHTPS_FWDATA_BLOCK_SIZE_MAX					0xFFFF
#define SHTPS_BOOTLOADER_ACK_TMO					2000
#define SHTPS_FWTESTMODE_ACK_TMO					1000
#define SHTPS_F54_COMMAND_WAIT_POLL_COUNT			30
#define SHTPS_F54_COMMAND_WAIT_POLL_INTERVAL		10
#define SHTPS_PDT_PAGE_SIZE_MAX						4
#define SHTPS_PDT_READ_RETRY_COUNT					5
#define SHTPS_PDT_READ_RETRY_INTERVAL				200
#define SHTPS_FLASH_ERASE_WAIT_MS					2000

#define SHTPS_GET_PANEL_SIZE_X(ts)					(shtps_fwctl_get_maxXPosition(ts) + 1)
#define SHTPS_GET_PANEL_SIZE_Y(ts)					(shtps_fwctl_get_maxYPosition(ts) + 1)

#define SHTPS_POS_SCALE_X(ts)	(((CONFIG_SHTPS_SY3000_LCD_SIZE_X) * 10000) / shtps_fwctl_get_maxXPosition(ts))
#define SHTPS_POS_SCALE_Y(ts)	(((CONFIG_SHTPS_SY3000_LCD_SIZE_Y) * 10000) / shtps_fwctl_get_maxYPosition(ts))

#define SHTPS_REG_F54_ANALOG_CTRL41_OFFSET			0x14
#define SHTPS_REG_F54_ANALOG_CTRL57_OFFSET			0x17
#define SHTPS_REG_F54_ANALOG_CTRL88_OFFSET			0x17
#define SHTPS_REG_F54_ANALOG_CTRL149_OFFSET			0x31

/* ===================================================================================
 * [ Hardware specifications ]
 */
#define TPS_SPI_R_CLOCK			1600000
#define TPS_SPI_W_CLOCK			3200000
#define TPS_SPI_FW_W_CLOCK		3200000

#define TPS_SPI_R_BYTE_DELAY	36
#define TPS_SPI_W_BYTE_DELAY	10
#define TPS_SPI_FW_W_BYTE_DELAY	5
#define TPS_SPI_R_TANS_WAIT		5
#define TPS_SPI_W_TANS_WAIT		10
#define TPS_SPI_FW_W_TANS_WAIT	5

#define SHTPS_SY3X00_FINGER_SPIREAD_CNT		2

#define	SHTPS_SY3X00_SPIBLOCK_BUFSIZE		(SHTPS_TM_TXNUM_MAX * 4)
#define SHTPS_SY3X00_SPIBLOCKWRITE_BUFSIZE		0x10

#define SHTPS_SPI_RETRY_COUNT					5
#define SHTPS_SPI_RETRY_WAIT					5

#define SHTPS_STARTUP_MIN_TIME					300
#define SHTPS_POWERON_WAIT_MS					400
#define SHTPS_POWEROFF_WAIT_MS					10
#define SHTPS_HWRESET_TIME_US					1
#define SHTPS_HWRESET_AFTER_TIME_MS				1
#define SHTPS_HWRESET_WAIT_MS					290
#define SHTPS_SWRESET_WAIT_MS					300
#define SHTPS_RESET_BOOTLOADER_WAIT_MS			400
#define SHTPS_SLEEP_OUT_WAIT_US					67500

#define SHTPS_POWER_VDDH_WAIT_US				200
#define SHTPS_POWER_VBUS_WAIT_US				300

#define SHTPS_READ_SERIAL_NUMBER_SIZE			16

#define SHTPS_READ_SERIAL_NUMBER_CHECK_F01_ENABLE
#if defined(SHTPS_READ_SERIAL_NUMBER_CHECK_F01_ENABLE)
	#define SHTPS_READ_SERIAL_NUMBER_FROM_F01_SIZE	7
#endif /* SHTPS_READ_SERIAL_NUMBER_CHECK_F01_ENABLE */

#define SHTPS_PROXIMITY_SUPPORT_ENABLE
#if defined(SHTPS_PROXIMITY_SUPPORT_ENABLE)
	#define SHTPS_PROXIMITY_USE_API
#endif /* SHTPS_PROXIMITY_SUPPORT_ENABLE */

/* ===================================================================================
 * [ Performance ]
 */
//#define SHTPS_CPU_CLOCK_CONTROL_ENABLE

#define SHTPS_CPU_IDLE_SLEEP_CONTROL_ENABLE
#define SHTPS_CPU_SLEEP_CONTROL_FOR_FWUPDATE_ENABLE


/* ===================================================================================
 * [ Standard ]
 */
#define SHTPS_IRQ_LINKED_WITH_IRQWAKE_ENABLE
#define SHTPS_PDT_READ_RETRY_ENABLE
#define SHTPS_SPI_AVOID_BLOCKREAD_FAIL

#define SHTPS_INPUT_POWER_MODE_CHANGE_ENABLE
#define SHTPS_GUARANTEE_SPI_ACCESS_IN_WAKE_ENABLE
#define SHTPS_TOUCHCANCEL_BEFORE_FORCE_TOUCHUP_ENABLE
#define SHTPS_WAKEUP_FAIL_TOUCH_EVENT_REJECTION_ENABLE


/* ===================================================================================
 * [ Host functions ]
 */
#if defined(SHTPS_RELEASE_FOR_MANUFACTURER)

#else

#define SHTPS_ACTIVE_SLEEP_WAIT_ALWAYS_ENABLE
#define SHTPS_DYNAMIC_RESET_CONTROL_ENABLE
#define SHTPS_CTRL_FW_REPORT_RATE
#define SHTPS_DEF_DISALLOW_Z_ZERO_TOUCH_EVENT_ENABLE

#ifdef CONFIG_SHARP_SHTERM
	#define SHTPS_SEND_SHTERM_EVENT_ENABLE
#endif

#if defined(SHTPS_GLOVE_DETECT_ENABLE)
//	#define SHTPS_DEF_GLOVE_CHANGE_LANDLIFTFILTER_ENABLE
#endif /* SHTPS_GLOVE_DETECT_ENABLE */

#if defined(SHTPS_COVER_ENABLE)
//	#define SHTPS_DEF_COVER_CHANGE_REPORT_NUM_MAX_ENABLE
//	#define SHTPS_DEF_COVER_CHANGE_FINGER_AMP_THRESH_ENABLE
#endif /* SHTPS_COVER_ENABLE */

#if defined(SHTPS_BOOT_FWUPDATE_FORCE_UPDATE)
	#undef SHTPS_BOOT_FWUPDATE_ONLY_ON_HANDSET
#endif /* SHTPS_BOOT_FWUPDATE_FORCE_UPDATE */

#if defined(SHTPS_LPWG_MODE_ENABLE)
	#define SHTPS_LPWG_DOUBLE_TAP_ENABLE
//	#define SHTPS_LPWG_SWEEP_ON_ENABLE
	#if defined(SHTPS_LPWG_SWEEP_ON_ENABLE)
		#define SHTPS_LPWG_CHANGE_SWIPE_DISTANCE_ENABLE
		#define SHTPS_LPWG_GRIP_SUPPORT_ENABLE
			#if defined(SHTPS_LPWG_GRIP_SUPPORT_ENABLE)
				#define SHTPS_DEF_LPWG_GRIP_PROC_ASYNC_ENABLE
			#endif /* SHTPS_LPWG_GRIP_SUPPORT_ENABLE */
		#define SHTPS_LPWG_ALLOWED_SWIPES_ENABLE
	#endif /* defined(SHTPS_LPWG_SWEEP_ON_ENABLE) */
#endif /* SHTPS_LPWG_MODE_ENABLE */

#if defined( SHTPS_DYNAMIC_RESET_CONTROL_ENABLE )
	#define SHTPS_DYNAMIC_RESET_ESD_ENABLE
//	#define SHTPS_DYNAMIC_RESET_ESD_FLG_CHECK_ENABLE
	#define SHTPS_DYNAMIC_RESET_SPI_ERROR_ENABLE
#endif /* SHTPS_DYNAMIC_RESET_CONTROL_ENABLE */

#if defined(SHTPS_CTRL_FW_REPORT_RATE) && defined(SHTPS_LOW_POWER_MODE_ENABLE)
//	#define SHTPS_DEF_CTRL_FW_REPORT_RATE_LINKED_LCD_BRIGHT_ENABLE
#endif /* SHTPS_CTRL_FW_REPORT_RATE && SHTPS_LOW_POWER_MODE_ENABLE */

#if defined(SHTPS_CPU_CLOCK_CONTROL_ENABLE) && defined(SHTPS_LOW_POWER_MODE_ENABLE)
	#define SHTPS_DEF_CTRL_CPU_CLOCK_LINKED_LCD_BRIGHT_ENABLE
	#define SHTPS_DEF_CTRL_CPU_CLOCK_LINKED_ECO_ENABLE
#endif /* SHTPS_CPU_CLOCK_CONTROL_ENABLE && SHTPS_LOW_POWER_MODE_ENABLE */

#endif /*SHTPS_RELEASE_FOR_MANUFACTURER*/

/* -----------------------------------------------------------------------------------
 */
#endif /* __SHTPS_CFG_PRJ_001860_H__ */
