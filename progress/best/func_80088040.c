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

s32 flushDCacheRange();
s32 func_80087F60();
s32 func_800936A8();
s32 func_8009D510();
s32 osCreateMesgQueue();
s32 osRecvMesg();
s32 osSendMesg();
extern char D_800E3F24[];
extern u8 D_8010086C;
extern s32 func_80088F6C;
extern s32 (*gDataBankAlloc)(s32, s32);
extern s32 sDataBankAux;
extern u32 sDataBankCount;
extern s32 sDataBankFlags;
extern u8 sDataBankInitialised;
extern s32 sDataBankMesgQueue;
extern s32 sDataBankMode;
extern s32 sDataBankTable;
extern s32 sDataBanks;

s32 func_80088040(u32 arg0, s32 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5, u8 arg6) {
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s2;
    s32 var_v1;
    u32 var_v1_2;
    void *temp_s1;
    s32 *__base_sDataBankMesgQueue;
    char *__base_D_800E3F24;

    __base_D_800E3F24 = D_800E3F24;

    __base_sDataBankMesgQueue = &sDataBankMesgQueue;

    var_s0 = arg1;
    if (sDataBankInitialised != 0) {
        var_s2 = 0;
        if (arg0 < (u32) sDataBankCount) {
            var_v1 = 0;
loop_3:
            if (*(u8 *)((char *)&sDataBankFlags + var_v1) != 0) {
                var_s2 += 1;
                var_v1 += 0x1228;
                if (var_s2 >= 2) {

                } else {
                    goto loop_3;
                }
            }
            if (var_s2 != 2) {
                temp_s1 = (var_s2 * 0x1228) + (char *)&sDataBanks;
                osCreateMesgQueue(temp_s1 + 0x11E0, temp_s1 + 0x11F8, 2);
                var_v1_2 = var_s0 * 8;
                if (var_s0 == 0) {
                    var_s0 = 0x3E80;
                    if (*(u8 *)((arg0 * 4) + sDataBankTable) == 0) {
                        var_s0 = 0x1F40;
                    }
                    var_v1_2 = var_s0 * 8;
                }
                M2C_FIELD(temp_s1, s8 *, 0x1204) = arg2;
                M2C_FIELD(temp_s1, s8 *, 0x1201) = arg3;
                M2C_FIELD(temp_s1, u8 *, 0x1202) = arg4;
                M2C_FIELD(temp_s1, u8 *, 0x1203) = arg5;
                M2C_FIELD(temp_s1, u8 *, 0x1219) = arg6;
                M2C_FIELD(temp_s1, s32 *, 0x1208) = var_s0;
                temp_a0 = (((var_v1_2 / 30) + 0x9F) / 160) * 0xA0;
                M2C_FIELD(temp_s1, s32 *, 0x1214) = temp_a0;
                if (sDataBankMode & 1) {
                    M2C_FIELD(temp_s1, s32 *, 0x1210) = *(s32 *)(__base_D_800E3F24 + (var_s2 * 4));
                } else {
                    temp_v0 = func_800936A8(temp_a0);
                    temp_v0_2 = gDataBankAlloc(temp_v0, 0);
                    M2C_FIELD(temp_s1, s32 *, 0x1210) = temp_v0_2;
                    flushDCacheRange(temp_v0_2, temp_v0);
                }
                if (M2C_FIELD(temp_s1, s32 *, 0x1210) != 0) {
                    osRecvMesg(__base_sDataBankMesgQueue, 0, 1);
                    func_8009D510(temp_s1, (*(s32 *)((arg0 * 4) + sDataBankTable) & 0xFFFFFF) + sDataBankAux, M2C_FIELD(temp_s1, s32 *, 0x1210), M2C_FIELD(temp_s1, s32 *, 0x1214), &func_80088F6C);
                    if (D_8010086C != 0) {
                        M2C_FIELD(temp_s1, u8 *, 0x11DE) = (u8) (M2C_FIELD(temp_s1, u8 *, 0x11DE) * 2);
                    }
                    M2C_FIELD(temp_s1, s32 *, 0x120C) = -1;
                    M2C_FIELD(temp_s1, s8 *, 0x1200) = 1;
                    osSendMesg(__base_sDataBankMesgQueue, 0);
                    return func_80087F60(var_s2);
                }
                goto block_18;
            }
            goto block_18;
        }
    }
block_18:
    return -1;
}
