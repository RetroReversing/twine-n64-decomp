typedef struct {
    f32 x, y, z, w;
} Quaternion46538;

/* Hamilton product of two quaternions (a * b), written to out. */
void quaternion_multiply(const Quaternion46538 *a, const Quaternion46538 *b, Quaternion46538 *out)
{
    f32 aw = a->w, bx = b->x, az = a->z, ax = a->x;
    f32 ay = a->y, bz = b->z, by = b->y, bw = b->w;
    f32 x = ((aw * bx + ax * bw) + ay * bz) - az * by;
    f32 y = ((aw * by + ay * bw) + az * bx) - ax * bz;
    f32 z = ((aw * bz + az * bw) + ax * by) - ay * bx;
    f32 w = ((aw * bw - ax * bx) - ay * by) - az * bz;

    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;
}
