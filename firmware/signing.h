/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __SIGNING_H__
#define __SIGNING_H__

#include <stdint.h>
#include <stdbool.h>
#include "bip32.h"
#include "types.pb.h"

void signing_init(uint32_t _inputs_count, uint32_t _outputs_count, const CoinType *_coin, HDNode *_root);
void signing_abort(void);
void signing_txack(TransactionType *tx);

#endif
