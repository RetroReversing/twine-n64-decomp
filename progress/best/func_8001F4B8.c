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

ActionHandler *func_800262A8(s32, s32);
s32 func_800278AC(s32, s32, u16);
extern u8 D_800B60EA;
extern ActionEntry D_800C4480[];
extern s32 D_80102EBC;
extern ActionOptions *D_80102F2C;
extern ActionState *D_80109BB0;
extern s32 D_8010A500[];

s32 func_8001F4B8(u16 slot, s32 action)
{
    ActionState **__base_D_80109BB0;
    s32 object = D_8010A500[slot];
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

    __base_D_80109BB0 = &D_80109BB0;
    state = (*__base_D_80109BB0);
    if (state->entered != 0) {
        return (u8)action;
    }
    if (D_800B60EA != 1) {
        return (u8)action;
    }
    if (index == 0x13) {
        /*__repair_pointer_balance*/if ((unsigned long)__base_D_80109BB0 & 0x100) {
func_800278AC(10, D_80102EBC, D_80102F2C->field7A);
} else {
func_800278AC(10, D_80102EBC, D_80102F2C->field7A);
}
        return (u8)action;
    }
    if (state->handler != 0) {
        handler = func_800262A8(state->object, 14);
        state = (*__base_D_80109BB0);
        state->entered = 1;
        callbackState = (*__base_D_80109BB0);
        state->handler = handler;
        callbackState->handler->enter(state);
    }
    return (u8)action;
}
