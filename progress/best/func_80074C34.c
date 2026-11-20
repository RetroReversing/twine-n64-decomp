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

f32 func_8000A4F4();
f32 func_80045E34();
s32 func_80074820();
s32 func_80087100();
extern s32 D_800C7EE4;
extern char D_80100310[];
extern char D_80100314[];
extern void *D_80100B20;
extern s32 D_8010302C;
extern s32 D_80109688;
extern char *D_8010A500;
extern u8 D_8010D294;
extern s16 D_80112EBC;

void func_80074C34(void *arg0, void *arg1, s32 arg2) {
    f32 temp_fv0;
    f32 var_fs0;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_v1;
    void **temp_s7;
    void **var_s2;
    void *temp_s0;
    void *temp_v0_2;
    void *var_s4;
    void *var_v0;

    var_a0 = 0;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s32 *, 0x60) |= 0x10000000;
    }
    temp_v1 = D_8010D294;
    var_s1 = 0;
    if (temp_v1 > 0) {
        var_v1 = 0;
        do {
            if (*(void **)(D_80100310 + var_v1) == arg1) {
                var_a0 = 1;
            }
            var_s1 += 1;
            var_v1 += 8;
        } while (var_s1 < (s32) D_8010D294);
    }
    if (var_a0 == 0) {
        temp_v0 = D_8010D294 * 8;
        *(D_80100314 + temp_v0) = arg2;
        *(void **)(D_80100310 + temp_v0) = arg1;
        D_8010D294 += 1;
    }
    D_8010302C += 1;
    var_s4 = arg1;
    if (arg2 != 0) {
        temp_s7 = &D_80100B20 - 1;
        do {
            var_fs0 = 5.0f;
            if (M2C_FIELD(var_s4, u16 *, 6) == 0x237) {
                var_fs0 = 0.0f;
            }
            temp_v0 = M2C_FIELD(var_s4, s32 *, 0);
            if (temp_v0 & 0x80000000) {
                var_fs0 = func_8000A4F4(temp_v0 & 0xFFFFFF);
            }
            func_80074820(D_80109688, func_80087100(M2C_FIELD(var_s4, u16 *, 6)), 0x20, 2, var_fs0 + 0.5f, D_800C7EE4);
            if (D_80112EBC != 0) {
                var_s1_2 = 0;
                if (D_80112EBC > 0) {
                    var_s2 = &D_80100B20;
                    do {
                        temp_v0_2 = *var_s2;
                        if (temp_v0_2 != NULL) {
                            temp_s0 = M2C_FIELD(temp_v0_2, void **, 0x6C);
                            if (arg0 != NULL) {
                                M2C_FIELD(temp_s0, void **, 0x2C) = arg0;
                                M2C_FIELD(temp_s0, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
                                M2C_FIELD(temp_s0, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
                                M2C_FIELD(temp_s0, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
                                temp_fv0 = func_80045E34(temp_s0 + 8, D_8010A500 + 0x24);
                                M2C_FIELD(temp_s0, f32 *, 0x28) = temp_fv0;
                                if (temp_fv0 < 4.0f) {
                                    M2C_FIELD(temp_s0, f32 *, 0x28) = 4.0f;
                                }
                            }
                        }
                        temp_v1_2 = M2C_FIELD(var_s4, s32 *, 0);
                        if (temp_v1_2 & 0x80000000) {
                            var_v0 = D_80100B20; } else {
                            var_v0 = temp_s7[D_80112EBC];
                        }
                        M2C_FIELD(M2C_FIELD(var_v0, void **, 0x6C), s32 *, 0x24) = temp_v1_2;
                        M2C_FIELD(M2C_FIELD(temp_s7[D_80112EBC], void **, 0x6C), s8 *, 0x32) = (s8) M2C_FIELD(var_s4, u16 *, 4);
                        var_s1_2 += 1;
                        var_s2 += 1;
                    } while (var_s1_2 < D_80112EBC);
                }
            }
            var_s4 += 8;
        } while ((u32) var_s4 < (u32) ((arg2 * 8) + arg1));
    }
}
