extern void *__osRunningThread; s32 osGetThreadPri(void *arg0) { void *var_a0=arg0; if (var_a0==0) var_a0=__osRunningThread; return *(s32*)((char*)var_a0+4); }
