extern int sBonusObjectTable;
extern int playTrackMarkerCue();
void playBonusMarkerCueIfFlagged(void *p) { if (*(int *)((char *)p+0x60) & 0x1000) playTrackMarkerCue(p,sBonusObjectTable,0); }
extern float gSinCosTable[];
float cosTableLookup(float x) { return gSinCosTable[(int)(x * 651.8986f) & 0xfff]; }
float sinTableLookup(float x) { return gSinCosTable[((int)(x * 651.8986f)-0x400) & 0xfff]; }
extern unsigned char gWorkerThreadActive;
extern void workerShutdownDrain(void), workerShutdownNoop(void);
/* If the worker thread is active, drain it, run shutdown hook, and mark it inactive. */ void shutdownWorkerThread(void) { if (gWorkerThreadActive) { workerShutdownDrain(); workerShutdownNoop(); gWorkerThreadActive=0; } }
