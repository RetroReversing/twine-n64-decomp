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

extern u8 D_800E2CC0[];
extern u8 D_800E2CE4[];
extern s32 sDataBankReady;

s32 func_80087F60(s32 arg0) {
    u8 *__base_D_800E2CC0;
    
s32 __repair_phase_temp_a0;
s32 __repair_phase___repair_phase_temp_a0;
    s32 temp_v0;
    s32 temp_v1;
    
    u32 var_v1;

    for (;;) {
s32 __block___repair_phase_temp_a0;
u32 __block_var_v1;
s32 cache;

        __block_var_v1 = 0;
loop_2:
        ;
        cache = sDataBankReady;
        __block___repair_phase_temp_a0 = 0;
        for (;;) {
            if ((*((__base_D_800E2CC0 = D_800E2CC0) + __block___repair_phase_temp_a0) == 0) || (__block_var_v1 == arg0) || (*(s32 *)(D_800E2CE4 + __block___repair_phase_temp_a0) != cache)) {
                __block_var_v1 += 1;
                __block___repair_phase_temp_a0 += 0x1228;
                if (__block_var_v1 < 2U) {
                    continue;
                }
            }
            break;
        }
        if (__block_var_v1 != 2) {
            __repair_phase___repair_phase_temp_a0 = sDataBankReady + 1;
            sDataBankReady = __repair_phase___repair_phase_temp_a0;
            __block_var_v1 = 0;
            if (__repair_phase___repair_phase_temp_a0 == -1) {
                sDataBankReady = 0;
                continue;
            }
            goto loop_2;
        }
        break;
    }
    __repair_phase_temp_a0 = arg0 * 0x1228;
    *(s32 *)(D_800E2CE4 + __repair_phase_temp_a0) = sDataBankReady;
    temp_v1 = sDataBankReady + 1;
    sDataBankReady = temp_v1;
    if (temp_v1 == -1) {
        sDataBankReady = 0;
    }
    return *(s32 *)(D_800E2CE4 + __repair_phase_temp_a0);
}
