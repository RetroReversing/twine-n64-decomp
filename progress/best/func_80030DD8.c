/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80030D40();
extern s32 D_800BFF04;
extern s32 D_800BFF10;
extern u16 D_800E1608;

void func_80030DD8(u16 arg0, s32 arg1, void *arg2, u16 arg3) {
    void *__repair_D_800E1608;
    unsigned long temp_v0;
    unsigned int var_a1;
    s32 var_a1_2;
    u32 var_a1_3;
    s32 var_v0;
    s32 var_v0_2;
    int var_v1;
    register s32 temp_s0;
    u16 temp_v1_2;
    u16 var_a0;
    u16 var_a3;
    void *temp_v1;
    

    var_a0 = arg0;
    temp_v1 = arg2;
    var_a3 = arg3;
    temp_s0 = var_a0;
    switch (temp_s0) {
    case 8:
        var_a1 = 0;
        if (D_800E1608 != 0) {
            var_a3 = D_800E1608;
            var_v0 = 0 & 0xFFFF;
            __repair_rows: {
                temp_v1 = (var_v0 * 8) + D_800BFF04;
                var_a0 = (*(u16 *)((char *)(temp_v1) + 2));
                var_a1 += 1;
                if (((u32) (var_a0 & 0xF0) >> 4) == (var_a0 & 0xF)) {
                    (*(u16 *)((char *)(temp_v1) + 2)) = (u16) ((var_a0 & 0xFFF0) | 1);
                }
                var_v0 = var_a1 & 0xFFFF;
            }
if ((u32) (var_a1 & 0xFFFF) < var_a3) goto __repair_rows;
        }
        temp_v0 = func_80030D40(var_a0, var_a1);
        D_800BFF10 = temp_v0;
        if (temp_v0 == 6) {
            func_80030DD8(4, arg1, arg2, arg3);
            return;
        }
    default:
        return;
    case 5:
        D_800BFF10 = (s32) temp_s0;
        if (D_800BFF04 != 0) {
            var_a1_2 = 0;
            __repair_D_800E1608 = D_800E1608;
            if (__repair_D_800E1608 != 0) {
                var_v1 = 0 & 0xFFFF;
                do {
                    temp_v1 = (var_v1 * 8) + D_800BFF04;
                    var_a1_2 += 1;
                    (*(u16 *)((char *)(temp_v1) + 2)) = (u16) (((*(u16 *)((char *)(temp_v1) + 2)) & (unsigned)0xFFF0) | 1);
                    var_v1 = var_a1_2 & 0xFFFF;
                } while ((u32) (var_a1_2 & 0xFFFF) < (u16) __repair_D_800E1608);
                return;
            }
        }
        break;
    case 4:
    case 9:
        var_a1_3 = 0;
        if (__repair_D_800E1608 != 0) {
            var_a3 = __repair_D_800E1608;
            var_v0_2 = 0 & 0xFFFF;
            do {
                temp_v1 = (var_v0_2 * 8) + D_800BFF04;
                temp_v1_2 = (*(u16 *)((char *)(temp_v1) + 2));
                var_a0 = temp_v1_2 & 0xF;
                if ((((int)var_a0 != 0) || (temp_v1_2 & 0xF0)) && ((short)var_a0 != 1)) {
                    (*(u16 *)((char *)(temp_v1) + 2)) = (u16) ((temp_v1_2 & 0xFFF0) | 2);
                }
                var_a1_3 += 1;
                var_v0_2 = var_a1_3 & 0xFFFF;
            } while ((u32) (var_a1_3 & 0xFFFF) < var_a3);
        }
        D_800BFF10 = func_80030D40(var_a0, var_a1_3, temp_v1);
        /* fallthrough */
    case 7:
        D_800BFF10 = (s32) temp_s0;
        break;
    }
}
