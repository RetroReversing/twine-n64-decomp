#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern char D_800EE420[];
extern char D_800F2720[];

u16 func_80096460(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a2;
    s32 var_v0_3;
    u32 temp_a2_2;
    u32 temp_t0;
    u8 *var_v0;
    u8 *var_v0_2;
    u8 *var_v0b;
    u32 var_t;
    u32 var_v1;
    void *temp_v1;
    void *temp_v1_2;
    void *var_v1_2;
    void *var_a2;
    void *var_a3;
    void *var_b2;
    void *tmp_a2;
    void *tmp_a3;
    void *tmp_b2;
    u8 cmd;
    u32 tb;

    cmd = arg0;
    temp_a2 = arg2 & 0xFF;
    if (temp_a2 != 0xFF) {
        temp_t0 = cmd & 0xFF;
        if (temp_t0 < 0x40U) {
            { u8 *bp = D_800EE420; u8 *bank; do { bank = bp + temp_a2 * 0x860; } while (0); temp_v1 = (u8 *)((arg1 & 0xFF) * 0x86) + (s32)bank + (arg0 & 0x1F); }
            var_v1 = M2C_FIELD(temp_v1, u8 *, 0x20);
            var_v0_3 = M2C_FIELD(temp_v1, u8 *, 0) << 7;
            goto block_19;
        }
        if ((u32) ((arg0 + 0x80) & 0xFF) < 2U) {
            { u8 *bp = D_800EE420; u8 *bank; do { bank = bp + temp_a2 * 0x860; } while (0); var_v1_2 = (u8 *)((arg1 & 0xFF) * 0x86) + (s32)bank; }
            do { temp_v1 = var_v1_2 + (arg0 & 0xFE); } while (0);
            var_v0_3 = M2C_FIELD(temp_v1, u8 *, 0);
            var_v1 = M2C_FIELD(temp_v1, u8 *, 1);
            var_v0_3 = var_v0_3 << 7;
            goto block_19;
        }
        if ((u32) ((arg0 + 0x7C) & 0xFF) < 2U) {
            { u8 *bp = D_800EE420; u8 *bank; do { bank = bp + temp_a2 * 0x860; } while (0); var_v1_2 = (u8 *)((arg1 & 0xFF) * 0x86) + (s32)bank; }
            do { temp_v1 = var_v1_2 + (arg0 & 0xFE); } while (0);
            var_v0_3 = M2C_FIELD(temp_v1, u8 *, 0);
            var_v1 = M2C_FIELD(temp_v1, u8 *, 1);
            var_v0_3 = var_v0_3 << 7;
            goto block_19;
        }
        if (temp_t0 < 0x46U) {
            { u8 *bp = D_800EE420; u8 *bank = bp + temp_a2 * 0x860; var_v0_2 = (u8 *)((arg1 & 0xFF) * 0x86) + (s32)bank + temp_t0; }
            goto block_22;
        }
        if ((u32) ((arg0 - 0x60) & 0xFF) < 6U) {
            return 0;
        }
            { u8 *bp = D_800EE420; u8 *bank = bp + temp_a2 * 0x860; var_v0 = (u8 *)((arg1 & 0xFF) * 0x86) + (s32)bank + temp_t0; }
        return *var_v0 << 7;
    }
    temp_a2 = cmd & 0xFF;
    if (temp_a2 < 0x40U) {
        { u8 *bp = D_800F2720; u32 bb; u8 *sm; bb = (arg1 & 0xFF); sm = bp + bb * 0x86; do { temp_v1_2 = sm + (arg0 & 0x1F); } while (0); }
        var_v0_3 = M2C_FIELD(temp_v1_2, u8 *, 0) << 7;
        var_v1 = M2C_FIELD(temp_v1_2, u8 *, 0x20);
        goto block_19;
    }
    if (((u32) ((arg0 + 0x80) & 0xFF) < 2U) || (((u32) ((arg0 + 0x7C) & 0xFF) < 2U) != 0)) {
        { u32 bb; u8 *bp; do { bb = (arg1 & 0xFF); } while (0); bp = D_800F2720; var_b2 = bp + bb * 0x86; }
block_18:
        do { tmp_b2 = var_b2 + (arg0 & 0xFE); } while (0);
        var_v0_3 = M2C_FIELD(tmp_b2, u8 *, 0);
        var_v1 = M2C_FIELD(tmp_b2, u8 *, 1);
        var_v0_3 = var_v0_3 << 7;
block_19:
        return var_v1 | var_v0_3;
    }
    if (temp_a2 < 0x46U) {
        { u8 *bp = D_800F2720; u32 bb; do { bb = (arg1 & 0xFF); } while (0); var_v0_2 = bp + bb * 0x86 + temp_a2; }
block_22:
        return -((u8) *var_v0_2 >= 0x40U) & 0x3FFF;
    }
    if ((u32) ((arg0 - 0x60) & 0xFF) < 6U) {
        return 0;
    }
        { u32 bb; u8 *bp; bb = (arg1 & 0xFF); bp = D_800F2720; var_v0b = bp + bb * 0x86 + temp_a2; }
    return *var_v0b << 7;
}
