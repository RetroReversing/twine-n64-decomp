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

extern float D_800D3FE8;
extern int D_800D3FEC;
extern int D_800D3FF0;
extern float D_800D3FF4;
extern int D_800D3FF8;
extern int D_800D3FFC;
extern float D_800D4000;
extern int D_800D4004;
extern int D_800D4008;
void *func_80016410();
s32 func_80016990();
s32 func_80044670();
s32 func_800452AC();
f32 func_80045D2C();
s32 func_80047AEC();
s32 func_80047B14();
f32 func_800829A0(f32);
f32 func_800829C8();
s32 func_80082FE4();
s32 func_80083A6C();
extern char D_800C469C[];
extern char D_80109688[];

void func_800589FC(void *arg0, void *arg1) {
    f32 sp10[9];
    f32 sp40;
    s16 sp70[3];
    f32 sp78[3];
    f32 sp88;
    f32 sp8C;
    f32 sp90;
    f32 sp98;
    s32 sp9C;
    s32 spA0;
    f32 spA8;
    s32 spAC;
    s32 spB0;
    f32 spB8;
    s32 spBC;
    s32 spC0;
    f32 spC8;
    f32 spD8;
    f32 spE8;
    void *spFC;
    void *sp104;
    f32 *sp10C;
    s32 var_a1;
    f32 *temp_s0;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs0_4;
    f32 temp_fs0_5;
    f32 temp_fs0_6;
    s8 temp_s2;
    void **temp_a1;
    void **temp_v1;
    void *temp_a0;
    void *temp_s1;
    void *temp_s7;
    void *temp_v0;
    void *temp_v0_2;

    spFC = arg0;
    temp_v0 = func_80016410(0x20, 0, 0);
    if (temp_v0 != NULL) {
        temp_s1 = M2C_FIELD(spFC, void **, 0x6C);
        temp_s7 = M2C_FIELD(temp_v0, void **, 0x6C);
        var_a1 = (s8)(M2C_FIELD(temp_s1, s8 *, 0x182));
        sp98 = D_800D3FE8;
        sp9C = D_800D3FEC;
        spA0 = D_800D3FF0;
        spA8 = D_800D3FF4;
        spAC = D_800D3FF8;
        spB0 = D_800D3FFC;
        spB8 = D_800D4000;
        spBC = D_800D4004;
        spC0 = D_800D4008;
        sp88 = M2C_FIELD(arg1, s32 *, 0);
        sp8C = M2C_FIELD(arg1, f32 *, 4);
        sp90 = M2C_FIELD(arg1, f32 *, 8);
        M2C_FIELD(temp_v0, void **, 0x18) = spFC;
        temp_a1 = (var_a1 * 4) + D_80109688;
        temp_a0 = *temp_a1;
        sp104 = (M2C_FIELD(M2C_FIELD(spFC, void **, 0x68), s8 *, 0xE) * 0xE8) + D_800C469C;
        if (temp_a0 == NULL) {
            sp78[0] = 0.0f;
            sp78[1] = 0.0f;
        } else {
            sp78[0] = -(M2C_FIELD(temp_a0, f32 *, 0x34) * 651.8986f);
            sp78[1] = M2C_FIELD(*temp_a1, f32 *, 0x38) * 651.8986f;
        }
        sp78[2] = 0;
        sp10[0] = func_800829C8();
        temp_fs0 = func_800829A0(sp78[0]);
        sp10[1] = -temp_fs0 * func_800829A0(sp78[1]);
        temp_fs0_2 = func_800829A0(sp78[1]);
        temp_fs0_3 = temp_fs0_2 * func_800829C8();
        sp10[3] = 0;
        sp10[2] = temp_fs0_3;
        sp10[4] = func_800829C8();
        sp10[5] = func_800829A0(sp78[0]);
        sp10[6] = -func_800829A0(sp78[1]);
        temp_fs0_4 = func_800829C8();
        sp10[7] = -(temp_fs0_4 * func_800829A0(sp78[0]));
        temp_fs0_5 = func_800829C8();
        temp_fs0_6 = temp_fs0_5 * func_800829C8();
        sp8C = -sp8C;
        sp88 = -sp88;
        sp10[8] = temp_fs0_6;
        func_80083A6C(sp10, &sp88);
        temp_v1 = (var_a1 * 4) + D_80109688;
        temp_v0_2 = *temp_v1;
        if (temp_v0_2 != NULL) {
            sp88 += M2C_FIELD(temp_v0_2, f32 *, 0x10);
            sp8C += M2C_FIELD(*temp_v1, f32 *, 0x14);
            sp90 += M2C_FIELD(*temp_v1, f32 *, 0x18);
        }
        M2C_FIELD(temp_v0, s16 *, 0x78) = 0x27;
        sp70[0] = (s16) (s32) M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xA8), f32 *, 0x3C);
        sp70[1] = (s16) (s32) M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xA8), f32 *, 0x40);
        sp70[2] = (s16) (s32) M2C_FIELD(M2C_FIELD(temp_s1, void **, 0xA8), f32 *, 0x44);
        func_80082FE4(sp70, &sp40);
        func_80083A6C(&sp40, &sp98);
        func_80083A6C(&sp40, &spA8);
        sp10C = &spB8;
        func_80083A6C(&sp40, sp10C);
        func_80083A6C(sp10, &sp98);
        func_80083A6C(sp10, &spA8);
        func_80083A6C(sp10, sp10C);
        func_80047B14(&sp98, M2C_FIELD(sp104, s32 *, 0xC4), &spC8, sp104);
        func_80047B14(&spA8, M2C_FIELD(sp104, s32 *, 0xC8), &spD8, sp104);
        func_80047B14(sp10C, M2C_FIELD(sp104, s32 *, 0xCC), &spE8, sp104);
        temp_s0 = temp_s7 + 4;
        M2C_FIELD(temp_s7, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_s7, f32 *, 8) = 0.0f;
        M2C_FIELD(temp_s7, f32 *, 0xC) = 0.0f;
        func_800452AC(&spC8, temp_s0, temp_s0);
        func_800452AC(&spD8, temp_s0, temp_s0);
        func_800452AC(&spE8, temp_s0, temp_s0);
        M2C_FIELD(temp_s7, f32 *, 0x10) = func_80045D2C(0x42800000);
        M2C_FIELD(temp_s7, f32 *, 0x14) = func_80045D2C(0x42800000);
        M2C_FIELD(temp_s7, f32 *, 0x18) = func_80045D2C(0x42800000);
        M2C_FIELD(temp_s7, f32 *, 4) += (M2C_FIELD(spFC, f32 *, 0x24) - M2C_FIELD(spFC, f32 *, 0x30));
        M2C_FIELD(temp_s7, f32 *, 8) += (M2C_FIELD(spFC, f32 *, 0x28) - M2C_FIELD(spFC, f32 *, 0x34));
        M2C_FIELD(temp_s7, f32 *, 0xC) += (M2C_FIELD(spFC, f32 *, 0x2C) - M2C_FIELD(spFC, f32 *, 0x38));
        func_80047B14(&sp98, M2C_FIELD(sp104, s32 *, 0xB8), &spC8, sp104);
        func_80047B14(&spA8, M2C_FIELD(sp104, s32 *, 0xBC), &spD8, sp104);
        func_80047B14(sp10C, M2C_FIELD(sp104, s32 *, 0xC0), &spE8, sp104);
        func_800452AC(&spC8, &sp88, &sp88);
        func_800452AC(&spD8, &sp88, &sp88);
        func_800452AC(&spE8, &sp88, &sp88);
        func_80047AEC(&sp88, temp_v0 + 0x24, temp_v0 + 0x30);
        func_800452AC(&sp88, &sp98, &sp98);
        func_800452AC(&sp88, &spA8, &spA8);
        func_800452AC(&sp88, sp10C, sp10C);
        M2C_FIELD(temp_v0, f32 *, 0x3C) = (f32) -sp78[0];
        M2C_FIELD(temp_v0, f32 *, 0x40) = sp78[1];
        M2C_FIELD(temp_v0, s16 *, 0x7A) = 0;
        M2C_FIELD(temp_v0, s32 *, 0x44) = sp78[2];
        if (M2C_FIELD(sp104, u16 *, 2) == 0x14) {
            var_a1 = 0xE;
        
        func_80044670(temp_v0, var_a1, 0x1B, sp104);} else {
            var_a1 = 0xD;
        
        func_80044670(temp_v0, var_a1, 0x1B, sp104);}
        func_80016990(temp_v0, M2C_FIELD(spFC, s32 *, 0x20));
        M2C_FIELD(temp_v0, f32 *, 0x54) = 0.015625f;
        M2C_FIELD(temp_s7, s16 *, 0x1C) = 0x1E;
        M2C_FIELD(temp_s7, f32 *, 0) = (f32) (M2C_FIELD(spFC, f32 *, 0x28) - M2C_FIELD(M2C_FIELD(spFC, void **, 0x68), f32 *, 0x38));
        M2C_FIELD(temp_v0, s16 *, 0x7A) = 0;
    }
}
