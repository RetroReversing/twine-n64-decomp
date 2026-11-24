extern s32 gHeapStart;
extern s16 sSceneGroupStackCount;
extern s8 D_801032AD;
s32 getHeapStart(void) { return gHeapStart; }
void resetSceneGroupStack(void) { sSceneGroupStackCount = 0; }
void setAudioFlagByte(s8 x) { D_801032AD = x; }
/* Comparator for sorted entries: returns the difference of the u16 keys at offset 4. */ s32 compareEntryKey(void *entryA, void *entryB) { return *(u16 *)((char *)entryA + 4) - *(u16 *)((char *)entryB + 4); }
