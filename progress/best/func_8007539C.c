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

M2C_UNK func_8000B9B8(s32 *, void *, M2C_UNK);      /* extern */
s16 strlen(s32 *);                                  /* extern */
extern M2C_UNK D_148B400;
extern u16 *D_800C994C;
extern s32 D_800C9958;

void func_8007539C(void) {
    s32 sp10;
    s32 sp410;
    s32 *var_s3;
    s32 var_s1;
    u16 **var_s2;
    u16 *temp_v1;
    u16 *var_s0;
    u32 var_s4;

    var_s4 = 0;
    var_s3 = &D_800C9958;
    var_s2 = &D_800C994C;
    sp410 = 0;
    do {
        temp_v1 = *var_s2;
        if (*temp_v1 != 0xFFFF) {
            var_s0 = temp_v1;
            var_s1 = *var_s3;
            __repair_rows: {
                func_8000B9B8(&sp410, var_s1 + &D_148B400, 4);
                func_8000B9B8(&sp10, sp410 + &D_148B400, 0x400);
                M2C_FIELD(var_s0, s16 *, 2) = strlen(&sp10);
                M2C_FIELD(var_s0, s32 *, 4) = sp410;
                var_s0 += 8;
                var_s1 += 4;
            }
if (*var_s0 != 0xFFFF) goto __repair_rows;
        }
        var_s3 += 4;
        var_s4 += 1;
        var_s2 += 4;
    } while (var_s4 < 3U);
}
