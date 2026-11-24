/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 getCurveTable();

/* Computes the voice's new 16.16 level from the event (scaled base plus offset, clamped to 0x7F0000), optionally remapped through a 128-entry curve table with interpolation. */ s32 updateVoiceLevelEnvelope(void *voice, void *event) {
    u16 curveId;
    u32 curve;
    unsigned long level;
    void *temp_v0_2;
    u32 temp_v1;
    register u8 temp_v0_3;
    u32 index;

    if ((*(u8 *)((char *)(event) + 6)) == 0) {
        (*(u32 *)((char *)(voice) + 0x30)) = (u32) ((u32) ((*(u32 *)((char *)(voice) + 0x30)) * (*(u8 *)((char *)(event) + 2))) >> 7);
    } else {
        (*(u32 *)((char *)(voice) + 0x30)) = (u32) ((u32) ((*(u32 *)((char *)(voice) + 0x34)) * (*(u8 *)((char *)(event) + 2))) >> 7);
    }
    temp_v1 = (*(u32 *)((char *)(voice) + 0x30)) + ((*(u8 *)((char *)(event) + 1)) << 0x10);
    (*(u32 *)((char *)(voice) + 0x30)) = temp_v1;
    if (temp_v1 > 0x7F0000U) {
        (*(u32 *)((char *)(voice) + 0x30)) = 0x7F0000U;
    }
    level = (*(u32 *)((char *)(voice) + 0x30));
    curveId = (*(u8 *)event);
    curveId |= (*(u8 *)((char *)event + 7)) << 8;
    if (curveId != 0) {
        curve = getCurveTable(curveId);
        index = level >> 16;
        if (curve != 0) {
            u32 frac = (u16)level;
            if (index < 127U) {
                u8 *samples = (u8 *)(index * 1 + (int)curve);
                u32 next = samples[1];
                u32 current = samples[0];
                level = (current << 16) + ((next - current) * frac);
            } else {
                level = ((u8 *)curve)[index] << 16;
            }
        }
    }
    (*(u32 *)((char *)(voice) + 0x30)) = level;
    return 0;
}

