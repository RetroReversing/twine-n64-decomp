extern f32 D_800CA350[];
extern void (*D_8010017C)(void *, int);
f32 func_800829C8(f32 x) { return D_800CA350[(s32)x & 0xFFF]; }
s32 func_800923AC(u32 *p) { u32 x = *p; if (x == -1U) return 1; return (x >> 31) ^ 1; }
void func_800955F0(void *p) { D_8010017C(p, 0); }
f32 func_800829A0(f32 x) { return D_800CA350[((s32)x - 0x400) & 0xFFF]; }
