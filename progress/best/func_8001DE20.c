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

s32 func_80025D84();
s32 func_80025E9C();
s32 func_80026004();
void *func_8002638C();
s8 func_800263B8();
s32 func_80087100();
extern s16 D_800B5B28;
extern s8 D_800BD690;
extern char D_800BD8EC[];
extern char D_800D2A74[];
extern s16 D_80108400;
extern void *D_80109BB0;
extern u8 D_8010A4C0;
extern u8 D_8010A4FC;
extern u8 D_8010A4FE;
extern u8 D_8010A4FF;

void func_8001DE20(void) {
    s32 var_a0;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a1;
    s32 var_v0;
    void *temp_s0;
    void *temp_s1;
    void *temp_s2;
    void *temp_s4;
    void *temp_s5;
    void *var_a0_2;
    void *var_s3;

    D_800BD690 = 1;
    temp_s4 = func_8002638C(D_800BD8EC);
    temp_s5 = func_8002638C(D_800BD8EC, 0x20);
    temp_s1 = func_8002638C(D_800BD8EC, 0x19);
    var_s3 = func_8002638C(D_800BD8EC, 0x1C);
    D_800B5B28 = 1;
    if (var_s3 == NULL) {
        var_s3 = func_8002638C(D_800BD8EC, 3);
    }
    var_v0 = temp_s4 != NULL;
    if ((var_v0 & (temp_s5 != NULL)) && ((temp_s1 != NULL) & (var_s3 != NULL))) {
        M2C_FIELD(temp_s5, s32 *, 0x14) = (s32) ((((D_8010A4FC * M2C_FIELD(temp_s5, s32 *, 0x10)) + 2) << 0x10) | 8);
        var_a0 = 0x1B;
        if (D_8010A4FE == 0) {
            var_a0 = 0x1A;
        }
        do { func_80026004(temp_s1, "%s", func_80087100(var_a0)); } while (0);
        temp_s2 = var_s3 - 0x28;
        if (D_80108400 != 0) {
            temp_s0 = temp_s4 - 0x28;
            M2C_FIELD(var_s3, s16 *, -0x28) = 3;
            func_80025E9C(temp_s2, var_s3, temp_s1 - 0x28, temp_s0, 1, 9);
            func_80026004(var_s3, D_800D2A74);
            func_80025D84(temp_s0, temp_s4, temp_s2, temp_s5 - 0x28, 0x1F, 1);
            var_a0_2 = M2C_FIELD(D_80109BB0, void **, 0x10);
            var_a1 = 0x1F;
        } else {
            M2C_FIELD(var_s3, s16 *, -0x28) = 0x1C;
            func_80025D84(var_s3 - 0x28, var_s3, temp_s1 - 0x28, temp_s4 - 0x28, 0x1C, 1);
            var_a0_3 = 0x1B3;
            if (D_8010A4FF != 0) {
                var_a0_3 = 0x1D;
            }
            func_80026004(var_s3, "%s", func_80087100(var_a0_3));
            func_80025E9C(temp_s4 - 0x28, temp_s4, var_s3 - 0x28, temp_s5 - 0x28, 1, 0xD);
            var_a0_2 = M2C_FIELD(D_80109BB0, void **, 0x10);
            var_a1 = 0x20;
        }
        M2C_FIELD(M2C_FIELD(D_80109BB0, void **, 0x10), s8 *, 4) = func_800263B8(var_a0_2, var_a1);
        var_a0_4 = 0x16;
        if ((D_8010A4C0 != 0)) {
            if ((D_8010A4C0 == 1)) {
                var_a0_4 = 0x17;
            }
        }
        do { func_80026004(temp_s4, "%s", func_80087100(var_a0_4)); } while (0);
    }
}
