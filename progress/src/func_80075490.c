/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void func_8000B9B8(u8 *, s32, u32);
u16 func_800870F4(void);
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
    s32 temp_s0;

    s32 id = arg1;
    D_800C7EDC = id;
    temp_v1 = func_800870F4() & 0xFFFF;
    if (temp_v1 == 2) goto one;
    if (temp_v1 == 5) goto two;
    var_v0_2 = 0;
    goto scale;
one:
    var_v0_2 = 1;
    goto scale;
found:
    temp_s0 = *(u16 *)(var_v1 + 2);
    func_8000B9B8(arg0, (*(s32 *)(var_v1 + 4)) + D_148B400, temp_s0);
    goto done;
two:
    var_v0_2 = 2;
scale:
    var_v0 = (s32)var_v0_2 * 4;
scan:
    temp_a0 = *(s32 *)(D_800C994C + var_v0);
    temp_s0 = 0;
    if (*temp_a0 != 0xFFFF) {
        unsigned sentinel = 0xFFFF;
        var_v1 = (char *)temp_a0;
        do {
            var_v0_3 = arg0;
            if (*(u16 *)var_v1 == arg1) goto found;
            var_v1 += 8;
        } while (*(u16 *)var_v1 != sentinel);
    }
done:
    *(arg0 + temp_s0) = 0;
}
