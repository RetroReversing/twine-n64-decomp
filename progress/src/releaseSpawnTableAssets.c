typedef struct { s16 *f0; u8 pad[8]; } Slot_800C3CF8;
s32 releaseAssetSlotIfUnused(s32);
extern u16 D_800BF680;
extern Slot_800C3CF8 D_800C3CF8[];
extern u8 *D_80102F40;
void releaseSpawnTableAssets(void) {
 u16 end;
 D_80102F40=(u8*)&D_800BF680;
 if(*(u16*)D_80102F40 !=0) {
  do {
   if((*(u16*)(D_80102F40+6))&1) releaseAssetSlotIfUnused(*D_800C3CF8[D_80102F40[5]].f0);
   end=*(u16*)(D_80102F40+0xC);
   D_80102F40+=0xC;
  } while(end!=0);
 }
}
