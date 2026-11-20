s32 func_8009C420(u32, s32, s32, u8, u8, u8, u8, u16, u16, u8, u8);
void func_8008E8F0(s32, s32);
extern u8 D_8010D724[];
extern s32 D_8010D734[];
extern s32 D_8010D738[];

#define FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))

s32 func_80099F80(void *state, void *command)
{
    u32 word = FIELD(command, u32, 0);
    s32 level = FIELD(state, u16, 0x4E) + ((s32)(word << 16) >> 24);
    u32 key, middle, low;
    s32 clamped;
    s32 flags;
    u8 bank, channel;
    s32 result, previous;
    s32 offset;
    u32 commandWords[2];

    word >>= 16;
    middle = FIELD(command, u8, 5);
    word <<= 16;
    low = FIELD(command, u8, 4);
    middle <<= 8;
    word |= middle;
    key = word | low;

    if (level >= 0) {
        clamped = 127;
        if (level < 128) {
            clamped = level;
        }
    } else {
        clamped = 0;
    }

    level = clamped;
    if (FIELD(state, u8, 0x4C)) {
        level |= 0x80;
    }

    flags = FIELD(state, u16, 0xBA);
    bank = FIELD(state, u8, 0x31);
    channel = FIELD(state, u8, 0x39);
    FIELD(state, u8, 0xBD) = 1;
    result = func_8009C420(key, flags, level & 0xFF, bank, channel,
                           FIELD(state, u8, 0x4A), FIELD(state, u8, 0x4B),
                           FIELD(command, u16, 6), FIELD(state, u8, 0x2F),
                           0, FIELD(state, u8, 0xBE));
    FIELD(state, u8, 0xBD) = 0;
    if (result != -1) {
        s32 index = result & 0xFF;
        s32 scaled = index * 12;
        s32 data = FIELD(state, s32, 0x60);
        offset = (scaled + index) * 32;
        FIELD(D_8010D738, s32, offset) = data;
        previous = FIELD(state, s32, 0x10);
        if (previous != -1) {
            FIELD(D_8010D734, s32, offset) = previous;
            FIELD(D_8010D738, s32, FIELD(state, u8, 0x13) * 0x1A0) = result;
        }
        {
            u8 linked = FIELD(state, u8, 0x4C);
            FIELD(state, s32, 0x10) = result;
            if (linked) {
                func_8008E8F0((s32)(D_8010D724 + offset), (s32)state);
            }
        }
        if (0) {
            func_8008E8F0((s32)(D_8010D724 + offset), (s32)state);
        }
    }

    return 0;
}
