/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern s32 (*D_800D941C)(f32, void *, void *, void *);

void func_80005D04(s32 *arg0, s32 *arg1, void *arg2, f32 arg3) {
    register f32 temp_ft0;
    f32 temp_ft2;
    f32 temp_ft0_2;
    f32 temp_ft1;
    s32 temp_s6;
    register s32 temp_a0;
    s32 temp_a2;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_ft3;
    char *var_v1;
    s32 temp_a3_2;
    s32 temp_a1;
    f32 temp_fv0;
    register long temp_a3;
    s32 temp_v0;
    s32 temp_s2;
    char *var_a1;
    register f32 temp_fv0_2;
s32 __repair_phase_temp_v0;
    
    s32 var_s0;
    int var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_t2;
    u32 temp_v1;
    u32 temp_v1_2;
    void *var_a0;

    temp_v0 = *arg1;
    temp_s2 = temp_v0 >> 0x10;
    *arg0 = temp_v0;
    if (temp_v0 & 2) {
        var_t2 = temp_s2 * 3;
    } else {
        var_t2 = 3;
    }
    var_s1 = 0;
    temp_s6 = var_t2 + temp_s2;
    if (0 < var_t2) {
        register var_a1 = arg0;
        var_a0 = arg2;
        var_v1 = arg1;
        __repair_rows: {
            temp_ft3 = (*(f32 *)((char *)(var_v1) + 8));
            temp_ft2 = (*(f32 *)((char *)(var_v1) + 0xC));
            temp_ft1 = (*(f32 *)((char *)(var_v1) + 0x10));
            temp_ft0 = (((*(f32 *)((char *)(var_a0) + 8)) - temp_ft3) * arg3) + temp_ft3;
            temp_fv0 = ((*(f32 *)((char *)(var_a0) + 0x10)) - temp_ft1) * arg3;
            temp_fv1 = (((*(f32 *)((char *)(var_a0) + 0xC)) - temp_ft2) * arg3) + temp_ft2;
            var_a0 += 0xC;
            var_s1 += 3;
            var_v1 += 0xC;
            (*(f32 *)((char *)(var_a1) + 8)) = temp_ft0;
            (*(f32 *)((char *)(var_a1) + 0x10)) = (f32) (temp_fv0 + temp_ft1);
            (*(f32 *)((char *)(var_a1) + 0xC)) = temp_fv1;
            var_a1 += 0xC;
        }
if (var_s1 < var_t2) goto __repair_rows;
    }
    var_s1_2 = 0;
    if (temp_s2 > 0) {
        do {
            temp_a0 = (var_s1_2 + var_t2) * 4;
            temp_v1 = (*(u32 *)((char *)((temp_a0 + arg1)) + 8));
            temp_v1_2 = (*(u32 *)((char *)((temp_a0 + arg2)) + 8));
            temp_a1 = (temp_v1 >> 0x16) * 4;
            temp_ft0_2 = (f32) ((s32) ((((temp_v1_2 >> 0x16) * 4) - temp_a1) << 0x14) >> 0x14) * arg3;
            temp_a2 = (temp_v1 >> 0xA) & 0xFFE;
            temp_a3 = (temp_v1 * 2) & 0xFFE;
            temp_fv1_2 = (f32) ((s32) ((((temp_v1_2 >> 0xA) & 0xFFE) - temp_a2) << 0x14) >> 0x14) * arg3;
            temp_fv0_2 = (f32) ((s32) ((((temp_v1_2 * 2) & 0xFFE) - temp_a3) << 0x14) >> 0x14) * arg3;
            var_s1_2++;
            (*(s32 *)((char *)((temp_a0 + arg0)) + 8)) = (s32) (((s32) (((s32) temp_fv0_2 + temp_a3) & 0xFFE) >> 1) | ((((s32) temp_fv1_2 + temp_a2) & 0xFFE) << 0xA) | (((s32) ((s32) temp_ft0_2 + temp_a1) >> 2) << 0x16));
        } while (temp_s2 > var_s1_2);
    }
    if ((*arg1) & 1) {
        register var_s1_3 = 0;
        if (temp_s2 > 0) {
            var_s0 = 2;
            temp_a0 = (var_t2 + temp_s2) + 2;
            do {
                var_s1_3 += 1;
                var_s0 += 4;
                __repair_phase_temp_v0 = temp_a0 * 4;
                D_800D941C(arg3, arg1 + __repair_phase_temp_v0, arg2 + __repair_phase_temp_v0, arg0 + __repair_phase_temp_v0);
                temp_a0 = temp_s6 + var_s0;
            } while (var_s1_3 < temp_s2);
        }
    }
}
