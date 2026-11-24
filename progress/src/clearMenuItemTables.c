extern s32 gMenuItemGrid[9][4], gBonusEndDelayFrames, gMenuItemList[];
/* Resets the bonus end delay and zeroes the menu item list and menu item grid. */ void clearMenuItemTables(void) {
 u16 i,j;
 gBonusEndDelayFrames=0;
 for(i=0;i<6;i++) gMenuItemList[i]=0;
 for(i=0;i<9;i++) for(j=0;j<4;j++) gMenuItemGrid[i][j]=0;
}
s32 getSaveSlotIndex(); s32 spawnCaptionMessage(); s32 lookupDataEntry(); s32 sprintf();
extern char gPlayerNames[], gNameAndTextFormat[]; extern s32 D_8010969C;
void showPlayerCaptionMessage(s32 arg0) {
 char sp30[0x20]; void *temp_s0;
 temp_s0 = ((getSaveSlotIndex(arg0 & 0xFFFF) & 0xFFFF) * 0x18) + gPlayerNames;
 sprintf(sp30, gNameAndTextFormat, temp_s0, lookupDataEntry(0x28B));
 spawnCaptionMessage(0, D_8010969C, sp30, -1, -1, 1, 0, 0, 6, 0, 0x3C);
}
