/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-strength-reduce, tried by autopilot */
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

M2C_UNK memset(s32, M2C_UNK, s32);                  /* extern */
extern M2C_UNK D_800CE354;
extern s32 D_80100904;
extern s32 D_80100918;
extern s32 D_80102CB8;
extern s32 D_80109A90;
extern s32 D_8010D368;

void func_80083C98(void) {
    s32 var_v1;
    u32 var_a0;

    var_a0 = 0;
    var_v1 = 0;
    __repair_rows: {
        *((M2C_UNK *)((s8 *)&D_800CE354 + var_v1)) = 0;
        var_a0 += 1;
        var_v1 += 0xC;
    }
if (var_a0 < 0x35U) goto __repair_rows;
    D_80102CB8 = D_8010D368;
    D_80100904 = D_80100918;
    D_80109A90 = D_80100918;
    memset(D_80100918, 0, D_8010D368 - D_80100918);
}
