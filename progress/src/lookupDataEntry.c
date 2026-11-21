/* Resolves a packed data entry id (group in the top nibble, index in the low 12 bits) to its address, or to entry 3 if missing. */
extern s32 sDataEntryBase;
extern s32 *sDataEntryOffsets0;
extern s32 *sDataEntryOffsets1;
extern s32 *sDataEntryOffsets2;
extern s32 *sDataEntryOffsets3;
extern s32 *sDataEntryOffsets6;
extern s32 *sDataEntryOffsets7;
extern s32 *sDataEntryOffsets8;
extern s32 *sDataEntryOffsets9;
extern s32 *sDataEntryOffsetsA;
extern s32 *sDataEntryOffsetsB;
extern s32 *sDataEntryOffsetsC;
extern char sDataEntryFixedBuffer[];

void *lookupDataEntry(s32 entryId) {
    u16 entryIndex = entryId & 0xfff;
    s32 entryGroup = entryId & 0xf000;

    switch (entryGroup) {
    case 0x0000:
        if (entryIndex < 0x2ea && sDataEntryOffsets0) return (void *)(sDataEntryBase + sDataEntryOffsets0[entryIndex]);
        break;
    case 0x1000:
        if (entryIndex < 0x92 && sDataEntryOffsets1) return (void *)(sDataEntryBase + sDataEntryOffsets1[entryIndex]);
        break;
    case 0x2000:
        if (entryIndex < 0x2c && sDataEntryOffsets2) return (void *)(sDataEntryBase + sDataEntryOffsets2[entryIndex]);
        break;
    case 0x3000:
        if (entryIndex < 0x25 && sDataEntryOffsets3) return (void *)(sDataEntryBase + sDataEntryOffsets3[entryIndex]);
        break;
    case 0x4000:
        if (entryIndex < 0x23) return (void *)(entryIndex * 300 + (u32)sDataEntryFixedBuffer);
        break;
    case 0x6000:
        if (entryIndex < 0x38 && sDataEntryOffsets6) return (void *)(sDataEntryBase + sDataEntryOffsets6[entryIndex]);
        break;
    case 0x7000:
        if (entryIndex < 0x1e && sDataEntryOffsets7) return (void *)(sDataEntryBase + sDataEntryOffsets7[entryIndex]);
        break;
    case 0x8000:
        if (entryIndex < 0x17 && sDataEntryOffsets8) return (void *)(sDataEntryBase + sDataEntryOffsets8[entryIndex]);
        break;
    case 0x9000:
        if (entryIndex < 0x21 && sDataEntryOffsets9) return (void *)(sDataEntryBase + sDataEntryOffsets9[entryIndex]);
        break;
    case 0xA000:
        if (entryIndex < 0x38 && sDataEntryOffsetsA) return (void *)(sDataEntryBase + sDataEntryOffsetsA[entryIndex]);
        break;
    case 0xB000:
        if (entryIndex < 0x6d && sDataEntryOffsetsB) return (void *)(sDataEntryBase + sDataEntryOffsetsB[entryIndex]);
        break;
    case 0xC000:
        if (entryIndex < 0x78 && sDataEntryOffsetsC) return (void *)(sDataEntryBase + sDataEntryOffsetsC[entryIndex]);
        break;
    }
    return lookupDataEntry(3);
}
