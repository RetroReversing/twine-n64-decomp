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

s32 func_80010B60(s32);                             /* extern */
s32 func_80012F50();                                /* extern */
s32 saveFindTaggedSlot();                           /* extern */
M2C_UNK saveSubmitCommand(M2C_UNK, void *, s16, M2C_UNK, s32, s32, s32, s32); /* extern */
s32 saveVerifySlot(s32, s16, s16 *);                /* extern */
M2C_UNK saveWaitCommand();                          /* extern */
extern M2C_UNK D_800E0768;
extern M2C_UNK D_800E076A;
extern M2C_UNK D_800E076B;
extern s16 D_800E0938;
extern s16 D_800E093C;
extern s16 D_800E093E;
extern M2C_UNK D_801083D4;
extern u8 D_80108F75;
extern s8 D_8010A3C6;
extern s8 D_8010A3C7;
extern s8 D_8010A3C8;
extern s32 gSaveCmdResult;
extern s16 gSaveSlot;
extern s8 gSaveSlotCodeBuf;
extern M2C_UNK gSaveSlotFlags;
extern s16 gSaveSlotLoaded;
extern M2C_UNK gSaveSlotTable;
extern M2C_UNK gSaveSlotValid;
extern u16 gSaveStatus;

u16 func_80012C70(void) {
    M2C_UNK *__base_D_800E0768;
    s16 *temp_a2;
    s16 temp_v0_2;
    s32 temp_a0;
    s32 temp_v0;
    s32 var_s0;
    int temp_v1;

    var_s0 = -1;
    gSaveSlotCodeBuf = 0;
    D_8010A3C6 = 0;
    D_8010A3C7 = 0;
    D_8010A3C8 = 0;
    D_800E093E = 0;
    gSaveSlot = 0;
    D_800E093C = -1;
    D_800E093E = 0;
    D_800E0938 = -1;
    saveSubmitCommand(0xD, NULL, 0, 0, 0, 0, 0, 0);
    saveWaitCommand();
    gSaveSlot = 0;
loop_1:
    temp_v0 = gSaveSlot * 2;
    temp_a2 = (void *)(temp_v0); temp_a2 = (void *)((char *)temp_a2 + (s32)(&gSaveSlotFlags));
    temp_a0 = gSaveSlot * 4;
    *temp_a2 = 0;
    (&gSaveSlotLoaded)[gSaveSlot] = 0;
    ((u16 *) &gSaveSlotValid)[gSaveSlot] = 0;
    ((s16 *) &D_801083D4)[gSaveSlot] = 0;
    __base_D_800E0768 = &D_800E0768;
    if ((*(&D_800E076B + temp_a0) == 0) && (((s32) D_80108F75 >> gSaveSlot) != 0) && (((*(__base_D_800E0768 + temp_a0) & 0x1F07) != 5) || (*temp_a2 = 1, ((*(&D_800E076A + temp_a0) & 1) != 0)))) {
        temp_v1 = saveVerifySlot(temp_a0, gSaveSlot, temp_a2) & 0xFFFF;
        switch (temp_v1) {                          /* irregular */
        case 0xA4:
            if ((var_s0 != 0) && (gSaveSlot == 0)) {
                var_s0 = 0;
                gSaveSlotLoaded = 1;
                if (!(func_80012F50() & 0xFFFF) && (saveFindTaggedSlot() & 0xFFFF)) {
                    gSaveStatus = 0x30;
                }
            }
            goto block_22;
        case 0xA5:
            saveSubmitCommand(0xC, (gSaveSlot * 0x68) + &gSaveSlotTable, gSaveSlot, 0, 0, 0, 0, 0);
            saveWaitCommand();
            goto block_22;
        default:
        case 0x12:
            if (gSaveSlot == 0) {
                return temp_v1;
            }
            goto block_22;
        case 0x20:
            if (gSaveSlot != 0) {
                goto block_22;
            }
            return func_80010B60(gSaveCmdResult) & 0xFFFF;
        }
    } else {
block_22:
        temp_v0_2 = (u16) gSaveSlot + 1;
        gSaveSlot = temp_v0_2;
        if (temp_v0_2 >= 4) {
            if (var_s0 == 0) {
                gSaveSlot = 0;
            } else {
                var_s0 = -1;
            }
            if (var_s0 < 0) {
                gSaveStatus = 0x10;
            }
            return gSaveStatus;
        }
        goto loop_1;
    }
}
