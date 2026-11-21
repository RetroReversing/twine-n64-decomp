#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
void *func_80027408(s32, s32, s32, s32);
s32 func_800278AC(s32, s32, u16);
s32 func_8002B050(s32 *, s32, void *);
s32 func_8002B150(s32 *, s32, s32);
s32 func_8002FBD4(s32, s32);
s32 lookupDataEntry(s32);
s32 menuItemIsActive(s32);
extern s32 D_800BD8C4, D_800BD640, D_800BFC94;
extern void *D_800E1560, *D_800E1584;
extern u8 D_80102EDC, D_80102EBC, gPendingMenuCommand;
extern s32 gMenuSoundParams;
extern void *gSaveMenuState, *sActiveMenu, gMenuState;
extern u16 sMenuAnimFlags;
extern s32 sMenuItemParamTable, sMenuTimer;
void func_8002F068(s32 unused, s32 arg1) {
    s32 var_a2;
    s32 var_a3;
    s32 *var_v0;
    s32 temp_v0;
    s32 temp_v1;
    u16 temp_v1_2;
    void *temp_v0_2;
    if (!(menuItemIsActive(0x23) & 0xFF) && !(menuItemIsActive(0x2A) & 0xFF) && (gPendingMenuCommand == 0)) {
        temp_v0 = lookupDataEntry(0x2E9);
        temp_v1 = sMenuAnimFlags & 1;
        var_a2 = 0xDC;
        if (temp_v1 != 0) var_a2 = 0xA0;
        var_a3 = 0x45;
        if (temp_v1 != 0) var_a3 = 0xB0;
        temp_v0_2 = func_80027408(temp_v0, 0, var_a2, var_a3);
        D_800E1560 = temp_v0_2;
        temp_v1_2 = *(u16 *)&D_800BFC94 & 0x3F;
        *(u16 *)((s8 *)&D_800BFC94 + 2) = temp_v1_2;
        if (temp_v1_2 >= 0x20U) *(u16 *)((s8 *)&D_800BFC94 + 2) = 0x3F - temp_v1_2;
        if (sMenuAnimFlags & 1) var_v0 = &sMenuItemParamTable + 4;
        else var_v0 = &sMenuItemParamTable + 0x24;
        M2C_FIELD(temp_v0_2, s32 *, 0x10) = *var_v0 & ~0xFF;
        M2C_FIELD(D_800E1560, s32 *, 0x10) = (M2C_FIELD(D_800E1560, s32 *, 0x10) & ~0xFF) | (*(u16 *)((s8 *)&D_800BFC94 + 2) * 8);
        *(u16 *)&D_800BFC94 = *(u16 *)&D_800BFC94 + 1;
        if (D_80102EDC != 0) func_8002B050(&sMenuTimer, 1, temp_v0_2);
    } else {
        *(u16 *)&D_800BFC94 = 0;
        M2C_FIELD(gSaveMenuState, s32 *, 0xC) = (s32)&D_800BD8C4;
        func_800278AC(1, gMenuSoundParams & ~0xFF, M2C_FIELD(sActiveMenu, u16 *, 0x7A));
        func_80027408(lookupDataEntry(3), 0x40, 0xA0, 0xCC);
        func_8002B150(&sMenuTimer, 0, 0);
        func_8002FBD4(arg1, 4);
    }
}
