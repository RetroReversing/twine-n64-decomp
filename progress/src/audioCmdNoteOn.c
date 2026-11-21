s32 func_8009C420(u32, s32, s32, u8, u8, u8, u8, u16, u16, u8, u8);
void func_8008E8F0(s32, s32);
extern u8 sVoiceTable[];
extern s32 gVoiceChannelTable[];
extern s32 D_8010D738[];

#define FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))

/* Command 0x08: starts a note on a channel. Builds the key and volume from the command bytes,
   starts a voice with func_8009C420, and links the new voice to the channel. */
s32 audioCmdNoteOn(void *channel, void *cmd)
{
    u32 cmdHi = FIELD(cmd, u32, 0);
    s32 volume = FIELD(channel, u16, 0x4E) + ((s32)(cmdHi << 16) >> 24);
    u32 noteKey, keyMid, keyLow;
    s32 clampedVolume;
    s32 voiceFlags;
    u8 bankIndex, channelIndex;
    s32 voiceIndex, prevVoice;
    s32 voiceOffset;
    u32 commandWords[2];

    cmdHi >>= 16;
    keyMid = FIELD(cmd, u8, 5);
    cmdHi <<= 16;
    keyLow = FIELD(cmd, u8, 4);
    keyMid <<= 8;
    cmdHi |= keyMid;
    noteKey = cmdHi | keyLow;

    if (volume >= 0) {
        clampedVolume = 127;
        if (volume < 128) {
            clampedVolume = volume;
        }
    } else {
        clampedVolume = 0;
    }

    volume = clampedVolume;
    if (FIELD(channel, u8, 0x4C)) {
        volume |= 0x80;
    }

    voiceFlags = FIELD(channel, u16, 0xBA);
    bankIndex = FIELD(channel, u8, 0x31);
    channelIndex = FIELD(channel, u8, 0x39);
    FIELD(channel, u8, 0xBD) = 1;
    voiceIndex = func_8009C420(noteKey, voiceFlags, volume & 0xFF, bankIndex, channelIndex,
                               FIELD(channel, u8, 0x4A), FIELD(channel, u8, 0x4B),
                               FIELD(cmd, u16, 6), FIELD(channel, u8, 0x2F),
                               0, FIELD(channel, u8, 0xBE));
    FIELD(channel, u8, 0xBD) = 0;
    if (voiceIndex != -1) {
        s32 slotIndex = voiceIndex & 0xFF;
        s32 slotScaled = slotIndex * 12;
        s32 channelData = FIELD(channel, s32, 0x60);
        voiceOffset = (slotScaled + slotIndex) * 32;
        FIELD(D_8010D738, s32, voiceOffset) = channelData;
        prevVoice = FIELD(channel, s32, 0x10);
        if (prevVoice != -1) {
            FIELD(gVoiceChannelTable, s32, voiceOffset) = prevVoice;
            FIELD(D_8010D738, s32, FIELD(channel, u8, 0x13) * 0x1A0) = voiceIndex;
        }
        {
            u8 linked = FIELD(channel, u8, 0x4C);
            FIELD(channel, s32, 0x10) = voiceIndex;
            if (linked) {
                func_8008E8F0((s32)(sVoiceTable + voiceOffset), (s32)channel);
            }
        }
        if (0) {
            func_8008E8F0((s32)(sVoiceTable + voiceOffset), (s32)channel);
        }
    }

    return 0;
}
