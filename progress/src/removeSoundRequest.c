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

extern s32 gSoundRequestQueue;

/* Clears the first queue entry matching soundId (-1 marks an empty slot). */ void removeSoundRequest(s32 soundId) {
    u32 slot;
    if (soundId != -1) {
        for (slot = 0; slot < 0x10; slot++) {
            if (((s32 *)&gSoundRequestQueue)[slot] == soundId) { ((s32 *)&gSoundRequestQueue)[slot] = -1; return; }
        }
    }
}
