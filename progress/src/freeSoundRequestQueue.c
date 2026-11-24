extern s32 gSoundRequestQueue;
extern void listUnlinkFree(s32);
/* Frees every non-empty entry (-1 means empty) in the 16-slot sound request queue. */ void freeSoundRequestQueue(void) {
 u32 index;
 s32 emptySlot;
 char *slot;
 index=0;
 emptySlot=-1;
 slot=(char *)&gSoundRequestQueue;
 do {
  s32 entry=*(s32 *)slot;
  if(entry!=emptySlot) listUnlinkFree(entry);
  slot+=4;
  index++;
 } while(index<16);
}
