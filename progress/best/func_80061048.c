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
extern char D_800C7BE2[];
extern char D_800C7C31[];
extern char D_800C7C35[];
extern char D_800C7C39[];
extern s32 *D_800CA31C;

void func_80061048(s16 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4, u16 arg5, u8 arg6, s32 arg7, u16 arg8) {
    s32 temp_a1;
    void *temp_a0;
    void *temp_v0;

    temp_v0 = func_80016410(0x2C);
    temp_a1 = arg0 & 0xFFFF;
    if (temp_v0 != NULL) {
        temp_a0 = M2C_FIELD(temp_v0, void **, 0x6C);
        M2C_FIELD(temp_a0, s32 *, 0x18) = arg7;
        M2C_FIELD(temp_a0, u16 *, 0x20) = arg8;
        M2C_FIELD(temp_a0, s32 *, 0x1C) = (s32) ((M2C_FIELD(temp_a0, s32 *, 0x1C) & 0xF) | (*(D_800C7BE2 + (temp_a1 * 2)) * 0x10) | 0x0FB00000);
        M2C_FIELD(temp_v0, u8 *, 0x7F) = (u8) *(D_800C7C31 + temp_a1);
        M2C_FIELD(temp_v0, u8 *, 0x80) = (u8) *(D_800C7C35 + temp_a1);
        M2C_FIELD(temp_v0, s16 *, 0x7C) = (s16) (arg3 + 1);
        M2C_FIELD(temp_v0, u8 *, 0x81) = (u8) *(D_800C7C39 + temp_a1);
        M2C_FIELD(temp_a0, s8 *, 0x27) = (s8) (arg4 + 1);
        M2C_FIELD(temp_a0, s8 *, 0x28) = (s8) (arg5 + 1);
        M2C_FIELD(temp_v0, s16 *, 0x7A) = 0;
        M2C_FIELD(temp_v0, s16 *, 0x78) = arg0;
        M2C_FIELD(temp_a0, u8 *, 0x22) = arg6;
        func_8003E6EC(*D_800CA31C, temp_v0, 1);
    }
}
