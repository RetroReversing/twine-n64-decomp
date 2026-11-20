
f32 func_8009532C(f32 *v) {
    f32 x = v[0], y = v[1], z = v[2];
    f32 length = __builtin_sqrtf(x*x + y*y + z*z);
    v[0] = x / length;
    v[1] /= length;
    v[2] /= length;
    return length;
}
typedef struct FreeNode {
    struct FreeNode *next;
    struct FreeNode *prev;
    s32 payload[2];
} FreeNode;
extern s32 D_800FD970, D_800FDB74;
extern FreeNode D_800FD974[32];
extern FreeNode *D_800FDB78;
extern char D_800FD978[];
void func_80098710(void) {
    FreeNode *prev = 0;
    FreeNode *node = D_800FD974;
    s32 i = 0;
    D_800FD970 = 0;
    D_800FDB74 = 0;
    D_800FDB78 = node;
    do {
        *(FreeNode **)(D_800FD978 + i) = prev;
        if (prev) prev->next = node;
        prev = node;
        i += 16;
        node = prev + 1;
    } while (i < 512);
    prev->next = 0;
}
extern volatile s16 D_800F38BC;
extern s32 *D_800F38C0;
extern volatile s32 D_800F3950;
extern s32 D_800F3954;
extern s32 func_800986DC(s32,s32);
extern s32 func_800956E0(s32,s32,s32,s32,s32 (*)(s32,s32));
s32 func_8009846C(s16 arg0) {
    s32 size = D_800F3950;
    volatile s16 *base = &D_800F38BC;
    s32 *result;
    s32 (*callback)(s32,s32) = func_800986DC;
    *base = arg0;
    result = (s32 *)func_800956E0((s32)base - 4, (s32)&D_800F3954, size, 8, callback);
    D_800F38C0 = (s32 *)result;
    return result ? *result : 0;
}
void guMtxF2L(f32 *src, u32 *dst) {
    f32 scale = 65536.0f;
    u32 mask = 0xffff0000U;
    volatile u32 *end = dst + 8;
    do {
        u32 first = (s32)(src[0] * scale);
        u32 second = (s32)(src[1] * scale);
        dst[0] = (first & mask) | (second >> 16);
        dst[8] = (first << 16) | (second & 0xffffU);
        dst++;
        src += 2;
    } while (dst != end);
}
