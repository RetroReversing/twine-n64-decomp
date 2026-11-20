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

M2C_UNK func_80070730(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_8007089C(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80074C34(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_800CEC64;
extern s32 D_80108F78;
extern M2C_UNK func_801183F4;

void func_8005C41C(void *arg0) {
    func_80070730(M2C_FIELD(arg0, s32 *, 0x6C), 3, 1);
    if (D_80108F78 == 2) {
        if (M2C_FIELD(&func_801183F4, s8 *, 0x55D) == 0) {
            if (M2C_FIELD(&func_801183F4, s8 *, 0x55E) == 0) {
                func_80074C34(0, &D_800CEC64, 1);
            }
            M2C_FIELD(&func_801183F4, s8 *, 0x55E) = 1;
            M2C_FIELD(&func_801183F4, s8 *, 0x55C) = 1;
        }
    }
    func_8007089C(arg0, 0, 0x2B);
}
