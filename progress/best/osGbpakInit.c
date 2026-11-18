/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 __osContRamRead();
s32 __osContRamWrite();
s32 __osPfsGetStatus();
s32 osCreateMesgQueue();
s32 osRecvMesg();
s32 osSetTimer();
extern char D_8010301C[];
extern char D_80109E70[];
extern char D_80112E48[];

s32 osGbpakInit(s32 arg0, void *arg1, s32 arg2) {
    s32 sp20;
    u8 sp3F;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    char *var_v1;
    char *var_v1_2;

    var_v0_2 = 0x1F;
    var_v1 = &sp3F;
    M2C_FIELD(arg1, s32 *, 0) = 0;
    do {
        *(u8 *)var_v1 = 0xFE;
        var_v0_2 -= 1;
        var_v1 -= 1;
    } while (var_v0_2 >= 0);
    var_v0 = __osContRamWrite(arg0, arg2, 0x400, &sp20, 0);
    if (var_v0 == 2) {
        var_v0 = __osContRamWrite(arg0, arg2, 0x400, &sp20, 0);
    }
    if (var_v0 == 0) {
        var_v0 = __osContRamRead(arg0, arg2, 0x400, &sp20);
        if (var_v0 == 2) {
            var_v0 = 4;
        }
        if (var_v0 == 0) {
            if (sp3F != 0xFE) {
                var_v0_3 = 0x1F;
                var_v1_2 = &sp3F;
                do {
                    *(u8 *)var_v1_2 = 0x84;
                    var_v0_3 -= 1;
                    var_v1_2 -= 1;
                } while (var_v0_3 >= 0);
                var_v0 = __osContRamWrite(arg0, arg2, 0x400, &sp20, 0);
                if (var_v0 == 2) {
                    var_v0 = 4;
                }
                if (var_v0 == 0) {
                    var_v0 = __osContRamRead(arg0, arg2, 0x400, &sp20);
                    if (var_v0 == 2) {
                        var_v0 = 4;
                    }
                    if (var_v0 == 0) {
                        if (sp3F != 0x84) {
                            goto block_18;
                        }
                        var_v0 = __osPfsGetStatus(arg0, arg2);
                        if (var_v0 == 0) {
                            osCreateMesgQueue(D_80112E48, D_8010301C, 1);
                            osSetTimer(D_80109E70, 0, 0, D_80112E48, D_8010301C);
                            osRecvMesg(D_80112E48, 0, 1);
                            var_v0 = 0;
                            M2C_FIELD(arg1, s32 *, 0) = 0x10;
                            M2C_FIELD(arg1, u8 *, 0x65) = 0x84;
                            M2C_FIELD(arg1, u8 *, 0x64) = 0xFF;
                            M2C_FIELD(arg1, s32 *, 4) = arg0;
                            M2C_FIELD(arg1, s32 *, 8) = arg2;
                            M2C_FIELD(arg1, s32 *, 0x4C) = 0xFF;
                            M2C_FIELD(arg1, s32 *, 0x50) = 0xFF;
                        }
                        /* Duplicate return node #21. Try simplifying control flow for better match */
                        return var_v0;
                    }
                    /* Duplicate return node #21. Try simplifying control flow for better match */
                    return var_v0;
                }
                /* Duplicate return node #21. Try simplifying control flow for better match */
                return var_v0;
            }
block_18:
            return 0xB;
        }
        /* Duplicate return node #21. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
