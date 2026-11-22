f32 approxDistance(void *, void *);
s32 findNearestMatchingObject(void *, void *, void **, f32 *);
extern u16 gSurfaceQueryStamp;
extern u16 D_80108F72;
extern void *sBonusObjectTable;
extern f32 D_80117408;

#define F(p, t, o) (*(t *)((s8 *)(p) + (o)))
#define NF ((found ^ 1) & 1)

void *func_8007847C(void *arg0) {
    void *sp10;
    f32 sp14;
    s32 temp_s6;
    s32 found;
    void *s5, *s0, *s2, *s4, *n, *a0, *v1;
    u16 stamp;
    void *v3, *c0;

    s5 = F(arg0, void *, 0x6C);
    sp10 = NULL;
    temp_s6 = F(arg0, s32, 0x60);
    if (F(s5, u8, 0x82) == 0x1E) {
        if (D_80117408 <= (f32) F(s5, s16, 0x74)) {
            n = F(F(arg0, void *, 0x20), void *, 0);
            for (; n != NULL; n = F(n, void *, 0)) {
                if (F(n, u16, 0x78) == 1 && (F(F(n, void *, 0x6C), s32, 0x88) & 0x01E00000) == 0x600000)
                    return n;
            }
        }
        goto block_49;
    }
    if (F(s5, u8, 0x82) == 0x1F) {
        n = F(F(arg0, void *, 0x20), void *, 0);
        for (; n != NULL; n = F(n, void *, 0)) {
            if (F(n, u16, 0x78) == 1 && (F(F(n, void *, 0x6C), s32, 0x88) & 0x01E00000) == 0x800000)
                return n;
        }
        goto block_48;
    }
    if ((F(s5, s32, 0x88) & 0x01E00000) == 0x200000) {
        void **tbl = (void **)&sBonusObjectTable;
        sp14 = approxDistance((s8 *)arg0 + 0x24, (s8 *)(*tbl) + 0x24);
        sp10 = *tbl;
    } else {
        sp10 = NULL;
        sp14 = 65536.0f;
    }
    stamp = gSurfaceQueryStamp + 1;
    gSurfaceQueryStamp = stamp;
    found = 0;
    if (D_80108F72 != 0) {
        F(arg0, s32, 0x60) &= 0xFFFE8FFF;
        c0 = F(arg0, void *, 0x20);
        F(F(c0, void *, 0x20), u16, 0x60) = stamp;
        if ((findNearestMatchingObject(c0, arg0, &sp10, &sp14) << 24) != 0) {
            found = 1;
            F(arg0, s32, 0x60) |= 0x1000;
        }
        s4 = F(F(c0, void *, 0x20), void *, 0x58);
        while ((s4 != NULL) & NF) {
            if (F(s4, u16, 0x26) & 0x2000) {
                a0 = F(s4, void *, 8);
                v1 = F(a0, void *, 0x20);
                s2 = F(v1, void *, 0x58);
                if (F(v1, u16, 0x60) != gSurfaceQueryStamp) {
                    F(v1, u16, 0x60) = gSurfaceQueryStamp;
                    if ((findNearestMatchingObject(a0, arg0, &sp10, &sp14) << 24) != 0) {
                        found = 1;
                        F(arg0, s32, 0x60) |= 0x2000;
                    }
                    while ((s2 != NULL) & NF) {
                        if (F(s2, u16, 0x26) & 0x2000) {
                            a0 = F(s2, void *, 8);
                            v1 = F(a0, void *, 0x20);
                            s0 = F(v1, void *, 0x58);
                            if (F(v1, u16, 0x60) != gSurfaceQueryStamp) {
                                F(v1, u16, 0x60) = gSurfaceQueryStamp;
                                if ((findNearestMatchingObject(a0, arg0, &sp10, &sp14) << 24) != 0) {
                                    found = 1;
                                    F(arg0, s32, 0x60) |= 0x4000;
                                }
                                while ((s0 != NULL) & NF) {
                                    if (F(s0, u16, 0x26) & 0x2000) {
                                        a0 = F(s0, void *, 8);
                                        v3 = F(a0, void *, 0x20);
                                        if (F(v3, u16, 0x60) != gSurfaceQueryStamp) {
                                            F(v3, u16, 0x60) = gSurfaceQueryStamp;
                                            if ((findNearestMatchingObject(a0, arg0, &sp10, &sp14) << 24) != 0) {
                                                found = 1;
                                                F(arg0, s32, 0x60) |= 0x8000;
                                            }
                                        }
                                    }
                                    s0 = F(s0, void *, 0);
                                }
                            }
                        }
                        s2 = F(s2, void *, 0);
                    }
                }
            }
            s4 = F(s4, void *, 0);
        }
        if (sp10 != NULL) {
            if (sp10 != *(void **)&sBonusObjectTable)
                F(s5, s32, 0x88) |= 0x40000000;
            else
                F(arg0, s32, 0x60) = temp_s6;
            return sp10;
        }
    }
    if ((F(s5, s32, 0x88) & 0x01E00000) == 0x400000) {
block_48:
        return NULL;
    }
block_49:
    return *(void **)&sBonusObjectTable;
}
