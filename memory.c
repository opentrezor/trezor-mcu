/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#include <libopencm3/stm32/flash.h>
#include <stdint.h>
#include "memory.h"
#include "sha2.h"

#define OPTION_BYTES_1 ((uint64_t *)0x1FFFC000)
#define OPTION_BYTES_2 ((uint64_t *)0x1FFFC008)

void memory_protect(void)
{
	//                     set RDP level 2                   WRP for sectors 0 and 1
	if ((((*OPTION_BYTES_1) & 0xFFFF) == 0xCCFF) && (((*OPTION_BYTES_2) & 0xFFFF) == 0xFFFC)) {
		return; // already set up correctly - bail out
	}
	flash_unlock_option_bytes();
	//                                 WRP +    RDP
	flash_program_option_bytes( 0xFFFC0000 + 0xCCFF);
	flash_lock_option_bytes();
}

int memory_bootloader_hash(uint8_t *hash)
{
	sha256_Raw((const uint8_t *)FLASH_BOOT_START, FLASH_BOOT_LEN, hash);
	sha256_Raw(hash, 32, hash);
	return 32;
}
