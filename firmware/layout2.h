/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __LAYOUT2_H__
#define __LAYOUT2_H__

#include "layout.h"
#include "types.pb.h"

void layoutDialogSwipe(LayoutDialogIcon icon, const char *btnNo, const char *btnYes, const char *desc, const char *line1, const char *line2, const char *line3, const char *line4, const char *line5, const char *line6);
void layoutProgressSwipe(const char *desc, int permil);

void layoutHome(void);
void layoutConfirmOutput(const CoinType *coin, const TxOutputType *out);
void layoutConfirmTx(const CoinType *coin, uint64_t amount_out, uint64_t amount_fee);
void layoutFeeOverThreshold(const CoinType *coin, uint64_t fee, uint32_t kb);
void layoutSignMessage(const uint8_t *msg, uint32_t len);
void layoutVerifyMessage(const uint8_t *msg, uint32_t len);
void layoutCipherKeyValue(bool encrypt, const char *key);
void layoutEncryptMessage(const uint8_t *msg, uint32_t len, bool signing);
void layoutDecryptMessage(const uint8_t *msg, uint32_t len, const char *address);
void layoutAddress(const char *address);

#endif
