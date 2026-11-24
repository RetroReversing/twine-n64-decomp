extern s16 gAnimationRemapGroups[];
extern s8 gAnimationRemapPairs[];

/* Looks up (groupKey, animId) in the remap tables; on a hit replaces animId with its mapped id, and sets groupKey to -1 if that id is negative. */ void lookupAnimationRemap(s32 *groupKey, s32 *animId) {
    s32 key = *groupKey;
    s32 id = *animId;
    s8 *pair = gAnimationRemapPairs;
    u32 offset = 0;
    s32 minusOne = -1;
    s16 *groups = gAnimationRemapGroups;
    s16 *countPtr = groups + 1;
    s16 *keyPtr = groups;

    for (; offset < 0x26; countPtr += 2, offset += 2, keyPtr += 2) {
        s32 remaining = *countPtr;
        s32 groupId = *keyPtr;
        while (remaining-- != 0) {
            if (key == groupId && id == pair[0]) {
                s32 newId = pair[1];
                *animId = newId;
                if (newId < 0) {
                    *groupKey = minusOne;
                }
                return;
            }
            pair += 2;
        }
    }
}
