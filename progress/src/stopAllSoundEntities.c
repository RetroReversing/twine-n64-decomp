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

s32 sndStopEntity();
extern char gSoundEntities[];

/* Stops all 8 sound entities. */ void stopAllSoundEntities(void) {
    s32 entityId;
    s32 byteOffset;
    u32 index;

    index = 0;
    byteOffset = 0;
    do {
        entityId = *(s32 *)(gSoundEntities + byteOffset);
        byteOffset += 0xFF8;
        index += 1;
        sndStopEntity(entityId);
    } while (index < 8U);
}
