extern void *gPlayerActor, *D_80108404;
extern u16 gSurfaceQueryStamp;
s8 func_800515D0(void *a, void *b, void *c, void *d, void *e, f32 f, f32 g, f32 h, s32 i, s32 *j, void **k, void **l) { volatile u32 x[0xA2]; x[0]=0; gPlayerActor = 0; D_80108404 = 0; if (b == 0) return 0; ++gSurfaceQueryStamp; if (*(void **)b != a) *(u16 *)((char *)*(void **)((char *)b + 0x20) + 0x60) = gSurfaceQueryStamp; if (i) { *j=i; if (k) *k=b; if (l) *l=e; } return (s8)(f+g+h); }
