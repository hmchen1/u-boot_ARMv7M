/*
 * (C) Copyright 2015
 * Kamil Lulko, <rev13@wp.pl>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_STM32F4DISCOVERY
#define CONFIG_SYS_GENERIC_BOARD

#define CONFIG_MACH_TYPE 0x000011e0

#define CONFIG_OF_LIBFDT

/*#define DEBUG*/

#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_BOARD_LATE_INIT

#define CONFIG_SYS_FLASH_BASE 0x08000000

#define CONFIG_SYS_INIT_SP_ADDR	0x10010000
#define CONFIG_SYS_TEXT_BASE	0x08000000
/*
 * Configuration of the external SDRAM memory
 */
#define CONFIG_NR_DRAM_BANKS		1
#define CONFIG_SYS_RAM_SIZE		(8 * 1024 * 1024)
#define CONFIG_SYS_RAM_CS		1
#define CONFIG_SYS_RAM_FREQ_DIV		2
#define CONFIG_SYS_RAM_BASE		0xD0000000
#define CONFIG_SYS_SDRAM_BASE		CONFIG_SYS_RAM_BASE
#define CONFIG_SYS_LOAD_ADDR		0xD0400000
#define CONFIG_LOADADDR		0xD0400000

#define CONFIG_SYS_MAX_FLASH_SECT	12
#define CONFIG_SYS_MAX_FLASH_BANKS	2

#define CONFIG_ENV_IS_IN_FLASH
#define CONFIG_ENV_OFFSET	(256 * 1024)
#define CONFIG_ENV_SECT_SIZE (128 * 1024)
#define CONFIG_ENV_SIZE	(8 * 1024)

#define CONFIG_BOARD_SPECIFIC_LED
#define CONFIG_RED_LED		110
#define CONFIG_GREEN_LED	109

#define CONFIG_STM32_GPIO
#define CONFIG_STM32_SERIAL
#define CONFIG_STM32_SPI
#define CONFIG_MMC
#define CONFIG_MMC_SPI
#define CONFIG_GENERIC_MMC

#define CONFIG_STM32_LTDC
#define CONFIG_LCD
#define CONFIG_FB_ADDR	0x20000000
#define LCD_BPP	LCD_COLOR16
#define CONFIG_LCD_LOGO
#define CONFIG_LCD_INFO
#define CONFIG_LCD_INFO_BELOW_LOGO
#define CONFIG_SYS_WHITE_ON_BLACK
#define CONFIG_SYS_CONSOLE_IS_IN_ENV
#define CONFIG_SYS_CONSOLE_OVERWRITE_ROUTINE

#define CONFIG_DOS_PARTITION

#define CONFIG_STM32_USART1

#define CONFIG_SYS_ICACHE_OFF
#define CONFIG_SYS_DCACHE_OFF

#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG

#define CONFIG_STM32_HSE_HZ	8000000

#define CONFIG_SYS_HZ_CLOCK	1000000	/* Timer is clocked at 1MHz */

#define CONFIG_SYS_CBSIZE	1024
#define CONFIG_SYS_PBSIZE	(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) \
				+ 16)

#define CONFIG_SYS_MAXARGS		16

#define CONFIG_SYS_MALLOC_LEN		(4 * 1024 * 1024)

#define CONFIG_STACKSIZE		(64 * 1024)

#define CONFIG_BAUDRATE			115200
#define CONFIG_BOOTARGS							\
	"console=ttystm0,115200 earlyprintk consoleblank=0 ignore_loglevel"
#define CONFIG_BOOTCOMMAND						\
	"run bootcmd_romfs"

#define CONFIG_EXTRA_ENV_SETTINGS \
	"bootargs_romfs=uclinux.physaddr=0x08180000 root=/dev/mtdblock0\0" \
	"bootargs_ramfs=root=initrd\0" \
	"bootcmd_romfs=setenv bootargs ${bootargs} ${bootargs_romfs};" \
	"bootm 0x08044000 - 0x08042000\0" \
	"bootcmd_ramfs=setenv bootargs ${bootargs} ${bootargs_ramfs};" \
	"mmc_spi 3:0;" \
	"ext4load mmc 0 0xD0000000 /rootfs.cpio.uboot;" \
	"bootm 0x08044000 0xD0000000 0x08042000\0"

/*
 * Only interrupt autoboot if <space> is pressed. Otherwise, garbage
 * data on the serial line may interrupt the boot sequence.
 */
#define CONFIG_BOOTDELAY		3
#define CONFIG_AUTOBOOT

/*
 * Command line configuration.
 */
#include <config_cmd_default.h>

#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT	       "U-Boot > "
#define CONFIG_AUTO_COMPLETE
#define CONFIG_CMDLINE_EDITING

#define CONFIG_CMD_FLASH
#define CONFIG_CMD_SAVEENV
#define CONFIG_CMD_MEM
#define CONFIG_CMD_MISC
#define CONFIG_CMD_TIMER
#define CONFIG_CMD_FAT
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_EXT4
#define CONFIG_CMD_SPI
#define CONFIG_CMD_MMC
#define CONFIG_CMD_MMC_SPI
#define HAVE_BLOCK_DEVICE


#endif /* __CONFIG_H */