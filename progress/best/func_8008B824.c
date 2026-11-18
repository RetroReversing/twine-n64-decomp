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

s32 func_80089384();
s32 func_800895F8();
extern f64 D_800D6798;
extern s32 D_800E41E8;
extern s32 D_800E41EC;
extern s8 D_800E4215;
extern s32 D_800E4230;
extern s32 D_800E4238;
extern s32 D_800E423C;
extern s16 D_800E4268;
extern s32 (*D_8010016C)(s32 *);
extern s32 (*D_8010017C)(s32, s32, s32);
extern s32 D_801002D8;
extern s32 D_80103098;
extern s8 D_8010309C;
extern s8 D_8010309D;
extern char D_8010319E[];
extern s32 D_8010D428;
extern s32 D_8011772C;
extern s32 func_8008B25C;

void func_8008B824(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 temp_fv1;
    f64 var_ft0;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_a1;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;

    var_s0 = arg1;
    if ((u32) (var_s0 & 0xFFFF) >= 0x21U) {
        var_s0 = 0x20;
    }
    D_800E4215 = 0;
    temp_s0 = var_s0 & 0xFFFF;
    func_80089384(temp_s0, *arg0);
    func_800895F8(temp_s0, *arg0, arg3 & 0xFF);
    temp_a2 = arg2 & 0xFFFF;
    if (temp_a2 != 0) {
        D_800E4230 = 0;
        temp_a2_2 = ((((*arg0 * temp_a2) / 1000) / 192) * 0xC0) + 0xC0;
        D_800E423C = temp_a2_2;
        D_800E4238 = D_8010017C(temp_a2_2 * 2, 0, temp_a2_2);
    } else {
        D_800E4238 = 0;
    }
    D_800E4268 = 0xFFFF;
    D_8011772C = 0;
    D_8010D428 = 0;
    D_8010016C(&func_8008B25C);
    temp_v0 = *arg0;
    var_ft0 = (f64) temp_v0;
    if (temp_v0 < 0) {
        var_ft0 += D_800D6798;
    }
    temp_fv1 = ((f32) var_ft0 * 0.016666668f * 0.0052083335f) + 0.5f;
    if (temp_fv1 >= 2.1474836e9f) {
        var_v1 = (s32) (temp_fv1 - 2.1474836e9f) | 0x80000000;
        var_v0 = var_v1 * 2;
    } else {
        var_v1 = (s32) temp_fv1;
        var_v0 = var_v1 * 2;
    }
    D_800E41EC = var_v1;
    D_800E41E8 = var_v1;
    D_801002D8 = (var_v0 + var_v1) << 6;
    D_8010309D = 0x10;
    D_8010309C = 1;
    D_80103098 = *arg0;
    var_a1 = 0;
    if (*"N64 RSP mixer V1.1" != 0) {
        var_v0_2 = 0 & 0xFF;
        do {
            var_a1 += 1;
            *(D_8010319E + var_v0_2) = (u8) "N64 RSP mixer V1.1"[var_v0_2];
            var_v0_2 = var_a1 & 0xFF;
        } while ("N64 RSP mixer V1.1"[var_a1 & 0xFF] != 0);
    }
    *(D_8010319E + (var_a1 & 0xFF)) = 0;
}
