s32 func_800266DC(s32, s32);
extern u8 D_800BD694;
extern u8 D_800BD695[];
extern s8 D_800BD705;
extern void *D_80102F2C;
extern s16 D_80108400;
void func_80027D60(s32 arg0) {
    s32 result;
    if (D_80102F2C != NULL) {
        if ((arg0 & 0xFFFF) == 4) {
            if (D_80108400 == 0) {
                D_800BD705 = 5;
            } else {
                D_800BD705 = 3;
            }
        }
        *(s16 *)((s8 *)D_80102F2C + 0x7A) = *(u8 *)(D_800BD695 + ((arg0 & 0xFFFF) * 0x1C));
        *(s16 *)((s8 *)D_80102F2C + 0x7C) = 0x78;
        func_800266DC(*(s16 *)((s8 *)D_80102F2C + 0x7A) * 0x1C + (s32)&D_800BD694, arg0);
    }
}
