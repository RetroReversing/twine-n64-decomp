extern int gBonusSceneHandle;
extern int playTrackMarkerCue();
void func_80081614(void *p) { if (*(int *)((char *)p+0x60) & 0x1000) playTrackMarkerCue(p,gBonusSceneHandle,0); }
extern float gSinCosTable[];
float cosTableLookup(float x) { return gSinCosTable[(int)(x * 651.8986f) & 0xfff]; }
float sinTableLookup(float x) { return gSinCosTable[((int)(x * 651.8986f)-0x400) & 0xfff]; }
extern unsigned char gWorkerActive;
extern void workerShutdownDrain(void), func_80095274(void);
void func_80095A08(void) { if (gWorkerActive) { workerShutdownDrain(); func_80095274(); gWorkerActive=0; } }
