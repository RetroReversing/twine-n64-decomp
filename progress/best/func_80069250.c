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

s32 func_800158A4();
f32 func_80045540();
s32 func_80045764();
s32 func_80046384(s32, f32, f32, f32);
s32 func_80064318();
s32 func_800643C8();
s32 func_800643D8();
f32 func_800829A0(f32);
f32 func_800829C8(f32);
s32 func_80083A6C();
extern f32 D_800C0740;
extern char D_800C469C[];
extern char D_800C46FC[];
extern f64 D_800D44F0;
extern f64 D_800D44F8;
extern u8 D_801002D4;
extern s32 D_80102ED8;
extern char D_80109688[];
extern char D_80109A98[];
extern char D_80109A9C[];
extern char D_80109AA0[];

void func_80069250(void *arg0) {
s32 __repair_operand;

    void * __repair_hoisted;

    f32 sp28[3];
    f32 sp38[3];
    f32 sp48[3];
f32 __repair_sp4C_1;
    f32 sp58[3];
    f32 sp68[9];
    f32 sp98[2];
    s32 spA8;
    f32 spB0[3];
    f32 spC0[3];
    void *spD4;
    s32 spDC;
    f32 temp_a0;
    f32 temp_a1;
    f32 temp_a2;
    f32 temp_fa0;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs0_4;
    f32 temp_fs0_5;
    f32 temp_ft0;
    f32 temp_ft0_2;
    f32 temp_ft1;
    f32 temp_ft1_2;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv1;
    s32 temp_v0_6;
    s32 var_v0;
    s8 temp_t0;
    void **temp_s5;
    void *temp_fp;
    void *temp_s2;
    void *temp_s3;
    void *temp_s4;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    
    void *temp_v1;

    temp_s3 = M2C_FIELD(arg0, void **, 0x6C);
    temp_s4 = M2C_FIELD(temp_s3, void **, 0xAC);
    temp_s2 = M2C_FIELD(temp_s3, void **, 0xB0);
    spD4 = M2C_FIELD(temp_s3, void **, 0xA8);
    func_800643D8(temp_s4);
    func_800643D8(temp_s2);
    __repair_hoisted = M2C_FIELD(arg0, void **, 0x68);
    if ((M2C_FIELD(M2C_FIELD(temp_s3, void **, 0xA8), s16 *, 0x7A) == 0) && ((temp_t0 = M2C_FIELD(temp_s3, s8 *, 0x182), spDC = (s32) temp_t0, temp_s5 = (temp_t0 * 4) + D_80109688, sp28[0] = M2C_FIELD(*temp_s5, f32 *, 0x34), temp_fp = (M2C_FIELD(__repair_hoisted, s8 *, 0xE) * 0xE8) + D_800C469C, sp28[2] = 0, sp28[1] = M2C_FIELD(*temp_s5, f32 *, 0x38), var_v0 = temp_s4 != NULL, ((M2C_FIELD(temp_fp, s32 *, 0x60) & 0xC) != 0)) || (var_v0 = temp_s4 != NULL, (M2C_FIELD(arg0, s16 *, 0x7C) == 5))) && (var_v0 & (temp_s2 != NULL))) {
        temp_v0 = *temp_s5;
        temp_a0 = M2C_FIELD(temp_v0, f32 *, 0x14);
        temp_a1 = M2C_FIELD(temp_v0, f32 *, 0x18);
        sp38[0] = M2C_FIELD(temp_v0, f32 *, 0x10);
        sp38[1] = temp_a0;
        sp38[2] = temp_a1;
        temp_fa0 = sp28[1] * 651.8986f;
        sp98[1] = temp_fa0;
        sp98[0] = -(sp28[0] * 651.8986f);
        temp_v0_2 = *temp_s5;
        sp48[0] = -((M2C_FIELD(temp_v0_2, f32 *, 0x78) * M2C_FIELD(temp_s3, f32 *, 0x24)) / M2C_FIELD(temp_v0_2, f32 *, 0x4C)) / M2C_FIELD(temp_v0_2, f32 *, 0x68);
        sp48[2] = 1.0f;
        temp_v0_3 = *temp_s5;
        sp48[1] = ((M2C_FIELD(temp_v0_3, f32 *, 0x7C) * M2C_FIELD(temp_s3, f32 *, 0x28)) / M2C_FIELD(temp_v0_3, f32 *, 0x4C)) / M2C_FIELD(temp_v0_3, f32 *, 0x6C);
        sp68[0] = func_800829C8(temp_fa0);
        temp_fs0 = func_800829A0(sp98[0]);
        sp68[1] = -temp_fs0 * func_800829A0(temp_fa0);
        temp_fs0_2 = func_800829A0(temp_fa0);
        temp_fs0_3 = temp_fs0_2 * func_800829C8(sp98[0]);
        sp68[3] = 0;
        sp68[2] = temp_fs0_3;
        sp68[4] = func_800829C8(sp98[0]);
        sp68[5] = func_800829A0(sp98[0]);
        sp68[6] = -func_800829A0(temp_fa0);
        temp_fs0_4 = func_800829C8(temp_fa0);
        sp68[7] = -(temp_fs0_4 * func_800829A0(sp98[0]));
        temp_fs0_5 = func_800829C8(sp98[0]);
        sp68[8] = temp_fs0_5 * func_800829C8(temp_fa0);
        func_80083A6C(sp68, sp48);
        func_80045764(sp48, sp48);
        temp_ft0 = sp48[1] * 256.0f;
        temp_fv0 = sp48[2] * 256.0f;
        temp_ft1 = sp48[0] * 256.0f;
        sp48[0] = temp_ft1;
        __repair_sp4C_1 = temp_ft0;
        sp48[2] = temp_fv0;
        sp48[0] = temp_ft1 + sp38[0];
        sp48[1] = (sp38[1]) + (temp_ft0);
        sp48[2] = temp_fv0 + sp38[2];
        if (M2C_FIELD(arg0, s16 *, 0x7C) == 5) {
            temp_v0_4 = M2C_FIELD(M2C_FIELD(temp_s3, void **, 0xBC), void **, 0x6C);
            M2C_FIELD(temp_v0_4, f32 *, 0) = sp48[0];
            M2C_FIELD(temp_v0_4, f32 *, 4) = sp48[1];
            M2C_FIELD(temp_v0_4, f32 *, 8) = sp48[2];
        }
        if ((func_800158A4(sp38, sp48, M2C_FIELD(*temp_s5, s32 *, 0xF4), sp58, &spA8, 0, M2C_FIELD(temp_s3, s32 *, 0), 1, 0) << 0x18) != 0) {
            sp58[0] = sp48[0];
            sp58[1] = sp48[1];
            sp58[2] = sp48[2];
        }
        __repair_operand = M2C_FIELD(M2C_FIELD(spD4, void **, 0x68), s32 *, 4);
        temp_v0_5 = (M2C_FIELD(temp_fp, u16 *, 0x90) * 0xC) + __repair_operand;
        temp_a2 = M2C_FIELD(temp_v0_5, f32 *, 8);
        spB0[0] = M2C_FIELD(temp_v0_5, f32 *, 0);
        spB0[1] = M2C_FIELD(temp_v0_5, f32 *, 4);
        spB0[2] = temp_a2;
        spB0[1] = -spB0[1];
        spB0[0] = -spB0[0];
        func_80083A6C(sp68, spB0, temp_a2);
        spB0[0] += M2C_FIELD(*((M2C_FIELD(temp_s3, s8 *, 0x182) * 4) + D_80109688), f32 *, 0x10);
        spB0[1] += M2C_FIELD(*((M2C_FIELD(temp_s3, s8 *, 0x182) * 4) + D_80109688), f32 *, 0x14);
        spB0[2] += M2C_FIELD(*((M2C_FIELD(temp_s3, s8 *, 0x182) * 4) + D_80109688), f32 *, 0x18);
        temp_fv0_2 = func_80045540(spB0, sp58);
        M2C_FIELD(temp_s4, f32 *, 0x54) = temp_fv0_2;
        M2C_FIELD(temp_s4, f32 *, 0x24) = spB0[0];
        M2C_FIELD(temp_s4, f32 *, 0x28) = spB0[1];
        M2C_FIELD(temp_s4, f32 *, 0x2C) = spB0[2];
        temp_ft1_2 = spB0[0] - sp58[0];
        temp_ft0_2 = spB0[1] - sp58[1];
        temp_fv1 = spB0[2] - sp58[2];
        spC0[0] = temp_ft1_2;
        spC0[1] = temp_ft0_2;
        spC0[2] = temp_fv1;
        func_80046384(temp_s4 + 0x3C, temp_ft1_2, temp_ft0_2, temp_fv1);
        M2C_FIELD(temp_s4, s32 *, 0x44) = 0;
        M2C_FIELD(temp_s4, s32 *, 0x58) |= 0x10000;
        M2C_FIELD(temp_s4, f32 *, 0x3C) = (f32) -M2C_FIELD(temp_s4, f32 *, 0x3C);
        M2C_FIELD(temp_s2, s32 *, 0x58) |= 0x10000;
        M2C_FIELD(temp_s2, f32 *, 0x24) = sp58[0];
        M2C_FIELD(temp_s2, f32 *, 0x28) = sp58[1];
        M2C_FIELD(temp_s2, f32 *, 0x2C) = sp58[2];
        if (spA8 == 1) {
            M2C_FIELD(temp_s2, s8 *, 0x7F) = 0x40;
            M2C_FIELD(temp_s2, s8 *, 0x80) = 0;
            M2C_FIELD(temp_s2, s8 *, 0x81) = 0;
        } else {
            M2C_FIELD(temp_s2, u8 *, 0x7F) = 0xFF;
            M2C_FIELD(temp_s2, u8 *, 0x80) = 0xFF;
            M2C_FIELD(temp_s2, u8 *, 0x81) = 0xFF;
        }
        temp_v1 = M2C_FIELD(arg0, void **, 0x68);
        if ((M2C_FIELD(temp_v1, u16 *, 0xC) & 1) && (*(s32 *)(D_800C46FC + (M2C_FIELD(temp_v1, s8 *, 0xE) * 0xE8)) & 8)) {
            temp_v0_6 = spDC * 0xC;
            *(s32 *)(D_80109A98 + temp_v0_6) = sp58[0];
            *(s32 *)(D_80109A9C + temp_v0_6) = sp58[1];
            *(s32 *)(D_80109AA0 + temp_v0_6) = sp58[2];
        }
        if (M2C_FIELD(arg0, s16 *, 0x7C) == 5) {
            spD4 = M2C_FIELD(M2C_FIELD(temp_s3, void **, 0xBC), void **, 0x6C);
            M2C_FIELD(spD4, f32 *, 0) = sp58[0];
            M2C_FIELD(spD4, f32 *, 4) = sp58[1];
            M2C_FIELD(spD4, f32 *, 8) = sp58[2];
        }
        if (M2C_FIELD(temp_fp, s32 *, 0x60) & 4) {
            temp_fv0_3 = (f32) ((f64) ((temp_fv0_2 * temp_fv0_2) / D_800C0740) + D_800D44F0);
            M2C_FIELD(temp_s2, f32 *, 0x54) = temp_fv0_3;
            if (D_800D44F8 < (f64) temp_fv0_3) {
                M2C_FIELD(temp_s2, f32 *, 0x54) = 4.0f;
            }
            if (D_80102ED8 != 0) {
                if (D_801002D4 != 0) {
                    func_800643C8(temp_s4);
                }
            } else {
                func_80064318(temp_s4, M2C_FIELD(temp_s3, s8 *, 0x182));
            }
            func_800643C8(temp_s2);
        }
    }
}
