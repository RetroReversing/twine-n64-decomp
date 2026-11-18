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
s32 func_8003E6EC();
s32 func_80044670();
extern s32 *D_800CA31C;

void *func_80061DC4(s32 arg0, s32 arg1, void *arg2) {
    s32 temp_v0_2;
    void *temp_a0;
    void *temp_v0;

    temp_v0 = func_80016410(8, arg0, arg1);
    if (temp_v0 != NULL) {
        temp_a0 = M2C_FIELD(temp_v0, void **, 0x6C);
        M2C_FIELD(temp_v0, s16 *, 0x78) = 0x52;
        temp_v0_2 = (M2C_FIELD(temp_a0, s32 *, 0) & 0xFFFFF) | (*M2C_FIELD(arg2, s16 **, 0x28) << 0x14);
        M2C_FIELD(temp_a0, s32 *, 0) = temp_v0_2;
        M2C_FIELD(temp_a0, s32 *, 0) = (s32) ((temp_v0_2 & 0xFFF0000F) | (M2C_FIELD(arg2, u16 *, 0) * 0x10));
        M2C_FIELD(temp_a0, s8 *, 4) = (s8) M2C_FIELD(arg2, u16 *, 0x2C);
        M2C_FIELD(temp_a0, s8 *, 5) = (s8) M2C_FIELD(arg2, u16 *, 0x2E);
        M2C_FIELD(temp_a0, s8 *, 6) = (s8) M2C_FIELD(arg2, u16 *, 0x30);
        M2C_FIELD(temp_v0, u8 *, 0x7F) = 0xF0;
        M2C_FIELD(temp_v0, u8 *, 0x80) = 0xFF;
        M2C_FIELD(temp_v0, u8 *, 0x81) = 0xFF;
        M2C_FIELD(temp_v0, s16 *, 0x7A) = 0;
        M2C_FIELD(temp_v0, u8 *, 0x82) = 0x80;
        func_80044670(temp_v0, M2C_FIELD(arg2, u16 *, 0), *M2C_FIELD(arg2, s16 **, 0x28));
        func_8003E6EC(*D_800CA31C, temp_v0, 1);
    }
    return temp_v0;
}
