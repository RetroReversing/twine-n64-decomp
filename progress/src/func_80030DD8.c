extern s32 func_80030D40(void);
extern s32 D_800BFF04, D_800BFF10;
extern u16 D_800E1608;
void func_80030DD8(s32 arg0) {
    u16 i;
    switch (arg0) {
    case 8: {
        u16 x, count;
        s32 base;
        u16 *p;
        count = D_800E1608;
        i = 0;
        if (count) {
        base = D_800BFF04;
        do {
            p = (u16 *)(i * 8 + base + 2);
            x = *p;
            i++;
            if (((x & 0xF0) >> 4) == (x & 15))
                *p = (x & 0xFFF0) | 1;
        } while (i < count);
        }
        D_800BFF10 = func_80030D40();
        if (D_800BFF10 == 6) func_80030DD8(4);
        break;
    }
    case 5: {
        s32 base;
        u16 *p;
        base = D_800BFF04;
        D_800BFF10 = arg0;
        if (base) {
            u16 limit = D_800E1608;
            i = 0;
            if (limit) {
                s32 items = base;
                do {
                    p = (u16 *)(i * 8 + items + 2);
                    i++;
                    *p = (*p & 0xFFF0) | 1;
                } while (i < limit);
            }
        }
        break;
    }
    case 4:
    case 9: {
        u16 x, count;
        s32 base;
        u16 *p;
        count = D_800E1608;
        i = 0;
        if (count) {
        base = D_800BFF04;
        do {
            p = (u16 *)(i * 8 + base + 2);
            x = *p;
            if ((x & 15) != 0) goto nonzero;
            if ((x & 0xF0) == 0) goto skip;
nonzero:
            if ((x & 15) != 1) *p = (x & 0xFFF0) | 2;
skip:;
            i++;
        } while (i < count);
        }
        D_800BFF10 = func_80030D40();
    }
    case 7:
        D_800BFF10 = arg0;
        break;
    }
}
