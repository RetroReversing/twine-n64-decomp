f32 sqrtf32(f32 x) {
    f32 result = 0.0f;
    if (!(x <= 0.0f)) result = sqrtf(x);
    return result;
}

extern u8 sDataBankInitialised, sDataBankFlags;
extern s32 sDataBankSlots;
s32 isSlotActiveById(s32 id) {
    u32 i;
    s32 offset, index;
    if (sDataBankInitialised != 0) {
        i = 0;
        offset = 0;
        do {
            if (*(&sDataBankFlags + offset) && *(s32 *)((s8 *)&sDataBankSlots + offset) == id) {
                index = i;
                goto found;
            }
            i++;
            offset += 0x1228;
        } while (i < 2);
        index = -1;
found:
        if (index != -1) return *(&sDataBankFlags + index * 0x1228) != 0;
    }
    return 0;
}

extern s32 spawnKindActor(void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void *gCutscene;
void spawnObjectEffect(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char *obj = *(char **)((u8 *)gCutscene + arg0 * 0xD4 + 0x68);
    u8 kind = *(u8 *)(*(char * volatile *)(obj + 0x68) + 0xB1);
    spawnKindActor(obj + 0x24, obj + 0x3C, 0, 0, 0, 0x64, 0x64, 0x64, arg1, 0,
        *(u8 *)(*(char * volatile *)(obj + 0x68) + 0xB1), arg2, -(kind == 0x33) & 3, 0, arg3, 0);
}

extern void emitScissorFromWindow(void *);
extern void appendProjectionViewportCommands(void);
extern s32 gCurCombineSetup, gCurrentFogColorMode, gCurGeometryModeSetup, gRenderMode;
extern u32 *gDisplayListPtr, *sDisplayListCursor;
extern u8 *sRenderState;
/* Emits the window scissor, resets cached render state, and terminates the main display list while chaining the second list to the address stored in the render state. */ void endWindowDisplayList(void *window) {
    u32 *head, *list, address;
    u8 *renderState;
    emitScissorFromWindow(window);
    if (gRenderMode != 0) {
        gRenderMode = 0;
        appendProjectionViewportCommands();
    }
    head = gDisplayListPtr;
    list = sDisplayListCursor;
    renderState = sRenderState;
    head[0] = 0xDF000000;
    head[1] = 0;
    list[0] = 0xDE000000;
    address = *(u32 *)(renderState + 0x1658);
    gCurCombineSetup = -1;
    gCurGeometryModeSetup = -1;
    gRenderMode = -1;
    gCurrentFogColorMode = -1;
    gDisplayListPtr = head + 2;
    sDisplayListCursor = list + 2;
    list[1] = address;
}
