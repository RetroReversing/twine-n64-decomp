extern s32 func_80030D40(void);
extern s32 D_800BFF04, D_800BFF10;
extern u16 D_800E1608;
void func_80030DD8(s32 arg0) {
    u16 i, x, count, j;
    s32 base;
    u16 *p;
    switch (arg0) {
    case 8:
        count = D_800E1608;
        i = 0;
        if (count) {
        base = D_800BFF04;
        do {
            p = (u16 *)(base + i * 8 + 2);
            x = *p;
            i++;
            if (((x & 0xF0) >> 4) == (x & 15))
                *p = (x & 0xFFF0) | 1;
        } while (i < count);
        }
        D_800BFF10 = func_80030D40();
        if (D_800BFF10 == 6) func_80030DD8(4);
        break;
    case 5:
        D_800BFF10 = arg0;
        base = D_800BFF04;
        if (base) {
            for (i = 0; i < D_800E1608; i++) {
                p = (u16 *)(base + i * 8 + 2);
                *p = (*p & 0xFFF0) | 1;
            }
        }
        break;
    case 4:
    case 9:
        count = D_800E1608;
        j = 0;
        if (count) {
        base = D_800BFF04;
        do {
            p = (u16 *)(base + j * 8 + 2);
            x = *p;
            if ((x & 15) != 0) goto nonzero;
            if ((x & 0xF0) == 0) goto skip;
nonzero:
            if ((x & 15) != 1) *p = (x & 0xFFF0) | 2;
skip:;
            j++;
        } while (j < count);
        }
        D_800BFF10 = func_80030D40();
    case 7:
        D_800BFF10 = arg0;
        break;
    }
}
