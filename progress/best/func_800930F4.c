/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008C0D4();
s32 func_8008C11C();
s32 func_8008F520();
extern u8 D_800CF540;
extern s16 D_800EDAA0;
extern char D_800EDAA4[];

s32 func_800930F4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
int __repair_literal;

    int temp_a3;
    u32 var_v1;
    s32 var_a2;
    s32 temp_s0;
    register char *var_s0;
    unsigned short var_a0;
    register void *temp_a1;
    void *temp_s1;
    void *temp_s2;

    if (D_800CF540 != 0) {
        var_v1 = 0;
__repair_literal = 0;

        if (__repair_literal < D_800EDAA0) {
            temp_a3 = arg1 & 0xFFFF;
            var_a2 = 0;
            for (;;) {
                temp_a1 = *(s32 *)(D_800EDAA4 + var_a2);
                if ((*(u16 *)((char *)(temp_a1) + 4)) != (arg0 & 0xFFFF)) {
                    var_v1++;
                    var_a2 += 4;
                    if (D_800EDAA0 <= var_v1) {
                        return -1;
                    }
                    continue;
                }
                break;
            }
            if ((*(u16 *)((char *)(temp_a1) + 6)) == 0) {
                var_s0 = temp_a1 + ((*(s32 *)((char *)(temp_a1) + 0x24)) + 8);
                var_a0 = *(u16 *)var_s0;
                temp_s2 = temp_a1 + ((*(s32 *)((char *)(temp_a1) + 0x1C)) + 8);
                temp_s1 = temp_a1 + ((*(s32 *)((char *)(temp_a1) + 0x20)) + 8);
                if ((short)var_a0 != 0xFFFF) {
                    while (var_a0 != (int)temp_a3) {
                        var_s0 += 0x84;
                        var_a0 = *(u16 *)var_s0;
                        if (var_a0 == 0xFFFF) {
                            return -1;
                        }
                    }
                    func_8008C0D4(var_a0, temp_a1, var_a2);
                    temp_s0 = func_8008F520(temp_s2, temp_s1, var_s0, arg2, arg3);
                    func_8008C11C();
                    return temp_s0;
                }
                return -1;
            }
            /* Duplicate return node #17. Try simplifying control flow for better match */
            return -1;
        }
    }
return -1;
}
