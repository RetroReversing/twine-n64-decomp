/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f32 func_80046140(f32);
f32 func_80082A70();
extern u8 D_800CA338;

typedef struct { unsigned char pad_0[20]; int field_14; unsigned char pad_18[124]; short field_94; unsigned char pad_96[2]; short field_98; } __repair_record_temp_a2;
s16 func_8000628C(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    f32 temp_fs0;
    f32 temp_fs1;
    register f32 temp_fs2;
    f32 var_ft1;
    s16 temp_a0;
    s16 temp_a0_2;
    s16 temp_v1_3;
    register s16 var_v0_3;
    s16 var_v0_5;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_s0;
    long var_v0;
    s32 var_v0_2;
    s32 var_v0_4;
    s32 var_v1;
    u16 temp_v0_2;
    register u16 temp_v0_3;
    void *temp_a2;
    void *temp_s1;
    void *temp_v0;
    
    void *temp_v1_2;
    void *temp_v1_4;
    register void *temp_v1_5;
    void *temp_v1_6;

    temp_a2 = (*(void **)((char *)(arg0) + 0x68));
    temp_s1 = temp_a2 + 0x14;
    if (arg1 != NULL) {
        var_ft1 = 0.2f;
        ((__repair_record_temp_a2*)temp_a2)->field_14 |= 0x180000;
        if (D_800CA338 != 0) {
            var_ft1 = 0.0f;
        }
        temp_v0 = (*(void **)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0));
        temp_fs1 = (*(f32 *)((char *)(arg1) + 0)) - (*(f32 *)((char *)(temp_v0) + 0));
        temp_fs0 = (*(f32 *)((char *)(arg1) + 8)) - (*(f32 *)((char *)(temp_v0) + 8));
        temp_fs2 = ((*(f32 *)((char *)(arg1) + 4)) - (*(f32 *)((char *)(temp_v0) + 0xAC))) + var_ft1;
        var_s0 = (s32) ((f32) (s32) (func_80082A70(-temp_fs1, (s32)temp_fs0) * 651.8986f) + (*(f32 *)((char *)(arg0) + 0x40))) & 0xFFF;
        if (var_s0 >= 0x800) {
            var_s0 -= 0x1000;
        }
        var_a1 = (s32) (func_80082A70(temp_fs2, func_80046140(temp_fs1)) * 651.8986f);
        var_v1 = arg2 * 2;
    } else {
        var_s0 = 0;
        var_a1 = 0;
        var_v1 = arg2 * 2;
    }
    temp_a2 = var_v1 + temp_s1;
    var_a0 = (s32) ((var_s0 - ((__repair_record_temp_a2*)temp_a2)->field_94) * arg3) >> 7;
    if (var_a0 < -0x40) {
        var_a0 = -0x40;
    } else if (var_a0 >= 0x41) {
        var_a0 = 0x40;
    }
    temp_v1_2 = (arg2 * 2) + temp_s1;
    temp_v0_2 = (*(u16 *)((char *)(temp_v1_2) + 0x94)) + var_a0;
    (*(u16 *)((char *)(temp_v1_2) + 0x94)) = temp_v0_2;
    if (var_a0 >= 0) {
        var_v0_2 = var_s0 < (s16) temp_v0_2;
    } else {
        var_v0_2 = (s16) temp_v0_2 < var_s0;
    }
    if (var_v0_2) {
        (*(u16 *)((char *)(temp_v1_2) + 0x94)) = (u16) var_s0;
    }
    if (!arg2) {
        temp_v1_3 = (*(s16 *)((char *)(temp_s1) + 0x94));
        if (temp_v1_3 < -0x384) {
            (*(s16 *)((char *)(temp_s1) + 0x94)) = -0x384;
        } else if (temp_v1_3 >= 0x385) {
            (*(s16 *)((char *)(temp_s1) + 0x94)) = 0x384;
        }
    } else {
        temp_v1_4 = (arg2 * 2) + temp_s1;
        temp_a0 = (*(s16 *)((char *)(temp_v1_4) + 0x94));
        var_v0_3 = -0x1C2;
        if ((temp_a0 < -0x1C2) || (var_v0_3 = 0x1C2, ((temp_a0 < 0x1C3) == 0))) {
            (*(s16 *)((char *)(temp_v1_4) + 0x94)) = var_v0_3;
        }
    }
    var_a0_2 = (s32) ((var_a1 - ((__repair_record_temp_a2*)temp_a2)->field_98) * arg3) >> 7;
    if (var_a0_2 < -0x40) {
        var_a0_2 = -0x40;
    } else if (var_a0_2 >= 0x41) {
        var_a0_2 = 0x40;
    }
    temp_v1_5 = temp_s1 + (arg2 * 2);
    temp_v0_3 = (*(u16 *)((char *)(temp_v1_5) + 0x98)) + var_a0_2;
    (*(u16 *)((char *)(temp_v1_5) + 0x98)) = temp_v0_3;
    if (var_a0_2 >= 0) {
        var_v0_4 = var_a1 < (s16) temp_v0_3;
    } else {
        var_v0_4 = (s16) temp_v0_3 < var_a1;
    }
    if (var_v0_4 != 0) {
        (*(u16 *)((char *)(temp_v1_5) + 0x98)) = (u16) var_a1;
    }
    temp_v1_6 = temp_s1 + (arg2 * 2);
    temp_a0_2 = (*(s16 *)((char *)(temp_v1_6) + 0x98));
    var_v0_5 = -0x258;
    if (temp_a0_2 >= -0x258) {
        var_v0 = arg2 * 2;
        if (temp_a0_2 >= 0x259) {
            var_v0_5 = 0x258;
            (*(s16 *)((char *)(temp_v1_6) + 0x98)) = var_v0_5;
            var_v0 = arg2 * 2;
        }
    } else {
        (*(s16 *)((char *)(temp_v1_6) + 0x98)) = var_v0_5;
        var_v0 = arg2 * 2;
    }
    return (*(s16 *)((char *)((var_v0 + temp_s1)) + 0x94));
}
