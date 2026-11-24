extern double D_800D3E40;

typedef struct { f32 x, y, z; } Vec3;

/* Moller-Trumbore ray/triangle test; returns 1 and writes the hit distance to outDist if the ray hits. */ s32 rayTriangleIntersectDistance(Vec3 *origin, Vec3 *dir, Vec3 *v0, Vec3 *v1, Vec3 *v2, f32 *outDist) {
    Vec3 e1;
    Vec3 e2;
    Vec3 t, p, q;
    f32 det, u, v;
    f32 e1x, e1y, e1z;
    f32 ex, ey, ez;
    f32 dx, dy, dz;
    e1x = v1->x - v0->x;
    e1.x = e1x;
    e1y = v1->y - v0->y;
    e1.y = e1y;
    e1z = v1->z - v0->z;
    e1.z = e1z;
    ex = v2->x - v0->x;
    e2.x = ex;
    ey = v2->y - v0->y;
    dz = ((const volatile Vec3 *)dir)->z;
    e2.y = ey;
    ez = v2->z - v0->z;
    dy = dir->y;
    dx = dir->x;
    p.x = dy * ez - dz * ey;
    p.y = dz * ex - dx * ez;
    p.z = dx * ey - dy * ex;
    e2.z = ez;
    det = e1x * p.x + e1y * p.y + e1z * p.z;
    if (det < 1e-10f) return 0;
    t.x = origin->x - v0->x;
    t.y = origin->y - v0->y;
    t.z = origin->z - v0->z;
    u = t.x * p.x + t.y * p.y + t.z * p.z;
    if (u < 0.0 || u > det) return 0;
    q.x = t.y * e1z - t.z * e1y;
    q.y = t.z * e1x - t.x * e1z;
    q.z = t.x * e1y - t.y * e1x;
    v = dx * q.x + dy * q.y + dz * q.z;
    if (v < 0.0 || det < u + v) return 0;
    *outDist = (ex * q.x + ey * q.y + ez * q.z) * (f32)(D_800D3E40 / det);
    return 1;
}
