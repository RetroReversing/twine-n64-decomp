extern s32 D_800E06B8;
extern void listUnlinkFree(s32);
void func_8000A7D4(void) {
 u32 i;
 s32 stop;
 char *p;
 i=0;
 stop=-1;
 p=(char *)&D_800E06B8;
 do {
  s32 x=*(s32 *)p;
  if(x!=stop) listUnlinkFree(x);
  p+=4;
  i++;
 } while(i<16);
}
