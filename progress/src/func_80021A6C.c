s32 func_800219A0(u8);
s32 func_80026004(s32, s32 *, s32);
s32 func_80029068();
s32 func_80087100(s32);
extern void *D_80109BB0;
extern u8 D_8010A4C0;
extern char D_800D2AA0[];

void func_80021A6C(void) {
    s32 base;
    u8 *p;
    s32 v;
    s32 a;
    u8 *ctx;

    func_80029068();
    ctx = (u8 *)D_80109BB0;
    if (ctx[0x2D] != 0) {
        base = *(s32 *)(ctx + 0x18) + 0x28;
        p = &D_8010A4C0;
        a = func_800219A0(*p);
        if ((a & 0xFF) == 0 || (v = *p) == 0) {
            func_80026004(base, (s32 *)D_800D2AA0, func_80087100(0x16));
        } else if (v == 1) {
            func_80026004(base, (s32 *)D_800D2AA0, func_80087100(0x17));
        }
    }
}
