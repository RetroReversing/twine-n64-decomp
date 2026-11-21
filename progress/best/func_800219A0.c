extern void updateVideoMode(void);
extern void setupMenuListFlags(void);
extern void func_8007560C(void);
extern s16 gExpansionPakPresent;
extern s8 D_8010A4C0;
extern s32 D_8010A4E4;
extern s32 gHiResScreen;
extern s32 D_8010A4EC;
extern s32 D_8010A4F0;
extern s32 D_8010A4F4;
extern s32 D_8010A4F8;

s32 func_800219A0(s8 arg0) {
    s32 result;
    s32 *p;
    s32 t;

    result = 1;
    p = &D_8010A4E4;
    t = gExpansionPakPresent;
    D_8010A4C0 = arg0;
    if (t == 0 && (arg0 & 0xFF)) {
        D_8010A4C0 = 0;
        result = 0;
    }
    if (*((u8 *)p - 0x24) == 0) {
        *p = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 1;
        p[4] = 0;
        p[5] = 0;
    } else {
        gHiResScreen = 0;
        D_8010A4EC = 1;
        D_8010A4F0 = 0;
        D_8010A4F4 = 1;
        D_8010A4F8 = 0;
    }
    updateVideoMode();
    func_8007560C();
    D_8010A4E4 = 1;
    setupMenuListFlags();
    return result;
}
