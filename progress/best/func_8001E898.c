#define FIELD(p,T,o) (*(T *)((u8 *)(p) + (o)))
extern s32 func_80018318(void *);
extern void func_80022B60(s32,s32);
extern void func_80022E5C(s32);
extern void func_80022E88(s32);
extern void func_80022EB8(s32,s32,s32);
extern s32 D_800BD660, D_800BD664, gMenuSoundParams;
extern u16 D_800E0ECC[], D_800E0ED4[], gMenuMode;
extern u8 gMenuSlot;
extern void *gSaveMenuState;
#define ALPHA FIELD(gSaveMenuState,u8,0x30)
void func_8001E898(void *item, s32 dim, s32 draw)
{
    void *obj = FIELD(item,void *,0);
    s32 mask;
    s32 flags;
    s32 width;
    s32 selected;
    if (obj) {
        flags = FIELD(obj,s32,0x28) & ~0xFC;
        FIELD(obj,u16,0x20) = FIELD(item,u16,4);
        width = FIELD(item,u16,6);
        { u32 enabled = (u8)dim == 0;
          u32 fill = 0u - enabled;
          flags |= fill & 0x1C; }
        FIELD(obj,s16,0x1E) = 0x40;
        FIELD(obj,s32,0x28) = flags;
        FIELD(obj,u16,0x22) = width;
        func_80022B60(0,width);
        mask = ~0xFF;
        FIELD(obj,s32,0x10) = (gMenuSoundParams & mask) | ALPHA;
        func_80022E88(0);
        func_80022E5C(ALPHA);
        switch (gMenuMode) {
        case 0:
            if (draw & 0xFF) goto draw_box;
            selected = D_800E0ECC[gMenuSlot];
            goto check_selection;
        case 1:
            if (draw & 0xFF) {
draw_box:
                width = (func_80018318(obj) * 12) & 0xFC;
                func_80022EB8((FIELD(item,u16,4)-2)&0xFFFF, (FIELD(item,u8,7)-4)&0xFF, width);
                FIELD(obj,s32,0x10) = (D_800BD664 & mask) | ALPHA;
                break;
            }
            selected = D_800E0ED4[gMenuSlot];
check_selection:
            if (selected == FIELD(item,u8,8))
                FIELD(obj,s32,0x10) = (D_800BD660 & mask) | ALPHA;
            break;
        }
        FIELD(obj,s32,0x10) = (FIELD(obj,s32,0x10) & ~0xFF) | ALPHA;
    }
}
