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

extern u32 gBitIoIndex;
extern s8 gBitIoSrcMask;
extern s8 gBitIoDstMask;

/* Reads bitCount bits LSB-first from a bit stream (byte pointer + bit position) and returns them packed into one value. */ s32 readBitsLsbFirst(void *stream, s32 unused, u32 bitCount) {
    u8 __repair_frame[8];
    s32 bitPos;
    s32 result;
    s8 dstMask;
    s32 srcMask;
    u32 nextIndex;
    u8 *bytePtr;

    gBitIoIndex = 0;
    result = 0;
    if (bitCount != 0) {
        do {
            bytePtr = M2C_FIELD(stream, u8 **, 0);
            srcMask = 1 << M2C_FIELD(stream, s32 *, 4);
            dstMask = 1 << gBitIoIndex;
            gBitIoSrcMask = srcMask;
            gBitIoDstMask = dstMask;
            if (*bytePtr & srcMask) {
                result |= dstMask & 0xFF;
            }
            bitPos = M2C_FIELD(stream, s32 *, 4);
            if ((bitPos & 7) == 7) {
                M2C_FIELD(stream, u8 **, 0) = (u8 *) (bytePtr + 1);
                M2C_FIELD(stream, s32 *, 4) = 0;
            } else {
                M2C_FIELD(stream, s32 *, 4) = (s32) (bitPos + 1);
            }
            nextIndex = gBitIoIndex + 1;
            gBitIoIndex = nextIndex;
        } while (nextIndex < bitCount);
    }
    return result;
}
