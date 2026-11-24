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
extern char gActorTypeKindTable[];

/* Sets the actor's default command (0x1FB or 0x1FC) based on its type kind and a state flag, then clears a state byte. */ void setActorDefaultCommand(void *actor) {
    s32 command;
    u8 kind;
    void *state;

    kind = *(gActorTypeKindTable + (M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s8 *, 0xE) * 0xE8));
    state = M2C_FIELD(actor, void **, 0x6C);
    switch (kind) {
    case 0:
    case 1:
    case 3:
        setActorCommandState(actor, 0x1FC);
        break;
    case 2:
        command = 0x1FB;
        if (M2C_FIELD(state, s32 *, 0x88) & 0x40000000) {
            command = 0x1FC;
        }
        setActorCommandState(actor, command);
        break;
    }
    M2C_FIELD(state, s8 *, 0x7F) = 0;
}
