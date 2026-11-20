extern void *D_800BF5A0;
extern void func_8002AF44(void *);
s32 func_8002AEC8(void *arg0) {
    void *p;
    void (*f)();
    s32 result = 0;
    D_800BF5A0 = arg0;
    if (arg0) {
        p = *(void **)((char *)arg0 + 4);
        if (p) {
            f = *(void (**)())((char *)p + 4);
            if (f) f();
        }
        if (*(u8 *)((char *)arg0 + 15)) {
            func_8002AF44(arg0);
            return 0;
        }
        return 1;
    }
    return 0;
}
