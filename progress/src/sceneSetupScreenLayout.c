extern s32 gVisibleSaveSlotCount;
extern u8 gSceneType;
extern u8 gBorderFlipFlag;
extern u16 D_8011ED40;
extern u16 D_8011ED42;
extern u16 D_8011ED44[];
extern u16 D_8011ED4C[];
extern u16 D_8011F0EC;
extern u16 D_8011F0EE;
extern u32 D_8011F2E8[][4];
extern u32 D_8011F3B8[];
extern u8 D_8011ED54[];
extern u32 sMarkerTextNode1[];
extern u32 D_8011F040[];
s32 spawnTextNode(void *);
void func_8011C4D8(void);
void setupSaveSlotMarkers(void);
void create_player_state_objects(void);
void func_8011CC3C(void);
void func_8011C430(void);
void func_8011D3C0(void);

/* Sets the screen layout for the current border mode, clears scene tables and runs the scene's init. */
void sceneSetupScreenLayout(void) {
    u16 baseX, flipX;
    u16 i, j;

    if (gVisibleSaveSlotCount == 1) {
        D_8011ED42 = 0xCA;
    } else {
        D_8011ED42 = 0x76;
    }
    baseX = D_8011ED42;
    D_8011ED44[0] = 100;
    D_8011ED44[1] = 130;
    D_8011ED44[2] = 190;
    D_8011ED44[3] = 220;
    D_8011F0EE = 120;
    D_8011ED4C[0] = baseX;
    D_8011ED4C[1] = baseX;
    D_8011ED4C[2] = baseX;
    D_8011ED4C[3] = baseX;
    switch (gVisibleSaveSlotCount) {
    case 1:
        D_8011F0EC = 0x140;
        break;
    case 2: {
        if (gBorderFlipFlag == 1) {
            flipX = D_8011ED40;
            D_8011F0EC = 0xA0;
            D_8011F0EE = 0xF0;
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
        D_8011F0EC = 0x140;
        break;
    }
    default:
        D_8011F0EC = 0xA0;
        break;
    }
after:
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 4; j++) {
            D_8011F2E8[i][j] = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        D_8011F3B8[(unsigned short)i] = 0;
    }
    switch (gSceneType) {
    case 8:
        for (i = 0; i < 3; i++) {
            sMarkerTextNode1[i] = spawnTextNode(D_8011ED54 + i * 36);
        }
        func_8011C4D8();
        break;
    case 6:
        setupSaveSlotMarkers();
        break;
    case 4:
    case 5:
        create_player_state_objects();
        break;
    case 2:
    case 3:
        func_8011CC3C();
        break;
    case 7:
        break;
    }
    func_8011C430();
    func_8011D3C0();
}
