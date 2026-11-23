typedef struct { s32 n; f32 x, dx, ddx, dddx, y, dy, ddy, dddy, z, dz, ddz, dddz; } CubicState;
void func_80047068(const f32 *p, const f32 *q, const f32 *r, const f32 *s, s32 n, CubicState *out)
{

    f32 h = 1.0f / (f32)n;
    f32 h2 = h * h;
    f32 h3 = h * h2;
    f32 a, b, c;
    a = (p[0] * -0.5f + q[0] * 1.5f - r[0] * 1.5f + s[0] * 0.5f) * h3;
    b = (p[0] - q[0] * 2.5f + r[0] * 2.0f - s[0] * 0.5f) * h2;
    c = (p[0] * -0.5f + r[0] * 0.5f) * h;
    out->dx = a + b + c;
    out->dddx = a * 6.0f;
    out->ddx = a * 6.0f + b * 2.0f;
    a = (p[1] * -0.5f + q[1] * 1.5f - r[1] * 1.5f + s[1] * 0.5f) * h3;
    b = (p[1] - q[1] * 2.5f + r[1] * 2.0f - s[1] * 0.5f) * h2;
    c = (p[1] * -0.5f + r[1] * 0.5f) * h;
    out->dy = a + b + c;
    out->dddy = a * 6.0f;
    out->ddy = a * 6.0f + b * 2.0f;
    a = (p[2] * -0.5f + q[2] * 1.5f - r[2] * 1.5f + s[2] * 0.5f) * h3;
    b = (p[2] - q[2] * 2.5f + r[2] * 2.0f - s[2] * 0.5f) * h2;
    c = (p[2] * -0.5f + r[2] * 0.5f) * h;
    out->dz = a + b + c;
    out->dddz = a * 6.0f;
    out->ddz = a * 6.0f + b * 2.0f;
    out->n = n;
    out->x = q[0];
    out->y = q[1];
    out->z = q[2];
}
