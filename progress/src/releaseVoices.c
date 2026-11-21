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

s32 voiceResetSlot();
s32 voiceListRemove();
s32 voiceReleaseHandles();
extern u8 D_801002EA;
extern u8 D_8010A930;
extern u8 D_8010D720;
extern char sVoiceTable[];
extern s32 D_8010D748;
extern u8 sVoiceKeepFlags[];
extern u8 D_80110DB0;
extern char D_80117388[];
extern struct { char value; char pad[3]; } D_80117389[];
extern u8 sVoiceCount;

typedef struct { unsigned char field_0; unsigned char field_1; unsigned short field_2; } __repair_record_temp_a0;
/* Stops active voices (all, or only those not flagged in sVoiceKeepFlags) and returns their slots to the pool. */ void releaseVoices(s32 keepFlagged) {
int slotId;

    char *activeMaskPtr;
    char *voiceActivePtr;
    s32 voiceIndex;
    s32 voiceOffset;
    u8 unusedByte;
    void *slotRecord;
    void *voice;

    voiceIndex = 0;
slotId = 0;

    if ((s32) sVoiceCount > slotId) {
        int lowBitsMask = -4;
        int noSlot = 255;
        activeMaskPtr = &D_8010D748;
        voiceActivePtr = (char *)&D_8010D748 - 0x24;
        voiceOffset = 0;
        do {
            if (*(s32 *)voiceActivePtr != 0) {
                if (!(keepFlagged & 0xff) || (*(sVoiceKeepFlags + voiceOffset) == 0)) {
                    voice = voiceOffset + sVoiceTable;
                    voiceListRemove(voice);
                    M2C_FIELD(voice, s32 *, 0x28) = 0;
                    M2C_FIELD(voice, s32 *, 0x24) &= lowBitsMask;
                    voiceReleaseHandles(voice);
                    slotId = (u8)(M2C_FIELD(voice, u8 *, 0x63));
                    M2C_FIELD(voice, s32 *, 0) = 0;
                    M2C_FIELD(voice, s8 *, 0x2E) = 0;
                    slotRecord = (slotId * 4) + D_80117388;
                    if (((__repair_record_temp_a0*)slotRecord)->field_2 == 0) {
                        ((__repair_record_temp_a0*)slotRecord)->field_2 = 1U;
                        if (D_801002EA != noSlot) {
                            ((__repair_record_temp_a0*)slotRecord)->field_1 = noSlot;
                            ((__repair_record_temp_a0*)slotRecord)->field_0 = (u8) D_80110DB0;
                            D_80117389[D_80110DB0].value = slotId;
                        } else {
                            ((__repair_record_temp_a0*)slotRecord)->field_1 = noSlot;
                            ((__repair_record_temp_a0*)slotRecord)->field_0 = noSlot;
                            D_801002EA = slotId;
                        }
                        D_80110DB0 = slotId;
                        if (M2C_FIELD(voice, u8 *, 0x4C) != 0) {
                            D_8010A930 -= 1;
                        } else {
                            D_8010D720 -= 1;
                        }
                    }
                    M2C_FIELD(voice, s32 *, 0x60) = -1;
                    *(s32 *)voiceActivePtr = 0;
                    *(s32 *)activeMaskPtr &= lowBitsMask;
                    goto block_13;
                }
            } else {
block_13:
                voiceResetSlot(voiceIndex);
            }
            activeMaskPtr += 0x1A0;
            voiceActivePtr += 0x1A0;
            voiceIndex += 1;
            voiceOffset += 0x1A0;
        } while (voiceIndex < (s32) sVoiceCount);
    }
}

