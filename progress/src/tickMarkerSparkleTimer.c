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

s32 randomIntBelow();
s32 spawnFlashEffect(s32, s32, f32, s32);
extern u8 gTrackMarkerDone[];

/* If the actor's track marker is done, counts down a timer and spawns a flash effect at a random 1-300 tick interval. */ void tickMarkerSparkleTimer(void *actor) {
    u16 timer;

    if (*(gTrackMarkerDone + (s16) (s32) M2C_FIELD(actor, f32 *, 0x74)) != 0) {
        timer = M2C_FIELD(actor, u16 *, 0x7C) - 1;
        M2C_FIELD(actor, u16 *, 0x7C) = timer;
        if ((timer << 0x10) <= 0) {
            M2C_FIELD(actor, u16 *, 0x7C) = (u16) (randomIntBelow(0x12C) + 1);
            spawnFlashEffect(actor, actor + 0x24, 1.0f, 0);
        }
    }
}
