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

s32 func_8008C5DC();
s32 func_8009876C();
s32 func_80098A18();
extern u8 D_801002EA;
extern u8 D_8010A930;
extern u8 D_8010D720;
extern char D_8010D724[];
extern u8 D_8010D748[];
extern u8 D_8010D770[];
extern u8 D_80110DB0;
extern char D_80117388[];
extern char D_80117389[];
extern u8 D_801176E8;

typedef struct { unsigned char field_0; unsigned char field_1; unsigned short field_2; } __repair_record_temp_a0;
void func_8009991C(s32 arg0) {
int __repair_constant = 0xFF;

int __repair_literal;

    char *var_s1;
    char *var_s4;
    s32 var_s2;
    s32 var_s3;
    u8 temp_a1;
    void *temp_a0;
    void *temp_s0;

    var_s2 = 0;
__repair_literal = 0;

    if ((s32) D_801176E8 > __repair_literal) {
        var_s1 = D_8010D748;
        var_s4 = D_8010D748 - 0x24;
        var_s3 = 0;
        do {
            if (*(s32 *)var_s4 != 0) {
                if (!(arg0 & 0xFF) || (*(D_8010D770 + var_s3) == 0)) {
                    temp_s0 = var_s3 + D_8010D724;
                    func_8009876C(temp_s0);
                    M2C_FIELD(temp_s0, s32 *, 0x28) = 0;
                    M2C_FIELD(temp_s0, s32 *, 0x24) &= ~3;
                    func_80098A18(temp_s0);
                    temp_a1 = M2C_FIELD(temp_s0, u8 *, 0x63);
                    M2C_FIELD(temp_s0, s32 *, 0) = 0;
                    M2C_FIELD(temp_s0, s8 *, 0x2E) = 0;
                    temp_a0 = (temp_a1 * 4) + D_80117388;
                    if (((__repair_record_temp_a0*)temp_a0)->field_2 == 0) {
                        ((__repair_record_temp_a0*)temp_a0)->field_2 = 1U;
                        if (D_801002EA != 0xFF) {
                            ((__repair_record_temp_a0*)temp_a0)->field_1 = 0xFF;
                            ((__repair_record_temp_a0*)temp_a0)->field_0 = (u8) D_80110DB0;
                            *(D_80117389 + (D_80110DB0 * 4)) = temp_a1;
                        } else {
                            ((__repair_record_temp_a0*)temp_a0)->field_1 = 0xFF;
                            ((__repair_record_temp_a0*)temp_a0)->field_0 = 0xFFU;
                            D_801002EA = temp_a1;
                        }
                        D_80110DB0 = temp_a1;
                        if (M2C_FIELD(temp_s0, u8 *, 0x4C) != 0) {
                            D_8010A930 -= 1;
                        } else {
                            D_8010D720 -= 1;
                        }
                    }
                    M2C_FIELD(temp_s0, s32 *, 0x60) = -1;
                    *(s32 *)var_s4 = 0;
                    *(s32 *)var_s1 &= ~3;
                    goto block_13;
                }
            } else {
block_13:
                func_8008C5DC(var_s2);
            }
            var_s1 += 0x1A0;
            var_s4 += 0x1A0;
            var_s2 += 1;
            var_s3 += 0x1A0;
        } while (var_s2 < (s32) D_801176E8);
    }
}
