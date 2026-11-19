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

typedef struct { s32 w[2]; } __repair_words2;
s32 func_80097194(s32 arg0) {
    s16 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    s32 var_v1;
    void *var_t0;

    func_8008C0D4();
    var_a1 = 0;
    if (D_800F7954 > 0) {
        var_v1 = 0;
        for (;;) {
            if (*(u16 *)(D_800F795C + var_v1) != (arg0 & 0xFFFF)) {
                var_a1 += 1;
                var_v1 += 8;
                if (var_a1 < D_800F7954) {
                    continue;
                }
            }
            break;
        }
    }
    var_a3 = D_800F7954;
    temp_v1 = var_a1 * 8;
    if (var_a1 != var_a3) {
        temp_v0 = *(u16 *)(D_800F795C + 2 + temp_v1) - 1;
        *(u16 *)(D_800F795C + 2 + temp_v1) = temp_v0;
        var_a2 = var_a1 + 1;
        if (!(temp_v0 & 0xFFFF)) {
            if (var_a2 < var_a3) {
                temp_v0_2 = var_a2 * 8;
                var_t0 = temp_v0_2 + (D_800F7958 - 8);
                var_a3 = (s32) (temp_v0_2 + D_800F7958);
                do {
                    M2C_FIELD(var_t0, __repair_words2 *, 0x0) = *(__repair_words2 *) ((s8 *) var_a3 + 0x0);
                    var_t0 += 8;
                    var_a2 += 1;
                    var_a3 += 8;
                } while (var_a2 < D_800F7954);
            }
            D_800F7954 -= 1;
            func_8008C11C(D_800F7958, var_a1, var_a2, (void *) var_a3);
            return 1;
        }
    }
    func_8008C11C();
    return 0;
}
