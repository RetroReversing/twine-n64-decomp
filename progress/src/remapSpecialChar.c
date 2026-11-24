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

/* Remaps special character codes 0x80-0x85 to their alternate codes; other values pass through. Returns the low byte. */ s32 remapSpecialChar(s32 ch) {
    s32 code;
    s32 result;

    result = ch;
    code = result & 0xFF;
    switch (code) {
    case 0x80:
        result = 0x80;
        break;
    case 0x81:
        result = 0x82;
        break;
    case 0x82:
        result = 0xA0;
        break;
    case 0x83:
        result = 0xA1;
        break;
    case 0x84:
        result = 0x83;
        break;
    case 0x85:
        result = 0x84;
        break;
    }
    return result & 0xFF;
}
