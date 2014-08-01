/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __UTIL_H_
#define __UTIL_H_

#include <stdint.h>

inline void delay(uint32_t wait);

// converts uint32 to hexa (8 digits)
void uint32hex(uint32_t num, char *str);

// converts data to hexa
void data2hex(const void *data, uint32_t len, char *str);

// read protobuf integer and advance pointer
uint32_t readprotobufint(uint8_t **ptr);

// halt execution (or do an endless loop)
void __attribute__((noreturn)) system_halt(void);
// reset system
void __attribute__((noreturn)) system_reset(void);

#endif
