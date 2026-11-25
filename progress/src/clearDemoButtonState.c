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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-strength-reduce, tried by autopilot */

extern s16 D_800E1A86;
extern char gDemoButtons[];

/* Zeroes the demo button entries (two halfwords per 8-byte entry) and five trailing halfwords. */ void clearDemoButtonState(s32 arg0) {
    char *buttonCursor;
    char *trailingSlot;
    s32 byteOffset;
    s32 remaining;

    buttonCursor = gDemoButtons;
    byteOffset = 0;
    do {
        M2C_FIELD(buttonCursor, s16 *, 2) = 0;
        *(s16 *)(gDemoButtons + byteOffset) = 0;
        byteOffset += 8;
        buttonCursor += 8;
    } while (byteOffset < 0x20);
    remaining = 3;
    trailingSlot = &D_800E1A86;
    do {
        *(s16 *)trailingSlot = 0;
        remaining -= 1;
        trailingSlot -= 2;
    } while (remaining >= 0);
}
