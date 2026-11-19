/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800158A4();
f32 func_80045540();
s32 func_80045764();
s32 func_80046384();
s32 func_80064318();
s32 func_800643C8();
s32 func_800643D8();
f32 func_800829A0();
f32 func_800829C8();
s32 func_80083A6C();
extern f32 D_800C0740;
extern char D_800C469C[];
extern char D_800C46FC[];
extern f64 D_800D44F0;
extern f64 D_800D44F8;
extern u8 D_801002D4;
extern s32 D_80102ED8;
extern char D_80109688[];
extern char D_80109A98[];
extern char D_80109A9C[];
extern char D_80109AA0[];

void func_80069250(void *arg0) {
    f32 sp48;
    f32 sp4C;
    unsigned sp30;
    f32 sp38;
    f32 sp3C;
    f32 sp2C;
    f32 sp28;
    f32 sp40;
f32 __repair_sp4C_1;
    f32 sp50;
    f32 sp58;
    f32 sp5C;
    register f32 sp60;
    register f32 sp68;
    f32 sp6C;
    f32 sp70;
    int sp74;
    f32 sp78;
    f32 sp7C;
    f32 sp80;
    f32 sp84;
    f32 sp88;
    f32 sp98;
    f32 sp9C;
    int spA8;
    f32 spB0;
    f32 spB4;
    f32 spB8;
    f32 spC0;
    f32 spC4;
    f32 spC8;
    void *spD4;
    unsigned int spDC;
    f32 temp_a0;
    f32 temp_a1;
    f32 temp_a2;
    f32 temp_fa0;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs0_4;
    f32 temp_fs0_5;
    f32 temp_ft0;
    f32 temp_ft0_2;
    f32 temp_ft1;
    f32 temp_ft1_2;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv1;
    unsigned long temp_v0_6;
    int var_v0;
    s8 temp_t0;
    void **temp_s5;
    void *temp_fp;
    void *temp_s2;
    void *temp_s3;
    void *temp_s4;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    
    void *temp_v1;

    temp_s3 = (*(void **)((char *)(arg0) + 0x6C));
    temp_s4 = (*(void **)((char *)(temp_s3) + 0xAC));
    temp_s2 = (*(void **)((char *)(temp_s3) + 0xB0));
    spD4 = (*(void **)((char *)(temp_s3) + 0xA8));
    do { func_800643D8(temp_s4); } while (0);
    func_800643D8(temp_s2);
    if (((*(s16 *)((char *)((*(void **)((char *)(temp_s3) + 0xA8))) + 0x7A)) == 0) && ((temp_t0 = (*(s8 *)((char *)(temp_s3) + 0x182)), spDC = (s32) temp_t0, temp_s5 = (temp_t0 * 4) + D_80109688, sp28 = (*(f32 *)((char *)(*temp_s5) + 0x34)), temp_fp = ((*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0xE)) * 0xE8) + D_800C469C, sp30 = 0, sp2C = (*(f32 *)((char *)(*temp_s5) + 0x38)), var_v0 = temp_s4 != NULL, (((*(s32 *)((char *)(temp_fp) + 0x60)) & 0xC) != 0)) || (var_v0 = temp_s4 != NULL, ((*(s16 *)((char *)(arg0) + 0x7C)) == 5))) && (var_v0 & (temp_s2 != NULL))) {
        temp_v0 = *temp_s5;
        temp_a0 = (*(f32 *)((char *)(temp_v0) + 0x14));
        temp_a1 = (*(f32 *)((char *)(temp_v0) + 0x18));
        sp38 = (*(f32 *)((char *)(temp_v0) + 0x10));
        sp3C = temp_a0;
        sp40 = temp_a1;
        temp_fa0 = sp2C * 651.8986f;
        sp9C = temp_fa0;
        sp98 = -(sp28 * 651.8986f);
        temp_v0_2 = *temp_s5;
        sp48 = -(((*(f32 *)((char *)(temp_v0_2) + 0x78)) * (*(f32 *)((char *)(temp_s3) + 0x24))) / (*(f32 *)((char *)(temp_v0_2) + 0x4C))) / (*(f32 *)((char *)(temp_v0_2) + 0x68));
        temp_v0_3 = *temp_s5;
        sp50 = 1.0f;
        sp4C = (((*(f32 *)((char *)(temp_v0_3) + 0x7C)) * (*(f32 *)((char *)(temp_s3) + 0x28))) / (*(f32 *)((char *)(temp_v0_3) + 0x4C))) / (*(f32 *)((char *)(temp_v0_3) + 0x6C));
        sp68 = func_800829C8(temp_fa0);
        temp_fs0 = func_800829A0(sp98);
        sp6C = -temp_fs0 * func_800829A0(temp_fa0);
        temp_fs0_2 = func_800829A0(temp_fa0);
        temp_fs0_3 = temp_fs0_2 * func_800829C8(sp98);
        sp74 = 0;
        sp70 = temp_fs0_3;
        sp78 = func_800829C8(sp98);
        sp7C = func_800829A0(sp98);
        sp80 = -func_800829A0(temp_fa0);
        temp_fs0_4 = func_800829C8(temp_fa0);
        sp84 = -(temp_fs0_4 * func_800829A0(sp98));
        temp_fs0_5 = func_800829C8(sp98);
        sp88 = temp_fs0_5 * func_800829C8(temp_fa0);
        func_80045764(&sp48, &sp48);
        func_80083A6C(&sp68, &sp48);
        temp_ft1 = sp48 * 256.0f;
        temp_ft0 = sp4C * 256.0f;
        temp_fv0 = sp50 * 256.0f;
        sp48 = temp_ft1;
        __repair_sp4C_1 = temp_ft0;
        sp50 = temp_fv0;
        sp48 = temp_ft1 + sp38;
        sp4C = temp_ft0 + sp3C;
        sp50 = temp_fv0 + sp40;
        if ((*(s16 *)((char *)(arg0) + 0x7C)) == 5) {
            register temp_v0_4 = (*(void **)((char *)((*(void **)((char *)(temp_s3) + 0xBC))) + 0x6C));
            (*(f32 *)((char *)(temp_v0_4) + 0)) = sp48;
            (*(f32 *)((char *)(temp_v0_4) + 4)) = sp4C;
            (*(f32 *)((char *)(temp_v0_4) + 8)) = sp50;
        }
        if ((func_800158A4(&sp38, &sp48, (*(s32 *)((char *)(*temp_s5) + 0xF4)), &sp58, &spA8, 0, (*(s32 *)((char *)(temp_s3) + 0)), 1, 0) << 0x18) != 0) {
            register sp58 = sp48;
            sp5C = sp4C;
            sp60 = sp50;
        }
        temp_v0_5 = ((*(u16 *)((char *)(temp_fp) + 0x90)) * 0xC) + (*(s32 *)((char *)((*(void **)((char *)(spD4) + 0x68))) + 4));
        temp_a2 = (*(f32 *)((char *)(temp_v0_5) + 8));
        spB0 = (*(f32 *)((char *)(temp_v0_5) + 0));
        spB4 = (*(f32 *)((char *)(temp_v0_5) + 4));
        spB8 = temp_a2;
        spB4 = -spB4;
        spB0 = -spB0;
        { func_80083A6C(&sp68, &spB0, temp_a2); }
        spB0 += (*(f32 *)((char *)(*(((*(s8 *)((char *)(temp_s3) + 0x182)) * 4) + D_80109688)) + 0x10));
        spB8 += (*(f32 *)((char *)(*(((*(s8 *)((char *)(temp_s3) + 0x182)) * 4) + D_80109688)) + 0x18));
        spB4 += (*(f32 *)((char *)(*(((*(s8 *)((char *)(temp_s3) + 0x182)) * 4) + D_80109688)) + 0x14));
        temp_fv0_2 = func_80045540(&spB0, &sp58);
        (*(f32 *)((char *)(temp_s4) + 0x54)) = temp_fv0_2;
        (*(f32 *)((char *)(temp_s4) + 0x24)) = spB0;
        (*(f32 *)((char *)(temp_s4) + 0x28)) = spB4;
        (*(f32 *)((char *)(temp_s4) + 0x2C)) = spB8;
        temp_ft1_2 = spB0 - sp58;
        temp_ft0_2 = spB4 - sp5C;
        temp_fv1 = spB8 - sp60;
        spC0 = temp_ft1_2;
        spC4 = temp_ft0_2;
        spC8 = temp_fv1;
        do { func_80046384(temp_s4 + 0x3C, temp_ft1_2, temp_ft0_2, temp_fv1); } while (0);
        (*(s32 *)((char *)(temp_s4) + 0x44)) = 0;
        (*(s32 *)((char *)(temp_s4) + 0x58)) |= 0x10000;
        (*(f32 *)((char *)(temp_s4) + 0x3C)) = (f32) -(*(f32 *)((char *)(temp_s4) + 0x3C));
        (*(s32 *)((char *)(temp_s2) + 0x58)) |= 0x10000;
        (*(f32 *)((char *)(temp_s2) + 0x24)) = sp58;
        (*(f32 *)((char *)(temp_s2) + 0x28)) = sp5C;
        (*(f32 *)((char *)(temp_s2) + 0x2C)) = sp60;
        if (spA8 == 1) {
            (*(s8 *)((char *)(temp_s2) + 0x7F)) = 0x40;
            (*(s8 *)((char *)(temp_s2) + 0x80)) = 0;
            (*(s8 *)((char *)(temp_s2) + 0x81)) = 0;
        } else {
            (*(u8 *)((char *)(temp_s2) + 0x7F)) = 0xFF;
            (*(u8 *)((char *)(temp_s2) + 0x80)) = 0xFF;
            (*(u8 *)((char *)(temp_s2) + 0x81)) = 0xFF;
        }
        temp_v1 = (*(void **)((char *)(arg0) + 0x68));
        if (((*(u16 *)((char *)(temp_v1) + 0xC)) & 1) && (*(s32 *)(D_800C46FC + ((*(s8 *)((char *)(temp_v1) + 0xE)) * 0xE8)) & 8)) {
            temp_v0_6 = spDC * 0xC;
            *(s32 *)(D_80109A98 + (short)temp_v0_6) = sp58;
            *(s32 *)(D_80109AA0 + temp_v0_6) = sp60;
            *(s32 *)((u32)D_80109A9C + temp_v0_6) = sp5C;
        }
        if ((*(s16 *)((char *)((s32)arg0) + 0x7C)) == 5) {
            spD4 = (*(void **)((char *)((*(void **)((char *)(temp_s3) + 0xBC))) + 0x6C));
            (*(f32 *)((char *)(spD4) + 0)) = sp58;
            (*(f32 *)((char *)(spD4) + 8)) = sp60;
            (*(f32 *)((char *)(spD4) + 4)) = sp5C;
        }
        if ((*(s32 *)((char *)(temp_fp) + 0x60)) & 4) {
            temp_fv0_3 = (f32) ((f64) ((temp_fv0_2 * temp_fv0_2) / D_800C0740) + D_800D44F0);
            (*(f32 *)((char *)(temp_s2) + 0x54)) = temp_fv0_3;
            if (D_800D44F8 < (f64) temp_fv0_3) {
                (*(f32 *)((char *)(temp_s2) + 0x54)) = 4.0f;
            }
            if (D_80102ED8) {
                if (D_801002D4) {
                    func_800643C8(temp_s4);
                }
            } else {
                func_80064318(temp_s4, (*(s8 *)((char *)(temp_s3) + 0x182)));
            }
            func_800643C8(temp_s2);
        }
    }
}
