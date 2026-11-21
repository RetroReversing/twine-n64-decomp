extern double D_800D3E40;

typedef struct { f32 x, y, z; } Vec3;
typedef union { f32 f; u32 i; } FU;

s32 func_8004D910(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2, Vec3 *arg3, Vec3 *arg4, f32 *arg5) {
    Vec3 e1;
    u32 e2[3];
    Vec3 t, p, q;
    f32 det, u, v;
    FU ex, ey, ez, dx, dy;
    f32 dz;
    e1.x = arg3->x - arg2->x;
    e1.y = arg3->y - arg2->y;
    e1.z = arg3->z - arg2->z;
    ex.f = arg4->x - arg2->x;
    e2[0] = ex.i;
    ey.f = arg4->y - arg2->y;
    dz = arg1->z;
    e2[1] = ey.i;
    ez.f = arg4->z - arg2->z;
    dy = ((FU*)arg1)[1];
    dx = ((FU*)arg1)[0];
    p.x = dy.f * ez.f - dz * ey.f;
    p.y = dz * ex.f - dx.f * ez.f;
    p.z = dx.f * ey.f - dy.f * ex.f;
    e2[2] = ez.i;
    det = e1.x * p.x + e1.y * p.y + e1.z * p.z;
    if (det < 1e-10f) return 0;
    t.x = arg0->x - arg2->x;
    t.y = arg0->y - arg2->y;
    t.z = arg0->z - arg2->z;
    u = t.x * p.x + t.y * p.y + t.z * p.z;
    if (u < 0.0 || u > det) return 0;
    q.x = t.y * e1.z - t.z * e1.y;
    q.y = t.z * e1.x - t.x * e1.z;
    q.z = t.x * e1.y - t.y * e1.x;
    v = dx.f * q.x + dy.f * q.y + dz * q.z;
    if (v < 0.0 || det < u + v) return 0;
    *arg5 = (ex.f * q.x + ey.f * q.y + ez.f * q.z) * (D_800D3E40 / det);
    return 1;
}
