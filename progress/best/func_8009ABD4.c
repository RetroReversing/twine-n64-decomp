/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s16 func_80096E7C();
s32 func_80096F44();
extern char D_80112E9E[];

s32 func_8009ABD4(s32 arg0, void *arg1, s32 arg2) {
    s16 var_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_4;
    u32 temp_v1_6;
    s32 var_s0;
    u32 temp_v0_3;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 temp_v1_7;
    u32 temp_v1_4;
    u32 temp_v1_5;
    short var_a2;
    u32 temp_v1_3;
    u32 var_a0;
    u32 var_v1;

    temp_v0_3 = (*(u32 *)((char *)(arg1) + 4));
    if ((*(u8 *)((char *)(arg1) + 0)) != 0) {
        var_s1 = func_80096E7C(arg0, temp_v0_3 & 0xFF);
    } else {
        temp_v1_6 = temp_v0_3 & 0x1F;
        temp_v0 = temp_v1_6 * 2;
        if (temp_v1_6 < 0x10U) {
            var_s1 = (*(s16 *)((char *)((temp_v0 + arg0)) + 0x180));
        } else {
            var_s1 = *(s16 *)(D_80112E9E + temp_v0);
        }
    }
    var_v1 = arg2 & 0xFF;
    if (var_v1 == 4) {
        var_a0 = (u32) (*(u32 *)((char *)(arg1) + 4)) >> 8;
    } else {
        temp_v1_3 = (*(u32 *)((char *)(arg1) + 4));
        temp_v1_4 = temp_v1_3 >> 0x10;
        if ((temp_v1_3 >> 8) & 0xFF) {
            var_a0 = func_80096E7C(arg0, temp_v1_4 & 0xFF);
        } else {
            temp_v0_3 = temp_v1_4 & 0x1F;
            temp_v0_2 = temp_v0_3 * 2;
            if (temp_v0_3 < 0x10U) {
                var_a0 = (u32) (*(s16 *)((char *)((temp_v0_2 + arg0)) + 0x180));
            } else {
                var_a0 = (u32) *(s16 *)(D_80112E9E + temp_v0_2);
            }
        }
        var_v1 = arg2 & 0xFF;
    }
    switch (var_v1) {
    case 0:
    case 4:
        var_s0 = var_s1 + (s16) var_a0;
        break;
    case 1:
        var_s0 = var_s1 - (s16) var_a0;
        break;
    case 2:
        var_s0 = var_s1 * (s16) var_a0;
        break;
    case 3:
        if ((s16) var_a0 != 0) {
            /*__repair_loop_weight*/
            var_s0 = var_s1 / (s16) var_a0;
            
        } else {
            var_s0 = 0;
        }
        break;
    }
    temp_v0_3 = (u32) (*(u8 *)((char *)(arg1) + 0));
    temp_v1_6 = temp_v0_3 >> 0x10;
    if (var_s0 < -0x8000) {
        var_a2 = -0x8000;
    } else {
        var_a2 = 0x7FFF;
        if (var_s0 <= 0x7FFF) {
            var_a2 = var_s0;
        }
    }
    if ((temp_v0_3 >> 8) & 0xFF) {
        func_80096F44(arg0, temp_v1_6 & 0xFF, (s16) var_a2);
        return 0;
    }
    temp_v1_7 = (temp_v0_3 >> 0x10) & 0x1F;
    temp_v0_4 = temp_v1_7 * 2;
    if (temp_v1_7 < 0x10U) {
        (*(s16 *)((char *)(((short)temp_v0_4 + arg0)) + 0x180)) = (s16) var_a2;
    } else {
        *(s16 *)(D_80112E9E + (short)temp_v0_4) = (s16) var_a2;
    }
    return 0;
}
