/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_8003C8F8(void *);                        /* extern */
s32 func_8003D53C(f32, f32,f32);               /* extern */
s32 func_8003D57C(void *, void *);                  /* extern */
s32 func_8003D778(void *, void *, f32);         /* extern */
s32 func_8003DA68(void *, void *, void *, void *, void *); /* extern */
f32 func_80045540(void *, void *);                  /* extern */

void func_8003CEF8(void *arg0) {
    f32 temp_fs0;
    f32 temp_fv0;
    f32 var_fv1;
    f32 var_fs1;
    f32 temp_fv0_2;
    s32 var_s1;
    u16 temp_a0;
    u16 temp_v0_2;
    
    u32 var_s0_2;
    void *temp_a3;
    union { void * pointer; u32 value; } __repair_phase_storage;
    void *temp_s5;
    void *temp_v0;
    void *temp_v1;
    void *var_s2;
    void *var_s3;
    void *var_s4;
    void *var_v1;

    var_s3 = arg0;
    temp_s5 = var_s3;
    if (var_s3 != NULL) {
        __repair_rows: {
            if ((*(u16 *)((char *)(var_s3) + 0x58)) == 0x46) {
                var_s2 = (*(void **)((char *)(var_s3) + 0x10));
                if (var_s2 != NULL) {
                    do {
                        if (((*(u16 *)((char *)(var_s2) + 0x58)) == 0x46) && (func_80045540(var_s3 + 0x40, var_s2 + 0x40) < ((*(f32 *)((char *)(var_s3) + 0x4C)) + (*(f32 *)((char *)(var_s2) + 0x4C))))) {
                            var_s4 = temp_s5;
                            if (var_s4 != NULL) {
                                do {
                                    temp_a0 = (*(u16 *)((char *)(var_s4) + 0x58));
                                    __repair_phase_storage.pointer = var_s4 + 0x40;
                                    if (((((temp_a0 == 0x1E) | (temp_a0 == 0x84)) != 0) || (temp_a0 == 0x88)) && ((func_8003D778(__repair_phase_storage.pointer, var_s3, 1.0f) << 0x18) != 0) && ((func_8003D778(__repair_phase_storage.pointer, var_s2, 1.0f) << 0x18) != 0) && ((func_8003D57C(var_s4, var_s3) << 0x18) != 0) && ((func_8003D57C(var_s4, var_s2) << 0x18) != 0) && (((*(void **)((char *)((*(void **)((char *)(var_s3) + 0x20))) + 0x58)) = func_8003C8F8((*(void **)((char *)((*(void **)((char *)(var_s3) + 0x20))) + 0x58))), (*(u8 *)((char *)((*(void **)((char *)((*(void **)((char *)(var_s3) + 0x20))) + 0x58))) + 0x28)) = (u8) (*(u8 *)((char *)(var_s4) + 0x54)), (*(u8 *)((char *)((*(void **)((char *)((*(void **)((char *)(var_s3) + 0x20))) + 0x58))) + 0x29)) = (u8) (*(u8 *)((char *)(var_s4) + 0x55)), (*(void **)((char *)((*(void **)((char *)((*(void **)((char *)(var_s3) + 0x20))) + 0x58))) + 4)) = var_s4, (*(void **)((char *)((*(void **)((char *)((*(void **)((char *)(var_s3) + 0x20))) + 0x58))) + 8)) = var_s2, (*(s16 *)((char *)((*(void **)((char *)((*(void **)((char *)(var_s3) + 0x20))) + 0x58))) + 0x26)) = (s16) (((u32) (*(u16 *)((char *)(var_s4) + 0x58)) >> 2) & 0x3FFF), temp_a3 = (*(void **)((char *)((*(void **)((char *)(var_s3) + 0x20))) + 0x58)), func_8003DA68(var_s4, var_s3, var_s2, temp_a3 + 0xC, temp_a3 + 0x18), (*(void **)((char *)((*(void **)((char *)(var_s2) + 0x20))) + 0x58)) = func_8003C8F8((*(void **)((char *)((*(void **)((char *)(var_s2) + 0x20))) + 0x58))), (*(u8 *)((char *)((*(void **)((char *)((*(void **)((char *)(var_s2) + 0x20))) + 0x58))) + 0x28)) = (u8) (*(u8 *)((char *)(var_s4) + 0x54)), (*(u8 *)((char *)((*(void **)((char *)((*(void **)((char *)(var_s2) + 0x20))) + 0x58))) + 0x29)) = (u8) (*(u8 *)((char *)(var_s4) + 0x55)), (*(void **)((char *)((*(void **)((char *)((*(void **)((char *)(var_s2) + 0x20))) + 0x58))) + 4)) = var_s4, (*(void **)((char *)((*(void **)((char *)((*(void **)((char *)(var_s2) + 0x20))) + 0x58))) + 8)) = var_s3, (*(s16 *)((char *)((*(void **)((char *)((*(void **)((char *)(var_s2) + 0x20))) + 0x58))) + 0x26)) = (s16) (((u32) (*(u16 *)((char *)(var_s4) + 0x58)) >> 2) & 0x3FFF), temp_v1 = (*(void **)((char *)((*(void **)((char *)(var_s2) + 0x20))) + 0x58)), (*(u16 *)((char *)((unsigned short)temp_v1) + 0x26)) = (u16) ((*(u16 *)((char *)(temp_v1) + 0x26)) & 0xF7FF), (*(f32 *)((char *)((*(void **)((char *)((*(void **)((char *)(var_s2) + 0x20))) + 0x58))) + 0xC)) = (f32) -(*(f32 *)((char *)((*(void **)((char *)((*(void **)((char *)(var_s3) + 0x20))) + 0x58))) + 0xC)), (*(f32 *)((char *)((*(void **)((char *)((*(void **)((char *)(var_s2) + 0x20))) + 0x58))) + 0x10)) = (f32) -(*(f32 *)((char *)((*(void **)((char *)((*(void **)((char *)(var_s3) + 0x20))) + 0x58))) + 0x10)), (*(f32 *)((char *)((*(void **)((char *)((*(void **)((char *)(var_s2) + 0x20))) + 0x58))) + 0x14)) = (f32) -(*(f32 *)((char *)((*(void **)((char *)((*(void **)((char *)(var_s3) + 0x20))) + 0x58))) + 0x14)), (*(f32 *)((char *)((*(void **)((char *)((*(void **)((char *)(var_s2) + 0x20))) + 0x58))) + 0x18)) = (f32) -(*(f32 *)((char *)((*(void **)((char *)((*(void **)((char *)(var_s3) + 0x20))) + 0x58))) + 0x18)), (*(void **)((char *)((*(void **)((char *)((*(void **)((char *)(var_s3) + 0x20))) + 0x58))) + 0x20)) = (void *) (*(void **)((char *)((*(void **)((char *)(var_s2) + 0x20))) + 0x58)), (*(void **)((char *)((*(void **)((char *)((*(void **)((char *)(var_s2) + 0x20))) + 0x58))) + 0x20)) = (void *) (*(void **)((char *)((*(void **)((char *)(var_s3) + 0x20))) + 0x58)), ((((u32) (*(u16 *)((char *)(var_s3) + 0x58)) >> 2) & 0x200) != 0)) || (((u32) (*(u16 *)((char *)(var_s2) + 0x58)) >> 2) & 0x200))) {
                                        temp_v0 = (*(void **)((char *)(var_s4) + 0x3C));
                                        var_v1 = (*(void **)((char *)(temp_v0) + 0x34));
                                        var_fs1 = (*(f32 *)((char *)(var_v1) + 4));
                                        temp_v0_2 = (*(u16 *)((char *)(temp_v0) + 0x42));
                                        __repair_phase_storage.value = 0;
                                        var_fv1 = var_fs1;
                                        if (temp_v0_2 != 0) {
                                            do {
                                                temp_fv0 = (*(f32 *)((char *)(var_v1) + 4));
                                                if (var_fv1 < temp_fv0) {
                                                    var_fv1 = temp_fv0;
                                                }
                                                if (var_fs1 > temp_fv0) {
                                                    var_fs1 = temp_fv0;
                                                }
                                                __repair_phase_storage.value += 1;
                                                var_v1 += 0xC;
                                            } while (__repair_phase_storage.value < temp_v0_2);
                                        }
                                        if (var_fv1 != var_fs1) {
                                            temp_fv0_2 = (*(f32 *)((char *)((*(void **)((char *)(var_s3) + 0x3C))) + 0x20));
                                            var_s0_2 = 0;
                                            temp_fs0 = temp_fv0_2 - (var_fv1 - temp_fv0_2);
                                            if ((*(u16 *)((char *)((*(void **)((char *)(var_s4) + 0x3C))) + 0x42)) != 0) {
                                                register var_s1 = 0;
                                                do {
                                                    if ((func_8003D53C((*(f32 *)((char *)((var_s1 + (*(s32 *)((char *)((*(void **)((char *)(var_s4) + 0x3C))) + 0x34)))) + 4)), var_fs1,0.1f) << 0x18) != 0) {
                                                        (*(f32 *)((char *)((var_s1 + (*(void **)((char *)((*(void **)((char *)(var_s4) + 0x3C))) + 0x34)))) + 4)) = temp_fs0;
                                                    }
                                                    var_s0_2 += 1;
                                                    var_s1 += 0xC;
                                                } while (var_s0_2 < (u16) (*(u16 *)((char *)((*(void **)((char *)(var_s4) + 0x3C))) + 0x42)));
                                            }
                                        }
                                    }
                                    var_s4 = (*(void **)((char *)(var_s4) + 0x10));
                                } while (var_s4 != NULL);
                            }
                        }
                        var_s2 = (*(void **)((char *)(var_s2) + 0x10));
                    } while (var_s2 != NULL);
                }
            }
            var_s3 = (*(void **)((char *)(var_s3) + 0x10));
        }
if (var_s3 != NULL) goto __repair_rows;
    }
}
