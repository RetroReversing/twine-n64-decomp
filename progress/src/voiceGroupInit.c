#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

s32 func_800269B4(void *, s32, s32);    /* extern */
void *buildMenuItemRecord(void *, s32);       /* extern */
extern s32 D_800BD660;
extern s32 D_800BF5A0;
extern s32 gMenuSoundParams;
extern void *gMenuState;

/* Sets up a voice group: stores its id and size, primes each sub-entry's
 * channel with a clamped priority, and resets the group's shared state. */
s32 voiceGroupInit(void *group, s32 id, u8 count, s8 flags) {
    s32 temp_v1;
    s32 var_a0;
    s32 var_s2;
    void *temp_a0;
    void *temp_a1;
    void *temp_s0;
    void *temp_v0;

    if ((group == NULL) || (M2C_FIELD(group, s32 *, 0) = id, M2C_FIELD(group, u8 *, 0xE) = count, M2C_FIELD(group, s8 *, 0xC) = 0, M2C_FIELD(group, s8 *, 0xF) = 0, M2C_FIELD(group, s8 *, 0xD) = flags, M2C_FIELD(group, void **, 8) = NULL, (M2C_FIELD(group, s32 *, 0) == 0))) {
        return 0;
    }
    var_s2 = 0;
    M2C_FIELD(group, s32 *, 4) = id;
    if (M2C_FIELD(group, u8 *, 0xE) != 0) {
        do {
            temp_s0 = M2C_FIELD(group, s32 *, 0) + ((var_s2 & 0xFFFF) * 0x28);
            temp_v0 = buildMenuItemRecord(temp_s0, gMenuSoundParams);
            M2C_FIELD(temp_s0, void **, 8) = temp_v0;
            if (temp_v0 != NULL) {
                void *p = temp_v0;
                temp_v1 = (((u32) M2C_FIELD(p, u32 *, 0x28) >> 2) & 0x3F) - 3;
                if (temp_v1 >= 0) {
                    var_a0 = 7;
                    if (temp_v1 < 8) {
                        var_a0 = temp_v1;
                    }
                } else {
                    var_a0 = 0;
                }
                M2C_FIELD(p, u32 *, 0x28) = (u32) ((M2C_FIELD(p, u32 *, 0x28) & ~0xFC) | ((var_a0 & 0x3F) * 4));
            }
            var_s2 += 1;
        } while ((u32) (var_s2 & 0xFFFF) < (u8) M2C_FIELD(group, u8 *, 0xE));
    }
    func_800269B4(group + 8, 3, 0x2A);
    temp_a1 = M2C_FIELD(group, void **, 8);
    if (temp_a1 != NULL) {
        M2C_FIELD(temp_a1, s32 *, 0x10) = (s32) ((D_800BD660 & ~0xFF) | M2C_FIELD(gMenuState, u8 *, 0x30));
        temp_a0 = M2C_FIELD(group, void **, 8);
        M2C_FIELD(temp_a0, s32 *, 0x28) = (s32) (M2C_FIELD(temp_a0, s32 *, 0x28) & ~0xFC);
    }
    D_800BF5A0 = 0;
    return 1;
}
