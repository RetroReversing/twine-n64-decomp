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

s32 _Printf();
s32 func_80087100();
s16 strlen();
extern s32 func_80025D50;

void func_80026004(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;
    void *temp_s0;

    if (arg0 != NULL) {
        temp_v0 = _Printf(&func_80025D50, func_80087100(M2C_FIELD(arg0, u16 *, 0), arg1), arg1, &arg2);
        if (temp_v0 >= 0) {
            *(s32 *)(func_80087100(M2C_FIELD(arg0, u16 *, 0)) + temp_v0) = 0;
        }
        temp_s0 = M2C_FIELD(arg0, void **, 8);
        if (temp_s0 != NULL) {
            M2C_FIELD(temp_s0, s16 *, 0x1C) = strlen(M2C_FIELD(temp_s0, s32 *, 0x18));
        }
    }
}
