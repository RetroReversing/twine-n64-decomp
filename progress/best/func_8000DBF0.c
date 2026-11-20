typedef struct {
    u32 *pc;
    u8 pad4[8];
    s32 count;
    u8 pad10[2];
    s16 status;
} InterpreterState;
extern InterpreterState *gObjectTable;
s32 func_8000DBF0(s32 arg0) {
    InterpreterState *state = gObjectTable;
    unsigned int count = state->count;
    s32 opcode;
    volatile s32 frame_flag = 1;
    volatile u32 scratch[58];
    if (count > 0) {
        state->count = count - 1;
        return arg0;
    }
    for (;;) {
        opcode = *state->pc;
        state->pc++;
        switch (opcode & 0x3F) {
        default:
            return frame_flag;
        case 0:
            frame_flag = 0;
            state->count = ((u32)opcode >> 8) - 1;
            break;
        case 1:
            frame_flag = 0;
            state->status = 0;
            break;
        }
    }
}
