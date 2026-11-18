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

void *func_8000182C();
s32 func_8000B900();
extern char D_800C3928[];
extern f64 D_800D2008;
extern s32 (*D_800D9424)(f32 *, void *);
extern char D_F8D70[];

void func_800055CC(s32 *arg0, u32 arg1, u32 arg2, s32 arg3) {
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 temp_fv1;
    f64 temp_fs0;
    f64 var_fv0;
    f64 var_fv0_2;
    f64 var_fv0_3;
    s16 temp_a0;
    s16 temp_s4;
    s16 var_s5;
    s32 temp_a0_2;
    s32 temp_fp;
    s32 temp_s0;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_s0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s6;
    s32 var_v0;
    s32 var_v1;
    u32 temp_v0_2;
    u32 temp_v1;
    u32 var_a0;
    void *temp_a1;
    void *temp_s3;
    void *temp_v0;
    void *var_a0_2;
    void *var_v1_2;

    var_a0 = arg1;
    if (var_a0 >= 0x40BU) {
        var_a0 = 0x71;
    }
    temp_v0 = func_8000182C(var_a0);
    temp_a0 = M2C_FIELD(temp_v0, s16 *, 2);
    temp_s4 = *(D_800C3928 + ((temp_a0 & 0x7FFF) * 8));
    temp_a0_2 = temp_a0 & 0x8000;
    var_v1 = temp_s4 << 0x10;
    if (temp_a0_2 != 0) {
        var_s6 = temp_s4 * 3;
        if (arg3 != 0) {
            var_v1 |= 3;
        } else {
            var_v1 |= 2;
        }
    } else {
        var_s6 = 3;
        if (arg3 != 0) {
            var_v1 |= 1;
        }
    }
    *arg0 = var_v1;
    temp_s3 = arg0 + 8;
    var_s5 = 1;
    temp_fp = var_s6 + temp_s4;
    if (temp_a0_2 != 0) {
        var_s5 = temp_s4;
    }
    var_s1 = 0;
    temp_s0 = var_s5 * 6;
    func_8000B900(temp_s3, ((M2C_FIELD(temp_v0, s32 *, 4) + (((var_s5 * 3) + (temp_s4 * 2)) * (arg2 & -(arg2 < (u32) M2C_FIELD(temp_v0, s16 *, 0))) * 2)) - temp_s0) + D_F8D70, temp_fp * 4);
    if (var_s5 > 0) {
        var_a0_2 = temp_s3;
        var_v1_2 = temp_s3 + temp_s0;
        __repair_rows: {
            M2C_FIELD(var_a0_2, f32 *, 0) = (f32) (((f32) M2C_FIELD(var_v1_2, u16 *, 0) * M2C_FIELD(temp_v0, f32 *, 8)) + M2C_FIELD(temp_v0, f32 *, 0x14));
            M2C_FIELD(var_a0_2, f32 *, 4) = (f32) (((f32) M2C_FIELD(var_v1_2, u16 *, 2) * M2C_FIELD(temp_v0, f32 *, 0xC)) + M2C_FIELD(temp_v0, f32 *, 0x18));
            temp_fv1 = ((f32) M2C_FIELD(var_v1_2, u16 *, 4) * M2C_FIELD(temp_v0, f32 *, 0x10)) + M2C_FIELD(temp_v0, f32 *, 0x1C);
            var_s1 += 1;
            var_v1_2 += 6;
            M2C_FIELD(var_a0_2, f32 *, 8) = temp_fv1;
            var_a0_2 += 0xC;
        }
if (var_s1 < var_s5) goto __repair_rows;
    }
    if (arg3 != 0) {
        var_s1_2 = 0;
        if (temp_s4 > 0) {
            temp_fs0 = D_800D2008;
            var_s0 = temp_fp;
            var_v0 = var_s6;
            do {
                temp_v1 = *(u32 *)((var_v0 * 4) + temp_s3);
                temp_v0_2 = temp_v1 >> 0x16;
                var_fv0 = (f64) (temp_v0_2 * 4);
                if (temp_v0_2 & 0x20000000) {
                    var_fv0 += temp_fs0;
                }
                sp10 = (f32) var_fv0;
                temp_v0_3 = (temp_v1 >> 0xA) & 0xFFE;
                var_fv0_2 = (f64) temp_v0_3;
                if (temp_v0_3 < 0) {
                    var_fv0_2 += temp_fs0;
                }
                sp14 = (f32) var_fv0_2;
                temp_v0_4 = (temp_v1 * 2) & 0xFFE;
                var_fv0_3 = (f64) temp_v0_4;
                if (temp_v0_4 < 0) {
                    var_fv0_3 += temp_fs0;
                }
                temp_a1 = temp_s3 + (var_s0 * 4);
                var_s0 += 4;
                var_s1_2 += 1;
                sp18 = (f32) var_fv0_3;
                D_800D9424(&sp10, temp_a1);
                var_v0 = var_s6 + var_s1_2;
            } while (var_s1_2 < temp_s4);
        }
    }
}
