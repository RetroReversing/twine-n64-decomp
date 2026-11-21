extern void func_800957A8(u32 *);
extern u8 D_80107EE8;
extern s32 D_80107EEC;
extern s32 D_80107EF0;
extern s32 D_80107EF4;
extern s32 D_80107EF8;

void func_8008EF6C(u8 arg0, u16 arg1, u8 arg2) {
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

    var_s1 = arg1;
    if (!(var_s1 & 0xFFFF)) {
        var_s1 = arg1 + 1;
    }
    temp_s0 = var_s1 & 0xFFFF;
    sp10 = temp_s0;
    func_800957A8(&sp10);
    temp_a2 = arg2 & 0xFF;
    switch (temp_a2) {
    case 0xFF: {
        s32 value, divisor, previous, current;
        u32 tick;
        var_a2 = 0;
        value = (arg0 & 0xFF) << 0x10;
        tick = sp10;
        divisor = (u16)var_s1;
        var_a1 = &D_80107EF0;
        var_a0 = 0;
        do {
            if ((u8) *(&D_80107EE8 + var_a0) < 2U) {
                *var_a1 = value;
                *((s32 *)((u8 *)&D_80107EF8 + var_a0)) = tick;
                current = *var_a1;
                previous = *((s32 *)((u8 *)&D_80107EEC + var_a0));
                *((s32 *)((u8 *)&D_80107EF4 + var_a0)) = (current - previous) / divisor;
            }
            var_a1 += 0xA;
            var_a2 += 1;
            var_a0 += 0x28;
        } while (var_a2 < 0x20U);
        return;
    }
    case 0xFC: {
        s32 value, divisor, previous, current;
        u32 tick;
        var_a2_2 = 0;
        value = (arg0 & 0xFF) << 0x10;
        tick = sp10;
        divisor = (u16)var_s1;
        var_a1_2 = &D_80107EF0;
        var_a0_2 = 0;
        do {
            if ((u32) (*(&D_80107EE8 + var_a0_2) - 2) < 2U) {
                *var_a1_2 = value;
                *((s32 *)((u8 *)&D_80107EF8 + var_a0_2)) = tick;
                current = *var_a1_2;
                previous = *((s32 *)((u8 *)&D_80107EEC + var_a0_2));
                *((s32 *)((u8 *)&D_80107EF4 + var_a0_2)) = (current - previous) / divisor;
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
        s32 value, divisor, previous, current;
        u32 tick;
        var_a2_3 = 0;
        selected = (u8)var_v0;
        value = (arg0 & 0xFF) << 0x10;
        tick = sp10;
        divisor = (u16)var_s1;
        var_a1_3 = &D_80107EF0;
        var_a0_3 = 0;
        do {
            if (*(&D_80107EE8 + var_a0_3) == selected) {
                *var_a1_3 = value;
                *((s32 *)((u8 *)&D_80107EF8 + var_a0_3)) = tick;
                current = *var_a1_3;
                previous = *((s32 *)((u8 *)&D_80107EEC + var_a0_3));
                *((s32 *)((u8 *)&D_80107EF4 + var_a0_3)) = (current - previous) / divisor;
            }
            var_a1_3 += 0xA;
            var_a2_3 += 1;
            var_a0_3 += 0x28;
        } while (var_a2_3 < 0x20U);
        return;
    }
    default: {
        s32 previous, current, quotient;
        temp_v1 = temp_a2 * 0x28;
        *((volatile s32 *)((u8 *)&D_80107EF0 + temp_v1)) = (arg0 & 0xFF) << 0x10;
        current = *((volatile s32 *)((u8 *)&D_80107EF0 + temp_v1));
        previous = *((s32 *)((u8 *)&D_80107EEC + temp_v1));
        quotient = (current - previous) / temp_s0;
        *((s32 *)((u8 *)&D_80107EF8 + temp_v1)) = sp10;
        *((s32 *)((u8 *)&D_80107EF4 + temp_v1)) = quotient;
        return;
    }
    }
}
