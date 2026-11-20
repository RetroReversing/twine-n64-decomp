s32 func_8003090C(); s32 func_80030D40(); extern s32 D_800BFF04;
s32 func_80031250(s16 arg0, s32 arg1) {
 s16 v; s32 t;
 if ((arg1 & 0xffff)==1) v=func_8003090C(arg0);
 else v=arg0-1;
 if (v<0) return 3;
 t=*(u16 *)((char *)D_800BFF04+v*8+2)&15;
 if (t==1) return 0xa0;
 if (t==2) return 0x9f;
 if (func_80030D40()==7) return 0x76;
 return 0x9e;
}
