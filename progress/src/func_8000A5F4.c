s32 func_8000A580(void);
void func_8000B900(s32, u32, u32);
s32 runSceneGroupEntry(u16, u16, s32, s32);
typedef struct { u32 value; u8 pad[8]; } SoundWord;
typedef struct { u16 value; u8 pad[10]; } SoundHalf;
extern SoundWord D_800B2480[];
extern SoundWord D_800B2484[];
extern SoundHalf D_800B2488[];
extern SoundHalf D_800B248A[];
extern s32 D_800E06B0;
extern s32 D_800E0708;
extern s32 D_800E070C;
extern s32 sDistanceSoundsActive;

s32 func_8000A5F4(s32 arg0) {
    s32 *ptr;
    u32 start, end;
    s32 index, result;

    if ((sDistanceSoundsActive == 0) || (index = 0, arg0 == D_800E06B0)) {
        return -1;
    }
    for (;;) {
        if (D_800B2480[index].value == 0) {
            return -1;
        }
        if (D_800B248A[index].value == arg0) {
            break;
        }
        index++;
    }
    func_8000A580();
    ptr = &D_800E070C;
    end = D_800B2484[index].value;
    start = D_800B2480[index].value;
    D_800E06B0 = arg0;
    func_8000B900(*ptr, start, end - start);
    result = runSceneGroupEntry(D_800B2488[index].value, D_800B248A[index].value, *ptr, 0);
    D_800E0708 = result;
    return result;
}
