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

extern char D_80115094[];

s32 func_80081AA4(s32 arg0, s32 arg1) {
    s16 __repair_sign;
char *__repair_addr;

    s32 temp_a2;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v0_2;
    u8 temp_v1_2;
    
    union { void * pointer; unsigned int value; } __repair_phase_storage;
    void *temp_t0;

    temp_a2 = arg0 * 0xA0;
    temp_t0 = temp_a2 + D_80115094;
    __repair_phase_storage.pointer = (arg1 * 2) + temp_t0;
    temp_v1_2 = M2C_FIELD(__repair_phase_storage.pointer, u8 *, 1);
    if (temp_v1_2 != 0) {
        temp_v1 = *((temp_v1_2 * 4) + (D_80115094 + 0x70) + temp_a2);
        if (!(M2C_FIELD(__repair_phase_storage.pointer, u8 *, 0) & 0x40)) {
            var_v0_2 = arg1 * 2;
            if (temp_v1 > 0) {
                return temp_v1;
            }
            goto block_6;
        }
        var_v0 = temp_v1;
        if (temp_v1 >= 0) {
            goto block_5;
        }
        /* Duplicate return node #9. Try simplifying control flow for better match */
        return var_v0;
    }
block_5:
    var_v0_2 = arg1 * 2;
__repair_addr = (char *)(var_v0_2 + temp_t0);

block_6:
    __repair_phase_storage.value = (u8)( *(s32 *)(__repair_addr));
    if (!(((u8)__repair_phase_storage.value) & 0x10)) {
        return 0;
    }
    __repair_sign = -((((u8)__repair_phase_storage.value) & 0x20) != 0);
    var_v0 = (__repair_sign << 16) | 0x10000;
    return var_v0;
}
