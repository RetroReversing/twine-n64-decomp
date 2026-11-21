f32 __cosf(f32);
f32 sinApprox(f32);

void eulerToQuat(const f32 *arg0, f32 *arg1) {
    f32 a = arg0[0] * 0.0007669904f;
    f32 b = arg0[1] * 0.0007669904f;
    f32 c = arg0[2] * 0.0007669904f;
    f32 ca = __cosf(a);
    f32 sa = sinApprox(a);
    f32 cb = __cosf(b);
    f32 sb = sinApprox(b);
    f32 cc = __cosf(c);
    f32 sc = sinApprox(c);
    f32 cacc = ca * cc;
    f32 casc = ca * sc;
    f32 sacc = sa * cc;
    f32 sasc = sa * sc;
    arg1[0] = cb * sacc - sb * casc;
    arg1[1] = cb * sasc + sb * cacc;
    arg1[2] = cb * casc - sb * sacc;
    arg1[3] = cb * cacc + sb * sasc;
}
