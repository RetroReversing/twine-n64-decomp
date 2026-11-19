/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f32 func_8000A4F4();
f32 func_80045E34();
s32 func_80074820();
s32 func_80087100();
extern s32 D_800C7EE4;
extern char D_80100310[];
extern char D_80100314[];
extern void *D_80100B20;
extern s32 D_8010302C;
extern s32 D_80109688;
extern s32 D_8010A500;
extern u8 D_8010D294;
extern s16 D_80112EBC;

void func_80074C34(void *arg0, void *arg1, s32 arg2) {
    s32 __repair_store_1;
    s32 __repair_store_0;
    s32 __repair_store_2;
int __repair_literal;

    f32 temp_fv0;
    f32 var_fs0;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    long var_a0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_v1;
    void **temp_s7;
    void **var_s2;
    void *temp_s0;
    void *temp_v0_2;
    void *var_s4;
    

    var_a0 = 0;
    if (arg0 != NULL) {
        (*(s32 *)((char *)(arg0) + 0x60)) |= 0x10000000;
    }
    var_s1 = 0;
    if ((s32) D_8010D294 > 0) {
        var_v1 = 0;
        do {
            if (*(D_80100310 + var_v1) == arg1) {
                var_a0 = 1;
            }
            var_s1 += 1;
            var_v1 += 8;
        } while (var_s1 < (s32) D_8010D294);
    }
    if (var_a0 == 0) {
        temp_v0 = D_8010D294 * 8;
        *(D_80100314 + temp_v0) = arg2;
        D_8010D294 += 1;
        *(D_80100310 + temp_v0) = arg1;
    }
    D_8010302C += 1;
    var_s4 = arg1;
    if (arg2 != 0) {
        temp_s7 = &D_80100B20 - 4;
        do {
            var_fs0 = 5.0f;
            if ((*(u16 *)((char *)(var_s4) + 6)) == 0x237) {
                var_fs0 = 0.0f;
            }
            temp_v0 = (*(s32 *)((char *)(var_s4) + 0));
            if (temp_v0 & 0x80000000) {
                var_fs0 = func_8000A4F4(temp_v0 & 0xFFFFFF);
            }
            func_80074820(D_80109688, func_80087100((*(u16 *)((char *)(var_s4) + 6))), 0x20, 2, var_fs0 + 0.5f, D_800C7EE4);
            if ((s32)D_80112EBC != 0) {
                var_s1_2 = 0;
__repair_literal = 0;

                if (D_80112EBC > __repair_literal) {
                    var_s2 = &D_80100B20;
                    do {
                        temp_v0_2 = *var_s2;
                        if (temp_v0_2 != NULL) {
                            temp_s0 = (*(void **)((char *)(temp_v0_2) + 0x6C));
                            if (arg0 != NULL) {
                                (*(void **)((char *)(temp_s0) + 0x2C)) = arg0;
                                __repair_store_0 = (s32) (*(s32 *)((char *)(arg0) + 0x24));
                                __repair_store_1 = (s32) (*(s32 *)((char *)(arg0) + 0x28));
                                __repair_store_2 = (s32) (*(s32 *)((char *)(arg0) + 0x2C));
                                (*(s32 *)((char *)(temp_s0) + 8)) = __repair_store_0;
                                (*(s32 *)((char *)(temp_s0) + 0xC)) = __repair_store_1;
                                (*(s32 *)((char *)(temp_s0) + 0x10)) = __repair_store_2;
                                temp_fv0 = func_80045E34(temp_s0 + 8, (int)D_8010A500 + 0x24);
                                (*(s32 *)((char *)(temp_s0) + 0x28)) = temp_fv0;
                                if (temp_fv0 < 4.0f) {
                                    (*(s32 *)((char *)(temp_s0) + 0x28)) = 4.0f;
                                }
                            }
                        }
                        temp_v1_2 = (*(s32 *)((char *)(var_s4) + 0));
                        if (temp_v1_2 & 0x80000000) {
                            temp_s0 = D_80100B20; } else {
                            temp_s0 = temp_s7[D_80112EBC];
                        }
                        (*(s32 *)((char *)((*(void **)((char *)(temp_s0) + 0x6C))) + 0x24)) = temp_v1_2;
                        (*(u8 *)((char *)((*(void **)((char *)(temp_s7[D_80112EBC]) + 0x6C))) + 0x32)) = (s8) (*(u16 *)((char *)(var_s4) + 4));
                        var_s1_2 += 1;
                        var_s2 += 1;
                    } while (var_s1_2 < D_80112EBC);
                }
            }
            var_s4 += 8;
        } while ((u32) var_s4 < (u32) ((arg2 * 8) + arg1));
    }
}
