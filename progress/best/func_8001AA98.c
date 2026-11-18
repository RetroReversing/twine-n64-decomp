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

s32 func_80026004();
s32 func_80029068();
s32 func_80087100();
extern char D_801001A2[];
extern u8 D_801002AD;
extern void *D_80109BB0;

void func_8001AA98(void) {
    s32 var_a0;
    s32 temp_s0;
    u32 temp_v1;
    u8 temp_s1;

    func_80029068();
    if (M2C_FIELD(D_80109BB0, u8 *, 0x2D) != 0) {
        temp_s1 = *(D_801001A2 + (D_801002AD * 0x18));
        temp_v1 = temp_s1 & 0xFFFF;
        temp_s0 = M2C_FIELD(D_80109BB0, s32 *, 0x18) + 0x28;
        switch (temp_v1) {
        case 0:
            var_a0 = 0xA;
block_9:
            func_80026004(temp_s0, "%s", func_80087100(var_a0));
            break;
        case 1:
            var_a0 = 9;
            goto block_9;
        case 2:
            var_a0 = 0x6B;
            goto block_9;
        case 3:
            var_a0 = 0x6C;
            goto block_9;
        case 4:
            var_a0 = 0x296;
            goto block_9;
        case 5:
            var_a0 = 0x297;
            goto block_9;
        }
        *(D_801001A2 + (D_801002AD * 0x18)) = temp_s1;
    }
}
