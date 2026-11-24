typedef struct { u8 type; u8 rest[23]; } SlotEnt;
extern SlotEnt sSaveSlotInfo[];
extern s32 sSaveMenuColorActive, gVisibleSaveSlotCount;
extern u8 sMarkerTextArgs[];
extern void *sSaveSlotMarkerTable[3][4];
extern s32 sBonusMarkerNodes,sMarkerTextNode2,sMarkerTextNode3;
s32 spawnTextNode(void *); void *spawnTrackMarker(s32); void initObjectFromBankEntry(void *, s32, s32);
/* Creates the text nodes and, for each visible save slot of a markable type, three marker objects. */
void setupSaveSlotMarkers(void) {
 u16 slot,row; u8 slotType; s32 *marker;
 sBonusMarkerNodes=spawnTextNode(sMarkerTextArgs);
 sMarkerTextNode2=spawnTextNode(sMarkerTextArgs+0x24);
 sMarkerTextNode3=spawnTextNode(sMarkerTextArgs+0x48);
 for(slot=0;slot<gVisibleSaveSlotCount;slot++) {
 slotType=sSaveSlotInfo[slot].type;
 switch(slotType) {
 case 1: case 2: case 3: case 5:
 for(row=0;row<3;row++) {
 marker=spawnTrackMarker(slot);
 if(marker!=0) {initObjectFromBankEntry(marker,0x13,0xF4); marker[4]=sSaveMenuColorActive; sSaveSlotMarkerTable[row][slot]=marker;}
 }
 break;
 default: for(row=0;row<3;row++) sSaveSlotMarkerTable[row][slot]=0; break;
 }
 }
}
