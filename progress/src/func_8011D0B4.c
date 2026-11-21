extern s32 D_8011F2E8[], D_8011F3A8, D_8011F3B8[];
void func_8011E800(void) {
 u16 i,j;
 D_8011F3A8=0;
 for(i=0;i<6;i++) D_8011F3B8[i]=0;
 for(i=0;i<9;i++) for(j=0;j<4;j++) D_8011F2E8[i*4+j]=0;
}
s32 getSaveSlotIndex(); s32 func_80073AF8(); s32 lookupDataEntry(); s32 sprintf();
extern char D_801001A4[], D_8011F010[]; extern volatile s32 D_8010969C;
void func_8011D0B4(s32 arg0) {
 char sp30[0x20]; void *temp_s0;
 temp_s0 = ((getSaveSlotIndex(arg0 & 0xFFFF) & 0xFFFF) * 0x18) + D_801001A4;
 sprintf(sp30, D_8011F010, temp_s0, lookupDataEntry(0x28B));
 func_80073AF8(0, *(s32 *)&D_8010969C, &sp30[0], -1, -1, 1, 0, 0, 6, 0, 0x3C);
}
