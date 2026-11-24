f32 approxDistance(void *, void *);
s32 findNearestMatchingObject(void *, void *, void **, f32 *);
extern u16 gSurfaceQueryStamp;
extern u16 gTargetSearchEnabled;
extern void *sBonusObjectTable;
extern f32 gMinTargetValue;

#define F(p, t, o) (*(t *)((s8 *)(p) + (o)))
#define NF ((found ^ 1) & 1)

/* Picks the target object for an actor: kinds 0x1E/0x1F scan the sibling list; otherwise searches the actor's cell and linked cells (up to 3 deep) for the nearest match, falling back to the bonus object. */
void *findTargetObject(void *actor) {
    void *best;
    f32 bestDist;
    s32 savedFlags;
    s32 found;
    void *actorInfo, *link3, *link2, *link1, *sibling, *nextCell, *nextCellData;
    u16 stamp;
    void *cellData3, *cell;

    actorInfo = F(actor, void *, 0x6C);
    best = NULL;
    savedFlags = F(actor, s32, 0x60);
    if (F(actorInfo, u8, 0x82) == 0x1E) {
        if (gMinTargetValue <= (f32) F(actorInfo, s16, 0x74)) {
            sibling = F(F(actor, void *, 0x20), void *, 0);
            for (; sibling != NULL; sibling = F(sibling, void *, 0)) {
                if (F(sibling, u16, 0x78) == 1 && (F(F(sibling, void *, 0x6C), s32, 0x88) & 0x01E00000) == 0x600000)
                    return sibling;
            }
        }
        goto block_49;
    }
    if (F(actorInfo, u8, 0x82) == 0x1F) {
        sibling = F(F(actor, void *, 0x20), void *, 0);
        for (; sibling != NULL; sibling = F(sibling, void *, 0)) {
            if (F(sibling, u16, 0x78) == 1 && (F(F(sibling, void *, 0x6C), s32, 0x88) & 0x01E00000) == 0x800000)
                return sibling;
        }
        goto block_48;
    }
    if ((F(actorInfo, s32, 0x88) & 0x01E00000) == 0x200000) {
        void **tbl = (void **)&sBonusObjectTable;
        bestDist = approxDistance((s8 *)actor + 0x24, (s8 *)(*tbl) + 0x24);
        best = *tbl;
    } else {
        best = NULL;
        bestDist = 65536.0f;
    }
    stamp = gSurfaceQueryStamp + 1;
    gSurfaceQueryStamp = stamp;
    found = 0;
    if (gTargetSearchEnabled != 0) {
        F(actor, s32, 0x60) &= 0xFFFE8FFF;
        cell = F(actor, void *, 0x20);
        F(F(cell, void *, 0x20), u16, 0x60) = stamp;
        if ((findNearestMatchingObject(cell, actor, &best, &bestDist) << 24) != 0) {
            found = 1;
            F(actor, s32, 0x60) |= 0x1000;
        }
        link1 = F(F(cell, void *, 0x20), void *, 0x58);
        while ((link1 != NULL) & NF) {
            if (F(link1, u16, 0x26) & 0x2000) {
                nextCell = F(link1, void *, 8);
                nextCellData = F(nextCell, void *, 0x20);
                link2 = F(nextCellData, void *, 0x58);
                if (F(nextCellData, u16, 0x60) != gSurfaceQueryStamp) {
                    F(nextCellData, u16, 0x60) = gSurfaceQueryStamp;
                    if ((findNearestMatchingObject(nextCell, actor, &best, &bestDist) << 24) != 0) {
                        found = 1;
                        F(actor, s32, 0x60) |= 0x2000;
                    }
                    while ((link2 != NULL) & NF) {
                        if (F(link2, u16, 0x26) & 0x2000) {
                            nextCell = F(link2, void *, 8);
                            nextCellData = F(nextCell, void *, 0x20);
                            link3 = F(nextCellData, void *, 0x58);
                            if (F(nextCellData, u16, 0x60) != gSurfaceQueryStamp) {
                                F(nextCellData, u16, 0x60) = gSurfaceQueryStamp;
                                if ((findNearestMatchingObject(nextCell, actor, &best, &bestDist) << 24) != 0) {
                                    found = 1;
                                    F(actor, s32, 0x60) |= 0x4000;
                                }
                                while ((link3 != NULL) & NF) {
                                    if (F(link3, u16, 0x26) & 0x2000) {
                                        nextCell = F(link3, void *, 8);
                                        cellData3 = F(nextCell, void *, 0x20);
                                        if (F(cellData3, u16, 0x60) != gSurfaceQueryStamp) {
                                            F(cellData3, u16, 0x60) = gSurfaceQueryStamp;
                                            if ((findNearestMatchingObject(nextCell, actor, &best, &bestDist) << 24) != 0) {
                                                found = 1;
                                                F(actor, s32, 0x60) |= 0x8000;
                                            }
                                        }
                                    }
                                    link3 = F(link3, void *, 0);
                                }
                            }
                        }
                        link2 = F(link2, void *, 0);
                    }
                }
            }
            link1 = F(link1, void *, 0);
        }
        if (best != NULL) {
            if (best != *(void **)&sBonusObjectTable)
                F(actorInfo, s32, 0x88) |= 0x40000000;
            else
                F(actor, s32, 0x60) = savedFlags;
            return best;
        }
    }
    if ((F(actorInfo, s32, 0x88) & 0x01E00000) == 0x400000) {
block_48:
        return NULL;
    }
block_49:
    return *(void **)&sBonusObjectTable;
}
