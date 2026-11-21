/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000237C();
s32 func_80002BD0();
s32 func_80002D30();
s32 func_800160FC();
s32 func_800162BC();
void *spawnEffectObject();
s32 func_80018318();
s32 func_80019E28();
s32 func_80022A30();
s32 func_80022AD8();
s32 func_80022DBC();
s16 func_80022DE8();
s32 func_80022E18();
s32 func_80025F78();
s32 formatTextEntry();
s32 findEntryById();
void *func_8002638C();
s32 layoutTextBox();
s32 func_8002A644();
s32 func_8002A7CC();
s32 func_8002A9A8();
s32 func_8002AC04();
s32 func_8002ACB4();
s32 func_8002B8AC();
s32 func_8002B9CC();
void *func_8002BA6C();
s32 getKeyEntryFlag();
s32 actorLinkToSurface();
s32 func_80044D28();
void *func_80087100();
s32 sprintf();
extern void *volatile gPickupActor;
extern char D_800BD640[];
extern u16 gSharedItemId;
extern s16 gSharedItemArg;
extern u8 D_800BD68E;
extern s8 D_800BD690;
extern u8 D_800BF688[];
extern char D_800C3CF8[];
extern s32 *gProbeObjectList;
typedef struct { s32 f0; u8 pad[20]; } Slot_8010019C;
extern Slot_8010019C gSaveSlotInfo[];
typedef struct { u8 f0; u8 pad[23]; } Slot_801001A0;
extern Slot_801001A0 D_801001A0[];
extern char D_801001A2[];
extern char D_801001A3[];
extern u8 D_801002AD;
extern s32 D_801002B4;
extern s32 gSaveSlotCount;
extern s8 D_801002E6;
extern s8 D_801002E7;
extern s8 D_801002E8;
extern s8 D_801002E9;
extern char D_80100408[];
extern s32 D_80102EBC;
extern s32 D_80102EC0;
extern s32 D_80102EC4;
extern s32 D_80102F48[];
extern s8 D_80104311;
extern s8 gSharedItemBusy;
extern void *gMenuState;
extern char D_8010A488[];
extern s32 func_8001AC88;
extern s32 func_80022C04;

