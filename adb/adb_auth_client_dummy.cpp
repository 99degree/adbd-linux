/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define TRACE_TAG AUTH

#include "sysdeps.h"
#include "adb_auth.h"

#include <resolv.h>
#include <stdio.h>
#include <string.h>

#include "cutils/list.h"
#include "cutils/sockets.h"

#include "adb.h"
#include "fdevent.h"
#include "transport.h"

#if 0
static fdevent listener_fde;
static fdevent framework_fde;
static int framework_fd = -1;

static void usb_disconnected(void* unused, atransport* t);
static struct adisconnect usb_disconnect = { usb_disconnected, nullptr};
static atransport* usb_transport;
static bool needs_retry = false;
#endif

int adb_auth_generate_token(void *token, size_t token_size)
{
    FILE *f;
    int ret;

    f = fopen("/dev/urandom", "re");
    if (!f)
        return 0;

    ret = fread(token, token_size, 1, f);

    fclose(f);
    return ret * token_size;
}

int __attribute__((weak)) adb_auth_verify(uint8_t* token, size_t token_size, uint8_t* sig, int siglen)
{
    int ret = 0;
    return ret;
}

void __attribute__((weak)) adb_auth_confirm_key(unsigned char *key, size_t len, atransport *t)
{
}

void __attribute__((weak)) adbd_cloexec_auth_socket() {
}

void __attribute__((weak)) adbd_auth_init(void) {
}
