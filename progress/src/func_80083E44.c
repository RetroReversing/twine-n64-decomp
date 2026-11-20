extern int D_800CE570; extern signed char D_800E1A90; extern int D_80102CB8;
void func_80083E44(int arg0) { if (D_800E1A90 == 0) { int old = D_80102CB8; int *p = &D_800CE570; int v = *p; D_80102CB8 = arg0; *p = v - (arg0 - old); } }
