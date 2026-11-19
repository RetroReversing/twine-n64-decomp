extern s32 D_801002B4;
extern s32 *D_8010A500[];

s32 *func_8011B3D8(s32 arg0) {
    u16 i;
    s32 *p;
    s32 *q;

    arg0 &= 0x1E000;
    for (i = 0; i < D_801002B4; i++) {
        p = D_8010A500[i];
        if (p != NULL) {
            q = ((s32 **)p)[0x6C / 4];
            if (q != NULL && arg0 == (*q & 0x1E000)) {
                return q;
            }
        }
    }
    return NULL;
}
