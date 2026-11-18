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

s32 func_8005B5A8();
extern s32 D_800C4420;
extern s32 D_800C4424;
extern void *D_80108788;

void func_8005B880(u32 arg0, void *arg1, s32 *arg2, s32 *arg3) {
    char *var_a2;
    char *var_a3;
    s32 var_t0;
    s32 var_t1;
    s32 var_v0;
    u16 temp_v1;
    u32 var_a0;
    void *var_a1;

    var_a0 = arg0;
    var_a1 = arg1;
    var_a2 = arg2;
    var_a3 = arg3;
    var_t1 = 0;
    if ((D_80108788 != NULL) && (var_a1 = D_80108788, temp_v1 = M2C_FIELD(var_a1, u16 *, 0x78), (((s32) temp_v1 < 0x13) != 0))) {
        var_v0 = 0;
        if ((s32) temp_v1 >= 0x11) {
            var_v0 = 0;
            if (M2C_FIELD(var_a1, s16 *, 0x7A) == 0) {
                var_t0 = 0;
                var_a3 = &D_800C4424;
                var_a2 = &D_800C4420;
                do {
                    var_a0 = M2C_FIELD(M2C_FIELD(var_a1, void **, 0x70), u32 *, 0x30);
                    if ((((var_a0 >> 4) & 0xFFFF) == *(s32 *)var_a2) && ((var_a0 >> 0x14) == *(s32 *)var_a3)) {
                        var_t1 = 1;
                        if (M2C_FIELD(M2C_FIELD(var_a1, void **, 0x6C), s32 *, 0x2C) & 0x08000000) {
                            M2C_FIELD(var_a1, s32 *, 0x60) |= 0x08000000;
                        }
                    }
                    var_a3 += 4;
                    var_t0 += 1;
                    var_a2 += 4;
                } while (var_t0 == 0);
                goto block_10;
            }
        }
    } else {
block_10:
        var_v0 = var_t1;
    }
    if (var_v0 == 0) {
        func_8005B5A8(var_a0, var_a1, var_a2);
    }
}
