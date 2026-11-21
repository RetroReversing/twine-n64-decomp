#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 func_800422F4(); s32 func_800426B8(); s32 activateIdList();
extern u16 gSharedItemId,D_800C2B50,D_800C2B54,D_800C2B5C,D_800C2B64,D_800C2B68,D_800C2B70,D_800C2B80,D_800C2B88,D_800C2B94,D_800C2BA0,D_800C2BA4,D_800C2BB0,D_800C2BB8,D_800C2BC0,D_800C2BCC,D_800C2BF4;
extern char D_800C447A[]; extern s32 gBorderSkipActive; extern void *gTrackMarkers; extern u8 D_80112F6C,D_80112F6D;

/* Resets the marker id list for trackId, then activates the marker and HUD id lists for it. */
void setupTrackMarkers(u32 trackId) {
    s16 idList[0x100];
    s16 fillValue, fillValue2;
    s32 fillIndex, fillIndex2, copyIndex;
    char *bufCursor;
    u16 *listSrc;
    u16 copyWord;

    idList[0] = -1;
    func_800422F4();
    func_800426B8(M2C_FIELD(gTrackMarkers, s32*, 8), trackId, 1);
    switch (trackId) {
    case 2: listSrc = &D_800C2B54; break;
    case 20: listSrc = &D_800C2B5C; break;
    case 16: listSrc = &D_800C2B64; break;
    case 34: listSrc = &D_800C2B68; break;
    case 25: listSrc = &D_800C2B70; break;
    case 38: listSrc = &D_800C2B80; break;
    case 1: listSrc = &D_800C2B88; break;
    case 11: listSrc = &D_800C2B94; break;
    case 41: listSrc = &D_800C2BA0; break;
    case 40: listSrc = &D_800C2BA4; break;
    case 28: listSrc = &D_800C2BB0; break;
    case 18: listSrc = &D_800C2BB8; break;
    case 29: listSrc = &D_800C2BC0; break;
    case 33: listSrc = &D_800C2BCC; break;
    case 36: listSrc = &D_800C2B50; break;
    case 0: case 4: case 7: case 9: case 12: case 19: case 21: case 22: case 23: case 24: case 26: case 31: case 32: case 39:
        fillIndex = 0x1B; listSrc = (u16 *)&idList[0x1B]; fillValue = 0x1FA;
        do { *listSrc = fillValue; listSrc--; fillIndex--; fillValue--; } while (fillIndex >= 0);
        idList[0x1C] = -1; activateIdList(&idList[0]); listSrc = &D_800C2BF4; break;
    default: listSrc = NULL; break;
    }
    if (listSrc != NULL) activateIdList(listSrc);
    fillIndex2 = 0x1B;
    if (D_80112F6C != 0) {
        listSrc = (u16 *)&idList[0x1B]; fillValue2 = 0x1FA;
        do { *listSrc = fillValue2; listSrc--; fillIndex2--; fillValue2--; } while (fillIndex2 >= 0);
        idList[0x1C] = -1; activateIdList(&idList[0]);
    }
    copyIndex = 0;
    if (D_80112F6D != 0) {
        bufCursor = (char *)&idList[0]; listSrc = (u16 *)0;
        do { copyWord = *(u16*)(D_800C447A + (s32)listSrc); listSrc += 8; copyIndex++; *(u16*)bufCursor = copyWord; bufCursor += 2; } while (copyIndex < 0x1E);
        idList[0x1E] = -1; activateIdList(&idList[1], bufCursor);
    }
    if (gBorderSkipActive != 0) activateIdList(&gSharedItemId);
}
