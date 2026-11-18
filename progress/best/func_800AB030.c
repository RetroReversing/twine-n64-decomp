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

s32 func_800ABE80();
f64 func_800ABFA0();
extern char D_800D1250[];
extern f64 D_800D6FA0;
extern f64 D_800D6FA8;

void func_800AB030(f64 arg0, s32 arg1, f64 *arg2, f64 *arg3) {
    f64 temp_fs0;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_ret;
    s32 var_a1;
    s32 var_a2;
    s32 var_s0;
    s32 var_s2;
    s32 var_t0;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 var_a3;
    u32 var_s1;
    u32 var_s3;
    u32 var_t1;
    void *temp_v0;
    void *temp_v0_2;

    var_s0 = 0x09B74EDA;
    var_s1 = 0x8435E580;
    var_s2 = 0;
    var_s3 = 0;
    temp_ret = func_800ABE80(arg0 * D_800D6FA0);
    var_a2 = temp_ret;
    var_a3 = (u32) (u64) temp_ret;
    var_a1 = 0;
    do {
        if (var_a2 >= 0) {
            if (var_a1 & 0x20) {
                var_v1 = var_s2 >> var_a1;
                var_v0 = var_s2 >> 0x1F;
            } else {
                var_v1 = (s32) (var_s3 >> var_a1);
                if ((var_a1 << 0x1A) != 0) {
                    var_v1 |= var_s2 << -var_a1;
                }
                var_v0 = var_s2 >> var_a1;
            }
            var_t1 = var_s1 - var_v1;
            var_t0 = (var_s0 - var_v0) - (var_s1 < (u32) var_v1);
            if (var_a1 & 0x20) {
                var_v1_2 = var_s0 >> var_a1;
                var_v0_2 = var_s0 >> 0x1F;
            } else {
                var_v1_2 = (s32) (var_s1 >> var_a1);
                if ((var_a1 << 0x1A) != 0) {
                    var_v1_2 |= var_s0 << -var_a1;
                }
                var_v0_2 = var_s0 >> var_a1;
            }
            var_s3 += var_v1_2;
            var_s2 = var_s2 + var_v0_2 + (var_s3 < (u32) var_v1_2);
            temp_v0 = (var_a1 * 8) + D_800D1250;
            temp_v1 = M2C_FIELD(temp_v0, u32 *, 4);
            temp_a0 = var_a3 < temp_v1;
            var_a3 -= temp_v1;
            var_a2 = (var_a2 - M2C_FIELD(temp_v0, s32 *, 0)) - temp_a0;
        } else {
            if (var_a1 & 0x20) {
                var_v1_3 = var_s2 >> var_a1;
                var_v0_3 = var_s2 >> 0x1F;
            } else {
                var_v1_3 = (s32) (var_s3 >> var_a1);
                if ((var_a1 << 0x1A) != 0) {
                    var_v1_3 |= var_s2 << -var_a1;
                }
                var_v0_3 = var_s2 >> var_a1;
            }
            var_t1 = var_s1 + var_v1_3;
            var_t0 = var_s0 + var_v0_3 + (var_t1 < (u32) var_v1_3);
            if (var_a1 & 0x20) {
                var_v1_4 = var_s0 >> var_a1;
                var_v0_4 = var_s0 >> 0x1F;
            } else {
                var_v1_4 = (s32) (var_s1 >> var_a1);
                if ((var_a1 << 0x1A) != 0) {
                    var_v1_4 |= var_s0 << -var_a1;
                }
                var_v0_4 = var_s0 >> var_a1;
            }
            temp_a0_2 = var_s3 < (u32) var_v1_4;
            var_s3 -= var_v1_4;
            var_s2 = (var_s2 - var_v0_4) - temp_a0_2;
            temp_v0_2 = (var_a1 * 8) + D_800D1250;
            temp_v1_2 = M2C_FIELD(temp_v0_2, u32 *, 4);
            var_a3 += temp_v1_2;
            var_a2 = var_a2 + M2C_FIELD(temp_v0_2, s32 *, 0) + (var_a3 < temp_v1_2);
        }
        var_s0 = var_t0;
        var_a1 += 1;
        var_s1 = var_t1;
    } while (var_a1 < 0x34);
    temp_fs0 = D_800D6FA8;
    *arg2 = func_800ABFA0(var_s2, var_s3, var_a2, var_a3) / temp_fs0;
    *arg3 = func_800ABFA0(var_s0, var_s1) / temp_fs0;
}
