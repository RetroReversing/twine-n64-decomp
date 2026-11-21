extern int gBonusObjects;
extern int playTrackMarkerCue();
void func_80081614(void *p) { if (*(int *)((char *)p+0x60) & 0x1000) playTrackMarkerCue(p,gBonusObjects,0); }
extern float gSinCosTable[];
float cosTableLookup(float x) { return gSinCosTable[(int)(x * 651.8986f) & 0xfff]; }
float sinTableLookup(float x) { return gSinCosTable[((int)(x * 651.8986f)-0x400) & 0xfff]; }
extern unsigned char gWorkerThreadActive;
extern void workerShutdownDrain(void), func_80095274(void);
void func_80095A08(void) { if (gWorkerThreadActive) { workerShutdownDrain(); func_80095274(); gWorkerThreadActive=0; } }
