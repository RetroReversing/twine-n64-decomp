/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern int D_800D4240;
extern int D_800D4244;
extern int D_800D4248;
s32 func_8001751C();
s32 applyNearbyActorImpact();
s32 func_80045CF8();
s32 func_80061578();
s32 func_80082FE4();
s32 func_80083A6C();
extern u8 D_80109A60[];

void func_80061168(void *arg0) {
    s32 sp10[3];
    char sp20[0x30];
    s16 sp50[3];
    s32 sp58[3];
    f32 sp68[3];
    register s16 temp_v1;
    s16 var_v0;
    u32 var_s0;
    u32 temp_v1_2;
    register u8 temp_v0;
    void **temp_v0_2;
    void *temp_s2;
    void *var_v1;

    if (((*(s32 *)((char *)(arg0) + 0x58)) & 4) || ((*(s32 *)((char *)(arg0) + 0x60)) & 0x3000)) {
        temp_v1 = (*(s16 *)((char *)(arg0) + 0x7A));
        temp_s2 = (*(void **)((char *)(arg0) + 0x6C));
        if (temp_v1 != 1) {
            if (temp_v1 >= 2) {
                if (temp_v1 != 2) {
                    (*(s32 *)((char *)(arg0) + 0x60)) = 0;
                    return;
                }
                if (func_80045CF8((*(u8 *)((char *)(temp_s2) + 0x28))) == 0) {
                    var_v0 = 1;
                    goto block_25;
                }
                goto block_26;
            }
            if (temp_v1 != 0) {
                (*(s32 *)((char *)(arg0) + 0x60)) = 0;
                return;
            }
            sp10[0] = D_800D4240;
            sp10[1] = D_800D4244;
            sp10[2] = D_800D4248;
            sp50[0] = (s16) (s32) (*(f32 *)((char *)(arg0) + 0x3C));
            sp50[1] = (s16) (s32) (*(f32 *)((char *)(arg0) + 0x40));
            sp50[2] = (s16) (s32) (*(f32 *)((char *)(arg0) + 0x44));
            func_80082FE4(sp50, sp20);
            func_80083A6C(sp20, sp10);
            (*(s32 *)((char *)(temp_s2) + 0)) = sp10[0];
            (*(s32 *)((char *)(temp_s2) + 4)) = sp10[1];
            var_v0 = 1;
            (*(s32 *)((char *)(temp_s2) + 8)) = sp10[2];
            goto block_25;
        }
        temp_v0 = (*(u8 *)((char *)(temp_s2) + 0x22));
        if ((!temp_v0) || (*(D_80109A60 + temp_v0) != 0)) {
            if (func_80045CF8((u8) (*(s16 *)((char *)(arg0) + 0x7C))) == 0) {
                sp58[0] = (*(s32 *)((char *)(arg0) + 0x24));
                sp58[2] = (*(s32 *)((char *)(arg0) + 0x2C));
                sp58[1] = (*(s32 *)((char *)(arg0) + 0x28));
                sp68[0] = (*(f32 *)((char *)(arg0) + 0x3C));
                sp68[1] = (*(f32 *)((char *)(arg0) + 0x40));
                sp68[2] = (*(f32 *)((char *)(arg0) + 0x44));
                func_8001751C((*(s32 *)((char *)(temp_s2) + 0x18)), (*(u8 *)((char *)(temp_s2) + 0x21)), sp58, sp68);
                func_80061578(arg0, sp58);
                applyNearbyActorImpact(arg0);
                temp_v1_2 = (*(u16 *)((char *)(arg0) + 0x78));
                var_s0 = 0;
                if ((s32) temp_v1_2 >= 0x47) {
                    if ((s32) temp_v1_2 >= 0x49) {
                        if (temp_v1_2 == 0x49) {
                            var_s0 = 0x02000000;
                            goto block_18;
                        }
                    } else {
block_18:
                        temp_v0_2 = (*(void ***)((char *)(arg0) + 0x20));
                        if (temp_v0_2 != NULL) {
                            var_v1 = *temp_v0_2;
                            if (var_v1 != NULL) {
                                do {
                                    (*(s32 *)((char *)(var_v1) + 0x60)) |= var_s0;
                                    var_v1 = (*(void **)((char *)(var_v1) + 0));
                                } while (var_v1 != NULL);
                            }
                        }
                    }
                }
            }
            if (func_80045CF8((*(u8 *)((char *)(temp_s2) + 0x27))) == 0) {
                var_v0 = 2;
block_25:
                (*(s16 *)((char *)(arg0) + 0x7A)) = var_v0;
            }
            goto block_26;
        }
    } else {
block_26:
        (*(s32 *)((char *)(arg0) + 0x60)) = 0;
    }
}
