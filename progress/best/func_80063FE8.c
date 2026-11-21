extern f32 approxDistance(void *, s32);
extern void actorInitTrackMarker(void *);
extern s16 randomIntBelow(u32);
extern s32 gSaveTotalSlots;
extern u32 gTrackMarkerCount;
extern u8 D_80100BE0[];
extern s32 gTrackMarkerIndex;
extern s32 sBonusObjectTable[];
extern u8 gTrackMarkerPosTable[];
extern u8 gSceneType;

void func_80063FE8(u8 *arg0) {
    f32 best;
    f32 d;
    f32 min;
    s16 cand;
    s16 j;
    s16 i;
    s16 t;
    s16 chosen;
    s32 isSpecial;
    u8 *act;

    best = -1.0f;
    act = *(u8 **)(arg0 + 0x6C);
    if ((u32)(gSceneType - 2) >= 2U) {
        for (;;) {
            j = 0;
            cand = randomIntBelow(gTrackMarkerCount);
            if (gSaveTotalSlots > 0) {
                do {
                    if (j != *(s8 *)(act + 0x182)) {
                        if (approxDistance(gTrackMarkerPosTable + (cand & 0xFFFF) * 0xC, sBonusObjectTable[j] + 0x24) < 3.0f)
                            goto again;
                    }
                    t = j + 1;
                    j = t;
                } while (t < gSaveTotalSlots);
            }
            chosen = cand;
            break;
again:
            ;
        }
    } else {
        chosen = 0;
        i = 0;
        if (gTrackMarkerCount != 0) {
            do {
                if (isSpecial == 0 || D_80100BE0[i & 0xFFFF] == (*(u8 **)(act + 0xB4))[0x12]) {
                    min = 4194304.0f;
                    j = 0;
                    if (gSaveTotalSlots > 0) {
                        do {
                            if (j != *(s8 *)(act + 0x182)) {
                                d = approxDistance(gTrackMarkerPosTable + (i & 0xFFFF) * 0xC, sBonusObjectTable[j] + 0x24);
                                if (d < min) min = d;
                            }
                            t = j + 1;
                            j = t;
                        } while (t < gSaveTotalSlots);
                    }
                    if (best < min) {
                        best = min;
                        chosen = i;
                    }
                }
                i++;
            } while ((u32)(i & 0xFFFF) < gTrackMarkerCount);
        }
    }
    gTrackMarkerIndex = chosen;
    actorInitTrackMarker(arg0);
}
