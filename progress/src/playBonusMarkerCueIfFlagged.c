extern int sBonusObjectTable;
extern int playTrackMarkerCue();
/* Plays the track marker cue for obj when its flag 0x1000 (at offset 0x60) is set. */ void playBonusMarkerCueIfFlagged(void *obj) { if (*(int *)((char *)obj+0x60) & 0x1000) playTrackMarkerCue(obj,sBonusObjectTable,0); }
extern float gSinCosTable[];
float cosTableLookup(float x) { return gSinCosTable[(int)(x * 651.8986f) & 0xfff]; }
float sinTableLookup(float x) { return gSinCosTable[((int)(x * 651.8986f)-0x400) & 0xfff]; }
extern unsigned char gWorkerThreadActive;
extern void workerShutdownDrain(void), workerShutdownNoop(void);
void shutdownWorkerThread(void) { if (gWorkerThreadActive) { workerShutdownDrain(); workerShutdownNoop(); gWorkerThreadActive=0; } }
