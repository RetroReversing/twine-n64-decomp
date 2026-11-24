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
s32 saveSubmitCommand();
extern char gSaveSlotTable[];
extern char gSaveSlotValid[];

/* Queries each of the 4 save slots and marks it valid if the save command succeeds. */ void validateSaveSlots(void) {
    s16 *validFlag;
    u16 slot;

    for (slot = 0; slot < 4; slot++) {
        validFlag = (slot * 2) + gSaveSlotValid;
        *validFlag = 0;
        saveSubmitCommand(0xC, (slot * 0x68) + gSaveSlotTable, slot, 0, 0, 0, 0, 0);
        if (saveWaitCommand() == 0) {
            *validFlag = 1;
        }
    }
}
