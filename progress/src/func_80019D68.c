extern s32 D_801002B8, D_801002BC;
s32 func_80019B34(s32);

s32 func_80019D68(void) {
    s32 limit = D_801002B8;
    s32 count;
    s32 i = 0;
    u16 j;
    s32 start;

    if (limit > 0) {
        do {
            if ((u16)func_80019B34((u16)i) != 0x159)
                return 0;
            count = D_801002B8;
            i++;
        } while ((u16)i < count);
    }

    count = D_801002BC;
    j = 4;
    start = j;
    if (start < count + 4) {
        do {
            if ((u16)func_80019B34(j) != 0x159)
                return 0;
            count = D_801002BC;
            j++;
        } while ((j & 0xFFFF) < count + 4);
    }
    return 1;
}
