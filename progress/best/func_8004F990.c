f32 func_80045540(s32 *, void *);
s32 func_800455CC(f32 *, void *, f32 *, void *);
f32 func_80045764(f32 *, f32 *);
f32 func_80045E34(void *, void *);
s32 func_80047998(f32, f32, s32 *, void *, void *, f32 *, f32 *, f32 *, f32, f32);
extern s32 D_800C42B0;
extern s8 D_800C42B1;
extern s8 D_800C42B2;
extern f32 D_800C42B4;
extern s32 D_800D3E50;
extern f64 D_800D3E60;
extern void *D_80108788;
extern f32 D_80108F78;
extern s32 D_80108F84;

void *func_8004F990(void **arg0, void *arg1, f32 *arg2, s32 arg3, void *arg4, u8 arg5, u8 arg6, s32 arg7) {
    f32 sp50[3];
    f32 sp20[3];
    f32 sp60[3];
    f32 sp70[3];
    f32 sp30[3];
    s32 sp40[3];
    s32 sp80[3];
    s32 sp90;
    register void *var_s6;
    s32 spC4;
    f32 var_fs2;
    void *var_s0;
    s32 i;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    f32 var_fs1;
f32 __repair_var_fs1_1;
    f32 temp_fs0;
    f32 temp_fv1;
    f32 temp_ft0;
    f32 temp_fv0_2;
    f32 d;
    f32 temp_fv0_4;

    var_s6 = NULL;
    var_fs2 = 65536.0f;
    spC4 = 0;
    sp20[0] = arg2[0] - ((f32 *)arg1)[0];
    sp20[1] = arg2[1] - ((f32 *)arg1)[1];
    sp20[2] = arg2[2] - ((f32 *)arg1)[2];
    func_80045764(sp20, sp20);
    D_80108F84 = 0;
    D_80108788 = NULL;
    if (arg0 != NULL) {
        var_s0 = *arg0;
        while (var_s0 != NULL) {
            if ((var_s0 != (void *)arg7) && (((s32 *)var_s0)[0x58 / 4] & 0x400)) {
                s32 f5c = ((s32 *)var_s0)[0x5C / 4];
                if ((f5c & 0x400) && (f5c & arg3)) {
                    var_fs1 = 1.5f;
                    if ((D_80108F78 == 0x19) && (*(u16 *)((u8 *)var_s0 + 0x78) == 1)) {
                        __repair_var_fs1_1 = 2.5f;
                    }
                }
            }
            var_s0 = *(void **)var_s0;
        }
    }
    return var_s6;
}
