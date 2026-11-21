extern s8 D_801002EA; extern char D_80102CE2[]; extern u8 sVoiceOwnerChains[]; extern u16 sVoiceLinkHead; extern s8 D_8010A930; extern s8 D_8010D720; extern s8 D_80110DB0; typedef struct { u8 prev; u8 next; u16 active; } Links;
extern Links D_80117388[]; extern u8 sVoiceCount;
void func_800993A4(void) {
 u8 frame[1]; s32 temp_v1; u32 var_a0_2,var_v1_2,i;
 for (i = 0; i < sVoiceCount; i++) {
   D_80117388[i].prev = i - 1;
   D_80117388[i].active = 1;
   D_80117388[i].next = i + 1;
 }
 {
   u32 last = sVoiceCount;
   D_80117388[0].prev=0xFF;
   last -= 1;
   D_80117388[last].next=0xFF;
 }
 temp_v1=sVoiceCount;
 D_801002EA=0;
 D_80110DB0=temp_v1-1;
 temp_v1 &= 0xFF; var_a0_2=0;
 if(temp_v1!=0){do{*(u16 *)(D_80102CE2+var_a0_2)=0;var_a0_2+=4;}while((s32)var_a0_2<(u32)(temp_v1*4));}
 var_v1_2=0; do {*(sVoiceOwnerChains+var_v1_2)=0xFF;var_v1_2+=1;}while(var_v1_2<0x100U);
 sVoiceLinkHead=0xFFFF;D_8010A930=0;D_8010D720=0;
}
