/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */

s32 func_8000B900();
extern char D_106C[];
extern char D_110C[];
extern char D_12B0[];
extern char D_1334[];
extern char D_13AC[];
extern char D_14977A0[];
extern char D_14A8380[];
extern char D_14BA940[];
extern s32 D_800CE800;
extern s32 D_800CE804;
extern void *D_800CE808;
extern void *D_800CE80C;
extern void *D_800CE810;
extern void *D_800CE814;
extern void *D_800CE818;
extern void *D_800CE81C;
extern void *D_800CE820;
extern void *D_800CE824;
extern void *D_800CE828;
extern void *D_800CE82C;
extern s16 D_800CE830;
extern s32 D_80108F7C;
extern char D_BA8[];
extern char D_DF0[];
extern char D_EA0[];
extern char D_F34[];
extern char D_F90[];

s32 func_80086DA0(s32 arg0) {
    void *var_v1;
    register unsigned int temp_a0;

    temp_a0 = arg0 & 0xFFFF;
    switch (temp_a0) {                              /* irregular */
    case 2:
        D_800CE830 = 2;
        D_800CE804 = D_800CE800;
        D_800CE808 = D_800CE800 + D_BA8;
        D_800CE80C = D_800CE800 + D_DF0;
        D_800CE810 = D_800CE800 + (s32)D_EA0;
        D_800CE814 = (s32)D_800CE800 + D_F90;
        D_800CE818 = D_800CE800 + D_106C;
        D_800CE81C = D_800CE800 + D_1334;
        D_800CE820 = D_800CE800 + D_F34;
        D_800CE824 = D_800CE800 + D_12B0;
        D_800CE828 = D_800CE800 + D_110C;
        func_8000B900(D_800CE800);
        var_v1 = D_800CE800 + D_13AC;
        break;
    case 5:
        D_800CE830 = 5;
        func_8000B900(D_800CE800);
        D_800CE804 = D_800CE800;
        D_800CE808 = D_800CE800 + D_BA8;
        D_800CE80C = D_800CE800 + D_DF0;
        D_800CE810 = D_800CE800 + (u32)D_EA0;
        D_800CE814 = D_800CE800 + (unsigned)D_F90;
        D_800CE818 = D_800CE800 + D_106C;
        D_800CE81C = D_800CE800 + D_1334;
        D_800CE820 = D_800CE800 + D_F34;
        D_800CE824 = D_800CE800 + D_12B0;
        D_800CE828 = D_800CE800 + D_110C;
        var_v1 = D_800CE800 + D_13AC;
        break;
    default:
        D_800CE804 = (s32)&D_800CE800;
        D_800CE830 = 1;
        D_800CE80C = D_800CE800 + (unsigned)D_DF0;
        D_800CE808 = D_800CE800 + D_BA8;
        D_800CE818 = D_800CE800 + D_106C;
        D_800CE810 = D_800CE800 + D_EA0;
        D_800CE814 = D_800CE800 + (u32)D_F90;
        D_800CE81C = D_800CE800 + D_1334;
        D_800CE820 = D_800CE800 + D_F34;
        D_800CE828 = D_800CE800 + D_110C;
        func_8000B900(D_800CE800);
        D_800CE824 = D_800CE800 + D_12B0;
        var_v1 = D_800CE800 + D_13AC;
        break;
    }
    D_800CE82C = var_v1;
    return 1;
}
