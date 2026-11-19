/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800957A8();
extern char D_80107ED4[];
extern s32 D_80107ED8;
extern char D_80107EDC[];
extern char D_80107EE0[];
extern char D_80107EE4[];
extern u8 D_80107EE8[];
extern char D_80107EE9[];

void func_8008EB80(u8 arg0, s32 arg1, u8 arg2, s8 arg3, s32 arg4) {
    char *var_a1;
    register s32 sp10;
    
    
    s32 temp_a2;
    s32 temp_s0;
    unsigned temp_v1;
    s32 var_a0;
    s32 var_a0_2;
    register unsigned int var_a0_3;
    unsigned var_s1;
    s32 var_v0;
    long var_a2;
    unsigned long var_a2_2;
    unsigned int var_a2_3;

    var_s1 = arg1;
    if (!(var_s1 & 0xFFFF)) {
        var_s1 = arg1 + 1;
    }
    temp_s0 = var_s1 & 0xFFFF;
    sp10 = temp_s0;
    func_800957A8(&sp10);
    temp_a2 = arg2 & 0xFF;
    switch (temp_a2) {
    case 0xFF:
        var_a2 = 0;
        var_a0 = 0;
        var_a1 = &D_80107ED8;
        do {
            if ((u8) *(D_80107EE8 + var_a0) < 2U) {
                *(s32 *)var_a1 = (arg0 & 0xFF) << 0x10;
                *(s32 *)(D_80107EE0 + var_a0) = sp10;
                *(s32 *)(D_80107EDC + var_a0) = (s32) (*(s32 *)var_a1 - *(s32 *)(D_80107ED4 + var_a0)) / (s32) (var_s1 & 0xFFFF);
                *(s32 *)(D_80107EE4 + var_a0) = -1;
            }
            var_a1 += 0x28;/*__repair_loop_weight*/do {do {do {
            var_a2 += 1;} while (0);} while (0);} while (0);
            var_a0 += (short)0x28;
        } while (0x20U > var_a2);
        return;
    case 0xFC:
        var_a2_2 = 0;
        var_a1 = &D_80107ED8;
        var_a0_2 = 0;
        do {
            if ((u32) (*((D_80107EE8-16) + var_a0_2) - 2) < 2U) {
                *(s32 *)var_a1 = (arg0 & 0xFF) << 0x10;
                *(s32 *)(D_80107EE0 + var_a0_2) = sp10;
                *(s32 *)(D_80107EDC + var_a0_2) = (s32) (*(s32 *)var_a1 - *(s32 *)(D_80107ED4 + var_a0_2)) / (s32) (var_s1 & 0xFFFF);
                *(s32 *)(D_80107EE4 + var_a0_2) = -1;
            }
            var_a1 += 0x28;
            var_a0_2 += 0x28;
            ++var_a2_2;
        } while (0x20U > var_a2_2);
        return;
    case 0xFA:
        var_v0 = 2;
block_18:
        var_a2_3 = 0;
        var_a1 = &D_80107ED8;
        var_a0_3 = 0;
        do {
            if (*(D_80107EE8 + var_a0_3) == (var_v0 & 0xFF)) {
                *(s32 *)(D_80107EE0 + var_a0_3) = sp10;
                *(s32 *)var_a1 = (arg0 & 0xFF) << 0x10;
                *(s32 *)(D_80107EE4 + var_a0_3) = -1;
                *(s32 *)(D_80107EDC + var_a0_3) = (s32) (*(s32 *)var_a1 - *(s32 *)(D_80107ED4 + var_a0_3)) / (s32) (var_s1 & (unsigned short)0xFFFF);
            }
            var_a1 += 0x28;
            var_a0_3 += 0x28;
            ++var_a2_3;
        } while (var_a2_3 < 0x20U);
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
        *(s32 *)(D_80107ED8 + temp_v1) = (arg0 & 0xFF) << 0x10;
        *(s32 *)(D_80107EDC + temp_v1) = (s32) (*(s32 *)(D_80107ED8 + temp_v1) - *(s32 *)(D_80107ED4 + temp_v1)) / temp_s0;
        *(D_80107EE9 + temp_v1) = arg3;
        *(s32 *)(D_80107EE4 + temp_v1) = arg4;
        *(s32 *)(D_80107EE0 + temp_v1) = sp10;
        return;
    }
}
