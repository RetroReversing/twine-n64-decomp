extern u8 Probe_BoundsContainPoint(void *, void *); extern void func_80016A34(void *);
void func_8007CC78(void *arg0) { u8 *p = arg0; void *bounds = *(void **)(p+0x20); *(u32 *)(p+0x58) &= ~1; if (bounds && !Probe_BoundsContainPoint(p+0x24, bounds)) func_80016A34(p); }
