/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008C0D4();
s32 func_8008C11C();
extern s32 D_800F3950;
extern char D_800F3954[];
extern char D_800F3958[];

s32 func_80097704(s32 arg0) {
    s16 temp_v0;
    s32 temp_v0_2;
    s32 var_v1;
    s32 var_a1;
    register s32 var_a2;
    register void *var_t0;
    s32 var_a3;
    u32 temp_v1;

    func_8008C0D4();
    var_a1 = 0;
    if (0 < D_800F3950) {
        var_v1 = 0;
        for (;;) {
            if (*(u16 *)(D_800F3958 + (unsigned short)var_v1) != (arg0 & (short)0xFFFF)) {
                var_v1 += 8;
                var_a1 += 1;
                if (var_a1 < D_800F3950) {
                    continue;
                }
            }
            break;
        }
    }
    var_a3 = D_800F3950;
    temp_v1 = var_a1 * 8;
    if (var_a1 != var_a3) {
        temp_v0 = *(u16 *)(D_800F3958 + 2 + temp_v1) - 1;
        *(u16 *)(D_800F3958 + 2 + temp_v1) = temp_v0;
        var_a2 = var_a1 + 1;
        if (!(temp_v0 & 0xFFFF)) {
            if (var_a2 < var_a3) {do{do{do{do{do{
                temp_v0_2 = var_a2 * 8;}while(0);}while(0);}while(0);}while(0);}while(0);
                var_t0 = temp_v0_2 + (D_800F3954 - 8);
                var_a3 = (s32) (temp_v0_2 + D_800F3954);
                do {
                    (*(s32 *)((char *)(var_t0) + 0)) = (s32) (*(s32 *)((char *)(var_a3) + 0));
                    (*(s32 *)((char *)(var_t0) + 4)) = (s32) (*(s32 *)((char *)(var_a3) + 4));
                    var_t0 += 8;/*__repair_loop_weight*/do {
                    var_a2++;} while (0);
                    var_a3 += 8;
                } while (var_a2 < D_800F3950);
            }
            D_800F3950--;
            func_8008C11C(D_800F3954, var_a1, var_a2, (void *) var_a3);
            return 1;
        }
    }
    func_8008C11C();
    return 0;
}
