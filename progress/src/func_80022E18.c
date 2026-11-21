s32 spawnTextNode(void *);
extern s16 D_800B7D1C;
extern s32 D_800B7D20;

void func_80022E18(s32 arg0) {
    s16 *p;
    if (D_800B7D20 == 0) {
        p = &D_800B7D1C;
        *p = arg0 & 0xFF;
        D_800B7D20 = spawnTextNode((char *)p - 0x20);
    }
}
