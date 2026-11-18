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

M2C_UNK func_800A0170(void *, s32);                 /* extern */
extern void *D_800E4254;
extern void *D_800E4258;
extern s32 D_800E425C;
extern s32 D_800E4260;
extern void *D_800E4264;
extern void *(*D_8010017C)(s32, M2C_UNK);

void func_80089E64(s32 arg0) {
    s32 temp_s1;
    s32 temp_s3;
    s32 var_a1;
    s32 var_a2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *var_a3;
    void *var_v1;

    temp_s3 = arg0 & 0xFFFF;
    temp_s1 = temp_s3 * 0x600;
    temp_v0 = D_8010017C(temp_s1, 0);
    D_800E4254 = temp_v0;
    func_800A0170(temp_v0, temp_s1);
    temp_v0_2 = D_8010017C(temp_s3 * 0x18, 0);
    var_a2 = 1;
    D_800E4258 = temp_v0_2;
    D_800E425C = 0;
    D_800E4260 = 0;
    D_800E4264 = temp_v0_2;
    M2C_FIELD(temp_v0_2, s32 *, 4) = 0;
    M2C_FIELD(temp_v0_2, void **, 0x14) = (void *) D_800E4254;
    if (temp_s3 > 1) {
        var_a3 = D_800E4254 + 0x600;
        var_a1 = 0;
        var_v1 = temp_v0_2 + 0x18;
        __repair_rows: {
            M2C_FIELD(var_v1, void **, 0x14) = var_a3;
            var_a3 += 0x600;
            temp_v0_3 = temp_v0_2 + var_a1;
            var_a1 += 0x18;
            M2C_FIELD(var_v1, void **, -0x18) = var_v1;
            M2C_FIELD(var_v1, void **, 4) = temp_v0_3;
            var_a2 += 1;
            var_v1 += 0x18;
        }
if (var_a2 < temp_s3) goto __repair_rows;
    }
    M2C_FIELD(((var_a2 * 0x18) + D_800E4258), s32 *, -0x18) = 0;
}
