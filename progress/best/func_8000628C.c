/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f32 func_80046140(f32, f32);
f32 func_80082A70(f32, f32);
extern u8 D_800CA338;

typedef struct { unsigned char pad_0[20]; int field_14; unsigned char pad_18[124]; short field_94; unsigned char pad_96[2]; short field_98; } __repair_record_temp_a2;
static inline short __repair_store_halfword(int x){x=(unsigned int)x<<16;x=x>>16;return (u32)x;}

s16 func_8000628C(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    f32 temp_fs0;
    s16 var_v0_5;
    register f32 temp_fs2;
    f32 var_ft1;
    s16 temp_a0;
    f32 scale;
    s16 temp_a0_2;
    s16 temp_v1_3;
    register s16 var_v0_3;
    f32 temp_fs1;
    s32 var_a0;
    
    s32 var_a1;
    s32 var_s0;
    int var_v0;
    s32 var_v0_2;
    unsigned var_v0_4;
    s32 var_v1;
    u16 temp_v0_2;
    register u16 temp_v0_3;
    union { void * pointer; s32 value; } __repair_phase_storage;
    void *temp_s1;
    void *temp_v0;
    
    
    
    register void *temp_v1_5;
    void *temp_v1_6;

    __repair_phase_storage.pointer = (*(void **)((char *)(arg0) + 0x68));
    temp_s1 = (void *) ((0x14) + (s32) __repair_phase_storage.pointer);
    if (arg1 != NULL) {
        var_ft1 = 0.2f;
        ((__repair_record_temp_a2*)__repair_phase_storage.pointer)->field_14 |= 0x180000;
        if (D_800CA338) {
            var_ft1 = 0.0f;
        }
        temp_v0 = (*(void **)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0));
        temp_fs1 = (*(f32 *)((char *)(arg1) + 0)) - (*(f32 *)((char *)(temp_v0) + 0));
        temp_fs0 = (*(f32 *)((char *)(arg1) + 8)) - (*(f32 *)((char *)(temp_v0) + 8));
        temp_fs2 = ((*(f32 *)((char *)(arg1) + 4)) - (*(f32 *)((char *)(temp_v0) + 0xAC))) + var_ft1;
        scale = 651.8986f;
        var_s0 = (s32) ((f32) (s32) (func_80082A70(-temp_fs1, temp_fs0) * scale) + (*(f32 *)((char *)(arg0) + 0x40))) & 0xFFF;
        if (var_s0 >= 0x800) {
            var_s0 -= 0x1000;
        }
        var_a1 = (s32) (func_80082A70(temp_fs2, func_80046140(temp_fs1, temp_fs0)) * scale);
        var_v1 = arg2 * 2;
    } else {
        var_s0 = 0;
        var_a1 = 0;
        var_v1 = arg2 * 2;
    }
    __repair_phase_storage.pointer = (void *) ((var_v1) + (s32) temp_s1);
    var_a0 = (s32) (((u32)var_s0 - ((__repair_record_temp_a2*)__repair_phase_storage.pointer)->field_94) * arg3) >> 7;
    if (var_a0 < -0x40) {
        var_a0 = -0x40;
    } else if ((s32)var_a0 >= 0x41) {
        var_a0 = 0x40;
    }
    temp_v0 = (void *) (((arg2 * 2)) + (s32) temp_s1);
    temp_v0_2 = (*(u16 *)((char *)(temp_v0) + 0x94)) + var_a0;
    (*(u16 *)((char *)(temp_v0) + 0x94)) = __repair_store_halfword(temp_v0_2);
    if ((int)var_a0 >= 0) {
        var_v0_2 = var_s0 < (s16) temp_v0_2;
    } else {
        var_v0_2 = (s16) temp_v0_2 < var_s0;
    }
    if (var_v0_2) {
        (*(u16 *)((char *)(temp_v0) + 0x94)) = (u16) var_s0;
    }
    if (!arg2) {
        temp_v1_3 = (*(s16 *)((char *)(temp_s1) + 0x94));
        if (temp_v1_3 < -0x384) {
            (*(s16 *)((char *)(temp_s1) + 0x94)) = -0x384;
        } else if (0x385 <= temp_v1_3) {
            (*(s16 *)((char *)(temp_s1) + 0x94)) = 0x384;
        }
    } else {
        temp_v0 = (void *) (((arg2 * 2)) + (s32) temp_s1);
        temp_a0 = (*(s16 *)((char *)(temp_v0) + 0x94));
        var_v0_3 = -0x1C2;
        if ((temp_a0 < -0x1C2) || (var_v0_3 = 0x1C2, ((temp_a0 < 0x1C3) == 0))) {
            (*(s16 *)((char *)(temp_v0) + 0x94)) = var_v0_3;
        }
    }
    __repair_phase_storage.value = (s32) ((var_a1 - ((__repair_record_temp_a2*)__repair_phase_storage.pointer)->field_98) * arg3) >> 7;
    if (__repair_phase_storage.value < -0x40) {
        __repair_phase_storage.value = -0x40;
    } else if (__repair_phase_storage.value >= 0x41) {
        __repair_phase_storage.value = 0x40;
    }
    temp_v1_5 = (void *) (((arg2 * 2)) + temp_s1);
    temp_v0_3 = (*(u16 *)((char *)(temp_v1_5) + 0x98)) + __repair_phase_storage.value;
    (*(u16 *)((char *)(temp_v1_5) + 0x98)) = temp_v0_3;
    if (__repair_phase_storage.value >= 0) {
        var_v0_4 = var_a1 < (s16) temp_v0_3;
    } else {
        var_v0_4 = (s16) temp_v0_3 < var_a1;
    }
    if (var_v0_4 != 0) {
        (*(u16 *)((char *)(temp_v1_5) + 0x98)) = (u16) var_a1;
    }
    temp_v1_6 = (void *) (((arg2 * 2)) + (s32) temp_s1);
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
