void func_800A97A0(f32 *out, u32 *in) {
    u32 *end = in + 8;
    do {
        u32 a = in[0];
        u32 b = in[8];
        s32 x = (s32)(a & 0xFFFF0000) | (s32)(b >> 16);
        s32 y = (s32)(a << 16) | (s32)(b & 0xFFFF);
        out[0] = (f32)y * 0.0000152587890625f;
        out[1] = (f32)x * 0.0000152587890625f;
        in++;
        out += 2;
    } while (in != end);
}
