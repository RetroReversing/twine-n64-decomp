/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-schedule-insns, tried by autopilot */

s32 func_8008F2A4();
extern u8 D_800CF540;
extern char D_800E5AC4[];
extern char D_800E5FEC[];
extern u8 D_800E6A85[];

void func_80091970(s32 arg0, s32 arg1, s8 arg2) {
    s32 var_a0;
    s32 var_v1;
    u32 var_a3;

    if (D_800CF540) {
        var_a3 = 0;
        var_v1 = 0;
loop_2:
        if (*(D_800E6A85 + var_v1) != 0) {
            var_a3 += 1;
            goto block_9;
        }
        if (*(s32 *)(D_800E5AC4 + var_v1) == (arg0 & (short)0x7FFFFFFF)) {
            var_a0 = var_a3 | (arg0 & 0x7fffffff);
        } else {/*__repair_loop_weight*/__repair_rows: {do {do {
            var_a3 += 1;} while (0);} while (0);}
if (0) goto __repair_rows;
block_9:
            var_v1 += 0xFF8;
            if (8U <= var_a3) {
                var_a0 = -1;
            } else {
                goto loop_2;
            }
        }
        if (var_a0 != -1) {
            *((var_a0 * 0xFF8) + D_800E5FEC + (arg1 & 0xFF)) = arg2;
            func_8008F2A4(arg2 & 0xFF, 2);
        }
    }
}
