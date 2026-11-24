typedef struct { s32 n; f32 x, dx, ddx, dddx, y, dy, ddy, dddy, z, dz, ddz, dddz; } CubicState;
/* Sets up forward-differencing state to step a Catmull-Rom spline from p1 to p2 in the given number of steps. */
void initCatmullRomStepper(const f32 *p0, const f32 *p1, const f32 *p2, const f32 *p3, s32 steps, CubicState *state)
{

    f32 dt = 1.0f / (f32)steps;
    f32 dt2 = dt * dt;
    f32 dt3 = dt * dt2;
    f32 a, b, c;
    a = (p0[0] * -0.5f + p1[0] * 1.5f - p2[0] * 1.5f + p3[0] * 0.5f) * dt3;
    b = (p0[0] - p1[0] * 2.5f + p2[0] * 2.0f - p3[0] * 0.5f) * dt2;
    c = (p0[0] * -0.5f + p2[0] * 0.5f) * dt;
    state->dx = a + b + c;
    state->dddx = a * 6.0f;
    state->ddx = a * 6.0f + b * 2.0f;
    a = (p0[1] * -0.5f + p1[1] * 1.5f - p2[1] * 1.5f + p3[1] * 0.5f) * dt3;
    b = (p0[1] - p1[1] * 2.5f + p2[1] * 2.0f - p3[1] * 0.5f) * dt2;
    c = (p0[1] * -0.5f + p2[1] * 0.5f) * dt;
    state->dy = a + b + c;
    state->dddy = a * 6.0f;
    state->ddy = a * 6.0f + b * 2.0f;
    a = (p0[2] * -0.5f + p1[2] * 1.5f - p2[2] * 1.5f + p3[2] * 0.5f) * dt3;
    b = (p0[2] - p1[2] * 2.5f + p2[2] * 2.0f - p3[2] * 0.5f) * dt2;
    c = (p0[2] * -0.5f + p2[2] * 0.5f) * dt;
    state->dz = a + b + c;
    state->dddz = a * 6.0f;
    state->ddz = a * 6.0f + b * 2.0f;
    state->n = steps;
    state->x = p1[0];
    state->y = p1[1];
    state->z = p1[2];
}
