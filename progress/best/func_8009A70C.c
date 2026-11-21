typedef struct { u8 pad[0x30]; volatile u32 level; u32 baseline; } LevelState;
extern u8 *func_8009846C(u16);
s32 func_8009A70C(LevelState *state, u8 *settings) {
    u32 sum, level, index;
    s32 base, scale, delta;
    s16 curve;
    u8 *samples;
    if (settings[6] == 0) {
        scale = settings[2];
        base = state->level;
    } else {
        scale = settings[2];
        base = state->baseline;
    }
    state->level = (u32)(base * scale) >> 7;
    sum = state->level + ((u32)settings[1] << 16);
    state->level = sum;
    if (sum > 0x7f0000) state->level = 0x7f0000;
    {
        u32 high = settings[7];
        u32 low = settings[0];
        level = state->level;
        curve = low | (high << 8);
    }
    curve &= 0xFFFF;
    if (curve == 0) {
        state->level = level;
        return 0;
    }
    state->level = level;
    {
        s32 frac;
        samples = func_8009846C(curve);
        index = level >> 16;
        if (samples != NULL) {
            frac = (u16)level;
            if (index < 127) {
                u8 *point = samples + index;
                s32 next = point[1];
                s32 current = point[0];
                delta = (next - current) * frac;
                level = (current << 16) + delta;
            } else {
                level = samples[index] << 16;
            }
        }
        state->level = level;
        return 0;
    }
    state->level = level;
    return 0;
}
