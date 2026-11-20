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
s32 formatTextEntry();
s32 findEntryById();
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
s32 actorLinkToSurface();
s32 func_80044D28();
s32 func_80087100();
extern void *volatile gPickupActor;
extern u16 gSharedItemId;
extern s16 gSharedItemArg;
extern u8 D_800BD68E;
extern char D_800C3CF8[];
extern s32 *D_800CA31C;
extern char D_80100408[];
extern char D_80102F48[];
extern s8 gSharedItemBusy;
extern void *D_80109BB0;
extern char D_8010A488[];
extern s32 func_8001AC88;
extern s32 func_80022C04;

extern char D_800D2864[];
void func_8001B6F0(void) {
    u16 *__base_D_800BD680;
    unsigned int temp_a2;
    s32 temp_s4;
    s32 temp_v0_2;
    unsigned var_s1;
    s32 temp_v1_2;
    u32 temp_s0;
    void *temp_s2;
    void *temp_v0;
    char *__base_D_80102F48;

    __base_D_80102F48 = (s32)D_80102F48;

    temp_s4 = findEntryById((*(s32 *)((char *)(D_80109BB0) + 0x10)), 0x4000);
    if ((gPickupActor != NULL) || (temp_v0 = func_80016410(0, 0, 0), gPickupActor = temp_v0, (temp_v0 != NULL))) {
        (*(s16 *)((char *)(gPickupActor) + 0x78)) = 0x1F;
        (*(s32 *)((char *)(gPickupActor) + 0x58)) |= 0x400;
        (*(s8 *)((char *)(gPickupActor) + 0x7E)) = 1;
        (*(s16 *)((char *)(gPickupActor) + 0x7A)) = 0;
        (*(f32 *)((char *)(gPickupActor) + 0x54)) = 1.05f;
        (*(u8 *)((char *)(gPickupActor) + 0x7F)) = 0xFF;
        (*(u8 *)((char *)(gPickupActor) + 0x80)) = 0xFF;
        (*(u8 *)((char *)(gPickupActor) + 0x81)) = 0xFF;
        (*(f32 *)((char *)(gPickupActor) + 0x24)) = 0.85f;
        (*(f32 *)((char *)(gPickupActor) + 0x28)) = 0.25f;
        (*(f32 *)((char *)(gPickupActor) + 0x2C)) = -3.0f;
        var_s1 = 0;
        actorLinkToSurface(*D_800CA31C, gPickupActor);
        func_8002A644(D_8010A488, D_80100408, 0x1A4, 1, 0x32, 0xB4, 0x34, 0xF, 1, &func_80022C04, &func_8001AC88);
        func_80022A30(D_800BD68E, 0x30, 0x30, 0x6E, 0xF);
        temp_s2 = func_800316C8();
        for (;;) {
            temp_s0 = var_s1 & 0xFFFF;
            if (!((temp_s0 < (u32) (func_800316E4() & 0xFFFF)) && (temp_s2 != NULL))) {
                break;
            }
            temp_v0_2 = func_800162BC(D_800BD68E);
            ((s32 (*)[0x1]) D_80102F48)[temp_s0][0x0] = temp_v0_2;
            if (temp_v0_2) {
                func_800160FC(((s32 (*)[0x1]) D_80102F48)[temp_s0][0x0], func_8002BA6C(func_8002B9FC(((u8 (*)[0x4]) temp_s2)[temp_s0][0x2])), 0x40);
            }
            var_s1 += 1;
            temp_a2 = var_s1 & 0xFF;
            func_8002A7CC(D_8010A488, ((s32 (*)[0x1]) D_80102F48)[temp_s0][0x0], temp_a2, func_80018318(((s32 (*)[0x1]) D_80102F48)[temp_s0][0x0]) & 0xFF);
        }
        func_80022E18(D_800BD68E);
        func_80022AD8(D_800BD68E);
        func_8002A9A8(D_8010A488, 0);
        func_8002AC04(D_8010A488, 1);
        func_8002ACB4(D_8010A488);
        if (temp_s4 != 0) {
            formatTextEntry(temp_s4, D_800D2864, func_80087100((*(u16 *)((char *)(temp_s2) + 0))));
        }
        func_8002B8AC();
        temp_v1_2 = *(u16 *)*(s32 *)(D_800C3CF8 + (func_8002B9CC(func_8002B9FC((*(u8 *)((char *)(temp_s2) + 2)))) * 0xC));
        gSharedItemArg = -1;
        gSharedItemBusy = 1;
        __base_D_800BD680 = &gSharedItemId;
        (*__base_D_800BD680) = temp_v1_2;
        func_80044D28(__base_D_800BD680);
        gSharedItemBusy = 0;
        func_8000237C(gPickupActor, func_8002B9CC(func_8002B9FC((*(u8 *)((char *)(temp_s2) + 2)))), 0, 0);
        func_80002BD0(gPickupActor, 0x14D);
        (*(f32 *)((char *)((*(void **)((char *)(gPickupActor) + 0x68))) + 0x34)) = 0.05f;
    }
}
