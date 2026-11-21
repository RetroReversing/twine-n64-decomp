void segmentClosestPoint(void *a, void *b, void *c, void *d);
void normalizeVector3(f32 *a, f32 *b);
f32 approxDistance(void *a, void *b);
extern u8 D_801096A0;
extern u8 gTrackMarkerDone[];

/* Finds the two track segments nearest the actor and blends their light colours into outR/outG/outB, clamped to 0xFF. Returns the nearest segment or NULL. */
void *trackFindNearestLight(u8 *actor, u8 *outR, u8 *outG, u8 *outB) {
    void *nearestSegs[2];
    f32 nearestDist[2];
    f32 closestPoint[3];
    f32 toSegDir[3];
    union { u8 * pointer; u32 value; } __repair_phase_storage;
    u8 *segList;
    f32 lightDot;
    u8 *nearestSeg;
    union { u32 index; u8 *selected; } sortIdx;
    f32 *pos;
    f32 *tf;
    f32 dist;
    s32 idx;
    register u8 *seg;
    u32 red, green, blue, weight;
    register unsigned int k;
    pos = (f32 *)(actor + 0x24);
    __repair_phase_storage.pointer = *(u8 **)(actor + 0x20);
    if (__repair_phase_storage.pointer != NULL) {
        segList = *(u8 **)(*(u8 **)(__repair_phase_storage.pointer + 0x20) + 0x58);
        for (idx = 0; (u32)idx < 2; idx++) {
            nearestSegs[idx] = NULL;
            nearestDist[idx] = 65536.0f;
        }
        while (__repair_phase_storage.pointer != NULL) {
            seg = *(u8 **)(*(u8 **)(__repair_phase_storage.pointer + 0x20) + 0x50);
            while (seg != NULL) {
                if (seg[0x2B] == 0 || gTrackMarkerDone[seg[0x2B]] != 0) {
                    segmentClosestPoint(closestPoint, seg + 4, seg + 0x10, ((f32 *)(actor + 0x24)));
                    dist = approxDistance(((f32 *)(actor + 0x24)), closestPoint);
                    idx = 0;
                    do {
                        if (dist > 0.0f && dist < nearestDist[idx]) {
                            for (sortIdx.index = 1; sortIdx.index > idx; sortIdx.index--) {
                                nearestDist[sortIdx.index] = nearestDist[sortIdx.index - 1];
                                nearestSegs[sortIdx.index] = nearestSegs[sortIdx.index - 1];
                            }
                            nearestSegs[idx] = seg;
                            nearestDist[idx] = dist;
                            break;
                        }
                    } while ((u32)++idx < 2U);
                }
                seg = *(u8 **)seg;
            }
            if (segList != NULL) {
                __repair_phase_storage.pointer = *(u8 **)(segList + 8);
                segList = *(u8 **)segList;
            } else {
                __repair_phase_storage.pointer = NULL;
            }
        }
        blue = 0; green = 0; red = 0;
        idx = 0;
        do {
            sortIdx.selected = nearestSegs[idx];
            if (!sortIdx.selected) goto next_color;
            {
                nearestSeg = sortIdx.selected;
                tf = (f32 *)nearestSeg;
                toSegDir[0] = ((f32 *)(actor + 0x24))[0] - tf[1];
                toSegDir[1] = ((f32 *)(actor + 0x24))[1] - tf[2];
                toSegDir[2] = ((f32 *)(actor + 0x24))[2] - tf[3];
                normalizeVector3(toSegDir, toSegDir);
                lightDot = toSegDir[0] * tf[7] + toSegDir[1] * tf[8] + toSegDir[2] * tf[9];
                if (lightDot > 0.0f) {
                    weight = (u32)lightDot & 0xFFFF;
                    red += (weight * nearestSeg[0x28]) >> 8;
                    green += (weight * nearestSeg[0x29]) >> 8;
                    blue += (weight * nearestSeg[0x2A]) >> 8;
                    if ((red & 0xFFFF) >= 0x100) red = 0xFF;
                    if ((green & 0xFFFF) >= 0x100) green = 0xFF;
                    if ((blue & 0xFFFF) >= 0x100) blue = 0xFF;
                }
            }
next_color:
            ++idx;
        } while ((u32)idx < 2);
        __repair_phase_storage.value = D_801096A0;
        if ((red & 0xFFFF) < ((u16)__repair_phase_storage.value)) red = (int)D_801096A0;
        if ((green & 0xFFFF) < ((u16)__repair_phase_storage.value)) green = D_801096A0;
        if ((blue & 0xFFFF) < ((u16)__repair_phase_storage.value)) blue = D_801096A0;
        if ((red & 0xFFFF) >= 0x100) red = 0xFF;
        if ((green & 0xFFFF) >= 0x100) green = 0xFF;
        if ((blue & 0xFFFF) >= 0x100) blue = 0xFF;
        *outR = red; *outG = green; *outB = blue;
        if (nearestSegs[0] != NULL) return nearestSegs[0];
    }
    return NULL;
}
