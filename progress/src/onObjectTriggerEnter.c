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

M2C_UNK clearPendingMessageEntry(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK requestEnemyDefChange(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK registerTrackMarkers(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_800CEC64;
extern s32 gGameMode;
extern M2C_UNK selectActorTarget;

/* Handler that, in game mode 2, registers the track markers once and sets two state flags, then forwards to the object's next-state call. */ void onObjectTriggerEnter(void *object) {
    clearPendingMessageEntry(M2C_FIELD(object, s32 *, 0x6C), 3, 1);
    if (gGameMode == 2) {
        if (M2C_FIELD(&selectActorTarget, s8 *, 0x55D) == 0) {
            if (M2C_FIELD(&selectActorTarget, s8 *, 0x55E) == 0) {
                registerTrackMarkers(0, &D_800CEC64, 1);
            }
            M2C_FIELD(&selectActorTarget, s8 *, 0x55E) = 1;
            M2C_FIELD(&selectActorTarget, s8 *, 0x55C) = 1;
        }
    }
    requestEnemyDefChange(object, 0, 0x2B);
}
