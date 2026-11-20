void func_80006604(void *arg0, s32 arg1) {
 s32 *p = (s32 *)(*(char **)((char *)arg0 + 0x68) + 0x14);
 unsigned int x = -(arg1 != 0);
 x = (x & 3) | 2;
 *p = (*p & ~12) | (x << 2);
}
