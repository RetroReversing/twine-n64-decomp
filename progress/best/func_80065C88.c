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

s32 func_800643D8();
extern s32 D_801002B8;
extern s8 D_8010A4C2;
extern void *D_8010A500;
extern char D_8011508B[];

void func_80065C88(void) {
    s32 var_s2;
    s32 var_s4;
    void **var_s3;
    void *temp_s0;
    void *temp_s1;

    var_s2 = 0;
    if (D_801002B8 > 0) {
        var_s4 = 0;
        var_s3 = &D_8010A500;
        do {
            temp_s0 = *var_s3;
            if (temp_s0 != NULL) {
                temp_s1 = M2C_FIELD(temp_s0, void **, 0x6C);
                if (M2C_FIELD(temp_s0, s16 *, 0x7C) == 5) {
                    *(D_8011508B + var_s4) = 1;
                }
                var_s4 += 0xA0;
                if (M2C_FIELD(temp_s0, s16 *, 0x7C) == 7) {
                    func_800643D8(M2C_FIELD(temp_s1, s32 *, 0xA8));
                    M2C_FIELD(temp_s1, s16 *, 0x134) = (s16) (s8) M2C_FIELD(M2C_FIELD(temp_s0, void **, 0x68), u8 *, 0xE);
                    M2C_FIELD(M2C_FIELD(temp_s0, void **, 0x68), s8 *, 0xF) = 0;
                    D_8010A4C2 &= 0xDE;
                }
            } else {
                var_s4 += 0xA0;
            }
            var_s2 += 1;
            var_s3 += 1;
        } while (var_s2 < D_801002B8);
    }
}
