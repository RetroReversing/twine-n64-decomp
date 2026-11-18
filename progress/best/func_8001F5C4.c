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
extern char D_800D2A84[];
extern s16 D_80108400;
extern void *D_80109BB0;
extern u8 D_8010A4C0;
extern u8 D_8010A4FE;
extern u8 D_8010A4FF;

void func_8001F5C4(void) {
    s32 var_a0;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a1;
    s32 var_v0;
    void *temp_s0;
    void *temp_s2;
    void *temp_s2_2;
    void *temp_s3;
    void *temp_s5;
    void *var_a0_2;
    void *var_s4;

    temp_s5 = func_8002638C(M2C_FIELD(D_80109BB0, void **, 0x10), 0x1F);
    temp_s2 = func_8002638C(M2C_FIELD(D_80109BB0, void **, 0x10), 0x19);
    var_s4 = func_8002638C(M2C_FIELD(D_80109BB0, void **, 0x10), 0x1C);
    var_v0 = temp_s5 != NULL;
    if (var_s4 == NULL) {
        var_s4 = func_8002638C(M2C_FIELD(D_80109BB0, void **, 0x10), 3);
        var_v0 = temp_s5 != NULL;
    }
    if ((var_v0 & (temp_s2 != NULL)) && (var_s4 != NULL)) {
        var_a0 = 0x1B;
        if (D_8010A4FE == 0) {
            var_a0 = 0x1A;
        }
        func_80026004(temp_s2, "%s", func_80087100(var_a0));
        temp_s3 = var_s4 - 0x28;
        if (D_80108400 != 0) {
            temp_s2_2 = temp_s2 - 0x28;
            temp_s0 = temp_s5 - 0x28;
            M2C_FIELD(var_s4, s16 *, -0x28) = 3;
            func_80025E9C(temp_s3, var_s4, temp_s2_2, temp_s0, 1, 9);
            func_80026004(var_s4, D_800D2A84);
            func_80025D84(temp_s0, temp_s5, temp_s3, temp_s2_2, 0x1F, 1);
            var_a0_2 = M2C_FIELD(D_80109BB0, void **, 0x10);
            var_a1 = 0x1F;
        } else {
            M2C_FIELD(var_s4, s16 *, -0x28) = 0x1C;
            func_80025D84(var_s4 - 0x28, var_s4, temp_s2 - 0x28, temp_s5 - 0x28, 0x1C, 1);
            var_a0_3 = 0x1B3;
            if (D_8010A4FF != 0) {
                var_a0_3 = 0x1D;
            }
            func_80026004(var_s4, "%s", func_80087100(var_a0_3));
            func_80025E9C(temp_s5 - 0x28, temp_s5, var_s4 - 0x28, temp_s2 - 0x28, 1, 0xD);
            var_a0_2 = M2C_FIELD(D_80109BB0, void **, 0x10);
            var_a1 = 0x19;
        }
        M2C_FIELD(M2C_FIELD(D_80109BB0, void **, 0x10), s8 *, 4) = func_800263B8(var_a0_2, var_a1);
        var_a0_4 = 0x16;
        if ((D_8010A4C0 != 0) && (D_8010A4C0 == 1)) {
            var_a0_4 = 0x17;
        }
        func_80026004(temp_s5, "%s", func_80087100(var_a0_4));
    }
}
