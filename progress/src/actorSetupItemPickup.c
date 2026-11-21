typedef struct { u16 label; u8 item; u8 pad; } Selection;
typedef struct { u16 *id; u32 unknown[2]; } ItemMap;
typedef struct { u8 pad[8]; u8 index; } Pickup;
extern ItemMap D_800C3CF8[];
extern void *volatile gPickupActor;
extern s32 gPickupSearchBox;
extern void *gSaveMenuState;
extern s16 gSharedItemArg;
extern s8 gSharedItemBusy;
extern u16 gSharedItemId;
extern char sFmtEntryName[];
extern void activateIdList(u16 *);
extern void clearProbeState(void *, s32);
extern s32 findEntryById(s32, s32);
extern void formatTextEntry(s32, char *, s32);
extern void func_8000237C(void *, s32, s32, s32);
extern void func_80002BD0(void *, s32);
extern void func_80002EF0(void *);
extern u16 func_80029C08(s32 *, s32, s32);
extern Pickup *func_8002A980(s32 *);
extern void func_8002ACB4(s32 *);
extern void func_8002B8AC(void);
extern s32 func_8002B9CC(s32);
extern s32 func_8002B9FC(u8);
extern Selection *func_800316C8(void);
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
    func_8002ACB4(searchBox);
    actor = (void **)&gPickupActor;
    if (*actor != NULL) {
        func_80002EF0(*actor);
        FIELD(ACTOR, f32, 0x24) = 0.85f;
        FIELD(ACTOR, f32, 0x28) = 0.25f;
        FIELD(ACTOR, f32, 0x2C) = -3.0f;
        FIELD(ACTOR, f32, 0x54) = 1.05f;
        clearProbeState(*actor, 0x14D);
        if (func_80029C08(searchBox, 2, 0)) {
            pickupEntry = func_8002A980(searchBox);
            if (pickupEntry != NULL) {
                entryTextId = findEntryById(FIELD(gSaveMenuState, s32, 0x10), 0x4000);
                selectionList = func_800316C8();
                if (selectionList != NULL) {
                    if (entryTextId != 0) {
                        formatTextEntry(entryTextId, sFmtEntryName, lookupDataEntry(selectionList[pickupEntry->index].label));
                    }
                    func_8002B8AC();
                    itemId = *D_800C3CF8[func_8002B9CC(func_8002B9FC(selectionList[pickupEntry->index].item))].id;
                    gSharedItemArg = -1;
                    gSharedItemBusy = 1;
                    sharedIdPtr = &gSharedItemId;
                    *sharedIdPtr = itemId;
                    activateIdList(sharedIdPtr);
                    gSharedItemBusy = 0;
                    func_8000237C(*actor, func_8002B9CC(func_8002B9FC(selectionList[pickupEntry->index].item)), 0, 0);
                    func_80002BD0(*actor, 0x14D);
                    FIELD(FIELD(gPickupActor, void *, 0x68), f32, 0x34) = 0.05f;
                }
            }
        }
    }
}
