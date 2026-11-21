extern s32 func_80076168(s32);
extern s32 func_8011A2A0(void);
extern void func_8011C580(void);
extern void updateRaceTimerHud(s32);
extern void func_8011C890(void);
extern void func_8011CAE4(void);
extern void func_8011CEA0(void);
extern void func_8011DC18(void);
extern void func_8011E894(void);
extern u8 gSceneType;
extern u8 D_801002AC;
extern u8 D_801002AE;
extern s32 gSaveTotalSlots;
extern s32 gVisibleSaveSlots;
extern s32 gBorderSkipFlag;
extern u8 gBorderFlipFlag;
extern s16 D_8011F0EC;
extern s16 D_8011F0EE;
extern s32 D_8011F3A8;

void func_8011E634(void) {
    u8 *p;
    u8 *q;
    s32 *b;
    s32 i;
    s32 t;
    s32 s;
    D_8011F0EE = 0x78;
    if (gVisibleSaveSlots >= 3) {
        D_8011F0EC = 0xA0;
    } else if (gBorderFlipFlag == 1) {
        D_8011F0EC = 0xA0;
        D_8011F0EE = 0xF0;
    } else {
        D_8011F0EC = 0x140;
    }
    p = &D_801002AE;
    if (*p == 0) {
        updateRaceTimerHud(-1);
        if (*p == 0) {
            func_8011C580();
        }
    }
    s = gSceneType;
    if (s < 6) {
        if (s >= 4) {
            func_8011C890();
            s = gSceneType;
        }
    }
    if (s >= 2) {
        if (s >= 4) {
            if (s == 6) {
                func_8011CAE4();
            }
        } else {
            func_8011CEA0();
        }
    }
    func_8011DC18();
    if (((gBorderSkipFlag != 0 && D_801002AC != 0) || (func_8011A2A0() & 0xFFFF)) && (t = D_8011F3A8 - 1, D_8011F3A8 = t, t <= 0)) {
        if (t == 0) {
            func_8011E894();
            i = 0;
            b = &gSaveTotalSlots;
            if ((u32)t < (u32)*b) {
                q = (u8 *)b - 6;
                do {
                    *q = 1;
                    func_80076168(i & 0xFF);
                    i++;
                } while ((i & 0xFFFF) < *(s32 *)(q + 6));
            }
        } else {
            D_8011F3A8 = -1;
        }
    }
}
