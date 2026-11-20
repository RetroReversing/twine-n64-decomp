/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80034928();
extern u8 D_801002E5;
extern u8 D_80100774;
extern u8 D_80100775;
extern u8 D_80100776;
extern u8 D_80100777;
extern u8 D_80100778;
extern u8 D_80100779;
extern u8 D_8010077A;
extern u8 D_8010077B;
extern u8 D_8010077C;
extern u8 D_801007CC;
extern u8 D_801007CD;
extern u8 D_801007CE;
extern u8 D_801007CF;
extern u8 D_801007D0;
extern u8 D_801007D1;
extern u8 D_801007D2;
extern u8 D_801007D3;
extern u8 D_801007D4;
extern u8 D_80102F38;
extern u8 D_801032A4;
extern u8 D_80108F74;
extern u8 D_801093A0;
extern u8 D_8010A3C4;
extern u8 D_8010A4B8;
extern void *D_8010A4D8;
extern u8 D_80110CA8;
extern u8 D_80110DB1;
extern void *D_80115328;

void func_800349B4(void *arg0) {
    register unsigned int temp_v1;
    s32 var_s1;
    s32 var_s2;
s32 __repair_phase_var_s2;
    void *temp_a0;
    s32 var_s3;
    void *temp_a3;

    var_s2 = 0;
    var_s1 = 0;
    var_s3 = 0;
    if ((*(s32 *)((char *)(arg0) + 0x100)) & 1) {
        (*(u8 *)((char *)(arg0) + 0x145)) = 0U;
        (*(u8 *)((char *)(arg0) + 0x144)) = 0U;
        (*(u8 *)((char *)(arg0) + 0x143)) = 0U;
        (*(u8 *)((char *)(arg0) + 0x146)) = 0xFFU;
        func_80034928(arg0, D_8010A4D8);
    }
    if ((*(s32 *)((char *)(arg0) + 0x100)) & 4) {
        (*(u8 *)((char *)(arg0) + 0x143)) = (u8) D_801093A0;
        (*(u8 *)((char *)(arg0) + 0x144)) = (u8) D_801002E5;
        (*(u8 *)((char *)(arg0) + 0x145)) = (u8) D_80110CA8;
        (*(u8 *)((char *)(arg0) + 0x146)) = 0xFFU;
        func_80034928(arg0, D_8010A4D8);
    }
    if ((*(s32 *)((char *)(arg0) + 0x100)) & 2) {
        (*(u8 *)((char *)(arg0) + 0x143)) = (u8) D_8010A3C4;
        (*(u8 *)((char *)(arg0) + 0x144)) = (u8) D_8010A4B8;
        (*(u8 *)((char *)(arg0) + 0x145)) = (u8) D_80110DB1;
        (*(u8 *)((char *)(arg0) + 0x146)) = 0xFFU;
        func_80034928(arg0, (void *)2);
    }
    temp_a3 = D_80115328;
    D_80115328 = temp_a3 + 8;
    (*(s32 *)((char *)(temp_a3) + 0)) = 0xFB000000;
    (*(s32 *)((char *)(temp_a3) + 4)) = (s32) (((*(u8 *)((char *)(arg0) + 0x143)) << 0x18) | ((*(u8 *)((char *)(arg0) + 0x144)) << 0x10) | ((*(u8 *)((char *)(arg0) + 0x145)) << 8) | (*(u8 *)((char *)(arg0) + 0x146)));
    temp_v1 = (*(s32 *)((char *)(arg0) + 0x100));
    if (temp_v1 & 2) {
        __repair_phase_var_s2 = D_801007CF;
        var_s3 = D_801007D1;
        var_s1 = D_801007D0;
        (*(s32 *)((char *)(temp_a3) + 8)) = 0xDB080000;
        D_80115328 = temp_a3 + 0x10;
        var_s1 = (__repair_phase_var_s2 + var_s1 + var_s3) / 3;
        var_s2 = 0;
        (*(s32 *)((char *)(temp_a3) + 0xC)) = (s32) (((D_801007CD + 0x7530) << 0x10) | ((D_801007CE - 0x7530) & 0xFFFF));
    } else if (temp_v1 & 4) {
        var_s2 = 0;
        (*(s32 *)((char *)(temp_a3) + 8)) = 0xDB080000;
        var_s1 = 0;
        (*(s32 *)((char *)(temp_a3) + 0xC)) = (s32) (((D_801007CD + (D_801007CC * 0x78)) << 0x10) | (((D_801007CC * -0x78) + D_801007CE) & 0xFFFF));
        D_80115328 = temp_a3 + 0x10;
        D_80102F38 = D_801007D2;
        D_80108F74 = D_801007D3;
        D_801032A4 = D_801007D4;
        var_s3 = 0x40;
    } else {
        if (temp_v1 & 1) {
            var_s2 = D_801007CF;
            var_s1 = D_801007D0;
            var_s3 = D_801007D1;
            (*(s32 *)((char *)(temp_a3) + 0xC)) = (s32) (((D_801007CD + (D_801007CC * 0x78)) << 0x10) | (((D_801007CC * -0x78) + D_801007CE) & 0xFFFF));
            (*(s32 *)((char *)(temp_a3) + 8)) = 0xDB080000;
            D_80115328 = temp_a3 + 0x10;
            D_80102F38 = D_801007D2;
            D_80108F74 = D_801007D3;
            D_801032A4 = D_801007D4;
        }
        if ((*(s32 *)((char *)(arg0) + 0x100)) & 8) {
            var_s2 = D_80100777;
            var_s1 = D_80100778;
            var_s3 = D_80100779;
            (*(s32 *)((char *)(D_80115328) + 0)) = 0xDB080000;
            (*(s32 *)((char *)(D_80115328) + 4)) = (s32) (((D_80100775 + (D_80100774 * 0x78)) << 0x10) | (((D_80100774 * -0x78) + D_80100776) & 0xFFFF));
            D_80102F38 = D_8010077A;
            D_80115328 += 8;
            D_80108F74 = D_8010077B;
            D_801032A4 = D_8010077C;
        }
    }
    temp_a0 = D_80115328;
    D_80115328 = temp_a0 + 8;
    (*(s32 *)((char *)(temp_a0) + 0)) = 0xF8000000;
    (*(s32 *)((char *)(temp_a0) + 4)) = (s32) ((var_s2 << 0x18) | ((var_s1 & 0xFF) << 0x10) | (var_s3 << 8) | 0xFF);
}
