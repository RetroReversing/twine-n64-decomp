/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */

u64 func_800ABE80(f64);                             /* extern */
f64 func_800ABFA0(s32, u32, s32, s32);              /* extern */
extern s32 D_800D1550;
extern f64 D_800D6F20;
extern f64 D_800D6F28;

f64 func_800AAA20(f64 arg0) {
    union { s32 * pointer; s32 value; } __repair_phase_storage;
    s32 temp_a2;
    
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
    var_t1 = (u32) (u32)temp_ret;
    var_v0 = 1 * 8;
    var_a1 = 1;
    do { {
        __repair_phase_storage.pointer = &D_800D1550;
        temp_v0 = var_v0 + __repair_phase_storage.pointer;
        temp_v1 = (*(u32 *)((char *)(temp_v0) + 4));
        __repair_phase_storage.value = temp_v1 - var_t1;
        temp_a2 = ((*(s32 *)((char *)(temp_v0) + 0)) - (int)var_t0) - (temp_v1 < var_t1);
        if ((temp_a2 <= 0) && ((temp_a2 != 0) || (__repair_phase_storage.value == 0))) {
            var_t1 = (u32) -__repair_phase_storage.value;
            var_t0 = -temp_a2 - (var_t1 != 0);
            if (var_a1 & 0x20) {
                var_v0_2 = var_s0 >> 0x1F;
                var_v1 = var_s0 >> var_a1;
            } else {
                var_v1 = (s32) (var_s1 >> var_a1);
                if ((var_a1 << 0x1A) != 0) {
                    var_v1 |= var_s0 << -var_a1;
                }
                var_v0_2 = var_s0 >> var_a1;
            }
            var_s0 = var_s0 + var_v0_2 + (var_s1 < (u32) var_v1);
            var_s1 += var_v1;
        }
        var_a1 += 1;
        var_v0 = var_a1 * 8;
    }
} while (var_a1 < 0x36);
    return func_800ABFA0(var_s0, var_s1, temp_a2, __repair_phase_storage.value) / D_800D6F28;
}
