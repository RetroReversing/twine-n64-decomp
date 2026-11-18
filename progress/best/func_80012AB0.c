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

s32 func_800103B0();
s32 func_80010A2C();
s32 func_8001226C();
s32 func_80012428();
s32 func_80012F50();
extern u16 D_800BFC32;
extern s32 D_800E0978;
extern u8 D_80103042;
extern char D_80107B68[];
extern char D_80108412[];
extern char D_8010A3C5[];

u16 func_80012AB0(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    D_800BFC32 = 3;
    D_800E0978 = temp_a0;
    if (!(func_80012F50(temp_a0) & 0xFFFF)) {
        if (*(D_80107B68 + (D_800E0978 * 0x18)) != 0) {
            if (func_8001226C(D_800E0978) == 0) {
                D_800BFC32 = 0x81;
                return 0x81U;
            }
            D_80103042 = *(D_80108412 + (D_800E0978 << 5));
            func_800103B0(D_8010A3C5, &D_80103042, 4);
            goto block_5;
        }
block_5:
        if (func_80010A2C() & 0xFFFF) {
            D_800BFC32 = 0x30;
            return 0x30U;
        }
        if (!(func_80012428() & 0xFFFF) && !(func_80012F50() & 0xFFFF)) {
            D_800BFC32 = 3;
            return 3U;
        }
        goto block_10;
    }
block_10:
    return D_800BFC32;
}
