s32 findEntryIndexById(); s32 getEntryStatus(); extern s32 gEntryTable;
/* Returns a description id for a table entry based on its type; 3 if the entry index is negative. */ s32 getEntryDescriptionId(s16 index, s32 mode) {
 s16 entryIndex; s32 entryType;
 if ((mode & 0xffff)==1) entryIndex=findEntryIndexById(index);
 else entryIndex=index-1;
 if (entryIndex<0) return 3;
 entryType=*(u16 *)((char *)gEntryTable+entryIndex*8+2)&15;
 if (entryType==1) return 0xa0;
 if (entryType==2) return 0x9f;
 if (getEntryStatus()==7) return 0x76;
 return 0x9e;
}
