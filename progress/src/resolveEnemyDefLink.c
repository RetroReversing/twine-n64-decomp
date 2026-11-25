extern u8 sEnemyDefLinkSlot[];
extern s8 D_800C46A0[];
extern u8 D_800C469E[];
/* Returns the linked enemy definition index if this entry has a link and both entries share the same group byte; otherwise returns the input index. */
s32 resolveEnemyDefLink(s16 defIndex, s32 arg1) {
    s32 entry = defIndex;
    s32 offset = (entry * 29) * 8;
    s32 hasLink = D_800C46A0[offset];
    s32 link = *(u16 *)(D_800C469E + offset);
    if (hasLink != 0) {
        s32 linkEntry = (s16)link;
        s32 linkOffset = (linkEntry * 29) * 8;
        if (sEnemyDefLinkSlot[offset] == sEnemyDefLinkSlot[linkOffset]) defIndex = link;
    }
    return (s16)defIndex;
}
