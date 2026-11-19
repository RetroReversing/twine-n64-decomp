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

extern char D_800C471C[];
extern char D_800C7C16[];

s32 func_801182B0(void *arg0, void *arg1) {
char *__repair_addr;

    s32 var_condition_bit;
    s32 var_v0;
    s32 temp_a1_2;
    u16 temp_v1;
    u16 temp_v1_2;
    u8 temp_v1_3;
    void *temp_a1;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0xB4), u8 *, 0x10) != 7) {
        temp_a1 = M2C_FIELD(arg1, void **, 0x6C);
        temp_v1 = M2C_FIELD(temp_a1, u16 *, 0x3C);
        if (temp_v1 == 2) {
            temp_v1_2 = M2C_FIELD(temp_a1, u16 *, 0x3E);
__repair_addr = (char *)((arg0 + (temp_v1_2 * 2)));

            var_condition_bit = (f32) M2C_FIELD(__repair_addr, s16 *, 0x1BC) < ((f32) *(s16 *)(D_800C7C16 + (temp_v1_2 * 4)) * 0.5f);
            goto block_9;
        }
        if (temp_v1 == 0) {
            temp_v1_3 = *(D_800C471C + (M2C_FIELD(temp_a1, u16 *, 0x3E) * 0xE8));
            var_condition_bit = (f32) M2C_FIELD((arg0 + (temp_v1_3 * 2)), s16 *, 0x1BC) < ((f32) *(s16 *)(D_800C7C16 + (temp_v1_3 * 4)) * 0.5f);
            goto block_9;
        }
        temp_a1_2 = M2C_FIELD(temp_a1, u16 *, 0x3E);
        var_v0 = 0;
        if ((s32) temp_a1_2 >= 0x17) {
            var_v0 = 1;
            if ((s32) temp_a1_2 >= 0x1A) {
                var_v0 = 0;
                if (temp_a1_2 == 0x1A) {
                    var_condition_bit = M2C_FIELD(arg0, f32 *, 0x60) < 75.0f;
block_9:
                    var_v0 = 1;
                    if (!var_condition_bit) {
                        var_v0 = 0;
                    }
                }
            }
        }
    } else {
        var_v0 = 0;
    }
    return var_v0;
}
