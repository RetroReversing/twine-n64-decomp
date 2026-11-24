extern int findEntryIndexById(short);
extern char *gEntryTable;
/* Returns 0, 1 or 2 for the entry's type (low 4 bits of its flags), or 3 if the entry is missing or has flag 0x200 set. The entry is found by id if lookupById == 1, otherwise by 1-based number. */ int getEntryKind(short idOrNumber, unsigned short lookupById) {
    short entryIndex;
    unsigned short flags;
    int entryType;
    if (lookupById == 1) entryIndex = findEntryIndexById(idOrNumber);
    else entryIndex = idOrNumber - 1;
    if (entryIndex < 0) return 3;
    flags = *(unsigned short *)(gEntryTable + entryIndex * 8 + 2);
    if (flags & 0x200) return 3;
    entryType = flags & 15;
    if (entryType == 0) return 0;
    if (entryType == 2) return 2;
    return 1;
}
