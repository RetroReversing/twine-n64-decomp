s32 func_8004FF30(s32, f32 *, void *, f32, s32, s32, s32, s32);
void func_8006F50C(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    f32 current[3];
    u8 buffer[0x10];
    f32 delta[3];
    f32 vector[3];
    f32 original[3];
    f32 *position = (f32 *)((u8 *)arg1 + 0x24);
    current[0] = position[0];
    current[1] = position[1];
    current[2] = position[2];
    current[1] += 1.0f;
    delta[0] = 0.0f;
    delta[1] = 0.0f;
    delta[2] = 0.0f;
    original[0] = position[0];
    vector[0] = original[0];
    original[1] = position[1];
    vector[1] = original[1];
    original[2] = position[2];
    vector[2] = original[2];
    if ((func_8004FF30(arg0, vector, buffer, 0.75f, 16, arg2, arg3, 0) << 24) != 0) {
        delta[2] += vector[2] - original[2];
        delta[1] += vector[1] - original[1];
        delta[0] += vector[0] - original[0];
    }
    position[0] += delta[0];
    position[1] += delta[1];
    position[2] += delta[2];
}
