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

s32 advanceDataBankPlayback();
extern u8 sDataBankInitialised;
extern char sDataBanks[];
extern char sDataBankElapsedTicks[];

/* Advances the given data bank's playback by ticks + extraTicks and adds that to its elapsed tick counter; always returns 0. */ s32 advanceDataBankByTicks(s32 unused0, s32 ticks, s32 unused2, s32 extraTicks, s32 bankIndex) {
    s32 bankOffset;
    s32 totalTicks;

    if (sDataBankInitialised != 0) {
        bankOffset = bankIndex * 0x1228;
        advanceDataBankPlayback(bankOffset + sDataBanks, (totalTicks = ticks + extraTicks));
        *(s32 *)(sDataBankElapsedTicks + bankOffset) = *(s32 *)(sDataBankElapsedTicks + bankOffset) + totalTicks;
    }
    return 0;
}
