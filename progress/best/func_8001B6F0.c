/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000237C();
s32 func_80002BD0();
s32 func_800160FC();
s32 func_800162BC();
void *func_80016410();
s32 func_80018318();
s32 func_80022A30();
s32 func_80022AD8();
s32 func_80022E18();
s32 func_80026004();
s32 func_800262A8();
s32 func_8002A644();
s32 func_8002A7CC();
s32 func_8002A9A8();
s32 func_8002AC04();
s32 func_8002ACB4();
s32 func_8002B8AC();
s32 func_8002B9CC();
s32 func_8002B9FC();
s32 func_8002BA6C();
void *func_800316C8();
s32 func_800316E4();
s32 func_8003E6EC();
s32 func_80044D28();
s32 func_80087100();
extern void *D_800B5B14;
extern u16 D_800BD680;
extern s16 D_800BD682;
extern u8 D_800BD68E;
extern char D_800C3CF8[];
extern s32 *D_800CA31C;
extern char D_80100408[];
extern char D_80102F48[];
extern s8 D_80107ECC;
extern void *D_80109BB0;
extern char D_8010A488[];
extern s32 func_8001AC88;
extern s32 func_80022C04;

void func_8001B6F0(void) {
    s32 *temp_s0_2;
    s32 temp_a2;
    unsigned temp_s4;
    s32 temp_v0_2;
    u32 temp_v1;
    s32 var_s1;
    u16 temp_v1_2;
    u32 temp_s0;
    void *temp_s2;
    void *temp_v0;

    temp_s4 = func_800262A8((*(s32 *)((char *)(D_80109BB0) + 0x10)), 0x4000);
    if ((D_800B5B14 != NULL) || (temp_v0 = func_80016410(0, 0, 0), D_800B5B14 = temp_v0, (temp_v0 != NULL))) {
        (*(s16 *)((char *)(D_800B5B14) + 0x78)) = 0x1F;
        (*(s32 *)((char *)(D_800B5B14) + 0x58)) |= 0x400;
        (*(s8 *)((char *)(D_800B5B14) + 0x7E)) = 1;
        (*(s16 *)((char *)(D_800B5B14) + 0x7A)) = 0;
        (*(f32 *)((char *)(D_800B5B14) + 0x54)) = 1.05f;
        (*(u8 *)((char *)(D_800B5B14) + 0x7F)) = 0xFF;
        (*(u8 *)((char *)(D_800B5B14) + 0x80)) = 0xFF;
        (*(u8 *)((char *)(D_800B5B14) + 0x81)) = 0xFF;
        (*(f32 *)((char *)(D_800B5B14) + 0x24)) = 0.85f;
        (*(f32 *)((char *)(D_800B5B14) + 0x2C)) = -3.0f;
        (*(f32 *)((char *)(D_800B5B14) + 0x28)) = 0.25f;
        var_s1 = 0;
        func_8003E6EC(*D_800CA31C);
        func_8002A644(D_8010A488, D_80100408, 0x1A4, 1, 0x32, 0xB4, 0x34, 0xF, 1, &func_80022C04, &func_8001AC88);
        func_80022A30(D_800BD68E, 0x30, 0x30, 0x6E, 0xF);
        temp_s2 = func_800316C8();
loop_3:
        temp_s0 = var_s1 & 0xFFFF;
        if ((temp_s0 < (u32) (func_800316E4() & 0xFFFF)) && (temp_s2 != NULL)) {
            temp_v0_2 = func_800162BC(D_800BD68E);
            temp_v1 = temp_s0 * 4;
            temp_s0_2 = temp_v1 + D_80102F48;
            *temp_s0_2 = temp_v0_2;
            if (temp_v0_2) {
                func_800160FC(*temp_s0_2, func_8002BA6C(func_8002B9FC((*(u8 *)((char *)((temp_v1 + temp_s2)) + 2)))), 0x40);
            }
            temp_a2 = var_s1 & 0xFF;/*__repair_loop_weight*/do {do {do {
            var_s1 += 1;} while (0);} while (0);} while (0);
            func_8002A7CC(D_8010A488, *temp_s0_2, temp_a2, func_80018318(*temp_s0_2) & 0xFF);
            goto loop_3;
        }
        func_80022E18(D_800BD68E);
        func_80022AD8(D_800BD68E);
        func_8002A9A8(D_8010A488, 0);
        func_8002AC04(D_8010A488, 1);
        func_8002ACB4(D_8010A488);
        if (temp_s4 != 0) {
            func_80026004(temp_s4, "%s", func_80087100((*(u16 *)((char *)(temp_s2) + 0))));
        }
        func_8002B8AC();
        temp_v1_2 = *(u16 *)*(s32 *)(D_800C3CF8 + (func_8002B9CC(func_8002B9FC((*(u8 *)((char *)(temp_s2) + 2)))) * 0xC));
        D_800BD682 = -1;
        D_80107ECC = 1;
        D_800BD680 = temp_v1_2;
        func_80044D28(&D_800BD680);
        D_80107ECC = 0;
        func_8000237C(D_800B5B14, func_8002B9CC(func_8002B9FC((*(u8 *)((char *)(temp_s2) + 2)))), 0, 0);
        func_80002BD0(D_800B5B14, 0x14D);
        (*(f32 *)((char *)((*(void **)((char *)(D_800B5B14) + 0x68))) + 0x34)) = 0.05f;
    }
}
