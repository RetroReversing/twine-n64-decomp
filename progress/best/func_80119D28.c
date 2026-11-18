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

f32 func_80045E34(void *, void *);                  /* extern */
extern void *D_8010A500;

void func_80119D28(void *arg0) {
    f32 temp_fv1;
    u16 temp_v1;
    u32 var_s2;
    void **var_s1;
    void *temp_a0;
    void *temp_a1;
    void *temp_v0;

    var_s2 = 0;
    var_s1 = &D_8010A500;
    M2C_FIELD(arg0, u16 *, 0x7C) = (u16) (M2C_FIELD(arg0, u16 *, 0x7C) + 1);
    do {
        temp_a0 = *var_s1;
        if (temp_a0 != NULL) {
            temp_v1 = M2C_FIELD(temp_a0, u16 *, 0x7A);
            if (((u32) (temp_v1 - 2) >= 2U) && ((s16) temp_v1 != 6) && (M2C_FIELD(temp_a0, s32 *, 0x20) == M2C_FIELD(arg0, s32 *, 0x20))) {
                temp_v0 = M2C_FIELD(*var_s1, void **, 0x6C);
                temp_fv1 = func_80045E34(temp_a0 + 0x24, arg0 + 0x24);
                if (temp_v0 != NULL) {
                    temp_a1 = M2C_FIELD(temp_v0, void **, 0xB4);
                    if ((temp_a1 != NULL) && (temp_fv1 < M2C_FIELD(arg0, f32 *, 0x54)) && ((s16) M2C_FIELD(arg0, u16 *, 0x7C) == ((M2C_FIELD(arg0, u16 *, 0x7C) / 150) * 0x96))) {
                        M2C_FIELD(temp_a1, u16 *, 0xC) = (u16) (M2C_FIELD(temp_a1, u16 *, 0xC) + 1);
                    }
                }
            }
        }/*__repair_loop_weight*/do {
        var_s2 += 1;} while (0);
        var_s1 += 4;
    } while (var_s2 < 4U);
}
