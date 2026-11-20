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
    u32 i;

    D_800E41E4 = arg0;
    temp_v0 = D_8010017C((arg0 & 0xFFFF) * 0x68, 0);
    D_800E41E0 = temp_v0;
    D_800E41DC = temp_v0;
    D_800E41E6 = 0;
    i = 0;
    if (D_800E41E4 != 0) {
        do {
            *(s8 *)(D_800E41E0 + ((i & 0xFFFF) * 0x68)) = 0;
            *(s8 *)(D_800E41E0 + ((i & 0xFFFF) * 0x68) + 0x61) = 0;
            *(u8 *)(D_800E41E0 + ((i & 0xFFFF) * 0x68) + 0x60) = 0xFF;
            i += 1;
        } while ((i & 0xFFFF) < D_800E41E4);
    }
    if (D_8010086C == 0) {
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
    if (var_fv1 <= 2.1474836e9f) {
block_13:
        D_800E4216 = (s32) var_fv1 + 1;
    } else {
        var_fv0 = var_fv1 - 2.1474836e9f;
block_14:
        D_800E4216 = (s32) var_fv0 | (s32) &D_80000001;
    }
    D_800E4220 = D_8010017C(D_800E4216 * 0xA10, 0);
    D_800E4224 = D_8010017C(D_800E4216 * 0xA10, 0);
    D_800E422A = 0;
    D_800E4228 = 0;
    temp_v0_2 = D_8010017C(0x298, 0);
    D_800E422C = temp_v0_2;
    bzero(temp_v0_2, 0x298);
    func_800A0220(D_800E422C, 0x298);
}
