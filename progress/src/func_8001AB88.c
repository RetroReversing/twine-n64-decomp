void func_80022B60(s32, ...);
extern u32 sSaveMenuFlagsA;
extern u32 D_800BD64C;
extern u8 gMenuUseTextList;
extern u8 *gMenuState;
typedef struct { u8 pad[0x10]; u32 color; u8 pad14[0xC]; u16 x, y; u8 pad24[4]; u32 hi : 24; u32 mode : 6; u32 lo : 2; } Spr;
typedef struct { Spr *spr; u16 x, y; u8 kind; } Ent;

void func_8001AB88(Ent *arg0, u8 arg1) {
    Spr *s = arg0->spr;

    if (s != NULL) {
        s->x = arg0->x;
        s->y = arg0->y;
        if (arg0->kind == 0xFF) {
            s->color = (sSaveMenuFlagsA & ~0xFF) | gMenuState[0x30];
        } else {
            s->color = (D_800BD64C & ~0xFF) | gMenuState[0x30];
        }
        if (gMenuUseTextList == 0) {
            func_80022B60(3);
            s->mode = (arg1 == 0 ? 7 : 0) | 3;
        } else {
            s->mode = (arg1 == 0 ? 7 : 0) | 2;
            func_80022B60(2);
        }
    }
}
