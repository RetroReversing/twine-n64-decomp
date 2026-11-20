f32 func_80014BD8(f32 *, s32);
f32 func_800828D0(f32);
s32 func_80083A6C(void *, f32 *);
extern f32 D_8010A2D0;
typedef struct { u8 pad[0x20]; s32 planes; } B14C10;
typedef struct { u8 pad0[0x10]; f32 pos[3]; u8 pad1c[0x30]; f32 r; u8 pad50[0x18]; f32 f68, f6C; u8 pad70[0x18]; u8 m[0x18]; f32 a0, a4, a8; u8 padAC[8]; f32 b4; } C14C10;

s32 IsSphereVisible(f32 *arg0, f32 arg1, B14C10 *arg2, C14C10 *arg3) {
    f32 v[3];
    f32 d[3];
    f32 r = arg1 * arg3->r;
    f32 nr;

    v[0] = arg0[0] - arg3->pos[0];
    v[1] = arg0[1] - arg3->pos[1];
    v[2] = arg0[2] - arg3->pos[2];
    func_80083A6C(arg3->m, v);
    if (D_8010A2D0 < v[2] - r) {
        return 0;
    }
    if (v[2] + r < 0.2f) {
        return 0;
    }
    nr = -r;
    if (func_80014BD8(v, arg2->planes + 0x10) < nr) {
        return 0;
    }
    if (r < func_80014BD8(v, arg2->planes + 0x20)) {
        return 0;
    }
    if (r < func_80014BD8(v, arg2->planes + 0x30)) {
        return 0;
    }
    if (func_80014BD8(v, arg2->planes + 0x40) < nr) {
        return 0;
    }
    if (r > 0.5f) {
        d[2] = arg3->a0 * arg0[0] + arg3->a4 * arg0[1] + arg3->a8 * arg0[2];
        d[2] = d[2] + arg3->b4;
        if (func_800828D0((arg3->f68 / d[2] * r + arg3->f6C / d[2] * r) * 0.5f) < 2.0f) {
            return 0;
        }
    }
    return 1;
}
