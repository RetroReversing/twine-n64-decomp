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
extern s32 D_800F7954;
extern char D_800F7958[];
extern char D_800F795C[];
extern char D_800F7960[];

typedef struct { s32 w[2]; } __repair_words2;
s32 func_80097020(s16 arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a3;
    s32 var_t1;
    s32 var_v0;
    s32 var_v1;
    u32 temp_a1;
    void *var_a2;
    void *var_t0;

    func_8008C0D4();
    var_a0 = D_800F7954;
    var_t1 = 0;
    if (var_a0 > 0) {
        temp_a1 = arg0 & 0xFFFF;
        var_v1 = 0;
loop_2:
        if ((u16) *(u16 *)(D_800F795C + var_v1) < temp_a1) {
            var_t1 += 1;
            var_v1 += 8;
            if (var_t1 < var_a0) {
                goto loop_2;
            }
        }
        var_a0 = var_t1 * 8;
        if (var_t1 < D_800F7954) {
            if (*(u16 *)(D_800F795C + var_a0) != temp_a1) {
                var_a3 = D_800F7954 - 1;
                if (D_800F7954 < 0x800) {
                    temp_v1 = var_a3 * 8;
                    if (var_a3 >= var_t1) {
                        var_t0 = temp_v1 + D_800F7960;
                        var_a2 = temp_v1 + (D_800F7960 - 8);
                        do {
                            M2C_FIELD(var_t0, __repair_words2 *, 0x0) = *(__repair_words2 *) ((s8 *) var_a2 + 0x0);
                            var_t0 -= 8;
                            var_a3 -= 1;
                            var_a2 -= 8;
                        } while (var_a3 >= var_t1);
                    }
                    var_v0 = D_800F7954 + 1;
                    goto block_15;
                }
                goto block_14;
            }
            *(u16 *)(D_800F795C + 2 + var_a0) = *(u16 *)(D_800F795C + 2 + var_a0) + 1;
            goto block_14;
        }
        goto block_13;
    }
block_13:
    var_v0 = D_800F7954 + 1;
    if (D_800F7954 >= 0x800) {
block_14:
        func_8008C11C(var_a0);
        return 0;
    }
block_15:
    D_800F7954 = var_v0;
    temp_v0 = var_t1 * 8;
    *(u16 *)(D_800F795C + temp_v0) = arg0;
    *(s32 *)(D_800F7958 + temp_v0) = arg1;
    *(u16 *)(D_800F795C + 2 + temp_v0) = 1;
    func_8008C11C(var_a0);
    return 1;
}
