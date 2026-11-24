typedef struct N9 { struct N9 *next; struct N9 *prev; s32 pad[4]; } N9;
typedef struct S9 { u8 a; u8 b; u8 pad[0xFF6]; } S9;
extern N9 gSndNodePool[];
extern N9 *gFreeSndNodeList;
extern S9 gSndChannelStates[];
extern s32 gSoundEntityIdCounter;

/* Resets the 8 sound channel states and links the 256 sound nodes into a doubly linked free list. */ void initSoundNodePool(void) {
    u32 i;
    s32 j;
    N9 *prev;
    N9 *cur;

    for (i = 0; i < 8; i++) {
        gSndChannelStates[i].a = 0;
        gSndChannelStates[i].b = 1;
    }
    prev = NULL;
    gFreeSndNodeList = gSndNodePool;
    j = 0;
    cur = gSndNodePool;
    for (; j < 0x100; j++) {
        gSndNodePool[j].prev = prev;
        if (prev != NULL) {
            prev->next = cur;
        }
        prev = cur;
        cur++;
    }
    prev->next = NULL;
    gSoundEntityIdCounter = 0;
}
