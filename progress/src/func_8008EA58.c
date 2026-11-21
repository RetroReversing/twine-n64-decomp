extern s32 func_800989B8(void);
extern u8 gWorkerThreadActive;
extern s32 gVoiceChannelTable;
extern s32 D_8010D748;
extern s32 D_8010D784;
s32 func_8008EA58(void) {
    s32 key, found;
    u32 offset;
    found = -1;
    if (gWorkerThreadActive != 0) {
        key = func_800989B8();
        if (key != -1) {
            do {
                { u32 index = (u8)key; offset = (index * 13) << 5; }
                if (*(s32 *)((u8 *)&D_8010D784 + offset) == key) {
                    found = 0;
                    *(s32 *)((u8 *)&D_8010D748 + offset) |= 8;
                }
                key = *(s32 *)((u8 *)&gVoiceChannelTable + offset);
            } while (key != -1);
        }
    }
    return found;
}
