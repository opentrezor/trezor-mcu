/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __BOOTLOADER_H__
#define __BOOTLOADER_H__

#define VERSION_MAJOR 1
#define VERSION_MINOR 2
#define VERSION_PATCH 5

#define STR(X) #X
#define VERSTR(X) STR(X)

#define VERSION_MAJOR_CHAR "\x01"
#define VERSION_MINOR_CHAR "\x02"
#define VERSION_PATCH_CHAR "\x05"

#include "memory.h"

#endif
