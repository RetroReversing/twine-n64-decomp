extern u16 gKeyEntryFlagsTable;
/* Returns bit 7 of the halfword in key entry `index` (entries are 12 bytes apart). */
s32 getKeyEntryFlag(s32 index) {
    return (*(u16 *)((char *)&gKeyEntryFlagsTable + index * 12) >> 7) & 1;
}
