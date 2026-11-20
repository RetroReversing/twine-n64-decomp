typedef union {
    u32 word;
    u16 halfword;
    u8 firstByte;
} TwinePackedAudioWord;

typedef struct {
    TwinePackedAudioWord control;
    TwinePackedAudioWord resource;
} TwineAudioControl;

typedef struct {
    u8 pad0[0x24];
    u32 flags;
    u8 pad28[0x44];
    u32 midpoint;
    u32 length;
    u8 pad74[4];
    s8 repeat;
    s8 level;
} TwineAudioControlState;

void func_800957A8(u32 *);
void func_800957B8(u32 *, s32);

s32 func_8009A39C(TwineAudioControlState *state, TwineAudioControl *config) {
    u32 resource;
    u32 control, repeatBits;
    s8 levelBits, repeat;

    if (config->control.firstByte & 3) {
        state->flags |= 0x8000;
    } else {
        state->flags &= ~0x8000;
    }
    resource = config->resource.halfword;
    if ((config->resource.word >> 8) & 1) {
        func_800957A8(&resource);
    } else {
        func_800957B8(&resource, (s32)state);
    }
    if (resource != 0) {
        state->length = resource;
        state->flags |= 0x4000;
        control = config->control.word;
        repeatBits = control >> 8;
        repeat = repeatBits;
        levelBits = control >> 16;
        if ((s8)repeatBits < 0) {
            if (levelBits < 0) {
                state->level = -levelBits;
            } else {
                state->level = levelBits;
            }
            state->repeat = -repeat;
            state->midpoint = state->length >> 1;
        } else {
            if (levelBits < 0) {
                if ((s8)repeatBits == 0) {
                    state->level = -levelBits;
                    state->midpoint = state->length >> 1;
                } else {
                    repeat--;
                    state->level = 100 - levelBits;
                    goto clear_midpoint;
                }
            } else {
                state->level = levelBits;
            clear_midpoint:
                state->midpoint = 0;
            }
            state->repeat = repeat;
        }
    } else {
        state->flags &= ~0x4000;
    }
    return 0;
}
