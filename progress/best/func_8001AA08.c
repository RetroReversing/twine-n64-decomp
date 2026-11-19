/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80026004();
s32 func_80029068();
u16 func_80087100();
extern s32 D_801002A8;
extern s32 D_80102FD4;
extern void *D_80109BB0;
extern s32 D_80117730;

extern char D_800D2858[];
extern char D_800D2864[];
void func_8001AA08(void) {
    s32 var_a0;
    s32 *var_a1;
    u16 var_a2;

    func_80029068();
    if ((*(u8 *)((char *)(D_80109BB0) + 0x2D)) != 0) {
        var_a2 = *(u16 *)((D_80117730 * 2) + D_80102FD4);
        D_801002A8 = (s32) var_a2;
        if (var_a2 != 0) {
            var_a0 = (*(s32 *)((char *)(D_80109BB0) + 0x18));
            var_a1 = D_800D2858;
        
        func_80026004(var_a0 + 0x28, var_a1);} else {
            var_a1 = D_800D2864;
            var_a2 = func_80087100(0x5F);
            var_a0 = (*(s32 *)((char *)(D_80109BB0) + 0x18));
        
        func_80026004(var_a0 + 0x28, var_a1);}
    }
}
