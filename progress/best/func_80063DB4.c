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

s32 func_80016718();
s32 func_8003E6EC();
s32 func_800635B4();
extern s32 *D_800CA31C;
extern s32 D_801002E0;
extern s32 D_80102F3C;
extern char D_80108608[];
extern char D_8010860C[];
extern char D_80108610[];
extern char D_80109688[];
extern char D_80110B28[];
extern char D_80110B2C[];
extern char D_80110B30[];

void func_80063DB4(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_a0;
    s32 var_a1;
    void *temp_s1;
    void *temp_v1;

    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    func_80016718();
    temp_v1 = *(D_80109688 + (M2C_FIELD(temp_s1, s8 *, 0x182) * 4));
    temp_v0 = D_80102F3C * 0xC;
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) *(D_80110B28 + temp_v0);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) *(D_80110B2C + temp_v0);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) *(D_80110B30 + temp_v0);
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
    M2C_FIELD(temp_v1, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
    M2C_FIELD(temp_v1, s32 *, 0x14) = (s32) M2C_FIELD(arg0, s32 *, 0x34);
    M2C_FIELD(temp_v1, s32 *, 0x18) = (s32) M2C_FIELD(arg0, s32 *, 0x38);
    M2C_FIELD(temp_v1, s32 *, 0x28) = (s32) M2C_FIELD(temp_v1, s32 *, 0x10);
    M2C_FIELD(temp_v1, s32 *, 0x2C) = (s32) M2C_FIELD(temp_v1, s32 *, 0x14);
    M2C_FIELD(temp_v1, s32 *, 0x30) = (s32) M2C_FIELD(temp_v1, s32 *, 0x18);
    var_a1 = 0;
    if (M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x68), s8 *, 0xB3) > 0) {
        var_a0 = 0;
        do {
            *(s32 *)(var_a0 + M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x68), s32 *, 0)) = M2C_FIELD(arg0, s32 *, 0x24);
            M2C_FIELD((var_a0 + M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x68), s32 *, 0)), s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
            M2C_FIELD((var_a0 + M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x68), s32 *, 0)), s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
            *(s32 *)(var_a0 + M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x68), s32 *, 4)) = M2C_FIELD(arg0, s32 *, 0x24);
            M2C_FIELD((var_a0 + M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x68), s32 *, 4)), s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
            M2C_FIELD((var_a0 + M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x68), s32 *, 4)), s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
            var_a1 += 1;
            var_a0 += 0xC;
        } while (var_a1 < M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x68), s8 *, 0xB3));
    }
    temp_v0_2 = D_80102F3C * 0xC;
    M2C_FIELD(arg0, s32 *, 0x3C) = (s32) *(D_80108608 + temp_v0_2);
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) *(D_8010860C + temp_v0_2);
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) *(D_80108610 + temp_v0_2);
    M2C_FIELD(arg0, s32 *, 0x48) = (s32) M2C_FIELD(arg0, s32 *, 0x3C);
    M2C_FIELD(arg0, s32 *, 0x4C) = (s32) M2C_FIELD(arg0, s32 *, 0x40);
    M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(arg0, s32 *, 0x44);
    func_8003E6EC(*D_800CA31C, arg0, 0);
    temp_v0_3 = D_80102F3C + 1;
    D_80102F3C = temp_v0_3;
    if (temp_v0_3 == D_801002E0) {
        D_80102F3C = 0;
    }
    M2C_FIELD(*(D_80109688 + (M2C_FIELD(temp_s1, s8 *, 0x182) * 4)), s32 *, 0xF4) = (s32) M2C_FIELD(arg0, s32 *, 0x20);
    func_800635B4(arg0, 0);
}
