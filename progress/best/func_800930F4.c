/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008C0D4();
s32 func_8008C11C();
s32 func_8008F520();
extern u8 D_800CF540;
extern s16 D_800EDAA0;
extern char D_800EDAA4[];

s32 func_800930F4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
int __repair_literal;

    u16 var_a0;
    s32 temp_s0;
    s32 var_a2;
    register s32 var_v1;
    char *var_s0;
    unsigned int temp_a3;
    void *temp_a1;
    void *temp_s1;
    void *temp_s2;

    if (D_800CF540) {
        register var_v1 = 0;
__repair_literal = 0;

        if (D_800EDAA0 > __repair_literal) {
            temp_a3 = arg1 & 0xFFFF;
            var_a2 = 0;
loop_3:
            temp_a1 = *(s32 *)(D_800EDAA4 + var_a2);
            if ((*(u16 *)((char *)(temp_a1) + 4)) != (arg0 & (short)0xFFFF)) {
                var_a2 += 4;
                var_v1 += 1;
                if (var_v1 >= D_800EDAA0) {
                    goto block_16;
                }
                goto loop_3;
            }
            if ((*(u16 *)((char *)(temp_a1) + 6)) == 0) {
                var_s0 = temp_a1 + ((*(s32 *)((char *)(temp_a1) + 0x24)) + 8);
                var_a0 = *(u16 *)var_s0;
                temp_s1 = temp_a1 + ((*(s32 *)((char *)(temp_a1) + 0x20)) + 8);
                temp_s2 = temp_a1 + ((*(s32 *)((char *)(temp_a1) + 0x1C)) + 8);
                if (var_a0 != (short)0xFFFF) {
loop_9:
                    if (var_a0 != temp_a3) {
                        var_a0 = *(u16 *)var_s0;
                        var_s0 += 0x84;
                        if ((s32)var_a0 == (short)0xFFFF) {
                            return -1;
                        }
                        goto loop_9;
                    }
                    func_8008C0D4(var_a0, temp_a1, var_a2);
                    temp_s0 = func_8008F520(temp_s2, temp_s1, var_s0, arg2, arg3);
                    func_8008C11C();
                    return temp_s0;
                }
                goto block_16;
            }
            /* Duplicate return node #17. Try simplifying control flow for better match */
            return -1;
        }
    }
block_16:
    return -1;
}
