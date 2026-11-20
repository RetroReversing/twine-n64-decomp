void func_80092A28(s32 arg0, u16 *arg1) { func_80097D0C(arg0 & 0xFFFF, arg1 + 2, *arg1); }
extern int D_800CE570; extern signed char D_800E1A90; extern int D_80102CB8;
void func_80083E44(int arg0) { if (D_800E1A90 == 0) { int old = D_80102CB8; int *p = &D_800CE570; int v = *p; D_80102CB8 = arg0; *p = v - (arg0 - old); } }
s32 func_800972A4();
static inline char *find_chunk(void *arg1, u16 id) {
    char *c = (char *)arg1 + *(s32 *)((char *)arg1 + 12);
    while (*(s32 *)c != -1) {
        if (*(u16 *)(c + 4) == id) return c;
        c += *(s32 *)c;
    }
    return NULL;
}
void func_800928F4(u16 *arg0, void *arg1) {
    char *found;
    while (*arg0 != 0xFFFF) {
        found = find_chunk(arg1, *arg0);
        if (found != NULL) func_800972A4(*arg0, found + 12, *(u16 *)(found+10));
        arg0++;
    }
}
extern u16 D_800BF686;
s32 getKeyEntryFlag(s32 arg0) {
    return (*(u16 *)((char *)&D_800BF686 + arg0 * 12) >> 7) & 1;
}
