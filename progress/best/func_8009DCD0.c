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

M2C_UNK func_8009DBE8(s32, s16 *, M2C_UNK *, s16 *, M2C_UNK *, M2C_UNK *, M2C_UNK *, s32); /* extern */

s32 func_8009DCD0(s32 arg0, void *arg1, s32 arg2) {
    M2C_UNK sp48;
    volatile M2C_UNK stack_reserve[40];
    M2C_UNK spB0;
    s16 spB8;
    M2C_UNK spC0;
    M2C_UNK spC8;
    s16 spD0;
    s16 spD2;
    s16 spD4;
    s16 spD6;
    s16 spD8;
    s16 spDA;
    s16 spDC;
    s16 spDE;
    M2C_UNK *var_a3;
    M2C_UNK *var_t1;
    M2C_UNK *var_t2;
    M2C_UNK *var_v1;
    s16 *var_t0;
    u8 temp_t4;
    u8 temp_t9;
    void *var_v0;

    var_v0 = arg1;
    sp48 = 0;
    spD0 = (((s32) M2C_FIELD(arg1, u8 *, 1) >> 6) & 3) | ((M2C_FIELD(arg1, u8 *, 0) & 0xF) * 4);
    var_a3 = &spC8;
    spD2 = M2C_FIELD(arg1, u8 *, 1) & 0x3F;
    var_t0 = &spB8;
    var_t1 = &spC0;
    spD4 = ((s32) M2C_FIELD(arg1, u8 *, 2) >> 3) & 0x1F;
    var_t2 = &spB0;
    spD6 = (((s32) M2C_FIELD(arg1, u8 *, 3) >> 6) & 3) | ((M2C_FIELD(arg1, u8 *, 2) & 7) * 4);
    var_v1 = &sp48;
    spD8 = ((s32) M2C_FIELD(arg1, u8 *, 3) >> 2) & 0xF;
    spDA = (((s32) M2C_FIELD(arg1, u8 *, 4) >> 6) & 3) | ((M2C_FIELD(arg1, u8 *, 3) & 3) * 4);
    spDC = ((s32) M2C_FIELD(arg1, u8 *, 4) >> 3) & 7;
    spDE = M2C_FIELD(arg1, u8 *, 4) & 7;
    __repair_rows: { /* keep loop target stable */
        var_v1 += 0x1A;
        var_a3 += 2;
        M2C_FIELD(var_a3, s16 *, -2) = (s16) (((s32) M2C_FIELD(var_v0, u8 *, 5) >> 1) & 0x7F);
        temp_t4 = M2C_FIELD(var_v0, u8 *, 6);
        temp_t9 = M2C_FIELD(var_v0, u8 *, 5);
        var_v0 += 7;
        *var_t0 = (((s32) temp_t4 >> 7) & 1) | ((temp_t9 & 1) * 2);
        var_t0 += 2;
        var_t1 += 2;
        M2C_FIELD(var_t1, s16 *, -2) = (s16) (((s32) M2C_FIELD(var_v0, u8 *, -1) >> 5) & 3);
        var_t2 += 2;
        M2C_FIELD(var_t2, s16 *, -2) = (s16) ((((s32) M2C_FIELD(var_v0, u8 *, 0) >> 7) & 1) | ((M2C_FIELD(var_v0, u8 *, -1) & 0x1F) * 2));
        M2C_FIELD(var_v1, s16 *, -0x1A) = (s16) (((s32) M2C_FIELD(var_v0, u8 *, 0) >> 4) & 7);
        M2C_FIELD(var_v1, s16 *, -0x18) = (s16) (((s32) M2C_FIELD(var_v0, u8 *, 0) >> 1) & 7);
        M2C_FIELD(var_v1, s16 *, -0x16) = (s16) ((((s32) M2C_FIELD(var_v0, u8 *, 1) >> 6) & 3) | ((M2C_FIELD(var_v0, u8 *, 0) & 1) * 4));
        M2C_FIELD(var_v1, s16 *, -0x14) = (s16) (((s32) M2C_FIELD(var_v0, u8 *, 1) >> 3) & 7);
        M2C_FIELD(var_v1, s16 *, -0x12) = (s16) (M2C_FIELD(var_v0, u8 *, 1) & 7);
        M2C_FIELD(var_v1, s16 *, -0x10) = (s16) (((s32) M2C_FIELD(var_v0, u8 *, 2) >> 5) & 7);
        M2C_FIELD(var_v1, s16 *, -0xE) = (s16) (((s32) M2C_FIELD(var_v0, u8 *, 2) >> 2) & 7);
        M2C_FIELD(var_v1, s16 *, -0xC) = (s16) ((((s32) M2C_FIELD(var_v0, u8 *, 3) >> 7) & 1) | ((M2C_FIELD(var_v0, u8 *, 2) & 3) * 2));
        M2C_FIELD(var_v1, s16 *, -0xA) = (s16) (((s32) M2C_FIELD(var_v0, u8 *, 3) >> 4) & 7);
        M2C_FIELD(var_v1, s16 *, -8) = (s16) (((s32) M2C_FIELD(var_v0, u8 *, 3) >> 1) & 7);
        M2C_FIELD(var_v1, s16 *, -6) = (s16) ((((s32) M2C_FIELD(var_v0, u8 *, 4) >> 6) & 3) | ((M2C_FIELD(var_v0, u8 *, 3) & 1) * 4));
        M2C_FIELD(var_v1, s16 *, -4) = (s16) (((s32) M2C_FIELD(var_v0, u8 *, 4) >> 3) & 7);
        M2C_FIELD(var_v1, s16 *, -2) = (s16) (M2C_FIELD(var_v0, u8 *, 4) & 7);
    }
if (var_v1 != &spB0) goto __repair_rows;
    func_8009DBE8(arg0, &spD0, &spC8, &spB8, &spC0, &spB0, &sp48, arg2);
    return 0;
}
