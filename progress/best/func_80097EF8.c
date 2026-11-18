/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

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

s32 func_80097EF8(s16 arg0, s32 arg1) {
    s32 *var_a1;
    s32 temp_a1;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 var_a0_2;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_v0_2;
    u16 temp_v0;
    u16 temp_v1_3;
    u16 var_a3;
    u16 var_t1;
    u16 var_v0;
    u32 temp_t2;
    u32 var_a0;
    void *var_t0;

    func_8008C0D4();
    var_a0 = arg0 & 0xFFFF;
    temp_t2 = var_a0 >> 6;
    temp_v1 = temp_t2 * 4;
    temp_v0 = *(D_800F8D60 + temp_v1);
    if (temp_v0 == 0) {
        var_t1 = D_800F8D5E & 0xFFFF;
        *(D_800F8D62 + temp_v1) = D_800F8D5E;
        var_a3 = var_t1;
        goto block_11;
    }
    var_a3 = *(D_800F8D62 + temp_v1);
    var_a2 = 0;
    if (temp_v0 != 0) {
        var_v0 = var_a3;
loop_4:
        var_v0_2 = temp_t2 * 4;
        if ((u16) *(D_800F9564 + (var_v0 * 8)) < var_a0) {
            var_a2 += 1;
            var_v0 = var_a3 + var_a2;
            if (var_a2 >= (s32) temp_v0) {
                var_v0_2 = temp_t2 * 4;
            } else {
                goto loop_4;
            }
        }
        var_t1 = var_a3 + var_a2;
        if (var_a2 < (s32) *(D_800F8D60 + var_v0_2)) {
            temp_v1_2 = var_t1 * 8;
            if (*(D_800F9564 + temp_v1_2) == var_a0) {
                *(D_800F9566 + temp_v1_2) = *(D_800F9566 + temp_v1_2) + 1;
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
            temp_v1_3 = *(D_800F8D62 + var_a0);
            if ((s32) var_a3 < (s32) temp_v1_3) {
                M2C_FIELD(var_a1, s16 *, 2) = (s16) (temp_v1_3 + 1);
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
                M2C_FIELD(var_t0, s32 *, 0) = (s32) M2C_FIELD(var_a3, s32 *, 0);
                M2C_FIELD(var_t0, s32 *, 4) = (s32) M2C_FIELD(var_a3, s32 *, 4);
                var_t0 -= 8;
                var_a2_2 -= 1;
                var_a3 -= 8;
            } while (var_a2_2 >= (s32) var_t1);
            var_a0_2 = var_t1 * 8;
        }
        temp_a1 = temp_t2 * 4;
        *(D_800F9564 + var_a0_2) = arg0;
        *(D_800F9566 + var_a0_2) = 1;
        *(D_800F9560 + var_a0_2) = arg1;
        *(D_800F8D60 + temp_a1) = *(D_800F8D60 + temp_a1) + 1;
        D_800F8D5C += 1;
        func_8008C11C(var_a0_2, temp_a1, var_a2_2, (void *) var_a3);
        return 1;
    }
block_21:
    func_8008C11C((s32) var_a0);
    return 0;
}
