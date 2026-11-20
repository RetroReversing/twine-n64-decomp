typedef struct { u8 active; u8 pad[7]; f64 time; u32 now; u32 prev; u8 rest[0x50]; } E8B1C0;
extern E8B1C0 *D_800E41DC; extern u16 D_800E41E4;
void func_8008B1C0(void) { s32 i; E8B1C0 *e,*p; i=0; e=D_800E41DC; if(i<D_800E41E4) do { p=e; if(p->active) {p->prev=p->now;p->now=p->time;} i++;e++; } while(i<D_800E41E4); }
extern f32 sqrtf(f32);
void func_8009532C(f32 *a){ f32 x=a[0],y=a[1],z=a[2]; f32 v=__builtin_sqrt(x*x+y*y+z*z); a[0]=x/v;a[1]=a[1]/v;a[2]=a[2]/v; }
extern s32 D_800E4290;
void func_8008CDC0(s32 a,s32 b){unsigned int n=b;if((n&255)==255)n=8; *((s32 *)((s8 *)&D_800E4290+((n&255)*4)))=(((unsigned)a*0x18)<<9)/240;}
s32 func_8000A8B4(u16,f32,s32); s32 func_80045CF8(s32); f32 func_80084270(s32 *); extern s32 D_800CE700;
void func_80084E10(void){s32 sp10; f32 f=func_80084270(&sp10);func_8000A8B4(*((u16 *)((s8 *)&D_800CE700+func_80045CF8(2)*2)),f,255);}
