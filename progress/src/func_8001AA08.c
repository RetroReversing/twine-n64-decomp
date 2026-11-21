/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 formatTextEntry();
s32 updateActiveMenuState();
s32 lookupDataEntry();
extern s32 D_801002A8;
extern s32 D_80102FD4;
extern void *gMenuState;
extern s32 D_80117730;

extern char D_800D2858[];
extern char D_800D2864[];
void func_8001AA08(void) {
    u16 n;

    updateActiveMenuState();
    if ((*(u8 *)((char *)(gMenuState) + 0x2D)) != 0) {
        n = *(u16 *)((D_80117730 * 2) + D_80102FD4);
        D_801002A8 = n;
        if (n != 0) {
            formatTextEntry((*(s32 *)((char *)(gMenuState) + 0x18)) + 0x28, D_800D2858, n);
        } else {
            formatTextEntry((*(s32 *)((char *)(gMenuState) + 0x18)) + 0x28, D_800D2864, lookupDataEntry(0x5F));
        }
    }
}
