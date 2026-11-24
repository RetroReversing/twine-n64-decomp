extern s32 gHeapStart;
extern s16 sSceneGroupStackCount;
extern s8 D_801032AD;
s32 getHeapStart(void) { return gHeapStart; }
void resetSceneGroupStack(void) { sSceneGroupStackCount = 0; }
/* Stores a flag byte used by the audio system. */ void setAudioFlagByte(s8 value) { D_801032AD = value; }
s32 compareEntryKey(void *a, void *b) { return *(u16 *)((char *)a + 4) - *(u16 *)((char *)b + 4); }
