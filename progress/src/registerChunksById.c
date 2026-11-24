s32 insertOrCountEntry();

static inline char *findChunk(void *file, u16 id) {
    char *chunk = (char *)file + *(s32 *)((char *)file + 8);

    while (*(s32 *)chunk != -1) {
        if (*(u16 *)(chunk + 4) == id) {
            return chunk;
        }
        chunk += *(s32 *)chunk;
    }
    return NULL;
}

/* For each id in the 0xFFFF-terminated list, finds its chunk in the file and registers the chunk payload. */
void registerChunksById(u16 *ids, void *chunkFile) {
    char *found;

    while (*ids != 0xFFFF) {
        found = findChunk(chunkFile, *ids);
        if (found != NULL) {
            insertOrCountEntry(*ids, found + 8);
        }
        ids++;
    }
}
