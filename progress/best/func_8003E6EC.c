
s32 func_8003D64C(f32 *, void *);
s32 func_8004886C(void *, f32 *, s32);
s32 func_8004E6E4(s32 *, void *, f32 *, s32 *, s32 *, f32, s32, s32, s32);
s32 func_80082FE4(s16 *, s32 *);
s32 func_80083A6C(s32 *, f32 *);
extern s32 D_800D2FC8;
extern s32 D_800D2FD4;
extern s32 func_8004DBD8;

s32 func_8003E6EC(void *arg0, void *arg1, u8 arg2) {
    s32 *__base_D_800D2FC8;
    s16 sp28[3];
    u8 sp30[0x64];
    s32 sp70[3];
    f32 sp60[3];
    s32 sp80[3];
    f32 sp90[3];
    f32 sp94;
    s32 spB0[18];
    u8 spA7;
    s32 *spAC;
    f32 temp_fv0;
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fv1;
    void *temp_v0;
    register void *temp_v0_2;
    void *temp_v0_3;
    register void *temp_v0_4;
    void *temp_v0_5;
    register void *var_s1;
    void *var_s3;
    void *var_s4;

    var_fs0 = 65536.0f;
    var_s3 = NULL;
    temp_v0 = (*(void **)((char *)(arg1) + 0x70));
    var_s4 = NULL;
    var_s1 = arg0;
    spA7 = arg2;
    var_fs1 = 65536.0f;
    if (temp_v0 != NULL) {
        sp60[0] = ((*(f32 *)((char *)(temp_v0) + 0x18)) + (*(f32 *)((char *)(temp_v0) + 0x1C))) * 0.5f;
        temp_v0_2 = (*(void **)((char *)(arg1) + 0x70));
        sp60[1] = ((*(f32 *)((char *)(temp_v0_2) + 0x20)) + (*(f32 *)((char *)(temp_v0_2) + 0x24))) * 0.5f;
        temp_v0_3 = (*(void **)((char *)(arg1) + 0x70));
        sp60[2] = ((*(f32 *)((char *)(temp_v0_3) + 0x28)) + (*(f32 *)((char *)(temp_v0_3) + 0x2C))) * 0.5f;
        sp28[0] = (s16) (s32) (*(f32 *)((char *)(arg1) + 0x3C));
        sp28[1] = (s16) (s32) (*(f32 *)((char *)(arg1) + 0x40));
        sp28[2] = (s16) (s32) (*(f32 *)((char *)(arg1) + 0x44));
        { func_80082FE4(sp28, sp30); }
        do { func_80083A6C(sp30, sp60); } while (0);
        sp60[0] += (*(f32 *)((char *)(arg1) + 0x24));
        sp60[1] += (*(f32 *)((char *)(arg1) + 0x28));
        sp60[2] = sp60[2] + (*(f32 *)((char *)(arg1) + 0x2C));
    } else {
        sp60[0] = (*(f32 *)((char *)(arg1) + 0x24));
        sp60[1] = (*(f32 *)((char *)(arg1) + 0x28));
        sp60[2] = (*(f32 *)((char *)(arg1) + 0x2C));
    }
    if (var_s1 != NULL) {
        spAC = sp70;
        do {
            if (((*(u16 *)((char *)(var_s1) + 0x58)) == 0x46) && ((func_8004886C(var_s1 + 0x40, sp60, (*(s32 *)((char *)(arg1) + 0x64))) << 0x18) != 0) && ((func_8003D64C(sp60, var_s1) << 0x18) != 0)) {
                __base_D_800D2FC8 = &D_800D2FC8;
                sp70[0] = (*(s32 *)((char *)(__base_D_800D2FC8) + 0));
                sp70[1] = (*(s32 *)((char *)(__base_D_800D2FC8) + 4));
                sp70[2] = (*(s32 *)((char *)(__base_D_800D2FC8) + 8));
                sp80[0] = (*(s32 *)((char *)(&D_800D2FD4) + 0));
                sp80[1] = (*(s32 *)((char *)(&D_800D2FD4) + 4));
                sp80[2] = (*(s32 *)((char *)(&D_800D2FD4) + 8));
                temp_fv0 = (*(f32 *)((char *)(var_s1) + 0x4C));
                if (temp_fv0 < var_fs1) {
                    var_s4 = var_s1;
                    var_fs1 = temp_fv0;
                }
                if ((func_8004E6E4(&func_8004DBD8, var_s1, sp60, spAC, &sp90, 256.0f, 0, 1, 0) << 0x18) != 0) {
                    var_fv1 = sp94 - sp60[1];
                    goto block_14;
                }
                if ((func_8004E6E4(&func_8004DBD8, var_s1, sp60, sp80, &sp90, 256.0f, 0, 1, 0) << 0x18) != 0) {
                    var_fv1 = sp60[1] - sp94;
block_14:
                    if (var_fv1 < var_fs0) {
                        var_s3 = var_s1;
                        var_fs0 = var_fv1;
                    }
                }
            }
            var_s1 = (*(void **)((char *)(var_s1) + 0x10));
        } while (var_s1 != NULL);
    }
    if (var_s3 != NULL) {
        temp_v0_4 = (*(void **)((char *)(var_s3) + 0));
        if (temp_v0_4 != NULL) {
            (*(void **)((char *)(temp_v0_4) + 4)) = arg1;
        }
        (*(void **)((char *)(arg1) + 0)) = (void *) (*(void **)((char *)(var_s3) + 0));
        (*(void **)((char *)(arg1) + 4)) = var_s3;
        (*(void **)((char *)(var_s3) + 0)) = arg1;
        (*(s32 *)((char *)(var_s3) + 4)) = 0;
        (*(void **)((char *)(arg1) + 0x20)) = var_s3;
        return 1;
    }
    if (var_s4 != NULL) {
        temp_v0_5 = (*(void **)((char *)(var_s4) + 0));
        if (temp_v0_5 != NULL) {
            (*(void **)((char *)(temp_v0_5) + 4)) = arg1;
        }
        (*(void **)((char *)(arg1) + 0)) = (void *) (*(void **)((char *)(var_s4) + 0));
        (*(void **)((char *)(arg1) + 4)) = var_s4;
        (*(void **)((char *)(var_s4) + 0)) = arg1;
        (*(s32 *)((char *)(var_s4) + 4)) = 0;
        (*(void **)((char *)(arg1) + 0x20)) = var_s4;
        return 1;
    }
    if ((spA7 << 0x18) != 0) {
        (*(s32 *)((char *)(arg1) + 0x60)) = (s32) ((*(s32 *)((char *)(arg1) + 0x60)) | 1);
    }
    return 0;
}
