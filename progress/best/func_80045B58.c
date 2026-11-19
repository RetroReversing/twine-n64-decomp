s32 func_80045B58(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    f32 *v[3];
    u32 i;
    u32 prev;
    f32 *p;
    f32 *q;
    f32 e0, e1, e2;
    f32 c0, c1, c2;

    v[0] = arg1;
    v[1] = arg2;
    v[2] = arg3;
    i = 0;
    prev = 2;
    do {
        p = v[i];
        q = v[prev];
        e0 = p[0] - q[0];
        e1 = p[1] - q[1];
        e2 = p[2] - q[2];
        c0 = e1 * arg4[2] - e2 * arg4[1];
        c1 = e2 * arg4[0] - e0 * arg4[2];
        c2 = e0 * arg4[1] - e1 * arg4[0];
        if ((arg0[0] - p[0]) * c0 + (arg0[1] - p[1]) * c1 + (arg0[2] - p[2]) * c2 > 0.0f) {
            return 0;
        }
        prev = i;
        i++;
    } while (i < 3);
    return 1;
}
