struct triple { s32 x, y, z; };
s32 boundsContainPoint(void *, void *);
s32 sphereContainsPoint(void *, void *, f32);
s32 castRayAgainstObjectsAndRooms(void *, void *, void *, s32 *, void *, f32, s32, s32, s32);
extern s32 gVecUp[];
extern s32 gVecDown[];
extern u8 rayTriangleIntersect[];

/* For each object of type 0x18, find the nearest type-0x46 object below or above it
   whose height is not lower, and link it into that object's child list. */
void Obj_AttachToFloorObjects(void *objList) {
    s32 upDir[3];
    s32 downDir[3];
    struct { void *obj; f32 y; f32 z; f32 w; } hit;
    void *obj, *cand, *floorObj, *bestFloor, *fallbackFloor;
    void *objPos;
    f32 bestDist, fallbackDist, dist;

    fallbackFloor = NULL;
    obj = objList;
    while (obj != (int)NULL) {
        bestFloor = NULL;
        if (*(u16 *)((u8 *)obj + 0x58) == 0x18) {
            fallbackDist = 65536.0f;
            cand = objList;
            bestDist = 65536.0f;
            if (cand != NULL) {
                objPos = (u8 *)obj + 0x40;
            do {
                if (*(u16 *)((u8 *)cand + 0x58) == 0x46) {
                    if (*(f32 *)((u8 *)cand + 0x4C) >= *(f32 *)((u8 *)obj + 0x4C)
                        && ((sphereContainsPoint((u8 *)cand + 0x40, objPos, *(f32 *)((u8 *)obj + 0x4C)) << 0x18) != 0)
                        && ((boundsContainPoint(objPos, cand) << 0x18) != 0)
                        && *(f32 *)((u8 *)cand + 0x4C) >= *(f32 *)((u8 *)obj + 0x4C)) {
                        *(struct triple *)upDir = *(struct triple *)gVecUp;
                        *(struct triple *)downDir = *(struct triple *)gVecDown;
                        if (*(f32 *)((u8 *)cand + 0x4C) < fallbackDist) {
                            fallbackFloor = cand;
                            fallbackDist = *(f32 *)((u8 *)cand + 0x4C);
                        }
                        if ((castRayAgainstObjectsAndRooms(rayTriangleIntersect, cand, objPos, (u32)downDir, &hit.obj, 256.0f, 0, 1, 0) << 24) != 0) {
                            dist = *(f32 *)((u8 *)obj + 0x44) - hit.y;
                            if (dist < bestDist) {
                                bestDist = dist;
                                bestFloor = cand;
                            }
                        } else {
                            if ((castRayAgainstObjectsAndRooms((int)rayTriangleIntersect, cand, objPos, upDir, &hit.obj, 256.0f, 0, 1, 0) << 24) != 0) {
                                dist = hit.y - *(f32 *)((u8 *)obj + 0x44);
                                if (dist < bestDist) {
                                    bestDist = dist;
                                    bestFloor = cand;
                                }
                            }
                        }
                    }
                }
                cand = *(void **)((u8 *)cand + 0x10);
            } while (cand != NULL);
            }
            if (bestFloor != (unsigned)NULL) {
                if ((*(u32 *)((u8 *)obj + 0x58) >> 2) & 4) {
                    *(f32 *)(*(u8 **)((u8 *)bestFloor + 0x20) + 0x5C) = *(f32 *)((u8 *)obj + 0x28);
                }
                *(void **)((u8 *)obj + 0x18) = bestFloor;
                *(void **)((u8 *)obj + 0x14) = *(void **)((u8 *)bestFloor + 0x14);
                *(void **)((u8 *)bestFloor + 0x14) = obj;
            } else if (fallbackFloor != NULL) {
                if ((*(u32 *)((u8 *)obj + 0x58) >> 2) & 4) {
                    *(f32 *)(*(u8 **)((u8 *)fallbackFloor + 0x20) + 0x5C) = *(f32 *)((u8 *)obj + 0x28);
                }
                *(void **)((u8 *)obj + 0x18) = fallbackFloor;
                *(void **)((u8 *)obj + 0x14) = *(void **)((u8 *)fallbackFloor + 0x14);
                *(void **)((u8 *)fallbackFloor + 0x14) = obj;
                fallbackFloor = NULL;
            }
        }
        obj = *(void **)((u8 *)obj + 0x10);
    }
}
