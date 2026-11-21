extern int gBonusSceneHandle;
extern int func_8007C72C();
void func_80081614(void *p) { if (*(int *)((char *)p+0x60) & 0x1000) func_8007C72C(p,gBonusSceneHandle,0); }
extern float gCosTable[];
float func_80082968(float x) { return gCosTable[(int)(x * 651.8986f) & 0xfff]; }
float func_8008292C(float x) { return gCosTable[((int)(x * 651.8986f)-0x400) & 0xfff]; }
extern unsigned char gWorkerActive;
extern void workerShutdownDrain(void), func_80095274(void);
void func_80095A08(void) { if (gWorkerActive) { workerShutdownDrain(); func_80095274(); gWorkerActive=0; } }
