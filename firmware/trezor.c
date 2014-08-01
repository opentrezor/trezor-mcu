/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#include "trezor.h"
#include "oled.h"
#include "bitmaps.h"
#include "util.h"
#include "usb.h"
#include "setup.h"
#include "storage.h"
#include "layout.h"
#include "layout2.h"
#include "rng.h"

uint32_t __stack_chk_guard;

void __attribute__((noreturn)) __stack_chk_fail(void)
{
	layoutDialog(DIALOG_ICON_ERROR, NULL, NULL, NULL, "Stack smashing", "detected.", NULL, "Please unplug", "the device.", NULL);
	for (;;) {} // loop forever
}

int main(void)
{
	__stack_chk_guard = random32();
#ifndef APPVER
	setup();
	oledInit();
#else
	setupApp();
#endif
#if DEBUG_LINK
	oledSetDebug(1);
	storage_reset(); // wipe storage if debug link
	storage_reset_uuid();
	storage_commit();
#endif

	oledDrawBitmap(40, 0, &bmp_logo64);
	oledRefresh();

	storage_init();
	layoutHome();
	usbInit();
	for (;;) {
		usbPoll();
	}

	return 0;
}
