extern s16 D_800C7C16[];
extern s16 D_800C7C14[];
extern s32 func_8005EF30(void *,s32);
extern void showTrackMarker(u32);
s32 func_8005EF84(void *a, void *b) {
 u8 *s=*(u8**)((u8*)b+0x6c);
 u8 *p=*(u8**)((u8*)a+0x6c);
 u16 mode=*(u16*)(s+0x26);
 u16 id=*(u16*)(s+0x28);
 s32 result=0;
 if (mode==2) {
  s16 *field=(s16 *)(p+0x1bc+id*2);
  s32 limit=D_800C7C16[id*2];
  if (*field<limit && func_8005EF30(a,id)) {
   *field += D_800C7C14[id*2];
   if (*field>limit) *field=limit;
   result=1;
  }
 }
 showTrackMarker(*(u16*)(s+0x2a));
 return result || mode!=2;
}
