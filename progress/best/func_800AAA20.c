/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */
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

u64 func_800ABE80(f64);                             /* extern */
f64 func_800ABFA0(s32, u32, s32, s32);              /* extern */
extern M2C_UNK D_800D1550;
extern f64 D_800D6F20;
extern f64 D_800D6F28;

f64 func_800AAA20(f64 arg0) {
    s32 temp_a2;
    s32 temp_a3;
    s32 var_a1;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    u32 temp_v1;
    u32 var_s1;
    u32 var_t1;
    u64 temp_ret;
    u64 var_t0;
    void *temp_v0;

    var_s0 = 0x10000000;
    var_s1 = 0;
    temp_ret = func_800ABE80(arg0 * D_800D6F20);
    var_t0 = temp_ret;
    var_t1 = (u32) temp_ret;
    var_a1 = 1;
    var_v0 = 1 * 8;
    do {
        temp_v0 = var_v0 + &D_800D1550;
        temp_v1 = M2C_FIELD(temp_v0, u32 *, 4);
        temp_a3 = temp_v1 - var_t1;
        temp_a2 = (M2C_FIELD(temp_v0, s32 *, 0) - var_t0) - (temp_v1 < var_t1);
        if ((temp_a2 <= 0) && ((temp_a2 != 0) || (temp_a3 == 0))) {
            var_t1 = (u32) -temp_a3;
            var_t0 = -temp_a2 - (var_t1 != 0);
            if (var_a1 & 0x20) {
                var_v1 = var_s0 >> var_a1;
                var_v0_2 = var_s0 >> 0x1F;
            } else {
                var_v1 = (s32) (var_s1 >> var_a1);
                if ((var_a1 << 0x1A) != 0) {
                    var_v1 |= var_s0 << -var_a1;
                }
                var_v0_2 = var_s0 >> var_a1;
            }
            var_s1 += var_v1;
            var_s0 = var_s0 + var_v0_2 + (var_s1 < (u32) var_v1);
        }
        var_a1 += 1;
        var_v0 = var_a1 * 8;
    } while (var_a1 < 0x36);
    return func_800ABFA0(var_s0, var_s1, temp_a2, temp_a3) / D_800D6F28;
}
