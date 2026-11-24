typedef struct Link798C Link798C;
struct Link798C { Link798C *next; };
Link798C *__osPopThread(Link798C **head) {
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
extern Entry989 *gVoiceListHead;
s32 soundResolveHandle(u32 key) {
    Entry989 *p, *found;
    if (key == (u32)-1)
        return -1;
    p = gVoiceListHead;
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
extern Gfx38 * volatile sDisplayListCursor;
extern u32 gFrameBufferIndex;
extern u8 *sRenderState;
/* Appends four display-list commands (two matrix loads, a movemem and a perspective-norm word) for the current frame buffer. */ void appendProjectionViewportCommands(void) {
    Gfx38 *gfx = sDisplayListCursor;
    u32 frameIndex = gFrameBufferIndex;
    u8 *renderState = sRenderState;
    u32 matrixOffset = frameIndex << 6;
    gfx[0].w0 = 0xda380007;
    gfx[0].w1 = (u32)(renderState + matrixOffset) - 0x80000000u;
    gfx[1].w0 = 0xda380005;
    gfx[1].w1 = (u32)(renderState + (matrixOffset + 0x180)) - 0x80000000u;
    gfx[2].w0 = 0xdc080008;
    gfx[2].w1 = (u32)(renderState + ((frameIndex << 4) + 0x300));
    gfx[3].w0 = 0xdb0e0000;
    {
        u16 fogValue = *(volatile u16 *)(((frameIndex << 1) + (u32)renderState) + 0x360);
        sDisplayListCursor = gfx + 1;
        sDisplayListCursor = gfx + 2;
        sDisplayListCursor = gfx + 3;
        sDisplayListCursor = gfx + 4;
        gfx[3].w1 = fogValue;
    }
}

extern f32 *D_800D93C0, *D_800D93CC, *D_800D93D8, *D_800D9404, *D_800D9408;
f32 getKindTableValue(void *a, s32 i, s32 kind) {
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
