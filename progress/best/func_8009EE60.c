void func_8009EE60(s32 a0, s32 a1, s16 *a2, s16 *a3)
{
    s32 idx;
    s32 t0, t1, t2, t3, t4;
    s32 i;
    s16 *p;

    if (a0 <= 7) {
        idx = 0;
        t0 = idx >> 4;
        t1 = idx & 7;
    } else {
        t0 = (a0 - 8) >> 3;
        t1 = a0 & 7;
    }
    t4 = (t1 << 11) + 0x47FF;
    t2 = 6 - t0;
    t3 = 1 << (t2 - 1);
    p = a2;
    for (i = 13; i > 0; i--) {
        s32 v = ((*p << 13) - 0x7000) * t4;
        v = (v + 0x4000) >> 15;
        *p = (s16)((v + t3) >> t2);
        p++;
    }
    p = a3;
    for (i = 40; i > 0; i--) {
        *p++ = 0;
    }
    p = a3 + a1 * 2;
    p = a3 + a1 * 2;
    for (i = 13; i > 0; i--) {
        *p = *a2++;
        p += 3;
    }
}
