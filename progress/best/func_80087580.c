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

void *func_80016410();
s32 func_80044670();
s32 func_80076340();
s32 func_80087380();
extern u8 D_800B21CF;
extern u8 D_800B241F;

void *func_80087580(void *arg0, void *arg1, void *arg2, void *arg3, s32 arg4) {
    u32 var_s4;
    void *temp_s0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *var_s2;

    temp_v0 = func_80016410(0x4C, 0, 0);
    if (temp_v0 != NULL) {
        temp_s0 = M2C_FIELD(temp_v0, void **, 0x6C);
        M2C_FIELD(temp_s0, s8 *, 0x44) = (s8) M2C_FIELD(arg2, u16 *, 0x2C);
        M2C_FIELD(temp_s0, s8 *, 0x45) = (s8) M2C_FIELD(arg2, u16 *, 0x2E);
        M2C_FIELD(temp_s0, s8 *, 0x46) = (s8) M2C_FIELD(arg2, u16 *, 0x30);
        M2C_FIELD(temp_s0, s8 *, 0x47) = (s8) M2C_FIELD(arg2, u16 *, 0x32);
        M2C_FIELD(temp_s0, s8 *, 0x48) = (s8) M2C_FIELD(arg2, u16 *, 0x34);
        M2C_FIELD(temp_s0, s8 *, 0x49) = (s8) M2C_FIELD(arg2, u16 *, 0x36);
        M2C_FIELD(temp_s0, void **, 0x1C) = arg3;
        M2C_FIELD(temp_s0, s8 *, 0x4A) = (s8) M2C_FIELD(arg2, u16 *, 0x38);
        M2C_FIELD(temp_s0, s8 *, 0x4B) = (s8) M2C_FIELD(arg2, u16 *, 0x40);
        if (arg3 != NULL) {
            M2C_FIELD(temp_s0, s16 *, 0x28) = (s16) arg4;
            M2C_FIELD(temp_s0, s16 *, 0x2A) = 0;
            M2C_FIELD(temp_s0, s32 *, 0x20) = 0;
            M2C_FIELD(temp_s0, f32 *, 0x24) = 0.01f;
            func_80076340(temp_s0 + 0x1C, 1, 0x40066666);
            temp_v0_2 = M2C_FIELD(temp_s0, void **, 0x1C);
            M2C_FIELD(temp_v0, s32 *, 0x30) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0);
            M2C_FIELD(temp_v0, s32 *, 0x34) = (s32) M2C_FIELD(temp_v0_2, s32 *, 4);
            M2C_FIELD(temp_v0, s32 *, 0x38) = (s32) M2C_FIELD(temp_v0_2, s32 *, 8);
            M2C_FIELD(temp_v0, s32 *, 0x24) = (s32) M2C_FIELD(temp_v0, s32 *, 0x30);
            M2C_FIELD(temp_v0, s32 *, 0x28) = (s32) M2C_FIELD(temp_v0, s32 *, 0x34);
            M2C_FIELD(temp_v0, s32 *, 0x2C) = (s32) M2C_FIELD(temp_v0, s32 *, 0x38);
            temp_v0_3 = M2C_FIELD(temp_s0, void **, 0x1C);
            M2C_FIELD(temp_v0, s32 *, 0x48) = (s32) M2C_FIELD(temp_v0_3, s32 *, 0xC);
            M2C_FIELD(temp_v0, s32 *, 0x4C) = (s32) M2C_FIELD(temp_v0_3, s32 *, 0x10);
            M2C_FIELD(temp_v0, s32 *, 0x50) = (s32) M2C_FIELD(temp_v0_3, s32 *, 0x14);
        } else {
            M2C_FIELD(temp_v0, s32 *, 0x30) = (s32) M2C_FIELD(arg0, s32 *, 0);
            M2C_FIELD(temp_v0, s32 *, 0x34) = (s32) M2C_FIELD(arg0, s32 *, 4);
            M2C_FIELD(temp_v0, s32 *, 0x38) = (s32) M2C_FIELD(arg0, s32 *, 8);
            M2C_FIELD(temp_v0, s32 *, 0x24) = (s32) M2C_FIELD(temp_v0, s32 *, 0x30);
            M2C_FIELD(temp_v0, s32 *, 0x28) = (s32) M2C_FIELD(temp_v0, s32 *, 0x34);
            M2C_FIELD(temp_v0, s32 *, 0x2C) = (s32) M2C_FIELD(temp_v0, s32 *, 0x38);
            M2C_FIELD(temp_v0, s32 *, 0x48) = (s32) M2C_FIELD(arg1, s32 *, 0);
            M2C_FIELD(temp_v0, s32 *, 0x4C) = (s32) M2C_FIELD(arg1, s32 *, 4);
            M2C_FIELD(temp_v0, s32 *, 0x50) = (s32) M2C_FIELD(arg1, s32 *, 8);
        }
        M2C_FIELD(temp_v0, s32 *, 0x3C) = (s32) M2C_FIELD(temp_v0, s32 *, 0x48);
        M2C_FIELD(temp_v0, s32 *, 0x40) = (s32) M2C_FIELD(temp_v0, s32 *, 0x4C);
        M2C_FIELD(temp_v0, s32 *, 0x44) = (s32) M2C_FIELD(temp_v0, s32 *, 0x50);
        M2C_FIELD(temp_v0, s16 *, 0x78) = 0x3B;
        M2C_FIELD(temp_v0, s16 *, 0x7A) = 0;
        M2C_FIELD(temp_v0, s16 *, 0x7C) = 0;
        var_s4 = 0;
        func_80044670(temp_v0, M2C_FIELD(arg2, u16 *, 0), *M2C_FIELD(arg2, s16 **, 0x28));
        var_s2 = temp_s0;
        M2C_FIELD(temp_v0, s32 *, 0x5C) |= 0x600;
        M2C_FIELD(temp_v0, s32 *, 0x58) |= 0x20000;
        do {
            temp_v0_4 = func_80016410(0, 0, 0);
            M2C_FIELD(var_s2, void **, 0x2C) = temp_v0_4;
            if (temp_v0_4 != NULL) {
                M2C_FIELD(temp_v0_4, void **, 0x18) = temp_v0;
                M2C_FIELD(temp_v0_4, s16 *, 0x78) = 0x30;
                M2C_FIELD(temp_v0_4, s32 *, 0x5C) |= 0x600;
                func_80044670(temp_v0_4, 3U, *M2C_FIELD(arg2, s16 **, 0x28));
            }
            var_s4 += 1;
            var_s2 += 4;
        } while (var_s4 < 6U);
        func_80087380(temp_v0);
        M2C_FIELD(temp_s0, s16 *, 0x14) = 0x1EF;
        M2C_FIELD(temp_s0, u8 *, 0x19) = 0xFF;
        M2C_FIELD(temp_s0, s8 *, 0x18) = 0;
        M2C_FIELD(temp_s0, s8 *, 0x16) = 0;
        M2C_FIELD(temp_s0, s8 *, 0x17) = 0;
        M2C_FIELD(temp_s0, s8 *, 0x1A) = 1;
        M2C_FIELD(temp_s0, f32 *, 0xC) = (f32) D_800B21CF;
        M2C_FIELD(temp_s0, s32 *, 0) = -1;
        M2C_FIELD(temp_s0, f32 *, 4) = 1000.0f;
        M2C_FIELD(temp_s0, f32 *, 8) = 1000.0f;
        M2C_FIELD(temp_s0, f32 *, 0x10) = (f32) D_800B241F;
    }
    return temp_v0;
}
