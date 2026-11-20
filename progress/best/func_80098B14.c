extern u8 D_80102CE0[];
extern u8 D_8010957D[];
extern u16 D_80109B1C;
extern u16 D_8010A51A[];
extern u16 D_8010A51C[];
s32 func_80098A18();

void func_80098B14(u8 *arg0, u8 arg1) {
int __repair_literal;

    u8 temp_s4;
    union { u8 * pointer; u32 value; } __repair_phase_storage;
    u8 v;
    u16 a0;
    u16 s2;
    
    u32 v1;
    u8 t;

    temp_s4 = arg0[0x63];
    __repair_phase_storage.pointer = D_80102CE0 + temp_s4 * 4;
    if (*(u16 *)(__repair_phase_storage.pointer + 2) == 1) {
        if (arg0[0x2E] != arg1) {
            func_80098A18();
            goto block_3;
        }
    } else {
block_3:
        *(u16 *)(__repair_phase_storage.pointer + 2) = 1;
        __repair_phase_storage.pointer[0] = 0xFF;
        t = D_8010957D[arg1];
        __repair_phase_storage.pointer[1] = t;
        if (t != 0xFF) {
__repair_literal = 4;

            D_80102CE0[D_8010957D[arg1] * __repair_literal] = (arg0[0x63]);
            v = arg1;
        } else {
            u16 a1 = arg1;
            if (D_80109B1C != 0xFFFF) {
                __repair_phase_storage.value = a1;
                if (__repair_phase_storage.value >= D_80109B1C) {
                    a0 = D_80109B1C;
                    v1 = a0;
                    for (;;) {
                        if (__repair_phase_storage.value >= v1) {
                            s2 = a0;
                            a0 = D_8010A51A[v1 * 2];
                            v1 = a0;
                            if (a0 != 0xFFFF) continue;
                        }
                        break;
                    }
                    D_8010A51A[s2 * 2] = a1;
                    D_8010A51C[arg1 * 2] = s2;
                    D_8010A51A[arg1 * 2] = a0;
                    if (a0 != 0xFFFF) {
                        D_8010A51C[a0 * 2] = a1;
                        v = arg1;
                    } else {
                        goto block_14;
                    }
                } else {
                    D_8010A51A[arg1 * 2] = D_80109B1C;
                    D_8010A51C[arg1 * 2] = 0xFFFF;
                    D_8010A51C[D_80109B1C * 2] = a1;
                    D_80109B1C = a1;
                    v = arg1;
                }
            } else {
                D_8010A51A[arg1 * 2] = 0xFFFF;
                D_8010A51C[arg1 * 2] = 0xFFFF;
                D_80109B1C = arg1;
block_14:
                v = arg1;
            }
        }
        D_8010957D[v] = temp_s4;
        arg0[0x2E] = arg1;
    }
}
