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

s32 func_800882D0();
s32 func_8008C0D4();
s32 func_8008C11C();
s32 func_8009D278();
extern s8 D_800CEEC0;
extern u8 D_800CEEC1;
extern char D_800E2CC0[];
extern s32 D_800E3F1C;
extern s32 D_800E3F24;
extern s32 D_800E3F2C;
extern s32 (*D_80100180)(s32);
extern s32 D_8010D428;

void func_80088DE0(s32 arg0, s32 arg1) {
    s32 var_a1;
    char *var_s1;
    s32 temp_a0;
    s32 var_a0;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_v1;

    var_a1 = arg1;
    var_s0 = 0;
    do {
        func_800882D0(var_s0, var_a1);
        var_s0 += 1;
        var_a1 = 2;
    } while (var_s0 < 2);
    var_a0 = 0;
    do {
        var_v1 = 0;
loop_4:
        if (*(D_800E2CC0 + var_v1) == 0) {
            var_a0 += 1;
            var_v1 += 0x1228;
            if (var_a0 < 2) {
                goto loop_4;
            }
        }
        var_a0 = 0;
    } while (var_a0 != 2);
    D_800CEEC0 = 0;
    func_8008C0D4(0, 2);
    D_8010D428 = 0;
    func_8009D278();
    func_8008C11C();
    if ((D_800E3F1C != 0) && (D_800CEEC1 != 0)) {
        D_80100180(D_800E3F1C);
    }
    var_s0_2 = 0;
    if (D_800E3F2C & 1) {
        var_s1 = &D_800E3F24;
        do {
            temp_a0 = *(s32 *)var_s1;
            var_s1 += 4;
            var_s0_2 += 1;
            D_80100180(temp_a0);
        } while (var_s0_2 < 2);
    }
}
