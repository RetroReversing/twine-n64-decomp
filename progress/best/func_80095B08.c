extern u8 D_800EE420[];
extern u8 D_800F2720[];

void func_80095B08(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *__base_D_800EE420;
    u8 *var_v0;
    u32 temp_t0;
    arg2 &= 0xFF;
    temp_t0 = arg0 & 0xFF;
    if (temp_t0 < 0x40U) {
        if (arg2 != 0xFF) {
            __base_D_800EE420 = D_800EE420;
            var_v0 = (void *)(__base_D_800EE420); var_v0 = (void *)((char *)var_v0 + (s32)(arg2 * 0x860 + (arg1 & 0xFF) * 0x86));
        } else {
            var_v0 = (void *)(D_800F2720); var_v0 = (void *)((char *)var_v0 + (s32)((arg1 & 0xFF) * 0x86));
        }
        var_v0[arg0 & 0x1F] = ((u32)(arg3 & 0xFFFF) >> 7) & 0x7F;
        if (arg2 != 0xFF) {
            var_v0 = (void *)(__base_D_800EE420); var_v0 = (void *)((char *)var_v0 + (s32)(arg2 * 0x860 + (arg1 & 0xFF) * 0x86));
        } else {
            var_v0 = (void *)(D_800F2720); var_v0 = (void *)((char *)var_v0 + (s32)((arg1 & 0xFF) * 0x86));
        }
        var_v0[(arg0 & 0x1F) | 0x20] = arg3 & 0x7F;
        return;
    }
    if ((u32)((arg0 + 0x80) & 0xFF) < 2U) {
        if (arg2 != 0xFF) {
            var_v0 = (arg2 * 0x860 + (arg1 & 0xFF) * 0x86) + (__base_D_800EE420);
        } else {
            var_v0 = (void *)(D_800F2720); var_v0 = (void *)((char *)var_v0 + (s32)((arg1 & 0xFF) * 0x86));
        }
        var_v0[arg0 & 0xFE] = ((u32)(arg3 & 0xFFFF) >> 7) & 0x7F;
        if (arg2 != 0xFF) {
            var_v0 = (void *)(__base_D_800EE420); var_v0 = (void *)((char *)var_v0 + (s32)(arg2 * 0x860 + (arg1 & 0xFF) * 0x86));
        } else {
            var_v0 = D_800F2720 + (arg1 & 0xFF) * 0x86;
        }
        var_v0[(arg0 | 1) & 0xFF] = arg3 & 0x7F;
        return;
    }
    if ((u32)((arg0 + 0x7C) & 0xFF) >= 2U) {
        if (arg2 != 0xFF) {
            var_v0 = __base_D_800EE420 + arg2 * 0x860 + (arg1 & 0xFF) * 0x86;
        } else {
            var_v0 = (void *)(D_800F2720); var_v0 = (void *)((char *)var_v0 + (s32)((arg1 & 0xFF) * 0x86));
        }
        var_v0[arg0 & 0xFF] = ((u32)(arg3 & 0xFFFF) >> 7) & 0x7F;
    } else {
        if (arg2 != 0xFF) {
            var_v0 = __base_D_800EE420 + arg2 * 0x860 + (arg1 & 0xFF) * 0x86;
        } else {
            var_v0 = D_800F2720 + (arg1 & 0xFF) * 0x86;
        }
        var_v0[arg0 & 0xFE] = ((u32)(arg3 & 0xFFFF) >> 7) & 0x7F;
        if (arg2 != 0xFF) {
            var_v0 = __base_D_800EE420 + arg2 * 0x860 + (arg1 & 0xFF) * 0x86;
        } else {
            var_v0 = D_800F2720 + (arg1 & 0xFF) * 0x86;
        }
        var_v0[(arg0 | 1) & 0xFF] = arg3 & 0x7F;
    }
}
