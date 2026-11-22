extern double D_800D3E40;

typedef struct { f32 x, y, z; } Vec3;

s32 func_8004D910(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2, Vec3 *arg3, Vec3 *arg4, f32 *arg5) {
    Vec3 e1;
    Vec3 e2;
    Vec3 t, p, q;
    f32 det, u, v;
    f32 e1x, e1y, e1z;
    f32 ex, ey, ez;
    f32 dx, dy, dz;
    e1x = arg3->x - arg2->x;
    e1.x = e1x;
    e1y = arg3->y - arg2->y;
    e1.y = e1y;
    e1z = arg3->z - arg2->z;
    e1.z = e1z;
    ex = arg4->x - arg2->x;
    e2.x = ex;
    ey = arg4->y - arg2->y;
    dz = ((const volatile Vec3 *)arg1)->z;
    e2.y = ey;
    ez = arg4->z - arg2->z;
    dy = arg1->y;
    dx = arg1->x;
    p.x = dy * ez - dz * ey;
    p.y = dz * ex - dx * ez;
    p.z = dx * ey - dy * ex;
    e2.z = ez;
    det = e1x * p.x + e1y * p.y + e1z * p.z;
    if (det < 1e-10f) return 0;
    t.x = arg0->x - arg2->x;
    t.y = arg0->y - arg2->y;
    t.z = arg0->z - arg2->z;
    u = t.x * p.x + t.y * p.y + t.z * p.z;
    if (u < 0.0 || u > det) return 0;
    q.x = t.y * e1z - t.z * e1y;
    q.y = t.z * e1x - t.x * e1z;
    q.z = t.x * e1y - t.y * e1x;
    v = dx * q.x + dy * q.y + dz * q.z;
    if (v < 0.0 || det < u + v) return 0;
    *arg5 = (ex * q.x + ey * q.y + ez * q.z) * (f32)(D_800D3E40 / det);
    return 1;
}
