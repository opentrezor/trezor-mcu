/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __TREZOR_H__
#define __TREZOR_H__

#define VERSION_MAJOR 1
#define VERSION_MINOR 2
#define VERSION_PATCH 1

#define STR(X) #X
#define VERSTR(X) STR(X)

#ifndef DEBUG_LINK
#define DEBUG_LINK 0
#endif

#ifndef DEBUG_LOG
#define DEBUG_LOG 0
#endif

#endif
