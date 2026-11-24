/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

extern char D_800EE380[];
extern char D_800EE400[];

void setClipSlotValue(s32 arg0, s32 arg1, s8 arg2) {
    s32 bank = (u8)arg1;
    if (bank != 0xFF) {
        char *base = D_800EE380;
        u8 column = arg0;
        char *p = (char *)((bank << 4) + (s32)base);
        *(p + column) = arg2;
    } else {
        D_800EE400[(u8)arg0] = arg2;
    }
}
