/* identical to osEepromLongRead in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
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

s32 osEepromRead(s32, s32, s32);                   /* extern */

/* Reads consecutive 8-byte EEPROM blocks into a buffer until done or an error occurs. */ s32 osEepromLongRead(s32 mq, s32 blockStart, s32 buffer, s32 remaining) {
    s32 bytesLeft;
    s32 block;
    s32 dest;
    s32 result;

    dest = buffer;
    bytesLeft = remaining;
    block = blockStart;
    result = 0;
    if (bytesLeft > 0) {
loop_1:
        result = osEepromRead(mq, block & 0xFF, dest);
        bytesLeft -= 8;
        if (result == 0) {
            block += 1;
            dest += 8;
            if (bytesLeft > 0) {
                goto loop_1;
            }
        }
    }
    return result;
}
