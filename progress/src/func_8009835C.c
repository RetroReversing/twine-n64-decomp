typedef struct { s32 rom; u32 pad4; u16 size; u16 padA; } Bank9835C;
typedef struct { u8 pad0[8]; s32 b; s32 a; u32 c; s32 d; s32 e; } Hdr9835C;
typedef struct { s32 a; s32 b; s32 zero; s32 c; s32 d; s32 e; u8 f; } Out9835C;
extern s16 D_800F3894;
extern Hdr9835C *D_800F38B0;
extern void *D_800F38B4;
extern s32 D_800F38EC;
extern Bank9835C D_800F38F0[];
Hdr9835C *func_800956E0(void *, s32, s32, s32, void *);
void func_800986CC(void);

s32 func_8009835C(s16 arg0, Out9835C *out) {
    s32 i;
    Hdr9835C *h;

    D_800F3894 = arg0;
    for (i = 0; i < D_800F38EC; i++) {
        h = func_800956E0(&D_800F3894, D_800F38F0[i].rom, D_800F38F0[i].size, 0x1C, func_800986CC);
        D_800F38B0 = h;
        if (h != NULL) {
            out->a = h->a;
            out->b = h->b;
            out->zero = 0;
            out->d = h->d;
            out->c = h->c & 0xFFFFFF;
            D_800F38B4 = &h->a;
            out->e = h->e;
            out->f = *(u8 *)&h->c;
            return 0;
        }
    }
    return -1;
}
