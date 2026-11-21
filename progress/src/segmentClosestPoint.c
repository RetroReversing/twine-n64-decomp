typedef struct { f32 x, y, z; } Vec3;

f32 func_800455CC(Vec3 *out, const Vec3 *a, const Vec3 *b, const Vec3 *p) {
    f32 dx = a->x - b->x;
    f32 dy = a->y - b->y;
    f32 dz = a->z - b->z;
    f32 len2 = dx * dx + dy * dy + dz * dz;
    f32 py = p->y;
    f32 pz = p->z;
    f32 px = p->x;
    f32 t;

    if (len2 == 0.0f) {
        out->x = a->x;
        out->y = a->y;
        out->z = a->z;
        return 0.0f;
    }
    t = (a->x * a->x + b->x * px - a->x * (b->x + px) + dy * (a->y - py) + dz * (a->z - pz)) / len2;
    if (t < 0.0f) {
        t = 0.0f;
        out->x = a->x;
        out->y = a->y;
        out->z = a->z;
    } else if (t > 1.0f) {
        t = 1.0f;
        out->x = b->x;
        out->y = b->y;
        out->z = b->z;
    } else {
        out->x = a->x + t * (b->x - a->x);
        out->y = a->y + t * (b->y - a->y);
        out->z = a->z + t * (b->z - a->z);
    }
    return t;
}
