extern s32 gSoundRequestQueue[];
extern s32 gSoundRequestWriteIndex;
/* Empties the sound request queue (-1 = no request) and resets the write index. */ void clearSoundRequestQueue(void) {
    unsigned int slot;
    for (slot = 0; slot < 16; slot++) gSoundRequestQueue[slot] = -1;
    gSoundRequestWriteIndex = 0;
}
