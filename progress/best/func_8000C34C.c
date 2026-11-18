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

s32 func_8000BB50();
s32 func_80043FA0();
void *func_80044818();
f32 func_80046140();
f32 func_8008292C();
f32 func_80082968();
f32 func_80082A70();
s32 func_800A37C0();
extern f32 D_800AE4D8;
extern char D_800B1B68[];
extern char D_800B1D48[];
extern u32 D_800B1D84;
extern char D_800B25C0[];
extern u8 D_800C2B40;
extern char D_800C392A[];
extern s32 D_801032A0;
extern u32 D_80107EA0;
extern s32 D_8010A924;
extern s32 *D_8010A928;
extern s32 D_8010D538;
extern f32 D_80112F90;
extern f32 D_80112F98;
extern f32 D_80112FA0;
extern f32 D_80112FA8;
extern f32 D_80112FB0;
extern f32 D_80112FB8;
extern void *D_80117728;

void func_8000C34C(void *arg0, void *arg1) {
    s32 sp18;
    s32 sp24;
    s32 *var_a0_2;
    s32 *var_s2;
    s32 var_a0;
    s32 var_a1;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs1;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 var_fs1;
    f32 var_fs2;
    f32 var_ft1;
    s32 *temp_a0_2;
    s32 *temp_v1_2;
    s32 *temp_v1_3;
    s32 *temp_v1_4;
    s32 *temp_v1_8;
    s32 var_a1_2;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s4;
    s8 temp_a0;
    s8 temp_s6;
    u32 temp_v0;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_v1;
    void *temp_v1_5;
    void *temp_v1_6;
    void *temp_v1_7;

    temp_v1 = M2C_FIELD(arg0, void **, 0x68);
    if (*(D_800C392A + (M2C_FIELD(temp_v1, u8 *, 0xB2) * 8)) == 0) {
        temp_s6 = M2C_FIELD(temp_v1, s8 *, 0xB3);
        var_a0 = 0xF;
        if (!(((u32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u32 *, 0x58) >> 2) & 0x200)) {
            var_a0 = 0xE;
            if (D_8010A924 != 0xE) {
                temp_v1_2 = D_8010A928;
                D_8010A924 = 0xE;
                D_8010A928 = temp_v1_2 + 8;
                M2C_FIELD(temp_v1_2, s32 *, 0) = 0xDE000000;
                M2C_FIELD(temp_v1_2, s32 **, 4) = D_800B1D48;
            }
            var_fs2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), f32 *, 8);
        } else {
            if (D_8010A924 != 0xF) {
                temp_v1_3 = D_8010A928;
                D_8010A924 = 0xF;
                D_8010A928 = temp_v1_3 + 8;
                M2C_FIELD(temp_v1_3, s32 *, 0) = 0xDE000000;
                M2C_FIELD(temp_v1_3, s32 **, 4) = D_800B1B68;
            }
            var_fs2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), f32 *, 8) + 0.01f;
        }
        var_a1 = 0xFCFF0000;
        if (D_801032A0 != 7) {
            var_a1 = 0xFCFF97FF;
            temp_v1_4 = D_8010A928;
            var_a0 = 0xFFFDFE38;
            D_801032A0 = 7;
            D_8010A928 = temp_v1_4 + 8;
            M2C_FIELD(temp_v1_4, s32 *, 0) = 0xFCFF97FF;
            M2C_FIELD(temp_v1_4, s32 *, 4) = 0xFFFDFE38;
        }
        if (arg1 != NULL) {
            temp_fv0 = func_80082A70(M2C_FIELD(arg0, f32 *, 0x24) - M2C_FIELD(arg1, f32 *, 4), M2C_FIELD(arg0, f32 *, 0x2C) - M2C_FIELD(arg1, f32 *, 0xC), var_a0, var_a1, 7, arg1);
            var_fs1 = func_8008292C(temp_fv0);
            var_ft1 = func_80082968(temp_fv0);
        } else {
            var_fs1 = 1.0f;
            var_ft1 = 0.0f;
        }
        var_s1 = 0;
        if (temp_s6 > 0) {
            var_a0_2 = &sp18;
            var_a1_2 = 0;
            do {
                M2C_FIELD(var_a0_2, f32 *, 4) = var_fs2;
                M2C_FIELD(var_a0_2, f32 *, 0) = (f32) *(f32 *)(var_a1_2 + M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0));
                M2C_FIELD(var_a0_2, f32 *, 8) = (f32) M2C_FIELD((var_a1_2 + M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0)), f32 *, 8);
                temp_v1_5 = M2C_FIELD(arg0, void **, 0x68);
                M2C_FIELD(var_a0_2, f32 *, 0) += (var_fs1 * ((M2C_FIELD((var_a1_2 + M2C_FIELD(temp_v1_5, s32 *, 0)), f32 *, 4) - D_800AE4D8) - M2C_FIELD(temp_v1_5, f32 *, 8)));
                temp_v1_6 = M2C_FIELD(arg0, void **, 0x68);
                temp_fv1 = M2C_FIELD(var_a0_2, f32 *, 8) + (var_ft1 * ((M2C_FIELD((var_a1_2 + M2C_FIELD(temp_v1_6, s32 *, 0)), f32 *, 4) - D_800AE4D8) - M2C_FIELD(temp_v1_6, f32 *, 8)));
                var_s1 += 1;
                var_a1_2 += 0xC;
                M2C_FIELD(var_a0_2, f32 *, 8) = temp_fv1;
                var_a0_2 += 0xC;
            } while (var_s1 < temp_s6);
        }
        var_s1_2 = 1;
        if (temp_s6 > 1) {
            var_s2 = &sp24;
            var_s4 = 8;
            do {
                if (*(D_800B25C0 + var_s4) != -1) {
                    temp_s0 = var_s4 + D_800B25C0;
                    temp_a0 = M2C_FIELD(temp_s0, s8 *, 1);
                    temp_v1_7 = &sp18 + (temp_a0 * 0xC);
                    temp_fs1 = M2C_FIELD(temp_v1_7, f32 *, 0) - M2C_FIELD(var_s2, f32 *, 0);
                    temp_fs0 = M2C_FIELD(temp_v1_7, f32 *, 8) - M2C_FIELD(var_s2, f32 *, 8);
                    temp_s0_2 = func_80044818(M2C_FIELD(temp_s0, s32 *, 4), 0x2A);
                    temp_fs0_2 = func_80046140(temp_fs1, temp_fs0, temp_a0);
                    temp_fv1_2 = func_80082A70(temp_fs1, temp_fs0);
                    if (((u32) D_80107EA0 < (u32) D_800B1D84) && ((temp_v0 = D_80107EA0 + 1, D_80107EA0 = temp_v0, D_8010D538 = M2C_FIELD(D_80117728, s32 *, 0x74C) + (temp_v0 << 6), func_8000BB50(&D_80112F90, M2C_FIELD(var_s2, f32 *, 0) * 64.0f, M2C_FIELD(var_s2, f32 *, 4) * 64.0f, M2C_FIELD(var_s2, f32 *, 8) * 64.0f, temp_fv1_2), D_80112F90 *= temp_fs0_2, D_80112FA0 *= temp_fs0_2, D_80112FB0 *= temp_fs0_2, D_80112F98 *= temp_fs0_2, D_80112FA8 *= temp_fs0_2, D_80112FB8 *= temp_fs0_2, func_800A37C0(&D_80112F90, D_8010D538), temp_a0_2 = D_8010A928, D_8010A928 = temp_a0_2 + 8, M2C_FIELD(temp_a0_2, s32 *, 0) = 0xDA380003, M2C_FIELD(temp_a0_2, s32 *, 4) = (s32) (D_8010D538 - 0x80000000), M2C_FIELD(temp_a0_2, s32 *, 8) = 0xFA000000, M2C_FIELD(temp_a0_2, s32 *, 0xC) = (s32) (((M2C_FIELD(arg0, u8 *, 0x82) * 2) / 3) & 0xFF), D_8010A928 = temp_a0_2 + 0x10, (M2C_FIELD(temp_s0_2, s32 *, 0) != 0)) || (func_80043FA0(temp_s0_2, 0xDA380003), (M2C_FIELD(temp_s0_2, s32 *, 0) != 0)))) {
                        if (!(M2C_FIELD(temp_s0_2, u8 *, 0x46) & 0x80)) {
                            M2C_FIELD(temp_s0_2, u8 *, 0x46) = (u8) D_800C2B40;
                        }
                        temp_v1_8 = D_8010A928;
                        M2C_FIELD(temp_v1_8, s32 *, 0) = 0xDE000000;
                        D_8010A928 = temp_v1_8 + 8;
                        M2C_FIELD(temp_v1_8, s32 *, 4) = (s32) M2C_FIELD(temp_s0_2, s32 *, 0);
                    }
                }
                var_s2 += 0xC;
                var_s1_2 += 1;
                var_s4 += 8;
            } while (var_s1_2 < temp_s6);
        }
    }
}
