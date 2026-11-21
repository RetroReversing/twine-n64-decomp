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

s32 audioVoiceIsActive();
s32 func_8008C590();
s32 voiceListRemove();
s32 func_80098B14();
s32 func_80098D18();
extern char sVoiceTable[];
extern char sVoiceKeepFlags[];
extern char D_8010D784[];
extern char D_8010D7E1[];

s32 func_800994B4(s32 arg0) {
    s32 temp_s1;
    s32 temp_s3;
    s32 temp_v0;
    void *temp_s2;

    temp_s3 = arg0 & 0xFF;
    temp_v0 = func_80098D18(temp_s3, 0xFF, 0xFFFF, 1);
    if (temp_v0 != -1) {{ s32 __repair_value; __repair_value = temp_v0 * 0x1A0; temp_s1 = __repair_value; }
        temp_s2 = temp_s1 + sVoiceTable;
        *(D_8010D7E1 + temp_s1) = 1;
        *(sVoiceKeepFlags + temp_s1) = 1;
        voiceListRemove(temp_s2);
        *(s32 *)(D_8010D784 + temp_s1) = temp_v0 | ~0xFF;
        if (audioVoiceIsActive(temp_v0) & 0xFF) {
            func_8008C590(temp_v0);
        }
        *(s32 *)(sVoiceTable + temp_s1) = 0;
        func_80098B14(temp_s2, temp_s3);
    }
    return temp_v0;
}
