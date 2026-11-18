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

s32 func_8008CDC0();
s8 func_8008EF18();
s32 func_8008FB20();
s32 func_8008FF80();
s32 func_8008FFF8();
s32 func_8009010C();
s32 func_800902B4();
s32 func_80090464();
s32 func_8009CCB0();
extern void *D_800E5AC0;
extern char D_800E5AC4[];
extern u8 D_800E6A84;
extern char D_800E6A85[];
extern char D_800E6A88[];
extern u32 D_800EDA84;
extern u8 D_800EDA87;
extern s8 D_800EDA88;
extern void *D_800EDA8C;
extern s32 D_801002D8;
extern s32 D_8010A514;

void func_800923D0(void) {
    s32 temp_a0;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;
    s32 var_a0;
    s32 var_s2;
    u32 temp_lo;
    u32 temp_v0;
    u32 temp_v1_2;
    u32 var_s7;
    char *var_s6;
    void **temp_v1_4;
    void *temp_a1;
    void *temp_a2;
    void *temp_s1;
    void *temp_v1;
    void *temp_v1_3;
    void *var_s0;

    if (D_801002D8 != 0) {
        var_s7 = 0;
        var_s6 = &D_800E6A84;
        var_s2 = 0;
        do {
            if (*(u8 *)var_s6 != 0) {
                D_800EDA8C = var_s2 + D_800E5AC4;
                D_800EDA84 = var_s7;
                temp_a2 = D_800EDA8C;
                D_800EDA88 = func_8008EF18(*(D_800E6A88 + var_s2));
                if ((M2C_FIELD(temp_a2, s32 *, 0xF68) != 0) && (M2C_FIELD(M2C_FIELD(temp_a2, void **, 0xF6C), u32 *, 0) != -1U)) {
loop_6:
                    temp_a1 = M2C_FIELD(temp_a2, void **, 0xF6C);
                    if ((u32) (M2C_FIELD(temp_a2, s32 *, 0xF74) + M2C_FIELD(temp_a2, s32 *, 0x120)) >= (u32) M2C_FIELD(temp_a1, u32 *, 0)) {
                        temp_a0 = M2C_FIELD(temp_a1, s32 *, 4);
                        M2C_FIELD(temp_a2, s32 *, 0x124) = temp_a0;
                        func_8008CDC0(temp_a0, D_800EDA87);
                        temp_v1 = M2C_FIELD(D_800EDA8C, void **, 0xF6C);
                        M2C_FIELD(D_800EDA8C, void **, 0xF6C) = (void *) (temp_v1 + 8);
                        if (M2C_FIELD(temp_v1, s32 *, 8) != -1) {
                            goto loop_6;
                        }
                    }
                }
                temp_lo = ((u32) (((M2C_FIELD(D_800EDA8C, s32 *, 0x124) * 0xC00) / 60) * ((s32) (D_801002D8 << 0x10) / (s32) D_8010A514)) >> 3) * M2C_FIELD(D_800EDA8C, u16 *, 0xFC2);
                var_a0 = M2C_FIELD(D_800EDA8C, s32 *, 0xF68);
                temp_v1_2 = temp_lo >> 0x18;
                M2C_FIELD(D_800EDA8C, u32 *, 0x11C) = temp_v1_2;
                M2C_FIELD(D_800EDA8C, s32 *, 0x118) = (s32) ((temp_lo >> 8) & 0xFFFF);
                M2C_FIELD(D_800EDA8C, s32 *, 0x120) = (s32) ((s32) temp_v1_2 >> 1);
                if (var_a0 != 0) {
                    temp_v0 = M2C_FIELD(D_800EDA8C, s32 *, 0xF70) + M2C_FIELD(D_800EDA8C, s32 *, 0x118);
                    var_a0 = temp_v0 & 0xFFFF;
                    M2C_FIELD(D_800EDA8C, s32 *, 0xF70) = var_a0;
                    M2C_FIELD(D_800EDA8C, s32 *, 0xF74) += ((temp_v0 >> 0x10) + M2C_FIELD(D_800EDA8C, u32 *, 0x11C));
                }
                temp_s5 = func_80090464(var_a0);
                temp_s4 = func_8008FB20();
                func_8009010C();
                func_800902B4();
                func_8008FF80();
                var_s0 = M2C_FIELD(D_800EDA8C, void **, 0xF7C);
                temp_s3 = func_8008FFF8();
                if (var_s0 != NULL) {
                    do {
                        temp_s1 = M2C_FIELD(var_s0, void **, 0);
                        if (func_8009CCB0(M2C_FIELD(var_s0, s32 *, 8)) == -1) {
                            temp_v1_3 = M2C_FIELD(var_s0, void **, 0);
                            if (temp_v1_3 != NULL) {
                                M2C_FIELD(temp_v1_3, void ***, 4) = (void **) M2C_FIELD(var_s0, void ***, 4);
                            }
                            temp_v1_4 = M2C_FIELD(var_s0, void ***, 4);
                            if (temp_v1_4 != NULL) {
                                *temp_v1_4 = M2C_FIELD(var_s0, void **, 0);
                            } else {
                                M2C_FIELD(D_800EDA8C, void **, 0xF7C) = (void *) M2C_FIELD(var_s0, void **, 0);
                            }
                            M2C_FIELD(var_s0, void **, 0) = (void *) D_800E5AC0;
                            if (D_800E5AC0 != NULL) {
                                M2C_FIELD(D_800E5AC0, void **, 4) = var_s0;
                            }
                            M2C_FIELD(var_s0, void ***, 4) = NULL;
                            D_800E5AC0 = var_s0;
                        }
                        var_s0 = temp_s1;
                    } while (var_s0 != NULL);
                }
                if ((!(temp_s5 & 0xFF) & !(temp_s4 & 0xFF)) && !(temp_s3 & 0xFF)) {
                    *(u8 *)var_s6 = 0;
                    *(D_800E6A85 + var_s2) = 1;
                }
            }
            var_s6 += 0xFF8;
            var_s7 += 1;
            var_s2 += 0xFF8;
        } while (var_s7 < 8U);
    }
}
