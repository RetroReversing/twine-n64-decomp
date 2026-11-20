f32 func_80082908(f32, f32 *, void *, s32);

void func_8003C94C(void *arg0, f32 *arg1, void *arg2, s32 arg3) {
    f32 *temp_s0;
    f32 *temp_v0;
    u16 temp_v1;
    f32 x2, y2, z2, length2;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 var_fs3;
    f32 var_fs4;
    f32 var_fs5;
    f32 var_ft0;
    f32 var_ft1;
    f32 var_ft2;
    u32 var_a3;
    f32 *var_a1;
    f32 *temp_v1_2;

    temp_s0 = arg1;
    var_a1 = temp_s0;
    var_a3 = arg3;
    if (arg0 == NULL) return;
    if (temp_s0 != NULL) {
        temp_v0 = *(f32 **)((char *)arg0 + 0x34);
        temp_v1 = *(u16 *)((char *)arg0 + 0x42);
        var_fs3 = temp_v0[0];
        var_fs4 = temp_v0[1];
        var_fs5 = temp_v0[2];
        var_ft2 = var_fs3;
        var_ft0 = var_fs4;
        var_ft1 = var_fs5;
        if (temp_v1) {
            var_a3 = 0;
            var_a1 = temp_v0;
            temp_v1_2 = (f32 *)(temp_v1 * 0xC + (u32)temp_v0);
            do {
                temp_fv0 = *var_a1;
                if (temp_fv0 < var_fs3) {
                    var_fs3 = temp_fv0;
                } else if (var_ft2 < temp_fv0) {
                    var_ft2 = temp_fv0;
                }
                temp_fv0_2 = *(f32 *)(var_a3 + *(u32 *)((char *)arg0 + 0x34) + 4);
                if (var_fs4 > temp_fv0_2) {
                    var_fs4 = temp_fv0_2;
                } else if (temp_fv0_2 > var_ft0) {
                    var_ft0 = temp_fv0_2;
                }
                temp_fv0_3 = *(f32 *)(var_a3 + *(u32 *)((char *)arg0 + 0x34) + 8);
                if (var_fs5 > temp_fv0_3) {
                    var_fs5 = temp_fv0_3;
                } else if (var_ft1 < temp_fv0_3) {
                    var_ft1 = temp_fv0_3;
                }
                var_a3 += 0xC;
                var_a1 += 3;
            } while ((s32)var_a1 < (s32)temp_v1_2);
        }
        temp_fs2 = var_ft2 - var_fs3;
        x2 = temp_fs2 * temp_fs2;
        temp_fs1 = var_ft0 - var_fs4;
        y2 = temp_fs1 * temp_fs1;
        temp_fs0 = var_ft1 - var_fs5;
        z2 = temp_fs0 * temp_fs0;
        length2 = x2 + y2;
        ((f32 *)arg2)[1] = var_ft2;
        do { } while (0);
        ((f32 *)arg2)[3] = var_ft0;
        ((f32 *)arg2)[5] = var_ft1;
        length2 += z2;
        ((f32 *)arg2)[0] = var_fs3;
        ((f32 *)arg2)[2] = var_fs4;
        ((f32 *)arg2)[4] = var_fs5;
        temp_s0[3] = func_80082908(length2, var_a1, arg2, var_a3) * 0.5f;
        temp_s0[0] = var_fs3 + (temp_fs2 * 0.5f);
        temp_s0[1] = var_fs4 + (temp_fs1 * 0.5f);
        temp_s0[2] = var_fs5 + (temp_fs0 * 0.5f);
    }
}

