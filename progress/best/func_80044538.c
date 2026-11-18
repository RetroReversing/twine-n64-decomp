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

s32 func_80084048();
extern char D_800C0784[];
extern char D_800C0788[];
extern char D_800C078C[];

void func_80044538(s32 arg0) {
    s32 temp_s0;
    s32 temp_v1;
    s32 var_a2;
    u32 var_a1;
    void *temp_a3;
    void *var_v1;

    temp_v1 = arg0 * 0x10;
    var_a2 = 1;
    if (*(D_800C0784 + temp_v1) != 0) {
        temp_a3 = *(D_800C0788 + temp_v1);
        var_a1 = 0;
        if (*(D_800C078C + temp_v1) != 0) {
            var_v1 = temp_a3;
            do {
                if (M2C_FIELD(var_v1, s32 *, 0) != 0) {
                    if ((u8) M2C_FIELD(var_v1, u8 *, 0x46) >= 5U) {
                        M2C_FIELD(var_v1, u8 *, 0x46) = 4U;
                    }
                    var_a2 = 0;
                }
                var_a1 += 1;
                var_v1 += 0x4C;
            } while (var_a1 < (u32) *(D_800C078C + temp_v1));
        }
        temp_s0 = arg0 * 0x10;
        if (var_a2 != 0) {
            func_80084048(*(D_800C0788 + temp_s0), 0xA, var_a2, temp_a3);
            func_80084048(M2C_FIELD(M2C_FIELD(*(D_800C0784 + temp_s0), void **, 0x10), s32 *, 4), 0x1B);
            func_80084048(M2C_FIELD(M2C_FIELD(*(D_800C0784 + temp_s0), void **, 0x18), s32 *, 8), 0x1A);
            func_80084048(M2C_FIELD(*(D_800C0784 + temp_s0), s32 *, 0x10), 0x18);
            func_80084048(M2C_FIELD(*(D_800C0784 + temp_s0), s32 *, 0x18), 0x1A);
            *(D_800C0784 + temp_s0) = 0;
        }
    }
}
