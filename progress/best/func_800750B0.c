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
extern char D_800C7EE9[];
extern s8 D_80102EE8;

void *func_800750B0(s32 arg0, s32 arg1, void *arg2) {
    u16 temp_v0_2;
    u16 temp_v1;
    void *temp_v0;
    void *var_v0;

    if (((*(u8 *)&D_80102EE8) == 0) || ((s32) (*(u8 *)&D_80102EE8) < 0) || ((s32) D_80102EE8 >= 3) || (temp_v1 = M2C_FIELD(arg2, u16 *, 0x2C), (temp_v1 == 9)) || (var_v0 = NULL, (temp_v1 == 0xD))) {
        temp_v0 = func_80016410(0, arg0, 0);
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, s16 *, 0x78) = 0x6A;
            temp_v0_2 = M2C_FIELD(arg2, u16 *, 0x2C);
            M2C_FIELD(temp_v0, u16 *, 0x7C) = temp_v0_2;
            *(D_800C7EE9 + ((s16) temp_v0_2 * 0xC)) = 0;
        }
        var_v0 = temp_v0;
    }
    return var_v0;
}
