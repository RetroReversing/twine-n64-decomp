extern void func_8001E5BC(void);
extern s32 func_800260A0(s32);
extern u32 randomU32Next(void);
extern u8 gMenuFlagItem20, gMenuFlagItem22, gMenuFlagItem27, gMenuRowEnabled;
extern void *gSaveMenuState;
void updateRandomMenuItem(void) {
 u32 r; s32 idx, a; u8 flag;
 if (*(u8 *)((u8 *)gSaveMenuState + 0x2e) == 0) {
 r = randomU32Next(); a = r % 13 + 14; idx = a & 0xffff;
 if ((u32)idx < 14) a = 14;
 if ((u32)idx >= 28) a = 27;
 idx = a & 0xffff;
 switch(idx) {
 case 27: flag = gMenuFlagItem27; goto check;
 case 22: flag = gMenuFlagItem22; goto check;
 case 20: flag = gMenuFlagItem20; goto check;
 case 17: flag = gMenuRowEnabled; check: if (!flag) a--; break;
 }
 *(s32 *)((u8 *)*(void **)((u8 *)gSaveMenuState + 0x18) + 0x14) = ((func_800260A0(a & 0xffff) & 0xffff) << 8) | 12;
 }
 func_8001E5BC();
}
