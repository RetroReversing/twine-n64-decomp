/* Plays sound soundId at distance from the listener, attenuating volume between its near and far ranges; returns the voice or -1. */
s32 func_8000A724(s32 voice);
s32 func_8009C930(s32 voice, s32 volume);
s32 func_8009CC3C(s32 soundId, s32 channel, s32 flags);
extern u8 sDistanceNearRange[];
extern u8 sDistanceFarRange[];
extern u8 sDistanceSoundEnabled[];
extern f64 gSoundMaxVolume;
extern s32 sDistanceSoundsActive;

s32 playDistanceSound(s32 soundId, f32 distance, u8 channel) {
    f32 nearRange;
    f32 farRange;
    f32 attenuation;
    s32 volume;
    s32 voice;
    s32 result;

    if (sDistanceSoundsActive == 0) goto failed;
    {
        nearRange = (f32) sDistanceNearRange[soundId];
        attenuation = distance - nearRange;
        farRange = (f32) sDistanceFarRange[soundId];
        if (attenuation < 0.0f) {
            attenuation = 0.0f;
        }
        result = -1;
        if (!(farRange <= distance)) {
            attenuation /= (farRange - nearRange);
            attenuation *= attenuation;
            volume = (s32) (gSoundMaxVolume - (f64) (attenuation * 127.0f));
            voice = func_8009CC3C(soundId & 0xFFFF, channel & 0xFF, 0xFF);
            func_8009C930(voice, volume & 0xFF);
            if (sDistanceSoundEnabled[soundId] == 0) {
failed:
                result = -1;
            } else {
                func_8000A724(voice);
                result = voice;
            }
        }
        return result;
    }
}
