/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800957A8();
extern char D_80107EE8[];
extern char D_80107EEC[];
extern s32 D_80107EF0;
extern char D_80107EF4[];
extern char D_80107EF8[];

void func_8008EF6C(s32 arg0, s32 arg1, s32 arg2) {
    unsigned sp10;
    char *var_a1;
    char *var_a1_2;
    char *var_a1_3;
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_v1;
    u32 var_a2_3;
    s32 var_a0_2;
    s32 var_a0_3;
    unsigned int var_s1;
    s32 var_v0;
    u32 var_a2;
    u32 var_a2_2;
    s32 var_a0;

    var_s1 = arg1;
    if (!(var_s1 & 0xFFFF)) {
        var_s1 = arg1 + 1;
    }
    temp_s0 = var_s1 & 0xFFFF;
    sp10 = temp_s0;
    func_800957A8(&sp10);
    temp_v1 = arg2 & 0xFF;
    switch (temp_v1) {
    case 0xFF:
        var_a2 = 0;
        var_a0 = 0;
        var_a1 = &D_80107EF0;
        do {
            if ((u8) *(D_80107EE8 + var_a0) < 2U) {
                *(s32 *)var_a1 = (arg0 & 0xFF) << 0x10;
                *(s32 *)(D_80107EF8 + var_a0) = sp10;
                *(D_80107EF4 + var_a0) = (s32) (*(s32 *)var_a1 - *(s32 *)(D_80107EEC + var_a0)) / (s32) (var_s1 & (short)0xFFFF);
            }
            var_a1 += 0x28;
            ++var_a2;
            var_a0 += 0x28;
        } while (var_a2 < 0x20U);
        return;
    case 0xFC:
        var_a2_2 = 0;
        var_a1_2 = &D_80107EF0;
        var_a0_2 = 0;
        do {
            if ((u32) (*(D_80107EE8 + var_a0_2) - 2) < 2U) {
                *(s32 *)var_a1_2 = (arg0 & 0xFF) << 0x10;
                *(s32 *)(D_80107EF8 + var_a0_2) = sp10;
                *(D_80107EF4 + var_a0_2) = (s32) (*(s32 *)var_a1_2 - *(s32 *)(D_80107EEC + var_a0_2)) / (s32) (var_s1 & 0xFFFF);
            }
            var_a1_2 += 0x28;
            var_a2_2 += 1;
            var_a0_2 += 0x28;
        } while (var_a2_2 < 0x20U);
        return;
    case 0xFA:
        var_v0 = 2;
block_18:
        var_a2_3 = 0;
        var_a1_3 = &D_80107EF0;
        var_a0_3 = 0;
        do {
            if (*(D_80107EE8 + var_a0_3) == (var_v0 & 0xFF)) {
                *(s32 *)var_a1_3 = (arg0 & 0xFF) << 0x10;
                *(s32 *)(D_80107EF8 + var_a0_3) = sp10;
                *(D_80107EF4 + var_a0_3) = (s32) (*(s32 *)var_a1_3 - *(s32 *)(D_80107EEC + var_a0_3)) / (s32) (var_s1 & 0xFFFF);
            }
            var_a1_3 += 0x28;
            ++var_a2_3;
            var_a0_3 += 0x28;
        } while (0x20U > var_a2_3);
        return;
    case 0xFB:
        var_v0 = 3;
        goto block_18;
    case 0xFD:
        var_v0 = 0;
        goto block_18;
    case 0xFE:
        var_v0 = 1;
        goto block_18;
    default:
        temp_v1 = (arg2 & 0xFF) * 0x28;
        *(s32 *)(D_80107EF0 + temp_v1) = (arg0 & 0xFF) << 0x10;
        *(D_80107EF4 + temp_v1) = (s32) (*(s32 *)(D_80107EF0 + temp_v1) - *(s32 *)(D_80107EEC + temp_v1)) / temp_s0;
        *(s32 *)(D_80107EF8 + temp_v1) = sp10;
        return;
    }
}
