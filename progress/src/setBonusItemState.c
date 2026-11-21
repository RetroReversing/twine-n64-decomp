extern void *sBonusMarkerNodes[];

s32 requestSound(s32 soundId);

/* Switches a bonus item to a new state (0 = red, 1 = blue, other = white), updating its tint, linked parent and marker node colour. */
void setBonusItemState(s32 markerIndex, s32 newState, void *item) {
    s32 state;
    short tintR;
    short tintG;
    short tintB;
    void *linkedItem;
    void *markerNode;

    state = newState & 0xFF;
    if (state != *(s16 *)((char *)item + 0x7C)) {
        switch (state) {
        case 0:
            tintR = 0xFF;
            tintG = 0x40;
            tintB = 0x40;
            break;
        case 1:
            tintR = 0x40;
            tintG = 0x40;
            tintB = 0xFF;
            break;
        default:
            tintR = 0xFF;
            tintG = 0xFF;
            tintB = 0xFF;
            break;
        }
        linkedItem = *(void **)((char *)item + 0x6C);
        *(s16 *)((char *)item + 0x7C) = (s16)(newState & 0xFF);
        *(s8 *)((char *)item + 0x7F) = tintR;
        *(s8 *)((char *)item + 0x80) = tintG;
        *(s8 *)((char *)item + 0x81) = tintB;
        if (linkedItem != NULL) {
            *(s16 *)((char *)linkedItem + 0x7A) = 0x400;
            *(s8 *)((char *)linkedItem + 0x7F) = tintR;
            *(s8 *)((char *)linkedItem + 0x80) = tintG;
            *(s8 *)((char *)linkedItem + 0x81) = tintB;
        }
        requestSound(0x226);
        requestSound(0x21A);
        markerNode = *(void **)((s8 *)sBonusMarkerNodes + ((markerIndex & 0xFFFF) * 4));
        if (markerNode != NULL) {
            *(s32 *)((char *)markerNode + 0x10) = (tintR << 0x18) | (tintG << 0x10) | (tintB << 8) | 0xFF;
        }
    }
}
