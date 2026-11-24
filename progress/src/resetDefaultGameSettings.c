s32 updateVideoMode();
s32 resetMenuSlotsWrapper();
s32 setBonusSlotState(s32, s32);
extern s8 sDifficultyLevel;
extern s8 gExpansionModeEnabled;
extern s8 gTrackMarkerActiveMask;
extern s8 gSceneFlagsB;
extern s8 D_8010A4C3;
extern s8 D_8010A4C4;
extern s32 D_8010A4C8;
extern s32 D_8010A4CC;
extern s32 D_8010A4D0;
extern s32 gScissorEnabled;
extern s32 D_8010A4D8;
extern s32 D_8010A4DC;
extern s32 D_8010A4E0;
extern s32 gSceneLoaded;
extern s32 gHiResScreen;
extern s32 gFogColorOverrideEnabled;
extern s32 D_8010A4F0;
extern s32 D_8010A4F4;
extern s32 D_8010A4F8;
extern s32 D_80112F68;
extern s8 D_80112F6C;

/* Restores the default game-setting globals, then applies the video mode and resets four display slots. */
void resetDefaultGameSettings(void) {
    s16 slot;
    int var_s0;
    s32 var_a0;

    resetMenuSlotsWrapper();
    D_8010A4C4 = 1;
    gTrackMarkerActiveMask = 1;
    gSceneFlagsB = 0x1F;
    D_8010A4C3 = 0xF;
    sDifficultyLevel = 0;
    D_80112F68 = 0;
    D_80112F6C = 0;
    gExpansionModeEnabled = 0;
    D_8010A4C8 = 1;
    D_8010A4CC = 1;
    D_8010A4D0 = 1;
    gScissorEnabled = 1;
    D_8010A4D8 = 2;
    D_8010A4DC = 1;
    D_8010A4E0 = 1;
    gSceneLoaded = 1;
    gHiResScreen = 0;
    gFogColorOverrideEnabled = 0;
    D_8010A4F0 = 1;
    D_8010A4F4 = 0;
    D_8010A4F8 = 0;
    updateVideoMode();
    for (slot = 0; slot < 4; slot++) {
        setBonusSlotState(slot, 2);
    }
}
