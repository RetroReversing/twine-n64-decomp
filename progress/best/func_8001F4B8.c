typedef struct ActionState ActionState;

typedef struct {
    void (*unused)(ActionState *);
    void (*enter)(ActionState *);
} ActionHandler;

struct ActionState {
    u8 pad0[0xC];
    s32 object;
    u8 pad10[8];
    ActionHandler *handler;
    u8 pad1C[0x10];
    u8 entered;
};

typedef struct {
    void (*invoke)(s32);
    u8 pad4[0xC];
} ActionEntry;

typedef struct {
    u8 pad0[0x7A];
    u16 field7A;
} ActionOptions;

ActionHandler *findEntryById(s32, s32);
s32 func_800278AC(s32, s32, u16);
extern u8 D_800B60EA;
extern ActionEntry D_800C4480[];
extern s32 gMenuSoundParams;
extern ActionOptions *sActiveMenu;
extern ActionState *gMenuItems;
extern s32 gBonusObject[];

s32 func_8001F4B8(u16 slot, s32 action)
{
    s32 object = gBonusObject[slot];
    s32 index;
    void (*invoke)(s32);
    ActionState *state;
    ActionHandler *handler;
    ActionState *callbackState;

    if (object == 0) {
        return 0;
    }

    index = (u8)action;
    invoke = D_800C4480[index].invoke;
    if (invoke != 0) {
        invoke(object);
    }

    state = gMenuItems;
    if (state->entered != 0) {
        return (u8)action;
    }
    if (D_800B60EA != 1) {
        return (u8)action;
    }
    if (index == 0x13) {
        func_800278AC(10, gMenuSoundParams, sActiveMenu->field7A);
        return (u8)action;
    }
    if (state->handler != 0) {
        handler = findEntryById(state->object, 14);
        state = gMenuItems;
        state->entered = 1;
        callbackState = gMenuItems;
        state->handler = handler;
        callbackState->handler->enter(state);
    }
    return (u8)action;
}
