typedef struct { u32 a, b, c, d; } FourWords;
extern u8 D_800BD68E, D_800BD68F, D_80102EDD, D_801007D2, D_801007D3, D_801007D4, D_8010A4C1[], D_8010A4C2;
extern u16 gUpdateGateWord;
extern FourWords D_800E1098, D_801007C8;
void func_8000A2B8(void);
void func_8000A368(void);
void func_8000A3AC(void);
void func_8001E7A4(u16);
void func_80026450(void) {
    u8 *flags = D_8010A4C1;
    s32 mask;
    *flags = 0;
    D_8010A4C2 = 0;
    func_8000A2B8();
    if (D_80102EDD == 0) {
        *flags |= 1;
        D_8010A4C2 |= 1;
    } else {
        D_800E1098 = D_801007C8;
        D_801007D2 = -1;
        D_801007D3 = -1;
        D_801007D4 = -1;
        if ((*(s32 *)&gUpdateGateWord) != 0) {
            D_8010A4C2 |= 1 << D_800BD68E;
        } else {
            mask = 1 << D_800BD68E;
            D_8010A4C2 |= mask;
            *flags |= mask;
        }
    }
    if (D_80102EDD != 0) func_8000A368();
    else func_8000A3AC();
    if (D_80102EDD != 0) func_8001E7A4(D_800BD68F);
}
