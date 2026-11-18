/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_8000237C();
s32 func_80002BD0();
s32 func_80002D30();
s32 func_800160FC();
s32 func_800162BC();
void *func_80016410();
s32 func_80018318();
s32 func_80019E28();
s32 func_80022A30();
s32 func_80022AD8();
s32 func_80022DBC();
s16 func_80022DE8();
s32 func_80022E18();
s32 func_80025F78();
s32 func_80026004();
s32 func_800262A8();
void *func_8002638C();
s32 func_80027A7C();
s32 func_8002A644();
s32 func_8002A7CC();
s32 func_8002A9A8();
s32 func_8002AC04();
s32 func_8002ACB4();
s32 func_8002B8AC();
s32 func_8002B9CC();
void *func_8002BA6C();
s32 func_8002BC28();
s32 func_8003E6EC();
s32 func_80044D28();
void *func_80087100();
s32 sprintf();
extern void *D_800B5B14;
extern char D_800BD640[];
extern u16 D_800BD680;
extern s16 D_800BD682;
extern u8 D_800BD68E;
extern s8 D_800BD690;
extern char D_800BF688[];
extern char D_800C3CF8[];
extern s32 *D_800CA31C;
extern char D_8010019C[];
extern char D_801001A0[];
extern char D_801001A2[];
extern char D_801001A3[];
extern u8 D_801002AD;
extern s32 D_801002B4;
extern s32 D_801002B8;
extern s8 D_801002E6;
extern s8 D_801002E7;
extern s8 D_801002E8;
extern s8 D_801002E9;
extern char D_80100408[];
extern s32 D_80102EBC;
extern s32 D_80102EC0;
extern s32 D_80102EC4;
extern char D_80102F48[];
extern s8 D_80104311;
extern s8 D_80107ECC;
extern void *D_80109BB0;
extern char D_8010A488[];
extern s32 func_8001AC88;
extern s32 func_80022C04;

