#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
extern u8 D_800C4736;
void func_80067390(void *arg0) {
    void *dest;
    void *p;
    void *q;
    s32 value;
    s32 index;
    p = M2C_FIELD(arg0, void **, 0x68);
    q = M2C_FIELD(arg0, void **, 0x6C);
    M2C_FIELD(p, u8 *, 0xF) = M2C_FIELD(p, u8 *, 0xE);
    
    index = M2C_FIELD((M2C_FIELD(arg0, void **, 0x68)), s8 *, 0x10);
    value = *((u16 *)((s8 *)&D_800C4736 + index * 0xE8));
    if (value == 0) goto zero_case;
    value = 1;
    dest = M2C_FIELD(q, void **, 0xA8);
    goto finish;
zero_case:
    dest = M2C_FIELD(q, void **, 0xA8);
    value = 3;
finish:
    M2C_FIELD(dest, s16 *, 0x7A) = value;
}
