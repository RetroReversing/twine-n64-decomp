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

/* Applies a packed audio control config (repeat, level, loop midpoint) and sample length to the voice state. */
s32 audioApplyVoiceConfig(TwineAudioControlState *state, TwineAudioControl *config) {
    u32 sampleLength;
    u32 control, repeatByte;
    s8 levelByte, repeatCount;

    if (config->control.firstByte & 3) {
        state->flags |= 0x8000;
    } else {
        state->flags &= ~0x8000;
    }
    sampleLength = config->resource.halfword;
    if ((config->resource.word >> 8) & 1) {
        func_800957A8(&sampleLength);
    } else {
        func_800957B8(&sampleLength, (s32)state);
    }
    if (sampleLength != 0) {
        state->length = sampleLength;
        state->flags |= 0x4000;
        control = config->control.word;
        repeatByte = control >> 8;
        repeatCount = repeatByte;
        levelByte = control >> 16;
        if ((s8)repeatByte < 0) {
            if (levelByte < 0) {
                state->level = -levelByte;
            } else {
                state->level = levelByte;
            }
            state->repeat = -repeatCount;
            state->midpoint = state->length >> 1;
        } else {
            if (levelByte < 0) {
                if ((s8)repeatByte == 0) {
                    state->level = -levelByte;
                    state->midpoint = state->length >> 1;
                } else {
                    repeatCount--;
                    state->level = 100 - levelByte;
                    goto clear_midpoint;
                }
            } else {
                state->level = levelByte;
            clear_midpoint:
                state->midpoint = 0;
            }
            state->repeat = repeatCount;
        }
    } else {
        state->flags &= ~0x4000;
    }
    return 0;
}
