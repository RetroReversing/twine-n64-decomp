static __inline__ u16 __repair_inline(u16 a) { return a; }
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008C0D4();
s32 func_8008C11C();
extern s32 D_800F8D5C;
extern u16 D_800F8D5E;
extern char D_800F8D60[];
extern char D_800F8D62[];
extern char D_800F9560[];
extern char D_800F9564[];
extern char D_800F9566[];
extern char D_800F9568[];

s32 func_80097EF8(u16 arg0, s32 arg1) {
    volatile long long __frame_gap;
    char *var_a1;
    unsigned int temp_a1;
    unsigned temp_t2;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 var_a0_2;
    s32 var_a2;
    s32 var_a2_2;
    u32 var_v0_2;
    s32 temp_v0;
    u16 var_v0;
    u16 var_a3;
    u16 var_t1;
    void *var_t0;
    s32 temp_v1;
    u32 var_a0;
    u16 temp_v1_3;

    func_8008C0D4();
    var_a0 = arg0;
    temp_t2 = var_a0 >> 6;
    temp_v1 = temp_t2 * 4;
    do { temp_v0 = __repair_inline(*(u16 *)(D_800F8D60 + (temp_t2 * 4))); } while (0);
    if ((*(u16 *)(D_800F8D60 + temp_v1)) == 0) {
        var_t1 = D_800F8D5E & 0xFFFF;
        *(u16 *)(D_800F8D62 + temp_v1) = D_800F8D5E;
        var_a3 = var_t1;
        goto block_11;
    }
    var_a3 = *(u16 *)(D_800F8D62 + (temp_t2 * 4));
    var_a2 = 0;
    if (temp_v0 != 0) {
        var_v0 = var_a3;
loop_4:
        var_v0_2 = temp_t2 * 4;
        if ((u16) *(u16 *)(D_800F9564 + (var_v0 * 8)) < var_a0) {
            ++var_a2;
            var_v0 = var_a3 + var_a2;
            if (var_a2 >= (s32) temp_v0) {
                var_v0_2 = temp_t2 * 4;
            } else {
                goto loop_4;
            }
        }
        var_t1 = var_a3 + var_a2;
        if (var_a2 < (s32) *(u16 *)(D_800F8D60 + var_v0_2)) {
            temp_v1_2 = var_t1 * 8;
            if (*(u16 *)(D_800F9564 + temp_v1_2) == var_a0) {
                *(u16 *)(D_800F9566 + temp_v1_2) = *(u16 *)(D_800F9566 + temp_v1_2) + 1;
                goto block_21;
            }
            goto block_11;
        }
        goto block_10;
    }
block_10:
    var_t1 = var_a3 + var_a2;
block_11:
    var_a0 = 0;
    if (D_800F8D5C < 0x800) {
        var_a1 = D_800F8D60;
        do {
            temp_v1_3 = *(u16 *)(D_800F8D62 + var_a0);
            if ((s32) var_a3 < (s32) temp_v1_3) {
                (*(s16 *)((char *)(var_a1) + 2)) = (s16) (temp_v1_3 + 1);
            }
            var_a0 += 4;
            var_a1 += 4;
        } while ((s32) var_a0 < 0x800);
        var_a2_2 = D_800F8D5C - 1;
        var_a0_2 = var_t1 * 8;
        if (var_a2_2 >= (s32) var_t1) {
            temp_v1_4 = var_a2_2 * 8;
            var_t0 = temp_v1_4 + D_800F9568;
            var_a3 = (u16) (temp_v1_4 + (D_800F9568 - 8));
            do {
                (*(s32 *)((char *)(var_t0) + 0)) = (s32) (*(s32 *)((char *)(var_a3) + 0));
                (*(s32 *)((char *)(var_t0) + 4)) = (s32) (*(s32 *)((char *)(var_a3) + 4));
                var_t0 -= 8;
                var_a3 -= 8;
                var_a2_2 -= 1;
            } while (var_a2_2 >= (s32) var_t1);
            var_a0_2 = var_t1 * 8;
        }
        var_v0_2 = temp_t2 * 4;
        *(u16 *)(D_800F9564 + var_a0_2) = arg0;
        *(u16 *)(D_800F9566 + var_a0_2) = 1;
        *(s32 *)(D_800F9560 + var_a0_2) = arg1;
        *(u16 *)(D_800F8D60 + var_v0_2) = *(u16 *)(D_800F8D60 + var_v0_2) + 1;
        func_8008C11C(var_a0_2, var_v0_2, var_a2_2, (void *) var_a3);
        ++D_800F8D5C;
        return 1;
    }
block_21:
    func_8008C11C(var_a0);
    return 0;
}
