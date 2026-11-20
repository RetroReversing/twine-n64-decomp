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
M2C_UNK func_80045DB4(M2C_UNK32 *, f32, f32);
M2C_UNK func_800617D8(s32, M2C_UNK32 *, void *, M2C_UNK32 *, f32, f32, s32, s32, s32, s32, s32);
void func_80061BE4(void *arg0) {
    f32 __repair_fzero = 0.0f;

    s32 sp30[3];
    f32 sp40[3];
    sp30[0] = M2C_FIELD(arg0, s32 *, 0x24);
    sp30[1] = M2C_FIELD(arg0, s32 *, 0x28);
    sp30[2] = M2C_FIELD(arg0, s32 *, 0x2C);
    func_80045DB4(sp30, 1.0f, 0.5f);
    sp40[0] = __repair_fzero;
    sp40[1] = __repair_fzero;
    sp40[2] = __repair_fzero;
    func_80045DB4((s32 *)sp40, 0.02f, 0.01f);
    func_800617D8(M2C_FIELD(arg0, s32 *, 0x20), sp30, arg0 + 0x3C, (s32 *)sp40, 0.1f, 1.034f, 0x1B, 0xFB, 0x54, 0xFF, 0x80808002);
}
