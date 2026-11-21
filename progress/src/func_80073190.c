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

s32 func_8003941C();
extern u8 sSubdivideFlags;
extern f64 D_800D4830;
extern s32 sSubdivideMode;
extern f32 gSubdivideMinSize;
extern u32 sSubdivideBank;
extern s32 sSubdivideCount;

void func_80073190(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f64 var_fv1;

    var_fv1 = (f64) arg2;
    sSubdivideBank = (u32) M2C_FIELD(arg0, u32 *, 0x30) >> 0x14;
    if (arg2 < 0) {
        var_fv1 += D_800D4830;
    }
    gSubdivideMinSize = (f32) var_fv1;
    sSubdivideMode = arg3;
    sSubdivideFlags = M2C_FIELD(arg0, u8 *, 0x44);
    sSubdivideCount = 0;
    func_8003941C(arg0, arg1, 0, 0, 1);
}
