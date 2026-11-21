typedef struct { u8 type; u8 rest[23]; } SlotEnt;
extern SlotEnt sSaveSlotInfo[];
extern s32 sSaveMenuColorActive, gVisibleSaveSlotCount;
extern u8 sMarkerTextArgs[];
extern void *sSaveSlotMarkerTable[3][4];
extern s32 sBonusMarkerNodes,sMarkerTextNode2,sMarkerTextNode3;
s32 func_80015F74(void *); void *func_800162BC(s32); void func_800448A4(void *, s32, s32);
void setupSaveSlotMarkers(void) {
 u16 i,j; u8 t; s32 *o;
 sBonusMarkerNodes=func_80015F74(sMarkerTextArgs);
 sMarkerTextNode2=func_80015F74(sMarkerTextArgs+0x24);
 sMarkerTextNode3=func_80015F74(sMarkerTextArgs+0x48);
 for(i=0;i<gVisibleSaveSlotCount;i++) {
 t=sSaveSlotInfo[i].type;
 switch(t) {
 case 1: case 2: case 3: case 5:
 for(j=0;j<3;j++) {
 o=func_800162BC(i);
 if(o!=0) {func_800448A4(o,0x13,0xF4); o[4]=sSaveMenuColorActive; sSaveSlotMarkerTable[j][i]=o;}
 }
 break;
 default: for(j=0;j<3;j++) sSaveSlotMarkerTable[j][i]=0; break;
 }
 }
}
