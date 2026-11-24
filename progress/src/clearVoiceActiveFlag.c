/* adapted from similar verified C in clearAudioVoiceStatus in TWINE (matched), with its names changed by decompdecomp */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#endif
extern s32 gAudioVoiceTable;
/* Zeroes byte 1 of the 0x68-byte audio voice record at voiceIndex. */ void clearVoiceActiveFlag(s32 voiceIndex) {
    M2C_FIELD(((voiceIndex * 0x68) + gAudioVoiceTable), s8 *, 1) = 0;
}
