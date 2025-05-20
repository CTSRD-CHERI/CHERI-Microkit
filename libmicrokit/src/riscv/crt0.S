/*
 * Copyright 2024, UNSW
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

.extern main
.extern __global_pointer$

.section ".text.start"
.global _start;
.type _start, %function;
_start:
.option push
.option norelax
1:
#if defined(__CHERI_PURE_CAPABILITY__)
/* ca0 and ca1 should hold code and data caps */
#if defined(__CHERI_CAP_PERMISSION_CAPABILITY__)
   call _start_purecap
   llc cgp, __global_pointer$
   call main
#else
   cllc  ct0, _start_purecap
   jalr.cap        cra, ct0

   cllc cgp, __global_pointer$

   cllc ct0, main
   jalr.cap        cra, ct0
#endif

#else
1:  auipc gp, %pcrel_hi(__global_pointer$)
    addi  gp, gp, %pcrel_lo(1b)
.option pop
    j main
#endif
