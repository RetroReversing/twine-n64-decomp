/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */

u64 func_800ABE80(f64);                             /* extern */
f64 func_800ABFA0(s32, u32, s32, s32);              /* extern */
extern s32 D_800D1550;
extern f64 D_800D6F20;
extern f64 D_800D6F28;

f64 func_800AAA20(f64 arg0) {
    long var_v1;
    u32 var_s1;
    void *temp_v0;
    register unsigned int temp_a2;
    s32 var_v0;
    s32 var_v0_2;
    register s32 var_a1;
    u32 temp_v1;
    unsigned long temp_a3;
    s32 var_s0;
    u64 var_t0;
    u64 temp_ret;
    u32 var_t1;

    var_s0 = 0x10000000;
    var_s1 = 0;
    temp_ret = func_800ABE80(arg0 * D_800D6F20);
    var_t0 = temp_ret;
    var_t1 = (u32) temp_ret;
    var_a1 = 1;
    var_v0 = 1 * 8;
    do {
        register temp_v0 = var_v0 + &D_800D1550;
        temp_v1 = (*(u32 *)((char *)(temp_v0) + 4));
        temp_a3 = temp_v1 - var_t1;
        temp_a2 = ((*(s32 *)((char *)(temp_v0) + 0)) - var_t0) - (temp_v1 < var_t1);
        if ((0 >= temp_a2) && (((int)temp_a2 != 0) || (!temp_a3))) {
            register var_t1 = (u32) -temp_a3;
            register var_t0 = -temp_a2 - (var_t1 != 0);
            if (var_a1 & 0x20) {
                var_v1 = var_s0 >> var_a1;
                var_v0_2 = var_s0 >> 0x1F;
            } else {
                var_v1 = (s32) (var_s1 >> var_a1);
                if ((var_a1 << 0x1A) != 0) {
                    var_v1 |= (unsigned)var_s0 << -(u32)var_a1;
                }
                var_v0_2 = var_s0 >> var_a1;
            }
            var_s0 = var_s0 + var_v0_2 + (var_s1 < (u32) var_v1);
            var_s1 += var_v1;
        }
        var_a1++;
        var_v0 = var_a1 * 8;
    } while (var_a1 < 0x36);
    return func_800ABFA0(var_s0, var_s1, temp_a2, temp_a3) / D_800D6F28;
}
