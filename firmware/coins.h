/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __COINS_H__
#define __COINS_H__

#include "types.pb.h"

#define COINS_COUNT 5

extern const CoinType coins[COINS_COUNT];

const CoinType *coinByShortcut(const char *shortcut);
const CoinType *coinByName(const char *name);
const CoinType *coinByAddressType(uint8_t address_type);

#endif
