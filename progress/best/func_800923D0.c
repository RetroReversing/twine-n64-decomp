/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008CDC0();
s8 func_8008EF18();
s32 func_8008FB20();
s32 func_8008FF80();
s32 func_8008FFF8();
s32 func_8009010C();
s32 func_800902B4();
s32 func_80090464();
s32 func_8009CCB0();
extern void *D_800E5AC0;
extern char D_800E5AC4[];
extern u8 D_800E6A84;
extern char D_800E6A85[];
extern u8 D_800E6A88[];
extern u32 D_800EDA84;
extern u8 D_800EDA87;
extern s8 D_800EDA88;
extern void *D_800EDA8C;
extern s32 D_801002D8;
extern s32 D_8010A514;

void func_800923D0(void) {
    s32 temp_a0;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;
    u32 var_a0;
    unsigned var_s2;
    u32 temp_lo;
    unsigned int temp_v0;
    u32 temp_v1_2;
    u32 var_s7;
    char *var_s6;
    void **temp_v1_4;
    void *temp_a1;
    void *temp_a2;
    void *temp_s1;
    void *temp_v1;
    void *temp_v1_3;
    void *var_s0;

    if (D_801002D8 != 0) {
        var_s7 = 0;
        var_s6 = &D_800E6A84;
        var_s2 = 0;
        do {
            if (*(u8 *)var_s6 != 0) {
                D_800EDA8C = var_s2 + D_800E5AC4;
                D_800EDA84 = var_s7;
                temp_a2 = D_800EDA8C;
                D_800EDA88 = func_8008EF18(*(D_800E6A88 + var_s2));
                if (((*(s32 *)((char *)(temp_a2) + 0xF68)) != 0) && ((*(u32 *)((char *)((*(void **)((char *)(temp_a2) + 0xF6C))) + 0)) != -1U)) {
loop_6:
                    temp_a1 = (*(void **)((char *)(temp_a2) + 0xF6C));
                    if ((u32) ((*(s32 *)((char *)(temp_a2) + 0xF74)) + (*(s32 *)((char *)(temp_a2) + 0x120))) >= (u32) (*(u32 *)((char *)(temp_a1) + 0))) {
                        temp_a0 = (*(s32 *)((char *)(temp_a1) + 4));
                        (*(s32 *)((char *)(temp_a2) + 0x124)) = temp_a0;
                        func_8008CDC0(temp_a0);
                        temp_v1 = (*(void **)((char *)(D_800EDA8C) + 0xF6C));
                        (*(void **)((char *)(D_800EDA8C) + 0xF6C)) = (void *) (temp_v1 + 8);
                        if ((*(s32 *)((char *)(temp_v1) + 8)) != -1) {
                            goto loop_6;
                        }
                    }
                }
                temp_lo = ((u32) ((((*(s32 *)((char *)(D_800EDA8C) + 0x124)) * 0xC00) / 60) * ((s32) (D_801002D8 << 0x10) / (s32) D_8010A514)) >> 3) * (*(u16 *)((char *)(D_800EDA8C) + 0xFC2));
                var_a0 = (*(s32 *)((char *)(D_800EDA8C) + 0xF68));
                temp_v1_2 = temp_lo >> 0x18;
                (*(s32 *)((char *)(D_800EDA8C) + 0x118)) = (s32) ((temp_lo >> 8) & 0xFFFF);
                (*(u32 *)((char *)(D_800EDA8C) + 0x11C)) = temp_v1_2;
                (*(s32 *)((char *)(D_800EDA8C) + 0x120)) = (s32) ((s32) temp_v1_2 >> 1);
                if ((s32)var_a0 != 0) {
                    temp_v0 = (*(s32 *)((char *)(D_800EDA8C) + 0xF70)) + (*(s32 *)((char *)(D_800EDA8C) + 0x118));
                    var_a0 = temp_v0 & 0xFFFF;
                    (*(s32 *)((char *)(D_800EDA8C) + 0xF70)) = var_a0;
                    (*(s32 *)((char *)(D_800EDA8C) + 0xF74)) += (((unsigned short)temp_v0 >> 0x10) + (*(u32 *)((char *)(D_800EDA8C) + 0x11C)));
                }
                temp_s5 = func_80090464(var_a0);
                temp_s4 = func_8008FB20();
                func_8009010C();
                func_800902B4();
                func_8008FF80();
                var_s0 = (*(void **)((char *)(D_800EDA8C) + 0xF7C));
                temp_s3 = func_8008FFF8();
                if (var_s0 != NULL) {
                    do {
                        temp_s1 = (*(void **)((char *)(var_s0) + 0));
                        if (func_8009CCB0((*(s32 *)((char *)(var_s0) + 8))) == -1) {
                            temp_v1_3 = (*(void **)((char *)(var_s0) + 0));
                            if (temp_v1_3 != NULL) {
                                (*(void ***)((char *)(temp_v1_3) + 4)) = (void **) (*(void ***)((char *)(var_s0) + 4));
                            }
                            temp_v1_4 = (*(void ***)((char *)(var_s0) + 4));
                            if (temp_v1_4 != NULL) {
                                *temp_v1_4 = (*(void **)((char *)(var_s0) + 0));
                            } else {
                                (*(void **)((char *)(D_800EDA8C) + 0xF7C)) = (void *) (*(void **)((char *)(var_s0) + 0));
                            }
                            (*(void **)((char *)(var_s0) + 0)) = (void *) D_800E5AC0;
                            if (D_800E5AC0 != NULL) {
                                (*(void **)((char *)(D_800E5AC0) + 4)) = var_s0;
                            }
                            (*(void ***)((char *)(var_s0) + 4)) = NULL;
                            D_800E5AC0 = var_s0;
                        }
                        var_s0 = temp_s1;
                    } while (var_s0 != NULL);
                }
                if ((!(temp_s5 & 0xFF) & !(temp_s4 & 0xFF)) && !(temp_s3 & 0xFF)) {
                    *(u8 *)var_s6 = 0;
                    *(D_800E6A85 + var_s2) = 1;
                }
            }
            var_s6 += 0xFF8;
            var_s7 += 1;
            var_s2 += 0xFF8;
        } while (var_s7 < 8U);
    }
}
