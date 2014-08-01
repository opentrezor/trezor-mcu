/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#include <libopencm3/cm3/common.h>
#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/stm32/f2/rng.h>

#include "rng.h"

uint32_t random32(void)
{
	static uint32_t last = 0, new = 0;
	while (new == last) {
		if (((RNG_SR & (RNG_SR_SEIS | RNG_SR_CEIS)) == 0) && ((RNG_SR & RNG_SR_DRDY) > 0)) {
			new = RNG_DR;
		}
	}
	last = new;
	return new;
}

void random_buffer(uint8_t *buf, size_t len)
{
	size_t i;
	uint32_t r = 0;
	for (i = 0; i < len; i++) {
		if (i % 4 == 0) {
			r = random32();
		}
		buf[i] = (r >> ((i % 4) * 8)) & 0xFF;
	}
}
