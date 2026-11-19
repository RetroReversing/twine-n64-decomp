/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-schedule-insns, tried by autopilot */

s32 func_80083560(void *, void *);              /* extern */
s32 func_800839F0(void *, f32 *, void *, s32);       /* extern */
extern s32 (*D_800D9420)(s16 *, void *);

void func_80005868(s16 *arg0, void *arg1, void *arg2, s32 arg3) {
    f32 sp10[3];
    u8 sp28[0x930];
    s16 sp20[3];
    f32 var_ft0;
    f32 var_fv0;
    f32 var_fv1;
    s16 *var_s2;
    s32 var_s6;
    u32 temp_v1;
    void *temp_s0;
    void *temp_s1;
    void *var_s3;
    void *var_s5;

    var_s6 = 0;
    if (*arg0 >= 0) {
        var_s2 = arg0;
        var_s3 = arg2;
        var_s5 = arg1;
        __repair_rows: {
            temp_s1 = sp28 + ((*(s16 *)((char *)(var_s2) + 0)) * 0x30);
            temp_v1 = (*(u32 *)((char *)(var_s5) + 0x14));
            sp20[0] = ((u32)temp_v1 >> 0x16) * 4;
            sp20[1] = (temp_v1 >> 0xA) & 0xFFE;
            sp20[2] = (temp_v1 * 2) & 0xFFE;
            __repair_rows_: { D_800D9420(sp20, temp_s1); }
if (0) goto __repair_rows_;
            if (!var_s6) {
                var_fv1 = (*(f32 *)((char *)(arg1) + 8));
                var_ft0 = (*(f32 *)((char *)(arg1) + 0xC));
                var_fv0 = (*(f32 *)((char *)(arg1) + 0x10));
                if (arg3 == 0) {
                    var_fv0 = 0.0f;
                    var_ft0 = 0.0f;
                    var_fv1 = 0.0f;
                }
                (*(f32 *)((char *)(temp_s1) + 0x24)) = var_fv1;
                (*(f32 *)((char *)(temp_s1) + 0x28)) = var_ft0;
                (*(f32 *)((char *)(temp_s1) + 0x2C)) = var_fv0;
            } else {
                sp10[0] = (*(f32 *)((char *)(var_s2) + 4));
                sp10[1] = (*(f32 *)((char *)(var_s2) + 8));
                temp_s0 = sp28 + ((*(s16 *)((char *)(var_s2) + 2)) * 0x30);
                sp10[2] = (*(f32 *)((char *)(var_s2) + 0xC));
                func_800839F0(temp_s0, sp10, temp_s1 + 0x24, arg3);
                (*(f32 *)((char *)(temp_s1) + 0x24)) = (f32) ((*(f32 *)((char *)(temp_s1) + 0x24)) + (*(f32 *)((char *)(temp_s0) + 0x24)));
                (*(f32 *)((char *)(temp_s1) + 0x28)) = (f32) ((*(f32 *)((char *)(temp_s1) + 0x28)) + (*(f32 *)((char *)(temp_s0) + 0x28)));
                (*(f32 *)((char *)(temp_s1) + 0x2C)) = (f32) ((*(f32 *)((char *)(temp_s1) + 0x2C)) + (*(f32 *)((char *)(temp_s0) + 0x2C)));
                func_80083560(temp_s0, temp_s1);
            }
            var_s2 += 0x20;
            (*(f32 *)((char *)(var_s3) + 0)) = (f32) (*(f32 *)((char *)(temp_s1) + 0x24));
            (*(f32 *)((char *)(var_s3) + 4)) = (f32) (*(f32 *)((char *)(temp_s1) + 0x28));
            var_s6 += 1;
            var_s5 += 4;
            (*(f32 *)((char *)(var_s3) + 8)) = (f32) (*(f32 *)((char *)(temp_s1) + 0x2C));
            var_s3 += 0xC;
        }
if (*var_s2 >= 0) goto __repair_rows;
    }
}
