extern u8 gWorkerActive; extern u8 D_80107EE8[];
void func_8008F2A4(s32 a,s8 b){if(gWorkerActive) D_80107EE8[(a&255)*40]=b;}
void stopWorkerThread(); void func_80095274();
void func_800959D0(void){if(gWorkerActive){stopWorkerThread();func_80095274();gWorkerActive=0;}}
extern int D_800CE570; extern signed char D_800E1A90; extern int D_80102CB8;
void func_80083E44(int arg0) { if (D_800E1A90 == 0) { int old = D_80102CB8; int *p = &D_800CE570; int v = *p; D_80102CB8 = arg0; *p = v - (arg0 - old); } }
extern s8 D_800CEEB0; void func_8002CE18(); void func_8000A2F4(); void func_8000A2B8(); void func_80030F88(); void func_800066A0();
void func_80087C9C(void){D_800CEEB0=0;func_8002CE18();func_8000A2F4();func_8000A2B8();func_80030F88(7);func_800066A0(4);}
