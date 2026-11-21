/* Sets up the pickup actor and, when a matching entry exists, loads its item into the shared item slot and plays its animation. */
s32 func_8000237C();
s32 func_80002BD0();
s32 func_80002D30();
s32 func_80002EF0();
s32 formatTextEntry();
s32 findEntryById();
s32 func_80029C08();
void *func_8002A980();
s32 func_8002ACB4();
s32 func_8002B8AC();
s32 func_8002B9CC();
s32 func_8002B9FC();
s32 func_800316C8();
s32 activateIdList();
s32 lookupDataEntry();
extern void *volatile gPickupActor;
extern u16 gSharedItemId;
extern s16 gSharedItemArg;
extern char D_800C3CF8[];
extern s8 D_80107ECC;
extern void *gMenuState;
extern char gPickupSearchBox[];
extern char D_800D2864[];

void actorSetupItemPickup(void) {
    void *pickupActor;
    s32 itemTable;
    void *volatile *pickupActorRef;
    long msgBuffer;
    void *pickupEntry;
    u16 itemIdValue;
    u16 *sharedItemIdRef;

    func_8002ACB4(gPickupSearchBox);
    pickupActorRef = &gPickupActor;
    pickupActor = *pickupActorRef;
    if (pickupActor != NULL) {
        func_80002EF0(pickupActor);
        (*(f32 *)((char *)(gPickupActor) + 0x24)) = 0.85f;
        (*(f32 *)((char *)(gPickupActor) + 0x28)) = 0.25f;
        (*(f32 *)((char *)(gPickupActor) + 0x2C)) = -3.0f;
        (*(f32 *)((char *)(gPickupActor) + 0x54)) = 1.05f;
        func_80002D30((*pickupActorRef), 0x14D);
        if (func_80029C08(gPickupSearchBox, 2, 0) & 0xFFFF) {
            pickupEntry = func_8002A980(gPickupSearchBox);
            if (pickupEntry != NULL) {
                msgBuffer = findEntryById((*(s32 *)((char *)(gMenuState) + 0x10)), 0x4000);
                itemTable = func_800316C8();
                if (itemTable != 0) {
                    if (msgBuffer) {
                        formatTextEntry(msgBuffer, D_800D2864, lookupDataEntry(*(u16 *)(((*(u8 *)((char *)(pickupEntry) + 8)) * 4) + itemTable)));
                    }
                    func_8002B8AC();
                    itemIdValue = *(u16 *)*(s32 *)(D_800C3CF8 + (func_8002B9CC(func_8002B9FC((*(u8 *)((char *)((((*(u8 *)((char *)(pickupEntry) + 8)) * 4) + (int)itemTable)) + 2)))) * 0xC));
                    gSharedItemArg = -1;
                    D_80107ECC = 1;
                    sharedItemIdRef = &gSharedItemId;
                    (*sharedItemIdRef) = itemIdValue;
                    activateIdList(sharedItemIdRef);
                    D_80107ECC = 0;
                    func_8000237C((*pickupActorRef), func_8002B9CC(func_8002B9FC((*(u8 *)((char *)((((*(u8 *)((char *)(pickupEntry) + 8)) * 4) + itemTable)) + 2)))), 0, 0);
                    func_80002BD0((*pickupActorRef), 0x14D);
                    (*(f32 *)((char *)((*(void **)((char *)(gPickupActor) + 0x68))) + 0x34)) = 0.05f;
                }
            }
        }
    }
}
