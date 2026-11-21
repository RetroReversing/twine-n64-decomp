s32 insertSortedKeyEntry();
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
        if (found != NULL) insertSortedKeyEntry(*arg0, found + 12, *(u16 *)(found+10));
        arg0++;
    }
}
