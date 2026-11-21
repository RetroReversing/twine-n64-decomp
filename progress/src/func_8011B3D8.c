extern s32 gSaveTotalSlots;
extern s32 *sBonusObjectTable[];

s32 *func_8011B3D8(s32 arg0) {
    u16 i;
    s32 *p;
    s32 *q;

    arg0 &= 0x1E000;
    for (i = 0; i < gSaveTotalSlots; i++) {
        p = sBonusObjectTable[i];
        if (p != NULL) {
            q = ((s32 **)p)[0x6C / 4];
            if (q != NULL && arg0 == (*q & 0x1E000)) {
                return q;
            }
        }
    }
    return NULL;
}
