/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __STORAGE_H__
#define __STORAGE_H__

#include "types.pb.h"
#include "storage.pb.h"
#include "messages.pb.h"
#include "bip32.h"

void storage_init(void);
void storage_reset_uuid(void);
void storage_reset(void);
void storage_commit(void);
void session_clear(void);

void storage_loadDevice(LoadDevice *msg);

bool storage_getRootNode(HDNode *node);

const char *storage_getLabel(void);
void storage_setLabel(const char *label);

const char *storage_getLanguage(void);
void storage_setLanguage(const char *lang);

void session_cachePassphrase(const char *passphrase);
bool session_isPassphraseCached(void);

bool storage_isPinCorrect(const char *pin);
bool storage_hasPin(void);
void storage_setPin(const char *pin);
void session_cachePin(const char *pin);
bool session_isPinCached(void);
void storage_resetPinFails(void);
void storage_increasePinFails(void);
uint32_t storage_getPinFails(void);

bool storage_isInitialized(void);

extern Storage storage;

extern char storage_uuid_str[25];

#endif
