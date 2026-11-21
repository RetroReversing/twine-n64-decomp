/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80022B60();
extern char D_800BD640[];
extern s32 sSaveMenuFlagsA;
extern s32 D_800BD64C;
extern s32 D_800BD650;
extern s32 D_800BD65C;
typedef struct { u8 f0; u8 pad[23]; } Slot_801001A1;
extern Slot_801001A1 D_801001A1[];
extern u8 gSaveKeyRelaxed;
extern void *gMenuState;

void func_80022F10(void *arg0, s32 arg1) {
    unsigned temp_t0;
    char *__base_D_800BD640;
    s32 *var_v0_2;
    s32 *var_v0_4;
    register s32 *__base_D_800BD64C;
    s32 *__base_D_800BD644;
    s32 var_a1;
    s32 var_v0;
    
    u8 temp_v1;
    u8 temp_v1_2;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a2;
    void *global_ptr;

    var_a1 = arg1;
    temp_t0 = var_a1;
    if (arg0 != NULL) {
        temp_a2 = (*(void **)((char *)(arg0) + 0));
        if (temp_a2 != NULL) {
            temp_a0 = (*(void **)((char *)(temp_a2) + 0));
            if (temp_a0 != NULL) {
                (*(s32 *)((char *)(temp_a0) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_a0) + 0x28)) & ~0xFC) | (((-((temp_t0 & 0xFF) == 0) & 7) | 1) * 4));
                (*(u16 *)((char *)((*(void **)((char *)(temp_a2) + 0))) + 0x20)) = (u16) (*(u16 *)((char *)(arg0) + 4));
                (*(u16 *)((char *)((*(void **)((char *)(temp_a2) + 0))) + 0x22)) = (u16) (*(u16 *)((char *)(arg0) + 6));
                if (gSaveKeyRelaxed != 0) {
                    temp_v1 = (*(u8 *)((char *)(arg0) + 8));
                    switch (temp_v1) {              /* switch 1; irregular */
                    case 0xFF:                      /* switch 1 */
                        global_ptr = gMenuState;
                        var_a1 = (s32) (*(void **)((char *)(temp_a2) + 0));
                        __base_D_800BD644 = &sSaveMenuFlagsA;
                        var_v0 = (*__base_D_800BD644);
                        break;
                    case 0x1:                       /* switch 1 */
                        global_ptr = gMenuState;
                        var_a1 = (s32) (*(void **)((char *)(temp_a2) + 0));
                        var_v0 = D_800BD650;
                        break;
                    case 0x0:                       /* switch 1 */
                        global_ptr = gMenuState;
                        var_a1 = (s32) (*(void **)((char *)(temp_a2) + 0));
                        var_v0 = D_800BD65C;
                        break;
                    default:                        /* switch 1 */
                        var_a1 = (s32) (*(void **)((char *)(temp_a2) + 0));
                        __base_D_800BD640 = D_800BD640;
                        var_v0_2 = __base_D_800BD640 + 0x10;
                        if (D_801001A1[(*(u8 *)((char *)(arg0) + 8)) - 1].f0 == 0) {
                            var_v0_2 = __base_D_800BD640 + 0x1C;
                        }
                        global_ptr = gMenuState;
                        var_v0 = *var_v0_2;
                        break;
                    }
                } else {
                    var_a1 = (s32) (*(void **)((char *)(temp_a2) + 0));
                    __base_D_800BD64C = &D_800BD64C;
                    global_ptr = gMenuState;
                        var_v0 = (*__base_D_800BD64C);
                }
                (*(s32 *)((char *)(var_a1) + 0x10)) = (s32) ((var_v0 & ~0xFF) | (*(u8 *)((char *)(global_ptr) + 0x30)));
            }
            temp_a0_2 = (*(void **)((char *)(temp_a2) + 4));
            if (temp_a0_2 != NULL) {
                (*(s32 *)((char *)(temp_a0_2) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_a0_2) + 0x28)) & ~0xFC) | (((-((temp_t0 & 0xFF) == 0) & 7) | 1) * 4));
                if (gSaveKeyRelaxed != 0) {
                    temp_v1_2 = (*(u8 *)((char *)(arg0) + 8));
                    switch (temp_v1_2) {            /* switch 2; irregular */
                    case 0x0:                       /* switch 2 */
                        global_ptr = gMenuState;
                        var_a1 = (s32) (*(void **)((char *)(temp_a2) + 4));
                        temp_t0 = D_800BD65C;
                        break;
                    case 0x1:                       /* switch 2 */
                        global_ptr = gMenuState;
                        var_a1 = (s32) (*(void **)((char *)(temp_a2) + 4));
                        temp_t0 = D_800BD650;
                        break;
                    case 0xFF:                      /* switch 2 */
                        global_ptr = gMenuState;
                        var_a1 = (s32) (*(void **)((char *)(temp_a2) + 4));
                        temp_t0 = (*__base_D_800BD644);
                        break;
                    default:                        /* switch 2 */
                        var_a1 = (s32) (*(void **)((char *)(temp_a2) + 4));
                        __base_D_800BD640 = D_800BD640;
                        var_v0_4 = __base_D_800BD640 + 0x10;
                        if (D_801001A1[(*(u8 *)((char *)(arg0) + 8)) - 1].f0 == 0) {
                            var_v0_4 = __base_D_800BD640 + 0x1C;
                        }
                        global_ptr = gMenuState;
                        temp_t0 = *var_v0_4;
                        break;
                    }
                } else {
                    global_ptr = gMenuState;
                        temp_t0 = (s32)&D_800BD64C;
                    var_a1 = (s32) (*(void **)((char *)(temp_a2) + 4));
                }
                (*(s32 *)((char *)(var_a1) + 0x10)) = (s32) ((temp_t0 & ~0xFF) | (*(u8 *)((char *)(global_ptr) + 0x30)));
                if ((*(u8 *)((char *)(arg0) + 8)) == 0xFF) {
                    (*(s16 *)((char *)((*(void **)((char *)(temp_a2) + 4))) + 0x20)) = 0xA0;
                } else {
                    (*(s16 *)((char *)((*(void **)((char *)(temp_a2) + 4))) + 0x20)) = (s16) ((*(u16 *)((char *)(arg0) + 4)) + 0x90);
                }
                (*(u16 *)((char *)((*(void **)((char *)(temp_a2) + 4))) + 0x22)) = (u16) (*(u16 *)((char *)(arg0) + 6));
            }
            func_80022B60(1, (void *) var_a1, temp_a2, arg0);
        }
    }
}
