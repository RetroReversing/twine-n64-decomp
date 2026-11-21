extern s32 func_80015F74(void *);
extern s32 func_80022A30(u8, s32, s32, s32, s32);
extern s32 func_80022AD8(u8);
extern s32 func_80024D78(void);
extern s32 func_80024EF0(u16);
extern s32 func_8002A644(void *, void *, s32, s32, s32, s32, s32, s32, s32, void *, void *);
extern s32 func_8002A7CC(void *, void *, s32, s32);
extern s32 func_8002A9A8(void *, s32);
extern s32 func_8002AC04(void *, s32);
extern s32 func_8002CBD8(void);
extern s32 func_8002D09C(s32);
extern s32 updatePairedSpriteState(u16, u16, u8, s32);
extern u16 D_800B81A8;
extern u8 D_800B81AB;
extern s32 D_800BD550, D_800BD554;
extern u16 D_800BD558;
extern s8 D_800BD55A, D_800BD690;
extern s32 D_800BD5D0;
extern s32 D_80107EA8, D_80109C18[], D_80109C1C[], D_8010D478;
extern s32 func_800240A4, func_800241F8;
extern u8 gMenuParamC;
extern u8 *gMenuState;
void func_8002424C(void) {
    s32 i;
    s32 *record = &D_800BD5D0;
    func_8002CBD8();
    D_800BD690 = 0;
    func_8002A644(&D_80107EA8, &D_8010D478, 0xC0, 6, 0x58, 0xB2, 0x3C, 0x14, 1, &func_800240A4, &func_800241F8);
    func_80022A30(gMenuParamC, 0x20, 0x3C, 0xF8, 0x78);
    D_800BD554 = func_80015F74(record);
    D_800BD550 = func_80015F74(record - 0x24);
    for (i = 0; i < 16; i++) {
        s32 *p = record - 0x4C + i * 8;
        p[0] = gMenuParamC;
        p[9] = gMenuParamC;
        D_80109C18[i] = 0;
        D_80109C1C[i] = 0;
        if (func_8002D09C(i) == 0) p[-2] = 0x10;
        else p[-2] = 0xF;
        record[-0x34 + i * 0x18] = i + 0x4000;
        D_80109C18[i] = func_80015F74(record - 0x48 + i * 0x18);
        D_80109C1C[i] = func_80015F74(record - 0x6C + i * 0x18);
        func_8002A7CC(&D_80107EA8, &D_80109C18[i], i, 1);
    }
    func_80024D78();
    D_800BD55A = 0;
    D_800BD558 = 1;
    func_80022AD8(gMenuParamC);
    {
        u16 state = *(u16 *)(gMenuState + 0x14);
        if (state == 0x1A) D_800BD558 = 2;
        else if (state == 0x19 || state == 0x1B) D_800BD558 = 3;
        else D_800BD558 = 1;
    }
    updatePairedSpriteState(D_800BD558, D_800B81A8, D_800B81AB, 1);
    func_8002A9A8(&D_80107EA8, 0);
    func_8002AC04(&D_80107EA8, 1);
    {
        u16 state = *(u16 *)(gMenuState + 0x14);
        if ((u32)(state - 0x19) < 2) func_8002A9A8(&D_80107EA8, func_80024EF0(D_800BD558) & 0xFF);
    }
    *(s8 *)(gMenuState + 0x2C) = 0;
}
