extern s32 D_800E06B8[];
extern s32 D_800E06F8;
void func_8000A724(s32 arg0) {
    register unsigned int i;
    s32 *base;
    register unsigned long n;
    if (arg0 != -1) {
        i = D_800E06F8;
        n = 15;
        base = D_800E06B8;
    for (;;) {
        if (base[i] != -1) {
            i = (i + 1) & 15;
            if (n--) continue;
        }
        break;
    }
        D_800E06F8 = (i + 1) & 15;
        base[i] = arg0;
    }
}
