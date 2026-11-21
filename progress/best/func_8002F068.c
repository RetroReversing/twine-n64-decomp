typedef struct { u8 pad[16]; u32 color; } DisplayItem;
typedef struct { u16 tick, alpha; } Pulse;
typedef struct { u8 pad[0x7A]; u16 value; } MenuData;
typedef struct { u8 pad[12]; void *display; } MenuObject;

DisplayItem *func_80027408(s32, s32, s16, u8);
void func_800278AC(s32, u32, u16);
s32 func_80027CE0(s32);
void func_8002B050(void *, s32, DisplayItem *);
void func_8002B150(void *, s32, s8);
void func_8002FBD4(void *, s16);
s32 lookupDataEntry(s32);
extern u32 D_800BD640[];
extern u8 D_800BD8C4[];
extern u16 D_800BFC92;
extern u16 D_800BFC94, D_800BFC96;
extern DisplayItem *volatile D_800E1560;
extern u8 D_800E1584[];
extern u32 gMenuSoundParams;
extern u8 D_80102EDC, gPendingMenuCommand;
extern MenuData *sActiveMenu;
extern MenuObject *gMenuState;

void func_8002F068(void *unused, void *arg1)
{
    s32 asset;
    s32 mode;
    s32 x, y;
    DisplayItem *item;
    u32 phase;
    u32 *color, *palette;
    DisplayItem *current;

    if (!(u8)func_80027CE0(0x23) && !(u8)func_80027CE0(0x2A) && !gPendingMenuCommand) {
        asset = lookupDataEntry(0x2E9);
        mode = D_800BFC92 & 1;
        x = mode ? 0xA0 : 0xDC;
        y = mode ? 0xB0 : 0x45;
        item = func_80027408(asset, 0, x, y);
        D_800E1560 = item;

        phase = D_800BFC94 & 63;
        D_800BFC96 = phase;
        if (phase >= 32) {
            D_800BFC96 = 63 - phase;
        }
        palette = D_800BD640;
        if (D_800BFC92 & 1) {
            color = palette + 1;
        } else {
            color = palette + 9;
        }
        current = D_800E1560;
        item->color = *color & ~255;
        *(volatile u32 *)&current->color = (current->color & ~255) | (D_800BFC96 << 3);
        D_800BFC94++;
        if (D_80102EDC) {
            func_8002B050(D_800E1584, 1, item);
        }
    } else {
        D_800BFC94 = 0;
        gMenuState->display = D_800BD8C4;
        func_800278AC(1, gMenuSoundParams & ~255, sActiveMenu->value);
        func_80027408(lookupDataEntry(3), 0x40, 0xA0, 0xCC);
        func_8002B150(D_800E1584, 0, 0);
        func_8002FBD4(arg1, 4);
    }
}
