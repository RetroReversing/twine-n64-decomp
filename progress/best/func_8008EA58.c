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

s32 func_800989B8();                                /* extern */
extern u8 D_800CF540;
extern M2C_UNK D_8010D734;
extern M2C_UNK D_8010D748;
extern M2C_UNK D_8010D784;

s32 func_8008EA58(void) {
    s32 temp_v1;
    s32 var_a0;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;

    var_s0 = -1;
    if (D_800CF540 != 0) {
        var_a0 = func_800989B8();
        var_v0 = -1;
        if (var_a0 != -1) {
            var_v0_2 = var_a0 & 0xFF;
            do {
                {{ s32 __repair_value; __repair_value = var_v0_2 * 0x68; temp_v1 = __repair_value; }
                    if (*((M2C_UNK *)((s8 *)&D_8010D784 + temp_v1)) == var_a0) {
                        var_s0 = 0;
                        *((M2C_UNK *)((s8 *)&D_8010D748 + temp_v1)) = *((M2C_UNK *)((s8 *)&D_8010D748 + temp_v1)) | 8;
                    }
                    var_a0 = *((M2C_UNK *)((s8 *)&D_8010D734 + temp_v1));
                    var_v0_2 = var_a0 & 0xFF;
                }
            } while (var_a0 != -1);
            goto block_6;
        }
    } else {
block_6:
        var_v0 = var_s0;
    }
    return var_s0;
}
