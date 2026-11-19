extern s16 D_800D1D6C[];
extern s8 D_800D1DB8[];

void func_80001EB8(s32 *arg0, s32 *arg1) {
    s32 k = *arg0;
    s32 v = *arg1;
    s8 *p = D_800D1DB8;
    u32 i = 0;
    s32 neg = -1;
    s16 *base = D_800D1D6C;
    s16 *np = base + 1;
    s16 *kp = base;

    for (; i < 0x26; np += 2, i += 2, kp += 2) {
        s32 n = *np;
        s32 key = *kp;
        while (n-- != 0) {
            if (k == key && v == p[0]) {
                s32 r = p[1];
                *arg1 = r;
                if (r < 0) {
                    *arg0 = neg;
                }
                return;
            }
            p += 2;
        }
    }
}
