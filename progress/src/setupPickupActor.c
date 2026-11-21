/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000237C();
s32 func_80002BD0();
s32 func_800160FC();
s32 func_800162BC();
void *spawnEffectObject();
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
s32 activateIdList();
s32 lookupDataEntry();
extern void *volatile gPickupActor;
extern u16 gSharedItemId;
extern s16 gSharedItemArg;
extern u8 gMenuListParam;
extern char D_800C3CF8[];
extern s32 *gProbeObjectList;
extern char D_80100408[];
extern char D_80102F48[];
extern s8 gSharedItemBusy;
extern void *gMenuState;
extern char gPickupSearchBox[];
extern s32 func_8001AC88;
extern s32 bindMenuItemRecord;

extern char sFmtEntryName[];
/* Creates or reuses the pickup actor, configures it, links it to the surface list, and sets up the shared item display */ void setupPickupActor(void) {
    u16 *__base_D_800BD680;
    unsigned int temp_a2;
    s32 entryText;
    s32 result;
    unsigned i;
    s32 itemId;
    u32 index;
    void *itemList;
    void *temp_v0;
    char *__base_D_80102F48;

    __base_D_80102F48 = D_80102F48;

    entryText = findEntryById((*(s32 *)((char *)(gMenuState) + 0x10)), 0x4000);
    {
        void *volatile *pickup = &gPickupActor;
        if (*(void **)pickup == NULL) {
            temp_v0 = spawnEffectObject(0, 0, 0);
            *(void **)pickup = temp_v0;
            if (temp_v0 == NULL) return;
        }
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
        { char *actor = gPickupActor;
          f32 depth = -3.0f;
          s32 *probe = gProbeObjectList;
          *(f32 *)(actor + 0x2C) = depth;
          actorLinkToSurface(*(volatile s32 *)probe, *pickup, 1); }
        i = 0;
        func_8002A644(gPickupSearchBox, D_80100408, 0x1A4, 1, 0x32, 0xB4, 0x34, 0xF, 1, &bindMenuItemRecord, &func_8001AC88);
        func_80022A30(gMenuListParam, 0x30, 0x30, 0x6E, 0xF);
        itemList = func_800316C8();
        for (;;) {
            index = i & 0xFFFF;
            if (!((index < (u32) (func_800316E4() & 0xFFFF)) && (itemList != NULL))) {
                break;
            }
            result = func_800162BC(gMenuListParam);
            ((s32 (*)[0x1]) D_80102F48)[index][0x0] = result;
            if (result) {
                func_800160FC(((s32 (*)[0x1]) D_80102F48)[index][0x0], func_8002BA6C(func_8002B9FC(((u8 (*)[0x4]) itemList)[index][0x2])), 0x40);
            }
            result = func_80018318(((s32 *)D_80102F48)[index]);
            func_8002A7CC(gPickupSearchBox, ((s32 *)D_80102F48)[index], i & 0xFF, result & 0xFF);
            i++;
        }
        func_80022E18(gMenuListParam);
        func_80022AD8(gMenuListParam);
        func_8002A9A8(gPickupSearchBox, 0);
        func_8002AC04(gPickupSearchBox, 1);
        func_8002ACB4(gPickupSearchBox);
        if (entryText != 0) {
            formatTextEntry(entryText, sFmtEntryName, lookupDataEntry((*(u16 *)((char *)(itemList) + 0))));
        }
        func_8002B8AC();
        itemId = *(u16 *)*(s32 *)(D_800C3CF8 + (func_8002B9CC(func_8002B9FC((*(u8 *)((char *)(itemList) + 2)))) * 0xC));
        gSharedItemArg = -1;
        gSharedItemBusy = 1;
        __base_D_800BD680 = &gSharedItemId;
        (*__base_D_800BD680) = itemId;
        activateIdList(__base_D_800BD680);
        gSharedItemBusy = 0;
        result = func_8002B9CC(func_8002B9FC(*(u8 *)((char *)itemList + 2)));
        { void *volatile *actor = &gPickupActor;
          func_8000237C(*actor, result, 0, 0);
          func_80002BD0(*actor, 0x14D); }
        (*(f32 *)((char *)((*(void **)((char *)(gPickupActor) + 0x68))) + 0x34)) = 0.05f;
    }
}


