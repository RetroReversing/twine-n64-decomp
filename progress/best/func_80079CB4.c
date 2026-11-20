/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800015AC();
s32 func_8000237C();
s32 func_80002BD0();
s32 func_80002EAC();
void *func_800164F8();
s32 func_80017490();
s32 func_8001751C();
s32 func_8002BA9C();
s32 func_800312F4();
s32 actorLinkToSurface();
s32 func_80045CF8();
s32 func_80077960();
s32 func_800779C4();
s32 func_80077C00();
s32 func_8007C93C();
extern s32 *gProbeObjectList;
extern u8 D_800CA338;
extern u16 D_80108F72;
extern s32 D_80108F78;
extern char gTrackDoneFlags[];
extern u16 D_80113020;
extern u8 D_80117734;
extern s32 func_80076CE4;

typedef struct { unsigned char pad[136]; int value; } __repair_field_88;
void *func_80079CB4(void *arg0, void *arg1, s32 arg2, u8 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, u32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, u8 arg13, s32 arg14, s32 arg15) {
    s32 __repair_store_0;
    s32 var_s2;
    s32 __repair_store_2;
    s32 var_a0;
s32 __repair_phase_var_a0;
    register s32 var_a1_2;
    s32 var_a1_3;
    int temp_s2;
    s32 temp_v0;
    s32 temp_v1_2;
    register u8 var_v0_2;
    int var_v1;
    
    s32 __repair_store_1;
    s32 var_v0_3;
    
    s8 temp_a0;
    u8 temp_v0_2;
    s32 var_a1;
s32 __repair_phase_var_a1;
    u8 var_v0_4;
    u8 var_v0_5;
    u8 var_v0_6;
    void *temp_s0;
    void *temp_v1;
    register void *temp_v1_3;
    void *var_s1;

    var_s1 = NULL;
    if ((func_80017490(arg5, arg6, arg7) << 0x18) != 0) {
        var_s1 = func_800164F8(0x8C, 0, 0);
        if (var_s1 != NULL) {
            temp_s0 = (*(void **)((char *)(var_s1) + 0x6C));
            if (((unsigned)arg15 << 0x18) != 0) {
                (((__repair_field_88 *)temp_s0)->value) = (((__repair_field_88 *)temp_s0)->value) | 0x10000000;
            } else {
                (((__repair_field_88 *)temp_s0)->value) = (((__repair_field_88 *)temp_s0)->value) & 0xEFFFFFFF;
            }
            (*(s32 *)((char *)(temp_s0) + 0x60)) = 0;
            (((__repair_field_88 *)temp_s0)->value) &= 0x7FFFFFFF & 0xBFFFFFFF & 0xDFFFFFFF & 0xFDFFFFFF;
            (*(s8 *)((char *)(temp_s0) + 0x83)) = (s8) arg14;
            (*(s16 *)((char *)(var_s1) + 0x78)) = 1;
            (*(u8 *)((char *)(temp_s0) + 0x84)) = arg13;
            (*(s8 *)((char *)(temp_s0) + 0x86)) = 1;
            (*(s8 *)((char *)(temp_s0) + 0x87)) = (s8) ((int)arg3 - 1);
            (*(u8 *)((char *)(temp_s0) + 0x80)) = arg4;
            (*(u8 *)((char *)(temp_s0) + 0x81)) = arg9;
            (*(s32 *)((char *)(temp_s0) + 0x70)) = 0;
            (*(s32 *)((char *)(temp_s0) + 0x40)) = 0;
            (*(s32 *)((char *)(temp_s0) + 0x44)) = arg2;
            (*(s32 *)((char *)(temp_s0) + 0x48)) = 0;
            (*(s32 *)((char *)(temp_s0) + 0x4C)) = -1;
            (*(s16 *)((char *)(temp_s0) + 0x7C)) = 0;
            (*(s16 *)((char *)(temp_s0) + 0x7A)) = 0;
            (*(s16 *)((char *)(temp_s0) + 0x78)) = 0;
            func_8000237C(var_s1, arg10, 1, -(D_800CA338 == 0));
            if ((*(void **)((char *)(var_s1) + 0x68)) != NULL) {
                func_800015AC(var_s1, arg11);
                func_80002EAC(var_s1, &func_80076CE4);
                (*(f32 *)((char *)(var_s1) + 0x74)) = (f32) (func_8002BA9C(arg10) & 0xFFFF);
                (*(s32 *)((char *)(var_s1) + 0x58)) |= 0x2400;
                (*(u8 *)((char *)(temp_s0) + 0x82)) = arg12;
                (((__repair_field_88 *)temp_s0)->value) = (s32) (((((__repair_field_88 *)temp_s0)->value) & 0xFE1FFFFF) | 0x200000);
                (*(u8 *)((char *)(temp_s0) + 0x85)) = (u8) *(gTrackDoneFlags + (*(u8 *)((char *)(temp_s0) + 0x84)));
                (*(s16 *)((char *)(temp_s0) + 0x76)) = 0;
                (*(s16 *)((char *)(temp_s0) + 0x74)) = 0;
                if (D_80108F78 == 0x19) {
                    D_80117734 = 1;
                }
                var_s2 = 0x14D;
                if ((int)D_80117734 == 0) {
                    var_s2 = 0x129;
                }
                switch (arg8) {                     /* switch 1 */
                case 39:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0x28U;
                    break;
                case 46:                            /* switch 1 */
                    var_v0_2 = 0x2F;
block_74:
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = var_v0_2;
                    var_v0_3 = 0x600000;
block_75:
                    var_v1 = (((__repair_field_88 *)temp_s0)->value) & 0xFE1FFFFF;
block_76:
                    (((__repair_field_88 *)temp_s0)->value) = (s32) (var_v1 | var_v0_3);
                    break;
                case 45:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0x2EU;
                    break;
                case 38:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0x27U;
                    /* fallthrough */
                case 0:                             /* switch 1 */
                    temp_s2 = (*(s32 *)((char *)(temp_s0) + 0x44));
                    if (temp_s2 != 0) {
                        temp_a0 = (*(s8 *)((char *)(temp_s0) + 0x87));
                        if (temp_a0 >= 3) {
                            temp_v0 = func_80045CF8(temp_a0 - 1);
                            (*(s8 *)((char *)(temp_s0) + 0x86)) = (s8) (temp_v0 + 1);
                            temp_v1 = ((s32)temp_v0 * 0x18) + temp_s2;
                            __repair_store_0 = (s32) (*(s32 *)((char *)(temp_v1) + 0));
                            __repair_store_1 = (s32) (*(s32 *)((char *)(temp_v1) + 4));
                            __repair_store_2 = (s32) (*(s32 *)((char *)(temp_v1) + 8));
                            (*(s32 *)((char *)(arg0) + 0)) = __repair_store_0;
                            (*(s32 *)((char *)(arg0) + 4)) = __repair_store_1;
                            (*(s32 *)((char *)(arg0) + 8)) = __repair_store_2;
                            (*(s32 *)((char *)(arg1) + 0)) = (s32) (*(s32 *)((char *)(temp_v1) + 0xC));
                            (*(s32 *)((char *)(arg1) + 8)) = (s32) (*(s32 *)((char *)(temp_v1) + 0x14));
                            (*(s32 *)((char *)(arg1) + 4)) = (s32) (*(s32 *)((char *)(temp_v1) + 0x10));
                        }
                    }
                    break;
                case 44:                            /* switch 1 */
                    var_v0_2 = 0x2C;
                    goto block_74;
                case 47:                            /* switch 1 */
                    var_v0_2 = 0x30;
                    goto block_74;
                case 12:                            /* switch 1 */
                    var_v0_2 = 0x10;
                    goto block_74;
                case 11:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 1U;
                    break;
                case 6:                             /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0xAU;
                    break;
                case 9:                             /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0xDU;
                    break;
                case 24:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0xEU;
                    break;
                case 37:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0x26U;
                    break;
                case 8:                             /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0xBU;
                    break;
                case 7:                             /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 5U;
                    break;
                case 5:                             /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 9U;
                    (*(s32 *)((char *)(temp_s0) + 0x44)) = 0;
                    break;
                case 1:                             /* switch 1 */
                    (((__repair_field_88 *)temp_s0)->value) |= 0x40000000;
                    break;
                case 25:                            /* switch 1 */
                    var_a1 = arg3 & 0xFF;
                    var_v0_4 = 0x10;
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = var_v0_4;
                    (((__repair_field_88 *)temp_s0)->value) = (s32) (((((__repair_field_88 *)temp_s0)->value) & 0xFE1FFFFF) | 0x600000);
                    func_8001751C(arg2, var_a1, arg0, arg1);
                    (*(s32 *)((char *)(temp_s0) + 0x44)) = 0;
                    break;
                case 4:                             /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 9U;
                    /* fallthrough */
                case 2:                             /* switch 1 */
                    var_a1 = arg3 & 0xFF;
                    (*(u8 *)((char *)(temp_s0) + 0x85)) = 0U;
                    func_8001751C(arg2, var_a1, arg0, arg1);
                    (*(s32 *)((char *)(temp_s0) + 0x44)) = 0;
                    break;
                case 3:                             /* switch 1 */
                    var_v1 = (((__repair_field_88 *)temp_s0)->value);
                    var_v0_3 = 0x40000000;
                    (*(u8 *)((char *)(temp_s0) + 0x85)) = 0U;
                    (*(s32 *)((char *)(temp_s0) + 0x44)) = 0;
                    goto block_76;
                case 10:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0xFU;
                    break;
                case 34:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0x23U;
                    break;
                case 35:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0x24U;
                    break;
                case 36:                            /* switch 1 */
                    var_v0_2 = 0x25;
                    goto block_74;
                case 16:                            /* switch 1 */
                    var_v0_5 = 0x13;
                    D_80117734 = 1;
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = var_v0_5;
                    (((__repair_field_88 *)temp_s0)->value) = (s32) (((((__repair_field_88 *)temp_s0)->value) & 0xFE1FFFFF) | 0x400000);
                    ++D_80108F72;
                    break;
                case 17:                            /* switch 1 */
                    D_80117734 = 1;
                    var_v0_5 = 0x14;
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = var_v0_5;
                    (((__repair_field_88 *)temp_s0)->value) = (s32) (((((__repair_field_88 *)temp_s0)->value) & 0xFE1FFFFF) | 0x400000);
                    ++D_80108F72;
                    break;
                case 14:                            /* switch 1 */
                    if ((*(u8 *)((char *)(temp_s0) + 0x81)) == 7) {
                        (((__repair_field_88 *)temp_s0)->value) = (s32) (((((__repair_field_88 *)temp_s0)->value) & 0xFE1FFFFF) | 0x600000);
                    case 13:                        /* switch 1 */
                    } else {
                        (((__repair_field_88 *)temp_s0)->value) = (s32) (((((__repair_field_88 *)temp_s0)->value) & 0xFE1FFFFF) | 0x400000);
                        D_80108F72 += 1;
                    }
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0x15U;
                    break;
                case 28:                            /* switch 1 */
                    var_a0 = 1;
                    (*(u8 *)((char *)(temp_s0) + 0x85)) = 0U;
                    if (func_800312F4(var_a0, 0) == 1) {
                        (*(s32 *)((char *)(var_s1) + 0x60)) |= 1;
                    }
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0x15U;
                    break;
                case 29:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x85)) = 0U;
                    if (func_800312F4(2, 0) == 1) {
                        (*(s32 *)((char *)(var_s1) + 0x60)) |= 1;
                    }
                    /* fallthrough */
                case 50:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x85)) = 0U;
                    /* fallthrough */
                case 15:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0x16U;
                    break;
                case 30:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x85)) = 0U;
                    __repair_phase_var_a0 = 2;
                    if (func_800312F4(__repair_phase_var_a0, 0) == 1) {
                        (*(s32 *)((char *)(var_s1) + 0x60)) |= 1;
                    }
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0x15U;
                    break;
                case 18:                            /* switch 1 */
                    var_v0_2 = 0x17;
                    goto block_74;
                case 19:                            /* switch 1 */
                    var_v0_2 = 0x18;
                    goto block_74;
                case 20:                            /* switch 1 */
                    var_v0_2 = 0x19;
                    goto block_74;
                case 21:                            /* switch 1 */
                    var_v0_2 = 0x1A;
                    goto block_74;
                case 26:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0x1CU;
                    break;
                case 42:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0x2BU;
                    break;
                case 22:                            /* switch 1 */
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0x1BU;
                    break;
                case 27:                            /* switch 1 */
                    var_s2 = 0x14D;
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0x1EU;
                    var_v0_3 = 0x800000;
                    goto block_75;
                case 31:                            /* switch 1 */
                    (((__repair_field_88 *)temp_s0)->value) = (s32) (((((__repair_field_88 *)temp_s0)->value) & 0xFE1FFFFF) | 0x600000);
                    D_80113020 += 1;
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = 0x1FU;
                    break;
                case 32:                            /* switch 1 */
                    var_v0_6 = 0x20;
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = var_v0_6;
                    var_s2 = 0x14D;
                    break;
                case 33:                            /* switch 1 */
                    var_v0_6 = 0x21;
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = var_v0_6;
                    var_s2 = 0x14D;
                    break;
                case 40:                            /* switch 1 */
                    __repair_phase_var_a1 = arg3 & 0xFF;
                    (*(u8 *)((char *)(temp_s0) + 0x82)) = (int)var_v0_4;
                    var_v0_4 = 0x29;
                    (((__repair_field_88 *)temp_s0)->value) = (s32) (((((__repair_field_88 *)temp_s0)->value) & 0xFE1FFFFF) | 0x600000);
                    func_8001751C(arg2, __repair_phase_var_a1, arg0, arg1);
                    (*(s32 *)((char *)(temp_s0) + 0x44)) = 0;
                    break;
                case 41:                            /* switch 1 */
                    var_v0_2 = 0x2A;
                    goto block_74;
                case 43:                            /* switch 1 */
                    var_v0_2 = 0x2D;
                    goto block_74;
                case 48:                            /* switch 1 */
                    var_v0_2 = 0x31;
                    goto block_74;
                case 49:                            /* switch 1 */
                    var_v0_2 = 0x32;
                    goto block_74;
                }
                (*(s32 *)((char *)(var_s1) + 0x24)) = (s32) (*(s32 *)((char *)(arg0) + 0));
                (*(s32 *)((char *)(var_s1) + 0x28)) = (s32) (*(s32 *)((char *)(arg0) + 4));
                (*(s32 *)((char *)(var_s1) + 0x2C)) = (s32) (*(s32 *)((char *)(arg0) + 8));
                (*(s32 *)((char *)(var_s1) + 0x30)) = (s32) (*(s32 *)((char *)(var_s1) + 0x24));
                (*(s32 *)((char *)(var_s1) + 0x34)) = (s32) (*(s32 *)((char *)(var_s1) + 0x28));
                (*(s32 *)((char *)(var_s1) + 0x3C)) = (s32) (*(s32 *)((char *)(arg1) + 0));
                (*(s32 *)((char *)(var_s1) + 0x38)) = (s32) (*(s32 *)((char *)(var_s1) + 0x2C));
                (*(s32 *)((char *)(var_s1) + 0x44)) = (s32) (*(s32 *)((char *)(arg1) + 8));
                (*(s32 *)((char *)(var_s1) + 0x40)) = (s32) (*(s32 *)((char *)(arg1) + 4));
                (*(s32 *)((char *)(var_s1) + 0x48)) = (s32) (*(s32 *)((char *)(var_s1) + 0x3C));
                (*(s32 *)((char *)(temp_s0) + 0)) = (s32) (*(s32 *)((char *)(var_s1) + 0x24));
                (*(s32 *)((char *)(var_s1) + 0x50)) = (s32) (*(s32 *)((char *)(var_s1) + 0x44));
                (*(s32 *)((char *)(var_s1) + 0x4C)) = (s32) (*(s32 *)((char *)(var_s1) + 0x40));
                (*(s32 *)((char *)(temp_s0) + 4)) = (s32) (*(s32 *)((char *)(var_s1) + 0x28));
                (*(s32 *)((char *)(temp_s0) + 8)) = (s32) (*(s32 *)((char *)(var_s1) + 0x2C));
                (*(s32 *)((char *)(temp_s0) + 0xC)) = (s32) (*(s32 *)((char *)(var_s1) + 0x3C));
                (*(s32 *)((char *)(temp_s0) + 0x10)) = (s32) (*(s32 *)((char *)(var_s1) + 0x40));
                (*(s32 *)((char *)(temp_s0) + 0x14)) = (s32) (*(s32 *)((char *)(var_s1) + 0x44));
                temp_v1_2 = (((__repair_field_88 *)temp_s0)->value) & 0x01E00000;
                if (((temp_v1_2 == 0x400000) | (temp_v1_2 == 0x600000)) != 0) {
                    temp_v1_2 = 0x5E600;
                } else {
                    temp_v1_2 = 0x20600;
                }
                (*(s32 *)((char *)(var_s1) + 0x5C)) |= temp_v1_2;
                (*(s32 *)((char *)(temp_s0) + 0x6C)) = 0;
                if (var_s2 == 0x129) {
                    (*(s16 *)((char *)(var_s1) + 0x7C)) = 1;
                    (*(s8 *)((char *)(temp_s0) + 0x7F)) = 1;
                    func_80002BD0(var_s1, 0x129);
                } else if (var_s2 == 0x14D) {
                    (*(s16 *)((char *)(var_s1) + 0x7C)) = 0;
                    (*(s8 *)((char *)(temp_s0) + 0x7F)) = 0;
                    if ((*(u8 *)((char *)(temp_s0) + 0x82)) == 0x1E) {
                        (((__repair_field_88 *)temp_s0)->value) &= 0xBFFFFFFF;
                    }
                }
                func_80002BD0(var_s1, var_s2);
                (*(s16 *)((char *)(var_s1) + 0x7A)) = 0;
                (*(s8 *)((char *)(temp_s0) + 0x7E)) = 0;
                func_80077960(var_s1, 0);
                (*(u8 *)((char *)(var_s1) + 0x7F)) = 0x80;
                (*(u8 *)((char *)(var_s1) + 0x80)) = 0x80;
                (*(u8 *)((char *)(var_s1) + 0x81)) = 0x80;
                (*(u8 *)((char *)(var_s1) + 0x82)) = 0xFF;
                (*(s8 *)((char *)(var_s1) + 0x7E)) = 1;
                (*(s32 *)((char *)(temp_s0) + 0x38)) = 0;
                (*(s32 *)((char *)(temp_s0) + 0x3C)) = 0;
                (*(s32 *)((char *)(temp_s0) + 0x4C)) = -1;
                (*(s32 *)((char *)(temp_s0) + 0x38)) = 0;
                (*(s32 *)((char *)(temp_s0) + 0x3C)) = 0;
                (*(s32 *)((char *)(temp_s0) + 0x30)) = 0;
                if ((*(u8 *)((char *)(temp_s0) + 0x84)) != 0) {
                    func_80077960(var_s1, 0x27);
                    return var_s1;
                }
                actorLinkToSurface(*gProbeObjectList, var_s1, 1);
                func_80077960(var_s1, 0x26);
                temp_v0_2 = (*(u8 *)((char *)(temp_s0) + 0x82));
                var_s2 = 1;
                switch (temp_v0_2) {                /* switch 2 */
                case 2:
                case 3:
                case 4:
                case 5:
                case 44:
                default:                            /* switch 2 */
                    var_a1_2 = 1;
                    func_80077960(var_s1, var_a1_2);
                    break;
                case 15:                            /* switch 2 */
                    var_a1_2 = 0x42;
                    func_80077960(var_s1, var_a1_2);
                    break;
                case 6:                             /* switch 2 */
                case 8:                             /* switch 2 */
                    func_80002BD0(var_s1, 0x2C4);
                    var_a1_3 = 0x28;
block_94:
                    var_s2 = 0;
                    do { func_80077960(var_s1, var_a1_3); } while (0);
                    (*(s32 *)((char *)(var_s1) + 0x58)) |= 0x80000;
                    break;
                case 7:                             /* switch 2 */
                    func_80002BD0(var_s1, 0x2C5);
                    var_a1_3 = 0x29;
                    goto block_94;
                case 18:                            /* switch 2 */
                    func_80002BD0(var_s1, 0x215);
                    var_a1_3 = 0x2B;
                    goto block_94;
                case 34:                            /* switch 2 */
                    var_a1_2 = 3;
                    (*(s16 *)((char *)(var_s1) + 0x7C)) = 0xA;
                    (*(s8 *)((char *)(temp_s0) + 0x7F)) = 0xA;
                    func_80077960(var_s1, var_a1_2);
                    break;
                case 21:                            /* switch 2 */
                    var_s2 = 0;
                    if ((*(u8 *)((char *)(temp_s0) + 0x84)) == 0) {
                        func_8007C93C(var_s1);
                    }
                    break;
                case 22:                            /* switch 2 */
                    func_80002BD0(var_s1, 0x20E);
                    func_80077960(var_s1, 0x47);
                    var_s2 = 0;
                    break;
                case 42:                            /* switch 2 */
                    var_s2 = 0;
                    func_80002BD0(var_s1, 0x330);
                    var_a1_2 = 0x89;
                    func_80077960(var_s1, var_a1_2);
                    break;
                case 28:                            /* switch 2 */
                    if (func_800312F4(1, 0) == 2) {
                        (*(s32 *)((char *)(var_s1) + 0x60)) |= 1;
                    }
                    /* fallthrough */
                case 27:                            /* switch 2 */
                case 43:                            /* switch 2 */
                    func_800779C4(var_s1);
                    var_a1_2 = 0x3E;
                    func_80077960(var_s1, var_a1_2);
                    break;
                case 31:                            /* switch 2 */
                    func_80002BD0(var_s1, 0x1FE);
                    var_a1_2 = 0x77;
                    func_80077960(var_s1, var_a1_2);
                    break;
                case 23:                            /* switch 2 */
                    var_a1_2 = 0x58;
                    func_80077960(var_s1, var_a1_2);
                    break;
                case 26:                            /* switch 2 */
                    var_a1_2 = 0x65;
                    func_80077960(var_s1, var_a1_2);
                    break;
                case 24:                            /* switch 2 */
                    var_a1_2 = 0x4C;
                    func_80077960(var_s1, var_a1_2);
                    break;
                case 25:                            /* switch 2 */
                    var_a1_2 = 0x59;
                    func_80077960(var_s1, var_a1_2);
                    break;
                case 41:                            /* switch 2 */
                    var_a1_2 = 0x66;
                    func_80077960(var_s1, var_a1_2);
                    break;
                case 37:                            /* switch 2 */
                    var_a1_2 = 0x7E;
                    func_80077960(var_s1, var_a1_2);
                    break;
                }
                if ((*(void **)((char *)(var_s1) + 0x20)) == NULL) {
                    goto block_112;
                }
                temp_v1_3 = (*(void **)((char *)(var_s1) + 0x68));
                (*(u16 *)((char *)(temp_v1_3) + 0xC)) &= 0xFFF7;
                if ((var_s2 != 0) && ((*(u8 *)((char *)(temp_s0) + 0x80)) == 0)) {
                    func_80077C00(var_s1);
                    return var_s1;
                }
                (*(f32 *)((char *)((*(void **)((char *)(var_s1) + 0x68))) + 8)) = (f32) (*(f32 *)((char *)((*(void **)((char *)((*(void **)((char *)(var_s1) + 0x20))) + 0x3C))) + 0x20));
                goto block_117;
            }
block_112:
            (*(s32 *)((char *)(var_s1) + 0x60)) |= 1;
            return NULL;
        }
    }
block_117:
    return var_s1;
}
