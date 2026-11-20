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
extern s32 D_800E0978;
extern s32 gSaveCmdResult;
extern char D_80107B68[];
extern char D_80108408[];
extern char D_8010840C[];
extern char D_80108410[];
extern char D_80108416[];

u16 func_800128C0(s32 arg0) {
    s32 temp_a0;
    s32 temp_a1;

    temp_a0 = arg0 & 0xFFFF;
    D_800E0978 = temp_a0;
    gSaveStatus = 4;
    if (!(func_80012F50(temp_a0) & 0xFFFF)) {
        if (*(u16 *)(D_80107B68 + (D_800E0978 * 0x18)) == 0) {
            gSaveStatus = 0x80;
            return 0x80U;
        }
        temp_a1 = D_800E0978 << 5;
        saveSubmitCommand(6, (gSaveSlot * 0x68) + gSaveSlotTable, *(u16 *)(D_80108410 + temp_a1), *(s32 *)(D_8010840C + temp_a1), temp_a1 + D_80108416, temp_a1 + (D_80108416 - 4), 0, 0);
        if (saveWaitCommand() != 0) {
            return func_80010B60(gSaveCmdResult) & 0xFFFF;
        }
        *(s32 *)(D_80108408 + (D_800E0978 << 5)) = 0;
        if (!(func_80012F50() & 0xFFFF)) {
            gSaveStatus = 4;
            return 4U;
        }
        goto block_7;
    }
block_7:
    return gSaveStatus;
}
