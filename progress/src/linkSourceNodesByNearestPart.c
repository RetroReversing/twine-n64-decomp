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

M2C_UNK func_800452AC(f32 *, void *, f32 *);        /* extern */
f32 approxDistance(f32 *, s32);                      /* extern */
M2C_UNK func_80082FE4(s16 *, M2C_UNK *);            /* extern */
M2C_UNK rotateVec3ByMat3(M2C_UNK *, f32 *);            /* extern */

/* For each node of kind 0xB whose part is of a matching kind, find the closest part in the
   first list's parts and record this node as the link target of the matching entries. */
void linkSourceNodesByNearestPart(void *targetList, void *nodeList) {
    f32 nodeCenter[3];
    u8 transform[0x30];
    s16 nodePos[3];
    f32 dist;
    f32 bestDist;
    s32 partId;
    u8 kind;
    void *parent;
    void *parentParts;
    void *part;
    void *bestPart;
    void *node;
    void *cursor;
    void *target;
    void *targetParts;
    void *targetEntry;

    node = nodeList;
    if (node != NULL) {
        do {
            if ((M2C_FIELD(node, u16 *, 0x78) == 0xB) && ((kind = M2C_FIELD(M2C_FIELD(node, void **, 0x6C), u8 *, 0x4A), (((kind == 4) | (kind == 0xA)) != 0)) || (kind == 0xC))) {
                parent = M2C_FIELD(node, void **, 0x20);
                bestDist = 65536.0f;
                bestPart = NULL;
                if (parent != NULL) {
                    parentParts = M2C_FIELD(parent, void **, 0x20);
                    part = NULL;
                    if (parentParts != NULL) {
                        part = M2C_FIELD(parentParts, void **, 0x58);
                    }
                    if (part != NULL) {
                        do {
                            if (!(M2C_FIELD(part, u16 *, 0x26) & 0x1000)) {
                                partId = M2C_FIELD(part, s32 *, 4);
                                nodePos[0] = (s16) (s32) M2C_FIELD(node, f32 *, 0x3C);
                                nodePos[1] = (s16) (s32) M2C_FIELD(node, f32 *, 0x40);
                                nodePos[2] = (s16) (s32) M2C_FIELD(node, f32 *, 0x44);
                                { func_80082FE4(nodePos, transform); }
                                targetEntry = M2C_FIELD(node, void **, 0x70);
                                nodeCenter[0] = (M2C_FIELD(targetEntry, f32 *, 0x18) + M2C_FIELD(targetEntry, f32 *, 0x1C)) * 0.5f;
                                targetEntry = M2C_FIELD(node, void **, 0x70);
                                nodeCenter[1] = (M2C_FIELD(targetEntry, f32 *, 0x20) + M2C_FIELD(targetEntry, f32 *, 0x24)) * 0.5f;
                                targetEntry = M2C_FIELD(node, void **, 0x70);
                                nodeCenter[2] = (M2C_FIELD(targetEntry, f32 *, 0x28) + M2C_FIELD(targetEntry, f32 *, 0x2C)) * 0.5f;
                                rotateVec3ByMat3(transform, nodeCenter);
                                func_800452AC(nodeCenter, node + 0x24, nodeCenter);
                                dist = approxDistance(nodeCenter, partId + 0x40);
                                if (dist < bestDist) {
                                    bestDist = dist;
                                    bestPart = part;
                                }
                            }
                            part = M2C_FIELD(part, void **, 0);
                        } while (part != NULL);
                    }
                }
                if (bestPart != NULL) {
                    cursor = targetList;
                    if (cursor != NULL) {
                        do {
                            targetParts = M2C_FIELD(cursor, void **, 0x20);
                            target = NULL;
                            if (targetParts != NULL) {
                                target = M2C_FIELD(targetParts, void **, 0x58);
                            }
                            if (target != NULL) {
                                do {
                                    if (M2C_FIELD(bestPart, s32 *, 4) == M2C_FIELD(target, s32 *, 4)) {
                                        M2C_FIELD(target, void **, 0x1C) = node;
                                    }
                                    target = M2C_FIELD(target, void **, 0);
                                } while (target != NULL);
                            }
                            cursor = M2C_FIELD(cursor, void **, 0x10);
                        } while (cursor != NULL);
                    }
                }
            }
            node = M2C_FIELD(node, void **, 0x10);
        } while (node != NULL);
    }
}
