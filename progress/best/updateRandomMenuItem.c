extern void func_8001E5BC(void);
extern s32 func_800260A0(s32);
extern u32 randomU32Next(void);
extern u8 gMenuFlagItem20, gMenuFlagItem22, gMenuFlagItem27, sMenuRowEnabled;
extern void *gSaveMenuState;
void updateRandomMenuItem(void) {
    s32 a, v;
    u8 flag;
    if (*(u8 *)((char *)gSaveMenuState + 0x2e) == 0) {
        a = randomU32Next() % 13 + 14;
        v = a & 0xffff;
        if (v < 14) { a = 14; v = a & 0xffff; }
        else if (v >= 28) { a = 27; v = a & 0xffff; }
        switch (v) {
        case 27: flag = gMenuFlagItem27; goto check;
        case 22: flag = gMenuFlagItem22; goto check;
        case 20: flag = gMenuFlagItem20; goto check;
        case 17: flag = sMenuRowEnabled;
        check: if (flag == 0) a--; break;
        }
        *(s32 *)((char *)*(void **)((char *)gSaveMenuState + 0x18) + 0x14) = ((func_800260A0(a & 0xffff) & 0xffff) << 8) | 12;
    }
    func_8001E5BC();
}
