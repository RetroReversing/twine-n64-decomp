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

void *func_80015DAC();
s32 func_800175C0();
s32 func_8005B5A8();
s32 func_8005C508();
s32 func_8007092C();
extern char D_80109A60[];

void func_8005C5E4(s32 arg0) {
    s32 var_s0;
    u16 temp_a0;
    u16 temp_v0;
    void *temp_s0;
    void *temp_v1;
    void *var_s1;

    var_s1 = func_80015DAC();
    var_s0 = 0;
    if (var_s1 != NULL) {
        do {
            if ((M2C_FIELD(var_s1, u16 *, 0x78) == 0x24) && ((temp_v1 = M2C_FIELD(var_s1, void **, 0x6C), temp_v0 = M2C_FIELD(temp_v1, u16 *, 0x24), (temp_v0 == 0)) || (*(D_80109A60 + temp_v0) != 0))) {
                temp_a0 = M2C_FIELD(temp_v1, u16 *, 0x26);
                if ((temp_a0 == 1) && (M2C_FIELD(temp_v1, u16 *, 0x28) == 3)) {
                    temp_s0 = var_s1 + 0x24;
                    func_800175C0(M2C_FIELD(var_s1, s32 *, 0x20), 2, 0x10000, temp_s0, 0, (s32) temp_a0);
                    func_8005C508(var_s1, temp_s0);
                    var_s0 = 1;
                    M2C_FIELD(var_s1, s32 *, 0x60) |= 1;
                    if (arg0 != 0) {
                        func_8007092C(arg0, 1);
                    }
                }
            }
            var_s1 = M2C_FIELD(var_s1, void **, 0x10);
        } while (var_s1 != NULL);
    }
    if (var_s0 == 0) {
        func_8005B5A8();
    }
}
