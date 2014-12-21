/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __LAYOUT_H__
#define __LAYOUT_H__

#include <stdlib.h>
#include <stdbool.h>

typedef enum {
	DIALOG_NOICON = 0,
	DIALOG_ICON_ERROR,
	DIALOG_ICON_INFO,
	DIALOG_ICON_QUESTION,
	DIALOG_ICON_WARNING,
	DIALOG_ICON_OK,
} LayoutDialogIcon;

void layoutDialog(LayoutDialogIcon icon, const char *btnNo, const char *btnYes, const char *desc, const char *line1, const char *line2, const char *line3, const char *line4, const char *line5, const char *line6);
void layoutProgressUpdate(bool refresh);
void layoutProgress(const char *desc, int permil);

#endif
