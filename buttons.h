/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __BUTTONS_H__
#define __BUTTONS_H__

#include <libopencm3/stm32/gpio.h>

struct buttonState {
	volatile bool YesUp;
	volatile int YesDown;
	volatile bool NoUp;
	volatile int NoDown;
};

extern struct buttonState button;

void buttonUpdate(void);

#define BTN_PORT	GPIOC
#define BTN_PIN_YES	GPIO2
#define BTN_PIN_NO	GPIO5

#endif
