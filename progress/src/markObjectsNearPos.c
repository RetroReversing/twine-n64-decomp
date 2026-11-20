typedef struct { s32 x, y, z; } V3i;
f32 approxDistance(void *, void *);

/* Walks the object lists in a chain of list heads, and for objects in the given type set within max_dist of pos, updates their flag word and copies pos into their sub-record. */
/* Walks the object lists in a chain of heads, and for objects of the given types within maxDist of pos, sets their flags and copies pos into their sub-record. */ void markObjectsNearPos(void **listHead, s32 clearMask, s32 setMask, V3i *pos, f32 maxDist, s32 skipFlag) {
    void **firstHead = listHead;
    void *obj;
    void *chainNode;
    void *subRecord;
    s32 flagsNow;

    if (listHead == NULL) {
        return;
    }
    chainNode = *(void **)((char *)*(void **)((char *)listHead + 0x20) + 0x58);
    do {
        for (obj = *listHead; obj != NULL; obj = *(void **)obj) {
            switch (*(u16 *)((char *)obj + 0x78)) {
            case 1:
            case 2:
            case 3:
            case 0xB:
            case 0x24:
            case 0x3B:
            case 0x4C:
                if (maxDist == 0.0f || approxDistance(pos, (char *)obj + 0x24) < maxDist) {
                    u16 objType = *(u16 *)((char *)obj + 0x78);
                    if ((objType == 1 || objType == 0x4C) && !(*(s32 *)((char *)obj + 0x60) & clearMask)) {
                        s32 newFlags = *(s32 *)((char *)obj + 0x60) | setMask;
                        s32 markedFlags;
                        subRecord = *(void **)((char *)obj + 0x6C);
                        *(s32 *)((char *)obj + 0x60) = newFlags;
                        if (listHead == firstHead) {
                            markedFlags = newFlags | 0x1000;
                        } else {
                            markedFlags = newFlags | 0x2000;
                        }
                        *(s32 *)((char *)obj + 0x60) = markedFlags;
                        *(V3i *)((char *)subRecord + 0x50) = *pos;
                    } else if ((u32)(*(u16 *)((char *)obj + 0x78) - 2) < 2U) {
                        flagsNow = *(s32 *)((char *)obj + 0x60);
                        if (!(flagsNow & clearMask)) {
                            void *subRecord2 = *(void **)((char *)obj + 0x6C);
                            *(s32 *)((char *)obj + 0x60) = flagsNow | setMask;
                            *(V3i *)((char *)subRecord2 + 0x1A0) = *pos;
                        }
                    } else if ((s8)skipFlag == 0) {
                        *(s32 *)((char *)obj + 0x60) |= setMask;
                    }
                }
                break;
            }
        }
        listHead = NULL;
        if (chainNode != NULL) {
            listHead = *(void ***)((char *)chainNode + 8);
            chainNode = *(void **)chainNode;
        }
    } while (listHead != NULL);
}
