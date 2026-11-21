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
void actorSetupItemPickup(void) {
    s32 *box = &gPickupSearchBox;
    void **actor;
    Pickup *pickup;
    s32 entry;
    Selection *selections;
    u16 id;
    u16 *shared;
    func_8002ACB4(box);
    actor = (void **)&gPickupActor;
    if (*actor != NULL) {
        func_80002EF0(*actor);
        FIELD(ACTOR, f32, 0x24) = 0.85f;
        FIELD(ACTOR, f32, 0x28) = 0.25f;
        FIELD(ACTOR, f32, 0x2C) = -3.0f;
        FIELD(ACTOR, f32, 0x54) = 1.05f;
        clearProbeState(*actor, 0x14D);
        if (func_80029C08(box, 2, 0)) {
            pickup = func_8002A980(box);
            if (pickup != NULL) {
                entry = findEntryById(FIELD(gSaveMenuState, s32, 0x10), 0x4000);
                selections = func_800316C8();
                if (selections != NULL) {
                    if (entry != 0) {
                        formatTextEntry(entry, sFmtEntryName, lookupDataEntry(selections[pickup->index].label));
                    }
                    func_8002B8AC();
                    id = *D_800C3CF8[func_8002B9CC(func_8002B9FC(selections[pickup->index].item))].id;
                    gSharedItemArg = -1;
                    gSharedItemBusy = 1;
                    shared = &gSharedItemId;
                    *shared = id;
                    activateIdList(shared);
                    gSharedItemBusy = 0;
                    func_8000237C(*actor, func_8002B9CC(func_8002B9FC(selections[pickup->index].item)), 0, 0);
                    func_80002BD0(*actor, 0x14D);
                    FIELD(FIELD(gPickupActor, void *, 0x68), f32, 0x34) = 0.05f;
                }
            }
        }
    }
}
