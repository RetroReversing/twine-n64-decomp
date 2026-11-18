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

s32 func_8011AE4C();
s32 func_8011B3D8();
s32 func_8011C338();
s32 func_8011D0B4();
extern u8 D_801002A0;
extern u8 D_801002A1;
extern u8 D_801002D5;
extern char D_8011F100[];

void func_8011AA9C(void *arg0) {
    s32 temp_s1;
    s32 var_v0;
    void *temp_a0;
    void *temp_s0;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;

    temp_s0 = M2C_FIELD(arg0, void **, 0x6C);
    temp_s1 = func_8011B3D8(M2C_FIELD(temp_s0, s32 *, 4));
    if (D_801002A0 != 7) {
        if ((s32) D_801002A0 < 8) {
            if ((s32) D_801002A0 < 4) {
                var_v0 = temp_s1 ^ (s32) temp_s0;
                if ((s32) D_801002A0 >= 2) {
                    func_8011C338(arg0);
                    goto block_16;
                }
            } else {
block_16:
                var_v0 = temp_s1 ^ (s32) temp_s0;
            }
            goto block_17;
        }
        var_v0 = temp_s1 ^ (s32) temp_s0;
        if (D_801002A0 == 8) {
            if (M2C_FIELD(temp_s0, s32 *, 0x1B4) != 0x26) {

            } else if (M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xB4), u8 *, 0x10) == 7) {
                M2C_FIELD(M2C_FIELD(temp_s0, void **, 0xB4), u8 *, 0x11) = 1U;
                temp_v1 = M2C_FIELD(temp_s1, void **, 0xB4);
                M2C_FIELD(temp_v1, u16 *, 0xC) += 1;
            }
            func_8011AE4C(arg0, temp_s0, temp_s1);
        } else {
block_17:
            if (((var_v0 == 0) | (temp_s1 == 0)) != 0) {
                temp_v1_2 = M2C_FIELD(temp_s0, void **, 0xB4);
                M2C_FIELD(temp_v1_2, u16 *, 0xE) += 1;
            } else if (temp_s1 != 0) {
                if (D_801002A1 != 0) {
                    temp_a0 = M2C_FIELD(temp_s1, void **, 0xB4);
                    if (M2C_FIELD(temp_a0, u8 *, 0x12) == M2C_FIELD(M2C_FIELD(temp_s0, void **, 0xB4), u8 *, 0x12)) {
                        if (D_801002D5 != 0) {
                            M2C_FIELD(temp_a0, u16 *, 0xE) += 1;
                        }
                    } else {
                        M2C_FIELD(temp_a0, u16 *, 0xC) += 1;
                    }
                } else {
                    temp_v1_3 = M2C_FIELD(temp_s1, void **, 0xB4);
                    M2C_FIELD(temp_v1_3, u16 *, 0xC) += 1;
                }
            }
        }
    } else {
        temp_v1_4 = M2C_FIELD(temp_s0, void **, 0xB4);
        if (M2C_FIELD(temp_v1_4, u8 *, 0x11) != 0) {
            M2C_FIELD(temp_v1_4, u16 *, 0xC) -= 1;
            temp_v1_5 = M2C_FIELD(temp_s0, void **, 0xB4);
            M2C_FIELD(temp_v1_5, u8 *, 0x11) -= 1;
            if (M2C_FIELD(M2C_FIELD(temp_s0, void **, 0xB4), u16 *, 0xC) == 0) {
                func_8011D0B4(M2C_FIELD(temp_s0, s8 *, 0x182));
            }
        }
    }
    if (temp_s0 != NULL) {
        if (temp_s1 != 0) {
            *(D_8011F100 + (M2C_FIELD(temp_s0, s8 *, 0x182) * 2)) = (s16) (s8) M2C_FIELD(temp_s1, u8 *, 0x182);
            M2C_FIELD(temp_s0, s32 *, 4) = 0;
            return;
        }
        *(D_8011F100 + (M2C_FIELD(temp_s0, s8 *, 0x182) * 2)) = -1;
        M2C_FIELD(temp_s0, s32 *, 4) = 0;
    }
}
