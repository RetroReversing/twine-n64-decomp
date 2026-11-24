extern unsigned char gWorkerThreadActive;
/* Returns bit 0 of the entry's halfword at offset 8, or 0 if the worker thread is inactive. */ int isWorkerEntryFlagSet(void *entry) {
    if (gWorkerThreadActive != 0) {
        return (*(unsigned short *)((char *)entry + 8)) & 1;
    }
    return 0;
}
