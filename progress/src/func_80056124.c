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

s32 actorTickTimedState();
s32 tickTimedObject();
extern void *gPlayerActor;
extern void *D_80108F84;

s32 func_80056124(s32 arg0, void *arg1, s32 arg2) {
    if ((D_80108F84 != NULL) && (M2C_FIELD(D_80108F84, s32 *, 0x50) & 0x300000)) {
        actorTickTimedState(arg0, D_80108F84, arg2, M2C_FIELD(M2C_FIELD(arg1, void **, 0x2C), s32 *, 0xC), M2C_FIELD(arg1, s32 *, 0x24));
        return 1;
    }
    if ((gPlayerActor != NULL) && (M2C_FIELD(gPlayerActor, s32 *, 0x5C) & 0x300000)) {
        tickTimedObject(gPlayerActor, arg2, M2C_FIELD(M2C_FIELD(arg1, void **, 0x2C), s32 *, 0xC), M2C_FIELD(arg1, s32 *, 0x24));
        return 1;
    }
    return 0;
}
