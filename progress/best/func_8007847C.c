/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

f32 func_80045E34(void *, void *, void *);                  /* extern */
s32 func_80078114(void *, void *, void **, f32 *);  /* extern */
extern u16 D_800B35B0;
extern u16 D_80108F72;
extern void *D_8010A500;
extern f32 D_80117408;

void *func_8007847C(void *arg0) {
    void *sp10;
    f32 sp14;
    s32 temp_s6;
    s32 var_s3;
    
    s32 var_v0_3;
    s32 var_v1_3;
    u16 temp_t0;
    u8 temp_v1;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a1;
    void *temp_s0;
    void *temp_s5;
    void *temp_v1_2;
    void *temp_v1_3;
    void *var_s0;
    void *var_s2;
    void *var_s4;
    void *var_v0;
    void *var_v1;
    union { void * pointer; s32 value; } __repair_phase_storage;

    temp_s5 = M2C_FIELD(arg0, void **, 0x6C);
    sp10 = NULL;
    temp_v1 = M2C_FIELD(temp_s5, u8 *, 0x82);
    temp_s6 = M2C_FIELD(arg0, s32 *, 0x60);
    if (temp_v1 == 0x1E) {
        if ((D_80117408 <= (f32) M2C_FIELD(temp_s5, s16 *, 0x74)) && (var_v1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0), (var_v1 != NULL))) {
            for (;;) {
                if ((M2C_FIELD(var_v1, u16 *, 0x78) != 1) || (var_v0 = var_v1, ((M2C_FIELD(M2C_FIELD(var_v1, void **, 0x6C), s32 *, 0x88) & 0x01E00000) != 0x600000))) {
                    var_v1 = M2C_FIELD(var_v1, void **, 0);
                    if (var_v1 != NULL) {
                        continue;
                    }
                    goto block_49;
                }
                break;
            }
        } else {
            goto block_49;
        }
        /* Duplicate return node #50. Try simplifying control flow for better match */
        return var_v0;
    }
    if (temp_v1 == 0x1F) {
        __repair_phase_storage.pointer = M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), void **, 0);
        if (__repair_phase_storage.pointer != NULL) {
            for (;;) {
                if ((M2C_FIELD(__repair_phase_storage.pointer, u16 *, 0x78) != 1) || (var_v0 = __repair_phase_storage.pointer, ((M2C_FIELD(M2C_FIELD(__repair_phase_storage.pointer, void **, 0x6C), s32 *, 0x88) & 0x01E00000) != 0x800000))) {
                    __repair_phase_storage.pointer = M2C_FIELD(__repair_phase_storage.pointer, void **, 0);
                    if (__repair_phase_storage.pointer == NULL) {
                        return NULL;
                    }
                    continue;
                }
                break;
            }
            /* Duplicate return node #50. Try simplifying control flow for better match */
            return var_v0;
        }
        goto block_48;
    }
    if ((M2C_FIELD(temp_s5, s32 *, 0x88) & 0x01E00000) == 0x200000) {
        sp14 = func_80045E34(arg0, arg0 + 0x24, D_8010A500 + 0x24);
        sp10 = D_8010A500;
    } else {
        sp10 = NULL;
        sp14 = 65536.0f;
    }
    temp_t0 = D_800B35B0 + 1;
    D_800B35B0 = temp_t0;
    var_s3 = 0;
    if (D_80108F72 != 0) {
        temp_s0 = M2C_FIELD(arg0, void **, 0x20);
        M2C_FIELD(arg0, s32 *, 0x60) = (s32) (M2C_FIELD(arg0, s32 *, 0x60) & 0xFFFE8FFF);
        M2C_FIELD(M2C_FIELD(temp_s0, void **, 0x20), u16 *, 0x60) = temp_t0;
        if ((func_80078114(temp_s0, arg0, &sp10, &sp14) << 0x18) != 0) {
            var_s3 = 1;
            M2C_FIELD(arg0, s32 *, 0x60) = (s32) (M2C_FIELD(arg0, s32 *, 0x60) | 0x1000);
        }
        var_s4 = M2C_FIELD(M2C_FIELD(temp_s0, void **, 0x20), void **, 0x58);
        var_v1_3 = var_s3 ^ 1;
        while ((var_s4 != NULL) & var_v1_3) {
            if (M2C_FIELD(var_s4, u16 *, 0x26) & 0x2000) {
                            temp_a0 = M2C_FIELD(var_s4, void **, 8);
                            temp_v1_2 = M2C_FIELD(temp_a0, void **, 0x20);
                            var_s2 = M2C_FIELD(temp_v1_2, void **, 0x58);
                            if (M2C_FIELD(temp_v1_2, u16 *, 0x60) != D_800B35B0) {
                                M2C_FIELD(temp_v1_2, u16 *, 0x60) = (u16) D_800B35B0;
                                if ((func_80078114(temp_a0, arg0, &sp10, &sp14) << 0x18) != 0) {
                                    var_s3 = 1;
                                    M2C_FIELD(arg0, s32 *, 0x60) = (s32) (M2C_FIELD(arg0, s32 *, 0x60) | 0x2000);
                                }
                                __repair_phase_storage.value = var_s2 != NULL;
                                if (__repair_phase_storage.value & (var_s3 ^ 1)) {
                                    do {
                                        { {
                                                                    if (M2C_FIELD(var_s2, u16 *, 0x26) & 0x2000) {
                                                                        temp_a0_2 = M2C_FIELD(var_s2, void **, 8);
                                                                        temp_v1_3 = M2C_FIELD(temp_a0_2, void **, 0x20);
                                                                        var_s0 = M2C_FIELD(temp_v1_3, void **, 0x58);
                                                                        if (M2C_FIELD(temp_v1_3, u16 *, 0x60) != D_800B35B0) {
                                                                            M2C_FIELD(temp_v1_3, u16 *, 0x60) = (u16) D_800B35B0;
                                                                            if ((func_80078114(temp_a0_2, arg0, &sp10, &sp14) << 0x18) != 0) {
                                                                                var_s3 = 1;
                                                                                M2C_FIELD(arg0, s32 *, 0x60) = (s32) (M2C_FIELD(arg0, s32 *, 0x60) | 0x4000);
                                                                            }
                                                                            var_v0_3 = var_s0 != NULL;
                                                                            if (var_v0_3 & (var_s3 ^ 1)) {
                                                                                do {
                                                                                    if (M2C_FIELD(var_s0, u16 *, 0x26) & 0x2000) {
                                                                                        temp_a0_3 = M2C_FIELD(var_s0, void **, 8);
                                                                                        temp_a1 = M2C_FIELD(temp_a0_3, void **, 0x20);
                                                                                        if (M2C_FIELD(temp_a1, u16 *, 0x60) != D_800B35B0) {
                                                                                            M2C_FIELD(temp_a1, u16 *, 0x60) = (u16) D_800B35B0;
                                                                                            if ((func_80078114(temp_a0_3, arg0, &sp10, &sp14) << 0x18) != 0) {
                                                                                                var_s3 = 1;
                                                                                                M2C_FIELD(arg0, s32 *, 0x60) = (s32) (M2C_FIELD(arg0, s32 *, 0x60) | 0x8000);
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                    var_s0 = M2C_FIELD(var_s0, void **, 0);
                                                                                } while ((var_s0 != NULL) & (var_s3 ^ 1));
                                                                            }
                                                                        }
                                                                    }
                                                                    var_s2 = M2C_FIELD(var_s2, void **, 0);
                                                                }
                                        }
                                    } while ((var_s2 != NULL) & (var_s3 ^ 1));
                                }
                            }
                        }
                        var_s4 = M2C_FIELD(var_s4, void **, 0);
                        var_v1_3 = var_s3 ^ 1;
        }
        if (sp10 != NULL) {
            if (sp10 != D_8010A500) {
                M2C_FIELD(temp_s5, s32 *, 0x88) = (s32) (M2C_FIELD(temp_s5, s32 *, 0x88) | 0x40000000);
            } else {
                M2C_FIELD(arg0, s32 *, 0x60) = temp_s6;
            }
            return sp10;
        }
        goto block_47;
    }
block_47:
    if ((M2C_FIELD(temp_s5, s32 *, 0x88) & 0x01E00000) == 0x400000) {
block_48:
        return NULL;
    }
block_49:
    var_v0 = D_8010A500;
    return var_v0;
}
