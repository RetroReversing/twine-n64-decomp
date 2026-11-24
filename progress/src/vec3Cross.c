/* Computes the cross product out = a x b of two 3-float vectors. */
void vec3Cross(f32 *out, f32 *a, f32 *b) {
    out[0] = (f32) ((a[1] * b[2]) - (a[2] * b[1]));
    out[1] = (f32) ((a[2] * b[0]) - (a[0] * b[2]));
    out[2] = (f32) ((a[0] * b[1]) - (a[1] * b[0]));
}
