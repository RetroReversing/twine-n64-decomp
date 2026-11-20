/* adapted from similar verified C in func_8004493C in TWINE (matched), with its names changed by decompdecomp */
typedef struct { void *p; char pad[12]; } Entry;
extern Entry D_800C0784[];
s32 func_80044968(s32 arg0) {
    s32 result = 0;
    void *p;
    if (arg0 >= 0) {
        p = D_800C0784[arg0].p;
        if (p) return *(s32 *)((char *)p + 24);
    }
    return 0;
}
