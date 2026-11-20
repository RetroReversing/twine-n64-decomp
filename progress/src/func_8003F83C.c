s32 func_8003EC70(s32);
extern void *D_800E1770;
extern char D_800E1778[];
extern char D_800E177C[];
extern char D_800E1780[];
#define FIELD(p, offset) (*(f32 *)((char *)(p) + (offset)))

s32 func_8003F83C(void *arg0, void *arg1, s32 arg2) {
    f32 z;
    f32 one;
    s32 count;
    s32 i;
    s32 offset;
    char *out;
    char *in;
    char *clipped;
    char frame[16];

    in = arg1;
    i = 0;
    if (arg2 > 0) {
        one = 1.0f;
        offset = 0;
        do {
            *(f32 *)(D_800E1778 + offset) = FIELD(in, 0);
            *(f32 *)(D_800E177C + offset) = FIELD(in, 4);
            z = one / FIELD(in, 8);
            i++;
            in += 0x24;
            *(f32 *)(D_800E1780 + offset) = z;
            offset += 0x24;
        } while (i < arg2);
    }
    count = func_8003EC70(arg2);
    i = 0;
    if (count > 0) {
        one = 1.0f;
        out = arg0;
        clipped = D_800E1770;
        do {
            FIELD(out, 0) = FIELD(clipped, 0);
            FIELD(out, 4) = FIELD(clipped, 4);
            z = one / FIELD(clipped, 8);
            i++;
            clipped += 0x24;
            FIELD(out, 8) = z;
            out += 0x24;
        } while (i < count);
    }
    return count;
}
