typedef struct {
    f32 x, y, z;
} NormalizeVector;

extern f32 func_80046054(f32, f32, f32);

f32 normalizeVector3(NormalizeVector *out, const NormalizeVector *in) {
    f32 magnitude = func_80046054(in->x, in->y, in->z);
    if (magnitude != 0.0f) {
        f32 scale = 1.0f / magnitude;
        f32 x = in->x * scale;
        f32 y = in->y * scale;
        f32 z = in->z * scale;
        out->x = x;
        out->y = y;
        out->z = z;
    } else {
        out->x = out->y = out->z = 0.0f;
    }
    return magnitude;
}
