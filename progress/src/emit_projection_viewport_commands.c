typedef struct Link798C Link798C;
struct Link798C { Link798C *next; };
Link798C *func_800A798C(Link798C **head) {
    Link798C *prev = *head;
    *head = prev->next;
    return prev;
}

typedef struct Entry989 Entry989;
struct Entry989 {
    Entry989 *next;
    u32 unk4;
    u32 key;
    s32 value;
};
extern Entry989 *D_800FDB74;
s32 func_800989B8(u32 key) {
    Entry989 *p, *found;
    if (key == (u32)-1)
        return -1;
    p = D_800FDB74;
    found = NULL;
    if (p != NULL) {
        do {
            if (p->key == key) {
                found = p;
                break;
            }
            if (key < p->key) {
                found = NULL;
                break;
            }
            p = p->next;
        } while (p != NULL);
    }
    if (found == NULL)
        return -1;
    return found->value;
}

typedef struct { u32 w0, w1; } Gfx38;
extern Gfx38 * volatile D_80115328;
extern u32 D_800E1710;
extern u8 *D_80117728;
void emit_projection_viewport_commands(void) {
    Gfx38 *g = D_80115328;
    u32 index = D_800E1710;
    u8 *base = D_80117728;
    u32 offset = index << 6;
    g[0].w0 = 0xda380007;
    g[0].w1 = (u32)(base + offset) - 0x80000000u;
    g[1].w0 = 0xda380005;
    g[1].w1 = (u32)(base + (offset + 0x180)) - 0x80000000u;
    g[2].w0 = 0xdc080008;
    g[2].w1 = (u32)(base + ((index << 4) + 0x300));
    g[3].w0 = 0xdb0e0000;
    {
        u16 fog = *(volatile u16 *)(((index << 1) + (u32)base) + 0x360);
        D_80115328 = g + 1;
        D_80115328 = g + 2;
        D_80115328 = g + 3;
        D_80115328 = g + 4;
        g[3].w1 = fog;
    }
}

extern f32 *D_800D93C0, *D_800D93CC, *D_800D93D8, *D_800D9404, *D_800D9408;
f32 func_8000550C(void *a, s32 i, s32 kind) {
    s32 flag = *(s32 *)(*(char **)((char *)a+0x68)+0x14) & 0x200000;
    f32 *p = 0;
    switch (kind) {
    case 0x15f: p = D_800D93C0; if (flag) p = D_800D9404; break;
    case 0x165: p = D_800D93CC; if (flag) p = D_800D9408; break;
    case 0x16b: p = D_800D93D8; break;
    default: p = 0; break;
    }
    return ((p == NULL) | (i == 0)) ? 0.0f : p[i+1];
}
