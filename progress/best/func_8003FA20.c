/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */
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

M2C_UNK func_80032884(M2C_UNK);                     /* extern */
extern M2C_UNK D_800C0784;
extern M2C_UNK D_800C0788;
extern s32 D_80100914;

void func_8003FA20(void) {
    u32 var_v1;

    var_v1 = 0;
    D_80100914 = 0x1FC;
    __repair_rows: {
        *(&D_800C0784 + var_v1) = 0;
        *(&D_800C0788 + var_v1) = 0;
        var_v1 += 0x10;
    }
if (var_v1 < 0x1FC0U) goto __repair_rows;
    func_80032884(0x1FC0);
}
