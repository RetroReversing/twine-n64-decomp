extern u8 D_801096E8; extern u32 D_801096EC,D_801096F0,D_801096F4,D_801096F8,D_801096FC; extern u8 D_801176E8;
s32 func_8008C6CC(s32); void func_8008C6F4(s32,s32);
#define AT(T,s,o) (*(volatile T *)((u8 *)&(s)+(o)))
void func_80093268(void) {
 s32 i=0, off=0; u32 *entry=&D_801096F8, now, old, base;
 if ((s32)D_801176E8 <= 0) return;
 do {
  if (*(u8 *)((u8 *)&D_801096E8+off)==1) {
   now=func_8008C6CC(i); old=*entry;
   if(old<now) {
    if(((s32(*)(s32,s32,s32,s32,s32))AT(u32,D_801096EC,off))(AT(u32,D_801096F0,off)+old*2,now-old,0,0,AT(u32,D_801096FC,off))&255)
      func_8008C6F4(AT(u32,D_801096F0,off)+(*entry)*2,now-*entry);
   } else if(old>now) {
    base=AT(u32,D_801096F0,off);
    if(((s32(*)(s32,s32,s32,s32,s32))AT(u32,D_801096EC,off))(base+old*2,AT(u32,D_801096F4,off)-old,base,now,AT(u32,D_801096FC,off))&255) {
      func_8008C6F4(AT(u32,D_801096F0,off)+(*entry)*2,AT(u32,D_801096F4,off)-*entry);
      func_8008C6F4(AT(u32,D_801096F0,off),now);
    }
   }
   *entry=now;
  }
  entry+=6; i++; off+=24;
 } while(i<(s32)D_801176E8);
}
