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

s32 func_80089C10();
s32 func_80089E64();
s32 osCreateMesgQueue();
extern char D_8000003F[];
extern char D_800CEED0[];
extern f64 D_800D6700;
extern f64 D_800D6708;
extern f64 D_800D6710;
extern u8 D_800E41F0;
extern s32 D_800E41F4;
extern char D_800E41F8[];
extern char D_800E4210[];
extern s8 D_800E4214;
extern s32 (*D_8010017C)(s32, s32);
extern u8 D_8010086C;
extern s32 D_80103EB4;

void func_800895F8(s32 arg0, s32 arg1, s32 arg2) {
    f32 temp_fv1;
    f32 var_fv0;
    f32 var_fv1;
    f64 var_ft0;
    f64 var_ft0_2;
    f64 var_ft0_3;
    s32 temp_lo;
    s32 var_a0;
    s32 var_v0;
    s32 var_v1;

    if (D_8010086C == 0) {
        var_ft0 = (f64) arg1;
        var_a0 = arg0 & 0xFFFF;
        if (arg1 < 0) {
            var_ft0 += D_800D6700;
        }
        var_fv1 = (f32) var_ft0 * 0.000125f;
        if (var_fv1 >= 2.1474836e9f) {
            var_fv0 = var_fv1 - 2.1474836e9f;
            goto block_11;
        }
        goto block_10;
    }
    var_ft0_2 = (f64) arg1;
    var_a0 = arg0 & 0xFFFF;
    if (arg1 < 0) {
        var_ft0_2 += D_800D6708;
    }
    var_fv1 = (f32) var_ft0_2 * 0.00025f;
    if (var_fv1 < 2.1474836e9f) {
block_10:
        var_v0 = (s32) var_fv1 & 0xFFFF;
    } else {
        var_fv0 = var_fv1 - 2.1474836e9f;
block_11:
        var_v0 = ((s32) var_fv0 | 0x80000000) & 0xFFFF;
    }
    (*(u16 *)&D_800E41F0) = var_a0 * (var_v0 + 1);
    temp_lo = D_800E41F0 * 0x310;
    D_800E41F4 = 0x310;
    var_ft0_3 = (f64) temp_lo;
    if (temp_lo < 0) {
        var_ft0_3 += D_800D6710;
    }
    temp_fv1 = (f32) var_ft0_3 * 0.9f;
    if (temp_fv1 < 2.1474836e9f) {
        var_v1 = (s32) temp_fv1;
    } else {
        var_v1 = (s32) (temp_fv1 - 2.1474836e9f) | (s32) &D_8000003F;
    }
    D_800E41F4 = ((((u32) var_v1 >> 6) * 0x28) + 0xF) & 0xFFF0;
    D_80103EB4 = D_8010017C((*(u16 *)&D_800E41F0) * 0x18, 0);
    osCreateMesgQueue(D_800E41F8, D_800E4210, 1);
    D_800E4214 = 0;
    func_80089C10(D_800E41F0);
    func_80089E64((*(u16 *)(D_800CEED0 + ((arg2 & 0xFF) * 2)) * arg0) & 0xFFFF);
}
