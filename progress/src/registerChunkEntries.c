s32 insertSortedKeyEntry();
static inline char *findChunk(void *chunkFile, u16 chunkId) {
    char *cursor = (char *)chunkFile + *(s32 *)((char *)chunkFile + 12);
    while (*(s32 *)cursor != -1) {
        if (*(u16 *)(cursor + 4) == chunkId) return cursor;
        cursor += *(s32 *)cursor;
    }
    return NULL;
}
/* For each id in the 0xFFFF-terminated list, finds its chunk in the file and registers its data in the sorted key table. */
void registerChunkEntries(u16 *idList, void *chunkFile) {
    char *chunk;
    while (*idList != 0xFFFF) {
        chunk = findChunk(chunkFile, *idList);
        if (chunk != NULL) insertSortedKeyEntry(*idList, chunk + 12, *(u16 *)(chunk + 10));
        idList++;
    }
}
