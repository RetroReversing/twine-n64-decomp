/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000B9B8();
s32 func_800870F4();
extern char D_148B400[];
extern s32 D_800C7EDC;
extern char D_800C994C[];

void func_80075490(s8 *arg0, s32 arg1) {
    unsigned temp_v1;
    long var_v0;
    char *var_v1;
    unsigned int var_v0_2;
    u16 *temp_a0;
    register s8 *var_v0_3;
    u16 temp_s0;

    D_800C7EDC = arg1;
    temp_v1 = func_800870F4() & 0xFFFF;
    if (temp_v1 != 2) {
        if ((unsigned)temp_v1 != 5) {
            var_v0 = 0 * 4;
        } else {
            var_v0_2 = 2;
            goto block_6;
        }
    } else {
        var_v0_2 = 1;
block_6:
        var_v0 = (s32)var_v0_2 * 4;
    }
    temp_a0 = *(s32 *)(D_800C994C + var_v0);
    if (*temp_a0 != 0xFFFF) {
        var_v1 = temp_a0;
        for (;;) {
            if ((*(u16 *)((char *)(var_v1) + 0)) != arg1) {
                var_v1 += 8;
                if (*(u16 *)var_v1 == 0xFFFF) {
                    goto block_11;
                }
                continue;
            }
            break;
        }
        func_8000B9B8(arg0, (*(s32 *)((char *)(var_v1) + 4)) + D_148B400, temp_v1);
        var_v0_3 = &arg0[temp_v1];
        temp_v1 = (u16)((*(u16 *)((char *)(var_v1) + 2)));
    } else {
block_11:
        var_v0_3 = arg0;
    }
    *var_v0_3 = 0;
}
