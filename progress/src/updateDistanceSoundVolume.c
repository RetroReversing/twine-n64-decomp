void listUnlinkFree(s32 block);
s32 setSoundVolume(s32 sound, u8 volume);
extern u8 sDistanceNearRange[];
extern u8 sDistanceFarRange[];
extern f64 kMaxSoundVolume;
extern s32 sDistanceSoundsActive;

/* Sets a sound's volume from its distance (quadratic falloff between near/far range); stops the sound beyond the far range. Returns the handle, or -1 if inactive. */ s32 updateDistanceSoundVolume(s32 sound, s32 rangeIndex, f32 distance)
{
    f32 nearDistance;
    f32 farDistance;
    f32 attenuation;

    if (sDistanceSoundsActive != 0) {
        if (sound != -1) {
            nearDistance = sDistanceNearRange[rangeIndex];
            attenuation = distance - nearDistance;
            farDistance = sDistanceFarRange[rangeIndex];
            if (attenuation < 0.0f) {
                attenuation = 0.0f;
            }
            if (!(farDistance <= distance)) {
                attenuation /= farDistance - nearDistance;
                attenuation *= attenuation;
                setSoundVolume(sound, (s32)(kMaxSoundVolume - (f64)(attenuation * 127.0f)) & 0xFF);
                return sound;
            }
            listUnlinkFree(sound);
            goto inactive;
        }
        return -1;
    }

inactive:
    return -1;
}
