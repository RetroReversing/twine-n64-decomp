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

s32 __osMotorAccess();
s32 osMotorInit();
extern char D_800E0790[];
extern char D_80109DC8[];
extern char D_8010A3A0[];
extern char D_8010D298[];

void func_80010690(s32 arg0) {
    s32 temp_a2;
    s32 temp_s1;
    s32 var_s0;
    u16 *temp_v0;
    void *var_a0;
    char *__base_D_800E0790;

    __base_D_800E0790 = D_800E0790;

    temp_a2 = arg0 & 0xFFFF;
    temp_s1 = temp_a2 * 0x68;
    var_a0 = temp_s1 + __base_D_800E0790;
    if (osMotorInit(arg0, D_8010D298) == 0) {
        var_s0 = 0;
        do { {
            __osMotorAccess(var_a0, 0);
            var_s0 += 1;
            var_a0 = temp_s1 + __base_D_800E0790;
        }
} while (var_s0 < 3);
        temp_v0 = ((arg0 & 0xFFFF) * 2) + D_8010A3A0;
        *temp_v0 &= 0xFFFC;
        return;
    }
    *(u16 *)(D_80109DC8 + (temp_a2 * 2)) = 0;
}
