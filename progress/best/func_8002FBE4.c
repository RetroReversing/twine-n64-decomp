/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern int D_800E157C;
extern int D_800E1580;
u32 func_80045CC4();
extern s32 D_800E1564;
extern s32 D_800E1568;
extern s32 D_800E156C;
extern s32 D_800E1570;
extern s32 D_800E1574;
extern s32 D_800E1578;

void func_8002FBE4(s8 *arg0, u16 *arg1, u16 *arg2) {
int __repair_literal;

    register f32 temp_fv1;
    union { s32 * pointer; s32 value; } __repair_phase_storage;
    s32 temp_lo;
    
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    s8 *var_a0;
    u16 *temp_s2;
    u16 *var_a1;
    u16 var_a0_2;
    u8 temp_v1;

    var_a0 = arg0;
    var_a1 = arg1;
    temp_s2 = var_a1;
    if (var_a0 != NULL) {
        temp_s0 = (*(s32 *)((char *)(var_a0) + 8));
        D_800E156C = (s32) (*(u16 *)((char *)(var_a0) + 0x24));
        D_800E1580 = 0;
        D_800E1570 = (s32) (*(u8 *)((char *)(var_a0) + 0x28));
        if (*temp_s2 != 0) {
            __repair_phase_storage.pointer = &D_800E1580 - 4;
            do { {
                if (*arg2 == 0) {
                    var_a0_2 = ((s32) D_800E156C >> 2) + (func_80045CC4((s32) var_a0, (s32) var_a1) % (u32) ((s32) D_800E156C >> 1));
                } else {/*__repair_loop_weight*/do {
                    var_a0_2 = *temp_s2;} while (0);
                }
                D_800E1564 = (s32) var_a0_2;
                D_800E1568 = (func_80045CC4((s32) var_a0_2) & 3) + 0x1C;
                var_a1 = (u16 *) (D_800E1568 * D_800E156C);
                temp_v0_2 = (func_80045CC4() % 255) - 0x80;
                var_a0 = (char *)(temp_s0); var_a0 += (s32)((D_800E1564 + (s32)var_a1));
                (*(s32 *)((char *)(__repair_phase_storage.pointer) + 0)) = temp_v0_2;
                temp_v0_3 = (s32) (temp_v0_2 + *var_a0) >> 1;
                (*(s32 *)((char *)(__repair_phase_storage.pointer) + 0)) = temp_v0_3;
                *var_a0 = (s8) temp_v0_3;
                temp_v0 = (*(s32 *)((char *)(__repair_phase_storage.pointer) + 4)) + 1;
                (*(s32 *)((char *)(__repair_phase_storage.pointer) + 4)) = temp_v0;
            }
} while (temp_v0 < (s32) *temp_s2);
        }
        D_800E1568 = 0;
        if (D_800E1570 > 0) {
            do {
                var_a0_3 = D_800E1568 + 1;
                if (0x1D <= D_800E1568) {
                    var_a0_3 = D_800E1568 - 1;
                }
                D_800E1574 = var_a0_3;
                if (var_a0_3 < 0) {
                    var_v0 = var_a0_3 - 1 + D_800E1570;
                } else if (((unsigned short)D_800E1570 - 1) >= (unsigned short)var_a0_3) {
                    var_v0 = var_a0_3;
                } else {
                    var_v0 = (var_a0_3 + 1) - D_800E1570;
                }
                D_800E1574 = var_v0;
                D_800E1564 = 0;
__repair_literal = 0;

                if (D_800E156C > __repair_literal) {
                    do {
                        if (((s32) D_800E156C >> 1) >= D_800E1564) {
                            var_v1 = D_800E1564 + 1;
                        } else {
                            var_v1 = D_800E1564 - 1;
                        }
                        D_800E1578 = var_v1;
                        var_a0_4 = var_v1;
                        if (var_v1 < 0) {
                            var_a0_4 = var_v1 + D_800E156C;
                        } else if (D_800E156C < var_a0_4) {
                            var_a0_4 -= D_800E156C;
                        }
                        temp_lo = D_800E1574 * D_800E156C;
                        D_800E1578 = var_a0_4;
                        temp_v0_2 = (u8)(*(u8 *)(temp_s0 + (var_a0_4 + temp_lo)));
                        __repair_phase_storage.value = D_800E1568 * D_800E156C;
                        D_800E157C = (s32) temp_v0_2;
                        temp_v1_2 = temp_v0_2 + *(s32 *)(temp_s0 + (var_a0_4 + __repair_phase_storage.value));
                        D_800E157C = temp_v1_2;
                        temp_v1_3 = temp_v1_2 + *(s32 *)(temp_s0 + (D_800E1564 + temp_lo));
                        D_800E157C = temp_v1_3;
                        temp_v1_4 = temp_v1_3 + *(s32 *)(temp_s0 + (D_800E1564 + __repair_phase_storage.value));
                        temp_fv1 = (f32) temp_v1_4 * 0.24691357f;
                        D_800E157C = temp_v1_4;
                        if (!(temp_fv1 >= 2.1474836e9f)) {
                            var_v1_2 = temp_fv1;
                        } else {
                            var_v1_2 = (s32) (temp_fv1 - 2.1474836e9f) | 0x80000000;
                        }
                        var_v1 = var_v1_2 & 0xFF;
    temp_v1_5 = var_v1;
                        D_800E1580 = temp_v1_5;
                        temp_v0_5 = D_800E1564 + 1;
                        *(s32 *)(temp_s0 + (D_800E1564 + (D_800E1568 * D_800E156C))) = (s8) temp_v1_5;
                        D_800E1564 = temp_v0_5;
                    } while (D_800E156C > temp_v0_5);
                }
                temp_v0_4 = D_800E1568 + 1;
                D_800E1568 = temp_v0_4;
            } while (D_800E1570 > temp_v0_4);
        }
    }
}
