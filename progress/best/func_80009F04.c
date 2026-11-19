/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000A18C(s32);                     /* extern */
s32 func_8000A22C(s32);                     /* extern */
s32 func_8000A6F4();                            /* extern */
s32 func_8000B384(s32, s32);                    /* extern */
s32 func_8000B534();                                /* extern */
s32 func_8000B900(s32, s32, s32);               /* extern */
s32 func_80088AC0(s32 *, s32);          /* extern */
s32 func_80088C50(s32);                     /* extern */
s32 func_80092A68(s32, u16, s32 *, s32, s32); /* extern */
s32 func_80095820(s32, s32, s32, s32, s32, s32); /* extern */
s32 func_8009CE34(s32, s32);            /* extern */
s32 func_8009CF18(s32, s32, s32);   /* extern */
s32 func_8009D030(s32 *);                   /* extern */
extern s32 D_14CD630;
extern s32 D_14D0ED0;
extern s32 D_14DDC00;
extern s32 D_14E2500;
extern s32 D_1D69630;
extern s32 D_800B2480;
extern s32 D_800B2488;
extern s32 D_800B256C;
extern s32 D_800DD7D0;
extern s32 D_800E06B0;
extern s32 D_800E06FC;
extern s32 D_800E0700;
extern s32 D_800E0704;
extern s32 D_800E0708;
extern s32 *D_800E070C;
extern s16 D_80108400;

s32 func_80009F04(void) {
    s32 temp_s0;
    unsigned int temp_s2;
u16 __repair_narrow_temp_s2;
    s32 temp_s2_2;
    unsigned long temp_s2_3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_s0;
    s32 var_v0;
    u16 temp_a1;

    var_v0 = 0;
    if (func_80095820(0x5622, 0x14, 0xA, 0xA, 0xFA, -(D_80108400) & 0x140000) == 0) {
        temp_s2 = &D_14D0ED0 - &D_14CD630;
        temp_v0 = func_8000B384(temp_s2, 0);
        D_800E06FC = temp_v0;
        func_8000B900(temp_v0, (s32) &D_14CD630 & 0x0FFFFFFF, temp_s2);
        temp_s2_2 = &D_14DDC00 - &D_14D0ED0;
        temp_v0_2 = func_8000B384(temp_s2_2, 0);
        D_800E0700 = temp_v0_2;
        func_8000B900(temp_v0_2, (s32) &D_14D0ED0 & 0x0FFFFFFF, temp_s2_2);
        temp_s2_3 = &D_14E2500 - &D_14DDC00;
        temp_v0_3 = func_8000B384(temp_s2_3, 0);
        D_800E0704 = temp_v0_3;
        func_8000B900(temp_v0_3, (s32) &D_14DDC00 & 0x0FFFFFFF, temp_s2_3);
        func_80092A68(D_800E06FC, 0U, &D_14E2500, D_800E0704, D_800E0700);
        var_s0 = 0;
        if (D_800B2480) {
            __repair_rows: {
                var_s0 += 0xC;
                __repair_narrow_temp_s2 = (u16)(*((s32 *)((s8 *)&D_800B2488 + var_s0)));
                temp_s2_3 = (u16)__repair_narrow_temp_s2;
temp_s2 = (u16)temp_s2_3;
func_80092A68(D_800E06FC, temp_s2, &D_14E2500, D_800E0704, D_800E0700);
            }
if (*(&D_800B2480 + var_s0) != 0) goto __repair_rows;
        }
        func_8009CE34(0xE7, 0);
        func_8009CE34(0xE8, 0);
        func_8009CE34(0xE9, 0);
        func_8009CE34(0xEA, 0);
        func_8009CE34(0xEB, 0);
        func_8009CE34(0xEC, 0);
        func_8009CE34(0xED, 0);
        func_8009CE34(0xEE, 0);
        func_8009CF18(0x7F, 0, 0);
        func_8009CE34(0x1B8, 1);
        func_80088C50(1);
        func_80088AC0(&D_1D69630, 0);
        func_8009D030(&D_800B256C);
        D_800E0708 = -1;
        D_800E070C = &D_800DD7D0;
        func_8000A6F4();
        D_800E06B0 = -1;
        temp_s0 = func_8000B534();
        func_8000A18C(0xA);
        func_8000A22C(0xA);
        var_v0 = temp_s0;
    }
    return temp_s0;
}
