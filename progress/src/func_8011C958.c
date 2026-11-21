typedef struct { u8 type; u8 rest[23]; } SlotEnt;
extern SlotEnt D_801001A2[];
extern s32 sSaveMenuFlagsA; extern s32 gVisibleSaveSlots; extern u8 D_8011EDC0[]; extern void *D_8011F338[3][4]; extern s32 gMarkerEntry1,gMarkerEntry2,gMarkerEntry3;
s32 func_80015F74(void *); void *func_800162BC(s32); void func_800448A4(void *, s32, s32);
void func_8011C958(void) {
    u16 i; u16 j; u8 t; s32 *o;
    gMarkerEntry1 = func_80015F74(D_8011EDC0);
    gMarkerEntry2 = func_80015F74(D_8011EDC0 + 0x24);
    gMarkerEntry3 = func_80015F74(D_8011EDC0 + 0x48);
    for (i = 0; i < gVisibleSaveSlots; i++) {
        t = D_801001A2[i].type;
        switch (t) {
        case 1: case 2: case 3: case 5:
            for (j = 0; j < 3; j++) {
                o = func_800162BC(i);
                if (o != 0) {
                    func_800448A4(o, 0x13, 0xF4);
                    o[4] = sSaveMenuFlagsA;
                    D_8011F338[j][i] = o;
                }
            }
            break;
        default:
            for (j = 0; j < 3; j++) D_8011F338[j][i] = 0;
            break;
        }
    }
}
