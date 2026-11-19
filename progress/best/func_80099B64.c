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

extern char D_801007D9[];
extern char D_80100C7C[];

void func_80099B64(void *arg0) {
    char *__base_D_801007D9;
    s32 temp_v1;
    u8 temp_a2;
    u8 temp_v0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x60);
    if ((temp_v1 != -1) && (temp_a2 = M2C_FIELD(arg0, u8 *, 0x4A), (temp_a2 != 0xFF))) {
        temp_v0 = M2C_FIELD(arg0, u8 *, 0x4B);
        if (temp_v0 == 0xFF) {
            *(D_80100C7C + (temp_v1 & 0xFF)) = (s8) temp_v1;
            return;
        }
        __base_D_801007D9 = D_801007D9;
        *((temp_v0 * 0x10) + __base_D_801007D9 + temp_a2) = (s8) temp_v1;
    }
}
