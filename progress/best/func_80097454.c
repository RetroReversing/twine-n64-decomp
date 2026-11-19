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
extern s32 D_800F8158;
extern char D_800F815C[];
extern char D_800F8160[];
extern char D_800F8164[];

s32 func_80097454(s32 arg0) {
    s32 *var_a0;
    s16 temp_v1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    s32 var_v1;
    void *var_t0;

    func_8008C0D4();
    var_a1 = 0;
    if (D_800F8158 > 0) {
        var_v1 = 0;
loop_2:
        if (*(u16 *)(D_800F8160 + var_v1) != (arg0 & 0xFFFF)) {
            var_a1 += 1;
            var_v1 += 0xC;
            if (var_a1 < D_800F8158) {
                goto loop_2;
            }
        }
    }
    var_a3 = D_800F8158;
    if (var_a1 != var_a3) {
        var_a2 = var_a1 * 0xC;
        var_a0 = D_800F815C;
        temp_v1 = *(u16 *)(D_800F8164 + var_a2) - 1;
        *(u16 *)(D_800F8164 + var_a2) = temp_v1;
        var_a2 = var_a1 + 1;
        if (!(temp_v1 & 0xFFFF)) {
            if (var_a2 < var_a3) {
                temp_v0_2 = var_a2 * 0xC;
                var_t0 = temp_v0_2 + (D_800F815C - 0xC);
                var_a3 = (s32) (temp_v0_2 + D_800F815C);
                do {
                    var_a0 = M2C_FIELD(var_a3, s32 **, 8);
                    M2C_FIELD(var_t0, s32 *, 0) = (s32) M2C_FIELD(var_a3, s32 *, 0);
                    M2C_FIELD(var_t0, s32 *, 4) = (s32) M2C_FIELD(var_a3, s32 *, 4);
                    M2C_FIELD(var_t0, s32 **, 8) = var_a0;
                    var_t0 += 0xC;
                    var_a2 += 1;
                    var_a3 += 0xC;
                } while (var_a2 < D_800F8158);
            }
            D_800F8158 -= 1;
            func_8008C11C(var_a0, var_a1, var_a2, (void *) var_a3);
            return 1;
        }
    }
    func_8008C11C();
    return 0;
}
