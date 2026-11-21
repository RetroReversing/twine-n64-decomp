/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800328B8();
s32 func_800336FC(s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32);
void *func_8003C860();
s32 func_8003C94C();
s32 computeMeshBounds();
s32 func_8003CD18();
s32 func_8003FCF4();
s32 func_8003FDE0();
s32 func_8003FF3C();
s32 func_800404F0();
s32 func_80040E5C();
s32 func_800410E8();
s32 func_80041114();
s32 func_80045278();
s32 func_80045290();
s32 vec3Add();
s32 func_80083E90();
extern char D_800C0784[];
extern char D_800C0788[];
extern f32 D_800E19E0;
extern f32 D_800E19E4;
extern f32 D_800E19E8;
extern s8 D_80109A94;

typedef struct { unsigned char pad[36]; void * value; } __repair_field_24;
typedef struct { s32 w[3]; } __repair_words3;
typedef struct { unsigned char pad[52]; int value; } __repair_field_34;
void func_800411C0(void **arg0, void *arg1, s32 arg2) {
    s32 * __repair_hoisted;

    s32 __repair_store_0;
    s32 __repair_store_1;
    s32 __repair_store_2;
    s32 __repair_store_3;
    s32 sp30;
    s8 sp34;
    long sp38;
    s32 sp3C;
    unsigned sp40;
    s32 sp44;
    s32 sp48;
    s32 sp4C;
    s32 sp50;
    s32 var_a1;
    s32 var_a1_2;
    f32 var_fs1;
    
    s32 *temp_a3_4;
    s32 *temp_a3_3;
    s32 *temp_v0_16;
    s32 *temp_v1_7;
    register s32 *temp_v1_8;
    s32 temp_a1_3;
    s32 temp_a1_4;
    register s32 temp_a2;
    s32 temp_a2_2;
    register s32 temp_a2_3;
    s32 temp_a3_2;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 temp_s5;
    u32 temp_s7;
    s32 temp_v0_10;
    s32 temp_v0_13;
    s32 temp_v0_18;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s1;
    s32 var_s1_2;
    u16 temp_a0;
    u16 temp_v1_4;
    u32 temp_v1;
    u8 temp_v0_15;
    register u8 temp_v0_3;
    u8 temp_v0_4;
    u8 var_v0;
    u8 var_v0_2;
    void *temp_a0_2;
    void *temp_a1_2;
    void *temp_a3;
    void *temp_a3_5;
    void *temp_s4;
    void *temp_s4_2;
    void *temp_v0;
    void *temp_v0_11;
    void *temp_v0_12;
    register void *temp_v0_14;
    void *temp_v0_17;
    void *temp_v0_2;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_5;
    register void *temp_v1_6;
    void *temp_v1_9;
    void *var_a2;
    void *var_t0;

    s16 *tableIndex = *(s16 **)((char *)arg1 + 0x28);

    sp30 = 1;
    sp34 = 1;
    temp_s7 = *(s32 *)(D_800C0788 + (*tableIndex * 0x10));
    temp_a0 = (*(u16 *)((char *)(arg1) + 0));
    temp_v0 = (temp_a0 * 0x4C) + temp_s7;
    (*(s32 *)((char *)(temp_v0) + 0x30)) = (s32) (((*(s32 *)((char *)(temp_v0) + 0x30)) & 0xFFF0000F) | (temp_a0 * 0x10));
    temp_v0_2 = ((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7;
    (*(s32 *)((char *)(temp_v0_2) + 0x30)) = (s32) (((*(s32 *)((char *)(temp_v0_2) + 0x30)) & 0xFFFFF) | (*(*(s16 **)((char *)(arg1) + 0x28)) << 0x14));
    (*(s8 *)((char *)((((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7)) + 0x47)) = (s8) (*(u16 *)((char *)(arg1) + 0x3A));
    temp_v0_3 = (*(u8 *)((char *)(((__repair_field_24 *)arg1)->value) + 0x1E));
    var_fs1 = 1.0f;
    switch (temp_v0_3) {                            /* switch 1 */
    case 0x14:                                      /* switch 1 */
    case 0x15:                                      /* switch 1 */
    case 0x18:                                      /* switch 1 */
    case 0x19:                                      /* switch 1 */
    case 0x1A:                                      /* switch 1 */
    case 0x1B:                                      /* switch 1 */
    case 0x1E:                                      /* switch 1 */
    case 0x1F:                                      /* switch 1 */
    case 0x21:                                      /* switch 1 */
    case 0x22:                                      /* switch 1 */
    case 0x27:                                      /* switch 1 */
    case 0x3C:                                      /* switch 1 */
    case 0x3D:                                      /* switch 1 */
    case 0x3E:                                      /* switch 1 */
    case 0x40:                                      /* switch 1 */
    case 0x42:                                      /* switch 1 */
    case 0x43:                                      /* switch 1 */
    case 0x44:                                      /* switch 1 */
    case 0x45:                                      /* switch 1 */
    case 0x46:                                      /* switch 1 */
    case 0x47:                                      /* switch 1 */
    case 0x48:                                      /* switch 1 */
    case 0x49:                                      /* switch 1 */
    case 0x4D:                                      /* switch 1 */
    case 0x4F:                                      /* switch 1 */
    case 0x50:                                      /* switch 1 */
    case 0x52:                                      /* switch 1 */
    case 0x53:                                      /* switch 1 */
    case 0x68:                                      /* switch 1 */
    case 0x84:                                      /* switch 1 */
    case 0x85:                                      /* switch 1 */
    case 0x86:                                      /* switch 1 */
    case 0x87:                                      /* switch 1 */
    case 0x88:                                      /* switch 1 */
    case 0x89:                                      /* switch 1 */
    case 0x8A:                                      /* switch 1 */
    case 0x8B:                                      /* switch 1 */
    case 0x8C:                                      /* switch 1 */
    case 0x99:                                      /* switch 1 */
    case 0x9A:                                      /* switch 1 */
    case 0x9B:                                      /* switch 1 */
    case 0x9C:                                      /* switch 1 */
    case 0x9D:                                      /* switch 1 */
    case 0x9E:                                      /* switch 1 */
    case 0xC8:                                      /* switch 1 */
        if ((arg2 << 0x18) != 0) {
            temp_v0_3 = (*(u8 *)((char *)(((__repair_field_24 *)arg1)->value) + 0x1E));
            switch (temp_v0_3) {                    /* switch 2 */
            case 0x22:                              /* switch 2 */
            case 0x42:                              /* switch 2 */
            case 0x43:                              /* switch 2 */
            case 0x44:                              /* switch 2 */
            case 0x45:                              /* switch 2 */
            case 0x46:                              /* switch 2 */
            case 0x47:                              /* switch 2 */
            case 0x48:                              /* switch 2 */
            case 0x49:                              /* switch 2 */
            case 0x4F:                              /* switch 2 */
            case 0x50:                              /* switch 2 */
                temp_v0_5 = func_8003C860(*arg0, 1);
                *arg0 = temp_v0_5;
                (*(s32 *)((char *)(temp_v0_5) + 0x3C)) = (s32) (temp_s7 + ((*(u16 *)((char *)(arg1) + 0)) * 0x4C));
                (*(f32 *)((char *)(*arg0) + 0x24)) = (f32) (*(f32 *)((char *)(arg1) + 0xC));
                (*(f32 *)((char *)(*arg0) + 0x28)) = (f32) (*(f32 *)((char *)(arg1) + 0x10));
                (*(f32 *)((char *)(*arg0) + 0x2C)) = (f32) (*(f32 *)((char *)(arg1) + 0x14));
                D_800E19E0 = (*(f32 *)((char *)(*arg0) + 0x24));
                D_800E19E4 = (*(f32 *)((char *)(*arg0) + 0x28));
                D_800E19E8 = (*(f32 *)((char *)(*arg0) + 0x2C));
                break;
            default:                                /* switch 2 */
                temp_v0_6 = func_8003C860(*arg0, 0);
                *arg0 = temp_v0_6;
                (*(s32 *)((char *)(temp_v0_6) + 0x3C)) = (s32) (temp_s7 + ((*(u16 *)((char *)(arg1) + 0)) * 0x4C));
                break;
            }
            sp30 = 1;
            temp_s4 = (*(void **)((char *)(*arg0) + 0x3C));
            func_80045278(&D_800E19E0);
            (*(f32 *)((char *)(*arg0) + 0x24)) = (f32) (*(f32 *)((char *)(arg1) + 0xC));
            (*(f32 *)((char *)(*arg0) + 0x28)) = (f32) (*(f32 *)((char *)(arg1) + 0x10));
            (*(f32 *)((char *)(*arg0) + 0x2C)) = (f32) (*(f32 *)((char *)(arg1) + 0x14));
            (*(f32 *)((char *)(*arg0) + 0x30)) = (f32) ((*(f32 *)((char *)(arg1) + 0x18)) * 0.000004261058f);
            (*(f32 *)((char *)(*arg0) + 0x34)) = (f32) ((*(f32 *)((char *)(arg1) + 0x1C)) * 0.000004261058f);
            (*(f32 *)((char *)(*arg0) + 0x38)) = (f32) ((*(f32 *)((char *)(arg1) + 0x20)) * 0.000004261058f);
            (*(s32 *)((char *)(*arg0) + 0x50)) = func_8003FCF4(arg1);
            (*(f32 *)((char *)(*arg0) + 0x54)) = 0.0f;
            if ((*(s32 *)((char *)(arg1) + 0x3C)) & 0x10000) {
                temp_v0_7 = *arg0;
                (*(f32 *)((char *)(temp_v0_7) + 0x54)) += 5.0f;
            }
            if ((*(s32 *)((char *)(arg1) + 0x3C)) & 0x20000) {
                temp_v0_8 = *arg0;
                (*(f32 *)((char *)(temp_v0_8) + 0x54)) += 10.0f;
            }
            func_800404F0(arg1, *arg0, &sp30, &sp34);
            if ((*(s32 *)((char *)(arg1) + 0x3C)) & 0x2000) {
                temp_v0_9 = *arg0;
                temp_v1 = (*(u32 *)((char *)(temp_v0_9) + 0x5C));
                (*(u32 *)((char *)(temp_v0_9) + 0x5C)) = (u32) ((temp_v1 & 0x7FFFFF) | (((temp_v1 >> 0x17) | 0x10) << 0x17));
            }
            temp_a3 = ((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7;
            if ((*(u8 *)((char *)(temp_a3) + 0x45)) == 0) {
                func_8003FDE0((*(s32 *)((char *)(((__repair_field_24 *)arg1)->value) + 0x18)), &sp38, &sp3C, &sp40);
                (*(u16 *)((char *)(temp_s4) + 0x42)) = (u16) (*(u16 *)((char *)(((__repair_field_24 *)arg1)->value) + 4));
                (*(u16 *)((char *)(temp_s4) + 0x40)) = (u16) sp3C;
                (*(s8 *)((char *)((((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7)) + 0x45)) = 1;
                ((__repair_field_34 *)temp_s4)->value = func_80083E90((*(u16 *)((char *)(((__repair_field_24 *)arg1)->value) + 4)) * 0xC, 2);
                if ((u32) (sp40 - 1) < 2U) {
                    var_a1 = 4;
                    var_a0 = (*(u16 *)((char *)(temp_s4) + 0x40)) * 6;
                    var_v0 = (*(u8 *)((char *)(temp_s4) + 0x48)) | 4;
                } else {
                    var_a1 = 3;
                    var_a0 = (*(u16 *)((char *)(temp_s4) + 0x40)) * 3;
                    var_v0 = (*(u8 *)((char *)(temp_s4) + 0x48)) | 8;
                }
                (*(u8 *)((char *)(temp_s4) + 0x48)) = var_v0;
                (*(s32 *)((char *)(temp_s4) + 0x3C)) = func_80083E90(var_a0, var_a1);
                temp_v0_10 = func_80083E90((*(u16 *)((char *)(temp_s4) + 0x40)) * 2, 5);
                (*(s32 *)((char *)(temp_s4) + 0x38)) = temp_v0_10;
                __repair_hoisted = ((__repair_field_24 *)arg1)->value;
                var_s1 = 0;
                temp_s5 = (*(s32 *)((char *)(__repair_hoisted) + 0x18));
                if ((s32) (*(u16 *)((char *)(__repair_hoisted) + 4)) > 0) {
                    var_s0 = 0;
                    do {
                        vec3Add(&D_800E19E0, (*(s32 *)((char *)(((__repair_field_24 *)arg1)->value) + 0)) + var_s0, ((__repair_field_34 *)temp_s4)->value + var_s0);
                        var_s1++;
                        var_s0 += 0xC;
                    } while (var_s1 < (s32) (*(u16 *)((char *)(((__repair_field_24 *)arg1)->value) + 4)));
                }
                do { func_8003FF3C(temp_s4, temp_s5, temp_v0_10); } while (0);
                (*(void **)((char *)(*arg0) + 0x3C)) = (void *) (temp_s7 + ((*(u16 *)((char *)(arg1) + 0)) * 0x4C));
                (*(u16 *)((char *)((*(void **)((char *)(*arg0) + 0x3C))) + 0x42)) = (u16) (*(u16 *)((char *)(((__repair_field_24 *)arg1)->value) + 4));
                temp_a1_2 = *arg0;
                temp_a0_2 = (*(void **)((char *)(temp_a1_2) + 0x3C));
                func_8003C94C(temp_a0_2, temp_a1_2 + 0x40, temp_a0_2 + 0x18);
                temp_v1_2 = *arg0;
                temp_v0_11 = ((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7;
                {
                    typedef struct { s32 words[4]; } Bounds;
                    *(Bounds *)((char *)temp_v0_11 + 8) = *(Bounds *)((char *)temp_v1_2 + 0x40);
                }
                func_80040E5C((*(void **)((char *)(*arg0) + 0x3C)));
                func_80041114(*arg0);
                if (var_fs1 != 1.0f) {
                    temp_v1_3 = ((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7;
                    (*(u8 *)((char *)(temp_v1_3) + 0x48)) |= 0x10;
                }
                (*(s8 *)((char *)((((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7)) + 0x45)) = (s8) sp30;
                temp_v1_4 = (*(u16 *)((char *)(arg1) + 0));
                if (((*(u8 *)((char *)(((temp_v1_4 * 0x4C) + temp_s7)) + 0x46)) & 0x80) && (sp34 != 0)) {
                    temp_v0_12 = *(s32 *)(D_800C0784 + (*(*(s16 **)((char *)(arg1) + 0x28)) * 0x10));
                    if (temp_v0_12 != NULL) {
                        temp_s2 = (*(s32 *)((char *)(temp_v0_12) + 0x10));
                        temp_s1 = (*(s32 *)((char *)(temp_v0_12) + 0x18));
                        temp_a3_3 = ((__repair_field_24 *)arg1)->value;
                        sp44 = 0;
                        sp48 = 0;
                        func_800336FC((*(s32 *)((char *)(temp_a3_3) + 0x18)), (*(s32 *)((char *)(((temp_v1_4 * 0x4C) + temp_s7)) + 0x34)), (*(s32 *)((char *)(temp_a3_3) + 8)), (*(s32 *)((char *)(temp_a3_3) + 0x10)), sp30, var_fs1, temp_s1, temp_s2, 0, &sp44, &sp48);
                        temp_v0_13 = func_80083E90((sp44 * 0x10) + (sp48 * 8), 0x2E);
                        *(s32 *)(((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7) = temp_v0_13;
                        func_800328B8(temp_v0_13 + (sp48 * 8), temp_v0_13);
                        (*(s32 *)((char *)(temp_s4) + 0)) = temp_v0_13;
                        temp_a3_4 = ((__repair_field_24 *)arg1)->value;
                        func_800336FC((*(s32 *)((char *)(temp_a3_4) + 0x18)), (*(s32 *)((char *)((((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7)) + 0x34)), (*(s32 *)((char *)(temp_a3_4) + 8)), (*(s32 *)((char *)(temp_a3_4) + 0x10)), sp30, var_fs1, temp_s1, temp_s2, 1, NULL, NULL);
                        if (D_80109A94 != 0) {
                            temp_v1_5 = ((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7;
                            (*(u8 *)((char *)(temp_v1_5) + 0x46)) |= 0x80;
                        }
                    }
                }
                func_800410E8(*arg0);
                {
                    typedef struct { s32 words[19]; } MeshRecord;
                    *(MeshRecord *)(((u16 *)arg1)[0] * 0x4C + temp_s7) = *(MeshRecord *)temp_s4;
                }
                return;
            }
            temp_v0_14 = *arg0;
            temp_a1_4 = (*(s32 *)((char *)(temp_a3) + 0x10));
            temp_a2_2 = (*(s32 *)((char *)(temp_a3) + 0x14));
            (*(s32 *)((char *)(temp_v0_14) + 0x40)) = (s32) (*(s32 *)((char *)(temp_a3) + 8));
            (*(s32 *)((char *)(temp_v0_14) + 0x44)) = (s32) (*(s32 *)((char *)(temp_a3) + 0xC));
            (*(s32 *)((char *)(temp_v0_14) + 0x4C)) = temp_a2_2;
            (*(s32 *)((char *)(temp_v0_14) + 0x48)) = temp_a1_4;
            (*(void **)((char *)(*arg0) + 0x3C)) = (void *) (temp_s7 + ((*(u16 *)((char *)(arg1) + 0)) * 0x4C));
            (*(f32 *)((char *)(*arg0) + 0x24)) = (f32) (*(f32 *)((char *)(arg1) + 0xC));
            (*(f32 *)((char *)(*arg0) + 0x28)) = (f32) (*(f32 *)((char *)(arg1) + 0x10));
            (*(f32 *)((char *)(*arg0) + 0x2C)) = (f32) (*(f32 *)((char *)(arg1) + 0x14));
            (*(f32 *)((char *)(*arg0) + 0x30)) = (f32) ((*(f32 *)((char *)(arg1) + 0x18)) * 0.000004261058f);
            (*(f32 *)((char *)(*arg0) + 0x34)) = (f32) ((*(f32 *)((char *)(arg1) + 0x1C)) * 0.000004261058f);
            (*(f32 *)((char *)(*arg0) + 0x38)) = (f32) ((*(f32 *)((char *)(arg1) + 0x20)) * 0.000004261058f);
            func_80041114(*arg0, temp_a1_4, temp_a2_2, temp_a3);
            func_800410E8(*arg0);
            return;
        }
        return;
    default:                                        /* switch 1 */
        if ((*(u8 *)((char *)((((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7)) + 0x45)) == 0) {
            func_8003FDE0((*(s32 *)((char *)(((__repair_field_24 *)arg1)->value) + 0x18)), &sp38, &sp3C, &sp40);
            (*(s8 *)((char *)((((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7)) + 0x45)) = 1;
            sp30 = 1;
            temp_v0_15 = (*(u8 *)((char *)(((__repair_field_24 *)arg1)->value) + 0x1E));
            var_s0_2 = 0;
            switch (temp_v0_15) {                   /* switch 3 */
            case 0x73:                              /* switch 3 */
                (*(s32 *)((char *)(arg1) + 0x3C)) |= 0x1000;
            case 0x30:                              /* switch 3 */
            case 0x54:                              /* switch 3 */
            case 0x56:                              /* switch 3 */
            case 0xC9:                              /* switch 3 */
block_52:
                var_s0_2 = 1;
                break;
            case 0x74:                              /* switch 3 */
                (*(s32 *)((char *)(arg1) + 0x3C)) |= 0x1000;
                /* fallthrough */
            case 0x31:                              /* switch 3 */
                sp30 = 1;
                break;
            case 0x34:                              /* switch 3 */
            case 0x51:                              /* switch 3 */
            case 0x7A:                              /* switch 3 */
            case 0x7D:                              /* switch 3 */
block_37:
                sp30 = 5;
                goto block_52;
            case 0x29:                              /* switch 3 */
            case 0x2A:                              /* switch 3 */
            case 0x2B:                              /* switch 3 */
                sp30 = 1;
                goto block_52;
            case 0x79:                              /* switch 3 */
                sp30 = 3;
                goto block_52;
            case 0x75:                              /* switch 3 */
                (*(s32 *)((char *)(arg1) + 0x3C)) |= 0x1000;
                /* fallthrough */
            case 0x32:                              /* switch 3 */
                sp30 = 0xC;
                goto block_52;
            case 0x97:                              /* switch 3 */
                sp30 = 0xA;
                goto block_52;
            case 0x76:                              /* switch 3 */
                (*(s32 *)((char *)(arg1) + 0x3C)) |= 0x1000;
                /* fallthrough */
            case 0x33:                              /* switch 3 */
                sp30 = 4;
                goto block_52;
            case 0x77:                              /* switch 3 */
                (*(s32 *)((char *)(arg1) + 0x3C)) |= 0x1000;
                goto block_37;
            case 0xC7:                              /* switch 3 */
                sp30 = 0xF;
                goto block_52;
            case 0x80:                              /* switch 3 */
                sp30 = 5;
                break;
            case 0x78:                              /* switch 3 */
                (*(s32 *)((char *)(arg1) + 0x3C)) |= 0x1000;
                /* fallthrough */
            case 0x35:                              /* switch 3 */
                sp30 = 6;
                goto block_52;
            case 0x55:                              /* switch 3 */
                sp30 = 9;
                goto block_52;
            case 0x5D:                              /* switch 3 */
                (*(s32 *)((char *)(arg1) + 0x3C)) |= 0x1000;
                break;
            }
            if ((*(s32 *)((char *)(arg1) + 0x3C)) & 0x1000) {
                var_fs1 = 64.0f;
            }
            (*(u16 *)((char *)((((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7)) + 0x42)) = (u16) (*(u16 *)((char *)(((__repair_field_24 *)arg1)->value) + 4));
            (*(s16 *)((char *)((((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7)) + 0x40)) = (s16) sp3C;
            temp_s4_2 = temp_s7 + ((*(u16 *)((char *)(arg1) + 0)) * 0x4C);
            temp_a2_3 = temp_s4_2 + 8;
            if (!var_s0_2) {
                ((__repair_field_34 *)temp_s4_2)->value = func_80083E90((*(u16 *)((char *)(((__repair_field_24 *)arg1)->value) + 4)) * 0xC, 2, temp_a2_3);
                if ((u32) (sp40 - 1) < 2U) {
                    var_a1_2 = 4;
                    var_a0_2 = (*(u16 *)((char *)(temp_s4_2) + 0x40)) * 6;
                    var_v0_2 = (*(u8 *)((char *)(temp_s4_2) + 0x48)) | 4;
                } else {
                    var_a1_2 = 3;
                    var_a0_2 = (*(u16 *)((char *)(temp_s4_2) + 0x40)) * 3;
                    var_v0_2 = (*(u8 *)((char *)(temp_s4_2) + 0x48)) | 8;
                }
                (*(u8 *)((char *)(temp_s4_2) + 0x48)) = var_v0_2;
                (*(s32 *)((char *)(temp_s4_2) + 0x3C)) = func_80083E90(var_a0_2, var_a1_2);
                (*(s32 *)((char *)(temp_s4_2) + 0x38)) = func_80083E90((*(u16 *)((char *)(temp_s4_2) + 0x40)) * 2, 5);
                var_s1_2 = 0;
                if ((s32) (*(u16 *)((char *)(((__repair_field_24 *)arg1)->value) + 4)) > 0) {
                    var_s0_3 = 0;
                    do {
                        func_80045290((*(s32 *)((char *)(((__repair_field_24 *)arg1)->value) + 0)) + var_s0_3, ((__repair_field_34 *)temp_s4_2)->value + var_s0_3);
                        ++var_s1_2;
                        var_s0_3 += 0xC;
                    } while (var_s1_2 < (s32) (*(u16 *)((char *)(((__repair_field_24 *)arg1)->value) + 4)));
                }
                func_8003FF3C(temp_s4_2, (*(s32 *)((char *)(((__repair_field_24 *)arg1)->value) + 0x18)), (*(s32 *)((char *)(temp_s4_2) + 0x38)));
                computeMeshBounds(temp_s4_2, temp_s4_2 + 8, temp_s4_2 + 0x18);
                func_80040E5C(temp_s4_2);
            } else {
                temp_v0_16 = ((__repair_field_24 *)arg1)->value;
                func_8003CD18((*(u16 *)((char *)(temp_v0_16) + 4)), (*(s32 *)((char *)(temp_v0_16) + 0)), temp_a2_3, temp_s4_2 + 0x18);
            }
            if (var_fs1 != 1.0f) {
                temp_v1_6 = ((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7;
                (*(u8 *)((char *)(temp_v1_6) + 0x48)) |= 0x10;
            }
            (*(s8 *)((char *)((((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7)) + 0x45)) = (s8) sp30;
            if ((*(u8 *)((char *)((((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7)) + 0x46)) & 0x80) {
                temp_v0_17 = *(s32 *)(D_800C0784 + (*(*(s16 **)((char *)(arg1) + 0x28)) * 0x10));
                if (temp_v0_17 != NULL) {
                    temp_s2_2 = (*(s32 *)((char *)(temp_v0_17) + 0x10));
                    temp_s1_2 = (*(s32 *)((char *)(temp_v0_17) + 0x18));
                    temp_v1_7 = ((__repair_field_24 *)arg1)->value;
                    sp4C = 0;
                    sp50 = 0;
                    func_800336FC((*(s32 *)((char *)(temp_v1_7) + 0x18)), (*(s32 *)((char *)(temp_v1_7) + 0)), (*(s32 *)((char *)(temp_v1_7) + 8)), (*(s32 *)((char *)(temp_v1_7) + 0x10)), sp30, var_fs1, temp_s1_2, temp_s2_2, 0, &sp4C, &sp50);
                    temp_v0_18 = func_80083E90((sp4C * 0x10) + (sp50 * 8), 0x2E);
                    func_800328B8(temp_v0_18 + (sp50 * 8), temp_v0_18);
                    *(s32 *)(((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7) = temp_v0_18;
                    temp_v1_8 = ((__repair_field_24 *)arg1)->value;
                    func_800336FC((*(s32 *)((char *)(temp_v1_8) + 0x18)), (*(s32 *)((char *)(temp_v1_8) + 0)), (*(s32 *)((char *)(temp_v1_8) + 8)), (*(s32 *)((char *)(temp_v1_8) + 0x10)), sp30, var_fs1, temp_s1_2, temp_s2_2, 1, NULL, NULL);
                    if (D_80109A94) {
                        temp_v1_9 = ((*(u16 *)((char *)(arg1) + 0)) * 0x4C) + temp_s7;
                        (*(u8 *)((char *)(temp_v1_9) + 0x46)) |= 0x80;
                    }
                }
            }
        }
        break;
    }
}
