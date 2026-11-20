extern s16 D_800D9428, D_800D942A, D_800D942C[6];
extern s16 D_800D94F8, D_800D94FA, D_800D9500[8];
extern s16 D_800DC710, D_800DC712;
extern s32 D_800DC718[6];

static __inline__ void fill_s16(s16 value, u32 i, s16 *out, u32 count, s16 *read, s16 *write) {
    *read = 0;
    *write = 0;
    do { *out++ = value; ++i; } while (i < count);
}
static __inline__ void fill_s32(s32 value, u32 i, s32 *out, u32 count, s16 *read, s16 *write) {
    *read = 0;
    *write = 0;
    do { *out++ = value; ++i; } while (i < count);
}
void initResourceCaches(void) {
    fill_s16(0x7fff, 0, D_800D942C, 6, &D_800D942A, &D_800D9428);
    fill_s16(0x7fff, 0, D_800D9500, 8, &D_800D94FA, &D_800D94F8);
    fill_s32(0x7fffffff, 0, D_800DC718, 6, &D_800DC712, &D_800DC710);
}
typedef struct { u8 pad[0x2D]; u8 flag2D; u8 pad2E; u8 flag2F; } MenuState;
extern MenuState *D_80109BB0;
extern u8 D_800BD690, D_801002A2, D_800BDA68[];
extern char D_800D2864[];
void func_8001A4F4(void);
void func_80026004(void *, s32, ...);
s32 func_8002638C(s32, s32);
char *func_80087100(s32);
void func_8001A434(void) {
    char *entry = (char *)func_8002638C((s32)D_800BDA68, 0x92);
    D_800BD690 = 1;
    if (!entry) return;
    {
        u8 *index;
        char *text;
        char *format;
        D_80109BB0->flag2F = 1;
        D_80109BB0->flag2D = 1;
        func_8001A4F4();
        D_80109BB0->flag2F = 0;
        index = &D_801002A2;
        text = func_80087100(*index + 0x16D);
        format = D_800D2864;
        func_80026004(entry, (s32)format, text);
        text = func_80087100(*index + 0x177);
        func_80026004(entry + 0x28, (s32)format, text);
    }
}
extern u8 D_800CEEB0;
void func_8001074C(u8, u16, u8);
void func_80082834(s32 a, s32 b, s32 percent) {
    if (!D_800CEEB0) {
        s32 factor = 0x51EB851F;
        s32 scale = percent * 255;
        union { long long value; struct { s32 high; u32 low; } words; } product;
        product.value = (long long)scale * factor;
        func_8001074C(a, b, (product.words.high >> 5) - (scale >> 31));
    }
}
