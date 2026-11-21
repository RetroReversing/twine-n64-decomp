typedef struct DataBank {
    u8 pad0[0x11DE];
    u8 f11DE;
    u8 pad11DF;
    u8 f11E0[0x18];
    u8 f11F8[0x8];
    u8 active;
    u8 f1201;
    u8 f1202;
    u8 f1203;
    u8 f1204;
    u8 pad1205[3];
    s32 f1208;
    s32 f120C;
    s32 f1210;
    s32 f1214;
    u8 f1218;
    u8 f1219;
    u8 pad121A[0x1228 - 0x121A];
} DataBank;
extern DataBank sDataBanks[2];
extern u8 sDataBankFlags[];
extern u8 D_800E3F24[];
extern s32 sDataBankMode;
extern u8 sDataBankMesgQueue[];
extern u8 D_8010086C;
extern void func_80088F6C(void);
extern s32 (*gDataBankAlloc)(s32, s32);
extern s32 sDataBankAux;
extern u32 sDataBankCount;
extern u8 sDataBankInitialised;
extern u8 *sDataBankTable;
s32 func_80087F60(s32);
s32 func_800936A8(s32);
void func_8009D510(void *, s32, s32, s32, void *);
void flushDCacheRange(s32, s32);
void osCreateMesgQueue(void *, void *, s32);
void osRecvMesg(void *, s32, s32);
void osSendMesg(void *, s32, s32);

s32 func_80088040(u32 arg0, u32 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5, u8 arg6) {
    s32 idx;
    s32 a0;
    s32 v0;
    DataBank *b;

    if (sDataBankInitialised != 0 && arg0 < sDataBankCount) {
        s32 off;
        for (idx = 0, off = 0; idx < 2; idx++, off += 0x1228) {
            if (sDataBankFlags[off] == 0) break;
        }
        if (idx == 2) return -1;
        b = &sDataBanks[idx];
        osCreateMesgQueue(b->f11E0, b->f11F8, 2);
        if (arg1 == 0) {
            arg1 = 0x3E80;
            if (*(sDataBankTable + arg0 * 4) == 0) arg1 = 0x1F40;
        }
        b->f1204 = arg2;
        b->f1201 = arg3;
        b->f1202 = arg4;
        b->f1203 = arg5;
        b->f1219 = arg6;
        b->f1208 = arg1;
        a0 = (((arg1 * 8) / 30 + 0x9F) / 160) * 0xA0;
        b->f1214 = a0;
        if (sDataBankMode & 1) {
            b->f1210 = *(s32 *)(D_800E3F24 + idx * 4);
        } else {
            v0 = func_800936A8(a0);
            a0 = gDataBankAlloc(v0, 0);
            b->f1210 = a0;
            flushDCacheRange(a0, v0);
        }
        if (b->f1210 == 0) return -1;
        osRecvMesg(sDataBankMesgQueue, 0, 1);
        func_8009D510(b, (*(s32 *)(sDataBankTable + arg0 * 4) & 0xFFFFFF) + sDataBankAux, b->f1210, b->f1214, func_80088F6C);
        if (D_8010086C != 0) b->f11DE = b->f11DE * 2;
        b->f120C = -1;
        b->active = 1;
        osSendMesg(sDataBankMesgQueue, 0, 0);
        return func_80087F60(idx);
    }
    return -1;
}
