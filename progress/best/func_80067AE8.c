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

s32 func_8000237C();
s32 func_80002D30();
s32 func_80064318();
s32 func_800643D8();
s32 func_80067A24();
extern char D_800C469C[];

void func_80067AE8(void *arg0) {
    s8 temp_s3;
    u16 temp_a1_2;
    u8 temp_a1;
    void *temp_s0;
    void *temp_s1;
    void *temp_s2;

    temp_s2 = M2C_FIELD(arg0, void **, 0x6C);
    temp_s1 = M2C_FIELD(temp_s2, void **, 0xA8);
    temp_s0 = (M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s8 *, 0xE) * 0xE8) + D_800C469C;
    temp_a1 = M2C_FIELD(temp_s0, u8 *, 0x9E);
    temp_s3 = M2C_FIELD(temp_s2, s8 *, 0x182);
    if (temp_a1 != 0xFF) {
        func_8000237C(temp_s1, temp_a1, 2, 0);
        temp_a1_2 = M2C_FIELD(temp_s0, u16 *, 0x92);
        if (temp_a1_2 != 0) {
            func_80002D30(temp_s1, temp_a1_2);
        } else {
            M2C_FIELD(M2C_FIELD(temp_s2, void **, 0xA8), s16 *, 0x7A) = 5;
            func_80067A24(temp_s1, M2C_FIELD(temp_s0, u16 *, 0x94));
        }
        func_80064318(temp_s1, temp_s3);
        return;
    }
    func_800643D8(temp_s1, temp_a1);
}
