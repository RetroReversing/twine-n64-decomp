typedef struct { u8 active; u8 pad[3]; u8 (*fn)(u32,u32,u32,u32,u32); u32 buf; u32 size; u32 pos; u32 arg; } Voice;
extern Voice gVoiceTable[]; extern u8 sVoiceCount;
s32 func_8008C6CC(s32); void func_8008C6F4(s32,s32);
void func_80093268(void) {
 s32 i; u32 now, old, base;
 for (i=0; i<sVoiceCount; i++) {
  if (gVoiceTable[i].active==1) {
   now=func_8008C6CC(i); old=gVoiceTable[i].pos;
   if(old!=now) {
    if(old<now) {
     if(gVoiceTable[i].fn(gVoiceTable[i].buf+old*2,now-old,0,0,gVoiceTable[i].arg))
      func_8008C6F4(gVoiceTable[i].buf+gVoiceTable[i].pos*2,now-gVoiceTable[i].pos);
    } else {
     base=gVoiceTable[i].buf;
     if(gVoiceTable[i].fn(base+old*2,gVoiceTable[i].size-old,base,now,gVoiceTable[i].arg)) {
      func_8008C6F4(gVoiceTable[i].buf+gVoiceTable[i].pos*2,gVoiceTable[i].size-gVoiceTable[i].pos);
      func_8008C6F4(gVoiceTable[i].buf,now);
     }
    }
   }
   gVoiceTable[i].pos=now;
  }
 }
}
