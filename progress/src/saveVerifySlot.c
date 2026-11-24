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

typedef struct {
    u8 bytes[32];
} SaveResponse;

extern SaveResponse gSaveBackup;
extern SaveResponse gSaveHeaderCopy;
s32 saveWaitCommand();
s32 saveRefreshStatus();
s32 saveSubmitCommand();
s32 memset();
extern u16 gSaveStatus;
extern char gRumblePaks[];
extern s16 gSaveSlot;
extern char D_800E096C[];
extern char D_800E0970[];
extern s32 gSaveCmdResult;
extern s16 gSaveSlotValid[];

/* Verifies the current save slot, rewriting or restoring it as needed; returns a result code. */ /* Runs the save-slot check for the current slot and returns a result code (0xA4/0xA5/0x63/0x62/0x10) or the stored status word. */ u16 saveVerifySlot(void) {
    u16 slotStatus;
    u16 unused;

    slotStatus = saveRefreshStatus() & 0xFFFF;
    if (slotStatus == 0) {
        goto start;
    }
    if (slotStatus == 0x62) {
        goto start;
    }
    return gSaveStatus;
start:
    {
        saveSubmitCommand(3, (gSaveSlot * 0x68) + gRumblePaks, D_800E096C, D_800E0970, 0, 0, 0, 0);
        if (saveWaitCommand() == 0) {
            if (gSaveSlot == 0) {
                gSaveBackup = gSaveHeaderCopy;
            }
            return 0xA4;
        }
        if (gSaveSlot == 0) {
            memset(&gSaveBackup, 0, 0x20);
        }
        saveSubmitCommand(0xC, (gSaveSlot * 0x68) + gRumblePaks, (s32 *) gSaveSlot, NULL, 0, 0, 0, 0);
        if (saveWaitCommand() == 0) {
            gSaveSlotValid[gSaveSlot] = 1;
            return 0xA5U;
        }
        saveSubmitCommand(0xE, (gSaveSlot * 0x68) + gRumblePaks, (s32 *) gSaveSlot, NULL, 0, 0, 0, 0);
        if (saveWaitCommand() == 0) {
            return 0x63U;
        }
        if (gSaveCmdResult == 0xB) {
            return 0x62;
        }
        return 0x10;
    }
}

