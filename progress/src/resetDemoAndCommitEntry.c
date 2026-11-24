extern u8 gWorkerThreadActive; extern u8 D_80107EE8[];
void setSoundEntityStatus(s32 a,s8 b){if(gWorkerThreadActive) D_80107EE8[(a&255)*40]=b;}
void stopWorkerThread(); void workerShutdownNoop();
void shutdownWorkerIfActive(void){if(gWorkerThreadActive){stopWorkerThread();workerShutdownNoop();gWorkerThreadActive=0;}}
extern int gBumpAllocRemaining; extern signed char gHeapActive; extern int gTopBumpAllocPtr;
void setTopBumpAllocPtr(int arg0) { if (gHeapActive == 0) { int old = gTopBumpAllocPtr; int *p = &gBumpAllocRemaining; int v = *p; gTopBumpAllocPtr = arg0; *p = v - (arg0 - old); } }
extern s8 gDemoRecordingActive; void initSetupTables(); void releaseSoundRequestQueue(); void releaseMusicStream(); void commitEntryAndCloseSaveMenu(); void setTransitionStateIfAllowed();
/* Stops demo recording, reinitialises setup tables, then commits the entry (mode 7) and calls setTransitionStateIfAllowed(4). */ void resetDemoAndCommitEntry(void){gDemoRecordingActive=0;initSetupTables();releaseSoundRequestQueue();releaseMusicStream();commitEntryAndCloseSaveMenu(7);setTransitionStateIfAllowed(4);}
