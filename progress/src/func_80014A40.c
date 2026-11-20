s32 func_800458C0(void *, s32 *, f32 *, f32 *);
typedef struct { s32 x, y, z; } Vec3i;
typedef struct {
    Vec3i vector;
    u32 padding;
    f32 a[3];
    f32 b[3];
    f32 c[3];
    f32 d[3];
} LocalFrame;
extern Vec3i D_800D2528;
void func_80014A40(void *arg0, void *arg1) {
    LocalFrame local;
    local.vector = D_800D2528;
    local.a[0] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 0)) / (*(f32 *)((char *)arg1 + 0x68));
    local.a[1] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 8)) / (*(f32 *)((char *)arg1 + 0x6C));
    local.a[2] = 1.0f;
    local.b[0] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 4)) / (*(f32 *)((char *)arg1 + 0x68));
    local.b[1] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 8)) / (*(f32 *)((char *)arg1 + 0x6C));
    local.b[2] = 1.0f;
    local.c[0] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 0)) / (*(f32 *)((char *)arg1 + 0x68));
    local.c[1] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 0xC)) / (*(f32 *)((char *)arg1 + 0x6C));
    local.c[2] = 1.0f;
    local.d[0] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 4)) / (*(f32 *)((char *)arg1 + 0x68));
    local.d[1] = (*(f32 *)((char *)((*(void **)((char *)arg0 + 0x20))) + 0xC)) / (*(f32 *)((char *)arg1 + 0x6C));
    local.d[2] = 1.0f;
    func_800458C0((*(void **)((char *)arg0 + 0x20)) + 0x10, (s32 *)&local.vector, local.a, local.b);
    func_800458C0((*(void **)((char *)arg0 + 0x20)) + 0x20, (s32 *)&local.vector, local.c, local.d);
    func_800458C0((*(void **)((char *)arg0 + 0x20)) + 0x30, (s32 *)&local.vector, local.a, local.c);
    func_800458C0((*(void **)((char *)arg0 + 0x20)) + 0x40, (s32 *)&local.vector, local.b, local.d);
}