void func_8001ADE8(void) {
    s32 sp34;
    s32 *temp_s0_3;
    s32 var_a1;
    s32 *temp_s0_2;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s3;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a3;
    s32 var_s0;
    s32 var_s2;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_v0_2;
    u16 temp_v1_4;
    u32 temp_s0;
    u8 *temp_s0_4;
    u8 temp_v1_2;
    u8 var_a0_2;
    u8 var_a0_3;
    void *temp_a0_3;
    void *temp_a1;
    void *temp_fp;
    void *temp_s1;
    void *temp_s5;
    void *temp_s6;
    void *temp_s7;
    void *temp_v0_3;
    void *temp_v0_5;
    void *temp_v1_3;
    void *var_a2;

    D_800BD690 = 1;
    temp_fp = func_8002638C(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x70);
    temp_s7 = func_8002638C(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x65);
    temp_s6 = func_8002638C(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x64);
    temp_s5 = func_8002638C(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x6A);
    sp34 = func_800262A8(M2C_FIELD(D_80109BB0, s32 *, 0x10), 0x400C);
    if (((temp_fp != NULL) & (temp_s7 != NULL)) && ((temp_s6 != NULL) & (temp_s5 != NULL)) && (sp34 != 0)) {
        func_8002A644(D_8010A488, D_80100408, 0x1A4, 0xB, 0x2C, 0xB4, 0x32, 0xE, 1, &func_80022C04, &func_8001AC88);
        func_80022A30(D_800BD68E, 0x27, 0x2E, 0x3C, 0x98);
        var_s2 = 0;
        if (D_801002B4 > 0) {
            var_s0 = 0 & 0xFFFF;
            do {
                temp_s3 = func_80022DBC(var_s0);
                temp_v0 = func_800162BC(D_800BD68E);
                *((var_s0 * 4) + D_80102F48) = temp_v0;
                if (temp_v0 != 0) {
                    temp_s1 = func_80087100((var_s2 + 0x4008) & 0xFFFF);
                    temp_s0 = temp_s3 & 0xFFFF;
                    if (temp_s0 < 4U) {
                        var_a2 = func_80087100(0xAD);
                        var_a3 = temp_s0 + 1;
                    } else {
                        var_a2 = func_80087100(0x158);
                        var_a3 = temp_s0 - 3;
                    }
                    sprintf(temp_s1, "%s %d", var_a2, var_a3);
                    func_800160FC(*(((var_s2 & 0xFFFF) * 4) + D_80102F48), temp_s1, 0x40);
                }
                temp_s0_2 = ((var_s2 & 0xFFFF) * 4) + D_80102F48;
                temp_a0 = *temp_s0_2;
                var_s2 += 1;
                func_8002A7CC(D_8010A488, *temp_s0_2, temp_s3 & 0xFF, func_80018318(temp_a0) & 0xFF);
                var_s0 = var_s2 & 0xFFFF;
            } while ((var_s2 & 0xFFFF) < D_801002B4);
        }
        func_80022E18(D_800BD68E);
        func_80022AD8(D_800BD68E);
        func_8002A9A8(D_8010A488, func_80022DE8(D_801002AD));
        func_8002AC04(D_8010A488, 1);
        func_8002ACB4(D_8010A488);
        temp_s0_3 = "%s";
        func_80026004(temp_fp, temp_s0_3, func_8002BA6C(*(D_8010019C + (D_801002AD * 0x18))));
        M2C_FIELD(temp_fp, void **, -0x18) = (void *) ((D_801002AD * 0x18) + (&D_801002AD - 0x111));
        func_80019E28(sp34);
        temp_s0_4 = &D_801002AD - 0x109;
        func_80026004(temp_s7, temp_s0_3, (D_801002AD * 0x18) + temp_s0_4);
        M2C_FIELD(temp_s7, void **, -0x18) = (void *) ((D_801002AD * 0x18) + temp_s0_4);
        temp_v1 = D_801002AD * 0x18;
        D_80104311 = *(D_801001A0 + temp_v1) / 10;
        func_80026004(temp_s6, "%d", (void *) *(D_801001A0 + temp_v1));
        M2C_FIELD(temp_s5, void **, -0x18) = (void *) ((D_801002AD * 0x18) + (&D_801002AD - 0x10B));
        temp_v1_2 = *(D_801001A2 + (D_801002AD * 0x18));
        switch (temp_v1_2) {
        case 0:
            var_a0 = 0xA;
block_19:
            func_80026004(temp_s5, "%s", func_80087100(var_a0));
            break;
        case 1:
            var_a0 = 9;
            goto block_19;
        case 2:
            var_a0 = 0x6B;
            goto block_19;
        case 3:
            var_a0 = 0x6C;
            goto block_19;
        case 4:
            var_a0 = 0x296;
            goto block_19;
        case 5:
            var_a0 = 0x297;
            goto block_19;
        }
        if (M2C_FIELD(D_80109BB0, u8 *, 8) != 1) {
            temp_v1_3 = M2C_FIELD(D_80109BB0, void **, 0x18);
            temp_v0_2 = M2C_FIELD(temp_v1_3, u16 *, 0xC);
            temp_a0_2 = temp_v0_2 & 0xF;
            if (temp_a0_2 != 0) {
                var_v0 = *(D_800BD640 + (temp_a0_2 * 4));
                var_a0_2 = M2C_FIELD(D_80109BB0, u8 *, 0x30);
            } else {
                if (temp_v0_2 & 0x80) {
                    var_v0 = D_80102EBC;
                } else {
                    var_v0 = D_80102EC4;
                }
                var_a0_2 = M2C_FIELD(M2C_FIELD(temp_v1_3, void **, 8), u8 *, 0x13);
            }
            M2C_FIELD(M2C_FIELD(temp_v1_3, void **, 8), s32 *, 0x10) = (s32) ((var_v0 & ~0xFF) | var_a0_2);
            M2C_FIELD(D_80109BB0, u8 *, 8) = 1U;
            M2C_FIELD(D_80109BB0, void **, 0x18) = (void *) (temp_s7 - 0x28);
            temp_v0_3 = M2C_FIELD(D_80109BB0, void **, 0x18);
            temp_a1 = M2C_FIELD(temp_v0_3, void **, 8);
            if (temp_a1 != NULL) {
                temp_v0_4 = M2C_FIELD(temp_v0_3, u16 *, 0xC) & 0xF;
                if (temp_v0_4 != 0) {
                    var_v0_2 = *(D_800BD640 + (temp_v0_4 * 4));
                    var_a0_3 = M2C_FIELD(D_80109BB0, u8 *, 0x30);
                } else {
                    var_v0_2 = D_80102EC0;
                    var_a0_3 = M2C_FIELD(temp_a1, u8 *, 0x13);
                }
                M2C_FIELD(temp_a1, s32 *, 0x10) = (s32) ((var_v0_2 & ~0xFF) | var_a0_3);
            }
            func_80027A7C(M2C_FIELD(D_80109BB0, s32 *, 0x1C), M2C_FIELD(D_80109BB0, void **, 0x18), 0);
        }
        temp_a0_3 = temp_s6 - 0x28;
        if (D_801002B8 < (s32) D_801002AD) {
            M2C_FIELD(temp_s7, s8 *, -1) = 7;
            M2C_FIELD(temp_fp, s8 *, -2) = 1;
            D_801002E8 = 7;
            D_801002E9 = 7;
            D_801002E6 = 1;
            D_801002E7 = 1;
            func_80025F78(temp_a0_3, 0xD);
            func_80025F78(temp_s6, 0xD);
            func_80025F78(temp_s5 - 0x28, 0xD);
            func_80025F78(temp_s5, 0xD);
            func_80026004(temp_s6, "%d", (void *) (*(D_800BF688 + (*(D_8010019C + (D_801002AD * 0x18)) * 0xC)) * 5));
            func_80026004(temp_s5, "%s", func_80087100(0x13));
        } else {
            M2C_FIELD(temp_s7, s8 *, -1) = 3;
            M2C_FIELD(temp_fp, s8 *, -2) = 5;
            D_801002E8 = 7;
            D_801002E9 = 3;
            D_801002E6 = 1;
            D_801002E7 = 1;
            func_80025F78(temp_a0_3, 0);
            func_80025F78(temp_s6, 0);
            func_80025F78(temp_s5 - 0x28, 0);
            func_80025F78(temp_s5, 0);
        }
        if ((D_800B5B14 != NULL) || (temp_v0_5 = func_80016410(0, 0, 0), D_800B5B14 = temp_v0_5, (temp_v0_5 != NULL))) {
            M2C_FIELD(D_800B5B14, s16 *, 0x78) = 0x1F;
            M2C_FIELD(D_800B5B14, s32 *, 0x58) |= 0x400;
            M2C_FIELD(D_800B5B14, s8 *, 0x7E) = 1;
            M2C_FIELD(D_800B5B14, s16 *, 0x7A) = 0;
            M2C_FIELD(D_800B5B14, f32 *, 0x54) = 1.05f;
            M2C_FIELD(D_800B5B14, u8 *, 0x7F) = 0xFF;
            M2C_FIELD(D_800B5B14, u8 *, 0x80) = 0xFF;
            M2C_FIELD(D_800B5B14, u8 *, 0x81) = 0xFF;
            M2C_FIELD(D_800B5B14, f32 *, 0x24) = 1.25f;
            M2C_FIELD(D_800B5B14, f32 *, 0x28) = 0.15f;
            M2C_FIELD(D_800B5B14, f32 *, 0x2C) = -3.0f;
            func_8003E6EC(*D_800CA31C, D_800B5B14, 1);
            func_8002B8AC();
            temp_v1_4 = *(u16 *)*(D_800C3CF8 + (func_8002B9CC(*(D_8010019C + (D_801002AD * 0x18))) * 0xC));
            D_800BD682 = -1;
            D_80107ECC = 1;
            D_800BD680 = temp_v1_4;
            func_80044D28(&D_800BD680);
            D_80107ECC = 0;
            func_8000237C(D_800B5B14, func_8002B9CC(*(D_8010019C + (D_801002AD * 0x18))), 0, *(D_801001A3 + (D_801002AD * 0x18)));
            func_80002BD0(D_800B5B14, 0x14D);
            M2C_FIELD(M2C_FIELD(D_800B5B14, void **, 0x68), f32 *, 0x34) = 0.05f;
            var_a1 = 0x327;
            if (!(func_8002BC28(*(D_8010019C + (D_801002AD * 0x18))) & 0xFF)) {
                var_a1 = 0x2A9;
            }
            func_80002D30(D_800B5B14, var_a1);
        }
    }
}
