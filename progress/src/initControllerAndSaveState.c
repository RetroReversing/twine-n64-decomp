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

s32 pollControllersAndRunSaveCommand();
s16 osContInit();
s32 osContStartReadData();
s32 osCreateMesgQueue();
s16 osEepromProbe();
s32 osSetEventMesg();
extern s16 gSaveFoundSlot;
extern char D_800E0760[];
extern char D_800E0768[];
extern s16 gMenuSlotValues;
extern s16 D_800E093E;
extern s32 gSaveBufferSize;
extern s16 gSlotValues;
extern s16 gSlotValues2;
extern s16 D_800E09A6;
extern s16 D_800E09AE;
extern s16 D_800E09B0;
extern s16 gSaveDisabled;
extern s16 gSaveCmdPending;
extern s16 D_80100908;
extern s8 D_80102D60;
extern s16 gSaveSlotAltFlags;
extern u8 gSavePresentMask;
extern s16 gSaveSlotValid;
extern s16 gSaveRecovering;
extern s16 gRumbleFlags;
extern char gSiMesgQueue[];
extern u16 gDemoButtons;
extern s16 D_8010D540;

/* Clears controller and save-slot state tables, creates the controller message queue, and starts controller/EEPROM probing. */ u8 initControllerAndSaveState(void) {
    char *saveSlotValid;
    char *saveCmdCount;
    char *saveCmdState;
    char *mesgQueueCount;
    char *controllerState;
    char *pendingRead;
    char *saveSlotCount;
    s32 i;
    s32 defaultValue;

    i = 0;
    defaultValue = 2;
    pendingRead = &gSaveSlotAltFlags;
    controllerState = &gRumbleFlags;
    mesgQueueCount = &D_800E09A6;
    saveCmdState = &gSlotValues2;
    saveCmdCount = &gSlotValues;
    saveSlotValid = &gSaveSlotValid;
    saveSlotCount = &gMenuSlotValues;
    D_80102D60 = 1;
    D_800E09AE = 0;
    gSaveFoundSlot = -1;
    D_800E09B0 = 0;
    gSaveCmdPending = 0;
    D_8010D540 = 0;
    gSaveBufferSize = 0;
    D_800E093E = 0;
    __repair_rows: {
        *(s16 *)saveSlotCount = 0;
        *(s16 *)saveSlotValid = 0;
        *(s16 *)saveCmdCount = 0;
        *(s16 *)saveCmdState = 0;
        *(s16 *)mesgQueueCount = 0;
        *(s16 *)controllerState = defaultValue;
        *(s16 *)pendingRead = 0;
        pendingRead += 2;
        controllerState += 2;
        mesgQueueCount += 2;
        saveCmdState += 2;
        saveCmdCount += 2;
        saveSlotValid += 2;
        i += 1;
        saveSlotCount += 2;
    }
if (i < 4) goto __repair_rows;
    osCreateMesgQueue(gSiMesgQueue, D_800E0760, 1, mesgQueueCount);
    osSetEventMesg(5, gSiMesgQueue, 1);
    gSaveDisabled = osContInit(gSiMesgQueue, &gSavePresentMask, D_800E0768);
    D_80100908 = osEepromProbe(gSiMesgQueue);
    osContStartReadData(gSiMesgQueue);
    D_800E09AE = 1;
    pollControllersAndRunSaveCommand();
    gSaveRecovering = 0;
    if (gDemoButtons & 0x1000) {
        gSaveRecovering = 1;
    }
    return gSavePresentMask;
}
