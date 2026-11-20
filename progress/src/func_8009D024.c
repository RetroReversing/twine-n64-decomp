extern s32 D_80100918;
extern s16 D_800EDAA0;
extern s8 D_801032AD;
s32 func_80083C8C(void) { return D_80100918; }
void func_80092780(void) { D_800EDAA0 = 0; }
void func_8009D024(s8 x) { D_801032AD = x; }
s32 func_800986BC(void *a, void *b) { return *(u16 *)((char *)a + 4) - *(u16 *)((char *)b + 4); }
