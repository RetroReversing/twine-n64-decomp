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

s32 func_80011950();
s16 osContInit();
s32 osContStartReadData();
s32 osCreateMesgQueue();
s16 osEepromProbe();
s32 osSetEventMesg();
extern s16 gSaveFoundSlot;
extern char D_800E0760[];
extern char D_800E0768[];
extern s16 D_800E0930;
extern s16 D_800E093E;
extern s32 D_800E0960;
extern s16 D_800E097E;
extern s16 D_800E099E;
extern s16 D_800E09A6;
extern s16 D_800E09AE;
extern s16 D_800E09B0;
extern s16 gSaveDisabled;
extern s16 gSaveCmdPending;
extern s16 D_80100908;
extern s8 D_80102D60;
extern s16 D_801083D4;
extern u8 D_80108F75;
extern s16 gSaveSlotValid;
extern s16 gSaveRecovering;
extern s16 D_8010A3A0;
extern char D_8010D298[];
extern u16 D_8010D430;
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
    pendingRead = &D_801083D4;
    controllerState = &D_8010A3A0;
    mesgQueueCount = &D_800E09A6;
    saveCmdState = &D_800E099E;
    saveCmdCount = &D_800E097E;
    saveSlotValid = &gSaveSlotValid;
    saveSlotCount = &D_800E0930;
    D_80102D60 = 1;
    D_800E09AE = 0;
    gSaveFoundSlot = -1;
    D_800E09B0 = 0;
    gSaveCmdPending = 0;
    D_8010D540 = 0;
    D_800E0960 = 0;
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
    osCreateMesgQueue(D_8010D298, D_800E0760, 1, mesgQueueCount);
    osSetEventMesg(5, D_8010D298, 1);
    gSaveDisabled = osContInit(D_8010D298, &D_80108F75, D_800E0768);
    D_80100908 = osEepromProbe(D_8010D298);
    osContStartReadData(D_8010D298);
    D_800E09AE = 1;
    func_80011950();
    gSaveRecovering = 0;
    if (D_8010D430 & 0x1000) {
        gSaveRecovering = 1;
    }
    return D_80108F75;
}
