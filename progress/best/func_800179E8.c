#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 func_8001792C(void *, s32, s32, s32);
extern u16 D_800B35B0;

void func_800179E8(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    void *sp10[0x80];
    s32 sp214;
    s32 sp21C;
    u32 sp224;
    s32 var_s4;
    u32 temp_s7;
    u32 var_s3;
    u32 var_s3_2;
    u32 var_s6;
    void **var_s2;
    void **var_s2_2;
    void **var_s2_3;
    void **var_s5;
    void *temp_a0;
    void *temp_s1;
    void *temp_s1_2;
    void *temp_s1_3;
    void *temp_t0;
    void *temp_t0_2;
    void *var_s0;
    void *var_s0_2;
    void *var_s0_3;

    var_s4 = arg2;
    sp214 = arg0;
    sp21C = arg3;
    sp224 = 0;
    D_800B35B0 += 1;
    var_s6 = 0;
    if (arg1 != NULL) {
        if (sp21C == 0) {
            var_s4 &= 0xFFFCFFFF;
        }
        func_8001792C(arg1, 2, var_s4 | 0x1000, sp214);
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x20), u16 *, 0x60) = (u16) D_800B35B0;
        if (sp21C == 1) {
            var_s4 &= 0xFFFCFFFF;
        }
        var_s0 = M2C_FIELD(M2C_FIELD(arg1, void **, 0x20), void **, 0x58);
        if (var_s0 != NULL) {
            var_s2 = &sp10[0];
            do {
                temp_s1 = M2C_FIELD(var_s0, void **, 8);
                temp_t0 = M2C_FIELD(temp_s1, void **, 0x20);
                if (M2C_FIELD(temp_t0, u16 *, 0x60) != D_800B35B0) {
                    M2C_FIELD(temp_t0, u16 *, 0x60) = (u16) D_800B35B0;
                    func_8001792C(temp_s1, 2, var_s4 | 0x2000, sp214);
                    *var_s2 = temp_s1;
                    var_s2 += 4;
                    var_s6 += 1;
                }
                var_s0 = M2C_FIELD(var_s0, void **, 0);
            } while (var_s0 != NULL);
        }
        if (sp21C == 2) {
            var_s4 &= 0xFFFCFFFF;
        }
        temp_s7 = var_s6;
        var_s3 = sp224;
        sp224 = temp_s7;
        if (var_s3 < temp_s7) {
            var_s5 = &(&sp10[0])[var_s3];
            do {
                var_s0_2 = M2C_FIELD(M2C_FIELD(*var_s5, void **, 0x20), void **, 0x58);
                if (var_s0_2 != NULL) {
                    var_s2_2 = &(&sp10[0])[var_s6];
                    do {
                        temp_s1_2 = M2C_FIELD(var_s0_2, void **, 8);
                        temp_t0_2 = M2C_FIELD(temp_s1_2, void **, 0x20);
                        if (M2C_FIELD(temp_t0_2, u16 *, 0x60) != D_800B35B0) {
                            M2C_FIELD(temp_t0_2, u16 *, 0x60) = (u16) D_800B35B0;
                            func_8001792C(temp_s1_2, 2, var_s4 | 0x4000, sp214);
                            *var_s2_2 = temp_s1_2;
                            var_s2_2 += 4;
                            var_s6 += 1;
                        }
                        var_s0_2 = M2C_FIELD(var_s0_2, void **, 0);
                    } while (var_s0_2 != NULL);
                }
                var_s3 += 1;
                var_s5 += 4;
            } while (var_s3 < temp_s7);
        }
        if (sp21C == 3) {
            var_s4 &= 0xFFFCFFFF;
        }
        var_s3_2 = sp224;
        if (var_s3_2 < var_s6) {
            var_s2_3 = &(&sp10[0])[var_s3_2];
            do {
                var_s0_3 = M2C_FIELD(M2C_FIELD(*var_s2_3, void **, 0x20), void **, 0x58);
                if (var_s0_3 != NULL) {
                    do {
                        temp_s1_3 = M2C_FIELD(var_s0_3, void **, 8);
                        temp_a0 = M2C_FIELD(temp_s1_3, void **, 0x20);
                        if (M2C_FIELD(temp_a0, u16 *, 0x60) != D_800B35B0) {
                            M2C_FIELD(temp_a0, u16 *, 0x60) = (u16) D_800B35B0;
                            func_8001792C(temp_s1_3, 2, var_s4 | 0x8000, sp214);
                        }
                        var_s0_3 = M2C_FIELD(var_s0_3, void **, 0);
                    } while (var_s0_3 != NULL);
                }
                var_s3_2 += 1;
                var_s2_3 += 4;
            } while (var_s3_2 < var_s6);
        }
    }
}
