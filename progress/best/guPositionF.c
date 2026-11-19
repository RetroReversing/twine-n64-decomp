/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f32 __cosf();
f32 __sinf();
extern f32 D_800CFDE0;

void guPositionF(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 temp_fa1;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs1;
    f32 temp_fs1_2;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 temp_fs5;
    f32 temp_ft0;
    register f32 temp_ft0_2;
    f32 temp_ft1;
    f32 temp_ft2;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_s1;

    temp_fs0 = arg1 * D_800CFDE0;
    temp_fs1 = arg2 * D_800CFDE0;
    temp_fs2 = arg3 * D_800CFDE0;
    temp_s1 = __sinf(temp_fs0);
    temp_fs3 = __cosf(temp_fs0);
    temp_fs0_2 = __sinf(temp_fs1);
    temp_fs5 = __cosf(temp_fs1);
    temp_fs1_2 = __sinf(temp_fs2);
    temp_fv0 = __cosf(temp_fs2);
    temp_ft0 = temp_s1 * temp_fs0_2;
    temp_fs0_3 = temp_fs3 * temp_fs0_2;
    temp_fa1 = temp_fs5 * temp_fv0 * arg4;
    temp_ft0_2 = (temp_ft0 * temp_fs1_2) + (temp_fs3 * temp_fv0);
    temp_ft1 = temp_fs0_3 * temp_fv0;
    temp_ft5 = temp_s1 * temp_fv0;
    temp_ft2 = ((temp_ft0 * temp_fv0) - (temp_fs3 * temp_fs1_2)) * arg4;
    (*(s32 *)((char *)(arg0) + 0xC)) = 0;
    (*(s32 *)((char *)(arg0) + 0x1C)) = 0;
    (*(s32 *)((char *)(arg0) + 0x2C)) = 0;
    (*(f32 *)((char *)(arg0) + 0x30)) = arg5;
    (*(f32 *)((char *)(arg0) + 0x34)) = arg6;
    (*(f32 *)((char *)(arg0) + 0x38)) = arg7;
    (*(f32 *)((char *)(arg0) + 0x3C)) = 1.0f;
    (*(f32 *)((char *)(arg0) + 8)) = (f32) (-temp_fs0_2 * arg4);
    (*(f32 *)((char *)(arg0) + 0)) = temp_fa1;
    (*(f32 *)((char *)(arg0) + 4)) = (f32) (temp_fs5 * temp_fs1_2 * arg4);
    (*(f32 *)((char *)(arg0) + 0x18)) = (f32) (temp_s1 * temp_fs5 * arg4);
    (*(f32 *)((char *)(arg0) + 0x28)) = (f32) (temp_fs3 * temp_fs5 * arg4);
    (*(f32 *)((char *)(arg0) + 0x20)) = (f32) ((temp_ft1 + (temp_s1 * temp_fs1_2)) * arg4);
    (*(f32 *)((char *)(arg0) + 0x14)) = (f32) (temp_ft0_2 * arg4);
    (*(f32 *)((char *)(arg0) + 0x10)) = temp_ft2;
    (*(f32 *)((char *)(arg0) + 0x24)) = (f32) (((temp_fs0_3 * temp_fs1_2) - temp_ft5) * arg4);
}
