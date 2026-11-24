/* adapted from similar verified C in func_8004493C in TWINE (matched), with its names changed by decompdecomp */
typedef struct { void *p; char pad[12]; } Entry;
extern Entry gAssetSlotHeader[];
s32 getAssetSlotField18(s32 arg0) {
    s32 result = 0;
    void *p;
    if (arg0 >= 0) {
        p = gAssetSlotHeader[arg0].p;
        if (p) return *(s32 *)((char *)p + 24);
    }
    return 0;
}
