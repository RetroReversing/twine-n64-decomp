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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 offsetToDoubledIndex();
s32 initAudioStreamState();
s32 flushDCacheRange();
s32 osCreateMesgQueue();
s32 osSendMesg();
extern s8 sDataBankInitialised;
extern char D_800E1AC0[];
extern char D_800E2CC0[];
extern s32 D_800E3F10;
extern s32 sDataBankTable;
extern s32 D_800E3F24;
extern s32 D_800E3F2C;
extern char D_800E3F30[];
extern char D_800E3F48[];
extern s32 (*gDataBankHandler)(s32, s32);
extern u8 D_8010086C;
extern s32 *D_8010D428;
extern s32 updateDataBankVoices;

/* Resets both data bank buffers, creates their message queue and enables data banks. */ void initDataBankBuffers(s32 mode) {
    char *bank;
    char *slot;
    s32 bufSize;
    s32 buf;
    s32 i;
    s32 j;
    s32 bankOffset;

    i = 0;
    bank = D_800E1AC0;
    bankOffset = 0;
    D_800E3F2C = mode;
    sDataBankTable = 0;
    do {
        initAudioStreamState(bank, 0, 0, 0, 0);
        if (D_8010086C != 0) {
            M2C_FIELD(bank, u8 *, 0x11DE) = (u8) (M2C_FIELD(bank, u8 *, 0x11DE) * 2);
        }
        *(D_800E2CC0 + bankOffset) = 0;
        bank += 0x1228;/*__repair_loop_weight*/do {
        i += 1;} while (0);
        bankOffset += 0x1228;
    } while (i < 2);/*__repair_call_balance*/if(i){
    osCreateMesgQueue(D_800E3F30, D_800E3F48, 1);}else{
    osCreateMesgQueue(D_800E3F30, D_800E3F48, 1);}
    osSendMesg(D_800E3F30, 0, 0);
    if (D_800E3F2C & 1) {
        bufSize = offsetToDoubledIndex(0x10E0);
        j = 0;
        slot = &D_800E3F24;
        do {
            buf = gDataBankHandler(bufSize, 0);
            j += 1;
            *(s32 *)slot = buf;
            flushDCacheRange(buf, bufSize);
            slot += 4;
        } while (j < 2);
    }
    D_8010D428 = &updateDataBankVoices;
    sDataBankInitialised = 1;
    D_800E3F10 = 0;
}
