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

void *func_8002A7CC(void *arg0, s32 arg1, s8 arg2, s8 arg3) {
    f32 temp_fv0;
    s16 var_a2;
    s32 temp_t1;
    s32 var_a1;
    s32 var_v1;
    u32 temp_t0;
    u8 temp_v0;
    u8 temp_v1;
    void *temp_a2;
    void *var_a1_2;

    if (arg0 != NULL) {
        temp_v1 = M2C_FIELD(arg0, u8 *, 0x19);
        temp_t0 = temp_v1 & 0xFF;
        if (temp_t0 < (u8) M2C_FIELD(arg0, u8 *, 0x1A)) {
            M2C_FIELD(arg0, u8 *, 0x19) = (u8) (temp_v1 + 1);
            temp_t1 = temp_t0 * 0xC;
            *(s32 *)(temp_t1 + M2C_FIELD(arg0, void **, 0)) = arg1;
            M2C_FIELD((temp_t1 + M2C_FIELD(arg0, void **, 0)), s8 *, 8) = arg2;
            M2C_FIELD((temp_t1 + M2C_FIELD(arg0, void **, 0)), u16 *, 4) = (u16) M2C_FIELD(arg0, u16 *, 0x16);
            var_a1_2 = M2C_FIELD(arg0, void **, 0);
            temp_a2 = (void *) ((temp_t1) + (s32) var_a1_2);
            if (temp_t0 != 0) {
                var_a1_2 += (temp_t0 - 1) * 0xC;
            }
            M2C_FIELD(temp_a2, s16 *, 6) = (s16) (M2C_FIELD(var_a1_2, u16 *, 6) + M2C_FIELD(arg0, u8 *, 0x21));
            M2C_FIELD((temp_t1 + M2C_FIELD(arg0, void **, 0)), s8 *, 9) = arg3;
            temp_v0 = M2C_FIELD(arg0, u8 *, 0x19);
            var_a1 = 0;
            var_a2 = 0;
            if (temp_v0 != 0) {
                var_v1 = 0 & 0xFF;
                do {
                    var_a1 += 1;
                    var_a2 += M2C_FIELD(((var_v1 * 0xC) + M2C_FIELD(arg0, void **, 0)), u8 *, 9);
                    var_v1 = var_a1 & 0xFF;
                } while ((u32) ((temp_t1 = var_a1) & 0xFF) < temp_v0);
            }
            temp_fv0 = (1.0f / (f32) var_a2) * (f32) M2C_FIELD(arg0, u8 *, 0x1B);
            M2C_FIELD(arg0, f32 *, 0xC) = temp_fv0;
            if (temp_fv0 > 1.0f) {
                M2C_FIELD(arg0, f32 *, 0xC) = 1.0f;
            }
            return M2C_FIELD(arg0, void **, 0) + ((var_a1 & 0xFF) * 0xC);
        }
        /* Duplicate return node #11. Try simplifying control flow for better match */
        return NULL;
    }
    return NULL;
}
