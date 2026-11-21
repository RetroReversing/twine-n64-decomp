typedef struct { s32 a; s32 b; u32 c; u32 max; } EnvA20C;
typedef struct { u8 pad0[0x24]; s32 f24; u8 pad28[8]; u16 h30; u8 pad32[0x26]; s32 f58; s32 f5C; u8 pad60[3]; u8 b63; } VoiceA20C;
typedef struct { u32 w0; s32 w4; } EvA20C;
extern s32 D_800FDB80;
extern s32 D_800FDB84;
extern u32 sAudioVoiceVolume;
extern u32 sAudioVolumeMax;
s32 func_8009835C(u16, s32 *);
void audioVoiceSetup(u8, u32 *, s32);

/* Computes the voice volume from an envelope entry (mode in byte 0, value in w4), clamps it, and sets up the voice. */
s32 audioVoiceApplyEnvelope(VoiceA20C *voice, EvA20C *envelope) {
    s32 flag;
    u32 *volumePtr;
    u8 channel;

    if (func_8009835C(envelope->w0 >> 8, &D_800FDB80) != 0) {
        goto __shared_return_0;
    }
    switch (*(u8 *)envelope) {
    case 0:
        sAudioVoiceVolume = envelope->w4;
        break;
    case 1:
        { s32 h = voice->h30; s32 w = envelope->w4; sAudioVoiceVolume = (u32)((0x7F - h) * w) / 127; }
        break;
    case 2:
        sAudioVoiceVolume = (u32)(voice->h30 * envelope->w4) / 127;
        break;
    default:
        sAudioVoiceVolume = 0;
        break;
    }
    volumePtr = &sAudioVoiceVolume;
    if (*volumePtr >= sAudioVolumeMax) {
        *volumePtr = sAudioVolumeMax - 1;
    }
    channel = voice->b63;
    if (!(voice->f24 & 0x200)) {
        audioVoiceSetup(channel, volumePtr - 2, 1);
        voice->f5C = D_800FDB80;
    } else {
        audioVoiceSetup(channel, volumePtr - 2, 0);
        voice->f5C = D_800FDB80;
    }
    voice->f24 |= 0x20;
    voice->f58 = D_800FDB84;
__shared_return_0:
    return 0;
}
