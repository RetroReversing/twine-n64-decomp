s32 func_8008C1B0(u8);
s32 func_80095638(void);
s32 func_800957A8(u32 *);
s32 func_800957B8(u32 *, void *);
s32 func_80099CA8(void *arg0, void *arg1) {
    u32 sp10;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_4;
    u16 temp_v0;
    u32 temp_a0;
    u32 var_v0_3;
    temp_v0 = *(u16 *)((s8 *)arg1 + 4);
    sp10 = (u32)temp_v0;
    if (temp_v0 != 0) {
        if (((u32)*(u32 *)arg1 >> 8) & 1) {
            temp_v1 = *(s32 *)((s8 *)arg0 + 0x24);
            if (!(temp_v1 & 8)) { var_v0 = temp_v1 | 4; goto block_5; }
            return 0;
        }
        var_v0 = *(s32 *)((s8 *)arg0 + 0x24) & ~4;
block_5:
        *(s32 *)((s8 *)arg0 + 0x24) = var_v0;
        if ((*(u8 *)arg1) & 1) {
            if ((*(s32 *)((s8 *)arg0 + 0x24) & 0x20) || (func_8008C1B0(*(u8 *)((s8 *)arg0 + 0x63)) & 0xFF)) {
                var_v0_2 = *(s32 *)((s8 *)arg0 + 0x24) | 0x100000; goto block_10;
            }
            goto block_22;
        }
        var_v0_2 = *(s32 *)((s8 *)arg0 + 0x24) & 0xFFEFFFFF;
block_10:
        *(s32 *)((s8 *)arg0 + 0x24) = var_v0_2;
        if (((u16)*(u32 *)arg1) & 1) sp10 = (u32)(func_80095638() & 0xFFFF) % sp10;
        var_v0_3 = -1U;
        if (sp10 != 0xFFFF) {
            temp_v0_2 = (((u32)*(u16 *)((s8 *)arg1 + 4)) >> 8) & 1;
            if (temp_v0_2 & 0xFF) { func_800957A8(&sp10); var_v0_4 = temp_v0_2 & 0xFF; }
            else { func_800957B8(&sp10, arg0); var_v0_4 = temp_v0_2 & 0xFF; }
            if (var_v0_4 != 0) { var_v0_3 = *(u32 *)((s8 *)arg0 + 0xA4) + sp10; goto block_20; }
            temp_a0 = *(u32 *)((s8 *)arg0 + 0xA0) + sp10;
            *(u32 *)((s8 *)arg0 + 0x9C) = temp_a0;
            if (*(u32 *)((s8 *)arg0 + 0xA4) >= temp_a0) { *(u32 *)((s8 *)arg0 + 0xA0) = temp_a0; *(u32 *)((s8 *)arg0 + 0x9C) = 0U; }
        } else {
block_20:
            *(u32 *)((s8 *)arg0 + 0x9C) = var_v0_3;
        }
        return *(u32 *)((s8 *)arg0 + 0x9C) != 0;
    }
block_22:
    return 0;
}
