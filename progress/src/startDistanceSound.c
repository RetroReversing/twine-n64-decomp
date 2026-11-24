s32 stopDistanceSound(void);
void func_8000B900(s32, u32, u32);
s32 runSceneGroupEntry(u16, u16, s32, s32);
typedef struct { u32 value; u8 pad[8]; } SoundWord;
typedef struct { u16 value; u8 pad[10]; } SoundHalf;
extern SoundWord D_800B2480[];
extern SoundWord D_800B2484[];
extern SoundHalf D_800B2488[];
extern SoundHalf gEntryTableValue[];
extern s32 sCurrentDistanceSoundId;
extern s32 sDistanceSoundResult;
extern s32 sDistanceSoundArg;
extern s32 sDistanceSoundsActive;

s32 startDistanceSound(s32 arg0) {
    s32 *ptr;
    u32 start, end;
    s32 index, result;

    if ((sDistanceSoundsActive == 0) || (index = 0, arg0 == sCurrentDistanceSoundId)) {
        return -1;
    }
    for (;;) {
        if (D_800B2480[index].value == 0) {
            return -1;
        }
        if (gEntryTableValue[index].value == arg0) {
            break;
        }
        index++;
    }
    stopDistanceSound();
    ptr = &sDistanceSoundArg;
    end = D_800B2484[index].value;
    start = D_800B2480[index].value;
    sCurrentDistanceSoundId = arg0;
    func_8000B900(*ptr, start, end - start);
    result = runSceneGroupEntry(D_800B2488[index].value, gEntryTableValue[index].value, *ptr, 0);
    sDistanceSoundResult = result;
    return result;
}
