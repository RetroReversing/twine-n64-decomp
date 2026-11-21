extern u8 D_800EE420, D_800F2720;

void func_80095B08(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a2_3;
    s32 temp_a2_4;
    s32 temp_t0_2;
    s32 var_t0;
    s8 temp_a3;
    s8 var_a3;
    u32 temp_t0;
    u32 temp_v0, high, index;
    u8 *var_v0;
    u8 *var_v0_2;
    u8 *var_v0_3;
    u8 *var_v0_4;
    u8 *var_v0_5;

    temp_t0 = arg0 & 0xFF;
    if (temp_t0 < 0x40U) {
        index = arg0 & 0x1F;
        high = (u16)arg3 >> 7;
        temp_a0 = arg2 & 0xFF;
        if (temp_a0 != 0xFF) {
            u32 row = (u32)&D_800EE420 + temp_a0 * 0x860;
            var_v0 = (u8 *)(row + (arg1 & 0xFF) * 0x86);
        } else {
            var_v0 = ((arg1 & 0xFF) * 0x86) + &D_800F2720;
        }
        var_v0[index] = high & 0x7F;
        temp_t0_2 = (arg0 & 0x1F) | 0x20;
        temp_a2 = arg2 & 0xFF;
        temp_a3 = arg3 & 0x7F;
        if (temp_a2 != 0xFF) {
            *(temp_t0_2 + (((arg1 & 0xFF) * 0x86) + ((temp_a2 * 0x860) + &D_800EE420))) = temp_a3;
            return;
        }
        *(temp_t0_2 + (((arg1 & 0xFF) * 0x86) + &D_800F2720)) = temp_a3;
        return;
    }
    if ((u32) ((arg0 + 0x80) & 0xFF) < 2U) {
        temp_a0_2 = arg2 & 0xFF;
        if (temp_a0_2 != 0xFF) {
            u32 row = (u32)&D_800EE420 + temp_a0_2 * 0x860;
            var_v0_2 = (u8 *)(row + (arg1 & 0xFF) * 0x86);
        } else {
            var_v0_2 = ((arg1 & 0xFF) * 0x86) + &D_800F2720;
        }
        *((arg0 & 0xFE) + var_v0_2) = ((u32) (arg3 & 0xFFFF) >> 7) & 0x7F;
        var_t0 = arg0 | 1;
        temp_a2_2 = arg2 & 0xFF;
        var_a3 = arg3 & 0x7F;
        if (temp_a2_2 != 0xFF) {
            u32 row = (u32)&D_800EE420 + temp_a2_2 * 0x860;
            var_v0_3 = (u8 *)(row + (arg1 & 0xFF) * 0x86);
        } else {
            goto block_19;
        }
        goto block_20;
    }
    temp_v0 = arg3 & 0xFFFF;
    if ((u32) ((arg0 + 0x7C) & 0xFF) < 2U) {
        temp_a0_3 = arg2 & 0xFF;
        if (temp_a0_3 != 0xFF) {
            u32 row = (u32)&D_800EE420 + temp_a0_3 * 0x860;
            var_v0_4 = (u8 *)(row + (arg1 & 0xFF) * 0x86);
        } else {
            var_v0_4 = ((arg1 & 0xFF) * 0x86) + &D_800F2720;
        }
        *((arg0 & 0xFE) + var_v0_4) = (temp_v0 >> 7) & 0x7F;
        var_t0 = arg0 | 1;
        temp_a2_3 = arg2 & 0xFF;
        var_a3 = arg3 & 0x7F;
        if (temp_a2_3 != 0xFF) {
            u32 row = (u32)&D_800EE420 + temp_a2_3 * 0x860;
            var_v0_3 = (u8 *)(row + (arg1 & 0xFF) * 0x86);
        } else {
block_19:
            var_v0_3 = ((arg1 & 0xFF) * 0x86) + &D_800F2720;
        }
block_20:
        *(var_v0_3 + (var_t0 & 0xFF)) = var_a3;
        return;
    }
    temp_a2_4 = arg2 & 0xFF;
    if (temp_a2_4 != 0xFF) {
        u32 row = (u32)&D_800EE420 + temp_a2_4 * 0x860;
        var_v0_5 = (u8 *)(row + (arg1 & 0xFF) * 0x86);
    } else {
        var_v0_5 = ((arg1 & 0xFF) * 0x86) + &D_800F2720;
    }
    *(var_v0_5 + temp_t0) = (temp_v0 >> 7) & 0x7F;
}
