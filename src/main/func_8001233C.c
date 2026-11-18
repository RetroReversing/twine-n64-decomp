#include "common_local_source_25769804137.h"

/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80010958();
s32 func_800109CC();
s32 func_80010B60();
s32 func_80011800();
extern u16 D_800BFC32;
extern char D_800E0790[];
extern s16 D_800E093A;
extern s32 D_800E0960;
extern u16 *D_800E0964;
extern s32 D_800E0978;
extern s32 D_801032A8;

u16 func_8001233C(void) {
    D_800BFC32 = 0;
    func_80011800(9, (D_800E093A * 0x68) + D_800E0790, D_800E0978, 0, 0, D_800E0960, D_800E0964, 0);
    if (func_800109CC() != 0) {
        return func_80010B60(D_801032A8) & 0xFFFF;
    }
    if ((func_80010958((unsigned)D_800E0964 + 2, D_800E0960 - 2) & 0xFFFF) != *D_800E0964) {
        D_801032A8 = -1;
        D_800BFC32 = 0x24;
    }
    return D_800BFC32;
}
