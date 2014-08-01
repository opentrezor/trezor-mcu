/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#include "trezor.h"
#include "debug.h"
#include "oled.h"

#if DEBUG_LOG

void oledDebug(const char *line)
{
	int i;
	static const char *lines[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	static char id = 3;
	for (i = 0; i < 7; i++) {
		lines[i] = lines[i + 1];
	}
	lines[7] = line;
	oledClear();
	for (i = 0; i < 8; i++) {
		if (lines[i]) {
			oledDrawChar(0, i * 8, '0' + (id + i) % 10);
			oledDrawString(8, i * 8, lines[i]);
		}
	}
	oledRefresh();
	id = (id + 1) % 10;
}

void debugLog(int level, const char *bucket, const char *text)
{
	(void)level;
	(void)bucket;
	oledDebug(text);
}

#endif
