#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#endif

M2C_UNK func_8002778C();
M2C_UNK setSaveMenuPage(M2C_UNK, M2C_UNK, M2C_UNK);
s32 isMenuButtonPressed(M2C_UNK);
extern void *gSaveMenuState;

/* Per-frame save-menu update: if either of two flags is set, runs the exit sequence; otherwise clears a state byte and calls the current menu state's optional handlers. */
void updateSaveMenuState(void) {
    M2C_UNK (*onUpdate)();
    M2C_UNK (*onEvent)();
    void *eventTable;

    if ((isMenuButtonPressed(0x23) & 0xFF) || (isMenuButtonPressed(0x24) & 0xFF)) {
        func_8002778C();
        setSaveMenuPage(0, 0, 0x12);
        return;
    }
    M2C_FIELD(gSaveMenuState, s8 *, 0x2E) = 0;
    if (gSaveMenuState != NULL) {
        eventTable = M2C_FIELD(gSaveMenuState, void **, 0x18);
        onEvent = M2C_FIELD(eventTable, M2C_UNK (**)(), 4);
        if ((onEvent != NULL) && (M2C_FIELD(eventTable, u16 *, 0xC) & 0x80)) {
            onEvent();
        }
        if (gSaveMenuState != NULL) {
            onUpdate = M2C_FIELD(M2C_FIELD(gSaveMenuState, void **, 0x10), M2C_UNK (**)(), 0x10);
            if (onUpdate != NULL) {
                onUpdate();
            }
        }
    }
}
