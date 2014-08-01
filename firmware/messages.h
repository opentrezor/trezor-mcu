/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#ifndef __MESSAGES_H__
#define __MESSAGES_H__

#include <stdint.h>
#include <stdbool.h>
#include "trezor.h"

#define MSG_IN_SIZE (9*1024)

#define MSG_OUT_SIZE (9*1024)

#define msg_read(buf, len) msg_read_common('n', (buf), (len))
#define msg_write(id, ptr) msg_write_common('n', (id), (ptr))
uint8_t *msg_out_data(void);

#if DEBUG_LINK

#define MSG_DEBUG_OUT_SIZE (4*1024)

#define msg_debug_read(buf, len) msg_read_common('d', (buf), (len))
#define msg_debug_write(id, ptr) msg_write_common('d', (id), (ptr))
uint8_t *msg_debug_out_data(void);

#endif

void msg_read_common(char type, uint8_t *buf, int len);
bool msg_write_common(char type, uint16_t msg_id, const void *msg_ptr);

void msg_read_tiny(uint8_t *buf, int len);
void msg_debug_read_tiny(uint8_t *buf, int len);
extern uint8_t msg_tiny[64];
extern uint16_t msg_tiny_id;

#endif
