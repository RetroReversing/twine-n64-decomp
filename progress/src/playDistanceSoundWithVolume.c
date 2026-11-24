/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 enqueueSoundRequest();
s32 setSoundVolume();
s32 startSound();
extern u8 sDistanceSoundEnabled[];
extern s32 sDistanceSoundsActive;

s32 playDistanceSoundWithVolume(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 var_s1;

    var_s1 = arg1;
    if (sDistanceSoundsActive != 0) {
        if (var_s1 >= 0x80) {
            var_s1 = 0x7F;
        }
        if (var_s1 <= 0) goto block_5;
        temp_v0 = startSound(arg0 & 0xFFFF, arg2 & 0xFF, 0xFF);
        setSoundVolume(temp_v0, var_s1 & 0xFF);
        if (*(sDistanceSoundEnabled + arg0) != 0) goto success;
    }
block_5:
    return -1;
success:
    enqueueSoundRequest(temp_v0);
    return temp_v0;
}
