/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __OLED_H__
#define __OLED_H__

#include <stdint.h>

#include "bitmaps.h"
#include "fonts.h"

#define OLED_WIDTH   128
#define OLED_HEIGHT  64
#define OLED_BUFSIZE (OLED_WIDTH * OLED_HEIGHT / 8)

void oledInit(void);
void oledClear(void);
void oledRefresh(void);

void oledSetDebug(char set);
void oledSetBuffer(uint8_t *buf);
const uint8_t *oledGetBuffer(void);
void oledDrawPixel(int x, int y);
void oledClearPixel(int x, int y);
void oledDrawChar(int x, int y, char c);
void oledDrawString(int x, int y, const char* text);
void oledDrawStringCenter(int y, const char* text);
void oledDrawStringRight(int x, int y, const char* text);
void oledDrawBitmap(int x, int y, const BITMAP *bmp);
void oledInvert(int x1, int y1, int x2, int y2);
void oledBox(int x1, int y1, int x2, int y2, char val);
void oledHLine(int y);
void oledFrame(int x1, int y1, int x2, int y2);
void oledSwipeLeft(void);
void oledSwipeRight(void);

#endif
