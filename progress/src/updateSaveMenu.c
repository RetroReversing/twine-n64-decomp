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

s32 checkSaveSlotMode();
u16 saveMenuStateCallback();
u16 saveMenuHandleCommand();
u16 handleSaveMenuEvent();
s32 findEntryById();
s32 findTableIndexById();
s32 setSaveMenuState();
s32 updateActiveMenuState();
s32 updateSaveMenuRowHighlight();
s32 getSaveSlotHeadersLow16();
extern u16 sSaveMenuAction;
extern u8 sSaveMenuSlot;
extern s8 sSaveMenuRefresh;
extern s32 sActiveMenu;
extern char gSaveMenuObjectPool[];
extern u8 D_80107EC0;
extern void *gSaveMenuState;

typedef struct { unsigned char pad[16]; int value; } __repair_field_10;
/* Per-frame save menu update: refreshes the slot label and dispatches the pending save action. */ /* Updates the active menu; if a reload is pending, reloads the data entry table, resets default player names and reselects the current item. */ /* Per-frame save menu update: refreshes the slot label and dispatches the pending save action. */ void updateSaveMenu(void) {
    s32 actionFlags;
    s32 actionCmd;

    sSaveMenuRefresh = 1;
    if (findEntryById(((__repair_field_10 *)gSaveMenuState)->value, 0x54) != 0) {
        if (M2C_FIELD(gSaveMenuState, u8 *, 0x2E) == 0) {
            M2C_FIELD(M2C_FIELD(gSaveMenuState, void **, 0x18), s8 *, 0x24) = (s8) ((sSaveMenuSlot + findTableIndexById(((__repair_field_10 *)gSaveMenuState)->value, 0x54)) - 1);
        }
    }
    if ((M2C_FIELD(gSaveMenuState, u8 *, 0x2C) != 0) && (M2C_FIELD(gSaveMenuState, u8 *, 0x2E) == 0)) {
        checkSaveSlotMode(sSaveMenuAction);
        actionFlags = sSaveMenuAction & 0xE000;
        if (sSaveMenuAction & 0x1000) {
            updateActiveMenuState(actionFlags);
            if (getSaveSlotHeadersLow16() & 0xFFFF) {
                setSaveMenuState(sActiveMenu, 0x18);
            }
        } else {
            actionCmd = sSaveMenuAction & 0xFFF;
            switch (actionCmd) {                      /* irregular */
            case 1:
                sSaveMenuAction = saveMenuStateCallback(actionFlags, D_80107EC0);
                return;
            case 2:
                sSaveMenuAction = saveMenuHandleCommand(actionFlags, D_80107EC0);
                return;
            case 3:
                sSaveMenuAction = handleSaveMenuEvent(actionFlags, D_80107EC0);
                return;
            }
        }
    } else {
        updateActiveMenuState();
        updateSaveMenuRowHighlight(gSaveMenuObjectPool, 2, 0);
        checkSaveSlotMode(sSaveMenuAction);
    }
}
