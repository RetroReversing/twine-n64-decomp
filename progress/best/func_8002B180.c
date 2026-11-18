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

s32 sprintf();

void func_8002B180(void *arg0, s8 *arg1) {
    s32 temp_t1;

    if (arg1 != NULL) {
        if (arg0 == NULL) {
            *arg1 = 0;
            return;
        }
        temp_t1 = M2C_FIELD(arg0, s32 *, 0);
        if (temp_t1 >= 0x3C) {
            sprintf(arg1, "%d:%02d:%02d", (s16) (M2C_FIELD(arg0, s32 *, 0) / 60), (s16) (M2C_FIELD(arg0, s32 *, 0) % 60), (s32) M2C_FIELD(arg0, s8 *, 6));
            return;
        }
        sprintf(arg1, "%d:%02d", (s16) temp_t1, (s16) M2C_FIELD(arg0, s8 *, 6));
    }
}
