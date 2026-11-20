void *func_80047B44(s32, void *, f32 *, s32);
s32 func_8004AD30(s32, f32 *, s32 *, f32, s32, s32, s32, s32);
f32 func_8008292C(f32);
f32 func_800829A0(f32);
f32 func_800829C8(f32);
f32 func_80082A70(f32, f32);
extern u8 D_8011508C;

struct Vec3 { f32 x; f32 y; f32 z; };

f32 func_8006F358(s32 arg0, void *arg1) {
    struct Vec3 v1;
    struct Vec3 v2;
    struct { s32 i; f32 f; } out;
    void *s3;
    s32 a0;
    void *p;
    f32 t;
    f32 res;
    s32 r;

    s3 = *(void **)((char *)arg1 + 0x6C);
    res = 0.0f;
    if (*((u8 *)((s8 *)&D_8011508C + (*(s8 *)((char *)s3 + 0x182)) * 0xA0)) != 0) {
        v1 = *(struct Vec3 *)((char *)arg1 + 0x24);
        v1.x = v1.x + func_800829A0(*(f32 *)((char *)arg1 + 0x40)) * 1.5f;
        v1.y += 0.5f;
        v1.z += func_800829C8(*(f32 *)((char *)arg1 + 0x40)) * 1.5f;
        a0 = arg0;
        p = func_80047B44(arg0, (char *)arg1 + 0x24, &v1.x, 0);
        if (p != NULL) {
            a0 = *(s32 *)((char *)p + 8);
        }
        r = func_8004AD30(a0, &v1.x, &out.i, 4.0f, 0, 0, 0, 0xE);
        if ((r << 24) != 0) {
            t = func_80082A70(out.f - *(f32 *)((char *)s3 + 0xE4), 1.5f);
            v2 = v1;
            v2.x += func_800829A0(*(f32 *)((char *)arg1 + 0x40));
            v2.y += func_8008292C(t);
            v2.z += func_800829C8(*(f32 *)((char *)arg1 + 0x40));
            res = t * 0.47746482f;
        }
    }
    return res;
}
