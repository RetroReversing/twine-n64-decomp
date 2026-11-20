s32 func_8008C0D4();
s32 func_8008C11C();
extern s32 D_800F8D5C;
extern u16 D_800F8D5E;
extern char D_800F8D60[];
extern char D_800F8D62[];
extern char D_800F9560[];
extern char D_800F9564[];
extern char D_800F9566[];
extern char D_800F9568[];

s32 func_80097EF8(s16 arg0, s32 arg1) {
    u32 key;
    u32 bucket;
    s32 boff;
    s32 i;
    s32 cnt;
    s32 start;
    s32 pos;
    s32 n;
    s32 j;

    func_8008C0D4();
    key = arg0 & 0xFFFF;
    bucket = key >> 6;
    boff = bucket * 4;
    cnt = *(u16 *)(D_800F8D60 + boff);
    if (cnt == 0) {
        pos = D_800F8D5E & 0xFFFF;
        *(u16 *)(D_800F8D62 + boff) = D_800F8D5E;
        goto insert;
    }
    start = *(u16 *)(D_800F8D62 + boff);
    i = 0;
    while (*(u16 *)(D_800F9564 + (start + i) * 8) < key) {
        i++;
        if (i >= cnt) {
            pos = start + i;
            goto check;
        }
    }
    pos = start + i;
check:
    if (i < *(u16 *)(D_800F8D60 + boff)) {
        if (*(u16 *)(D_800F9564 + pos * 8) == key) {
            *(u16 *)(D_800F9566 + pos * 8) += 1;
            func_8008C11C((s32) key);
            return 0;
        }
    }
insert:
    n = 0;
    if (D_800F8D5C < 0x800) {
        for (j = 0; j < 0x800; j += 4) {
            u16 s = *(u16 *)(D_800F8D62 + j);
            if (start < s) {
                *(u16 *)(D_800F8D60 + j + 2) = s + 1;
            }
        }
        n = D_800F8D5C - 1;
        for (; n >= pos; n--) {
            *(s32 *)(D_800F9568 + n * 8) = *(s32 *)(D_800F9568 + (n - 1) * 8);
            *(s32 *)(D_800F9568 + n * 8 + 4) = *(s32 *)(D_800F9568 + (n - 1) * 8 + 4);
        }
        *(u16 *)(D_800F9564 + pos * 8) = arg0;
        *(u16 *)(D_800F9566 + pos * 8) = 1;
        *(s32 *)(D_800F9560 + pos * 8) = arg1;
        *(u16 *)(D_800F8D60 + boff) += 1;
        D_800F8D5C += 1;
        func_8008C11C(pos * 8, boff, n, (void *) 0);
        return 1;
    }
    func_8008C11C((s32) key);
    return 0;
}
