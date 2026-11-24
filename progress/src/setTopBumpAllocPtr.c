extern u8 gWorkerThreadActive; extern u8 D_80107EE8[];
void setSoundEntityStatus(s32 a,s8 b){if(gWorkerThreadActive) D_80107EE8[(a&255)*40]=b;}
void stopWorkerThread(); void workerShutdownNoop();
void shutdownWorkerIfActive(void){if(gWorkerThreadActive){stopWorkerThread();workerShutdownNoop();gWorkerThreadActive=0;}}
extern int gBumpAllocRemaining; extern signed char gHeapActive; extern int gTopBumpAllocPtr;
/* Moves the top bump-allocation pointer to newPtr and adjusts the remaining-space counter by the same amount, when the heap is not active. */ void setTopBumpAllocPtr(int newPtr) { if (gHeapActive == 0) { int oldPtr = gTopBumpAllocPtr; int *remainingPtr = &gBumpAllocRemaining; int remaining = *remainingPtr; gTopBumpAllocPtr = newPtr; *remainingPtr = remaining - (newPtr - oldPtr); } }
extern s8 gDemoRecordingActive; void initSetupTables(); void releaseSoundRequestQueue(); void releaseMusicStream(); void commitEntryAndCloseSaveMenu(); void setTransitionStateIfAllowed();
void resetDemoAndCommitEntry(void){gDemoRecordingActive=0;initSetupTables();releaseSoundRequestQueue();releaseMusicStream();commitEntryAndCloseSaveMenu(7);setTransitionStateIfAllowed(4);}
