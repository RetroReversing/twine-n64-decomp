typedef u8 ControlRow[134];
extern ControlRow D_800EE420[][16];
extern ControlRow D_800F2720[];

void func_80095B08(u8 arg0, u8 arg1, u8 arg2, u16 arg3) {
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_t0_2;
    s32 var_t0;
    s8 temp_a3;
    s8 var_a3;
    u32 temp_t0;
    u32 temp_v0;
    u32 upper;
    u32 index;
    u32 groupBase;
    u32 rowOffset;
    u32 var_v0;

    temp_t0 = arg0 & 0xFF;
    if (temp_t0 < 0x40U) {
        index = arg0 & 0x1F;
        upper = (u16)arg3 >> 7;
        temp_a0 = arg2 & 0xFF;
        if (temp_a0 != 0xFF) {
            groupBase = (u32)D_800EE420[temp_a0];
            rowOffset = (arg1 & 0xFF) * 134;
            var_v0 = groupBase + rowOffset;
        } else {
            rowOffset = (arg1 & 0xFF) * 134;
            var_v0 = rowOffset + (u32)D_800F2720;
        }
        *(u8 *)(index + var_v0) = upper & 0x7F;
        temp_t0_2 = (arg0 & 0x1F) | 0x20;
        temp_a2 = arg2 & 0xFF;
        temp_a3 = arg3 & 0x7F;
        if (temp_a2 != 0xFF) {
            *(u8 *)(temp_t0_2 + (u32)D_800EE420[temp_a2][arg1 & 0xFF]) = temp_a3;
            return;
        }
        *(u8 *)(temp_t0_2 + (u32)D_800F2720[arg1 & 0xFF]) = temp_a3;
        return;
    }
    if (arg0 == 0x80 || arg0 == 0x81) {
        index = arg0 & 0xFE;
        upper = (u16)arg3 >> 7;
        temp_a0 = arg2 & 0xFF;
        if (temp_a0 != 0xFF) {
            groupBase = (u32)D_800EE420[temp_a0];
            rowOffset = (arg1 & 0xFF) * 134;
            var_v0 = groupBase + rowOffset;
        } else {
            rowOffset = (arg1 & 0xFF) * 134;
            var_v0 = rowOffset + (u32)D_800F2720;
        }
        *(u8 *)(index + var_v0) = upper & 0x7F;
        var_t0 = arg0 | 1;
        temp_a2 = arg2 & 0xFF;
        var_a3 = arg3 & 0x7F;
        if (temp_a2 != 0xFF) {
            groupBase = (u32)D_800EE420[temp_a2];
            rowOffset = (arg1 & 0xFF) * 134;
            var_v0 = groupBase + rowOffset;
        } else {
            goto block_19;
        }
        goto block_20;
    }
    temp_v0 = arg3 & 0xFFFF;
    if (arg0 == 0x84 || arg0 == 0x85) {
        temp_a0 = arg2 & 0xFF;
        if (temp_a0 != 0xFF) {
            groupBase = (u32)D_800EE420[temp_a0];
            rowOffset = (arg1 & 0xFF) * 134;
            var_v0 = groupBase + rowOffset;
        } else {
            rowOffset = (arg1 & 0xFF) * 134;
            var_v0 = rowOffset + (u32)D_800F2720;
        }
        *(u8 *)((arg0 & 0xFE) + var_v0) = (temp_v0 >> 7) & 0x7F;
        var_t0 = arg0 | 1;
        temp_a2 = arg2 & 0xFF;
        var_a3 = arg3 & 0x7F;
        if (temp_a2 != 0xFF) {
            groupBase = (u32)D_800EE420[temp_a2];
            rowOffset = (arg1 & 0xFF) * 134;
            var_v0 = groupBase + rowOffset;
        } else {
block_19:
            rowOffset = (arg1 & 0xFF) * 134;
            var_v0 = rowOffset + (u32)D_800F2720;
        }
block_20:
        *(u8 *)(var_v0 + (var_t0 & 0xFF)) = var_a3;
        return;
    }
    temp_a2 = arg2 & 0xFF;
    if (temp_a2 != 0xFF) {
        groupBase = (u32)D_800EE420[temp_a2];
        rowOffset = (arg1 & 0xFF) * 134;
        var_v0 = groupBase + rowOffset;
    } else {
        rowOffset = (arg1 & 0xFF) * 134;
        var_v0 = rowOffset + (u32)D_800F2720;
    }
    *(u8 *)(var_v0 + temp_t0) = (temp_v0 >> 7) & 0x7F;
}
