typedef struct {
    s32 x, y, z;
} BonusPos;

s32 func_8007C094(void *, void *, f32);
void func_80077960(void *, s32);
void triggerActorMarkerPulse(void *);
void triggerObjectMarkerEffect(void *);
void playRandomMarkerSound(s32);
extern u8 *gBonusObjects;

/* Checks whether an actor touches the bonus object and, if its state allows, collects it or resets its state. */
s32 tryCollectBonusObject(u8 *actor) {
    s32 actorFlags = *(s32 *)(actor + 0x60);
    u8 *actorState = *(u8 **)(actor + 0x6C);

    if (!((actorFlags & 0x3000) && ((u32)func_8007C094(actor, gBonusObjects + 0x24, 2.0f) << 24)))
        return 0;
    if ((*(s32 *)(actorState + 0x88) & 0x41E00000) != 0x200000)
        return 0;

    switch (actorState[0x82]) {
    case 3:
    case 15:
    case 35:
    case 39:
    case 40:
        goto reset;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 10:
    case 11:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 43:
    case 44:
        return 0;
    }
    switch (((s8 *)*(u8 **)(gBonusObjects + 0x68))[0xE]) {
    default:
        playRandomMarkerSound((s32)actor);
        func_80077960(actor, 0x38);
        return 1;
    case 0:
    case 0x1E:
    case 0x1F:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x2C:
    case 0x2D:
    case 0x2E:
    case 0x2F:
    case 0x30:
    case 0x37:
    case 0x38:
        triggerObjectMarkerEffect(actor);
        *(BonusPos *)(actorState + 0x18) = *(BonusPos *)(gBonusObjects + 0x24);
        func_80077960(actor, 0xD);
        return 0;
    }
reset:
    triggerActorMarkerPulse(actor);
    return 0;
}
