typedef struct { void *p; char pad[12]; } Entry;
extern Entry D_800C0784[];
s32 func_8004493C(s32 arg0) {
    s32 result = 0;
    void *p;
    if (arg0 >= 0) {
        p = D_800C0784[arg0].p;
        if (p) return *(s32 *)((char *)p + 0x10);
    }
    return 0;
}
