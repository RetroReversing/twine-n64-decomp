/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 formatTextEntry();
s32 updateActiveMenuState();
s32 lookupDataEntry();
extern s32 gBonusGoalTarget;
extern s32 gMenuOptionTable;
extern void *gSaveMenuState;
extern s32 gMenuOptionIndex;

extern char D_800D2858[];
extern char sFmtEntryName[];
/* Updates the selected bonus goal from the menu option table and writes its label: the number if nonzero, else the default name string. */ void refreshBonusGoalLabel(void) {
    u16 goalValue;

    updateActiveMenuState();
    if ((*(u8 *)((char *)(gSaveMenuState) + 0x2D)) != 0) {
        goalValue = *(u16 *)((gMenuOptionIndex * 2) + gMenuOptionTable);
        gBonusGoalTarget = goalValue;
        if (goalValue != 0) {
            formatTextEntry((*(s32 *)((char *)(gSaveMenuState) + 0x18)) + 0x28, D_800D2858, goalValue);
        } else {
            formatTextEntry((*(s32 *)((char *)(gSaveMenuState) + 0x18)) + 0x28, sFmtEntryName, lookupDataEntry(0x5F));
        }
    }
}
