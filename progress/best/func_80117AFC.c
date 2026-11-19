f32 func_80045E34(s32 *, s32);
extern s32 D_8011F068;
extern u32 D_8011F06C;

u32 func_80117AFC(void *arg0) {
    s32 sp10;
    f32 sp14;
    s32 sp18;
    f32 temp_fv0;
    f32 var_fs0;
    s32 var_s1;
    u32 var_s0;
    u32 var_s3;

    var_fs0 = 65536.0f;
    var_s0 = 0;
    var_s3 = 0;
    if (D_8011F06C != 0) {
        var_s1 = 0;
        do {
            sp10 = *(s32 *)((u8 *)arg0 + 0x24);
            sp14 = *(f32 *)((u8 *)arg0 + 0x28);
            sp18 = *(s32 *)((u8 *)arg0 + 0x2C);
            if ((u32)(*(u16 *)((u8 *)arg0 + 0x78) - 2) < 2U) {
                sp14 -= *(f32 *)(*(u8 **)((u8 *)arg0 + 0x68) + 0x38);
            }
            temp_fv0 = func_80045E34(&sp10, *(s32 *)(var_s1 + D_8011F068 + 0x10));
            if (temp_fv0 < var_fs0) {
                var_fs0 = temp_fv0;
                var_s3 = var_s0;
            }
            var_s0 += 1;
            var_s1 += 0x58;
        } while (var_s0 < D_8011F06C);
    }
    return var_s3;
}
