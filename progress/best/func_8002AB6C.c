typedef struct { u8 pad[9]; u8 w; u8 pad2[2]; } E2A;
typedef struct { E2A *e; u8 pad[0x14]; u8 x18; u8 x19; u8 x1A; u8 x1B; u8 x1C; u8 x1D; u8 x1E; } T2A;

s32 func_8002AB6C(T2A *t) {
    s16 i;
    s16 sum;
    s32 r;

    if (t == NULL) {
        return 0;
    }
    if (t->x18 == t->x19 - 1) {
        return 1;
    }
    sum = 0;
    for (i = t->x18; i < t->x19; i++) {
        sum += t->e[i].w;
    }
    r = 0;
    if (t->x1E == 0) {
        r = sum <= t->x1B;
    }
    return r;
}
