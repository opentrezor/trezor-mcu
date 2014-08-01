/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __RESET_H__
#define __RESET_H__

#include <stdint.h>
#include <stdbool.h>

void reset_init(bool display_random, uint32_t _strength, bool passphrase_protection, bool pin_protection, const char *language, const char *label);
void reset_entropy(const uint8_t *ext_entropy, uint32_t len);
uint32_t reset_get_int_entropy(uint8_t *entropy);
const char *reset_get_word(void);

#endif
