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

f32 func_8008292C();
f32 func_80082968();
s32 guRandom();
extern char D_80000040[];
extern s32 D_800B1D74;
extern f32 D_800B1D78;
extern f64 D_800D2E98;
extern s32 D_801007B8;
extern u8 D_80102F38;
extern u8 D_801032A4;
extern u8 D_80108F74;

void func_80033FB8(void *arg0) {
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs1_2;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f64 var_fa0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_ret;
    s32 temp_ret_2;
    s32 temp_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    u32 temp_v1;
    u8 temp_v0_2;
    u8 temp_v0_3;
    u8 temp_v1_2;
    u8 var_v0;
    void *temp_a0;

    temp_a0 = M2C_FIELD(arg0, void **, 0x20);
    if (M2C_FIELD(temp_a0, u16 *, 0x60) != D_800B1D74) {
        M2C_FIELD(temp_a0, u16 *, 0x60) = (u16) D_800B1D74;
        temp_v1 = (u32) M2C_FIELD(arg0, u32 *, 0x58) >> 2;
        if (temp_v1 & 0x10) {
            var_fa0 = (f64) D_801007B8;
            if (D_801007B8 < 0) {
                var_fa0 += D_800D2E98;
            }
            temp_fv1 = (func_8008292C((f32) var_fa0 * 0.1f, temp_a0) * 64.0f) + 192.0f;
            if (temp_fv1 >= 2.1474836e9f) {
                var_v1 = (s32) (temp_fv1 - 2.1474836e9f) | 0x80000000;
            } else {
                var_v1 = (s32) temp_fv1;
            }
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u8 *, 0x64) = (u8) var_v1;
            var_v1_2 = 0x40;
            goto block_17;
        }
        if (temp_v1 & 0x80) {
            temp_fs1 = func_8008292C(D_800B1D78 * 0.02f, temp_a0);
            temp_fs0 = func_80082968(D_800B1D78 * 0.07f);
            temp_fs1_2 = temp_fs1 * (temp_fs0 * 64.0f) * func_8008292C(D_800B1D78 * 0.04f);
            if (temp_fs1_2 >= 2.1474836e9f) {
                var_v1_3 = (s32) (temp_fs1_2 - 2.1474836e9f) | (s32) &D_80000040;
            } else {
                var_v1_3 = (s32) temp_fs1_2;
            }
            var_v1_2 = var_v1_3;
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u8 *, 0x64) = (u8) var_v1_2;
block_17:
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s8 *, 0x65) = (s8) var_v1_2;
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u8 *, 0x66) = (u8) var_v1_2;
            return;
        }
        if (temp_v1 & 0x40) {
            temp_fv1_2 = (func_8008292C(D_800B1D78 * 0.2f, temp_a0) * 128.0f) + 128.0f;
            if (temp_fv1_2 >= 2.1474836e9f) {
                var_v1_4 = (s32) (temp_fv1_2 - 2.1474836e9f) | 0x80000000;
            } else {
                var_v1_4 = (s32) temp_fv1_2;
            }
            temp_v1_2 = var_v1_4 | 8;
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u8 *, 0x64) = temp_v1_2;
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u8 *, 0x65) = temp_v1_2;
            var_v0 = 8;
            goto block_36;
        }
        if (temp_v1 & 0x20) {
            if ((u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u8 *, 0x64) < 0x20U) {
                temp_ret = guRandom(temp_a0);
                temp_v0 = temp_ret;
                temp_a0_2 = temp_ret / 30;
                if (temp_v0 == (temp_a0_2 * 0x1E)) {
                    var_v0_2 = guRandom((void *) temp_a0_2, MULT_HI(temp_v0, 0x88888889));
                    temp_a0_3 = var_v0_2;
                    if (temp_a0_3 < 0) {
                        var_v0_2 = temp_a0_3 + 0x7F;
                    }
                    temp_v0_2 = (temp_a0_3 - ((var_v0_2 >> 7) << 7)) - 0x80;
                    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u8 *, 0x64) = temp_v0_2;
                    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u8 *, 0x65) = temp_v0_2;
                    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u8 *, 0x66) = temp_v0_2;
                }
            } else {
                temp_ret_2 = guRandom(temp_a0);
                temp_a0_4 = temp_ret_2 / 3;
                if (temp_ret_2 == (temp_a0_4 * 3)) {
                    var_v0_3 = guRandom((void *) temp_a0_4, temp_ret_2 / 3);
                    temp_a0_5 = var_v0_3;
                    if (temp_a0_5 < 0) {
                        var_v0_3 = temp_a0_5 + 0x7F;
                    }
                    temp_v0_3 = (temp_a0_5 - ((var_v0_3 >> 7) << 7)) - 0x80;
                    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u8 *, 0x64) = temp_v0_3;
                    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u8 *, 0x65) = temp_v0_3;
                    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u8 *, 0x66) = temp_v0_3;
                }
            }
        } else {
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u8 *, 0x64) = (u8) D_80102F38;
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u8 *, 0x65) = (u8) D_80108F74;
            var_v0 = D_801032A4;
block_36:
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u8 *, 0x66) = var_v0;
        }
    }
}
