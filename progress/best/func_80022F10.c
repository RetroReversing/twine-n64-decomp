/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_80022B60();
extern char D_800BD640[];
extern s32 D_800BD644;
extern s32 D_800BD64C;
extern s32 D_800BD650;
extern s32 D_800BD65C;
extern char D_801001A1[];
extern u8 D_801002A1;
extern void *D_80109BB0;

void func_80022F10(void *arg0, s32 arg1) {
    s32 *var_v0_2;
    s32 *var_v0_4;
    s32 temp_t0;
    s32 var_a1;
    s32 var_v0;
    s32 var_v0_3;
    u8 temp_v1;
    u8 temp_v1_2;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a2;

    var_a1 = arg1;
    temp_t0 = var_a1;
    if (arg0 != NULL) {
        temp_a2 = M2C_FIELD(arg0, void **, 0);
        if (temp_a2 != NULL) {
            temp_a0 = M2C_FIELD(temp_a2, void **, 0);
            if (temp_a0 != NULL) {
                M2C_FIELD(temp_a0, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_a0, s32 *, 0x28) & ~0xFC) | (((-((temp_t0 & 0xFF) == 0) & 7) | 1) * 4));
                M2C_FIELD(M2C_FIELD(temp_a2, void **, 0), u16 *, 0x20) = (u16) M2C_FIELD(arg0, u16 *, 4);
                M2C_FIELD(M2C_FIELD(temp_a2, void **, 0), u16 *, 0x22) = (u16) M2C_FIELD(arg0, u16 *, 6);
                if (D_801002A1 != 0) {
                    temp_v1 = M2C_FIELD(arg0, u8 *, 8);
                    switch (temp_v1) {              /* switch 1; irregular */
                    case 0x0:                       /* switch 1 */
                        var_a1 = (s32) M2C_FIELD(temp_a2, void **, 0);
                        var_v0 = D_800BD65C;
                        break;
                    case 0x1:                       /* switch 1 */
                        var_a1 = (s32) M2C_FIELD(temp_a2, void **, 0);
                        var_v0 = D_800BD650;
                        break;
                    case 0xFF:                      /* switch 1 */
                        var_a1 = (s32) M2C_FIELD(temp_a2, void **, 0);
                        var_v0 = D_800BD644;
                        break;
                    default:                        /* switch 1 */
                        var_a1 = (s32) M2C_FIELD(temp_a2, void **, 0);
                        var_v0_2 = D_800BD640 + 0x10;
                        if (*(D_801001A1 + ((M2C_FIELD(arg0, u8 *, 8) - 1) * 0x18)) == 0) {
                            var_v0_2 = D_800BD640 + 0x1C;
                        }
                        var_v0 = *var_v0_2;
                        break;
                    }
                } else {
                    var_a1 = (s32) M2C_FIELD(temp_a2, void **, 0);
                    var_v0 = D_800BD64C;
                }
                M2C_FIELD(var_a1, s32 *, 0x10) = (s32) ((var_v0 & ~0xFF) | M2C_FIELD(D_80109BB0, u8 *, 0x30));
            }
            temp_a0_2 = M2C_FIELD(temp_a2, void **, 4);
            if (temp_a0_2 != NULL) {
                M2C_FIELD(temp_a0_2, s32 *, 0x28) = (s32) ((M2C_FIELD(temp_a0_2, s32 *, 0x28) & ~0xFC) | (((-((temp_t0 & 0xFF) == 0) & 7) | 1) * 4));
                if (D_801002A1 != 0) {
                    temp_v1_2 = M2C_FIELD(arg0, u8 *, 8);
                    switch (temp_v1_2) {            /* switch 2; irregular */
                    case 0x0:                       /* switch 2 */
                        var_a1 = (s32) M2C_FIELD(temp_a2, void **, 4);
                        var_v0_3 = D_800BD65C;
                        break;
                    case 0x1:                       /* switch 2 */
                        var_a1 = (s32) M2C_FIELD(temp_a2, void **, 4);
                        var_v0_3 = D_800BD650;
                        break;
                    case 0xFF:                      /* switch 2 */
                        var_a1 = (s32) M2C_FIELD(temp_a2, void **, 4);
                        var_v0_3 = D_800BD644;
                        break;
                    default:                        /* switch 2 */
                        var_a1 = (s32) M2C_FIELD(temp_a2, void **, 4);
                        var_v0_4 = D_800BD640 + 0x10;
                        if (*(D_801001A1 + ((M2C_FIELD(arg0, u8 *, 8) - 1) * 0x18)) == 0) {
                            var_v0_4 = D_800BD640 + 0x1C;
                        }
                        var_v0_3 = *var_v0_4;
                        break;
                    }
                } else {
                    var_a1 = (s32) M2C_FIELD(temp_a2, void **, 4);
                    var_v0_3 = D_800BD64C;
                }
                M2C_FIELD(var_a1, s32 *, 0x10) = (s32) ((var_v0_3 & ~0xFF) | M2C_FIELD(D_80109BB0, u8 *, 0x30));
                if (M2C_FIELD(arg0, u8 *, 8) == 0xFF) {
                    M2C_FIELD(M2C_FIELD(temp_a2, void **, 4), s16 *, 0x20) = 0xA0;
                } else {
                    M2C_FIELD(M2C_FIELD(temp_a2, void **, 4), s16 *, 0x20) = (s16) (M2C_FIELD(arg0, u16 *, 4) + 0x90);
                }
                M2C_FIELD(M2C_FIELD(temp_a2, void **, 4), u16 *, 0x22) = (u16) M2C_FIELD(arg0, u16 *, 6);
            }
            func_80022B60(1, (void *) var_a1, temp_a2, arg0);
        }
    }
}
