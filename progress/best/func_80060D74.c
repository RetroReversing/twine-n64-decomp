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

void *func_80016410();
s32 func_80016990();
s32 func_80044670();
s32 func_80045CF8();
f32 func_80045D2C();
f32 func_80045D8C();

void func_80060D74(void *arg0) {
    f32 sp10;
    s32 sp14;
    f32 sp18;
    f32 temp_a0;
    void *temp_s0;
    void *temp_s3;
    void *temp_v0;

    temp_s3 = M2C_FIELD(arg0, void **, 0x6C);
    if (((M2C_FIELD(arg0, s32 *, 0x58) & 4) || (M2C_FIELD(arg0, s32 *, 0x60) & 0x3000)) && (func_80045CF8(M2C_FIELD(arg0, s16 *, 0x7C)) == 0)) {
        temp_a0 = M2C_FIELD(arg0, f32 *, 0x2C);
        sp10 = M2C_FIELD(arg0, f32 *, 0x24);
        sp14 = M2C_FIELD(arg0, s32 *, 0x28);
        sp18 = temp_a0;
        sp10 += func_80045D8C(0x40000000, 0x3F800000, temp_a0) * M2C_FIELD(temp_s3, f32 *, 0);
        sp18 += func_80045D8C(0x40000000, 0x3F800000) * M2C_FIELD(temp_s3, f32 *, 0);
        temp_v0 = func_80016410(0xC, &sp10, 0);
        if (temp_v0 != NULL) {
            temp_s0 = M2C_FIELD(temp_v0, void **, 0x6C);
            func_80044670(temp_v0, 2, 0x1B);
            M2C_FIELD(temp_s0, f32 *, 4) = (f32) M2C_FIELD(temp_s3, f32 *, 4);
            M2C_FIELD(temp_s0, f32 *, 8) = (f32) -func_80045D2C(0x3EA740DB);
            M2C_FIELD(temp_v0, s16 *, 0x78) = 0x65;
            M2C_FIELD(temp_v0, s8 *, 0x7F) = 0;
            M2C_FIELD(temp_v0, s8 *, 0x80) = 0;
            M2C_FIELD(temp_v0, s8 *, 0x81) = 0;
            M2C_FIELD(temp_v0, s8 *, 0x82) = 0x40;
            func_80016990(temp_v0, M2C_FIELD(arg0, s32 *, 0x20));
        }
    }
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
}
