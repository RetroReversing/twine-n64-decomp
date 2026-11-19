/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800263B8(void *arg0, s32 arg1) {
char *__repair_addr;

    s32 temp_v1;
    s32 var_a2;
    s32 temp_v0;

    if (arg0 == NULL) {
        return 0;
    }
    temp_v0 = (*(u8 *)((char *)(arg0) + 5));
    var_a2 = 0;
    if (temp_v0 != 0) {
        for (;;) {
            temp_v1 = var_a2 & 0xFFFF;/*__repair_loop_weight*/do {
                    var_a2 += 1;} while (0);
            __repair_addr = (char *)((temp_v1 * 0x28) + (*(s32 *)((char *)(arg0) + 0)));
            if (*(s32 *)(__repair_addr) == (arg1 & 0xFFFF)) {
                break;
            }
            if ((u32) (var_a2 & 0xFFFF) >= ((*(u8 *)((char *)(arg0) + 5)))) {
                return 0;
            }
        }
        return temp_v1;
    }
    return 0;
}
