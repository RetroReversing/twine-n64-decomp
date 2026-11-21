extern int D_8010A500;
extern int func_8007C72C();
void func_80081614(void *p) { if (*(int *)((char *)p+0x60) & 0x1000) func_8007C72C(p,D_8010A500,0); }
extern float D_800CA350[];
float func_80082968(float x) { return D_800CA350[(int)(x * 651.8986f) & 0xfff]; }
float func_8008292C(float x) { return D_800CA350[((int)(x * 651.8986f)-0x400) & 0xfff]; }
extern unsigned char gWorkerActive;
extern void workerShutdownDrain(void), func_80095274(void);
void func_80095A08(void) { if (gWorkerActive) { workerShutdownDrain(); func_80095274(); gWorkerActive=0; } }
