/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#include <string.h>

#include "pinmatrix.h"
#include "oled.h"
#include "rng.h"

static char pinmatrix_perm[10] = "XXXXXXXXX";

void pinmatrix_draw(const char *text)
{
	const BITMAP *bmp_digits[10] = {
		&bmp_digit0, &bmp_digit1, &bmp_digit2, &bmp_digit3, &bmp_digit4,
		&bmp_digit5, &bmp_digit6, &bmp_digit7, &bmp_digit8, &bmp_digit9,
	};
	oledSwipeLeft();
	const int w = bmp_digit0.width, h = bmp_digit0.height, pad = 2;
	int i, j, k;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			// use (2 - j) instead of j to achieve 789456123 layout
			k = pinmatrix_perm[i + (2 - j) * 3] - '0';
			if (text) {
				oledDrawStringCenter(0, text);
			}
			oledDrawBitmap((OLED_WIDTH - 3 * w - 2 * pad) / 2 + i * (w + pad), OLED_HEIGHT - 3 * h - 2 * pad + j * (h + pad), bmp_digits[k]);
		}
	}
	oledRefresh();
}

void pinmatrix_start(const char *text)
{
	int i, j, k;
	char t;

	for (i = 0; i < 9; i++) {
		pinmatrix_perm[i] = '1' + i;
	}
	pinmatrix_perm[9] = 0;
	for (i = 0; i < 10000; i++) {
		j = random32() % 9;
		k = random32() % 9;
		t = pinmatrix_perm[j];
		pinmatrix_perm[j] = pinmatrix_perm[k];
		pinmatrix_perm[k] = t;
	}
	pinmatrix_draw(text);
}

void pinmatrix_done(char *pin)
{
	int k, i = 0;
	while (pin && pin[i]) {
		k = pin[i] - '1';
		if (k >= 0 && k <= 8) {
			pin[i] = pinmatrix_perm[k];
		} else {
			pin[i] = 'X';
		}
		i++;
	}
	memset(pinmatrix_perm, 'X', sizeof(pinmatrix_perm));
}

const char *pinmatrix_get(void)
{
	return pinmatrix_perm;
}
