typedef struct { u32 a, b, c, d; } FourWords;
extern u8 sMenuListKind, gMenuSlot, gMenuUseTextList, D_801007D2, D_801007D3, D_801007D4, gTrackMarkerActiveMask[], gSceneFlagsB;
extern u16 gBorderSkipActive;
extern FourWords D_800E1098, D_801007C8;
void func_8000A2B8(void);
void func_8000A368(void);
void func_8000A3AC(void);
void updateBonusSceneSlot(u16);
/* Resets menu scene flags, then sets the selected list bit and text-list state (text lists also refresh slot data). */ void setupMenuListFlags(void) {
    u8 *sceneFlagsA = gTrackMarkerActiveMask;
    s32 listBit;
    *sceneFlagsA = 0;
    gSceneFlagsB = 0;
    func_8000A2B8();
    if (gMenuUseTextList == 0) {
        *sceneFlagsA |= 1;
        gSceneFlagsB |= 1;
    } else {
        D_800E1098 = D_801007C8;
        D_801007D2 = -1;
        D_801007D3 = -1;
        D_801007D4 = -1;
        if ((*(s32 *)&gBorderSkipActive) != 0) {
            gSceneFlagsB |= 1 << sMenuListKind;
        } else {
            listBit = 1 << sMenuListKind;
            gSceneFlagsB |= listBit;
            *sceneFlagsA |= listBit;
        }
    }
    if (gMenuUseTextList != 0) func_8000A368();
    else func_8000A3AC();
    if (gMenuUseTextList != 0) updateBonusSceneSlot(gMenuSlot);
}
