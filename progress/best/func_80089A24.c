/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f64 func_8008CD54();
extern f64 D_800D6720;
extern f64 D_800D6728;
extern f64 D_800D6730;
extern f64 D_800D6738;
extern f64 D_800D6740;
extern f64 D_800D6748;
extern f64 D_800D6750;
extern f64 D_800D6758;

void func_80089A24(void *arg0, s32 arg1) {
    f64 temp_fa0;
    f64 temp_fs1;
    f64 temp_fs1_2;
    f64 temp_ft0;
    f64 temp_ft0_2;
    f64 temp_fv0;
    f64 var_fs0;
    f64 var_fv1;
    f64 var_fv1_2;
    register f64 var_fv1_3;
    f64 var_fv1_4;
    f64 var_fv1_5;
    f64 var_fv1_6;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    u32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 temp_v1_2;

    temp_a1 = arg1 & 0xFFFF;
    temp_v1 = (*(s32 *)((char *)(arg0) + 0x38));
    temp_fs1 = (f64) ((*(u16 *)((char *)(arg0) + 4)) * temp_a1) * D_800D6720;
    if ((temp_v1 != 0) && (((*(u8 *)((char *)(arg0) + 1)) != 0) || ((*(s32 *)((char *)(arg0) + 0x3C)) == 0))) {
        temp_v0 = (*(s32 *)((char *)(arg0) + 0x34)) + temp_v1;
        var_fs0 = (f64) temp_v0;
        if (temp_v0 < 0) {
            var_fs0 += D_800D6728;
        }
        if (func_8008CD54((*(f64 *)((char *)(arg0) + 8))) <= var_fs0) {
            temp_v1_2 = (*(s32 *)((char *)(arg0) + 0x38));
            temp_v0_2 = (*(s32 *)((char *)(arg0) + 0x34)); temp_v0_2 += temp_v1_2;
            var_fv1 = (f64) temp_v0_2;
            if (temp_v0_2 < 0) {
                var_fv1 += D_800D6730;
            }
            temp_ft0 = (*(f64 *)((char *)(arg0) + 8));
            temp_fv0 = temp_ft0 + temp_fs1;
            if (!(temp_fv0 < var_fv1)) {
                var_fv1_2 = (f64) temp_v1_2;
                temp_fs1_2 = temp_fs1 - (var_fv1 - temp_ft0);
                if (temp_v1_2 < 0) {
                    var_fv1_2 += D_800D6738;
                }
                temp_v0_3 = (*(s32 *)((char *)(arg0) + 0x38));
                var_fv1_3 = (f64) temp_v0_3;
                temp_ft0_2 = func_8008CD54(temp_fs1_2 / var_fv1_2);
                if (temp_v0_3 < 0) {
                    var_fv1_3 += D_800D6740;
                }
                temp_v0_4 = (*(s32 *)((char *)(arg0) + 0x34));
                var_fv1_4 = (f64) temp_v0_4;
                if (temp_v0_4 < 0) {
                    var_fv1_4 += D_800D6748;
                }
                (*(f64 *)((char *)(arg0) + 8)) = (f64) (var_fv1_4 + (temp_fs1_2 - (temp_ft0_2 * var_fv1_3)));
                return;
            }
            (*(f64 *)((char *)(arg0) + 8)) = temp_fv0;
            return;
        }
        goto block_19;
    }
block_19:
    temp_v0_5 = (*(s32 *)((char *)(arg0) + 0x30));
    var_fv1_5 = (f64) temp_v0_5;
    temp_fa0 = (*(f64 *)((char *)(arg0) + 8)) + temp_fs1;
    if (temp_v0_5 < 0) {
        var_fv1_5 += D_800D6750;
    }
    temp_v0_6 = temp_v0_5 - 1;
    if (var_fv1_5 <= temp_fa0) {
        var_fv1_6 = (f64) temp_v0_6;
        if (temp_v0_6 < 0) {
            var_fv1_6 += D_800D6758;
        }
        (*(f64 *)((char *)(arg0) + 8)) = var_fv1_6;
        return;
    }
    (*(f64 *)((char *)(arg0) + 8)) = temp_fa0;
}
