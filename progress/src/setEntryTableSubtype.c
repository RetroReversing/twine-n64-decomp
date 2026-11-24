s32 findEntryIndexById(s16,s32); s32 getEntryStatus(u16,void *);
extern s32 gEntryTable; extern u16 gEntryLevelLimit;
/* Finds an entry table record (by search or id-1), sets its low subtype nibble if its level is allowed, and applies it; returns 3 on failure. */ s32 setEntryTableSubtype(s32 entryId,s32 subtype,s32 lookupMode) {
 s32 index; u16 *entry; u16 flags;
 if ((lookupMode & 0xffff)==1) index = (s16)findEntryIndexById(entryId,subtype);
 else index=(s16)(entryId-1);
 if (index >= 0) {
  entry=(u16 *)(index*8+gEntryTable);
  flags=entry[1];
  if (gEntryLevelLimit >= (flags & 0xf000)) {
   entry[1]=(flags & 0xfff0)|subtype;
   return getEntryStatus(flags,entry);
  }
 }
 return 3;
}
