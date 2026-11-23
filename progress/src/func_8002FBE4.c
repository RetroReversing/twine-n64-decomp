u32 randomU32Next();
extern s32 D_800E1564;
extern s32 D_800E1568;
extern s32 D_800E156C;
extern s32 D_800E1570;
extern s32 D_800E1574;
extern s32 D_800E1578;
extern s32 D_800E157C;
extern s32 D_800E1580;

typedef struct { s32 a; s32 b; } TmpPair;

void func_8002FBE4(s8 *arg0, u16 *arg1, u16 *arg2) {
    u8 *buf;
    TmpPair *pa;
    s32 *pb;
    s32 *p;
    s32 a, t, v, x, y, r1, r2, c, q, q2, z;

    if (arg0 == NULL) {
        return;
    }
    buf = *(u8 **)(arg0 + 8);
    D_800E156C = *(u16 *)(arg0 + 0x24);
    D_800E1570 = *(u8 *)(arg0 + 0x28);
    *(&D_800E157C + 1) = 0;
    if (*arg1 != 0) {
        p = &D_800E157C;
        do {
            if (*arg2 == 0) {
                a = (D_800E156C >> 2) + randomU32Next() % (u32)(D_800E156C >> 1);
            } else {
                a = *arg1;
            }
            D_800E1564 = a;
            D_800E1568 = (randomU32Next() & 3) + 0x1C;
            p[0] = randomU32Next() % 255 - 0x80;
            buf[D_800E1564 + D_800E1568 * D_800E156C] = p[0] = (p[0] + (s8)buf[D_800E1564 + D_800E1568 * D_800E156C]) >> 1;
            p[1]++;
        } while (p[1] < *arg1);
    }
    for (D_800E1568 = 0; D_800E1568 < D_800E1570; D_800E1568++) {
        pa = (TmpPair *)&D_800E157C;
        pb = &pa->b;
        t = D_800E1568 + 1;
        if (D_800E1568 >= 0x1D) {
            t = D_800E1568 - 1;
        }
        D_800E1574 = t;
        if (t < 0) {
            q = t - 1;
            v = q + D_800E1570;
        } else if (t <= D_800E1570 - 1) {
            v = t;
        } else {
            q2 = t + 1;
            v = q2 - D_800E1570;
        }
        D_800E1574 = v;
        for (D_800E1564 = 0; D_800E1564 < D_800E156C; D_800E1564++) {
            if (D_800E156C >> 1 < D_800E1564) {
                x = D_800E1564 - 1;
            } else {
                x = D_800E1564 + 1;
            }
            D_800E1578 = x;
            if (x < 0) {
                y = x + D_800E156C;
            } else {
                y = x;
                if (D_800E156C < y) {
                    y -= D_800E156C;
                }
            }
            c = D_800E1564;
            r1 = D_800E1574 * D_800E156C;
            r2 = D_800E1568 * D_800E156C;
            D_800E1578 = y;
            pa->a = buf[y + r1];
            pa->a += buf[y + r2];
            pa->a += buf[c + r1];
            pa->a += buf[c + r2];
            z = (u32)((f32)pa->a * 0.24691357f);
            *pb = (u8)z;
            buf[D_800E1564 + D_800E1568 * D_800E156C] = *pb;
        }
    }
}
