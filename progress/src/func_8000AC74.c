void listUnlinkFree(s32 block);
s32 func_8009C930(s32 sound, u8 volume);
extern u8 D_800B1FE0[];
extern u8 D_800B2230[];
extern f64 D_800D2170;
extern s32 D_801002EC;

s32 func_8000AC74(s32 sound, s32 index, f32 distance)
{
    f32 nearDistance;
    f32 farDistance;
    f32 fraction;

    if (D_801002EC != 0) {
        if (sound != -1) {
            nearDistance = D_800B1FE0[index];
            fraction = distance - nearDistance;
            farDistance = D_800B2230[index];
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
