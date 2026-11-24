extern s8 D_801002EA; extern char D_80102CE2[]; extern u8 D_8010957D[]; extern u16 D_80109B1C; extern s8 D_8010A930; extern s8 D_8010D720; extern s8 D_80110DB0; typedef struct { u8 prev; u8 next; u16 active; } Links;
extern Links sVoiceFreeList[]; extern u8 sVoiceCount;
/* Resets the voice allocator: links all voices into a doubly linked list and clears the owner/lookup tables. */
void initVoiceAllocator(void) {
 u8 frame[1]; s32 temp_v1; u32 offset,idx,count,voice;
 for (voice = 0; voice < sVoiceCount; voice++) {
   sVoiceFreeList[voice].prev = voice - 1;
   sVoiceFreeList[voice].active = 1;
   sVoiceFreeList[voice].next = voice + 1;
 }
 {
   u32 last = sVoiceCount;
   sVoiceFreeList[0].prev=0xFF;
   last -= 1;
   sVoiceFreeList[last].next=0xFF;
 }
 do{do{ count=sVoiceCount;
 D_801002EA=0;
 D_80110DB0=count-1;
 count &= 0xFF;}while(0);}while(0); if(count!=0){
      offset=0;do{*(u16 *)(D_80102CE2+offset)=0;offset+=4;}while((s32)offset<(u32)(count*4));}
 idx=0; do {*(D_8010957D+idx)=0xFF;idx+=1;}while(idx<0x100U);
 D_80109B1C=0xFFFF;D_8010A930=0;D_8010D720=0;
}
