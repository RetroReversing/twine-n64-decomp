void setActorCommandState(void *, u16);
s32 randomIntBelow(s32);
extern u16 D_800C9D30[];

/* Sets the actor's command state from its type (+0x7C): a random one of two for types 0/1/3, fixed for types 10 and 2. */
void setActorCommandByType(void *actor) {
    u16 command;

    switch (*(s16 *)((s8 *)actor + 0x7C)) {
    case 0:
    case 1:
    case 3:
        command = *(u16 *)((s8 *)D_800C9D30 + (randomIntBelow(2) * 2));
        setActorCommandState(actor, command);
        break;
    case 10:
        command = 0x1EB;
        setActorCommandState(actor, command);
        break;
    case 2:
        command = 0x1ED;
        setActorCommandState(actor, command);
        break;
    }
}
