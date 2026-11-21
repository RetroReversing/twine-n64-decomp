extern u8 D_54D910[];
typedef struct { s32 offset; s32 count; s32 extra_offset; s32 extra_count; } Rec;
typedef struct { Rec *ptr; s32 pad[3]; } Slot; extern Slot D_800C0784[];
extern u8 D_800CA338[];
extern s32 func_80083E24(void);
extern u8 *func_80083E90(s32, s32);
extern void func_8000B9B8(u8 *, s32, u32);
extern void func_80084048(s32, s32);
extern void func_80083E44(s32);
void func_80042CFC(s32 arg0, s32 arg1) {
    s32 saved, src, size, count, special;
    Rec *fp; u8 *data, *extra;
    volatile s32 frame[0x30];
    saved = func_80083E24();
    fp = D_800C0784[arg1].ptr;
    count = fp->count;
    special = D_800CA338[0] != 0;
    size = count * 68;
    data = func_80083E90(size, 0x2D);
    src = fp->offset;
    func_8000B9B8(data, (s32)(D_54D910 + src), fp->count * 68);
    { s32 i; for (i = 0; i < count; i++) { u8 *p = data + i * 68; s32 off = *(s32 *)(p + 8); if (off) { u8 *q = func_80083E90(*(u16 *)(p + 2) * 24, 0x1F); func_8000B9B8(q, (s32)(D_54D910 + *(s32 *)(p + 8)), *(u16 *)(p + 2) * 24); } { u8 tmp[32]; func_8000B9B8(tmp, (s32)(D_54D910 + *(s32 *)(p + 0x24)), 32); *(u8 **)(p + 0x24) = tmp; } } }
    func_80084048((s32)data, 0x2D);
    if (!special && fp->extra_offset) {
        extra = func_80083E90(fp->extra_count * 28, 0x2D);
        func_80084048((s32)extra, 0x2D);
        func_8000B9B8(extra, (s32)(D_54D910 + fp->extra_offset), fp->extra_count * 28);
    }
    func_80083E44(saved);
}
