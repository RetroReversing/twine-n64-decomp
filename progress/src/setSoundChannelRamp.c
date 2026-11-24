extern void shiftLeft8InPlace(u32 *);
extern u8 D_80107EE8, D_80107EE9;
extern s32 D_80107EE4;
extern s32 D_80107ED4;
extern s32 D_80107ED8;
extern s32 D_80107EDC;
extern s32 D_80107EE0;

/* Ramps sound channel entries (0x28 bytes each) toward targetLevel over duration (min 1).
   channel 0xFA-0xFF selects groups of channels; otherwise it is a single index. */
void setSoundChannelRamp(u8 targetLevel, u16 duration, u8 channel, u8 flag, s32 userData) {
    u32 sp10;
    s32 *var_a1;
    s32 *var_a1_2;
    s32 *var_a1_3;
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    u16 var_s1;
    s32 var_v0;
    u32 selected;
    u32 var_a2;
    u32 var_a2_2;
    u32 var_a2_3;

    var_s1 = duration;
    if (!(var_s1 & 0xFFFF)) {
        var_s1 = duration + 1;
    }
    temp_s0 = var_s1 & 0xFFFF;
    sp10 = temp_s0;
    shiftLeft8InPlace(&sp10);
    temp_a2 = channel & 0xFF;
    switch (temp_a2) {
    case 0xFF: {
        s32 value, divisor, previous, current, quotient, sentinel;
        u32 tick;
        var_a2 = 0;
        value = (targetLevel & 0xFF) << 0x10;
        tick = sp10;
        divisor = (u16)var_s1;
        sentinel = -1;
        var_a1 = &D_80107ED8;
        var_a0 = 0;
        do {
            if ((u8) *(&D_80107EE8 + var_a0) < 2U) {
                *var_a1 = value;
                *((s32 *)((u8 *)&D_80107EE0 + var_a0)) = tick;
                current = *var_a1;
                previous = *((s32 *)((u8 *)&D_80107ED4 + var_a0));
                quotient = (current - previous) / divisor;
                *((s32 *)((u8 *)&D_80107EE4 + var_a0)) = sentinel;
                *((s32 *)((u8 *)&D_80107EDC + var_a0)) = quotient;
            }
            var_a1 += 0xA;
            var_a2 += 1;
            var_a0 += 0x28;
        } while (var_a2 < 0x20U);
        return;
    }
    case 0xFC: {
        s32 value, divisor, previous, current, quotient, sentinel;
        u32 tick;
        var_a2_2 = 0;
        value = (targetLevel & 0xFF) << 0x10;
        tick = sp10;
        divisor = (u16)var_s1;
        sentinel = -1;
        var_a1_2 = &D_80107ED8;
        var_a0_2 = 0;
        do {
            if ((u32) (*(&D_80107EE8 + var_a0_2) - 2) < 2U) {
                *var_a1_2 = value;
                *((s32 *)((u8 *)&D_80107EE0 + var_a0_2)) = tick;
                current = *var_a1_2;
                previous = *((s32 *)((u8 *)&D_80107ED4 + var_a0_2));
                quotient = (current - previous) / divisor;
                *((s32 *)((u8 *)&D_80107EE4 + var_a0_2)) = sentinel;
                *((s32 *)((u8 *)&D_80107EDC + var_a0_2)) = quotient;
            }
            var_a1_2 += 0xA;
            var_a2_2 += 1;
            var_a0_2 += 0x28;
        } while (var_a2_2 < 0x20U);
        return;
    }
    case 0xFA:
        var_v0 = 2;
        goto block_18;
    case 0xFB:
        var_v0 = 3;
        goto block_18;
    case 0xFD:
        var_v0 = 0;
        goto block_18;
    case 0xFE:
        var_v0 = 1;
block_18: {
        s32 value, divisor, previous, current, quotient, sentinel;
        u32 tick;
        var_a2_3 = 0;
        selected = (u8)var_v0;
        value = (targetLevel & 0xFF) << 0x10;
        tick = sp10;
        divisor = (u16)var_s1;
        sentinel = -1;
        var_a1_3 = &D_80107ED8;
        var_a0_3 = 0;
        do {
            if (*(&D_80107EE8 + var_a0_3) == selected) {
                *var_a1_3 = value;
                *((s32 *)((u8 *)&D_80107EE0 + var_a0_3)) = tick;
                current = *var_a1_3;
                previous = *((s32 *)((u8 *)&D_80107ED4 + var_a0_3));
                quotient = (current - previous) / divisor;
                *((s32 *)((u8 *)&D_80107EE4 + var_a0_3)) = sentinel;
                *((s32 *)((u8 *)&D_80107EDC + var_a0_3)) = quotient;
            }
            var_a1_3 += 0xA;
            var_a2_3 += 1;
            var_a0_3 += 0x28;
        } while (var_a2_3 < 0x20U);
        return;
    }
    default: {
        s32 previous, current, quotient;
        u32 tick;
        temp_v1 = temp_a2 * 0x28;
        *((volatile s32 *)((u8 *)&D_80107ED8 + temp_v1)) = (targetLevel & 0xFF) << 0x10;
        current = *((volatile s32 *)((u8 *)&D_80107ED8 + temp_v1));
        previous = *((s32 *)((u8 *)&D_80107ED4 + temp_v1));
        quotient = (current - previous) / temp_s0;
        tick = sp10;
        *(&D_80107EE9 + temp_v1) = flag;
        *((s32 *)((u8 *)&D_80107EE4 + temp_v1)) = userData;
        *((s32 *)((u8 *)&D_80107EE0 + temp_v1)) = tick;
        *((s32 *)((u8 *)&D_80107EDC + temp_v1)) = quotient;
        return;
    }
    }
}
