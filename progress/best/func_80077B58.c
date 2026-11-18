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

s32 func_800846A0();
extern s16 D_800C9BA8;

void func_80077B58(void *arg0) {
    s32 temp_a1;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x6C);
    temp_a1 = M2C_FIELD(temp_s0, s32 *, 0x88);
    if (((temp_a1 & 0x60000000) == 0x20000000) && ((temp_a1 & 0x01E00000) == 0x200000) && (M2C_FIELD(arg0, f32 *, 0x74) > 0.0f)) {
        if (D_800C9BA8 == 0) {
            func_800846A0(arg0, temp_a1);
            D_800C9BA8 = 0xF;
        }
        M2C_FIELD(temp_s0, s32 *, 0x88) &= 0xBFFFFFFF & 0xDFFFFFFF;
    }
}
