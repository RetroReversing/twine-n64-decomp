typedef struct { u32 a, b, c, d; } FourWords;
extern u8 gMenuListParam, gMenuSlot, gMenuUseTextList, D_801007D2, D_801007D3, D_801007D4, gSceneFlagsA[], gSceneFlagsB;
extern u16 gBorderSkipFlag;
extern FourWords D_800E1098, D_801007C8;
void func_8000A2B8(void);
void func_8000A368(void);
void func_8000A3AC(void);
void func_8001E7A4(u16);
void func_80026450(void) {
    u8 *flags = gSceneFlagsA;
    s32 mask;
    *flags = 0;
    gSceneFlagsB = 0;
    func_8000A2B8();
    if (gMenuUseTextList == 0) {
        *flags |= 1;
        gSceneFlagsB |= 1;
    } else {
        D_800E1098 = D_801007C8;
        D_801007D2 = -1;
        D_801007D3 = -1;
        D_801007D4 = -1;
        if ((*(s32 *)&gBorderSkipFlag) != 0) {
            gSceneFlagsB |= 1 << gMenuListParam;
        } else {
            mask = 1 << gMenuListParam;
            gSceneFlagsB |= mask;
            *flags |= mask;
        }
    }
    if (gMenuUseTextList != 0) func_8000A368();
    else func_8000A3AC();
    if (gMenuUseTextList != 0) func_8001E7A4(gMenuSlot);
}
