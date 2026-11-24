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
extern u8 gBitWriteSrcMask;

/* Writes the low `count` bits of `bits` into a bit stream (byte pointer + bit position), OR-ing each set bit and advancing to the next byte after bit 7. */ void writeBitsToStream(void *stream, s32 bits, s32 arg2, u32 count) {
    u32 nextIndex;
    void *bytePtr;
    void *oldBytePtr;

    gBitIoIndex = 0;
    if (count != 0) {
        do {
            gBitIoSrcMask = 1 << M2C_FIELD(stream, s32 *, 4);
            gBitWriteSrcMask = 1 << gBitIoIndex;
            if (bits & gBitWriteSrcMask) {
                bytePtr = M2C_FIELD(stream, void **, 0);
                M2C_FIELD(bytePtr, u8 *, 0) |= gBitIoSrcMask;
            }
            if ((M2C_FIELD(stream, s32 *, 4) & 7) == 7) {
                oldBytePtr = M2C_FIELD(stream, void **, 0);
                M2C_FIELD(stream, void **, 0) = (void *) (oldBytePtr + 1);
                M2C_FIELD(oldBytePtr, s8 *, 1) = 0;
                M2C_FIELD(stream, s32 *, 4) = 0;
            } else {
                M2C_FIELD(stream, s32 *, 4) = (s32) (M2C_FIELD(stream, s32 *, 4) + 1);
            }
            nextIndex = gBitIoIndex + 1;
            gBitIoIndex = nextIndex;
        } while (nextIndex < count);
    }
}
