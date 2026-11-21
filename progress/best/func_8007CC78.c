extern unsigned short D_8010A91A;
void func_8007CC78(void *arg0) {
char *__repair_addr;
 unsigned char *p = arg0; unsigned char *s = *(void **)(p + 0x6c); void *q = *(void **)(p + 0x20); *(unsigned int *)(p + 0x58) &= ~1; if (q && !Probe_BoundsContainPoint(p + 0x24, q)) func_80016A34(arg0);
__repair_addr = (char *)(arg0 + 0x7a);
 if (*(short *)(__repair_addr) != 0 && *(short *)(p + 0x7a) != 9) { if (s[0x82] != 40 && !(s[0x82] == 30 && *(int *)(s + 0x40) && (*(int *)(s + 0x88) & 0x40000000))) { if (!(*(int *)(arg0 + 0x58) & 4) && !(*(int *)(arg0 + 0x60) & 0x7006)) { *(int *)(p + 0x60) &= 1; func_8007947C(p); return; } if (*(int *)(s + 0x88) & 0x40000000) D_8010A91A++; } } }
