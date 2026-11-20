typedef struct {
    s8 active;
    u8 pad;
    u8 code;
    u8 bank;
    u16 volume;
    u8 rest[12];
} Channel969B4;
typedef struct {
    u8 pad[0xC2];
    Channel969B4 channel[10];
} Player969B4;

void func_800969B4(Player969B4 *player)
{
    Channel969B4 *channel = player->channel;
    u8 firstCode = 7;
    u16 defaultVolume = 0x100;
    u8 enabled = 1;
    channel[0].code = firstCode;
    channel[0].bank = 0;
    channel[0].volume = defaultVolume;
    channel[1].active = enabled;
    channel[1].code = 0xA;
    channel[2].code = 0x83;
    channel[3].code = 0x80;
    channel[6].code = 0x40;
    channel[7].code = 0x41;
    channel[8].code = 0x5B;
    channel[1].bank = 0;
    channel[1].volume = defaultVolume;
    channel[2].active = enabled;
    channel[2].bank = 0;
    channel[2].volume = defaultVolume;
    channel[3].active = enabled;
    channel[3].bank = 0;
    channel[3].volume = defaultVolume;
    channel[4].active = enabled;
    channel[5].code = enabled;
    channel[5].bank = 0;
    channel[5].volume = defaultVolume;
    channel[6].active = enabled;
    channel[6].bank = 0;
    channel[6].volume = defaultVolume;
    channel[7].active = enabled;
    channel[7].bank = 0;
    channel[7].volume = defaultVolume;
    channel[8].active = enabled;
    channel[8].bank = 0;
    channel[8].volume = defaultVolume;
    channel[9].active = enabled;
    channel[4].code = 0x84;
    channel[4].bank = 0;
    channel[4].volume = defaultVolume;
    channel[5].active = enabled;
}
