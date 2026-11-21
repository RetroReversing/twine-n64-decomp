extern char sSaveSlotTable[];
extern u8 gSceneType;
extern u8 gSaveKeyRelaxed;
extern s32 D_801002A8;
extern s8 D_801002AE;

s32 getSaveSlotIndex(s32 slot);
s32 func_8002B000(void *arg0, s32 arg1);
void *heapAllocTagged();

/* Allocates the save-slot state for a save menu object and fills in its defaults, scene-dependent values and slot rank. */
void initSaveMenuSlot(void *menu, u8 slot) {
    void *state;

    state = heapAllocTagged(0x14, 0x2C);
    *(void **)((char *)menu + 0xB4) = state;
    *(s16 *)((char *)(*(void **)((char *)menu + 0xB4)) + 0xC) = 0;
    func_8002B000(*(void **)((char *)menu + 0xB4), 0x1E);
    *(s16 *)((char *)(*(void **)((char *)menu + 0xB4)) + 0xE) = 0;
    D_801002AE = 0;
    *(s8 *)((char *)(*(void **)((char *)menu + 0xB4)) + 0x10) = 0;
    *(s32 *)((char *)(*(void **)((char *)menu + 0xB4)) + 8) = 0;
    *(s8 *)((char *)(*(void **)((char *)menu + 0xB4)) + 0x11) = 0;
    if (gSceneType == 7) {
        *(s8 *)((char *)(*(void **)((char *)menu + 0xB4)) + 0x11) = (s8) D_801002A8;
        *(s16 *)((char *)(*(void **)((char *)menu + 0xB4)) + 0xC) = (s16) D_801002A8;
    }
    if (gSaveKeyRelaxed != 0) {
        *(u8 *)((char *)(*(void **)((char *)menu + 0xB4)) + 0x12) = (u8) *(sSaveSlotTable + ((getSaveSlotIndex(slot & 0xFF) & 0xFFFF) * 0x18));
        return;
    }
    *(u8 *)((char *)(*(void **)((char *)menu + 0xB4)) + 0x12) = 2U;
}
