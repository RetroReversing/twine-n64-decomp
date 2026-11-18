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

s32 func_8002E9D0();
s32 func_8002FBE4();
extern u16 D_800BFC92;
extern u16 D_800BFC98;
extern char D_800E1590[];
extern u8 D_80102EDE;

void func_8002F718(void *arg0) {
    f32 temp_fv0;
    s32 var_s0;
    s32 var_v0;
    u16 temp_v0;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_v0_2;

    temp_a0 = M2C_FIELD(arg0, void **, 0x34);
    if ((M2C_FIELD(temp_a0, u8 *, 0x13) != 0) && (D_80102EDE == 0) && (D_800BFC92 & 1)) {
        func_8002FBE4(temp_a0, arg0 + 0x40, arg0 + 0x42);
    }
    temp_v0 = M2C_FIELD(arg0, u16 *, 0x40) + 1;
    M2C_FIELD(arg0, u16 *, 0x40) = temp_v0;
    if ((u32) (temp_v0 & 0xFFFF) >= 0x38U) {
        M2C_FIELD(arg0, u16 *, 0x40) = 0U;
        M2C_FIELD(arg0, u16 *, 0x42) = (u16) (M2C_FIELD(arg0, u16 *, 0x42) == 0);
    }
    if ((D_800BFC98 & 0xFFFF) == 5) {
        var_s0 = 0;
        var_v0 = 0 & 0xFFFF;
        do {
            func_8002E9D0((var_v0 * 0xC) + D_800E1590, 0xB);
            var_s0 += 1;
            var_v0 = var_s0 & 0xFFFF;
        } while ((u32) (var_s0 & 0xFFFF) < 9U);
        D_800BFC98 = 0;
    } else {
        D_800BFC98 += 1;
    }
    temp_v0_2 = M2C_FIELD(arg0, void **, 0x30);
    if (temp_v0_2 != NULL) {
        M2C_FIELD(temp_v0_2, f32 *, 0x40) += 2.0f;
        temp_a0_2 = M2C_FIELD(arg0, void **, 0x30);
        temp_fv0 = M2C_FIELD(temp_a0_2, f32 *, 0x40);
        if (temp_fv0 > 4095.0f) {
            M2C_FIELD(temp_a0_2, f32 *, 0x40) = (f32) (temp_fv0 - 4095.0f);
        }
    }
}
