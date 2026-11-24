s32 insertOrRefSortedEntry();

static inline char *findChunk(void *chunkFile, u16 id) {
    char *c = (char *)chunkFile + *(s32 *)((char *)chunkFile + 4);

    while (*(s32 *)c != -1) {
        if (*(u16 *)(c + 4) == id) {
            return c;
        }
        c += *(s32 *)c;
    }
    return NULL;
}

/* For each id in a 0xFFFF-terminated list, finds the matching chunk in the file and registers its payload. */
void registerChunksFromIdList(u16 *idList, void *chunkFile) {
    char *chunk;

    while (*idList != 0xFFFF) {
        chunk = findChunk(chunkFile, *idList);
        if (chunk != NULL) {
            insertOrRefSortedEntry(*idList, chunk + 8);
        }
        idList++;
    }
}
