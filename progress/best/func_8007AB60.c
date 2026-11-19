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

s32 func_80002BD0();
s32 func_80045CF8();
s32 func_80077960();
s32 func_80077ED8();
extern char D_800C469C[];
extern char D_800C9BD0[];
extern char D_800C9BE0[];
extern char D_800C9BE4[];
extern char D_800C9BF0[];
extern char D_800C9BF4[];

s32 func_8007AB60(void *arg0) {
    char *__base_D_800C9BF0;
int __repair_literal;

    s32 *var_s1;
    s32 var_a0;
    s32 var_a1;
    s16 temp_a0;
    u16 var_a1_2;
    u8 temp_v0;
    u8 temp_v1;
    u8 temp_v1_2;
    void *temp_a1;
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg0, void **, 0x6C);
    temp_a0 = M2C_FIELD(arg0, s16 *, 0x7C);
    temp_a1 = (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE) * 0xE8) + D_800C469C;
    switch (temp_a0) {                              /* switch 1 */
    case 0:                                         /* switch 1 */
    case 3:                                         /* switch 1 */
        if (M2C_FIELD(temp_a2, s32 *, 0x88) & 0x40000000) {
            temp_v1 = M2C_FIELD(temp_a1, u8 *, 0x6E);
            switch (temp_v1) {                      /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                func_80002BD0(arg0, *(u16 *)(D_800C9BE0 + (func_80045CF8(1, temp_a1, temp_a2) * 2)));
                var_a1 = 0x81;
                break;
            __base_D_800C9BF0 = D_800C9BF0;
            case 1:                                 /* switch 2 */
                func_80002BD0(arg0, *(u16 *)(__base_D_800C9BF0 + (func_80045CF8(1, temp_a1, temp_a2) * 2)));
                var_a1 = 0x81;
                break;
            case 2:                                 /* switch 2 */
                func_80002BD0(arg0, *(D_800C9BF4 + (func_80045CF8(5, temp_a1, temp_a2) * 2)));
                var_a1 = 0x81;
                break;
            default:                                /* switch 2 */
                var_a1_2 = 0x129;
block_31:
                func_80002BD0(arg0, var_a1_2);
                var_a1 = 4;
                break;
            }
            func_80077960(arg0, var_a1);
            return 1;
        }
        func_80077ED8(arg0, temp_a1, temp_a2);
        return 1;
    case 1:                                         /* switch 1 */
        if (M2C_FIELD(arg0, s32 *, 0x58) & 4) {
            temp_v1_2 = M2C_FIELD(temp_a1, u8 *, 0x6E);
            if (temp_v1_2 != 1) {
__repair_literal = 2;

                if ((s32) temp_v1_2 >= __repair_literal) {
                    if (temp_v1_2 != 2) {
                        return 0;
                    }
                    temp_v0 = M2C_FIELD(temp_a2, u8 *, 0x81);
                    if ((temp_v0 == 0) || (var_a0 = 5, (temp_v0 != 1))) {
                        var_s1 = D_800C9BD0;
                        var_a0 = 8;
                    } else {
                        var_s1 = D_800C9BE4;
                    }
                    var_a1_2 = *((func_80045CF8(var_a0, temp_a1, temp_a2) * 2) + var_s1);
                    goto block_31;
                }
                if (temp_v1_2 != 0) {
                    return 0;
                }
                var_a1_2 = *(u16 *)(D_800C9BE0 + (func_80045CF8(1, temp_a1, temp_a2) * 2));
                goto block_31;
            }
        }
    default:                                        /* switch 1 */
    case 2:                                         /* switch 1 */
    case 4:                                         /* switch 1 */
    case 5:                                         /* switch 1 */
    case 6:                                         /* switch 1 */
    case 7:                                         /* switch 1 */
    case 8:                                         /* switch 1 */
    case 9:                                         /* switch 1 */
    case 10:                                        /* switch 1 */
    case 11:                                        /* switch 1 */
    case 12:                                        /* switch 1 */
        return 0;
    }
}
