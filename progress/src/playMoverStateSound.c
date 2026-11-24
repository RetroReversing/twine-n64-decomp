typedef struct TwineMover76B30 {
    u8 pad0[0x24];
    f32 pos[3];
    u8 pad30[0x38];
    u8 *ptr68;
    u8 *ptr6C;
    u8 pad70[0xA];
    s16 state7A;
    s16 state7C;
} TwineMover76B30;

s32 func_80002BD0(void *, s32);
f32 vec3DistanceBetween(void *, void *);
s32 randomIntBelow(s32);
s32 func_80077960(void *, s32);
s32 triggerObjectMarkerEffect(void *);

/* Plays a mover sound chosen from its state and squared distance to the target, then sets sound mode 0xE. */ /* Plays a mover sound chosen from its state and its squared distance to the target, then sets sound mode 0xE. */ void playMoverStateSound(TwineMover76B30 *mover) {
    f32 distSq;
    s32 soundId;
    u8 *targetActor;
    s16 moverState;

    targetActor = mover->ptr6C;
    moverState = mover->state7A;
    if (moverState == 4) {
        goto block5;
    }
    if (moverState < 5) {
        if (moverState == 1) {
            goto block5;
        }
        return;
    }
    if (moverState != 0x81) {
        return;
    }
block5:
    if (!(*(s32 *)(targetActor + 0x88) & 0x40000000)) {
        soundId = -1;
        triggerObjectMarkerEffect(mover);
        switch (mover->state7C) {
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            break;
        case 1:
            distSq = vec3DistanceBetween(targetActor + 0x50, mover->pos);
            if (distSq < 5.0f) {
                soundId = 0x14D;
            } else {
                soundId = 0x1DE;
                if (distSq < 15.0f) {
                    soundId = 0x1DF;
                }
            }
            break;
        case 0:
        case 3:
            if (((s8 *)mover->ptr68)[0xE] == 0) {
                soundId = randomIntBelow(2) + 0x2E9;
            } else {
                soundId = randomIntBelow(2) + 0x2ED;
            }
            break;
        }
        if (soundId != -1) {
            func_80002BD0(mover, soundId);
            func_80077960(mover, 0xE);
        }
    }
}
