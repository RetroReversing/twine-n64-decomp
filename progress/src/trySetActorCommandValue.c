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

s32 setActorCommandState();

/* If setActorCommandState succeeds, stores value in the actor's linked data (+0x68, field +0xA0). */ void trySetActorCommandValue(void *actor, s32 arg1, s16 value) {
    if (setActorCommandState() != 0) {
        M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s16 *, 0xA0) = value;
    }
}
