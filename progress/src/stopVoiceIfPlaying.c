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

s32 workerLockAcquire();
s32 workerLockRelease();
s32 voiceRelease();
extern u8 gWorkerThreadActive;
extern u8 gVoiceTable[];

/* If the worker thread is active and the voice's state byte is 1 (playing), clears it and releases the voice, under the worker lock. */ void stopVoiceIfPlaying(s32 voiceIndex) {
    s32 voiceOffset;

    if (gWorkerThreadActive != 0) {
        workerLockAcquire();
        voiceOffset = voiceIndex * 0x18;
        if (*(gVoiceTable + voiceOffset) == 1) {
            *(gVoiceTable + voiceOffset) = 0;
            voiceRelease(voiceIndex);
        }
        workerLockRelease();
    }
}
