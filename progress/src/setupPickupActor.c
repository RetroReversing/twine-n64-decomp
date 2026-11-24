/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 allocActorAnimData();
s32 setActorCommandState();
s32 initTextWidget();
s32 spawnTrackMarker();
void *spawnEffectObject();
s32 getTextLength();
s32 setCursorMarker();
s32 updateTrackMarker();
s32 showTextPopup();
s32 formatTextEntry();
s32 findEntryById();
s32 initMenuWindow();
s32 appendWeightedListEntry();
s32 selectItemAndUpdateAmount();
s32 setMenuActiveState();
s32 drawMenuList();
s32 releaseSpawnTableAssets();
s32 getItemTableByte();
s32 findSpawnRecordIndex();
s32 loadSpawnEntryData();
void *getTextRefTableFirstEntry();
s32 getTextRefTableCount();
s32 actorLinkToSurface();
s32 loadTrackIdList();
s32 lookupDataEntry();
extern void *volatile gPickupActor;
extern u16 gSharedItemId;
extern s16 gSharedItemArg;
extern u8 sMenuListKind;
extern char gAssetSlotTable[];
extern s32 *gDefaultOrderObj;
extern char D_80100408[];
extern char D_80102F48[];
extern s8 gSharedItemBusy;
extern void *gSaveMenuState;
extern char gPickupSearchBox[];
extern s32 releaseMenuItemAndMarkers;
extern s32 bindMenuItemRecord;

extern char sFmtEntryName[];
/* Creates or reuses the pickup actor, configures it, links it to the surface list, and sets up the shared item display */ /* Creates or reuses the pickup actor, configures it, links it to the surface list, and sets up the shared item display */ void setupPickupActor(void) {
    u16 *itemIdPtr;
    unsigned int unusedArg;
    s32 entryTextId;
    s32 markerId;
    unsigned slot;
    s32 shownItemId;
    u32 index;
    void *itemList;
    void *newActor;
    char *slotTable;

    slotTable = D_80102F48;

    entryTextId = findEntryById((*(s32 *)((char *)(gSaveMenuState) + 0x10)), 0x4000);
    {
        void *volatile *pickup = &gPickupActor;
        if (*(void **)pickup == NULL) {
            newActor = spawnEffectObject(0, 0, 0);
            *(void **)pickup = newActor;
            if (newActor == NULL) return;
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
          s32 *probe = gDefaultOrderObj;
          *(f32 *)(actor + 0x2C) = depth;
          actorLinkToSurface(*(volatile s32 *)probe, *pickup, 1); }
        slot = 0;
        initMenuWindow(gPickupSearchBox, D_80100408, 0x1A4, 1, 0x32, 0xB4, 0x34, 0xF, 1, &bindMenuItemRecord, &releaseMenuItemAndMarkers);
        setCursorMarker(sMenuListKind, 0x30, 0x30, 0x6E, 0xF);
        itemList = getTextRefTableFirstEntry();
        for (;;) {
            index = slot & 0xFFFF;
            if (!((index < (u32) (getTextRefTableCount() & 0xFFFF)) && (itemList != NULL))) {
                break;
            }
            markerId = spawnTrackMarker(sMenuListKind);
            ((s32 (*)[0x1]) D_80102F48)[index][0x0] = markerId;
            if (markerId) {
                initTextWidget(((s32 (*)[0x1]) D_80102F48)[index][0x0], loadSpawnEntryData(findSpawnRecordIndex(((u8 (*)[0x4]) itemList)[index][0x2])), 0x40);
            }
            markerId = getTextLength(((s32 *)D_80102F48)[index]);
            appendWeightedListEntry(gPickupSearchBox, ((s32 *)D_80102F48)[index], slot & 0xFF, markerId & 0xFF);
            slot++;
        }
        showTextPopup(sMenuListKind);
        updateTrackMarker(sMenuListKind);
        selectItemAndUpdateAmount(gPickupSearchBox, 0);
        setMenuActiveState(gPickupSearchBox, 1);
        drawMenuList(gPickupSearchBox);
        if (entryTextId != 0) {
            formatTextEntry(entryTextId, sFmtEntryName, lookupDataEntry((*(u16 *)((char *)(itemList) + 0))));
        }
        releaseSpawnTableAssets();
        shownItemId = *(u16 *)*(s32 *)(gAssetSlotTable + (getItemTableByte(findSpawnRecordIndex((*(u8 *)((char *)(itemList) + 2)))) * 0xC));
        gSharedItemArg = -1;
        gSharedItemBusy = 1;
        itemIdPtr = &gSharedItemId;
        (*itemIdPtr) = shownItemId;
        loadTrackIdList(itemIdPtr);
        gSharedItemBusy = 0;
        markerId = getItemTableByte(findSpawnRecordIndex(*(u8 *)((char *)itemList + 2)));
        { void *volatile *actor = &gPickupActor;
          allocActorAnimData(*actor, markerId, 0, 0);
          setActorCommandState(*actor, 0x14D); }
        (*(f32 *)((char *)((*(void **)((char *)(gPickupActor) + 0x68))) + 0x34)) = 0.05f;
    }
}



