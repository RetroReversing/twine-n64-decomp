typedef struct { u8 pad[0x60]; f32 f60; u8 pad64[4]; s32 x68; u8 pad6c[0x1C]; u32 hi:11; u32 fld:4; u32 lo:17; } O81470;
typedef struct { u8 pad[0x60]; u32 flags; u8 pad64[8]; O81470 *o; u8 pad70[0xC]; s16 kind; } A81470;
void func_80081470(A81470 *a) {
    u32 mask = 0x04000080;
    u32 flags = a->flags;
    O81470 *o = a->o;

    if (flags & mask) {
        flags &= ~0x04000080;
        a->flags = flags;
        if (a->kind != 0xC) {
            a->flags = flags | 0x40000000;
            o->x68 |= 0x1000;
            o->f60 = 500.0f;
            o->fld = 0xE;
        }
    }
}
