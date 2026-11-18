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
extern s32 D_800FD560;
extern char D_800FD564[];
extern char D_800FD566[];
extern char D_800FD568[];

s32 func_80097D0C(s16 arg0, void *arg1, s16 arg2) {
    s16 temp_s1;
    s16 temp_s2;
    s16 var_a0;
    s16 var_a2;
    s32 temp_a2;
    s32 temp_v0;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    void *var_s0;

    var_a0 = arg0;
    var_a2 = arg2;
    var_s0 = arg1;
    var_v1 = 0;
    temp_s1 = var_a0;
    temp_s2 = var_a2;
    if (D_800FD560 > 0) {
        var_a2 = temp_s1 & 0xFFFF;
        var_a0 = 0;
loop_2:
        if (*(u16 *)(D_800FD564 + var_a0) != var_a2) {
            var_v1 += 1;
            var_a0 += 8;
            if (var_v1 < D_800FD560) {
                goto loop_2;
            }
        }
    }
    var_v0 = 0;
    if (var_v1 == D_800FD560) {
        var_v0 = 0;
        if (var_v1 < 0x80) {
            func_8008C0D4(var_a0, D_800FD560);
            temp_a2 = temp_s2 & 0xFFFF;
            temp_v0 = D_800FD560 * 8;
            *(u16 *)(D_800FD564 + temp_v0) = temp_s1;
            *(u16 *)(D_800FD566 + temp_v0) = temp_s2;
            *(u16 *)(D_800FD568 + temp_v0) = var_s0;
            var_v1_2 = 0;
            if (temp_a2 > 0) {
                do {
                    M2C_FIELD(var_s0, s8 *, 9) = 0x1F;
                    var_v1_2 += 1;
                    var_s0 += 0xC;
                } while (var_v1_2 < temp_a2);
            }
            D_800FD560 += 1;
            func_8008C11C();
            var_v0 = 1;
        }
    }
    return var_v0;
}
