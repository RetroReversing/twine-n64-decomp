extern s32 D_800C4428;
extern char D_800C4434[];
extern u8 D_80102F28;
extern void *D_80108788;
extern void *gTrackMarkers;
extern u8 gAnnounceCount;
s32 func_80073AF8();
s32 lookupDataEntry();
s32 sprintf();

/* Checks the player's current track marker against a table of three and, on a match, shows an announcement message. */ void checkTrackMarkerAnnounce(void) {
    char message[0x100];
    u32 markerWord;
    s32 rankName;
    s32 markerName;
    s32 i;
    char *cursor;
    extern char D_800D4110[];

    *(volatile s32 *)((s8 *)gTrackMarkers + 0x100) |= 0x40;
    *(s8 *)((s8 *)*(s8 **)&gTrackMarkers + 0x142) = 2;
    if (D_80108788 != NULL) {
        i = 0;
        if (*(s32 *)((s8 *)D_80108788 + 0x78) == 0x5A0000) {
            cursor = (char *)&D_800C4428;
            do {
                markerWord = *(u32 *)(*(s8 **)((s8 *)D_80108788 + 0x70) + 0x30);
                if ((((markerWord >> 4) & 0xFFFF) == *(s32 *)(&D_800C4428 + i)) && ((markerWord >> 0x14) == *(s32 *)(D_800C4434 + i * 4))) {
                    gAnnounceCount += 1;
                    markerName = lookupDataEntry(0xFA, markerWord);
                    rankName = lookupDataEntry(0xFF);
                    sprintf(message, D_800D4110, markerName, gAnnounceCount, rankName, (s32)D_80102F28, lookupDataEntry(0xFE));
                    *(s16 *)((s8 *)D_80108788 + 0x7A) = 1;
                    func_80073AF8(0, gTrackMarkers, message, -1, -1, 1, 0, 0, 3, 0, 0);
                }
                i += 1;
                cursor += 4;
            } while (i < 3U);
        }
    }
}
