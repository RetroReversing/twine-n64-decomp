extern u8 sEnemyDefLinkSlot[];
extern s16 getLinkedEnemyDefFlag(s32, s16);

/* Returns 1 if the enemy def is available: its link slot is occupied, its linked def has a flag set, or its link slot is 0. */ s32 isEnemyDefAvailable(s32 owner, s16 defIndex) {
    s32 entryOffset = defIndex * 0xE8;
    s32 linkSlot = sEnemyDefLinkSlot[entryOffset];
    s32 available;

    if (*(s16 *)(owner + (linkSlot << 1) + 0x1BC) != 0
        || getLinkedEnemyDefFlag(owner, defIndex) != 0) {
        available = 1;
    } else {
        available = sEnemyDefLinkSlot[entryOffset] == 0;
    }
    return available;
}
