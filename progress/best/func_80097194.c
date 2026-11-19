/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008C0D4();
s32 func_8008C11C();
extern s32 D_800F7954;
extern char D_800F7958[];
extern char D_800F795C[];

s32 func_80097194(s32 arg0) {
    s16 temp_v0;
    register void *var_t0;
    register s32 var_a2;
    int var_a3;
    s32 temp_v1;
    u32 temp_v0_2;
    register unsigned int var_v1;
    s32 var_a1;

    func_8008C0D4();
    var_a1 = 0;
    if (D_800F7954 > 0) {
        var_v1 = 0;
loop_2:
        if (*(u16 *)(D_800F795C + (unsigned short)var_v1) != (arg0 & (short)0xFFFF)) {
            var_a1 += 1;
            var_v1 += 8;
            if (var_a1 < D_800F7954) {
                goto loop_2;
            }
        }
    }
    var_a3 = D_800F7954;
    temp_v1 = var_a1 * 8;
    if (var_a1 != var_a3) {
        temp_v0 = *(u16 *)(D_800F795C + 2 + temp_v1) - 1;
        var_a2 = var_a1 + 1;
        *(u16 *)(D_800F795C + 2 + temp_v1) = temp_v0;
        if (!(temp_v0 & 0xFFFF)) {
            if (var_a2 < var_a3) {do{do{do{do{do{
                temp_v0_2 = var_a2 * 8;}while(0);}while(0);}while(0);}while(0);}while(0);
                var_t0 = temp_v0_2 + (D_800F7958 - 8);
                var_a3 = (s32) (temp_v0_2 + D_800F7958);
                do {
                    (*(s32 *)((char *)((u32)var_t0) + 0)) = (s32) (*(s32 *)((char *)(var_a3) + 0));
                    (*(s32 *)((char *)(var_t0) + 4)) = (s32) (*(s32 *)((char *)(var_a3) + 4));
                    var_t0 += 8;/*__repair_loop_weight*/do {do {do {
                    var_a2 += 1;} while (0);} while (0);} while (0);
                    var_a3 += 8;
                } while (D_800F7954 > var_a2);
            }
            D_800F7954 -= 1;
            func_8008C11C(D_800F7958, var_a1, var_a2, (void *) var_a3);
            return 1;
        }
    }
    func_8008C11C();
    return 0;
}
