typedef struct {
    char pad_head[0x18A];
    s16 a;
    s16 b;
    char pad_a[0x12];
    u32 buf[0x400];
    char pad1[0x28];
    s32 pos;
} Reader;
s32 func_800A0FA0(void *, s32);
s32 func_8009DBE8(Reader *, s16 *, s16 *, s16 *, s16 *, s16 *, s16 *, void *);
#define GETBITS(dst, n) \
    if (avail > (n)) { \
        (dst) = w & ((1 << (n)) - 1); \
        w >>= (n); \
        avail -= (n); \
    } else { \
        pos += 32; \
        (dst) = w & ((1 << avail) - 1); \
        w = p->buf[(pos >> 5) & 0x3ff]; \
        if (avail != (n)) { \
            (dst) |= (w & ((1 << ((n) - avail)) - 1)) << avail; \
        } \
        w >>= (n) - avail; \
        avail += 32 - (n); \
    }

s32 func_8009DF60(Reader *p, void *arg1) {
    s16 spE8[8];
    s16 spE0[4];
    s16 spD8[4];
    s16 spD0[4];
    s16 spC8[4];
    s16 sp60[4][13];
    s32 unused0;
    s32 avail;
    u32 w;
    s32 pos;
    s32 unused1;
    s32 i;

    pos = p->pos;
    w = p->buf[(pos >> 5) & 0x3ff] >> (pos & 0x1f);
    avail = 32 - (pos & 0x1f);
    if (p->a == 0 && p->b == 0) {
        GETBITS(i, 1);
        if (i != 0) {
            GETBITS(p->b, 4);
            p->b++;
        } else {
            GETBITS(p->a, 7);
            p->a++;
        }
    }
    if (p->b != 0) {
        func_800A0FA0(arg1, 0x140);
        p->b--;
    } else {
        GETBITS(spE8[0], 6);
        GETBITS(spE8[1], 6);
        GETBITS(spE8[2], 5);
        GETBITS(spE8[3], 5);
        GETBITS(spE8[4], 4);
        GETBITS(spE8[5], 4);
        GETBITS(spE8[6], 3);
        GETBITS(spE8[7], 3);
        for (i = 0; i < 4; i++) {
            GETBITS(spE0[i], 7);
            GETBITS(spD0[i], 2);
            GETBITS(spD8[i], 2);
            GETBITS(spC8[i], 6);
            GETBITS(sp60[i][0], 3);
            GETBITS(sp60[i][1], 3);
            GETBITS(sp60[i][2], 3);
            GETBITS(sp60[i][3], 3);
            GETBITS(sp60[i][4], 3);
            GETBITS(sp60[i][5], 3);
            GETBITS(sp60[i][6], 3);
            GETBITS(sp60[i][7], 3);
            GETBITS(sp60[i][8], 3);
            GETBITS(sp60[i][9], 3);
            GETBITS(sp60[i][10], 3);
            GETBITS(sp60[i][11], 3);
            GETBITS(sp60[i][12], 3);
        }
        p->a--;
        func_8009DBE8(p, spE8, spE0, spD0, spD8, spC8, sp60[0], arg1);
    }
    p->pos = (pos & ~0x1f) - avail + 32;
    return 0;
}
