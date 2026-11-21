void listUnlinkFree(s32 block);
s32 func_8009C930(s32 sound, u8 volume);
extern u8 sDistanceNearRange[];
extern u8 sDistanceFarRange[];
extern f64 D_800D2170;
extern s32 sDistanceSoundsActive;

s32 func_8000AC74(s32 sound, s32 index, f32 distance)
{
    f32 nearDistance;
    f32 farDistance;
    f32 fraction;

    if (sDistanceSoundsActive != 0) {
        if (sound != -1) {
            nearDistance = sDistanceNearRange[index];
            fraction = distance - nearDistance;
            farDistance = sDistanceFarRange[index];
            if (fraction < 0.0f) {
                fraction = 0.0f;
            }
            if (!(farDistance <= distance)) {
                fraction /= farDistance - nearDistance;
                fraction *= fraction;
                func_8009C930(sound, (s32)(D_800D2170 - (f64)(fraction * 127.0f)) & 0xFF);
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
