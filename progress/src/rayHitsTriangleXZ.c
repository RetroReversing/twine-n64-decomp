/* Ray vs. triangle test in the XZ plane: returns 1 and writes the hit distance to *outT when the ray from origin hits triangle (v0, v1, v2). */

extern f64 D_800D3E10;

typedef struct { f32 x, y, z; } Vec3f;

/* Ray vs. triangle test in the XZ plane: returns 1 and writes the hit distance to *outT when the ray from origin hits triangle (v0, v1, v2). */ s32 rayHitsTriangleXZ(void *origin, void *rayDir, void *v0, void *v1, void *v2, f32 *outT) {
    register Vec3f edge1;
    Vec3f edge2;
    register Vec3f toOrigin;
    register Vec3f pvec;
    register f32 u;
    f32 v;
    f32 s;
    f32 det;
    int a;
    register Vec3f qvec;
    register unsigned b;

    edge1.x = (*(f32 *)((char *)(v1) + 0)) - (*(f32 *)((char *)(v0) + 0));
    edge1.y = (*(f32 *)((char *)(v1) + 4)) - (*(f32 *)((char *)(v0) + 4));
    edge1.z = (*(f32 *)((char *)(v1) + 8)) - (*(f32 *)((char *)(v0) + 8));
    edge2.x = (*(f32 *)((char *)(v2) + 0)) - (*(f32 *)((char *)(v0) + 0));
    s = (*(f32 *)((char *)(rayDir) + 4));
    edge2.y = (*(f32 *)((char *)(v2) + 4)) - (*(f32 *)((char *)(v0) + 4));
    edge2.z = (*(f32 *)((char *)(v2) + 8)) - (*(f32 *)((char *)(v0) + 8));
    pvec.x = s * edge2.z;
    pvec.y = 0;
    pvec.z = -(s * edge2.x);
    det = (((edge1.x * pvec.x))) + (((edge1.z * pvec.z)));
    if (det < 1e-10f) {
        return 0;
    }
    toOrigin.x = (*(f32 *)((char *)(origin) + 0)) - (*(f32 *)((char *)(v0) + 0));
    toOrigin.y = (*(f32 *)((char *)(origin) + 4)) - (*(f32 *)((char *)(v0) + 4));
    toOrigin.z = (*(f32 *)((char *)(origin) + 8)) - (*(f32 *)((char *)(v0) + 8));
    u = (toOrigin.x * pvec.x) + (toOrigin.z * pvec.z);
    a = u < 0.0;
    b = det < u;
    if (a || b) {
        return 0;
    }
    qvec.x = (toOrigin.y * edge1.z) - (toOrigin.z * edge1.y);
    qvec.y = (toOrigin.z * edge1.x) - (toOrigin.x * edge1.z);
    qvec.z = (toOrigin.x * edge1.y) - (toOrigin.y * edge1.x);
    v = s * qvec.y;
    if (((s * qvec.y) < 0.0) || (det < (u + v))) {
        return 0;
    }
    *outT = ((edge2.x * qvec.x) + (edge2.y * qvec.y) + (edge2.z * qvec.z)) * (f32) (D_800D3E10 / det);
    return 1;
}
