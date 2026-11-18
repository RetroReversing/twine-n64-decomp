/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1 -fno-strength-reduce -g, tried by autopilot */
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

extern M2C_UNK D_800E1328;
extern M2C_UNK D_800E1368;
extern M2C_UNK D_800E14B0;
extern M2C_UNK D_800E1500;
extern M2C_UNK D_80100198;
extern s32 D_801002EC;
extern s32 D_801002F0;
extern M2C_UNK D_80102EB8;
extern M2C_UNK D_8010A4C0;
extern M2C_UNK D_80112F68;
extern M2C_UNK D_80115088;

void func_8002CC74(void) {
    M2C_UNK *var_a2;
    M2C_UNK *var_a2_2;
    M2C_UNK *var_a2_3;
    M2C_UNK *var_a3;
    M2C_UNK *var_a3_3;
    s32 temp_v1;
    s32 var_t0;
    void *temp_v0;
    void *temp_v1_2;
    void *var_a3_2;

    var_a3 = &D_800E1328;
    var_a2 = &D_8010A4C0;
    do {
        M2C_FIELD(var_a3, s32 *, 0) = (s32) M2C_FIELD(var_a2, s32 *, 0);
        M2C_FIELD(var_a3, s32 *, 4) = (s32) M2C_FIELD(var_a2, s32 *, 4);
        M2C_FIELD(var_a3, s32 *, 8) = (s32) M2C_FIELD(var_a2, s32 *, 8);
        M2C_FIELD(var_a3, s32 *, 0xC) = (s32) M2C_FIELD(var_a2, s32 *, 0xC);
        var_a2 += 0x10;
        var_a3 += 0x10;
    } while (var_a2 != (&D_8010A4C0 + 0x40));
    M2C_FIELD(&D_800E1368, s32 *, 0) = (s32) D_801002EC;
    M2C_FIELD(&D_800E1368, s32 *, 4) = (s32) D_801002F0;
    var_a3_2 = &D_800E1368 + 8;
    var_a2_2 = &D_80100198;
    do {
        M2C_FIELD(var_a3_2, s32 *, 0) = (s32) M2C_FIELD(var_a2_2, s32 *, 0);
        M2C_FIELD(var_a3_2, s32 *, 4) = (s32) M2C_FIELD(var_a2_2, s32 *, 4);
        M2C_FIELD(var_a3_2, s32 *, 8) = (s32) M2C_FIELD(var_a2_2, s32 *, 8);
        M2C_FIELD(var_a3_2, s32 *, 0xC) = (s32) M2C_FIELD(var_a2_2, s32 *, 0xC);
        var_a2_2 += 0x10;
        var_a3_2 += 0x10;
    } while (var_a2_2 != (&D_80100198 + 0x140));
    var_a3_3 = &D_800E14B0;
    var_a2_3 = &D_80102EB8;
    do {
        M2C_FIELD(var_a3_3, s32 *, 0) = (s32) M2C_FIELD(var_a2_3, s32 *, 0);
        M2C_FIELD(var_a3_3, s32 *, 4) = (s32) M2C_FIELD(var_a2_3, s32 *, 4);
        M2C_FIELD(var_a3_3, s32 *, 8) = (s32) M2C_FIELD(var_a2_3, s32 *, 8);
        M2C_FIELD(var_a3_3, s32 *, 0xC) = (s32) M2C_FIELD(var_a2_3, s32 *, 0xC);
        var_a2_3 += 0x10;
        var_a3_3 += 0x10;
    } while (var_a2_3 != (&D_80102EB8 + 0x50));
    M2C_FIELD(&D_800E1500, s32 *, 0) = (s32) M2C_FIELD(&D_80112F68, s32 *, 0);
    M2C_FIELD(&D_800E1500, s32 *, 4) = (s32) M2C_FIELD(&D_80112F68, s32 *, 4);
    M2C_FIELD(&D_800E1500, s32 *, 8) = (s32) M2C_FIELD(&D_80112F68, s32 *, 8);
    M2C_FIELD(&D_800E1500, s32 *, 0xC) = (s32) M2C_FIELD(&D_80112F68, s32 *, 0xC);
    M2C_FIELD(&D_800E1500, s32 *, 0x10) = (s32) M2C_FIELD(&D_80112F68, s32 *, 0x10);
    M2C_FIELD(&D_800E1500, s32 *, 0x14) = (s32) M2C_FIELD(&D_80112F68, s32 *, 0x14);
    M2C_FIELD(&D_800E1500, s32 *, 0x18) = (s32) M2C_FIELD(&D_80112F68, s32 *, 0x18);
    M2C_FIELD(&D_800E1500, s32 *, 0x1C) = (s32) M2C_FIELD(&D_80112F68, s32 *, 0x1C);
    var_t0 = 0;
    do {
        temp_v1 = var_t0 & 0xFFFF;
        temp_v1_2 = (temp_v1 * 0xA) + (&D_800E1500 + 0x20);
        temp_v0 = (temp_v1 * 0xA0) + &D_80115088;
        M2C_FIELD(temp_v1_2, M2C_UNK *, 0) = M2C_UNALIGNED32(M2C_FIELD(temp_v0, M2C_UNK *, 0));
        M2C_FIELD(temp_v1_2, M2C_UNK *, 4) = M2C_UNALIGNED32(M2C_FIELD(temp_v0, M2C_UNK *, 4));
        M2C_FIELD(temp_v1_2, s8 *, 8) = (s8) M2C_FIELD(temp_v0, s8 *, 8);
        M2C_FIELD(temp_v1_2, s8 *, 9) = (s8) M2C_FIELD(temp_v0, s8 *, 9);
        var_t0 += 1;
    } while ((u32) (var_t0 & 0xFFFF) < 4U);
}
