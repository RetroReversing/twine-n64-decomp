s32 audioVoiceIsActive(u8);
s32 randomU16Next(void);
s32 func_800957A8(u32 *);
s32 func_800957B8(u32 *, void *);

/* Updates a voice's clip selection from its descriptor flags: picks a random or sequential clip index, then advances the voice's clip cursor. Returns 1 while a clip is active. */
s32 audioUpdateClipSelection(void *voice, void *desc) {
    u32 clipIndex;
    u8 useRandom;
    u32 nextPos;

    clipIndex = *(u16 *)((s8 *)desc + 4);
    if (clipIndex != 0) {
        if ((*(u32 *)desc >> 8) & 1) {
            if (*(s32 *)((s8 *)voice + 0x24) & 8) return 0;
            *(s32 *)((s8 *)voice + 0x24) |= 4;
        } else {
            *(s32 *)((s8 *)voice + 0x24) &= ~4;
        }
        if (*(u8 *)desc & 1) {
            if (!(*(s32 *)((s8 *)voice + 0x24) & 0x20) && !(audioVoiceIsActive(*(u8 *)((s8 *)voice + 0x63)) & 0xFF)) return 0;
            *(s32 *)((s8 *)voice + 0x24) |= 0x100000;
        } else {
            *(s32 *)((s8 *)voice + 0x24) &= 0xFFEFFFFF;
        }
        if (*(u16 *)desc & 1) clipIndex = (randomU16Next() & 0xFFFF) % clipIndex;
        if (clipIndex != 0xFFFF) {
            if ((useRandom = (*(volatile u32 *)((s8 *)desc + 4) >> 8) & 1) & 0xFF) func_800957A8(&clipIndex);
            else func_800957B8(&clipIndex, voice);
            if (useRandom & 0xFF) {
                *(u32 *)((s8 *)voice + 0x9C) = *(u32 *)((s8 *)voice + 0xA4) + clipIndex;
            } else {
                nextPos = *(u32 *)((s8 *)voice + 0xA0) + clipIndex;
                *(u32 *)((s8 *)voice + 0x9C) = nextPos;
                if (*(u32 *)((s8 *)voice + 0xA4) >= nextPos) {
                    *(u32 *)((s8 *)voice + 0xA0) = nextPos;
                    *(u32 *)((s8 *)voice + 0x9C) = 0;
                }
            }
        } else {
            *(u32 *)((s8 *)voice + 0x9C) = -1;
        }
        return *(u32 *)((s8 *)voice + 0x9C) != 0;
    }
    return 0;
}
