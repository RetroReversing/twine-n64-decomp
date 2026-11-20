/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern int D_801002B8;
extern int D_801002BC;
typedef struct { u8 f0; u8 pad[23]; } Slot_801001A1;
extern Slot_801001A1 D_801001A1[];

s32 func_80019A3C(void) {
    int *__base_D_801002B8;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a3;
    s32 var_v0;
    s32 var_t0;
    s32 var_v0_2;
var_t0 = 0;
var_a3 = 0;
loop_1:
    var_a0 = 0;
    __base_D_801002B8 = &D_801002B8;
    if (0 < (*__base_D_801002B8)) {
        var_v0 = 0 & 0xFFFF;
        for (;;) {
            if (D_801001A1[(unsigned char)var_v0].f0 == (var_a3 & 0xFFFF)) {
                var_t0 = 1;
            } else {
                ++var_a0;
                var_v0 = var_a0 & 0xFFFF;
                if ((var_a0 & 0xFFFF) < (*(&D_801002B8))) {
                    continue;
                }
            }
            break;
        }
    }
    var_a0_2 = 0;
    if (D_801002BC > 0) {
        var_v0_2 = 0 & 0xFFFF;
loop_9:
        var_a0_2 += 1;
        if (D_801001A1[var_v0_2 + 4].f0 != (var_a3 & (short)0xFFFF)) {
            var_v0_2 = var_a0_2 & 0xFFFF;
            if ((var_a0_2 & 0xFFFF) < D_801002BC) {
                goto loop_9;
            }
        } else {
            var_t0 = 1;
        }
    }
    if (var_t0 & 0xFFFF) {
        ++var_a3;
        var_t0 = 0;
        if ((u32) (var_a3 & 0xFFFF) >= 2U) {
            return 1;
        }
        goto loop_1;
    }
    return 0;
}
