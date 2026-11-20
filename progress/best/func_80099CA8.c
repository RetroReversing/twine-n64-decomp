typedef struct { u8 pad0[0x24]; u32 flags; u8 pad28[0x3b]; u8 index; u8 pad64[0x38]; u32 pending, current, limit; } Voice99CA8;
typedef struct { u32 flags; union { u32 word; u16 half[2]; } value; } Note99CA8;
extern s32 func_8008C1B0(u8);
extern s32 func_80095638(void);
extern void func_800957A8(u32 *);
extern void func_800957B8(u32 *, Voice99CA8 *);
s32 func_80099CA8(Voice99CA8 *v, Note99CA8 *n) {
    u32 delay = n->value.half[0], flags, pending;
    u8 relative;
    if (delay != 0) {
        if ((n->flags >> 8) & 1) {
            flags = v->flags;
            if (flags & 8) return 0;
            flags |= 4;
        } else flags = v->flags & ~4;
        v->flags = flags;
        if (((u8 *)&n->flags)[0] & 1) {
            if (!(*(volatile u32 *)&v->flags & 0x20) && !(u8)func_8008C1B0(v->index)) return 0;
            flags = v->flags | 0x100000;
        } else flags = v->flags & ~0x100000;
        v->flags = flags;
        if (((u16 *)&n->flags)[0] & 1) delay = (u16)func_80095638() % delay;
        if (delay != 0xffff) {
            relative = (*(volatile u32 *)&n->value.word >> 8) & 1;
            if (relative) func_800957A8(&delay);
            else func_800957B8(&delay, v);
            if (relative) pending = v->limit + delay;
            else {
                pending = v->current + delay;
                v->pending = pending;
                if (v->limit >= pending) { v->current = pending; v->pending = 0; }
                return v->pending != 0;
            }
        } else pending = -1;
        v->pending = pending;
        return v->pending != 0;
    }
    return 0;
}
