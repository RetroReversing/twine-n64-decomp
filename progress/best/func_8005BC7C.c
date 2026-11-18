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

s32 func_8000A894();
s32 func_8005B5A8();
extern s32 D_800C4440;
extern s32 D_800C4444;
extern void *D_80108788;

void func_8005BC7C(void) {
    char *var_s0;
    char *var_s1;
    s32 var_a2;
    s32 var_s2;
    s32 var_v0;
    u32 temp_a1;

    var_a2 = 0;
    if (D_80108788 != NULL) {
        var_v0 = 0;
        if (M2C_FIELD(D_80108788, void **, 0x70) != NULL) {
            var_s2 = 0;
            var_s1 = &D_800C4444;
            var_s0 = &D_800C4440;
            do {
                temp_a1 = M2C_FIELD(M2C_FIELD(D_80108788, void **, 0x70), u32 *, 0x30);
                if ((((temp_a1 >> 4) & 0xFFFF) == *(s32 *)var_s0) && ((temp_a1 >> 0x14) == *(s32 *)var_s1) && (M2C_FIELD(D_80108788, u16 *, 0x78) == 0x12) && (M2C_FIELD(D_80108788, s16 *, 0x7C) == 0)) {
                    func_8000A894(0x12D, temp_a1, var_a2);
                    var_a2 = 1;
                    M2C_FIELD(D_80108788, s32 *, 0x60) |= 0x08000000;
                }
                var_s1 += 4;
                var_s2 += 1;
                var_s0 += 4;
            } while (var_s2 == 0);
            goto block_9;
        }
    } else {
block_9:
        var_v0 = var_a2;
    }
    if (var_v0 == 0) {
        func_8005B5A8();
    }
}
