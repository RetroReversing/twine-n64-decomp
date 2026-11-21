/* machine draft (m2c) for gcc-2.7.2-kmc -G8 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

s32 saveDataEncodeName();
s16 func_80010958();
s32 saveWaitCommand();
s32 func_80010B60();
s32 saveSubmitCommand();
s32 func_8001233C();
extern s16 gSaveStatus;
extern char gSaveSlotTable[];
extern s16 gSaveSlot;
extern s32 *D_800E0960;
extern s16 *D_800E0964;
extern s32 gSaveRequestSlot;
extern char D_80103030[];
extern s32 D_80103042;
extern s32 gSaveCmdResult;
extern char D_80107B68[];
extern char D_8010840C[];
extern char D_80108410[];
extern char D_80108416[];
extern char D_8010A3C5[];
extern s32 D_80115308;

/* Runs the staged save/load step sequence, checking status after each step; returns the final status. */ /* Runs the staged save/load step sequence (calls 0x6, 0xA, 0x9, 0xB via saveSubmitCommand), checking saveWaitCommand after each step; returns the final status. */ s32 saveDataRunSteps(void) {
    s32 block_offset;

    gSaveStatus = 0;
    saveDataEncodeName(&D_80115308, D_80103030, 0x10);
    saveDataEncodeName(&D_80103042, D_8010A3C5, 4);
    if ((*(u16 *)(D_80107B68 + (gSaveRequestSlot * 0x18)) == 0) || (block_offset = gSaveRequestSlot << 5, saveSubmitCommand(6, (gSaveSlot * 0x68) + gSaveSlotTable, *(u16 *)(D_80108410 + block_offset), *(s32 *)(D_8010840C + block_offset), block_offset + D_80108416, block_offset + (D_80108416 - 4), NULL, NULL), (saveWaitCommand() == 0))) {
        saveSubmitCommand(0xA, (gSaveSlot * 0x68) + gSaveSlotTable, 0x3639U, 0x4E4F3745, &D_80115308, &D_80103042, D_800E0960, &gSaveRequestSlot);
        if (saveWaitCommand() == 0) {
            *D_800E0964 = func_80010958((s8 *) D_800E0964 + 2, (s8 *)D_800E0960 - 2);
            saveSubmitCommand(9, (gSaveSlot * 0x68) + gSaveSlotTable, gSaveRequestSlot, 1, NULL, D_800E0960, D_800E0964, NULL);
            if (saveWaitCommand() == 0) {
                saveSubmitCommand(0xB, (gSaveSlot * 0x68) + gSaveSlotTable, 0x3639U, 0x4E4F3745, &D_80115308, &D_80103042, &gSaveRequestSlot, NULL);
                if (saveWaitCommand() == 0) {
                    return func_8001233C() & 0xFFFF;
                }
            }
        }
    }
    return func_80010B60(gSaveCmdResult) & 0xFFFF;
}
