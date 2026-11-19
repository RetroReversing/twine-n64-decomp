/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80098A18();
extern char D_80102CE0[];
extern u8 D_8010957D[];
extern u16 D_80109B1C;
extern char D_8010A51A[];
extern char D_8010A51C[];

void func_80098B14(void *arg0, u8 arg1) {
    unsigned long temp_a2;
    unsigned temp_v0_2;
    
    s32 temp_v1;
    u32 temp_v1_2;
    register s32 var_v0;
    register u16 temp_a1;
    s32 var_a0;
    s32 var_s2;
    register u32 temp_a0;
    u32 temp_a3;
    u32 var_v1;
    u8 temp_s4;
    u8 temp_v0;
    union { void * pointer; s32 value; } __repair_phase_storage;

    temp_s4 = (*(u8 *)((char *)(arg0) + 0x63));
    __repair_phase_storage.pointer = (temp_s4 * 4) + D_80102CE0;
    if ((*(u16 *)((char *)(__repair_phase_storage.pointer) + 2)) == 1) {
        if ((*(u8 *)((char *)(arg0) + 0x2E)) != (arg1 & 0xFF)) {
            func_80098A18();
            goto block_3;
        }
    } else {
block_3:
        (*(u16 *)((char *)(__repair_phase_storage.pointer) + 2)) = 1U;
        (*(u8 *)((char *)(__repair_phase_storage.pointer) + 0)) = 0xFF;
        temp_a2 = arg1 & 0xFF;
        temp_v0 = *(D_8010957D + temp_a2);
        (*(u8 *)((char *)(__repair_phase_storage.pointer) + 1)) = temp_v0;
        if ((temp_v0 & 0xFF) != 0xFF) {
            var_v0 = arg1 & 0xFF;
            *(D_80102CE0 + (*(D_8010957D + temp_a2) * 4)) = ((*(u8 *)((char *)(arg0) + 0x63)));
        } else {
            temp_a0 = D_80109B1C & 0xFFFF;
            temp_a1 = arg1 & 0xFF;
            if (temp_a0 != 0xFFFF) {
                temp_v0_2 = temp_a2 * 4;
                temp_a3 = temp_a1 & 0xFFFF;
                if (temp_a0 <= temp_a3) {
                    var_a0 = D_80109B1C;
                    var_v1 = var_a0 & 0xFFFF;
loop_8:
                    if (temp_a3 >= var_v1) {
                        var_a0 = *(u16 *)(D_8010A51A + (var_v1 * 4));
                        var_s2 = var_a0;
                        var_v1 = var_a0 & 0xFFFF;
                        if (var_a0 != 0xFFFF) {
                            goto loop_8;
                        }
                    }
                    *(u16 *)(D_8010A51A + ((var_s2 & 0xFFFF) * 4)) = temp_a1;
                    __repair_phase_storage.value = (arg1 & 0xFF) * 4;
                    temp_v1 = var_a0 & 0xFFFF;
                    *(s16 *)(D_8010A51C + __repair_phase_storage.value) = var_s2;
                    *(u16 *)(D_8010A51A + __repair_phase_storage.value) = var_a0;
                    if (temp_v1 != 0xFFFF) {
                        *(s16 *)(D_8010A51C + (temp_v1 * 4)) = temp_a1;
                        var_v0 = arg1 & 0xFF;
                    } else {
                        goto block_14;
                    }
                } else {
                    *(u16 *)(D_8010A51A + temp_v0_2) = D_80109B1C;
                    *(s16 *)(D_8010A51C + temp_v0_2) = 0xFFFF;
                    *(s16 *)(D_8010A51C + (temp_a0 * 4)) = temp_a1;
                    D_80109B1C = temp_a1;
                    var_v0 = arg1 & 0xFF;
                }
            } else {
                temp_a2 = temp_a2 * 4;
                *(u16 *)(D_8010A51A + temp_a2) = 0xFFFF;
                *(s16 *)(D_8010A51C + (int)temp_a2) = 0xFFFF;
                D_80109B1C = arg1 & 0xFF;
block_14:
                var_v0 = arg1 & 0xFF;
            }
        }
        *(D_8010957D + var_v0) = temp_s4;
        (*(u8 *)((char *)(arg0) + 0x2E)) = arg1;
    }
}
