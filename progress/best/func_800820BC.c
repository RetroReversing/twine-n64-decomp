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

s32 func_80011938();
s32 func_80081758();
extern s16 D_800E1A80;
extern char D_8010D434[];
extern char D_8010D436[];
extern char D_80115108[];
extern char D_8011510C[];

void func_800820BC(void) {
char *__repair_addr;

    char *var_s3;
    s16 temp_v0;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;

    var_s0 = 0;
    var_s3 = &D_800E1A80;
    var_s2 = 0;
    var_s1 = 0;
    do {
        func_80011938(var_s0 & 0xFFFF, 0);
        func_80081758(var_s0);
        *(s32 *)(D_80115108 + var_s1) = (s32) *(s16 *)(D_8010D434 + var_s2);
__repair_addr = (char *)(D_8010D436 + var_s2);

        temp_v0 = *(s16 *)(__repair_addr);
        var_s0 += 1;
        var_s2 += 8;
        *(s32 *)(D_8011510C + var_s1) = (s32) temp_v0;
        *(s16 *)var_s3 = 0;
        var_s3 += 2;
        var_s1 += 0xA0;
    } while (var_s0 < 4);
}
