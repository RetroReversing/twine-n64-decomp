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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */

s32 func_800645A4();
extern char D_800C469C[];
extern char D_800C46A1[];
extern char D_800C471E[];
extern char D_800C7C16[];
extern u8 D_80112F6C;

void func_80064630(void *arg0) {
    s32 var_a0;
    s32 var_s3;
    s32 var_s4;
    u32 temp_a0;
    u32 var_s2;
    u32 var_s2_2;
    void *temp_s0;
    void *temp_s5;
    void *var_s1;
    void *var_v1;

    var_s2 = 0;
    temp_s5 = M2C_FIELD(arg0, void **, 0x6C);
    var_a0 = 0;
    var_v1 = temp_s5;
    __repair_rows: {
        if (D_80112F6C != 0) {
            M2C_FIELD(var_v1, u16 *, 0x1BC) = (u16) *(u16 *)(D_800C7C16 + var_a0);
        } else {
            M2C_FIELD(var_v1, u16 *, 0x1BC) = 0U;
        }
        var_v1 += 2;
        var_s2 += 1;
        var_a0 += 4;
    }
if (var_s2 < 0x20U) goto __repair_rows;
    var_s3 = 0;
    var_s4 = 0;
    var_s2_2 = 0;
    var_s1 = temp_s5;
    do { {
        if (D_80112F6C != 0) {
            M2C_FIELD(var_s1, u8 *, 0x1FC) = (u8) *(D_800C46A1 + var_s3);
            M2C_FIELD(var_s1, u8 *, 0x1FF) = (u8) *(D_800C471E + var_s3);
        } else {
            M2C_FIELD(var_s1, u8 *, 0x1FC) = 0U;
            M2C_FIELD(var_s1, u8 *, 0x1FF) = 0U;
        }
        var_s3 += 0xE8;
        if (!(*(u16 *)(D_800C469C + var_s3) & 0x8000)) {
            M2C_FIELD((temp_s5 + var_s4), s8 *, 0x1FC) = 0;
        }
        temp_s0 = temp_s5 + var_s4;
        var_s4 += 8;
        var_s1 += 8;
        temp_a0 = var_s2_2;/*__repair_loop_weight*/do {do {
        var_s2_2 += 1;} while (0);} while (0);
        M2C_FIELD(temp_s0, s8 *, 0x1FD) = 0;
        M2C_FIELD(temp_s0, s8 *, 0x1FE) = 0;
        M2C_FIELD(temp_s0, f32 *, 0x200) = (f32) (func_800645A4(temp_a0) & 0xFF);
    }
} while (var_s2_2 < 0x3BU);
    M2C_FIELD(temp_s5, s8 *, 0x1FC) = 1;
    M2C_FIELD(temp_s5, s8 *, 0x32C) = 0;
    M2C_FIELD(temp_s5, s8 *, 0x324) = 0;
    if (D_80112F6C != 0) {
        M2C_FIELD(temp_s5, s8 *, 0x1FC) = 1;
    }
}
