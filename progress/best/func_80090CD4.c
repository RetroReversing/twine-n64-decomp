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

s32 func_80099708();
extern s32 *D_800E5AC0;
extern char D_800E5AC4[];
extern char D_800E6A84[];
extern char D_800E6A85[];
extern char D_800E6AB4[];

void func_80090CD4(s32 arg0) {
    s32 *temp_v0;
    s32 *temp_v0_2;
    s32 *var_v1_2;
    s32 *var_v1_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0_2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    u32 var_a0;
    void *temp_a0;
    void *temp_s2;
    void *var_s0;
    void *var_s0_2;

    var_a0 = 0;
    var_v1 = 0;
loop_1:
    if ((*(D_800E6A85 + var_v1) != 0) || (*(D_800E5AC4 + var_v1) != (arg0 & 0x7FFFFFFF))) {
        var_a0 += 1;
        var_v1 += 0xFF8;
        if (var_a0 >= 8U) {
            var_a0_2 = -1;
        } else {
            goto loop_1;
        }
    } else {
        var_a0_2 = var_a0 | (arg0 & 0x80000000);
    }
    if (var_a0_2 != -1) {
        if (var_a0_2 >= 0) {
            temp_v1 = var_a0_2 * 0xFF8;
            var_v0 = var_a0_2 << 9;
            if (*(D_800E6A84 + temp_v1) != 0) {
                var_v0 = var_a0_2 << 9;
                if (*(D_800E6A85 + temp_v1) == 0) {
                    temp_s2 = temp_v1 + D_800E5AC4;
                    *(D_800E6A84 + temp_v1) = 0;
                    var_s0 = M2C_FIELD(temp_s2, void **, 0xF78);
                    if (var_s0 != NULL) {
                        do {
                            func_80099708(M2C_FIELD(var_s0, s32 *, 8));
                            var_s0 = M2C_FIELD(var_s0, void **, 0);
                        } while (var_s0 != NULL);
                    }
                    var_s0_2 = M2C_FIELD(temp_s2, void **, 0xF7C);
                    var_v0_2 = var_a0_2 << 9;
                    if (var_s0_2 != NULL) {
                        do {
                            func_80099708(M2C_FIELD(var_s0_2, s32 *, 8));
                            var_s0_2 = M2C_FIELD(var_s0_2, void **, 0);
                            var_v0_2 = var_a0_2 << 9;
                        } while (var_s0_2 != NULL);
                    }
                    temp_a0 = ((var_v0_2 - var_a0_2) * 8) + D_800E5AC4;
                    var_v1_2 = M2C_FIELD(temp_a0, s32 **, 0xF78);
                    if (var_v1_2 != NULL) {
                        if (*var_v1_2 != NULL) {
                            do {
                                var_v1_2 = *var_v1_2;
                            } while (*var_v1_2 != NULL);
                        }
                        if (D_800E5AC0 != NULL) {
                            *var_v1_2 = D_800E5AC0;
                            M2C_FIELD(D_800E5AC0, s32 **, 4) = var_v1_2;
                        }
                        temp_v0 = M2C_FIELD(temp_a0, s32 **, 0xF78);
                        M2C_FIELD(temp_a0, s32 **, 0xF78) = NULL;
                        D_800E5AC0 = temp_v0;
                    }
                    var_v1_3 = M2C_FIELD(temp_a0, s32 **, 0xF7C);
                    var_v0 = var_a0_2 << 9;
                    if (var_v1_3 != NULL) {
                        if (*var_v1_3 != NULL) {
                            do {
                                var_v1_3 = *var_v1_3;
                            } while (*var_v1_3 != NULL);
                        }
                        if (D_800E5AC0 != NULL) {
                            *var_v1_3 = D_800E5AC0;
                            M2C_FIELD(D_800E5AC0, s32 **, 4) = var_v1_3;
                        }
                        temp_v0_2 = M2C_FIELD(temp_a0, s32 **, 0xF7C);
                        M2C_FIELD(temp_a0, s32 **, 0xF7C) = NULL;
                        D_800E5AC0 = temp_v0_2;
                        var_v0 = var_a0_2 << 9;
                    }
                }
            }
            *(D_800E6A85 + ((var_v0 - var_a0_2) * 8)) = 1;
            return;
        }
        temp_v1_2 = (var_a0_2 & 0x7FFFFFFF) * 0xFF8;
        if ((*(D_800E6A84 + temp_v1_2) != 0) && (*(D_800E6A85 + temp_v1_2) == 0)) {
            *(D_800E6AB4 + temp_v1_2) = 0;
        }
    }
}
