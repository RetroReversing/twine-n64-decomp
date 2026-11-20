typedef struct {
    s32 words[3];
} TableEntry;

extern volatile s32 D_800F8158;
extern s32 D_800F815C;
extern u16 D_800F8160, D_800F8162, D_800F8164;
extern TableEntry D_800F8168[];
void func_8008C0D4(void);
void func_8008C11C(void);

s32 func_800972A4(u16 key, const void *value, u16 extra) {
    s32 count, i, j, off, newCount;
    u32 wanted;
    TableEntry *dst, *src;

    func_8008C0D4();
    count = D_800F8158;
    i = 0;
    if (count <= 0)
        goto append;
    wanted = key;
    off = 0;
scan:
    if (*(u16 *)((u8 *)&D_800F8160 + off) >= wanted)
        goto scanned;
    ++i;
    off += 12;
    if (i < count)
        goto scan;
scanned:
    count = D_800F8158;
    if (i >= count)
        goto append;
    off = i * 12;
    if (*(u16 *)((u8 *)&D_800F8160 + off) == wanted)
        goto exists;
    if (count >= 256)
        goto fail;
    j = count - 1;
    if (j >= i) {
        volatile s64 padding;
        TableEntry *base = D_800F8168;
        s32 shift = j * 12;
        dst = &base[j];
        --base;
        src = &base[j];
        do {
            *dst = *src;
            dst--;
            j--;
            src--;
        } while (j >= i);
    }
    newCount = D_800F8158 + 1;
    goto insert;
exists:
    ++*(u16 *)((u8 *)&D_800F8164 + off);
    goto fail;
append:
    {
        s32 appendCount = D_800F8158;
        if (appendCount < 256) {
            newCount = appendCount + 1;
            goto insert;
        }
    }
fail:
    func_8008C11C();
    return 0;
insert:
    do { D_800F8158 = newCount; } while (0);
    {
    s32 insertOffset = i * 12;
    *(u16 *)((u8 *)&D_800F8160 + insertOffset) = key;
    *(const void **)((u8 *)&D_800F815C + insertOffset) = value;
    *(u16 *)((u8 *)&D_800F8162 + insertOffset) = extra;
    *(u16 *)((u8 *)&D_800F8164 + insertOffset) = 1;
    }
    func_8008C11C();
    return 1;
}
