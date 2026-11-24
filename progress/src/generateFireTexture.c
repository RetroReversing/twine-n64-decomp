u32 randomU32Next();
extern s32 gFireX;
extern s32 gFireY;
extern s32 gFireWidth;
extern s32 gFireHeight;
extern s32 D_800E1574;
extern s32 D_800E1578;
extern s32 D_800E157C;
extern s32 D_800E1580;

typedef struct { s32 a; s32 b; } TmpPair;

/* Fills an 8-bit texture with random seed pixels, then smooths it by averaging four neighbours (wrapping) per pixel. */ void generateFireTexture(s8 *image, u16 *seedCount, u16 *fixedPos) {
    u8 *pixels;
    TmpPair *pa;
    s32 *pb;
    s32 *p;
    s32 a, t, v, x, y, r1, r2, c, q, q2, z;

    if (image == NULL) {
        return;
    }
    pixels = *(u8 **)(image + 8);
    gFireWidth = *(u16 *)(image + 0x24);
    gFireHeight = *(u8 *)(image + 0x28);
    *(&D_800E157C + 1) = 0;
    if (*seedCount != 0) {
        p = &D_800E157C;
        do {
            if (*fixedPos == 0) {
                a = (gFireWidth >> 2) + randomU32Next() % (u32)(gFireWidth >> 1);
            } else {
                a = *seedCount;
            }
            gFireX = a;
            gFireY = (randomU32Next() & 3) + 0x1C;
            p[0] = randomU32Next() % 255 - 0x80;
            pixels[gFireX + gFireY * gFireWidth] = p[0] = (p[0] + (s8)pixels[gFireX + gFireY * gFireWidth]) >> 1;
            p[1]++;
        } while (p[1] < *seedCount);
    }
    for (gFireY = 0; gFireY < gFireHeight; gFireY++) {
        pa = (TmpPair *)&D_800E157C;
        pb = &pa->b;
        t = gFireY + 1;
        if (gFireY >= 0x1D) {
            t = gFireY - 1;
        }
        D_800E1574 = t;
        if (t < 0) {
            q = t - 1;
            v = q + gFireHeight;
        } else if (t <= gFireHeight - 1) {
            v = t;
        } else {
            q2 = t + 1;
            v = q2 - gFireHeight;
        }
        D_800E1574 = v;
        for (gFireX = 0; gFireX < gFireWidth; gFireX++) {
            if (gFireWidth >> 1 < gFireX) {
                x = gFireX - 1;
            } else {
                x = gFireX + 1;
            }
            D_800E1578 = x;
            if (x < 0) {
                y = x + gFireWidth;
            } else {
                y = x;
                if (gFireWidth < y) {
                    y -= gFireWidth;
                }
            }
            c = gFireX;
            r1 = D_800E1574 * gFireWidth;
            r2 = gFireY * gFireWidth;
            D_800E1578 = y;
            pa->a = pixels[y + r1];
            pa->a += pixels[y + r2];
            pa->a += pixels[c + r1];
            pa->a += pixels[c + r2];
            z = (u32)((f32)pa->a * 0.24691357f);
            *pb = (u8)z;
            pixels[gFireX + gFireY * gFireWidth] = *pb;
        }
    }
}
