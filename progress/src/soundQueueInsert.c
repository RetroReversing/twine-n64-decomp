/* Adds a sound slot to its group's priority-ordered queue (groups are keyed by slot id).
 * Returns 1 on success, 0 if the group table or node pool is full. */
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

extern s8 sSoundGroupKeys;
extern s8 sSoundGroupQueueHeads;
extern s8 sSoundGroupAuxList;
extern u8 sSoundGroupCount;
extern s8 sSoundQueueNodes;
extern s8 D_800EDE7C;
extern s8 D_800EDE80;
extern s8 D_800EDE84;
extern s8 D_800EDE88;
extern s8 D_800EDE8C;
extern s8 D_800EDE90;
extern u8 sSoundQueueCount;

s32 soundQueueInsert(void *slot, f32 priority, f32 param2, f32 param3, f32 param4, f32 param5) {
    M2C_UNK *queueLink;
    s32 groupOffset;
    s32 nodeOffset;
    s32 nodeOffsetB;
    s32 nodeOffsetC;
    s32 nodeOffsetD;
    s32 groupIndex;
    s32 keyOffset;

    s32 zeroValue;
    groupIndex = 0;
    zeroValue = 0;

    if ((s32) sSoundGroupCount > zeroValue) {
        s32 slotKey = M2C_FIELD(slot, s32 *, 0x38);
        s32 groupTotal = sSoundGroupCount;
        keyOffset = 0;
        for (;;) {
            if (slotKey != *((s32 *)(&sSoundGroupKeys + keyOffset))) {
                groupIndex += 1;
                keyOffset += 0xC;
                if (groupIndex < groupTotal) {
                    continue;
                }
            }
            break;
        }
    }
    if (groupIndex == sSoundGroupCount) {
        if (groupIndex != 0x20) {
            groupOffset = groupIndex * 0xC;
            *((M2C_UNK * *)(&sSoundGroupQueueHeads + groupOffset)) = 0;
            *((s32 *)(&sSoundGroupAuxList + groupOffset)) = 0;
            {
                s32 slotKey = M2C_FIELD(slot, s32 *, 0x38);
                sSoundGroupCount += 1;
                *((s32 *)(&sSoundGroupKeys + groupOffset)) = slotKey;
            }
            goto block_7;
        }
        goto block_8;
    }
block_7:
    if (sSoundQueueCount == 0x20) {
block_8:
        return 0;
    }
    nodeOffset = groupIndex * 0xC;
    queueLink = *((M2C_UNK * *)(&sSoundGroupQueueHeads + nodeOffset));
    if (queueLink != NULL) {
        if (*queueLink != NULL) {
loop_11:
            if (!(M2C_FIELD(queueLink, f32 *, 4) < priority)) {
                queueLink = M2C_FIELD(queueLink, M2C_UNK **, 0);
                if (*queueLink != NULL) {
                    goto loop_11;
                }
            }
        }
        nodeOffsetC = sSoundQueueCount * 0x1C;
        *((M2C_UNK * *)(&sSoundQueueNodes + nodeOffsetC)) = (M2C_UNK *)*queueLink;
        *queueLink = (s32)(&sSoundQueueNodes + nodeOffsetC);
    } else {
        nodeOffsetD = sSoundQueueCount * 0x1C;
        *((M2C_UNK * *)(&sSoundQueueNodes + nodeOffsetD)) = 0;
        *((M2C_UNK * *)(&sSoundGroupQueueHeads + nodeOffset)) = (M2C_UNK *)(&sSoundQueueNodes + nodeOffsetD);
    }
    nodeOffsetB = sSoundQueueCount * 0x1C;
    *((s32 *)(&D_800EDE90 + nodeOffsetB)) = (s32)slot;
    *((f32 *)(&D_800EDE8C + nodeOffsetB)) = param5;
    *((f32 *)(&D_800EDE80 + nodeOffsetB)) = param2;
    *((f32 *)(&D_800EDE84 + nodeOffsetB)) = param3;
    *((f32 *)(&D_800EDE88 + nodeOffsetB)) = param4;
    sSoundQueueCount += 1;
    *((f32 *)(&D_800EDE7C + nodeOffsetB)) = priority;
    return 1;
}
