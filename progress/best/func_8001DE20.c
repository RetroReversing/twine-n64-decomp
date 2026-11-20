s32 func_80025D84();
s32 func_80025E9C();
s32 func_80026004();
void *func_8002638C();
s8 func_800263B8();
s32 func_80087100();
extern s16 D_800B5B28;
extern s8 D_800BD690;
extern char D_800BD8EC[];
extern char D_800D2A74[];
extern s16 D_80108400;
extern void *D_80109BB0;
extern u8 D_8010A4C0;
extern u8 D_8010A4FC;
extern u8 D_8010A4FE;
extern u8 D_8010A4FF;

void func_8001DE20(void) {
    s32 var_a0;
s32 __repair_phase_var_a0;
    
    s32 var_a0_4;
    s32 var_v0;
    void *temp_s0;
    void *temp_s1;
    void *temp_s2;
    void *temp_s4;
    void *temp_s5;
    
    void *var_s3;

    D_800BD690 = 1;
    temp_s4 = func_8002638C(D_800BD8EC, 0x1F);
    temp_s5 = func_8002638C(D_800BD8EC, 0x20);
    temp_s1 = func_8002638C(D_800BD8EC, 0x19);
    var_s3 = func_8002638C(D_800BD8EC, 0x1C);
    D_800B5B28 = 1;
    if (var_s3 == (u32)NULL) {
        var_s3 = func_8002638C(D_800BD8EC, 3);
    }
    if (((temp_s4 != NULL) & (temp_s5 != NULL)) && ((temp_s1 != NULL) & (var_s3 != NULL))) {
        (*(s32 *)((char *)(temp_s5) + 0x14)) = (s32) ((((D_8010A4FC * (*(s32 *)((char *)(temp_s5) + 0x10))) + 2) << 0x10) | 8);
        if ((int)D_8010A4FE == 0) var_a0 = 0x1A;
        __repair_phase_var_a0 = 0x1B;
        { __repair_rows: { func_80026004(temp_s1, "%s", func_80087100(__repair_phase_var_a0)); }
if (0) goto __repair_rows; }
        temp_s2 = var_s3 - 0x28;
        if (D_80108400 != 0) {
            temp_s0 = temp_s4 - 0x28;
            (*(s16 *)((char *)(var_s3) + -0x28)) = 3;
            func_80025E9C(temp_s2, var_s3, temp_s1 - 0x28, temp_s0, 1, 9);
            func_80026004(var_s3, D_800D2A74);
            func_80025D84(temp_s0, temp_s4, temp_s2, temp_s5 - 0x28, 0x1F, 1);
            temp_s2 = (*(void **)((char *)(D_80109BB0) + 0x10));
            (*(s8 *)((char *)((*(void **)((char *)(D_80109BB0) + 0x10))) + 4)) = func_800263B8(temp_s2, 0x1F);
        } else {
            (*(s16 *)((char *)(var_s3) + -0x28)) = 0x1C;
            func_80025D84(var_s3 - 0x28, var_s3, temp_s1 - 0x28, temp_s4 - 0x28, 0x1C);
            var_a0 = 0x1B3;
            if (D_8010A4FF != 0) var_a0 = 0x1D;
            do { func_80026004(var_s3, "%s", func_80087100(var_a0)); } while (0);
            func_80025E9C(temp_s4 - 0x28, temp_s4, var_s3 - 0x28, temp_s5 - 0x28, 1, 0xD);
            temp_s2 = (*(void **)((char *)(D_80109BB0) + 0x10));
            (*(s8 *)((char *)((*(void **)((char *)(D_80109BB0) + 0x10))) + 4)) = func_800263B8(temp_s2, 0x20);
        }
        if (D_8010A4C0 == 1) var_a0_4 = 0x17;
        var_a0_4 = 0x16;
        do { func_80026004(temp_s4, "%s", func_80087100(var_a0_4)); } while (0);
    }
}
