f32 __cosf(f32);
f32 sinApprox(f32);

/* Builds a 4x4 float matrix from X/Y/Z Euler rotations and a translation. */ void buildRotationTranslationMatrix(void *mat, f32 rotX, f32 rotY, f32 rotZ, f32 posX, f32 posY, f32 posZ) {
    f32 zero = 0.0f;
    f32 sx, cx, sy, cy, sz, cz, a, b, t0, t1, t2, t3, t4, t5, t6, t7, t8, t9;

    sx = sinApprox(rotX);
    cx = __cosf(rotX);
    sy = sinApprox(rotY);
    cy = __cosf(rotY);
    sz = sinApprox(rotZ);
    cz = __cosf(rotZ);
    (*(f32 *)((char *)(mat) + 0x2C)) = zero;
    (*(f32 *)((char *)(mat) + 0x1C)) = zero;
    (*(f32 *)((char *)(mat) + 0xC)) = zero;
    (*(f32 *)((char *)(mat) + 8)) = -sy;
    (*(f32 *)((char *)(mat) + 0x30)) = posX;
    (*(f32 *)((char *)(mat) + 0x34)) = posY;
    (*(f32 *)((char *)(mat) + 0x38)) = posZ;
    (*(f32 *)((char *)(mat) + 0x3C)) = 1.0f;
    a = sx * sy;
    b = cx * sy;
    (*(f32 *)((char *)(mat) + 0)) = (cy * cz);
    (*(f32 *)((char *)(mat) + 4)) = (cy * sz);
    t0 = cx * sz;
    (*(f32 *)((char *)(mat) + 0x10)) = (a * cz) - t0;
    (*(f32 *)((char *)(mat) + 0x14)) = (a * sz) + (cz * cx);
    (*(f32 *)((char *)(mat) + 0x18)) = sx * cy;
    (*(f32 *)((char *)(mat) + 0x20)) = (b * cz) + (sx * sz);
    (*(f32 *)((char *)(mat) + 0x24)) = (b * sz) - (cz * sx);
    (*(f32 *)((char *)(mat) + 0x28)) = cx * cy;
}
