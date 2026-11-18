static __inline__ u8 __repair_inline(u8 a) { return a; }
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800312F4();
f32 func_80045540();
s32 func_800707B4();
s32 func_80074C34();
extern s32 D_800C7EE4;
extern char D_800C7EE8[];
extern u8 D_800C7EE9[];
extern char D_800C7EEC[];
extern u8 D_800CEEB0;
extern void *D_8010A500;
extern char D_80115091[];
extern s32 func_801188B4;

void func_8007514C(void *arg0) {
    s32 temp_a0;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_s0;
    s32 var_v0;
    u8 temp_v0;
    u8 temp_v1;
    void *temp_s2;

    if ((!D_800CEEB0) && (D_8010A500 != NULL)) {
        temp_v1 = __repair_inline(*(D_800C7EE8 + ((*(s16 *)((char *)(arg0) + 0x7C)) * 0xC)));
        temp_s2 = (*(void **)((char *)(D_8010A500) + 0x6C));
        var_s0 = 0;
        switch (temp_v1) {
case 2:                                     /* switch 1 */
            var_v0 = 0;
            if (func_800312F4(2, 0) != 3) {
                goto block_13;
            }
            break;
        case 4:                                     /* switch 1 */
            var_s0 = 1;
            if ((*(u8 *)((char *)(temp_s2) + 0x23C)) != 0) {
                goto block_12;
            }
            break;
        case 5:                                     /* switch 1 */
            var_s0 = 1;
            if ((*(s8 *)((char *)((*(void **)((char *)(D_8010A500) + 0x68))) + 0xE)) == 0x29) {
                goto block_12;
            }
            break;
        case 0: break;
                          /* switch 1 */
        case 1:                                     /* switch 1 */
            if ((func_800707B4((int)temp_s2) << 0x18) != 0) {
                var_s0 = 1;
                if ((*(s8 *)((char *)(&func_801188B4) + 0x9F)) != 0) {
                default:                            /* switch 1 */
block_12:
                    var_v0 = var_s0;
block_13:
                    if (((short)var_s0 != 0) || (func_80045540(arg0 + 0x24, D_8010A500 + 0x24) < 3.0f)) {
                        temp_v0 = *(D_80115091 + ((*(s8 *)((char *)(temp_s2) + 0x182)) * 0xA0));
                        switch (temp_v0) {          /* switch 2 */
                        default:                    /* switch 2 */
                            var_a0 = 0;
                            break;
                        case 1:                     /* switch 2 */
                        case 3:                     /* switch 2 */
                        case 5:                     /* switch 2 */
                        case 7:                     /* switch 2 */
                            var_a0 = 1;
                            break;
                        }
                        temp_v1_2 = (*(s16 *)((char *)(arg0) + 0x7C)) * 0xC;
                        if (*(D_800C7EE9 + temp_v1_2) == 0) {
                            *(D_800C7EE9 + temp_v1_2) = 1;
                            temp_a0 = var_a0 * 4;
                            if (*(s32 *)*(temp_a0 + (((*(s16 *)((char *)(arg0) + 0x7C)) * 0xC) + D_800C7EEC)) >= 0) {
                                D_800C7EE4 = 1;
                            }
                            func_80074C34(0, *(temp_a0 + (((*(s16 *)((char *)(arg0) + 0x7C)) * 0xC) + D_800C7EEC)));
                            D_800C7EE4 = 2;
                        }
                        (*(s32 *)((char *)(arg0) + 0x60)) |= 1;
                    }
                }
            }
            break;
        }
    }
}
