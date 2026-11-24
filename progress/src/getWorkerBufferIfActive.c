extern u8 gWorkerThreadActive;
extern s32 gWorkerBuffer;
/* Returns the address of gWorkerBuffer while the worker thread is active, otherwise 0. */ s32 getWorkerBufferIfActive(void) {
    if (gWorkerThreadActive != 0) return (s32)&gWorkerBuffer;
    return 0;
}
