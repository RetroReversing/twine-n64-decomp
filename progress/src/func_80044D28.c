void func_800422F4(s32);
void func_800426B8(s32, s32, s32);
typedef struct {
    s32 pad[2];
    volatile s32 value;
} IdTable;
extern IdTable *D_80109688;
void func_80044D28(s16 *input) {
    if (*input >= 0) {
        s16 *p = input;
        do {
            IdTable *state;
            s32 id;
            s32 value;

            func_800422F4(*p);
            state = D_80109688;
            id = *p;
            value = state->value;
            p++;
            func_800426B8(value, id, 1);
        } while (*p >= 0);
    }
}
