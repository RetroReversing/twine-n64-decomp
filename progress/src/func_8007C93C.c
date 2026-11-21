typedef struct { u8 pad0[0x7F]; u8 unk7F; u8 unk80; u8 kind; u8 unk82; u8 pad83[5]; u32 flags; } ActorData7C93C;
typedef struct { u8 pad0[0x6C]; ActorData7C93C *data; u8 pad70[0xC]; s16 unk7C; } Actor7C93C;

s32 func_80002BD0(void *, s32);
void func_80006604(void *, s32);
u32 randomIntBelow(s32);
void func_80077960(void *, s32);
extern u16 D_800C9D34[2];

void func_8007C93C(Actor7C93C *actor) {
    s32 state;
    s8 setFlag;
    s32 animation;
    ActorData7C93C *data = actor->data;

    data->unk82 = 0;
    func_80006604(actor, 0);
    setFlag = 0;
    switch (data->kind) {
    case 1:
        animation = D_800C9D34[randomIntBelow(2)];
        state = 0xAD;
        setFlag = 1;
        break;
    case 2:
        animation = 0x2AC;
        goto shortDelay;
    case 3:
        animation = 0x2AD;
    shortDelay:
        actor->unk7C = 8;
        state = 3;
        break;
    default:
        animation = 0x4D;
        state = 2;
        setFlag = 1;
        data->unk7F = 10;
        actor->unk7C = 10;
        break;
    case 5:
        animation = 0x3C2;
        goto setState;
    case 6:
        animation = 0x3C4;
    setState:
        state = 3;
        setFlag = 1;
        break;
    case 7:
        actor->unk7C = 8;
        state = 0xA3;
        animation = (-((data->flags & 0x01E00000) == 0x600000) & 0x217) | 0x214;
        break;
    }
    func_80002BD0(actor, animation);
    if (setFlag) {
        data->flags |= 0x40000000;
    }
    do { func_80077960(actor, state); } while (0);
}
