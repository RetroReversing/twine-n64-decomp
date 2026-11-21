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

s32 voiceReleaseHandles();
extern u8 D_801002EA;
extern u8 D_8010A930;
extern u8 D_8010D720;
extern u8 D_80110DB0;
extern char D_80117388[];
extern char D_80117389[];

typedef struct { unsigned char field_0; unsigned char field_1; unsigned short field_2; } __repair_record_temp_a0;
/* Releases an audio voice: frees its handles, clears its state and returns its slot to the free table. */ void releaseAudioVoice(void *voice) {
    u8 slotIndex;
    void *slotEntry;

    voiceReleaseHandles();
    slotIndex = M2C_FIELD(voice, u8 *, 0x63);
    M2C_FIELD(voice, s32 *, 0) = 0;
    M2C_FIELD(voice, s8 *, 0x2E) = 0;
    slotEntry = (slotIndex * 4) + D_80117388;
    if (((__repair_record_temp_a0*)slotEntry)->field_2 == 0) {
        ((__repair_record_temp_a0*)slotEntry)->field_2 = 1U;
        if (D_801002EA != 0xFF) {
            ((__repair_record_temp_a0*)slotEntry)->field_1 = 0xFF;
            ((__repair_record_temp_a0*)slotEntry)->field_0 = (u8) D_80110DB0;
            *(D_80117389 + (D_80110DB0 * 4)) = slotIndex;
        } else {
            ((__repair_record_temp_a0*)slotEntry)->field_1 = 0xFF;
            ((__repair_record_temp_a0*)slotEntry)->field_0 = 0xFFU;
            D_801002EA = slotIndex;
        }
        D_80110DB0 = slotIndex;
        if (M2C_FIELD(voice, u8 *, 0x4C) != 0) {
            D_8010A930 -= 1;
        } else {
            D_8010D720 -= 1;
        }
    }
    M2C_FIELD(voice, s32 *, 0x60) = -1;
}
