extern u8 D_800CF540;
extern s16 D_800EDAA0;
extern char *D_800EDAA4[];
void func_8008C0D4(void);
void func_8008C11C(void);
s32 func_8008F520();
s32 func_80092F9C(u16 id, u16 sub, s32 arg2, s32 arg3, u8 flag) {
 s32 i, result;
 char *p, *a, *b, *c;
 u16 n;
 if (D_800CF540) {
  { s32 offset=0; for (i=0; i<D_800EDAA0; i++, offset+=4) {
   p=*(char **)((char *)D_800EDAA4+offset);
   if (*(u16 *)(p+4)==id) {
    if (*(u16 *)(p+6)) return -1;
    c=p+(*(s32 *)(p+0x24)+8);
    n=*(u16 *)c;
    a=p+(*(s32 *)(p+0x1c)+8);
    b=p+(*(s32 *)(p+0x20)+8);
    while(n!=0xffff) {
     if(n==sub) {
      if(flag) result=func_8008F520(a,b,c,arg2,arg3);
      else {
       func_8008C0D4();
       result=func_8008F520(a,b,c,arg2,arg3);
       func_8008C11C();
      }
      return result;
     }
     c+=0x84;
     n=*(u16 *)c;
    }
    return -1;
   }
  } }
 }
 return -1;
}
