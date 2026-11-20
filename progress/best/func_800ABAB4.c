typedef struct { u8 active; u8 pad[7]; f64 time; u32 now; u32 prev; u8 rest[0x50]; } E8B1C0;
extern E8B1C0 *D_800E41DC;
extern u16 D_800E41E4;
void func_8008B1C0(void) { s32 i; E8B1C0 *e,*p; i=0; e=D_800E41DC; if(i<D_800E41E4) do { p=e; if(p->active) { p->prev=p->now; p->now=p->time; } i++; e++; } while(i<D_800E41E4); }
extern s32 D_800E06B0; extern void func_8000A5F4(void);
void func_8000A5D0(void) { D_800E06B0=-1; func_8000A5F4(); }
extern s8 D_800CA310,D_80102EDF; extern s32 D_80102EEC,D_8010A4E4; extern void hiscore_refresh_all(void);
void func_80045130(s8 x) { hiscore_refresh_all(); D_80102EDF=x; D_80102EEC=1; D_8010A4E4=0; D_800CA310=0; }
u64 func_800ABAB4(u64 a,u64 b) { return a*b; }