typedef struct { unsigned char pad[16]; int value; } __repair_field_10;
void func_8001ADE8(void) {
    long sp34;
    s32 *temp_s0_3;
    
    union { s32 * pointer; s32 value; } __repair_phase_storage;
    unsigned int temp_a0;
    s32 temp_a0_2;

    
    register unsigned long temp_v0;
    register s32 temp_v0_4;
    register s32 temp_v1;
    unsigned long var_a0;
s32 __repair_phase_var_a0;
    s32 var_s0;
    s32 var_s2;
    register s32 var_v0;
    
    u16 temp_v0_2;
    u16 temp_v1_4;
    register u32 temp_s0;
    u8 *temp_s0_4;
    u8 temp_v1_2;
    
    void *temp_a0_3;
    void *temp_a1;
    void *temp_fp;
    void *temp_s1;
    void *temp_s5;
    void *temp_s6;
    void *temp_s7;
    void *temp_v0_3;
    register void *temp_v0_5;
    void *temp_v1_3;
    void *var_a2;

    D_800BD690 = 1;
    temp_fp = func_8002638C(((__repair_field_10 *)gMenuState)->value, 0x70);
    temp_s7 = func_8002638C(((__repair_field_10 *)gMenuState)->value, 0x65);
    temp_s6 = func_8002638C(((__repair_field_10 *)gMenuState)->value, 0x64);
    temp_s5 = func_8002638C(((__repair_field_10 *)gMenuState)->value, 0x6A);
    sp34 = findEntryById(((__repair_field_10 *)gMenuState)->value, 0x400C);
    if (((temp_fp != NULL) & (temp_s7 != NULL)) && ((temp_s6 != (int)NULL) & (temp_s5 != NULL)) && (sp34)) {
        func_8002A644(D_8010A488, D_80100408, 0x1A4, 0xB, 0x2C, 0xB4, 0x32, 0xE, 1, &func_80022C04, &func_8001AC88);
        func_80022A30(D_800BD68E, 0x27, 0x2E, 0x3C, 0x98);
        var_s2 = 0;
        if (D_801002B4 > 0) {
            var_s0 = 0 & 0xFFFF;
            do {
                temp_a0_2 = func_80022DBC(var_s0);
                temp_v0 = func_800162BC(D_800BD68E);
                *(s32 *)((var_s0 * 4) + (s32)D_80102F48) = temp_v0;
                if (temp_v0) {
                    temp_s1 = func_80087100((var_s2 + 0x4008) & 0xFFFF);
                    temp_s0 = temp_a0_2 & 0xFFFF;
                    if (temp_s0 < 4U) {
                        var_a2 = func_80087100(0xAD);
                        sprintf(temp_s1, "%s %d", var_a2, temp_s0 + 1);
                    } else {
                        var_a2 = func_80087100(0x158);
                        sprintf(temp_s1, "%s %d", var_a2, temp_s0 - 3);
                    }
                    func_800160FC(*(((var_s2 & 0xFFFF) * 4) + D_80102F48), temp_s1, 0x40);
                }
                __repair_phase_storage.pointer = ((var_s2 & 0xFFFF) * 4) + D_80102F48;
                temp_a0 = *__repair_phase_storage.pointer;
                var_s2++;
                func_8002A7CC(D_8010A488, *__repair_phase_storage.pointer, temp_a0_2 & 0xFF, func_80018318(temp_a0) & 0xFF);
                var_s0 = var_s2 & 0xFFFF;
            } while ((var_s2 & 0xFFFF) < D_801002B4);
        }
        func_80022E18(D_800BD68E);
        func_80022AD8(D_800BD68E);
        func_8002A9A8(D_8010A488, func_80022DE8(D_801002AD));
        func_8002AC04(D_8010A488, 1);
        func_8002ACB4(D_8010A488);
        temp_s0_3 = "%s";
        formatTextEntry(temp_fp, temp_s0_3, func_8002BA6C(gSaveSlotInfo[D_801002AD].f0));
        (*(void **)((char *)(temp_fp) + -0x18)) = (void *) (((u32)D_801002AD * 0x18) + (&D_801002AD - 0x111));
        func_80019E28(sp34);
        temp_s0_4 = &D_801002AD - 0x109;
        formatTextEntry(temp_s7, temp_s0_3, (D_801002AD * 0x18) + temp_s0_4);
        (*(void **)((char *)(temp_s7) + -0x18)) = (void *) ((D_801002AD * 0x18) + temp_s0_4);
        temp_v1 = D_801002AD * 0x18;
        D_80104311 = D_801001A0[D_801002AD].f0 / 10;
        formatTextEntry(temp_s6, "%d", (void *) D_801001A0[D_801002AD].f0);
        (*(void **)((char *)(temp_s5) + -0x18)) = (void *) ((D_801002AD * 0x18) + (&D_801002AD - 0x10B));
        temp_v1_2 = *(u16 *)(D_801001A2 + (D_801002AD * 0x18));
        switch (temp_v1_2) {
        case 0:
            var_a0 = 0xA;
            formatTextEntry(temp_s5, "%s", func_80087100(var_a0));
            break;
        case 1:
            var_a0 = 9;
            {
            formatTextEntry(temp_s5, "%s", func_80087100(var_a0));break;}
        case 2:
            var_a0 = 0x6B;
            {
            formatTextEntry(temp_s5, "%s", func_80087100(var_a0));break;}
        case 3:
            var_a0 = 0x6C;
            formatTextEntry(temp_s5, "%s", func_80087100(var_a0));
            break;
        case 4:
            var_a0 = 0x296;
            formatTextEntry(temp_s5, "%s", func_80087100(var_a0));
            break;
        case 5:
            __repair_phase_var_a0 = 0x297;
            formatTextEntry(temp_s5, "%s", func_80087100(__repair_phase_var_a0));
            break;
        }
        if ((*(u8 *)((char *)(gMenuState) + 8)) != 1) {
            temp_v1_3 = (*(void **)((char *)(gMenuState) + 0x18));
            temp_v0_2 = (*(u16 *)((char *)(temp_v1_3) + 0xC));
            __repair_phase_storage.value = temp_v0_2 & 0xF;
            if (__repair_phase_storage.value != 0) {
                var_v0 = *(s32 *)(D_800BD640 + (__repair_phase_storage.value * 4));
                (*(s32 *)((char *)((*(void **)((char *)(temp_v1_3) + 8))) + 0x10)) = (s32) ((var_v0 & ~0xFF) | (*(u8 *)((char *)(gMenuState) + 0x30)));
            } else {
                if (temp_v0_2 & 0x80) {
                    var_v0 = D_80102EBC;
                } else {
                    var_v0 = D_80102EC4;
                }
                (*(s32 *)((char *)((*(void **)((char *)(temp_v1_3) + 8))) + 0x10)) = (s32) ((var_v0 & ~0xFF) | (*(u8 *)((char *)((*(void **)((char *)(temp_v1_3) + 8))) + 0x13)));
            }
            (*(u8 *)((char *)(gMenuState) + 8)) = 1U;
            (*(void **)((char *)(gMenuState) + 0x18)) = (void *) (temp_s7 - 0x28);
            temp_a1 = (*(void **)((char *)(temp_v0_3) + 8));
            temp_v0_3 = (*(void **)((char *)(gMenuState) + 0x18));
            if (temp_a1 != NULL) {
                temp_v0_4 = (*(u16 *)((char *)(temp_v0_3) + 0xC)) & 0xF;
                if (temp_v0_4) {
                    temp_a0_2 = *(s32 *)(D_800BD640 + (temp_v0_4 * 4));
                    __repair_phase_storage.value = (*(u8 *)((char *)(gMenuState) + 0x30));
                } else {
                    temp_a0_2 = D_80102EC0;
                    __repair_phase_storage.value = (*(u8 *)((char *)(temp_a1) + 0x13));
                }
                ((__repair_field_10 *)temp_a1)->value = (s32) ((temp_a0_2 & ~0xFF) | __repair_phase_storage.value);
            }
            layoutTextBox((*(s32 *)((char *)(gMenuState) + 0x1C)), (*(void **)((char *)(gMenuState) + 0x18)), 0);
        }
        temp_a0_3 = temp_s6 - 0x28;
        if (gSaveSlotCount < (s32) D_801002AD) {
            (*(s8 *)((char *)(temp_s7) + -1)) = 7;
            (*(s8 *)((char *)(temp_fp) + -2)) = 1;
            D_801002E8 = 7;
            D_801002E9 = 7;
            D_801002E6 = 1;
            D_801002E7 = 1;
            func_80025F78(temp_a0_3, 0xD);
            func_80025F78(temp_s6, 0xD);
            func_80025F78(temp_s5 - 0x28, 0xD);
            func_80025F78(temp_s5, 0xD);
            formatTextEntry(temp_s6, "%d", (void *) (*(u16 *)(D_800BF688 + (gSaveSlotInfo[D_801002AD].f0 * 0xC)) * 5));
            formatTextEntry(temp_s5, "%s", func_80087100(0x13));
        } else {
            (*(s8 *)((char *)(temp_s7) + -1)) = 3;
            (*(s8 *)((char *)(temp_fp) + -2)) = 5;
            D_801002E8 = 7;
            D_801002E9 = 3;
            D_801002E6 = 1;
            D_801002E7 = 1;
            func_80025F78(temp_a0_3, 0);
            func_80025F78(temp_s6, 0);
            func_80025F78(temp_s5 - 0x28, 0);
            func_80025F78(temp_s5, 0);
        }
        if ((gPickupActor != NULL) || (temp_v0_5 = spawnEffectObject(0, 0, 0), gPickupActor = temp_v0_5, (temp_v0_5 != NULL))) {
            (*(s16 *)((char *)(gPickupActor) + 0x78)) = 0x1F;
            (*(s32 *)((char *)(gPickupActor) + 0x58)) |= 0x400;
            (*(s8 *)((char *)(gPickupActor) + 0x7E)) = 1;
            (*(f32 *)((char *)(gPickupActor) + 0x54)) = 1.05f;
            (*(s16 *)((char *)(gPickupActor) + 0x7A)) = 0;
            (*(u8 *)((char *)(gPickupActor) + 0x7F)) = 0xFF;
            (*(u8 *)((char *)(gPickupActor) + 0x80)) = 0xFF;
            (*(f32 *)((char *)(gPickupActor) + 0x24)) = 1.25f;
            (*(f32 *)((char *)(gPickupActor) + 0x28)) = 0.15f;
            (*(u8 *)((char *)(gPickupActor) + 0x81)) = 0xFF;
            actorLinkToSurface(*gProbeObjectList, gPickupActor, 1);
            (*(f32 *)((char *)(gPickupActor) + 0x2C)) = -3.0f;
            func_8002B8AC();
            temp_v1_4 = *(u16 *)*(s32 *)(D_800C3CF8 + (func_8002B9CC(gSaveSlotInfo[D_801002AD].f0) * 0xC));
            gSharedItemArg = -1;
            gSharedItemBusy = 1;
            gSharedItemId = temp_v1_4;
            func_80044D28(&gSharedItemId);
            gSharedItemBusy = 0;
            func_8000237C(gPickupActor, func_8002B9CC(gSaveSlotInfo[D_801002AD].f0), 0, *(u16 *)(D_801001A3 + (D_801002AD * 0x18)));
            func_80002BD0(gPickupActor, 0x14D);
            (*(f32 *)((char *)((*(void **)((char *)(gPickupActor) + 0x68))) + 0x34)) = 0.05f;
            temp_a0_2 = 0x327;
            if (!(getKeyEntryFlag(gSaveSlotInfo[D_801002AD].f0) & 0xFF)) {
                temp_a0_2 = 0x2A9;
            }
            func_80002D30(gPickupActor, temp_a0_2);
        }
    }
}
