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

M2C_UNK func_80016314(s32);                         /* extern */
s32 func_80026A5C(void *, M2C_UNK);                 /* extern */
extern void *D_80109BB0;

void func_80026D40(void *arg0, M2C_UNK arg1) {
    M2C_UNK (*temp_v0_2)();
    M2C_UNK (*temp_v0_3)(void *);
    s16 temp_v1;
    s16 temp_v1_2;
    s16 var_s1;
    unsigned int var_s1_2;
    s32 temp_a0;
    s32 var_v1;
    void *temp_s2;
    
    void *temp_s0;
    void *temp_v0;
    void *var_a0;

    var_a0 = arg0;
    temp_s2 = var_a0;
    temp_v0 = M2C_FIELD(D_80109BB0, void **, 0x10);
    var_s1 = 0;
    if (temp_v0 != NULL) {
        temp_v0_2 = M2C_FIELD(temp_v0, M2C_UNK (**)(), 0xC);
        if (temp_v0_2 != NULL) {
            temp_v0_2();
        }
        var_a0 = D_80109BB0;
        if (M2C_FIELD(M2C_FIELD(var_a0, void **, 0x10), u8 *, 5) != 0) {
            do {
                temp_s0 = M2C_FIELD(M2C_FIELD(var_a0, void **, 0x10), s32 *, 0) + (var_s1 * 0x28);
                temp_a0 = M2C_FIELD(temp_s0, s32 *, 8);
                if (temp_a0 != 0) {
                    func_80016314(temp_a0);
                    M2C_FIELD(temp_s0, s32 *, 8) = 0;
                }
                var_a0 = D_80109BB0;
                temp_v1 = var_s1 + 1;
                var_s1 = temp_v1;
            } while (temp_v1 < (s32) M2C_FIELD(M2C_FIELD(var_a0, void **, 0x10), u8 *, 5));
        }
    }
    M2C_FIELD(D_80109BB0, void **, 0x10) = temp_s2;
    if (temp_s2 != NULL) {
        temp_v0_3 = M2C_FIELD(temp_s2, M2C_UNK (**)(void *), 8);
        if (temp_v0_3 != NULL) {
            temp_v0_3(var_a0);
        }
        var_s1_2 = 0;
        if (M2C_FIELD(temp_s2, u8 *, 5) != 0) {
            var_v1 = 0 << 0x10;
            __repair_rows: {
                temp_s0 = M2C_FIELD(temp_s2, s32 *, 0) + ((var_v1 >> 0x10) * 0x28);
                temp_v1_2 = var_s1_2 + 1;
                var_s1_2 = temp_v1_2;
                M2C_FIELD(temp_s0, s32 *, 8) = func_80026A5C(temp_s0, arg1);
                var_v1 = var_s1_2 << 0x10;
            }
if (temp_v1_2 < (s32) M2C_FIELD(temp_s2, u8 *, 5)) goto __repair_rows;
        }
    }
}
