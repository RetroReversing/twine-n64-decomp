typedef struct { u8 pad[0x58]; s32 flags; } S64318;
/* Clears the 4-bit flag group 0xF0 on the object and sets the one bit selected by layer (0-3); layers above 3 leave it cleared. */ void setObjectLayerFlag(S64318 *obj, u32 layer) {
    s32 newFlags;
    s32 clearedFlags = obj->flags & ~0xF0;
    obj->flags = clearedFlags;
    switch (layer) {
    case 0: newFlags = clearedFlags | 0x10; break;
    case 1: newFlags = clearedFlags | 0x20; break;
    case 2: newFlags = clearedFlags | 0x40; break;
    case 3: newFlags = clearedFlags | 0x80; break;
    default: return;
    }
    obj->flags = newFlags;
}
