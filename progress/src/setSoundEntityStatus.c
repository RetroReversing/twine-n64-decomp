extern u8 gWorkerThreadActive; extern u8 D_80107EE8[];
/* Stores a status byte in the first byte of a sound entity record (40-byte stride) when the sound worker is active. */ void setSoundEntityStatus(u8 entityIndex, s32 status){if(gWorkerThreadActive) D_80107EE8[(entityIndex&255)*40]=status;}
void stopWorkerThread(); void workerShutdownNoop();
void shutdownWorkerIfActive(void){if(gWorkerThreadActive){stopWorkerThread();workerShutdownNoop();gWorkerThreadActive=0;}}
extern int gBumpAllocRemaining; extern signed char gHeapActive; extern int gTopBumpAllocPtr;
void setTopBumpAllocPtr(int arg0) { if (gHeapActive == 0) { int old = gTopBumpAllocPtr; int *p = &gBumpAllocRemaining; int v = *p; gTopBumpAllocPtr = arg0; *p = v - (arg0 - old); } }
extern s8 gDemoRecordingActive; void initSetupTables(); void releaseSoundRequestQueue(); void releaseMusicStream(); void commitEntryAndCloseSaveMenu(); void setTransitionStateIfAllowed();
void resetDemoAndCommitEntry(void){gDemoRecordingActive=0;initSetupTables();releaseSoundRequestQueue();releaseMusicStream();commitEntryAndCloseSaveMenu(7);setTransitionStateIfAllowed(4);}
