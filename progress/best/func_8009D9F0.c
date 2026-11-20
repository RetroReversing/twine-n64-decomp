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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-strength-reduce -g, tried by autopilot */

s32 func_8009F1D4();

void func_8009D9F0(void *arg0, void *arg1, s32 arg2, s32 arg3) {
int *__repair_home2 = &arg2;

    s32 factor = 0x3333;
    s32 temp_t2;
    s32 temp_t8;
    s32 temp_t9;
    void *temp_v0;
    void *temp_v0_2;

    temp_v0 = arg0 + (M2C_FIELD(arg0, s16 *, 0x188) * 0x10);
    temp_v0_2 = temp_v0 + 0x168;
    M2C_FIELD(temp_v0, s16 *, 0x168) = (s16) (((s32) ((((M2C_FIELD(arg1, s16 *, 0) - 0x20) << 0xA) * factor) + 0x4000) >> 0xF) * 2);
    M2C_FIELD(temp_v0_2, s16 *, 2) = (s16) (((s32) ((((M2C_FIELD(arg1, s16 *, 2) - 0x20) << 0xA) * 0x3333) + 0x4000) >> 0xF) * 2);
    M2C_FIELD(temp_v0_2, s16 *, 4) = (s16) (((s32) ((((M2C_FIELD(arg1, s16 *, 4) - 0x10) << 0xA) * factor) + 0xFCCD1000) >> 0xF) * 2);
    M2C_FIELD(temp_v0_2, s16 *, 6) = (s16) (((s32) ((((M2C_FIELD(arg1, s16 *, 6) - 0x10) << 0xA) * factor) + 0x04003C00) >> 0xF) * 2);
    M2C_FIELD(temp_v0_2, s16 *, 8) = (s16) (((s32) ((((M2C_FIELD(arg1, s16 *, 8) - 8) << 0xA) * 0x4B17) + 0xFFC91B1C) >> 0xF) * 2);
    M2C_FIELD(temp_v0_2, s16 *, 0xA) = (s16) (((s32) (((M2C_FIELD(arg1, s16 *, 0xA) - 8) * 0x444400 * 4) + 0x03BBF800) >> 0xF) * 2);
    temp_t2 = (M2C_FIELD(arg1, s16 *, 0xC) - 4) << 0xA;
    M2C_FIELD(temp_v0_2, s16 *, 0xC) = (s16) (((s32) ((((((((((temp_t2 << 5) - temp_t2) * 4) - temp_t2) * 8) - temp_t2) * 0x10) - temp_t2) * 2) + 0x0147936C) >> 0xF) * 2);
    temp_t8 = M2C_FIELD(arg1, s16 *, 0xE) - 4;
    temp_t9 = temp_t8 << 0xA;
    M2C_FIELD(temp_v0_2, s16 *, 0xE) = (s16) (((s32) (((((((temp_t8 * 0x7400) << 6) + temp_t9) * 4) - temp_t9) * 4) + 0x040D6B40) >> 0xF) * 2);
    do { func_8009F1D4(arg0, (*__repair_home2), arg3); } while (0);
    M2C_FIELD(arg0, s16 *, 0x188) ^= 1;
}
