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

extern char D_800C470A[];
extern s32 D_80102ED8;

s32 func_8000299C(void *arg0, s32 arg1) {
    s32 var_a1;
    s32 var_a2;
    s32 var_v0;
    u8 var_a2_2;
    void *temp_a0;

    var_a1 = arg1;
    var_a2 = 1;
    if ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0x14) & 0x200000) && (D_80102ED8 == 0)) {
        var_a2 = 0;
        if (var_a1 != 0x153) {
            if (var_a1 < 0x154) {
                if (var_a1 < 0x126) {
                    if (var_a1 < 0x124) {
                        if (var_a1 != 7) {
                            if (var_a1 < 8) {
                                if (var_a1 == 2) {
                                    var_a1 = 0x2FA;
                                } else {
                                    var_a2 = 1;
                                }
                            } else {
                                var_v0 = 0x10B;
                                if (var_a1 != 0x106) {
                                    goto block_41;
                                }
                                goto block_45;
                            }
                        } else {
                            goto block_46;
                        }
                    } else {
                        goto block_45;
                    }
                } else if (var_a1 < 0x128) {
                    var_a2 = 1;
                } else if (var_a1 < 0x12A) {
                    var_a1 = 0x2FC;
                } else {
                    var_v0 = 0x14D;
                    goto block_41;
                }
            } else if (var_a1 != 0x2A9) {
                if (var_a1 < 0x2AA) {
                    if (var_a1 != 0x165) {
                        if (var_a1 < 0x166) {
                            if (var_a1 == 0x15F) {
                                var_a1 = 0x2FA;
                            } else {
                                var_a2 = 1;
                            }
                        } else {
                            switch (var_a1) {       /* irregular */
                            case 0x20A:
                                var_a1 = 0x20C;
                                break;
                            default:
                                var_a2 = 1;
                                break;
                            case 0x209:
                                var_a1 = 0x20B;
                                break;
                            }
                        }
                    } else {
block_46:
                        var_a1 = 0x2FB;
                    }
                } else if (var_a1 != 0x2EA) {
                    if (var_a1 < 0x2EB) {
                        if (var_a1 != 0x2E9) {
                            var_a2 = 1;
                        } else {
                            var_a1 = 0x304;
                        }
                    } else {
                        var_v0 = 0x46D;
                        if (var_a1 != 0x2EB) {
block_41:
                            if (var_a1 == var_v0) {
                                var_a1 = 0x2FC;
                            } else {
                                var_a2 = 1;
                            }
                        } else {
                            var_a1 = 0x306;
                        }
                    }
                } else {
                    var_a1 = 0x305;
                }
            } else {
                var_a1 = 0x302;
            }
        } else {
block_45:
            var_a1 = 0x2FC;
        }
    }
    if (var_a2 != 0) {
        temp_a0 = M2C_FIELD(arg0, void **, 0x68);
        if (!(M2C_FIELD(temp_a0, s32 *, 0x14) & 0x20000)) {
            var_a2_2 = *(D_800C470A + (M2C_FIELD(temp_a0, s8 *, 0xE) * 0xE8));
            if ((u32) (var_a1 - 1) < 0x14CU) {
                if (var_a2_2 == 5) {
                    var_a2_2 = 2;
                }
                var_a1 = (var_a1 - ((var_a1 - 2) % 5)) + var_a2_2;
            } else if ((u32) (var_a1 - 0x14C) < 0x68U) {
                var_a1 = (var_a1 - ((var_a1 - 0x14D) % 6)) + var_a2_2;
            }
        }
    }
    return var_a1;
}
