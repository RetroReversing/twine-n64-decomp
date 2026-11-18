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
s32 func_80017EC0();
s32 func_8003E6EC();
s32 func_80044670();
u16 func_80045CF8();
s32 func_8007659C();
s32 func_80085E30();
s32 func_80085E78();
extern s16 D_800C2942;
extern s32 *D_800CA31C;
extern u8 D_80109A60[];

void func_8006217C(void *arg0) {
    s16 temp_v1;
    u16 *temp_s0;
    u16 temp_v0;
    u8 temp_a1;
    void *temp_s0_2;
    void *temp_s3;
    void *temp_v0_2;

    temp_v1 = M2C_FIELD(arg0, s16 *, 0x7A);
    temp_s3 = M2C_FIELD(arg0, void **, 0x6C);
    switch (temp_v1) {                              /* irregular */
    case 0:
        temp_a1 = M2C_FIELD(temp_s3, u8 *, 0x2E);
        if ((temp_a1 == 0) || (*(D_80109A60 + temp_a1) != 0)) {
            M2C_FIELD(arg0, s16 *, 0x7A) = 1;
        }
        if (M2C_FIELD(arg0, s16 *, 0x7A) == 1) {
            func_8003E6EC(*D_800CA31C, arg0, 1);
            return;
        }
        return;
    case 1:
        if (M2C_FIELD(arg0, s32 *, 0x60) & 0x7000) {
            func_80044670(arg0, M2C_FIELD(temp_s3, u16 *, 0x2C), D_800C2942);
            temp_v0 = M2C_FIELD(temp_s3, u16 *, 0x2C) + 1;
            M2C_FIELD(temp_s3, u16 *, 0x2C) = temp_v0;
            if ((u32) (temp_v0 & 0xFFFF) >= 0x1DU) {
                M2C_FIELD(temp_s3, u16 *, 0x2C) = 0U;
            }
            if (!(M2C_FIELD(temp_s3, u16 *, 0x2C) & 7)) {
                temp_v0_2 = func_80016410(2, arg0 + 0x24, arg0 + 0x3C);
                if (temp_v0_2 != NULL) {
                    temp_s0 = M2C_FIELD(temp_v0_2, u16 **, 0x6C);
                    *temp_s0 = func_80045CF8(0x1C);
                    M2C_FIELD(temp_v0_2, s16 *, 0x78) = 0x5C;
                    M2C_FIELD(temp_v0_2, u8 *, 0x7F) = 0xFF;
                    M2C_FIELD(temp_v0_2, s8 *, 0x80) = 0;
                    M2C_FIELD(temp_v0_2, s8 *, 0x81) = 0;
                    M2C_FIELD(temp_v0_2, u8 *, 0x82) = 0xFF;
                    M2C_FIELD(temp_v0_2, f32 *, 0x54) = 0.5f;
                    func_80044670(temp_v0_2, *temp_s0, D_800C2942);
                    func_80016990(temp_v0_2, M2C_FIELD(arg0, s32 *, 0x20));
                }
            }
        }
        temp_s0_2 = temp_s3 + 0x10;
        func_80085E78(arg0, temp_s0_2);
        M2C_FIELD(temp_s3, f32 *, 4) += M2C_FIELD(temp_s3, f32 *, 8);
        func_80017EC0(arg0, 0x3F800000, 0x40A00000);
        func_8007659C(arg0, temp_s3);
        M2C_FIELD(arg0, s32 *, 0x3C) = 0;
        M2C_FIELD(arg0, s32 *, 0x40) = 0;
        M2C_FIELD(arg0, f32 *, 0x44) = 2048.0f;
        if (M2C_FIELD(temp_s3, s16 *, 0xE) >= (M2C_FIELD(temp_s3, s16 *, 0xC) - 4)) {
            *(D_80109A60 + M2C_FIELD(temp_s3, u8 *, 0x2F)) = 1;
            func_80085E30(temp_s0_2);
            M2C_FIELD(arg0, s32 *, 0x60) |= 1;
        }
        M2C_FIELD(arg0, s32 *, 0x58) |= 1;
        break;
    }
}
