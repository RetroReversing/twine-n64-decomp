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

s32 func_80026004();
s32 func_80029068();
u16 func_80087100();
extern s32 D_801002A8;
extern s32 D_80102FD4;
extern void *D_80109BB0;
extern s32 D_80117730;

void func_8001AA08(void) {
    s32 *var_a1;
    s32 var_a0;
    u16 var_a2;

    func_80029068();
    if (M2C_FIELD(D_80109BB0, u8 *, 0x2D) != 0) {
        var_a2 = *(u16 *)((D_80117730 * 2) + D_80102FD4);
        D_801002A8 = (s32) var_a2;
        if (var_a2 != 0) {
            var_a0 = M2C_FIELD(D_80109BB0, s32 *, 0x18);
            var_a1 = "%d";
        
        func_80026004(var_a0 + 0x28, var_a1);} else {
            var_a0 = M2C_FIELD(D_80109BB0, s32 *, 0x18);
            var_a1 = "%s";
            var_a2 = func_80087100(0x5F);
        
        func_80026004(var_a0 + 0x28, var_a1);}
    }
}
