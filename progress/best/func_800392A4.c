extern s32 D_800E1710;
extern void * volatile D_80115328;
extern s32 D_80117728;
typedef struct { s32 f0,f4,f8,fc,f10,f14,f18,f1c;} Rec;
void func_800392A4(void) {
 unsigned int t; void *p;
 p=D_80115328; t=D_800E1710<<6;
 ((Rec*)p)->f0=0xDA380007;
 ((Rec*)p)->f4=(D_80117728+(t+0x370))-0x80000000;
 ((Rec*)p)->f14=D_80117728+(D_800E1710*0x10+0x4f0);
 ((Rec*)p)->f8=0xDA380005;
 ((Rec*)p)->fc=(D_80117728+(t+0x180))-0x80000000;
 ((Rec*)p)->f10=0xDC080008;
 D_80115328=p+8;
 ((Rec*)p)->f18=0xDB0E0000;
 D_80115328=p+0x10;
 D_80115328=p+0x18;
 D_80115328=p+0x20;
 ((Rec*)p)->f1c=*(u16 *)((char *)(D_800E1710*2+D_80117728)+0x550);
}
