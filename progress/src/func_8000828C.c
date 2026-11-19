typedef struct { u8 pad0[0x78C]; s32 w78C; s32 w790; } Ctx828C;

s32 func_80083E90(s32, s32);
extern s32 D_800B1D7C;
extern s32 D_800B1D80;
extern s32 D_800B1D84;
extern s32 D_80102ED8;
extern s32 D_80108F78;
extern Ctx828C *D_8010A2BC[];
extern u16 D_8010A518;

void func_8000828C(void) {
    u32 i;

    if (D_80102ED8 != 0) {
        D_800B1D80 = 0x640;
        D_800B1D7C = 0x1388;
    } else {
        D_800B1D80 = 0x190;
        D_800B1D7C = 0xBB8;
        if (D_80108F78 == 0x24) {
            D_800B1D7C = 0xE74;
        }
    }
    D_800B1D84 = D_800B1D80 - 1;
    for (i = 0; i < D_8010A518; i++) {
        D_8010A2BC[i]->w790 = func_80083E90(D_800B1D7C * 8, 0x31);
        D_8010A2BC[i]->w78C = func_80083E90(D_800B1D80 << 6, 0x31);
    }
}
