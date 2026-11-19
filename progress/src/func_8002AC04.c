/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-schedule-insns, tried by autopilot */
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

s32 func_8002A1F0();

void func_8002AC04(void *arg0, u8 arg1) {
    s32 temp_index;
    s32 temp_base;
    u8 var_s1;
    u32 temp_a1;

    if ((arg0 != NULL) && (M2C_FIELD(arg0, s32 (**)(s32, s32, s32), 4) != NULL)) {
        M2C_FIELD(arg0, s8 *, 0x1F) = arg1;
        temp_a1 = arg1;
        if (temp_a1 != 0) {
            func_8002A1F0(arg0, temp_a1);
            return;
        }
        for (var_s1 = 0; var_s1 < (u8) M2C_FIELD(arg0, u8 *, 0x19); var_s1++) {
            temp_index = var_s1 * 0x3;
            temp_base = M2C_FIELD(arg0, s32 *, 0);
            M2C_FIELD(arg0, s32 (**)(s32, s32, s32), 4)(temp_base + temp_index * 4, 0, M2C_FIELD(arg0, u8 *, 0x18) == var_s1);
        }
    }
}
