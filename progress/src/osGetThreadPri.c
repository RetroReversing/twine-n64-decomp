extern void *D_800CFE80; s32 osGetThreadPri(void *arg0) { void *var_a0=arg0; if (var_a0==0) var_a0=D_800CFE80; return *(s32*)((char*)var_a0+4); }
