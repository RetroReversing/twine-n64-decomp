typedef struct { s32 x, y, z; } Words3;
typedef struct { f32 x, y, z; } Vec3f;
typedef union { f32 f[3]; u32 w[3]; } VecScratch;
s32 func_8004FF30(s32, f32 *, void *, f32, s32, s32, s32, s32);

void func_8006F50C(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    volatile Vec3f current;
    u8 buffer[0x10];
    VecScratch delta;
    f32 vector[3];
    f32 original[3];
    f32 *position = (f32 *)((u8 *)arg1 + 0x24);
    Words3 *src = (Words3 *)position;
    Words3 *dst = (Words3 *)&current;

    *dst = *src;
    current.y += 1.0f;
    delta.w[0] = 0;
    delta.w[1] = 0;
    delta.w[2] = 0;
    original[0] = position[0];
    vector[0] = original[0];
    original[1] = position[1];
    vector[1] = original[1];
    original[2] = position[2];
    vector[2] = original[2];
    if ((func_8004FF30(arg0, vector, buffer, 0.75f, 16, arg2, arg3, 0) << 24) != 0) {
        delta.f[2] += vector[2] - original[2];
        delta.f[1] += vector[1] - original[1];
        delta.f[0] += vector[0] - original[0];
    }
    position[0] += delta.f[0];
    position[1] += delta.f[1];
    position[2] += delta.f[2];
}
