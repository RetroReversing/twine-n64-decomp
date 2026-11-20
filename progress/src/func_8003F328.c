typedef struct {
    f32 x, y, z;
    s32 rest[6];
} ClipVertex;

extern f32 D_800C0740;
extern ClipVertex *D_800E1770;
extern ClipVertex D_800E1778[], D_800E1898[];
extern ClipVertex *D_800E19B8, *D_800E19BC, *D_800E19C0, *D_800E19C4;
extern s16 D_800E19C8, D_800E19CA, D_800E19CC, D_800E19CE, D_800E19D0, D_800E19D2;

s32 func_8003F328(s32 count)
{
    s32 i;
    s16 pass, remaining, in, out, prev;
    u8 outside[8];
    u8 *flag;
    f32 plane;

    D_800E19D2 = 0;
    D_800E19D0 = 0;
    D_800E19CE = 0;
    D_800E19CC = 0;
    D_800E19CA = 0;
    D_800E19C8 = 0;
    for (i = 0; i < count; i++) {
        f32 z = D_800E1778[i].z;
        if (z < 0.2f)
            D_800E19D0++;
        else if (D_800C0740 < z)
            D_800E19D2++;
    }
    if (D_800E19D0 + D_800E19D2 == 0) {
        D_800E1770 = D_800E1778;
        return count;
    }
    if (D_800E19D0 == count || D_800E19D2 == count)
        return 0;

    D_800E1770 = D_800E19B8 = D_800E1778;
    D_800E19BC = D_800E1898;
    for (pass = 0; pass < 2; pass++) {
        switch (pass) {
        default:
        case 0:
            if (!D_800E19D0) continue;
            plane = 0.2f;
            D_800E19C0 = D_800E19B8;
            flag = outside;
            for (remaining = count; remaining > 0;) {
                u8 value = D_800E19C0->z < plane;
                remaining--;
                *flag = value;
                D_800E19C0++;
                flag++;
            }
            break;
        case 1:
            if (!D_800E19D2) continue;
            plane = D_800C0740;
            D_800E19C0 = D_800E19B8;
            flag = outside;
            for (remaining = count; remaining > 0;) {
                u8 value = plane < D_800E19C0->z;
                remaining--;
                *flag = value;
                D_800E19C0++;
                flag++;
            }
            break;
        }
        out = 0;
        prev = count - 1;
        for (in = 0; in < count; in++) {
            if (outside[prev] != outside[in]) {
                if ((u16)pass < 2) {
                    s32 dstIndex = out;
                    s32 dstBase = (s32)D_800E19BC;
                    ClipVertex *dst = (ClipVertex *)(dstIndex * 36 + dstBase);
                    ClipVertex *cur = (ClipVertex *)(in * 36 + (s32)D_800E19B8);
                    ClipVertex *last = (ClipVertex *)(prev * 36 + (s32)D_800E19B8);
                    f32 fraction;
                    dst->z = plane;
                    fraction = (plane - cur->z) / (last->z - cur->z);
                    dst->x = cur->x + (last->x - cur->x) * fraction;
                    dst->y = cur->y + (last->y - cur->y) * fraction;
                }
                out++;
            }
            if (!outside[in]) {
                D_800E19BC[out] = D_800E19B8[in];
                out++;
            }
            prev = in;
        }
        { ClipVertex *tmp = D_800E19BC;
        D_800E19C4 = tmp;
        D_800E19BC = D_800E19B8;
        D_800E19B8 = tmp;
        }
        count = out;
    }
    D_800E1770 = D_800E19B8;
    return count;
}
