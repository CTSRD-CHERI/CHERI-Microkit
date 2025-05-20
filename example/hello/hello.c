/*
 * Copyright 2021, Breakaway Consulting Pty. Ltd.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */
#include <stdint.h>
#include <microkit.h>

uintptr_t virt_addr;

void init(void)
{
    volatile uintptr_t *cap = (volatile uintptr_t *) virt_addr;
    microkit_dbg_puts("hello, world\n");
    *cap = (volatile uintptr_t) &init;
    asm volatile("":::"memory");
    virt_addr = *cap;
}

void notified(microkit_channel ch)
{
}
