extern s16 D_800C7C16[];
extern s16 D_800C7C14[];
extern s32 func_8005EF30(void *,u16);
extern s32 showTrackMarker(u16);
s32 func_8005EF84(void *a, void *b) {
 u8 *s=*(u8**)((u8*)b+0x6c); u8 *p=*(u8**)((u8*)a+0x6c);
 u16 mode=*(u16*)(s+0x26), id=*(u16*)(s+0x28);
 if (mode==2) {
  if (*(s16*)(p+0x1bc+id*2)<D_800C7C16[id*2] && func_8005EF30(a,id)) {
    *(s16*)(p+0x1bc+id*2)+=D_800C7C14[id*2];
    if (D_800C7C16[id*2]<*(s16*)(p+0x1bc+id*2)) *(s16*)(p+0x1bc+id*2)=D_800C7C16[id*2];
    showTrackMarker(*(u16*)(s+0x2a)); return 1;
  } return 0;
 }
 showTrackMarker(*(u16*)(s+0x2a)); return 1;
}
