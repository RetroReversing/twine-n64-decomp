/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-strength-reduce -g3, tried by autopilot */
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

s32 func_8009349C();
s32 func_80093758();
s32 func_8009D5D4();
s32 func_8009D9B8();
s32 func_8009D9D8();
s32 osRecvMesg();
s32 osSendMesg();
extern u8 D_800CEEC0;
extern f64 D_800D66D0;
extern char D_800E1AC0[];
extern char D_800E2C60[];
extern char D_800E2CC0[];
extern char D_800E2CC1[];
extern char D_800E2CC2[];
extern char D_800E2CC3[];
extern char D_800E2CC4[];
extern char D_800E2CD4[];
extern u8 D_800E2CD8;
extern char D_800E2CD9[];
extern char D_800E2CDC[];
extern char D_800E2CE0[];
extern s32 D_800E3F2C;
extern char D_800E3F30[];
extern s32 (*D_80100180)(s32);
extern s32 func_80088EE4;

void func_8008863C(void) {
char *__repair_addr;

    f64 var_ft0;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s0;
    s32 var_s7;
    char *var_s2;
    char *var_s3;
    char *var_s4;
    char *var_s5;
    char *var_s6;
    u8 temp_v0_2;
    void *temp_s1;

    if (D_800CEEC0 != 0) {
        osRecvMesg(D_800E3F30, 0, 1);
        var_s7 = 0;
        var_s2 = &D_800E2CD8;
        var_s6 = &D_800E2CD8 - 0xC;
        var_s3 = &D_800E2CD8 - 8;
        var_s5 = &D_800E2CD8 - 0x3B;
        var_s4 = &D_800E2CD8 - 0x10;
        var_s0 = 0;
        do {
            if (*(D_800E2CC0 + var_s0) != 0) {
                temp_s1 = var_s0 + D_800E1AC0;
                func_8009D5D4(temp_s1);
                temp_v1 = *(D_800E2CC0 + var_s0) & 0xFF;
                if (temp_v1 != 2) {
                    if (temp_v1 < 3) {
                        if (temp_v1 != 1) {
                            var_s2 += 0x1228;
                        } else {
                            if ((s8) *(u8 *)var_s5 == 2) {
                                temp_v1_2 = *(u8 *)var_s4;
                                var_ft0 = (f64) temp_v1_2;
                                if (temp_v1_2 < 0) {
                                    var_ft0 += D_800D66D0;
                                }
                                *(s32 *)(D_800E2CDC + var_s0) = 0;
                                *(D_800E2CC0 + var_s0) = 2;
                                *(D_800E2CE0 + var_s0) = ((f32) *(u16 *)(D_800E2C60 + var_s0) * 160.0f) / (f32) var_ft0;
                                __repair_rows: { func_8009D9B8(temp_s1); }
if (0) goto __repair_rows;
__repair_addr = (char *)(D_800E2CD4 + var_s0);

                                temp_v0 = func_8009349C(*(D_800E2CC4 + var_s0), *(u8 *)var_s3, *(s32 *)(__repair_addr), *(u8 *)var_s4, (s32) *(D_800E2CC1 + var_s0), (s32) *(D_800E2CC2 + var_s0), (s32) *(D_800E2CC3 + var_s0), (s32) *(D_800E2CD9 + var_s0), &func_80088EE4, var_s7);
                                M2C_FIELD(temp_s1, s32 *, 0x120C) = temp_v0;
                                if (temp_v0 == -1) {
                                    func_8009D9D8(temp_s1);
                                    goto block_17;
                                }
                                goto block_23;
                            }
                            goto block_23;
                        }
                    } else if (temp_v1 != 3) {
                        var_s2 += 0x1228;
                    } else {
                        temp_v0_2 = *(u8 *)var_s2;
                        if (temp_v0_2 == 0) {
block_17:
                            if (!(D_800E3F2C & 1)) {
                                do { D_80100180(*(u8 *)var_s3); } while (0);
                            }
                            *(D_800E2CC0 + var_s0) = 0;
                            var_s2 += 0x1228;
                        } else {
                            if (temp_v0_2 == 2) {
                                func_80093758(*(u8 *)var_s6);
                                *(u8 *)var_s6 = -1;
                            }
                            M2C_FIELD(temp_s1, s8 *, 0x1218) = (s8) (*(u8 *)var_s2 - 1);
                            goto block_23;
                        }
                    }
                } else {
                    if ((s8) *(u8 *)var_s5 == 4) {
                        *(D_800E2CC0 + var_s0) = 3;
                        *(u8 *)var_s2 = 4;
                    }
                    goto block_23;
                }
            } else {
block_23:
                var_s2 += 0x1228;
            }
            var_s6 += 0x1228;
            var_s3 += 0x1228;
            var_s5 += 0x1228;
            var_s4 += 0x1228;
            var_s7 += 1;
            var_s0 += 0x1228;
        } while (var_s7 < 2);
        osSendMesg(D_800E3F30, 0, 0);
    }
}
