typedef struct { u8 pad0[0x78C]; s32 w78C; s32 w790; } Ctx828C;

s32 heapAllocTagged(s32, s32);
extern s32 sAuxPoolCount;
extern s32 sMatrixPoolCount;
extern s32 sMatrixPoolLimit;
extern s32 gBorderSkipActive;
extern s32 gGameMode;
extern Ctx828C *sMatrixPoolSlots[];
extern u16 sMatrixPoolSlotCount;

void initMatrixPools(void) {
    u32 i;

    if (gBorderSkipActive != 0) {
        sMatrixPoolCount = 0x640;
        sAuxPoolCount = 0x1388;
    } else {
        sMatrixPoolCount = 0x190;
        sAuxPoolCount = 0xBB8;
        if (gGameMode == 0x24) {
            sAuxPoolCount = 0xE74;
        }
    }
    sMatrixPoolLimit = sMatrixPoolCount - 1;
    for (i = 0; i < sMatrixPoolSlotCount; i++) {
        sMatrixPoolSlots[i]->w790 = heapAllocTagged(sAuxPoolCount * 8, 0x31);
        sMatrixPoolSlots[i]->w78C = heapAllocTagged(sMatrixPoolCount << 6, 0x31);
    }
}
