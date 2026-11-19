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

s32 func_80015D40();
s32 func_800175C0();
s32 func_8003E6EC();
s32 func_8007659C();
s32 func_80085E30();
s32 func_80085E78();
s32 func_80087380();
extern s32 *D_800CA31C;
extern u8 D_80109A60[];

typedef struct { unsigned char pad_0[32]; int field_20; unsigned char pad_24[52]; int field_58; unsigned char pad_5C[4]; int field_60; unsigned char pad_64[8]; void * field_6C; unsigned char pad_70[10]; short field_7A; unsigned short field_7C; } __repair_record_arg0;
void func_80087840(void *arg0) {
    s16 temp_v1;
    s16 temp_v1_2;
    u8 temp_a0;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v1_3;
    u8 temp_v1_4;
    void *temp_s0;

    temp_v1 = ((__repair_record_arg0*)arg0)->field_7A;
    temp_s0 = ((__repair_record_arg0*)arg0)->field_6C;
    switch (temp_v1) {                              /* irregular */
    case 0:
        temp_v0 = M2C_FIELD(temp_s0, u8 *, 0x44);
        if (temp_v0 != 0) {
            if (*(D_80109A60 + temp_v0) == M2C_FIELD(temp_s0, u8 *, 0x45)) {
                temp_v0_2 = M2C_FIELD(temp_s0, u8 *, 0x46);
                if ((temp_v0_2 != 0) && (*(D_80109A60 + temp_v0_2) == M2C_FIELD(temp_s0, u8 *, 0x47))) {
                    ((__repair_record_arg0*)arg0)->field_7A = 1;
                    func_8003E6EC(*D_800CA31C, arg0, 1);
                    return;
                }
            }
            return;
        }
        func_8003E6EC(*D_800CA31C, arg0, 1);
        if (M2C_FIELD(temp_s0, s32 *, 0x1C) == 0) {
            func_80087380(arg0);
            ((__repair_record_arg0*)arg0)->field_7A = 3;
            return;
        }
        ((__repair_record_arg0*)arg0)->field_7A = 1;
        return;
    case 1:
        temp_a0 = M2C_FIELD(temp_s0, u8 *, 0x4A);
        if (temp_a0 != 0) {
            if (!(((__repair_record_arg0*)arg0)->field_60 & func_80015D40(temp_a0))) {
                ((__repair_record_arg0*)arg0)->field_7C = 0U;
                return;
            }
            temp_v1_2 = ((__repair_record_arg0*)arg0)->field_7C + 1;
            ((__repair_record_arg0*)arg0)->field_7C = (u16) temp_v1_2;
            if ((f32) temp_v1_2 > 150.0f) {
                goto block_22;
            }
        } else {
block_22:
            ((__repair_record_arg0*)arg0)->field_7A = 2;
            return;
        }
        break;
    case 2:
        temp_v1_3 = M2C_FIELD(temp_s0, u8 *, 0x4B);
        if (temp_v1_3 != 0) {
            *(D_80109A60 + temp_v1_3) = 1;
        }
        M2C_FIELD(temp_s0, f32 *, 0x20) += 0.033333335f;
        func_80085E78(arg0, temp_s0);
        func_8007659C(arg0, temp_s0 + 0x1C);
        if (M2C_FIELD(temp_s0, s16 *, 0x2A) == M2C_FIELD(temp_s0, u8 *, 0x48)) {
            temp_v1_4 = M2C_FIELD(temp_s0, u8 *, 0x49);
            if (temp_v1_4 != 0) {
                *(D_80109A60 + temp_v1_4) = 1;
            }
        }
        if (M2C_FIELD(temp_s0, s16 *, 0x2A) == (M2C_FIELD(temp_s0, s16 *, 0x28) - 4)) {
            func_80085E30(temp_s0);
            ((__repair_record_arg0*)arg0)->field_7A = 3;
        }
        func_800175C0(((__repair_record_arg0*)arg0)->field_20, 0, 0x01200000, arg0 + 0x24, 0, 0);
        ((__repair_record_arg0*)arg0)->field_58 |= 1;
        func_80087380(arg0);
        break;
    }
}
