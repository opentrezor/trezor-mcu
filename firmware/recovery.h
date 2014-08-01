/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __RECOVERY_H__
#define __RECOVERY_H__

#include <stdint.h>
#include <stdbool.h>

void recovery_init(uint32_t _word_count, bool passphrase_protection, bool pin_protection, const char *language, const char *label, bool _enforce_wordlist);
void recovery_word(const char *word);
void recovery_abort(void);
const char *recovery_get_fake_word(void);
uint32_t recovery_get_word_pos(void);

#endif
