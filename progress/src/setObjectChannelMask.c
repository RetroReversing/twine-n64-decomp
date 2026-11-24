typedef struct { u8 pad[0x58]; s32 flags; } S64318;
/* Sets flag bits 4-7 so that only the selected channel (0-3) is cleared; other values leave them all cleared. */ void setObjectChannelMask(S64318 *object, u32 channel) {
    s32 newFlags;
    s32 clearedFlags = object->flags & ~0xF0;
    object->flags = clearedFlags;
    switch (channel) {
    case 0: newFlags = clearedFlags | 0xE0; break;
    case 1: newFlags = clearedFlags | 0xD0; break;
    case 2: newFlags = clearedFlags | 0xB0; break;
    case 3: newFlags = clearedFlags | 0x70; break;
    default: return;
    }
    object->flags = newFlags;
}
