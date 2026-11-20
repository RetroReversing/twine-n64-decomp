extern u8 D_80102CE0[];
extern u8 D_8010957D[];
extern u16 D_80109B1C;
extern u16 D_8010A51A[];
extern u16 D_8010A51C[];
s32 func_80098A18();

void func_80098B14(u8 *arg0, u8 arg1) {
    u8 temp_s4;
    u8 *temp_s0;
    u8 v;
    u16 a0;
    u16 s2;
    u32 a3;
    u32 v1;
    u8 t;

    temp_s4 = arg0[0x63];
    temp_s0 = D_80102CE0 + temp_s4 * 4;
    if (*(u16 *)(temp_s0 + 2) == 1) {
        if (arg0[0x2E] != arg1) {
            func_80098A18();
            goto block_3;
        }
    } else {
block_3:
        *(u16 *)(temp_s0 + 2) = 1;
        temp_s0[0] = 0xFF;
        t = D_8010957D[arg1];
        temp_s0[1] = t;
        if (t != 0xFF) {
            D_80102CE0[D_8010957D[arg1] * 4] = temp_s4;
            v = arg1;
        } else {
            u16 a1 = arg1;
            if (D_80109B1C != 0xFFFF) {
                a3 = a1;
                if (a3 >= D_80109B1C) {
                    a0 = D_80109B1C;
                    v1 = a0;
loop_8:
                    if (a3 >= v1) {
                        s2 = a0;
                        a0 = D_8010A51A[v1 * 2];
                        v1 = a0;
                        if (a0 != 0xFFFF) goto loop_8;
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
