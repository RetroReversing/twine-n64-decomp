#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) 0
#endif
void func_8008C7B8(); extern u32 sKeyTableCount; extern char sKeyTableSlots[]; extern char D_800F38F4[];
s32 func_80097A40(s32 arg0, u16 *arg1) {
    void *sp10[3];
    u32 i = 0;
    u32 count = sKeyTableCount;
    char *p = (char *)arg1;
    u32 id;
    s32 t, idx;
    if (count) {
        s32 off = 0;
        for (;;) {
            if (*(void **)(sKeyTableSlots + off) != p) { i++; off += 0xC; if (i < count) continue; }
            break;
        }
    }
    id = *(u16 *)p;
    if ((u16)id != 0xFFFF) {
        arg0 &= 0xFFFF; t = i * 12;
        do {
            if (id == arg0) {
                if (*(u16 *)(p + 2) == 0) {
                    s32 offset, base;
                    offset = *(s32 *)(p + 4);
                    base = *(s32 *)(D_800F38F4 + t);
                    sp10[0] = p + 0xC;
                    *(s32 *)(p + 8) = offset + base;
                    func_8008C7B8(&sp10, p + 8, i, id);
                }
                (*(u16 *)(p + 2))++;
                break;
            }
            p += 0x1C;
            id = *(u16 *)p;
        } while (id != 0xFFFF);
    }
    return 1;
}
