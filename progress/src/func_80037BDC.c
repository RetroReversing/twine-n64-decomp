f32 func_80082908(f32 x) {
    f32 result = 0.0f;
    if (!(x <= 0.0f)) result = sqrtf(x);
    return result;
}

extern u8 sDataBankInitialised, sDataBankFlags;
extern s32 D_800E2CE4;
s32 isSlotActiveById(s32 id) {
    u32 i;
    s32 offset, index;
    if (sDataBankInitialised != 0) {
        i = 0;
        offset = 0;
        do {
            if (*(&sDataBankFlags + offset) && *(s32 *)((s8 *)&D_800E2CE4 + offset) == id) {
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

extern s32 func_80079CB4(void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void *gObjectRecords;
void func_8000CCE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char *obj = *(char **)((u8 *)gObjectRecords + arg0 * 0xD4 + 0x68);
    u8 kind = *(u8 *)(*(char * volatile *)(obj + 0x68) + 0xB1);
    func_80079CB4(obj + 0x24, obj + 0x3C, 0, 0, 0, 0x64, 0x64, 0x64, arg1, 0,
        *(u8 *)(*(char * volatile *)(obj + 0x68) + 0xB1), arg2, -(kind == 0x33) & 3, 0, arg3, 0);
}

extern void emitScissorFromWindow(void *);
extern void emit_projection_viewport_commands(void);
extern s32 D_801032A0, D_8010A920, D_8010A924, gRenderMode;
extern u32 *D_8010A928, *sDisplayListCursor;
extern u8 *sRenderState;
void func_80037BDC(void *window) {
    u32 *head, *list, address;
    u8 *state;
    emitScissorFromWindow(window);
    if (gRenderMode != 0) {
        gRenderMode = 0;
        emit_projection_viewport_commands();
    }
    head = D_8010A928;
    list = sDisplayListCursor;
    state = sRenderState;
    head[0] = 0xDF000000;
    head[1] = 0;
    list[0] = 0xDE000000;
    address = *(u32 *)(state + 0x1658);
    D_801032A0 = -1;
    D_8010A924 = -1;
    gRenderMode = -1;
    D_8010A920 = -1;
    D_8010A928 = head + 2;
    sDisplayListCursor = list + 2;
    list[1] = address;
}
