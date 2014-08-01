/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __PROTECT_H__
#define __PROTECT_H__

#include <stdbool.h>
#include "types.pb.h"

bool protectButton(ButtonRequestType type, bool confirm_only);
bool protectPin(bool use_cached);
bool protectChangePin(void);
bool protectPassphrase(void);

extern bool protectAbortedByInitialize;

#endif
