/* Scales a 2D float vector (x, y) in place by per-axis factors. */
void scaleVec2(f32 *vec, f32 scaleX, f32 scaleY) {
    vec[0] = vec[0] * scaleX;
    vec[1] = vec[1] * scaleY;
}
