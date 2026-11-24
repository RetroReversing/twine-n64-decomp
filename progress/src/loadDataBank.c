s32 dmaRomToRam();

extern u8 sDataBankInitialised;
extern u8 sDataBankLoaded;
extern s32 sDataBankBase;
extern s32 sDataBankAux;
extern s32 *sDataBankTable;
extern s32 sDataBankCount;
extern s32 (*gDataBankTranslate)(s32);
extern s32 *(*gDataBankHandler)(s32, s32);
extern s32 (*gDataBankFree)(s32 *);

/* Loads the data bank table from arg0 (ROM or RAM address) and copies its data into a new buffer; returns 1 on success. */
s32 loadDataBank(s32 romAddr, s32 auxAddr) {
    s32 *countBuf;
    s32 *tableBuf;
    s32 base;

    if (sDataBankInitialised != 0) {
        if ((sDataBankTable != NULL) && (sDataBankLoaded != 0)) {
            gDataBankFree(sDataBankTable);
        }
        if ((romAddr & 0xF0000000) != 0x80000000) {
            base = gDataBankTranslate(romAddr);
            sDataBankBase = base;
            sDataBankAux = base;
            countBuf = gDataBankHandler(4, 0);
            if (countBuf != NULL) {
                dmaRomToRam(countBuf, sDataBankBase, 4);
                sDataBankCount = *countBuf;
                gDataBankFree(countBuf);
                tableBuf = gDataBankHandler(sDataBankCount * 4, 0);
                sDataBankTable = tableBuf;
                if (tableBuf != NULL) {
                    dmaRomToRam(tableBuf, sDataBankBase + 4, sDataBankCount * 4);
                    sDataBankLoaded = 1;
                    goto ok;
                }
            }
            goto block_9;
        }
        sDataBankBase = romAddr;
        sDataBankAux = gDataBankTranslate(auxAddr);
        sDataBankTable = romAddr + 4;
        sDataBankCount = *(s32 *)romAddr;
        sDataBankLoaded = 0;
ok:
        return 1;
    }
block_9:
    return 0;
}
