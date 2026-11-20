#define F(p,t,o) (*(t *)((char *)(p)+(o)))
s32 strlen(s8 *);
s32 func_80087100(s32);
void func_80074FD4(void *arg0) {
 void *p = F(F(arg0,void *,0x6c),void *,4);
 s32 v = F(p,u8,0x13);
 s32 n = v;
 switch (F(arg0,s16,0x7a)) {
 case 0:
  n = v + 8;
  if (n >= 256) { F(arg0,s16,0x7a)=1; n=255; }
  break;
 case 1:
  n = v - 8;
  if (n < 0) {
   F(arg0,s16,0x7a)=0;
   n=0;
   if (F(p,s32,0x18) == ((s32 (*)(s32))func_80087100)(0xf8))
    F(p,s32,0x18)=((s32 (*)(s32))func_80087100)(0x2ab);
   else F(p,s32,0x18)=((s32 (*)(s32))func_80087100)(0xf8);
   F(p,s16,0x1c)=strlen((s8 *)F(p,s32,0x18));
  }
  break;
 }
 v=(s16)n;
 F(p,s32,0x10)=(v<<16)|(v<<8)|0xff000000|v;
}
