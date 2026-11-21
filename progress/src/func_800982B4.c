typedef struct { u16 a; u16 b; } Pair982B4;
extern Pair982B4 D_800F8D60[];
extern s32 D_800F3880;
extern s32 D_800F3884;
extern s16 D_800F388C;
extern s32 *D_800F3890;
extern u8 D_800F9560[];
s32 *binarySearchRecords(void *, void *, s32, s32, void *);
void func_800986BC(void);

s32 func_800982B4(s16 arg0) {
    u32 idx = (u16)arg0 >> 6;
    s16 *p;
    s32 *r;
    s32 b;

    D_800F3884 = idx;
    if (D_800F8D60[idx].a != 0) {
        b = D_800F8D60[idx].b;
        p = &D_800F388C;
        *p = arg0;
        D_800F3880 = b;
        r = binarySearchRecords((u8 *)p - 4, &D_800F9560[b * 8], D_800F8D60[idx].a, 8, func_800986BC);
        D_800F3890 = r;
        if (r == NULL) {
            return 0;
        }
        return *r;
    }
    return 0;
}
