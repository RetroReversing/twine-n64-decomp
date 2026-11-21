s32 func_8000A18C(); s32 func_8000A22C(); s32 func_8000A6F4(); s32 heapAllocBlock(); s32 func_8000B534(); s32 romDmaRead(); s32 loadDataBank(); s32 initDataBankBuffers(); s32 func_80092A68(); s32 func_80095820(); s32 func_8009CE34(); s32 func_8009CF18(); s32 func_8009D030();
extern char D_14CD630[],D_14D0ED0[],D_14DDC00[],D_14E2500[],D_1D69630[],D_800B2488[],D_800B256C[],D_800DD7D0[];
extern char D_014D0ED0[], D_014DDC00[], D_014E2500[];
extern s32 D_800B2480,sCurrentDistanceSoundId,D_800E06FC,D_800E0700,D_800E0704,sDistanceSoundResult; extern s32 *sDistanceSoundArg; extern s16 gExpansionPakPresent;
/* Sets up the game's data banks and tables from ROM ranges, then loads the main data bank. */ s32 initGameDataBanks(void) {
    s32 result;
    s32 bankSize;
    s32 bankId;
    s32 entryOffset;
    s32 expansionPakMask = (gExpansionPakPresent != 0);
    expansionPakMask = -expansionPakMask & 0x140000;
    if (func_80095820(0x5622, 0x14, 0xA, 0xA, 0xFA, expansionPakMask) != 0) {
        return 0;
    }
    bankSize = D_014D0ED0 - D_14CD630;
    bankId = heapAllocBlock(bankSize, 0);
    D_800E06FC = bankId;
    romDmaRead(bankId, (s32)D_14CD630 & 0x0FFFFFFF, bankSize);
    bankSize = D_014DDC00 - D_14D0ED0;
    bankId = heapAllocBlock(bankSize, 0);
    D_800E0700 = bankId;
    romDmaRead(bankId, (s32)D_14D0ED0 & 0x0FFFFFFF, bankSize);
    bankSize = D_014E2500 - D_14DDC00;
    bankId = heapAllocBlock(bankSize, 0);
    D_800E0704 = bankId;
    romDmaRead(bankId, (s32)D_14DDC00 & 0x0FFFFFFF, bankSize);
    func_80092A68(D_800E06FC, 0, D_14E2500, D_800E0704, D_800E0700);
    entryOffset = 0;
    if (D_800B2480 != 0) {
        do {
            s32 tableA = D_800E06FC;
            u16 entryId = *(u16 *)(D_800B2488 + entryOffset);
            s32 tableC = D_800E0704;
            s32 tableB = D_800E0700;
            char *romTable = D_14E2500;
            func_80092A68(tableA, entryId, romTable, tableC, tableB);
            entryOffset += 0xC;
        } while (*(s32 *)((char *)&D_800B2480 + entryOffset) != 0);
    }
    func_8009CE34(0xE7, 0);
    func_8009CE34(0xE8, 0);
    func_8009CE34(0xE9, 0);
    func_8009CE34(0xEA, 0);
    func_8009CE34(0xEB, 0);
    func_8009CE34(0xEC, 0);
    func_8009CE34(0xED, 0);
    func_8009CE34(0xEE, 0);
    func_8009CF18(0x7F, 0, 0);
    func_8009CE34(0x1B8, 1);
    initDataBankBuffers(1);
    loadDataBank(D_1D69630, 0);
    func_8009D030(D_800B256C);
    sDistanceSoundResult = -1;
    sDistanceSoundArg = (s32 *)D_800DD7D0;
    func_8000A6F4();
    sCurrentDistanceSoundId = -1;
    result = func_8000B534();
    func_8000A18C(0xA);
    func_8000A22C(0xA);
    return result;
}

