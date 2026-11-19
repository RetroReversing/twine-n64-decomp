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

s32 func_800448A4();
s32 func_80087100();
s16 strlen();

void func_80016160(void *arg0, void *arg1) {
    s32 temp_a0_2;
    s32 temp_a2;
    s32 temp_v0;
    s32 temp_v0_2;
    
    s32 var_v1_2;
    u16 temp_a0;
    u16 var_v0;
    u32 temp_v1;
    u8 var_v0_2;

    if ((arg0 != NULL)) {
        if ((arg1 != NULL)) {
            M2C_FIELD(arg0, s32 *, 0x10) = (s32) M2C_FIELD(arg1, s32 *, 0);
            M2C_FIELD(arg0, s32 *, 0x14) = (s32) M2C_FIELD(arg1, s32 *, 4);
            M2C_FIELD(arg0, s32 *, 0x28) = (s32) ((M2C_FIELD(arg0, s32 *, 0x28) & ~0xFC) | (((u32) M2C_FIELD(arg1, u32 *, 8) >> 0x1D) * 4));
            M2C_FIELD(arg0, u16 *, 0x1E) = (u16) M2C_FIELD(arg1, u16 *, 0xA);
            temp_a0 = M2C_FIELD(arg1, u16 *, 0x14);
            if (temp_a0 != 0) {
                temp_v0 = func_80087100(temp_a0);
                M2C_FIELD(arg0, s32 *, 0x18) = temp_v0;
                M2C_FIELD(arg0, s16 *, 0x1C) = strlen(temp_v0);
            } else {
                temp_a2 = M2C_FIELD(arg1, s32 *, 0x1C);
                if (temp_a2 >= 0) {
                    func_800448A4(arg0, M2C_FIELD(arg1, s32 *, 0x18));
                } else {
                    M2C_FIELD(arg0, s32 *, 0x18) = func_80087100(3U, temp_a2);
                    M2C_FIELD(arg0, s16 *, 0x1C) = 0;
                }
            }
            M2C_FIELD(arg0, u16 *, 0x20) = (u16) M2C_FIELD(arg1, u16 *, 0xC);
            M2C_FIELD(arg0, s16 *, 0x22) = (s16) M2C_FIELD(arg1, u8 *, 0xE);
            var_v0 = M2C_FIELD(arg1, u16 *, 0x10);
            if (var_v0 == 0) {
                var_v0 = M2C_FIELD(arg0, u16 *, 0x24);
            }
            M2C_FIELD(arg0, u16 *, 0x26) = var_v0;
            var_v0_2 = M2C_FIELD(arg1, u8 *, 0x12);
            if (var_v0_2 == 0) {
                var_v0_2 = (u8) M2C_FIELD(arg0, s32 *, 0x28);
            }
            M2C_FIELD(arg0, u8 *, 0x29) = var_v0_2;
            temp_v1 = (u32) M2C_FIELD(arg1, u16 *, 0x10);
            if (!(temp_v1 & 0xF0)) {
                temp_a2 = 1;
            } else {
                temp_a2 = (temp_v1 >> 4) & 0xF;
            }
            temp_a0_2 = (M2C_FIELD(arg0, s32 *, 0x28) & 0xFFFF0FFF) | ((temp_a2 & 0xF) << 0xC);
            M2C_FIELD(arg0, s32 *, 0x28) = temp_a0_2;
            temp_v0_2 = (s32) M2C_FIELD(arg1, u16 *, 0x10) & 0xF;
            var_v1_2 = 1;
            if (temp_v0_2 != 0) {
                var_v1_2 = temp_v0_2;
            }
            M2C_FIELD(arg0, s32 *, 0x28) = (s32) ((temp_a0_2 & ~0xF00) | (var_v1_2 << 8));
        }
    }
}
