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

s32 findEntryPayload(s32, M2C_UNK);                 /* extern */
M2C_UNK formatTextEntry(s32, M2C_UNK *, s32);       /* extern */
s32 lookupDataEntry(M2C_UNK);                       /* extern */
s32 menuItemIsActive(M2C_UNK);                      /* extern */
M2C_UNK updateActiveMenuState();                    /* extern */
extern u8 D_80112F7F;
extern u8 D_80112F80;
extern u8 D_80112F81;
extern s8 gSaveKeyRelaxed;
extern void *gSaveMenuState;
extern u8 gSceneType;
extern M2C_UNK sFmtEntryName;

/* Fills the title and body text entries of the help page selected by gSceneType, and steps to the previous/next page when the page's advance flag is clear. */ void updateHelpPageText(void) {
    M2C_UNK bodyTextId;
    s32 bodyEntry;
    s32 titleEntry;
    

    if (M2C_FIELD(gSaveMenuState, u8 *, 0x2F) == 0) {
        updateActiveMenuState();
    }
    if (M2C_FIELD(gSaveMenuState, u8 *, 0x2D) != 0) {
        titleEntry = findEntryPayload(M2C_FIELD(gSaveMenuState, s32 *, 0x10), 0x5D);
        if (titleEntry != 0) {
            gSaveKeyRelaxed = 0;
            bodyEntry = titleEntry + 0x28;
            switch (gSceneType) {
            case 0:
                formatTextEntry(titleEntry, &sFmtEntryName, lookupDataEntry(0x81));
                bodyTextId = 0x8A;
block_20:
                formatTextEntry(bodyEntry, &sFmtEntryName, lookupDataEntry(bodyTextId));
                break;
            case 1:
                gSaveKeyRelaxed = 1;
                formatTextEntry(titleEntry, &sFmtEntryName, lookupDataEntry(0x82));
                bodyTextId = 0x8B;
                {
                formatTextEntry(bodyEntry, &sFmtEntryName, lookupDataEntry(bodyTextId));break;}
            case 2:
                gSaveKeyRelaxed = 1;
                formatTextEntry(titleEntry, &sFmtEntryName, lookupDataEntry(0x84));
                bodyTextId = 0x8D;
                {
                formatTextEntry(bodyEntry, &sFmtEntryName, lookupDataEntry(bodyTextId));break;}
            case 3:
                gSaveKeyRelaxed = 1;
                formatTextEntry(titleEntry, &sFmtEntryName, lookupDataEntry(0x85));
                formatTextEntry(bodyEntry, &sFmtEntryName, lookupDataEntry(0x8E));
                if (D_80112F80 == 0) {
                    M2C_FIELD(gSaveMenuState, u8 *, 0x2F) = 1U;
                    if (menuItemIsActive(0x21) & 0xFF) { gSceneType = gSceneType + 1; } else { gSceneType = gSceneType - 1; }
block_25:
                    updateHelpPageText();
                }
                break;
            case 4:
                formatTextEntry(titleEntry, &sFmtEntryName, lookupDataEntry(0x83));
                bodyTextId = 0x8C;
                {
                formatTextEntry(bodyEntry, &sFmtEntryName, lookupDataEntry(bodyTextId));break;}
            case 5:
                gSaveKeyRelaxed = 1;
                formatTextEntry(titleEntry, &sFmtEntryName, lookupDataEntry(0x182));
                formatTextEntry(bodyEntry, &sFmtEntryName, lookupDataEntry(0x183));
                if (D_80112F7F == 0) {
                    M2C_FIELD(gSaveMenuState, u8 *, 0x2F) = 1U;
                    gSceneType = (menuItemIsActive(0x21) & 0xFF) ? gSceneType + 1 : gSceneType - 1;
                    updateHelpPageText();
                }
                break;
            case 6:
                gSaveKeyRelaxed = 1;
                formatTextEntry(titleEntry, &sFmtEntryName, lookupDataEntry(0x87));
                bodyTextId = 0x90;
                {
                formatTextEntry(bodyEntry, &sFmtEntryName, lookupDataEntry(bodyTextId));break;}
            case 7:
                formatTextEntry(titleEntry, &sFmtEntryName, lookupDataEntry(0x86));
                bodyTextId = 0x8F;
                {
                formatTextEntry(bodyEntry, &sFmtEntryName, lookupDataEntry(bodyTextId));break;}
            case 8:
                formatTextEntry(titleEntry, &sFmtEntryName, lookupDataEntry(0x88));
                formatTextEntry(bodyEntry, &sFmtEntryName, lookupDataEntry(0x91));
                if (D_80112F81 == 0) {
                    M2C_FIELD(gSaveMenuState, u8 *, 0x2F) = 1U;
                    if (menuItemIsActive(0x21) & 0xFF) {
                        gSceneType = 0;
                    } else {
                        { u8 *__repair_byte_address = &gSceneType; *__repair_byte_address -= 1; }
                    }
                    {
                    updateHelpPageText();break;}
                }
                break;
            }
            goto block_26;
        }
    } else {
block_26:
        M2C_FIELD(gSaveMenuState, u8 *, 0x2F) = 0U;
    }
}
