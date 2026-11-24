extern u8 gInputBindingTables[];
s32 func_800819EC(s32 bank, s32 slot) {
    s32 offset = bank * 0xA0;
    u8 *base = gInputBindingTables + offset;
    volatile u8 *entry = base + slot * 2;
    s32 index = entry[1];
    u8 flags;
    if (index != 0) {
        s32 *values = (s32 *)(gInputBindingTables + 0x70 + index * 4 + offset);
        flags = entry[0];
        if (!(flags & 0x40)) {
            if (*values > 0)
                return *values;
        } else {
            if (*values < 0)
                return *values;
        }
    }
    entry = base + slot * 2;
    flags = entry[0];
    if (!(flags & 2))
        return 0;
    if (flags & 0x80) {
        entry[0] = flags & 0x7f;
        return 0;
    }
    return ((u32)-(s32)((flags & 0x20) != 0) << 16) | 0x10000;
}

extern void cordicSinCos(f64, f64 *, f64 *);
extern f64 D_800D6FE0, D_800D6FE8, D_800D6FF0, D_800D6FF8;

f64 func_800AB330(f64 x) {
    f64 sine, cosine;
    f64 turns = x / D_800D6FE0;
    f64 bias = D_800D6FE8;
    s32 n;
    if (x >= 0.0)
        bias = D_800D6FF0;
    n = (s32)(turns + bias);
    cordicSinCos(x - (f64)n * D_800D6FF8, &sine, &cosine);
    if (n & 1)
        cosine = -cosine;
    return cosine;
}

extern char D_A00FFFFC[], D_A0400000[];
u32 osGetMemSize(void) {
    u32 off = 0x400000;
    u32 upper = 0;
    do {
        volatile s32 *p = (volatile s32 *)(D_A0400000 + upper);
        s32 a = *p;
        s32 b = *(volatile s32 *)(D_A00FFFFC + off);
        s32 read;
        *p = ~*p;
        *(volatile s32 *)(D_A00FFFFC + off) = ~*(volatile s32 *)(D_A00FFFFC + off);
        read = *p;
        if (read != ~a)
            break;
        read = *(volatile s32 *)(D_A00FFFFC + off);
        if (read != ~b)
            break;
        *p = a;
        upper += 0x100000;
        *(volatile s32 *)(D_A00FFFFC + off) = b;
        off += 0x100000;
    } while (off <= 0x7fffffU);
    return off;
}

extern f32 gSinCosTable[];
typedef struct { f32 v[9]; } Matrix3;
void buildYzRotationMatrix(s16 *angle, Matrix3 *out) {
    s32 y = angle[1];
    s32 z = angle[2];
    f32 cy = gSinCosTable[y & 0xfff];
    f32 cz = gSinCosTable[z & 0xfff];
    f32 sz = gSinCosTable[(z - 0x400) & 0xfff];
    f32 m00 = cy * cz;
    f32 sy = gSinCosTable[(y - 0x400) & 0xfff];
    f32 m01 = -cy * sz;
    f32 m21 = sy * sz;
    f32 m20 = -cz * sy;
    out->v[5] = 0;
    out->v[2] = sy;
    out->v[3] = sz;
    out->v[4] = cz;
    out->v[8] = cy;
    out->v[0] = m00;
    out->v[7] = m21;
    out->v[1] = m01;
    out->v[6] = m20;
}
