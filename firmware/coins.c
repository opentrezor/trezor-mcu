/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#include <string.h>
#include "coins.h"

const CoinType coins[COINS_COUNT] = {
	{true, "Bitcoin",  true, "BTC",  true,   0, true,     10000, true,   5},
	{true, "Testnet",  true, "TEST", true, 111, true,  10000000, true, 196},
	{true, "Namecoin", true, "NMC",  true,  52, true,  10000000, true,   5},
	{true, "Litecoin", true, "LTC",  true,  48, true,  10000000, true,   5},
	{true, "Dogecoin", true, "DOGE", true,  30, true, 100000000, true,  22},
};

const CoinType *coinByShortcut(const char *shortcut)
{
	if (!shortcut) return 0;
	int i;
	for (i = 0; i < COINS_COUNT; i++) {
		if (strcmp(shortcut, coins[i].coin_shortcut) == 0) {
			return &(coins[i]);
		}
	}
	return 0;
}

const CoinType *coinByName(const char *name)
{
	if (!name) return 0;
	int i;
	for (i = 0; i < COINS_COUNT; i++) {
		if (strcmp(name, coins[i].coin_name) == 0) {
			return &(coins[i]);
		}
	}
	return 0;
}

const CoinType *coinByAddressType(uint8_t address_type)
{
	int i;
	for (i = 0; i < COINS_COUNT; i++) {
		if (address_type == coins[i].address_type) {
			return &(coins[i]);
		}
	}
	return 0;
}
