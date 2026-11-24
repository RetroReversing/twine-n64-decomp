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

s32 requestSound();
s32 updateActorSpeedScale();
s32 playSoundAtPos();
extern char gPhaseSlotIds[];

/* Advances the actor's phase counter through 0x28..0x37, plays the phase sound, then maps the phase to its slot index. */ void advanceActorPhaseSound(void *actor) {
    s32 soundId;
    s32 stateId;
    s16 skipFirstSound;
    s32 tableOffset;
    s8 nextPhase;
    s32 tableIndex;
    void *actorState;
    void *phaseTrackD;
    void *phaseTrackA;
    void *phaseTrackB;
    void *phaseTrackC;

    actorState = M2C_FIELD(actor, void **, 0x6C);
    stateId = M2C_FIELD(M2C_FIELD(actorState, void **, 0xA8), s16 *, 0x7A);
    skipFirstSound = 1;
    switch (stateId) {
    case 1:
    case 3:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
        break;
    default:
    case 0:
    case 2:
    case 4:
    case 8:
        phaseTrackA = M2C_FIELD(actor, void **, 0x68);
        M2C_FIELD(phaseTrackA, u8 *, 0x10) = (u8) M2C_FIELD(phaseTrackA, u8 *, 0xE);
        phaseTrackB = M2C_FIELD(actor, void **, 0x68);
        if (M2C_FIELD(phaseTrackB, s8 *, 0xF) < 0x28) {
            M2C_FIELD(actorState, s16 *, 0x134) = (s16) (s8) M2C_FIELD(phaseTrackB, u8 *, 0xE);
            M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s8 *, 0xF) = 0x27;
        }
        for (;;) {
            phaseTrackC = M2C_FIELD(actor, void **, 0x68);
            nextPhase = (u8) M2C_FIELD(phaseTrackC, s8 *, 0xF) + 1;
            M2C_FIELD(phaseTrackC, s8 *, 0xF) = nextPhase;
            if (nextPhase >= 0x37) {
                M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s8 *, 0xF) = 0x28;
                soundId = 0xEC;
                if (skipFirstSound != 0) {
                    skipFirstSound = 0;
                    goto block_10;
                }
                phaseTrackD = M2C_FIELD(actor, void **, 0x68);
                M2C_FIELD(phaseTrackD, s8 *, 0xF) = (s8) M2C_FIELD(phaseTrackD, u8 *, 0xE);
                {
                    requestSound(soundId);break;}
            }
block_10:
            {
            char *phaseSlot = actorState;
            phaseSlot += M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s8 *, 0xF) * 8;
            if (M2C_FIELD(phaseSlot, u8 *, 0x1FC) != 0) {
                soundId = 0x118;
                if (M2C_FIELD(actor, u16 *, 0x78) == 3) {
                    playSoundAtPos(0x118, actor + 0x24);
                } else {
block_12:
                    requestSound(soundId);
                }
            } else {
                continue;
            }
            break;
            }
        }
        updateActorSpeedScale(actor);
        M2C_FIELD(actorState, u16 *, 0x174) = 0U;
        tableIndex = 0;
        tableOffset = 0;
        do {
            if (M2C_FIELD(M2C_FIELD(actor, void **, 0x68), s8 *, 0xF) == *(s16 *)(gPhaseSlotIds + tableOffset)) {
                M2C_FIELD(actorState, u16 *, 0x174) = tableIndex;
            }
            tableIndex += 1;
            tableOffset += 0x10;
        } while (tableIndex < 0x1EU);
        break;
    }
}
