f32 __cosf(f32);
f32 sinApprox(f32);

void func_800347B0(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 zero = 0.0f;
    f32 sx, cx, sy, cy, sz, cz, a, b, t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;

    sx = sinApprox(arg1);
    cx = __cosf(arg1);
    sy = sinApprox(arg2);
    cy = __cosf(arg2);
    sz = sinApprox(arg3);
    cz = __cosf(arg3);
    (*(f32 *)((char *)(arg0) + 0x2C)) = zero;
    (*(f32 *)((char *)(arg0) + 0x1C)) = zero;
    (*(f32 *)((char *)(arg0) + 0xC)) = zero;
    (*(f32 *)((char *)(arg0) + 8)) = -sy;
    (*(f32 *)((char *)(arg0) + 0x30)) = arg4;
    (*(f32 *)((char *)(arg0) + 0x34)) = arg5;
    (*(f32 *)((char *)(arg0) + 0x38)) = arg6;
    (*(f32 *)((char *)(arg0) + 0x3C)) = 1.0f;
    a = sx * sy;
    b = cx * sy;
    (*(f32 *)((char *)(arg0) + 0)) = (cy * cz);
    (*(f32 *)((char *)(arg0) + 4)) = (cy * sz);
    t0 = cx * sz;
    (*(f32 *)((char *)(arg0) + 0x10)) = (a * cz) - t0;
    (*(f32 *)((char *)(arg0) + 0x14)) = (a * sz) + (cz * cx);
    (*(f32 *)((char *)(arg0) + 0x18)) = sx * cy;
    (*(f32 *)((char *)(arg0) + 0x20)) = (b * cz) + (sx * sz);
    (*(f32 *)((char *)(arg0) + 0x24)) = (b * sz) - (cz * sx);
    (*(f32 *)((char *)(arg0) + 0x28)) = cx * cy;
}
