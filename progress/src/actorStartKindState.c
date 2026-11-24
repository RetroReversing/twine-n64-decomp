typedef struct { u8 pad0[0x7F]; u8 unk7F; u8 unk80; u8 kind; u8 unk82; u8 pad83[5]; u32 flags; } ActorData7C93C;
typedef struct { u8 pad0[0x6C]; ActorData7C93C *data; u8 pad70[0xC]; s16 unk7C; } Actor7C93C;

s32 setActorCommandState(void *, s32);
void setSubStructModeFlag(void *, s32);
u32 randomIntBelow(s32);
void setActorAnimation(void *, s32);
extern u16 D_800C9D34[2];

/* Resets an actor and starts the action and animation matching its kind; sets flag 0x40000000 for kinds that need it. */ void actorStartKindState(Actor7C93C *actor) {
    s32 actionState;
    s8 setFlagOn;
    s32 animId;
    ActorData7C93C *data = actor->data;

    data->unk82 = 0;
    setSubStructModeFlag(actor, 0);
    setFlagOn = 0;
    switch (data->kind) {
    case 1:
        animId = D_800C9D34[randomIntBelow(2)];
        actionState = 0xAD;
        setFlagOn = 1;
        break;
    case 2:
        animId = 0x2AC;
        goto shortDelay;
    case 3:
        animId = 0x2AD;
    shortDelay:
        actor->unk7C = 8;
        actionState = 3;
        break;
    default:
        animId = 0x4D;
        actionState = 2;
        setFlagOn = 1;
        data->unk7F = 10;
        actor->unk7C = 10;
        break;
    case 5:
        animId = 0x3C2;
        goto setState;
    case 6:
        animId = 0x3C4;
    setState:
        actionState = 3;
        setFlagOn = 1;
        break;
    case 7:
        actor->unk7C = 8;
        actionState = 0xA3;
        animId = (-((data->flags & 0x01E00000) == 0x600000) & 0x217) | 0x214;
        break;
    }
    setActorCommandState(actor, animId);
    if (setFlagOn) {
        data->flags |= 0x40000000;
    }
    do { setActorAnimation(actor, actionState); } while (0);
}
