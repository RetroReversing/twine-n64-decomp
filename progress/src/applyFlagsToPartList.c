/* Walks a linked list of parts, ORs addFlags into each part's flags, and copies position into the part's data for types 1/0x4C and 2/3 unless a skipMask flag is set. */
void applyFlagsToPartList(void **listHead, s32 skipMask, s32 addFlags, void *position) {
    s32 flags;
    u16 partType;
    void *data;
    void *data2;
    void *part;

    if (listHead != NULL) {
        part = *listHead;
        if (part != NULL) {
            do {
                flags = (*(s32 *)((char *)(part) + 0x60)) | addFlags;
                (*(s32 *)((char *)(part) + 0x60)) = flags;
                partType = (*(u16 *)((char *)(part) + 0x78));
                if ((((partType == 1) | (partType == 0x4C)) != 0) && !(flags & skipMask)) {
                    data = (*(void **)((char *)(part) + 0x6C));
                    { struct V { s32 x,y,z; }; *(struct V *)((char *)data + 0x50) = *(struct V *)position; }
                }
                if (((u32) ((*(u16 *)((char *)(part) + 0x78)) - 2) < 2U) && !((*(s32 *)((char *)(part) + 0x60)) & skipMask)) {
                    data2 = (*(void **)((char *)(part) + 0x6C));
                    { struct V { s32 x,y,z; }; *(struct V *)((char *)data2 + 0x1A0) = *(struct V *)position; }
                }
                part = (*(void **)((char *)(part) + 0));
            } while (part != NULL);
        }
    }
}
