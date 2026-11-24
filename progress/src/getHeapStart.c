extern s32 gHeapStart;
extern s16 sSceneGroupStackCount;
extern s8 D_801032AD;
/* Returns the start address of the heap. */ s32 getHeapStart(void) { return gHeapStart; }
void resetSceneGroupStack(void) { sSceneGroupStackCount = 0; }
void setAudioFlagByte(s8 x) { D_801032AD = x; }
s32 compareEntryKey(void *a, void *b) { return *(u16 *)((char *)a + 4) - *(u16 *)((char *)b + 4); }
