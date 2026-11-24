extern u16 gSaveSlotValid[], D_800E09A6[], D_800E0996[], gSlotValues[], D_800E098E[], gSlotValues2[];
/* For a valid, unlocked save slot (0-3), stores two parameters and clears its two progress fields. */ void setSaveSlotEntryParams(u16 slot, s16 valueA, s16 valueB) {
 if (slot < 4 && gSaveSlotValid[slot] && !D_800E09A6[slot]) {
  D_800E0996[slot] = valueB;
  gSlotValues[slot] = valueA;
  D_800E098E[slot] = 0;
  gSlotValues2[slot] = 0;
 }
}
