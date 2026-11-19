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

s32 func_80018318();
s32 func_80019B34();
s32 func_80022B60();
s32 func_80022E5C();
s32 func_80022E88();
s32 func_80022EB8();
s32 func_80087100();
s16 strlen();
extern s32 D_800BD64C;
extern s32 D_800BD654;
extern s32 D_800BD65C;
extern s32 D_800BD664;
extern u8 D_801001A1[];
extern u8 D_801002A0;
extern s32 D_80102EBC;
extern void *D_80109BB0;

void func_8001CF24(void *arg0, s32 arg1, s32 arg2) {
int __repair_literal;

    s32 var_v0_2;
    s32 var_v0_3;
    void *temp_a1;
    void *temp_s0;
    void *temp_s1;
    void *temp_v1;
    void *var_a1;

    temp_s1 = M2C_FIELD(arg0, void **, 0);
    temp_v1 = M2C_FIELD(temp_s1, void **, 0);
    if (temp_v1 != NULL) {
        M2C_FIELD(temp_v1, u16 *, 0x20) = (u16) M2C_FIELD(arg0, u16 *, 4);
        M2C_FIELD(M2C_FIELD(temp_s1, void **, 0), u16 *, 0x22) = (u16) M2C_FIELD(arg0, u16 *, 6);
        temp_a1 = M2C_FIELD(temp_s1, void **, 0);
        M2C_FIELD(temp_a1, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_a1, s32 *, 0x28) & ~0xFC) | (((-((arg1 & 0xFF) == 0) & 7) | 3) * 4));
        func_80022E88(3, temp_a1);
        func_80022E5C(M2C_FIELD(D_80109BB0, u8 *, 0x30));
        if (arg2 & 0xFF) {
            func_80022EB8((M2C_FIELD(arg0, u16 *, 4) - 2) & 0xFFFF, (M2C_FIELD(arg0, u8 *, 7) - 4) & 0xFF, (func_80018318(M2C_FIELD(temp_s1, void **, 0)) * 0xC) & 0xFC);
            var_a1 = M2C_FIELD(temp_s1, void **, 0);
            M2C_FIELD(var_a1, s32 *, 0x10) = (s32) ((D_800BD664 & ~0xFF) | M2C_FIELD(D_80109BB0, u8 *, 0x30));
        } else {
            var_a1 = M2C_FIELD(temp_s1, void **, 0);
            M2C_FIELD(var_a1, s32 *, 0x10) = (s32) ((D_800BD64C & ~0xFF) | M2C_FIELD(D_80109BB0, u8 *, 0x30));
        }
        if (M2C_FIELD(temp_s1, void **, 4) != NULL) {
            M2C_FIELD(M2C_FIELD(temp_s1, void **, 4), s32 *, 0x18) = func_80087100(func_80019B34(M2C_FIELD(arg0, u8 *, 8), var_a1) & 0xFFFF);
            temp_s0 = M2C_FIELD(temp_s1, void **, 4);
            M2C_FIELD(temp_s0, s16 *, 0x1C) = strlen(M2C_FIELD(temp_s0, s32 *, 0x18));
            M2C_FIELD(M2C_FIELD(temp_s1, void **, 4), s16 *, 0x20) = (s16) (M2C_FIELD(arg0, u16 *, 4) + 0x7E);
            M2C_FIELD(M2C_FIELD(temp_s1, void **, 4), u16 *, 0x22) = (u16) M2C_FIELD(arg0, u16 *, 6);
            var_v0_2 = arg2 & 0xFF;
__repair_literal = 2;

            if (((s32) D_801002A0 >= __repair_literal) && ((var_v0_2 = arg2 & 0xFF, (((s32) D_801002A0 < 4) != 0)) || (var_v0_2 = arg2 & 0xFF, (D_801002A0 == 6)))) {
                if (var_v0_2 != 0) {
                    var_v0_3 = 0x800BD664;
                } else if (*(D_801001A1 + (M2C_FIELD(arg0, u8 *, 8) * 0x18)) == 0) {
                    var_v0_3 = D_800BD65C;
                } else {
                    var_v0_3 = D_800BD654;
                }
            } else if (var_v0_2 != 0) {
                var_v0_3 = D_800BD664;
            } else {
                var_v0_3 = D_80102EBC;
            }
            M2C_FIELD(M2C_FIELD(temp_s1, void **, 4), s32 *, 0x10) = (s32) ((var_v0_3 & ~0xFF) | M2C_FIELD(D_80109BB0, u8 *, 0x30));
            var_a1 = M2C_FIELD(temp_s1, void **, 4);
            M2C_FIELD(var_a1, s32 *, 0x28) = (s32) ((M2C_FIELD(var_a1, s32 *, 0x28) & ~0xFC) | (M2C_FIELD(M2C_FIELD(temp_s1, void **, 0), s32 *, 0x28) & 0xFC));
        }
        func_80022B60(3, var_a1);
    }
}
