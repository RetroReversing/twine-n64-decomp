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

s32 saveWaitCommand();
s32 func_80010B60();
s32 saveSubmitCommand();
s32 func_80012F50();
extern u16 gSaveStatus;
extern char gSaveSlotTable[];
extern s16 gSaveSlot;
extern s32 gSaveRequestSlot;
extern s32 gSaveCmdResult;
extern char gSaveSlotHeaders[];
extern char D_80108408[];
extern char D_8010840C[];
extern char D_80108410[];
extern char D_80108416[];

/* Loads the save in the given slot: scans saves, checks slot is in use, submits command 6, then clears the slot's entry. */ u16 saveLoadSlot(s32 slot) {
    s32 slotIndex;
    s32 slotOffset;

    slotIndex = slot & 0xFFFF;
    gSaveRequestSlot = slotIndex;
    gSaveStatus = 4;
    if (!(func_80012F50(slotIndex) & 0xFFFF)) {
        if (*(u16 *)(gSaveSlotHeaders + (gSaveRequestSlot * 0x18)) == 0) {
            gSaveStatus = 0x80;
            return 0x80U;
        }
        slotOffset = gSaveRequestSlot << 5;
        saveSubmitCommand(6, (gSaveSlot * 0x68) + gSaveSlotTable, *(u16 *)(D_80108410 + slotOffset), *(s32 *)(D_8010840C + slotOffset), slotOffset + D_80108416, slotOffset + (D_80108416 - 4), 0, 0);
        if (saveWaitCommand() != 0) {
            return func_80010B60(gSaveCmdResult) & 0xFFFF;
        }
        *(s32 *)(D_80108408 + (gSaveRequestSlot << 5)) = 0;
        if (!(func_80012F50() & 0xFFFF)) {
            gSaveStatus = 4;
            return 4U;
        }
        goto block_7;
    }
block_7:
    return gSaveStatus;
}
