extern f32 sqrt(f32);
f32 func_8009532C(f32 *v) {
    f32 x = v[0];
    f32 y = v[1];
    f32 z = v[2];
    f32 length = sqrt(x*x + y*y + z*z);
    v[0] = (v[0]) / length;
    v[1] = v[1] / length;
    v[2] = v[2] / length;
    return length;
}

