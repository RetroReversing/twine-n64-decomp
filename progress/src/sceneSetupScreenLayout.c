extern s32 gVisibleSaveSlotCount;
extern u8 gSceneType;
extern u8 gBorderFlipFlag;
extern u16 gMenuTimerLabelX;
extern u16 gMenuTimerLabelY;
extern u16 D_8011ED44[];
extern u16 D_8011ED4C[];
extern u16 gViewportWidth;
extern u16 gViewportHeight;
extern u32 gMenuItemGrid[][4];
extern u32 gMenuItemList[];
extern u8 D_8011ED54[];
extern u32 sBonusMarkerNodes[];
extern u32 D_8011F040[];
s32 spawnTextNode(void *);
void createMenuCountdownWidget(void);
void setupSaveSlotMarkers(void);
void createSaveSlotMarkers(void);
void spawnSaveSlotMarkers(void);
void showMenuTimerLabel(void);
void setupPlayerHudLabels(void);

/* Sets the screen layout for the current border mode, clears scene tables and runs the scene's init. */
void sceneSetupScreenLayout(void) {
    u16 baseX, flipX;
    u16 i, j;

    if (gVisibleSaveSlotCount == 1) {
        gMenuTimerLabelY = 0xCA;
    } else {
        gMenuTimerLabelY = 0x76;
    }
    baseX = gMenuTimerLabelY;
    D_8011ED44[0] = 100;
    D_8011ED44[1] = 130;
    D_8011ED44[2] = 190;
    D_8011ED44[3] = 220;
    gViewportHeight = 120;
    D_8011ED4C[0] = baseX;
    D_8011ED4C[1] = baseX;
    D_8011ED4C[2] = baseX;
    D_8011ED4C[3] = baseX;
    switch (gVisibleSaveSlotCount) {
    case 1:
        gViewportWidth = 0x140;
        break;
    case 2: {
        if (gBorderFlipFlag == 1) {
            flipX = gMenuTimerLabelX;
            gViewportWidth = 0xA0;
            gViewportHeight = 0xF0;
            D_8011ED4C[0] = baseX - 22;
            D_8011ED4C[1] = baseX - 11;
            D_8011ED4C[2] = baseX + 11;
            D_8011ED4C[3] = baseX + 22;
            D_8011ED44[0] = flipX;
            D_8011ED44[1] = flipX;
            D_8011ED44[2] = flipX;
            D_8011ED44[3] = flipX;
            goto after;
        }
        gViewportWidth = 0x140;
        break;
    }
    default:
        gViewportWidth = 0xA0;
        break;
    }
after:
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            gMenuItemGrid[i][j] = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        gMenuItemList[(unsigned short)i] = 0;
    }
    switch (gSceneType) {
    case 8:
        for (i = 0; i < 3; i++) {
            sBonusMarkerNodes[i] = spawnTextNode(D_8011ED54 + i * 36);
        }
        createMenuCountdownWidget();
        break;
    case 6:
        setupSaveSlotMarkers();
        break;
    case 4:
    case 5:
        createSaveSlotMarkers();
        break;
    case 2:
    case 3:
        spawnSaveSlotMarkers();
        break;
    case 7:
        break;
    }
    showMenuTimerLabel();
    setupPlayerHudLabels();
}
