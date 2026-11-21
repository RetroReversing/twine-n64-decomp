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
s32 voiceReleaseHandles();
extern u8 D_801002EA;
extern u8 D_8010A930;
extern u8 D_8010D720;
extern char sVoiceTable[];
extern char D_8010D784[];
extern char D_8010D7E1[];
extern u8 D_80110DB0;
extern char D_80117388[];
extern char D_80117389[];

typedef struct { unsigned char field_0; unsigned char field_1; unsigned short field_2; } __repair_record_temp_a0;
void voiceRelease(s32 arg0) {
    s32 temp_v0;
    s32 var_v0;
    u8 temp_a1;
    void *temp_a0;
    void *temp_s1;

    if (arg0 != -1) {
        if (audioVoiceIsActive() & 0xFF) {
            func_8008C590(arg0);
        }
        var_v0 = arg0 * 2;
        temp_v0 = (((var_v0 + arg0) * 4) + arg0) << 5;
        temp_s1 = temp_v0 + sVoiceTable;
        *(s32 *)(D_8010D784 + temp_v0) = arg0;
        voiceReleaseHandles(temp_s1);
        temp_a1 = M2C_FIELD(temp_s1, u8 *, 0x63);
        M2C_FIELD(temp_s1, s32 *, 0) = 0;
        M2C_FIELD(temp_s1, s8 *, 0x2E) = 0;
        temp_a0 = (temp_a1 * 4) + D_80117388;
        if (((__repair_record_temp_a0*)temp_a0)->field_2 == 0) {
            ((__repair_record_temp_a0*)temp_a0)->field_2 = 1U;
            if (D_801002EA != 0xFF) {
                ((__repair_record_temp_a0*)temp_a0)->field_1 = 0xFF;
                ((__repair_record_temp_a0*)temp_a0)->field_0 = (u8) D_80110DB0;
                *(D_80117389 + (D_80110DB0 * 4)) = temp_a1;
            } else {
                ((__repair_record_temp_a0*)temp_a0)->field_1 = 0xFF;
                ((__repair_record_temp_a0*)temp_a0)->field_0 = 0xFFU;
                D_801002EA = temp_a1;
            }
            D_80110DB0 = temp_a1;
            if (M2C_FIELD(temp_s1, u8 *, 0x4C) != 0) {
                D_8010A930 -= 1;
            } else {
                D_8010D720 -= 1;
            }
        }
        M2C_FIELD(temp_s1, s32 *, 0x60) = -1;
        *(D_8010D7E1 + (arg0 * 0x1A0)) = 0;
    }
}
