extern s32 gWorkerListHead;
extern s32 gActiveEmitterList;
/* Clears the active emitter list and worker list head. */ void resetAudioWorkerLists(void) {
    gActiveEmitterList = 0;
    gWorkerListHead = 0;
}
