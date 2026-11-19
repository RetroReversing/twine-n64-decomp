/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8000B900();
s32 memcpy();

void func_8000B9B8(s32 arg0, s32 arg1, u32 arg2) {
    s32 temp_s0;
    register u8 sp10;
    s32 temp_s5;
    s32 var_s2;
    s32 var_s3;
    u32 temp_s4;
    u32 var_s0;
    u32 var_s0_2;
    u32 var_s1;

    var_s3 = arg0;
    var_s2 = arg1;
    var_s1 = arg2;
    if (var_s1) {
        temp_s5 = var_s2 & 1;
        temp_s4 = var_s3 & 7;
        if ((temp_s5 | (temp_s4)) != 0) {
            var_s0 = 8 - temp_s4;
            if (var_s1 < var_s0) {
                var_s0 = var_s1;
            }
            do { func_8000B900(&sp10, var_s2 - temp_s5, arg2, (var_s1 + temp_s5 + 1) & ~1); } while (0);
            var_s0_2 = temp_s4;
            if (var_s0_2 == 0) {
                var_s0_2 = 8;
            }
            if (var_s1 < var_s0_2) {
                var_s0_2 = var_s1;
            }
            memcpy(var_s3, &(&sp10)[temp_s5], var_s0_2);
            var_s2 += var_s1 + temp_s5;
            var_s3 += var_s0_2;
            var_s1 -= var_s0_2;
        }
        temp_s0 = var_s1 & ~1;
        if (temp_s0 != 0) {
            do { func_8000B900((u8 *) var_s3, var_s2, temp_s0); } while (0);
            var_s2 += temp_s0;
            var_s3 += temp_s0;
        }
        if (var_s1 & 1) {
            func_8000B900(&sp10, var_s2, 2);
            *(s32 *)var_s3 = sp10;
        }
    }
}
