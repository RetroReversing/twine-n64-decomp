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

extern int D_800D4240;
extern int D_800D4244;
extern int D_800D4248;
s32 func_8001751C();
s32 func_80017EC0();
s32 func_80045CF8();
s32 func_80061578();
s32 func_80082FE4();
s32 func_80083A6C();
extern u8 D_80109A60[];

void func_80061168(void *arg0) {
    s32 sp10;
    s32 sp14;
    s32 sp18;
    char sp20[0x30];
    s16 sp50;
    s16 sp52;
    s16 sp54;
    s32 sp58;
    s32 sp5C;
    s32 sp60;
    f32 sp68;
    f32 sp6C;
    f32 sp70;
    s16 temp_v1;
    s16 var_v0;
    s32 var_s0;
    
    u8 temp_v0;
    void **temp_v0_2;
    void *temp_s2;
    void *var_v1;

    if ((M2C_FIELD(arg0, s32 *, 0x58) & 4) || (M2C_FIELD(arg0, s32 *, 0x60) & 0x3000)) {
        temp_v1 = M2C_FIELD(arg0, s16 *, 0x7A);
        temp_s2 = M2C_FIELD(arg0, void **, 0x6C);
        if (temp_v1 != 1) {
            if (temp_v1 >= 2) {
                if (temp_v1 != 2) {
                    M2C_FIELD(arg0, s32 *, 0x60) = 0;
                    return;
                }
                if (func_80045CF8(M2C_FIELD(temp_s2, u8 *, 0x28)) == 0) {
                    var_v0 = 1;
                    goto block_25;
                }
                goto block_26;
            }
            if (temp_v1 != 0) {
                M2C_FIELD(arg0, s32 *, 0x60) = 0;
                return;
            }
            sp10 = D_800D4240;
            var_s0 = D_800D4248;
            sp50 = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x3C);
            sp52 = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x40);
            sp54 = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x44);
            func_80082FE4(&sp50, sp20);
            do { func_80083A6C(sp20, &sp10); } while (0);
            M2C_FIELD(temp_s2, s32 *, 0) = sp10;
            sp14 = D_800D4244;
            M2C_FIELD(temp_s2, s32 *, 4) = sp14;
            var_v0 = 1;
            M2C_FIELD(temp_s2, s32 *, 8) = var_s0;
            goto block_25;
        }
        temp_v0 = M2C_FIELD(temp_s2, u8 *, 0x22);
        if ((temp_v0 == 0) || (*(D_80109A60 + temp_v0) != 0)) {
            if (func_80045CF8((u8) M2C_FIELD(arg0, s16 *, 0x7C)) == 0) {
                sp58 = M2C_FIELD(arg0, s32 *, 0x24);
                sp5C = M2C_FIELD(arg0, s32 *, 0x28);
                sp60 = M2C_FIELD(arg0, s32 *, 0x2C);
                sp68 = M2C_FIELD(arg0, f32 *, 0x3C);
                sp6C = M2C_FIELD(arg0, f32 *, 0x40);
                sp70 = M2C_FIELD(arg0, f32 *, 0x44);
                func_8001751C(M2C_FIELD(temp_s2, s32 *, 0x18), M2C_FIELD(temp_s2, u8 *, 0x21), &sp58, &sp68);
                func_80061578(arg0, &sp58);
                func_80017EC0(arg0);
                sp14 = M2C_FIELD(arg0, u16 *, 0x78);
                var_s0 = 0;
                if ((s32) sp14 >= 0x47) {
                    if ((s32) sp14 >= 0x49) {
                        if (sp14 == 0x49) {
                            var_s0 = 0x02000000;
                            goto block_18;
                        }
                    } else {
block_18:
                        temp_v0_2 = M2C_FIELD(arg0, void ***, 0x20);
                        if (temp_v0_2 != NULL) {
                            var_v1 = *temp_v0_2;
                            if (var_v1 != NULL) {
                                __repair_rows: {
                                    M2C_FIELD(var_v1, s32 *, 0x60) |= var_s0;
                                    var_v1 = M2C_FIELD(var_v1, void **, 0);
                                }
if (var_v1 != NULL) goto __repair_rows;
                            }
                        }
                    }
                }
            }
            if (func_80045CF8(M2C_FIELD(temp_s2, u8 *, 0x27)) == 0) {
                var_v0 = 2;
block_25:
                M2C_FIELD(arg0, s16 *, 0x7A) = var_v0;
            }
            goto block_26;
        }
    } else {
block_26:
        M2C_FIELD(arg0, s32 *, 0x60) = 0;
    }
}
