#ifndef IPMI_CONFIG_H
#define IPMI_CONFIG_H

/*
 * MyMCU Configuration
 */
#define CONFIG_CPU_WINBOND_HERMON 1

/*
 * Platform Configuration
 */
#define CONFIG_PLATFORM_SUPERMICRO_X7SB3 1
#undef CONFIG_PLATFORM_SUPERMICRO_SUBVERSION_X8DTT

/*
 * Build Option
 */
#define CONFIG_BUILD_SHARE_LIB 1
#define CONFIG_COMPILE_FLAGS "-DUSER_LOCK_DISABLE"
#define CONFIG_LINK_FLAGS ""
#undef CONFIG_STRIP_OBJECTS
#undef CONFIG_DEBUG_NETCONSOLE
#undef CONFIG_DEBUG

/*
 */

/*
 * IPMI
 */

/*
 * Channel Configuration
 */
#define CONFIG_CHNL_LAN 1
#define CONFIG_CHNL_LAN_OBJ 1
#undef CONFIG_CHNL_LAN_SRC
#define CONFIG_CHNL_KCS 1
#define CONFIG_CHNL_KCS_OBJ 1
#undef CONFIG_CHNL_KCS_SRC
#define CONFIG_CHNL_UART 1
#define CONFIG_CHNL_UART_OBJ 1
#undef CONFIG_CHNL_UART_SRC
#define CONFIG_CHNL_IPMB 1
#define CONFIG_CHNL_IPMB_OBJ 1
#undef CONFIG_CHNL_IPMB_SRC

/*
 * Module Configuration
 */
#define CONFIG_MODULE_SOL 1
#define CONFIG_MODULE_FW_FIREWALL 1
#define CONFIG_MODULE_SENSOR 1
#define CONFIG_MODULE_SENSOR_OBJ 1
#undef CONFIG_MODULE_SENSOR_SRC
#define CONFIG_MODULE_EVENT 1
#define CONFIG_MODULE_EVENT_OBJ 1
#undef CONFIG_MODULE_EVENT_SRC

/*
 * Driver Configuration
 */
#define CONFIG_DRIVERS 1
#define CONFIG_WDT_DRV 1
#define CONFIG_WDT_DRV_OBJ 1
#undef CONFIG_WDT_DRV_SRC
#define CONFIG_ADC_DRV 1
#define CONFIG_ADC_DRV_OBJ 1
#undef CONFIG_ADC_DRV_SRC
#define CONFIG_GPIO_DRV 1
#define CONFIG_GPIO_DRV_OBJ 1
#undef CONFIG_GPIO_DRV_SRC
#undef CONFIG_PWM_DRV
#undef CONFIG_PWM_DRV_OBJ
#undef CONFIG_PWM_DRV_SRC
#define CONFIG_UART_DRV 1
#define CONFIG_UART_DRV_OBJ 1
#undef CONFIG_UART_DRV_SRC
#define CONFIG_KCS_DRV 1
#define CONFIG_KCS_DRV_OBJ 1
#undef CONFIG_KCS_DRV_SRC
#define CONFIG_I2C_DRV 1
#define CONFIG_I2C_DRV_OBJ 1
#undef CONFIG_I2C_DRV_SRC
#define CONFIG_NIC_DRV 1
#define CONFIG_NIC_DRV_OBJ 1
#undef CONFIG_NIC_DRV_SRC
#define CONFIG_PECI_DRV 1
#define CONFIG_PECI_DRV_OBJ 1
#undef CONFIG_PECI_DRV_SRC
#define CONFIG_TECHOMETER_DRV 1
#define CONFIG_TECHOMETER_DRV_OBJ 1
#undef CONFIG_TECHOMETER_DRV_SRC

/*
 * NVRAM Drivers
 */
#define CONFIG_EE24C256_DRV 1
#define CONFIG_EE24C256_DRV_OBJ 1
#undef CONFIG_EE24C256_DRV_SRC
#define CONFIG_SPIFLASH_DRV 1
#define CONFIG_FILE_DRV 1
#define CONFIG_FILE_DRV_OBJ 1
#undef CONFIG_FILE_DRV_SRC

/*
 * Sensor drivers
 */
#define CONFIG_RAM_SENSOR 1
#define CONFIG_RAM_SENSOR_DRV_OBJ 1
#undef CONFIG_RAM_SENSOR_DRV_SRC

/*
 * Flash drivers
 */
#define CONFIG_SPI_FLASH 1
#define CONFIG_SPI_FLASH_DRV_OBJ 1
#undef CONFIG_SPI_FLASH_DRV_SRC

/*
 * Virtual Storage
 */
#define CONFIG_VIRTUALUSB 1
#undef CONFIG_PREMOUNT

/*
 * iKVM
 */
#define CONFIG_IKVM 1

/*
 * Video Source
 */
#define CONFIG_INT_VGA 1
#undef CONFIG_EXT_VGA
#undef CONFIG_EXT_DVI

/*
 * Web Server
 */
#define CONFIG_WEBSERVER 1

/*
 * WEB STYLE
 */
#undef CONFIG_SAMPLE_SUPER_MICRO_X8DTL
#define CONFIG_SUPERMICRO_2010 1

/*
 * Open Blade
 */
#undef CONFIG_COMPUTE_BLADE
#undef CONFIG_BLADE_MANAGEMENT_CONTROLLER
#undef CONFIG_CHASSIS_MANAGER
#undef CONFIG_COMPUTE_BLADE_OBJ
#undef CONFIG_COMPUTE_BLADE_SRC

/*
 * OpenWSMAN
 */
#define CONFIG_OPENWSMAN 1

/*
 * SMASH
 */
#define CONFIG_SMASH 1

/*
 * SNMP
 */
#undef CONFIG_SNMP

/*
 * DDNS
 */
#define CONFIG_DDNS 1

/*
 * Node Manager
 */
#define CONFIG_NM 1

/*
 * Network Time Protocol
 */
#define CONFIG_NTP 1

/*
 * DCMI
 */
#define CONFIG_DCMI 1

/*
 * TFTPD
 */
#undef CONFIG_TFTP

/*
 * UPNP
 */
#define CONFIG_UPNP 1

/*
 * LLDP
 */
#undef CONFIG_LLDP

/*
 * CHANNEL BONDING
 */
#define CONFIG_CHANNEL_BONDING 1

/*
 * Active Directory
 */
#define ENABLE_ACTIVE_DIRECTORY 1
#endif /* IPMI_CONFIG_H */
