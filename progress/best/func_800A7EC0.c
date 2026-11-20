extern s32 D_800CFDA0[];
extern s32 D_A0000000;
s32 func_800A7EC0(u8 *arg0, s32 arg1, s32 *arg2) {
    u8 *var_v1;
    u8 *temp_a3;
    s32 t0;
    if (*(vu32 *)0xA4600010 & 3) {
        do {
        } while (*(vu32 *)0xA4600010 & 3);
    }
    t0 = arg0[9];
    temp_a3 = (u8 *)(unsigned long)D_800CFDA0[t0];
    if (temp_a3[4] != arg0[4]) {
        var_v1 = temp_a3;
        if (t0 == 0) {
            if (var_v1[5] != arg0[5]) *(vu32 *)0xA4600014 = arg0[5];
            if (var_v1[6] != arg0[6]) *(vu32 *)0xA460001C = arg0[6];
            if (var_v1[7] != arg0[7]) *(vu32 *)0xA4600020 = arg0[7];
            if (var_v1[8] != arg0[8]) *(vu32 *)0xA4600018 = arg0[8];
        } else {
            if (var_v1[5] != arg0[5]) *(vu32 *)0xA4600024 = arg0[5];
            if (var_v1[6] != arg0[6]) *(vu32 *)0xA460002C = arg0[6];
            if (var_v1[7] != arg0[7]) *(vu32 *)0xA4600030 = arg0[7];
            if (var_v1[8] != arg0[8]) *(vu32 *)0xA4600028 = arg0[8];
        }
        var_v1[4] = arg0[4];
        var_v1[5] = arg0[5];
        var_v1[6] = arg0[6];
        var_v1[7] = arg0[7];
        var_v1[8] = arg0[8];
    }
    *(s32 *)(unsigned long)(*(u32 *)(arg0 + 0xC) | (u32)arg1 | (u32)&D_A0000000) = (s32)arg2;
    return 0;
}
