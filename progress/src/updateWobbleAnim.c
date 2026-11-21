extern void *gWobbleParams;

/* Advances the wobble animation: four phases, each held for a countdown timer; the angle sweeps up or down in the first two phases. */
void updateWobbleAnim(void *actor) {
    f32 angle, angleBack;
    s16 phase, nextPhase, wrappedPhase;
    u8 timer, timerDec;
    void *timerPtr;

    phase = *(s16 *)((s8 *)actor + 0x7A);
    timerPtr = *(void **)((s8 *)actor + 0x6C);
    switch (phase) {
    case 0:
        angle = *(f32 *)((s8 *)actor + 0x40) + 3.0f;
        {
            f32 t = angle * 0.0015339808f;
            *(f32 *)((s8 *)actor + 0x40) = angle;
            *(f32 *)((s8 *)gWobbleParams + 0x38) = t;
        }
    case 1:
        timer = *(u8 *)((s8 *)timerPtr + 2) - 1;
        *(u8 *)((s8 *)timerPtr + 2) = timer;
        if (!(timer & 0xFF)) {
            nextPhase = *(s16 *)((s8 *)actor + 0x7A) + 1;
            *(s16 *)((s8 *)actor + 0x7A) = nextPhase;
            if (nextPhase != 1) {
                *(u8 *)((s8 *)timerPtr + 2) = 0x78;
            } else {
                *(u8 *)((s8 *)timerPtr + 2) = 5;
            }
        }
        return;
    case 2:
        angleBack = *(f32 *)((s8 *)actor + 0x40) + -3.0f;
        {
            f32 t = angleBack * 0.0015339808f;
            *(f32 *)((s8 *)actor + 0x40) = angleBack;
            *(f32 *)((s8 *)gWobbleParams + 0x38) = t;
        }
    case 3:
        timerDec = *(u8 *)((s8 *)timerPtr + 2) - 1;
        *(u8 *)((s8 *)timerPtr + 2) = timerDec;
        if (!(timerDec & 0xFF)) {
            *(u8 *)((s8 *)timerPtr + 2) = 0;
            wrappedPhase = (*(s16 *)((s8 *)actor + 0x7A) + 1) & 3;
            *(s16 *)((s8 *)actor + 0x7A) = wrappedPhase;
            if (wrappedPhase == 3) {
                *(u8 *)((s8 *)timerPtr + 2) = 5;
            } else {
                *(u8 *)((s8 *)timerPtr + 2) = 0x78;
            }
        }
        break;
    }
}
