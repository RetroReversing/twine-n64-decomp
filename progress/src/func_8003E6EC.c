#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 Probe_BoundsContainPoint(f32 *, void *);
s32 Sphere_OverlapsPoint(void *, void *, f32);
s32 Ray_CastObjects(M2C_UNK *, void *, f32 *, s32 *, M2C_UNK *, f32, s32, s32, s32);
M2C_UNK func_80082FE4(s16 *, M2C_UNK *);
M2C_UNK func_80083A6C(M2C_UNK *, f32 *);
extern M2C_UNK gVecUp;
extern M2C_UNK gVecDown;
extern M2C_UNK Ray_TriangleIntersect;

/* Searches the list at listHead for the nearest surface above or below obj, then links obj into that surface's chain. */ s32 func_8003E6EC(void *listHead, void *obj, u8 flagIfUnlinked) {
    s16 rot[3];
    M2C_UNK mtx[12];
    f32 pos[3];
    s32 upA[3];
    s32 upB[3];
    f32 hit[3];
    u8 flagCopy;
    s32 *normOut;
    f32 curDist;
    f32 bestAboveDist;
    f32 bestBelowDist;
    f32 var_fv0;
    f32 dist;
    void *bounds;
    void *bounds2;
    void *bounds3;
    void *oldHead;
    void *oldHead2;
    void *cur;
    void *bestAbove;
    void *bestBelow;

    bestAboveDist = 65536.0f;
    bestAbove = NULL;
    bounds = M2C_FIELD(obj, void **, 0x70);
    bestBelow = NULL;
    cur = listHead;
    flagCopy = flagIfUnlinked;
    bestBelowDist = 65536.0f;
    if (bounds != NULL) {
        pos[0] = (M2C_FIELD(bounds, f32 *, 0x18) + M2C_FIELD(bounds, f32 *, 0x1C)) * 0.5f;
        bounds2 = M2C_FIELD(obj, void **, 0x70);
        pos[1] = (M2C_FIELD(bounds2, f32 *, 0x20) + M2C_FIELD(bounds2, f32 *, 0x24)) * 0.5f;
        bounds3 = M2C_FIELD(obj, void **, 0x70);
        pos[2] = (M2C_FIELD(bounds3, f32 *, 0x28) + M2C_FIELD(bounds3, f32 *, 0x2C)) * 0.5f;
        rot[0] = (s16) (s32) M2C_FIELD(obj, f32 *, 0x3C);
        rot[1] = (s16) (s32) M2C_FIELD(obj, f32 *, 0x40);
        rot[2] = (s16) (s32) M2C_FIELD(obj, f32 *, 0x44);
        func_80082FE4(rot, mtx);
        func_80083A6C(mtx, pos);
        pos[0] += M2C_FIELD(obj, f32 *, 0x24);
        pos[1] += M2C_FIELD(obj, f32 *, 0x28);
        pos[2] += M2C_FIELD(obj, f32 *, 0x2C);
    } else {
        pos[0] = M2C_FIELD(obj, f32 *, 0x24);
        pos[1] = M2C_FIELD(obj, f32 *, 0x28);
        pos[2] = M2C_FIELD(obj, f32 *, 0x2C);
    }
    if (cur != NULL) {
        f32 *point = pos;
        normOut = upA;
        do {
            if ((M2C_FIELD(cur, u16 *, 0x58) == 0x46) && ((Sphere_OverlapsPoint(cur + 0x40, point, M2C_FIELD(obj, f32 *, 0x64)) << 0x18) != 0) && ((Probe_BoundsContainPoint(point, cur) << 0x18) != 0)) {
                __builtin_memcpy(upA, &gVecUp, 12);
                __builtin_memcpy(upB, &gVecDown, 12);
                curDist = M2C_FIELD(cur, f32 *, 0x4C);
                if (curDist < bestBelowDist) {
                    bestBelow = cur;
                    bestBelowDist = curDist;
                }
                if ((Ray_CastObjects(&Ray_TriangleIntersect, cur, point, normOut, &hit, 256.0f, 0, 1, 0) << 0x18) != 0) {
                    dist = hit[1] - pos[1];
                    if (dist < bestAboveDist) {
                        bestAbove = cur;
                        bestAboveDist = dist;
                    }
                } else {
                    if ((Ray_CastObjects(&Ray_TriangleIntersect, cur, point, upB, &hit, 256.0f, 0, 1, 0) << 0x18) != 0) {
                        dist = pos[1] - hit[1];
                        if (dist < bestAboveDist) {
                            bestAbove = cur;
                            bestAboveDist = dist;
                        }
                    }
                }
            }
            cur = M2C_FIELD(cur, void **, 0x10);
        } while (cur != NULL);
    }
    if (bestAbove != NULL) {
        oldHead = M2C_FIELD(bestAbove, void **, 0);
        if (oldHead != NULL) {
            M2C_FIELD(oldHead, void **, 4) = obj;
        }
        M2C_FIELD(obj, void **, 0) = M2C_FIELD(bestAbove, void **, 0);
        M2C_FIELD(obj, void **, 4) = bestAbove;
        M2C_FIELD(bestAbove, void **, 0) = obj;
        M2C_FIELD(bestAbove, s32 *, 4) = 0;
        M2C_FIELD(obj, void **, 0x20) = bestAbove;
        return 1;
    }
    if (bestBelow != NULL) {
        oldHead2 = M2C_FIELD(bestBelow, void **, 0);
        if (oldHead2 != NULL) {
            M2C_FIELD(oldHead2, void **, 4) = obj;
        }
        M2C_FIELD(obj, void **, 0) = M2C_FIELD(bestBelow, void **, 0);
        M2C_FIELD(obj, void **, 4) = bestBelow;
        M2C_FIELD(bestBelow, void **, 0) = obj;
        M2C_FIELD(bestBelow, s32 *, 4) = 0;
        M2C_FIELD(obj, void **, 0x20) = bestBelow;
        return 1;
    }
    if ((flagCopy << 0x18) != 0) {
        M2C_FIELD(obj, s32 *, 0x60) = (s32) (M2C_FIELD(obj, s32 *, 0x60) | 1);
    }
    return 0;
}
