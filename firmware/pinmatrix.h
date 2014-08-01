/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __PINMATRIX_H__
#define __PINMATRIX_H__

void pinmatrix_start(const char *text);
void pinmatrix_done(char *pin);
const char *pinmatrix_get(void);

#endif
