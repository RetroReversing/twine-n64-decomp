typedef struct { u16 label; u8 item; u8 pad; } Selection;
typedef struct { u16 *id; u32 unknown[2]; } ItemMap;
typedef struct { u8 pad[8]; u8 index; } Pickup;
extern ItemMap gAssetSlotTable[];
extern void *volatile gPickupActor;
extern s32 gPickupSearchBox;
extern void *gSaveMenuState;
extern s16 gSharedItemArg;
extern s8 gSharedItemBusy;
extern u16 gSharedItemId;
extern char sFmtEntryName[];
extern void loadTrackIdList(u16 *);
extern void clearProbeState(void *, s32);
extern s32 findEntryById(s32, s32);
extern void formatTextEntry(s32, char *, s32);
extern void allocActorAnimData(void *, s32, s32, s32);
extern void setActorCommandState(void *, s32);
extern void updateActorAnimation(void *);
extern u16 updateSaveMenuRowHighlight(s32 *, s32, s32);
extern Pickup *getSelectedMenuEntry(s32 *);
extern void drawMenuList(s32 *);
extern void releaseSpawnTableAssets(void);
extern s32 getItemTableByte(s32);
extern s32 findSpawnRecordIndex(u8);
extern Selection *getTextRefTableFirstEntry(void);
extern s32 lookupDataEntry(u16);
#define FIELD(p,t,o) (*(t *)((u8 *)(p)+(o)))
#define ACTOR gPickupActor
/* Reconfigures the existing pickup actor, shows the selected item's name and id, and activates it */
void actorSetupItemPickup(void) {
    s32 *searchBox = &gPickupSearchBox;
    void **actor;
    Pickup *pickupEntry;
    s32 entryTextId;
    Selection *selectionList;
    u16 itemId;
    u16 *sharedIdPtr;
    drawMenuList(searchBox);
    actor = (void **)&gPickupActor;
    if (*actor != NULL) {
        updateActorAnimation(*actor);
        FIELD(ACTOR, f32, 0x24) = 0.85f;
        FIELD(ACTOR, f32, 0x28) = 0.25f;
        FIELD(ACTOR, f32, 0x2C) = -3.0f;
        FIELD(ACTOR, f32, 0x54) = 1.05f;
        clearProbeState(*actor, 0x14D);
        if (updateSaveMenuRowHighlight(searchBox, 2, 0)) {
            pickupEntry = getSelectedMenuEntry(searchBox);
            if (pickupEntry != NULL) {
                entryTextId = findEntryById(FIELD(gSaveMenuState, s32, 0x10), 0x4000);
                selectionList = getTextRefTableFirstEntry();
                if (selectionList != NULL) {
                    if (entryTextId != 0) {
                        formatTextEntry(entryTextId, sFmtEntryName, lookupDataEntry(selectionList[pickupEntry->index].label));
                    }
                    releaseSpawnTableAssets();
                    itemId = *gAssetSlotTable[getItemTableByte(findSpawnRecordIndex(selectionList[pickupEntry->index].item))].id;
                    gSharedItemArg = -1;
                    gSharedItemBusy = 1;
                    sharedIdPtr = &gSharedItemId;
                    *sharedIdPtr = itemId;
                    loadTrackIdList(sharedIdPtr);
                    gSharedItemBusy = 0;
                    allocActorAnimData(*actor, getItemTableByte(findSpawnRecordIndex(selectionList[pickupEntry->index].item)), 0, 0);
                    setActorCommandState(*actor, 0x14D);
                    FIELD(FIELD(gPickupActor, void *, 0x68), f32, 0x34) = 0.05f;
                }
            }
        }
    }
}
