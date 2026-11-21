typedef struct {
    u8 pad0[0x78];
    u16 type;
} NearbyObject;

f32 approxDistance(void *, void *);
s8 func_8005FE20(NearbyObject *, void *);
extern f64 D_800D41D8;
extern s32 gSaveTotalSlots;
extern s32 gBonusObjects;

s8 func_8005FD28(void *object) {
    u16 i = 0;
    if (gSaveTotalSlots > 0) {
        NearbyObject **objects = (NearbyObject **)&gBonusObjects;
        s32 excludedA = 0x4D;
        s32 excludedB = 0x61;
        f64 distance = D_800D41D8;
        do {
            NearbyObject **slot = (NearbyObject **)(((u32)(u16)i << 2) + (u32)objects);
            NearbyObject *other = *slot;
            if (other != NULL) {
                u16 type = other->type;
                if (type == excludedA) goto next;
                if (type == excludedB) goto next;
                if ((f64)approxDistance((u8 *)other + 0x24, (u8 *)object + 0x24) < distance) {
                    return func_8005FE20(*slot, object);
                }
            }
next:
            i++;
        } while ((u16)i < gSaveTotalSlots);
    }
    return 0;
}
