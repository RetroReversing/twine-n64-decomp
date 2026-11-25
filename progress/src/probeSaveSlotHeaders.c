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
s32 loadSaveSlotHeaders();
extern u16 gSaveStatus;
extern char gRumblePaks[];
extern s16 gSaveSlotIndex;
extern s16 gSaveSlot;
extern s32 gSaveCmdResult;

/* Loads the save slot headers and returns a save status: 0x25 on error 0x62; on 0x20 it submits command 8 for the current slot, then reports 0x21 or 0x22 on failure. */ s32 probeSaveSlotHeaders(void) {
    gSaveSlot = 0;
    switch (loadSaveSlotHeaders() & 0xFFFF) {
    case 0x62:
        gSaveStatus = 0x25;
        break;
    case 0x20:
        saveSubmitCommand(8, (gSaveSlotIndex * 0x68) + gRumblePaks, 0, 0, 0, 0, 0, 0);
        saveWaitCommand();
        if (gSaveCmdResult == 0xA) {
            gSaveStatus = 0x21;
            return 0x21;
        }
        if ((loadSaveSlotHeaders() & 0xFFFF) == 0x12) {
            gSaveStatus = 0x22;
            return 0x22;
        }
        break;
    }
    return gSaveStatus;
}
