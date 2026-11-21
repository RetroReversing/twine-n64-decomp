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

void func_8001A4F4(void) {
    M2C_UNK var_a0;
    s32 temp_s1;
    s32 temp_v0;
    

    if (M2C_FIELD(gSaveMenuState, u8 *, 0x2F) == 0) {
        updateActiveMenuState();
    }
    if (M2C_FIELD(gSaveMenuState, u8 *, 0x2D) != 0) {
        temp_v0 = findEntryPayload(M2C_FIELD(gSaveMenuState, s32 *, 0x10), 0x5D);
        if (temp_v0 != 0) {
            gSaveKeyRelaxed = 0;
            temp_s1 = temp_v0 + 0x28;
            switch (gSceneType) {
            case 0:
                formatTextEntry(temp_v0, &sFmtEntryName, lookupDataEntry(0x81));
                var_a0 = 0x8A;
block_20:
                formatTextEntry(temp_s1, &sFmtEntryName, lookupDataEntry(var_a0));
                break;
            case 1:
                gSaveKeyRelaxed = 1;
                formatTextEntry(temp_v0, &sFmtEntryName, lookupDataEntry(0x82));
                var_a0 = 0x8B;
                {
                formatTextEntry(temp_s1, &sFmtEntryName, lookupDataEntry(var_a0));break;}
            case 2:
                gSaveKeyRelaxed = 1;
                formatTextEntry(temp_v0, &sFmtEntryName, lookupDataEntry(0x84));
                var_a0 = 0x8D;
                {
                formatTextEntry(temp_s1, &sFmtEntryName, lookupDataEntry(var_a0));break;}
            case 3:
                gSaveKeyRelaxed = 1;
                formatTextEntry(temp_v0, &sFmtEntryName, lookupDataEntry(0x85));
                formatTextEntry(temp_s1, &sFmtEntryName, lookupDataEntry(0x8E));
                if (D_80112F80 == 0) {
                    M2C_FIELD(gSaveMenuState, u8 *, 0x2F) = 1U;
                    if (menuItemIsActive(0x21) & 0xFF) {
                        temp_s1 = gSceneType; temp_s1 += 1;
                    } else {
block_12:
                        temp_s1 = gSceneType - 1;
                    }
block_13:
                    gSceneType = temp_s1;
block_25:
                    func_8001A4F4();
                }
                break;
            case 4:
                formatTextEntry(temp_v0, &sFmtEntryName, lookupDataEntry(0x83));
                var_a0 = 0x8C;
                {
                formatTextEntry(temp_s1, &sFmtEntryName, lookupDataEntry(var_a0));break;}
            case 5:
                gSaveKeyRelaxed = 1;
                formatTextEntry(temp_v0, &sFmtEntryName, lookupDataEntry(0x182));
                formatTextEntry(temp_s1, &sFmtEntryName, lookupDataEntry(0x183));
                if (D_80112F7F == 0) {
                    M2C_FIELD(gSaveMenuState, u8 *, 0x2F) = 1U;
                    if (menuItemIsActive(0x21) & 0xFF) {
                        temp_s1 = gSceneType + 1;
                    } else {
                        goto block_12;
                    }
                    goto block_13;
                }
                break;
            case 6:
                gSaveKeyRelaxed = 1;
                formatTextEntry(temp_v0, &sFmtEntryName, lookupDataEntry(0x87));
                var_a0 = 0x90;
                {
                formatTextEntry(temp_s1, &sFmtEntryName, lookupDataEntry(var_a0));break;}
            case 7:
                formatTextEntry(temp_v0, &sFmtEntryName, lookupDataEntry(0x86));
                var_a0 = 0x8F;
                {
                formatTextEntry(temp_s1, &sFmtEntryName, lookupDataEntry(var_a0));break;}
            case 8:
                formatTextEntry(temp_v0, &sFmtEntryName, lookupDataEntry(0x88));
                formatTextEntry(temp_s1, &sFmtEntryName, lookupDataEntry(0x91));
                if (D_80112F81 == 0) {
                    M2C_FIELD(gSaveMenuState, u8 *, 0x2F) = 1U;
                    if (menuItemIsActive(0x21) & 0xFF) {
                        gSceneType = 0;
                    } else {
                        { u8 *__repair_byte_address = &gSceneType; *__repair_byte_address -= 1; }
                    }
                    {
                    func_8001A4F4();break;}
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
