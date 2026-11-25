extern s16 sCacheNextSlot, sCacheLastSlot, sCacheBlockIds[6];
extern s16 D_800D94F8, D_800D94FA, sStreamSlotIds[8];
extern s16 sLargeCacheNextSlot, sLargeCacheLastSlot;
extern s32 sLargeCacheBlockIds[6];

static __inline__ void fill_s16(s16 value, u32 i, s16 *out, u32 count, s16 *read, s16 *write) {
    *read = 0;
    *write = 0;
    do { *out++ = value; ++i; } while (i < count);
}
static __inline__ void fill_s32(s32 value, u32 i, s32 *out, u32 count, s16 *read, s16 *write) {
    *read = 0;
    *write = 0;
    do { *out++ = value; ++i; } while (i < count);
}
void initResourceCaches(void) {
    fill_s16(0x7fff, 0, sCacheBlockIds, 6, &sCacheLastSlot, &sCacheNextSlot);
    fill_s16(0x7fff, 0, sStreamSlotIds, 8, &D_800D94FA, &D_800D94F8);
    fill_s32(0x7fffffff, 0, sLargeCacheBlockIds, 6, &sLargeCacheLastSlot, &sLargeCacheNextSlot);
}
typedef struct { u8 pad[0x2D]; u8 flag2D; u8 pad2E; u8 flag2F; } MenuState;
extern MenuState *gSaveMenuState;
extern u8 gMenuAnyController, sOptionCursorIndex, sOptionEntryTable[];
extern char D_800D2864[];
void updateHelpPageText(void);
void formatTextEntry(void *, s32, ...);
s32 findEntryPayload(s32, s32);
char *lookupDataEntry(s32);
void refreshOptionEntryLabels(void) {
    char *entry = (char *)findEntryPayload((s32)sOptionEntryTable, 0x92);
    gMenuAnyController = 1;
    if (!entry) return;
    {
        u8 *index;
        char *text;
        char *format;
        gSaveMenuState->flag2F = 1;
        gSaveMenuState->flag2D = 1;
        updateHelpPageText();
        gSaveMenuState->flag2F = 0;
        index = &sOptionCursorIndex;
        text = lookupDataEntry(*index + 0x16D);
        format = D_800D2864;
        formatTextEntry(entry, (s32)format, text);
        text = lookupDataEntry(*index + 0x177);
        formatTextEntry(entry + 0x28, (s32)format, text);
    }
}
extern u8 gDemoRecordingActive;
void setSaveSlotEntryParams(u8, u16, u8);
/* Unless a demo is recording, converts percent (0-100) to 0-255 (percent*255/100 via multiply-high) and forwards it to setSaveSlotEntryParams. */ void setSaveSlotEntryPercent(char slot, s32 param, s32 percent) {
    if (!gDemoRecordingActive) {
        s32 reciprocal100 = 0x51EB851F;
        s32 scaled = percent * 255;
        union { long long value; struct { s32 high; u32 low; } words; } product;
        product.value = (long long)scaled * reciprocal100;
        setSaveSlotEntryParams(slot, param, (product.words.high >> 5) - (scaled >> 31));
    }
}
