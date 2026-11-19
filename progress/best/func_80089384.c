/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 bzero();
s32 func_800A0220();
extern char D_80000001[];
extern f64 D_800D66F0;
extern f64 D_800D66F8;
extern s32 D_800E41DC;
extern s32 D_800E41E0;
extern u16 D_800E41E4;
extern s8 D_800E41E6;
extern u16 D_800E4216;
extern s32 D_800E4220;
extern s32 D_800E4224;
extern s16 D_800E4228;
extern s16 D_800E422A;
extern s32 D_800E422C;
extern s32 (*D_8010017C)(s32, s32);
extern u8 D_8010086C;

void func_80089384(u16 arg0, s32 arg1) {
    f32 var_fv0;
    f32 var_fv1;
    f64 var_ft0;
    f64 var_ft0_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a1;
    s32 var_v0;
    u16 var_v0_2;

    D_800E41E4 = arg0;
    temp_v0 = D_8010017C((arg0 & 0xFFFF) * 0x68, 0);
    D_800E41E0 = temp_v0;
    D_800E41DC = temp_v0;
    D_800E41E6 = 0;
    var_a1 = 0;
    if (D_800E41E4 != 0) {
        var_v0 = 0 & 0xFFFF;
        do {
            temp_v1 = var_v0 * 0x68;
            *(s32 *)((unsigned short)temp_v1 + D_800E41E0) = 0;
            (*(s8 *)((char *)((temp_v1 + D_800E41E0)) + 0x61)) = 0;
            (*(u8 *)((char *)(((u32)temp_v1 + D_800E41E0)) + 0x60)) = 0xFF;
            var_a1 += 1;
            temp_v1 = var_a1 & 0xFFFF;
    var_v0 = temp_v1;
        } while ((u32) (var_a1 & 0xFFFF) < (u16) D_800E41E4);
    }
    if (!D_8010086C) {
        var_ft0 = (f64) arg1;
        if (arg1 < 0) {
            var_ft0 += D_800D66F0;
        }
        var_fv1 = (f32) var_ft0 * 0.000125f;
        if (var_fv1 >= 2.1474836e9f) {
            var_fv0 = var_fv1 - 2.1474836e9f;
            goto block_14;
        }
        goto block_13;
    }
    var_ft0_2 = (f64) arg1;
    if (arg1 < 0) {
        var_ft0_2 += D_800D66F8;
    }
    var_fv1 = (f32) var_ft0_2 * 0.00025f;
    if (var_fv1 < 2.1474836e9f) {
block_13:
        var_v0_2 = (s32) var_fv1 + 1;
    } else {
        var_fv0 = var_fv1 - 2.1474836e9f;
block_14:
        var_v0_2 = (s32) var_fv0 | (s32) &D_80000001;
    }
    D_800E4216 = var_v0_2;
    D_800E4220 = D_8010017C(D_800E4216 * 0xA10, 0);
    D_800E4224 = D_8010017C(D_800E4216 * 0xA10, 0);
    D_800E422A = 0;
    D_800E4228 = 0;
    temp_v0_2 = D_8010017C(0x298, 0);
    D_800E422C = temp_v0_2;
    bzero(temp_v0_2, 0x298);
    func_800A0220(D_800E422C, 0x298);
}
