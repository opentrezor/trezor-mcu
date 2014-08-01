/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "trezor.h"

#if DEBUG_LOG

void debugLog(int level, const char *bucket, const char *text);

#else

#define debugLog(L, B, T) do{}while(0)

#endif

#endif
