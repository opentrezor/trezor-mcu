/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __RNG_H__
#define __RNG_H__

#include <stdint.h>
#include <stdlib.h>

uint32_t random32(void);
void random_buffer(uint8_t *buf, size_t len);

#endif
