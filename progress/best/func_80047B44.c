extern f64 D_800D3E08;
f32 func_80045764(void *, const void *);
s32 func_8004886C(s32, void *, f32);
s32 func_8004DBD8(void *, f32 *, s32, s32, s32, f32 *);

void *func_80047B44(void *arg0, void *arg1, void *arg2, void *arg3) {
int __repair_literal;

    f32 sp18[3];
    f32 sp28[3];
    f32 sp38;
    volatile u64 frameSpace;
    f32 temp_fs1;
    f64 temp_fs0;
    s32 temp_v1, temp_v1_2;
    s32 var_s0;
    s32 var_s2;
    void *nodeObject;
    void *temp_s1;
    void *temp_v0, *temp_v0_2;
    void *var_s5;
    void *var_v0;

    if (arg0 != NULL) {
        var_s5 = *(void **)((s8 *)*(void **)((s8 *)arg0 + 0x20) + 0x58);
        sp28[0] = *(f32 *)((s8 *)arg2) - *(f32 *)((s8 *)arg1);
        sp28[1] = *(f32 *)((s8 *)arg2 + 4) - *(f32 *)((s8 *)arg1 + 4);
        sp28[2] = *(f32 *)((s8 *)arg2 + 8) - *(f32 *)((s8 *)arg1 + 8);
        temp_fs1 = func_80045764(sp18, sp28);
        if (var_s5 != NULL) {
            temp_fs0 = D_800D3E08;
        loop_3:
            nodeObject = *(void **)((s8 *)var_s5 + 4);
            if ((func_8004886C((s32)((s8 *)nodeObject + 0x40), arg1, temp_fs1) << 0x18) != 0) {
                temp_s1 = *(void **)((s8 *)nodeObject + 0x3C);
                if (temp_s1 != NULL) {
                    if (*(u8 *)((s8 *)temp_s1 + 0x48) & 4) {
                        var_s0 = 0;
__repair_literal = 0;

                        if ((s32)*(u16 *)((s8 *)temp_s1 + 0x40) > __repair_literal) {
                            var_s2 = 0;
                        loop_8:
                            temp_v1 = *(s32 *)((s8 *)temp_s1 + 0x34);
                            temp_v0 = (void *)(*(s32 *)((s8 *)temp_s1 + 0x3C) + var_s2);
                            if (!(func_8004DBD8(arg1, sp18, temp_v1 + (*(u16 *)((s8 *)temp_v0) * 0xC), temp_v1 + (*(u16 *)((s8 *)temp_v0 + 2) * 0xC), temp_v1 + (*(u16 *)((s8 *)temp_v0 + 4) * 0xC), &sp38) & 0xFF) || !(sp38 >= 0.0f) || !(sp38 <= temp_fs1)) {
                                var_s0 += 1;
                                var_s2 += 6;
                                if (var_s0 < (s32)*(u16 *)((s8 *)temp_s1 + 0x40)) goto loop_8;
                                goto block_21;
                            }
                            var_v0 = var_s5;
                            if (arg3 != NULL) {
                                *(f32 *)((s8 *)arg3) = (f32)((f64)(*(f32 *)((s8 *)arg1) + (sp38 * sp18[0])) + ((f64)sp18[0] * temp_fs0));
                                *(f32 *)((s8 *)arg3 + 4) = (f32)((f64)(*(f32 *)((s8 *)arg1 + 4) + (sp38 * sp18[1])) + ((f64)sp18[1] * temp_fs0));
                                *(f32 *)((s8 *)arg3 + 8) = (f32)((f64)(*(f32 *)((s8 *)arg1 + 8) + (sp38 * sp18[2])) + ((f64)sp18[2] * temp_fs0));
                                return var_v0;
                            }
                            return var_v0;
                        }
                        goto block_21;
                    }
                    var_s0 = 0;
                    if ((s32)*(u16 *)((s8 *)temp_s1 + 0x40) > 0) {
                        var_s2 = 0;
                    loop_15:
                        temp_v1_2 = *(s32 *)((s8 *)temp_s1 + 0x34);
                        temp_v0_2 = (void *)(*(s32 *)((s8 *)temp_s1 + 0x3C) + var_s2);
                        if ((func_8004DBD8(arg1, sp18, temp_v1_2 + (*(u8 *)((s8 *)temp_v0_2) * 0xC), temp_v1_2 + (*(u8 *)((s8 *)temp_v0_2 + 1) * 0xC), temp_v1_2 + (*(u8 *)((s8 *)temp_v0_2 + 2) * 0xC), &sp38) & 0xFF) && (sp38 >= 0.0f) && (sp38 <= temp_fs1)) {
                            var_v0 = var_s5;
                            if (arg3 != NULL) {
                                *(f32 *)((s8 *)arg3) = (f32)((f64)(*(f32 *)((s8 *)arg1) + (sp38 * sp18[0])) + ((f64)sp18[0] * temp_fs0));
                                *(f32 *)((s8 *)arg3 + 4) = (f32)((f64)(*(f32 *)((s8 *)arg1 + 4) + (sp38 * sp18[1])) + ((f64)sp18[1] * temp_fs0));
                                *(f32 *)((s8 *)arg3 + 8) = (f32)((f64)(*(f32 *)((s8 *)arg1 + 8) + (sp38 * sp18[2])) + ((f64)sp18[2] * temp_fs0));
                                return var_v0;
                            }
                            return var_v0;
                        }
                        var_s0 += 1;
                        var_s2 += 3;
                        if (var_s0 < (s32)*(u16 *)((s8 *)temp_s1 + 0x40)) goto loop_15;
                                goto block_21;
                    }
                    goto block_21;
                }
            }
        block_21:
            var_s5 = *(void **)var_s5;
            if (var_s5 == NULL) goto block_22;
            goto loop_3;
        }
    }
block_22:
    var_v0 = NULL;
    return var_v0;
}
