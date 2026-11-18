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

s32 func_80034560();
s32 func_80034928();
s32 func_800399D0(void *arg0);
s32 func_8003A4C0();
s32 func_8003AF20();
s32 func_8003B954();
s32 func_8003F940();
extern s8 D_800C0738;
extern s8 D_800E176C;
extern s32 D_8010A4D8;
extern s32 D_8010A4E8;
extern void *D_80115328;

void func_8003C228(void *arg0, s32 arg1, s32 arg2) {
    s32 sp14;
    u8 sp1F;
    f32 temp_fs0;
    f32 temp_fs1;
    s32 temp_s6;
    s32 temp_s7;
    s32 var_v0;
    u16 temp_v1;
    u16 var_a1;
    u32 temp_s1;
    u32 temp_s2;
    u8 var_a3;
    void *var_s0;
    void *temp_v1_4;
    void *temp_v1_3;
    
    void *temp_v1_2;
    void *temp_a3_2;
    void *temp_a3;
    void *temp_a0;

    sp14 = arg2;
    var_s0 = M2C_FIELD(arg0, void **, 4);
    temp_fs1 = M2C_FIELD(arg0, f32 *, 0x50) + M2C_FIELD(arg0, f32 *, 0x60);
    sp1F = 1;
    temp_fs0 = M2C_FIELD(arg0, f32 *, 0x58) + M2C_FIELD(arg0, f32 *, 0x64);
    if (var_s0 != NULL) {
        temp_s7 = (s32) temp_fs1;
        temp_s6 = (s32) temp_fs0;
        do {
            if ((((u32) M2C_FIELD(var_s0, u32 *, 0x28) >> 2) & 0x3F) == sp14) {
                temp_s1 = M2C_FIELD(var_s0, u32 *, 0x10);
                temp_v1 = M2C_FIELD(var_s0, u16 *, 0x1E);
                temp_s2 = M2C_FIELD(var_s0, u32 *, 0x14);
                if (temp_v1 & 0x1000) {
                    var_a1 = M2C_FIELD(var_s0, u16 *, 0x22);
                    var_a3 = (u8) M2C_FIELD(var_s0, u32 *, 0x28);
                    if (D_8010A4E8 != 0) {
                        var_a3 *= 2;
                        var_a1 *= 2;
                    }
                    func_8003F940(M2C_FIELD(var_s0, u16 *, 0x20), var_a1 & 0xFFFF, M2C_FIELD(var_s0, u16 *, 0x24));
                } else if (temp_v1 & 0x2000) {
                    func_80034560(arg0);
                } else if ((u32) (temp_s1 & 0xFF) >= 5U) {
                    var_v0 = temp_s1 & 0xFF;
                    if (sp1F == 1) {
                        func_800399D0(arg0);
                        sp1F = 0;
                        func_80034928(arg0, D_8010A4D8);
                        var_v0 = temp_s1 & 0xFF;
                    }
                    if (var_v0 != 0) {
                        if (M2C_FIELD(var_s0, u16 *, 0x1E) & 0x400) {
                            if (D_800E176C == 0) {
                                temp_v1_2 = D_80115328;
                                D_800E176C = 1;
                                D_80115328 = temp_v1_2 + 8;
                                M2C_FIELD(temp_v1_2, s32 *, 0) = 0xE3001201;
                                M2C_FIELD(temp_v1_2, s32 *, 4) = 0x2000;
                            }
                        } else if (D_800E176C != 0) {
                            temp_a0 = D_80115328;
                            D_800E176C = 0;
                            D_80115328 = temp_a0 + 8;
                            M2C_FIELD(temp_a0, s32 *, 0) = 0xE3001201;
                            M2C_FIELD(temp_a0, s32 *, 4) = 0;
                        }
                        if (M2C_FIELD(var_s0, s32 *, 0x18) != 0) {
                            if (M2C_FIELD(var_s0, u16 *, 0x1E) & 0x20) {
                                temp_v1_3 = D_80115328;
                                D_800C0738 = 1;
                                D_80115328 = temp_v1_3 + 8;
                                M2C_FIELD(temp_v1_3, s32 *, 4) = (s32) (temp_s1 & 0xFF);
                                M2C_FIELD(temp_v1_3, s32 *, 0) = 0xFA000000;
                                D_80115328 = temp_v1_3 + 0x10;
                                M2C_FIELD(temp_v1_3, s32 *, 8) = 0xFB000000;
                                M2C_FIELD(temp_v1_3, s32 *, 0xC) = 0;
                                func_8003B954((s32) (temp_fs1 + 1.0f), (s32) (temp_fs0 + 1.0f), var_s0);
                            }
                            temp_a3 = D_80115328;
                            D_800C0738 = 0;
                            D_80115328 = temp_a3 + 8;
                            M2C_FIELD(temp_a3, s32 *, 4) = (s32) (((temp_s1 >> 0x18) << 0x18) | (temp_s1 & 0xFF0000) | (temp_s1 & 0xFF00) | (temp_s1 & 0xFF));
                            D_80115328 = temp_a3 + 0x10;
                            M2C_FIELD(temp_a3, s32 *, 0) = 0xFA000000;
                            M2C_FIELD(temp_a3, s32 *, 8) = 0xFB000000;
                            M2C_FIELD(temp_a3, s32 *, 0xC) = (s32) (((temp_s2 >> 0x18) << 0x18) | (temp_s2 & 0xFF0000) | (temp_s2 & 0xFF00));
                            func_8003B954(temp_s7, temp_s6, var_s0, temp_a3);
                        } else {
                            if (M2C_FIELD(var_s0, u16 *, 0x1E) & 0x20) {
                                temp_a3_2 = D_80115328;
                                M2C_FIELD(temp_a3_2, s32 *, 0) = 0xFA000000;
                                M2C_FIELD(temp_a3_2, s32 *, 4) = (s32) (temp_s1 & 0xFF);
                                M2C_FIELD(temp_a3_2, s32 *, 8) = 0xFB000000;
                                M2C_FIELD(temp_a3_2, s32 *, 0xC) = 0;
                                D_80115328 = temp_a3_2 + 8;
                                D_80115328 = temp_a3_2 + 0x10;
                                if ((M2C_FIELD(var_s0, u32 *, 0x28) & 3) == 1) {
                                    D_80115328 = temp_a3_2 + 0x18;
                                    D_80115328 = temp_a3_2 + 0x20;
                                    M2C_FIELD(temp_a3_2, s32 *, 0x10) = 0xFC119623;
                                    M2C_FIELD(temp_a3_2, s32 *, 0x14) = 0xFF2FFFFF;
                                    M2C_FIELD(temp_a3_2, s32 *, 0x18) = 0xE3001001;
                                    M2C_FIELD(temp_a3_2, s32 *, 0x1C) = 0x8000;
                                    func_8003AF20((s32) (temp_fs1 + 1.0f), (s32) (temp_fs0 + 1.0f), var_s0, temp_a3_2);
                                } else {
                                    func_8003A4C0((s32) (temp_fs1 + 1.0f), (s32) (temp_fs0 + 1.0f), var_s0, temp_a3_2);
                                }
                            }
                            M2C_FIELD(D_80115328, s32 *, 4) = (s32) (((temp_s1 >> 0x18) << 0x18) | (temp_s1 & 0xFF0000) | (temp_s1 & 0xFF00) | (temp_s1 & 0xFF));
                            M2C_FIELD(D_80115328, s32 *, 0) = 0xFA000000;
                            M2C_FIELD(D_80115328, s32 *, 8) = 0xFB000000;
                            M2C_FIELD(D_80115328, s32 *, 0xC) = (s32) (((temp_s2 >> 0x18) << 0x18) | (temp_s2 & 0xFF0000) | (temp_s2 & 0xFF00));
                            temp_a0 = D_80115328 + 0x10;
                            D_80115328 += 8;
                            D_80115328 = temp_a0;
                            if ((M2C_FIELD(var_s0, u32 *, 0x28) & 3) == 1) {
                                func_8003AF20(temp_s7, temp_s6, var_s0);
                            } else {
                                func_8003A4C0(temp_s7, temp_s6, var_s0);
                            }
                        }
                    }
                }
            }
            var_s0 = M2C_FIELD(var_s0, void **, 4);
        } while (var_s0 != NULL);
    }
    if (D_800E176C == 0) {
        temp_v1_4 = D_80115328;
        D_80115328 = temp_v1_4 + 8;
        M2C_FIELD(temp_v1_4, s32 *, 0) = 0xE3001201;
        M2C_FIELD(temp_v1_4, s32 *, 4) = 0x2000;
    }
}
