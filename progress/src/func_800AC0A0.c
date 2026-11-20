typedef struct { u8 active; u8 pad[7]; f64 time; u32 now; u32 prev; u8 rest[0x50]; } E8B1C0;
extern E8B1C0 *D_800E41DC; extern u16 D_800E41E4;
void func_8008B1C0(void) { s32 i=0; E8B1C0 *e; if(i<D_800E41E4) { e=D_800E41DC; do {if(e->active){e->prev=e->now;e->now=e->time;} i++;e++;}while(i<D_800E41E4);}}
s32 ctype_toupper(s32);
u8 *func_800AB9B0(u8 *arg0) { u8 *p=arg0; while (*p) { *p=ctype_toupper((s8)*p); p++; } return arg0; }
typedef union { f64 d; u32 w[2]; } Bits;
f64 func_800AC0A0(f64 x, s32 *e) { u32 *p = (u32 *)&x; if (x==0.0) {*e=0; return 0.0;} *e=((*p>>20)&0x7ff)-0x3fe; *p=(*p&0x800fffff)|0x3fe00000; return x; }
extern u8 D_800CEEB0;
void func_8001074C(s32,s32,s32);
void func_80082834(s32 a,s32 b,s32 c) { if(!D_800CEEB0) func_8001074C(a&255,b&65535,((c*255)/100)&255); }
