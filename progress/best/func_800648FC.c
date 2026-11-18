/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80063C7C();
extern char D_800C469C[];

s32 func_800648FC(void *arg0, s32 arg1) {
int __repair_literal;

    s16 temp_a1;
    s16 var_v1;
    s32 temp_s2;
    s32 temp_v0;
    s8 temp_a0;
    short temp_a0_2;
    u8 temp_s0;
    void *temp_a2;
    void *temp_s1;
    void *temp_t0;

    temp_a0 = (*(s8 *)((char *)((*(void **)((char *)(arg0) + 0x68))) + 0xE));
    temp_s2 = (*(s32 *)((char *)(arg0) + 0x6C));
    temp_s1 = (D_800C469C) + ((temp_a0 * 0xE8));
    temp_s0 = (*(u8 *)((char *)(temp_s1) + 0x80));
    temp_v0 = func_80063C7C(temp_a0);
    temp_t0 = (char *)(temp_s2); temp_t0 += (s32)((temp_s0 * 2));
    temp_a1 = (*(s16 *)((char *)(temp_t0) + 0x1BC));
__repair_literal = 0;

    if (temp_a1 > __repair_literal) {
        temp_a2 = temp_s2 + ((s32) (temp_v0 << 0x10) >> 0xD);
        temp_a0_2 = (*(u8 *)((char *)(temp_s1) + 0x83));
        var_v1 = (*(u8 *)((char *)(temp_s1) + 0x82)) - (*(s8 *)((char *)(temp_a2) + 0x1FF));
        if (var_v1 > temp_a0_2) {
            register var_v1 = (s16) temp_a0_2;
        }
        if (temp_a1 < var_v1) {
            var_v1 = temp_a1;
        }
        if ((unsigned short)temp_a1 != 0) {
            if ((arg1 << 0x18) != 0) {
                return 1;
            }
            (*(s16 *)((char *)(temp_t0) + 0x1BC)) = (s16) (temp_a1 - temp_a1);
            (*(s8 *)((char *)(temp_a2) + 0x1FF)) = (s8) ((u8) (*(s8 *)((char *)(temp_a2) + 0x1FF)) + temp_a1);
            return 1;
        }
        goto block_10;
    }
block_10:
    return 0;
}
