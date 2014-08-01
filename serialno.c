/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#include <stdint.h>
#include <string.h>

#include <libopencm3/stm32/desig.h>

#include "serialno.h"
#include "util.h"
#include "sha2.h"

void fill_serialno_fixed(char *s)
{
	uint8_t uuid[32];
	desig_get_unique_id((uint32_t *)uuid);
	sha256_Raw(uuid, 12, uuid);
	sha256_Raw(uuid, 32, uuid);
	data2hex(uuid, 12, s);
}
