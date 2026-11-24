extern s32 gMenuItemGrid[], gBonusEndDelayFrames, gMenuItemList[];
void clearMenuItemTables(void) {
 u16 i,j;
 gBonusEndDelayFrames=0;
 for(i=0;i<6;i++) gMenuItemList[i]=0;
 for(i=0;i<9;i++) for(j=0;j<4;j++) gMenuItemGrid[i*4+j]=0;
}
s32 getSaveSlotIndex(); s32 spawnCaptionMessage(); s32 lookupDataEntry(); s32 sprintf();
extern char gPlayerNames[], gNameAndTextFormat[]; extern volatile s32 D_8010969C;
/* Formats "<player name> <text entry 0x28B>" and shows it as a caption message. */ void showPlayerCaptionMessage(s32 playerId) {
 char text[0x20]; void *playerName;
 playerName = ((getSaveSlotIndex(playerId & 0xFFFF) & 0xFFFF) * 0x18) + gPlayerNames;
 sprintf(text, gNameAndTextFormat, playerName, lookupDataEntry(0x28B));
 spawnCaptionMessage(0, *(s32 *)&D_8010969C, &text[0], -1, -1, 1, 0, 0, 6, 0, 0x3C);
}
