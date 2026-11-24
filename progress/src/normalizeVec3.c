
/* Normalizes a 3D vector in place and returns its original length. */ f32 normalizeVec3(f32 *vec) {
    f32 x = vec[0];
    f32 y = vec[1];
    f32 z = vec[2];
    f32 length = sqrtf(x*x + y*y + z*z);
    vec[0] = x / length;
    vec[1] = vec[1] / length;
    vec[2] = vec[2] / length;
    return length;
}
