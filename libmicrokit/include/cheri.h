/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2019 Hesham Almatary
 *
 * This software was developed by SRI International and the University of
 * Cambridge Computer Laboratory (Department of Computer Science and
 * Technology) under DARPA contract HR0011-18-C-0016 ("ECATS"), as part of the
 * DARPA SSITH research programme.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/**
 * @file
 *
 * @brief CHERI-RISC-V Utility
 */

#pragma once

//#include <stdbool.h>
//#include <stddef.h>
//#include <stdint.h>
#if defined(__CHERI_CAP_PERMISSION_CAPABILITY__)
#define __builtin_cheri_seal(x, y) ((void *) 0)
#define __builtin_cheri_unseal(x, y) ((void *) 0)

#define __CHERI_CAP_PERMISSION_PERMIT_EL__ (1 << 2) /* EL bit */
#define __CHERI_CAP_PERMISSION_PERMIT_SL__ (1 << 3) /* SL bit */
#define __CHERI_CAP_PERMISSION_GLOBAL__ (1 << 4) /* CL bit */
#define __CHERI_CAP_PERMISSION_PERMIT_EXECUTE__ __CHERI_CAP_PERMISSION_EXECUTE__
#define __CHERI_CAP_PERMISSION_PERMIT_LOAD_CAPABILITY__ __CHERI_CAP_PERMISSION_READ__
#define __CHERI_CAP_PERMISSION_PERMIT_LOAD__ __CHERI_CAP_PERMISSION_READ__
#define __CHERI_CAP_PERMISSION_PERMIT_STORE__ __CHERI_CAP_PERMISSION_WRITE__
#define __CHERI_CAP_PERMISSION_PERMIT_STORE_CAPABILITY__ __CHERI_CAP_PERMISSION_WRITE__
#endif

#ifndef size_t
typedef __SIZE_TYPE__ size_t;
typedef __PTRADDR_TYPE__ ptraddr_t;
typedef __uintcap_t uintptr_t;

#if __riscv_xlen == 32
typedef unsigned long long uint64_t;
typedef long long int64_t;
#else
typedef unsigned long uint64_t;
typedef long int64_t;
#endif
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

typedef int int32_t;
typedef short int16_t;
typedef signed char int8_t;
#endif

#define true 1
#define false 0

void * cheri_seal_cap( void * unsealed_cap,
                       size_t otype );
void * cheri_unseal_cap( void * unsealed_cap );
void * cheri_build_data_cap( ptraddr_t address,
                             size_t size,
                             size_t perms );
void * cheri_build_code_cap( ptraddr_t address,
                             size_t size,
                             size_t perms );
void * cheri_build_code_cap_unbounded( ptraddr_t address,
                                       size_t perms );
void * cheri_derive_data_cap( void * src,
                              ptraddr_t address,
                              size_t size,
                              size_t perms );
void * cheri_derive_code_cap( void * src,
                              ptraddr_t address,
                              size_t size,
                              size_t perms );
void cheri_print_cap(const void * cap );
void cheri_print_scrs( void );

void _start_purecap( void *__capability code_cap, void *__capability data_cap);
