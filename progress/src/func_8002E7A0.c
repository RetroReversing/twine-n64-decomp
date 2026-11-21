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

extern u32 D_800E1550;
extern s8 D_800E1554;
extern u8 D_800E1555;

void func_8002E7A0(void *arg0, s32 arg1, s32 arg2, u32 arg3) {
    u32 temp_v0;
    void *temp_v1;
    void *temp_v1_3;

    D_800E1550 = 0;
    if (arg3 != 0) {
        do {
            D_800E1554 = 1 << M2C_FIELD(arg0, s32 *, 4);
            D_800E1555 = 1 << D_800E1550;
            if (arg1 & D_800E1555) {
                temp_v1 = M2C_FIELD(arg0, void **, 0);
                M2C_FIELD(temp_v1, u8 *, 0) |= D_800E1554;
            }
            if ((M2C_FIELD(arg0, s32 *, 4) & 7) == 7) {
                temp_v1_3 = M2C_FIELD(arg0, void **, 0);
                M2C_FIELD(arg0, void **, 0) = (void *) (temp_v1_3 + 1);
                M2C_FIELD(temp_v1_3, s8 *, 1) = 0;
                M2C_FIELD(arg0, s32 *, 4) = 0;
            } else {
                M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 1);
            }
            temp_v0 = D_800E1550 + 1;
            D_800E1550 = temp_v0;
        } while (temp_v0 < arg3);
    }
}
