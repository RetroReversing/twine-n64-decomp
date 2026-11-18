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

s32 func_80008434();
s32 func_800084C0();
s32 func_80008598();
s32 func_80008660();
s32 func_80008750();
extern u32 D_800B1D84;
extern u32 D_80107EA0;
extern s32 D_8010D538;
extern void *D_80117728;

void func_80009DCC(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_s2;
    u32 temp_v0;
    u8 temp_a1;

    temp_s2 = M2C_FIELD(arg1, s32 *, 0x70);
    if ((temp_s2 != 0) && ((u32) D_80107EA0 < (u32) D_800B1D84)) {
        temp_a1 = M2C_FIELD(arg1, u8 *, 0x7E);
        if (temp_a1 != 0xB) {
            func_80008750(arg2, temp_a1, 0);
            temp_v0 = D_80107EA0 + 1;
            D_80107EA0 = temp_v0;
            D_8010D538 = M2C_FIELD(D_80117728, s32 *, 0x74C) + (temp_v0 << 6);
            if (M2C_FIELD(arg1, s32 *, 0x58) & 0x40000) {
                func_80008660(arg1);
            } else if ((arg4 << 0x18) != 0) {
                do { func_800084C0(arg1, arg0); } while (0);
            } else {
                func_80008434(arg1, M2C_FIELD(arg1, s32 *, 0x54));
            }
            func_80008598(temp_s2);
        }
    }
}
